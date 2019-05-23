/*
########################################################################################################################
##                                       Software Robot de SUMO                                                       ##
##                                                                                                                    ##
## FutBot - Future Robotics                                                                                           ##
## Universidad Nacional Experimental Simon Bolivar                                                                    ##
## Venezuela, 2016                                                                                                    ##
########################################################################################################################
*/
#include <SPI.h>
#include <TimerOne.h>
#include <PID_v1.h>

#define ENC_M1 2
#define ENC_M2 3
#define FR_M2 4
#define PWM_M1 5
#define PWM_M2 6
#define EN_M1 7
#define FR_M1 8
#define EN_M2 9

#define SHARP_1 A0
#define SHARP_2 A1
#define SHARP_3 A2
#define SHARP_4 A3
#define CURRENT_M1 A4
#define CURRENT_M2 A5

#define chipSelectPin 10

#define CURRENT_LIMIT 3.5

#define Vcc_  4.99
#define vref_pos 4.99
#define vref_neg 0

#define TiempoDeMuestreo 100
#define div_por_vuelta 30

#define FACTOR_DECENSO_PID 10

#define RADIUS_WHEEL 0.08 //En m
#define LENGTH_ROBOT 0.25 //En m

#define RPM_MAX 2000 //En rpm
#define W_MAX 115.19 //En rad/s

#define Sharp_Front_Center 2
#define Sharp_Izq 3
#define Sharp_Der 1
#define Ultrasonic_Back 4
// Ultrasonic_Front_Left Ult_F_Izq
// Ultrasonic_Front_Right Ult_F_Der
//######################################################################################################################
//##                                      Variables Globales                                                          ##
//######################################################################################################################
int Sharp1_adc=0, Sharp2_adc=0, Sharp3_adc=0, Sharp4_adc=0;
float Sharp1_volt=0, Sharp2_volt=0, Sharp3_volt=0, Sharp4_volt=0;
int current_M1_adc=0, current_M2_adc=0;
float current_M1_volt=0, current_M2_volt=0;
float current_M1_curr=0, current_M2_curr=0;
int pwm1, pwm2;
String serial_buffer;
float x_acc=0, y_acc=0, z_acc=0;
float line_f_izq=0, line_f_der=0, line_b_izq=0, line_b_der=0;
float ult_f_der=0, ult_f_izq;
SPISettings settings(1000000, MSBFIRST, SPI_MODE0); //1MHz
int adc_state=0;
double deltaT, RPM_M1,  RPM_M2, cont_encoder1, cont_encoder2, copy_cont_encoder1, copy_cont_encoder2;
unsigned long ahora, pasado=0;
double deltaT_print;
unsigned long ahora_print, pasado_print=0;
double deltaT_motion;
unsigned long ahora_motion=0, pasado_motion=0;
bool enable_motion=LOW;
bool contador_ini=HIGH;
unsigned long ahora_contIni=0,pasado_contIni=0;
double deltaT_contIni=0;
//------------------------------ PID Motor 1 Motor Izquierdo  ----------------------------------------
//Define Variables we'll be connecting to
double Setpoint_M1, Input_M1, Output_M1;
//Specify the links and initial tuning parameters
double Kp_M1=2, Ki_M1=0.5, Kd_M1=0.1;
int out_limit_M1=255;
PID PID_M1(&Input_M1, &Output_M1, &Setpoint_M1, Kp_M1, Ki_M1, Kd_M1, DIRECT);
//------------------------------ PID Motor 2 Motor Derecho  -----------------------------------------
//Define Variables we'll be connecting to
double Setpoint_M2, Input_M2, Output_M2;
//Specify the links and initial tuning parameters
double Kp_M2=2, Ki_M2=0.5, Kd_M2=0.1;
int out_limit_M2=255;
PID PID_M2(&Input_M2, &Output_M2, &Setpoint_M2, Kp_M2, Ki_M2, Kd_M2, DIRECT);
//----------------------------        Control     ---------------------------------------------------
double des_RPM_left = 1000;
double des_RPM_right = 1000;
float V_center;
float W_center;
float V_left;
float V_right;
int time_control=0;
int time_control_max=100*1000;
int Vc=0;
int Wc=0;
int estado_controlador=0;
bool enable_giro90pos=LOW;
bool motores_activados=LOW;
unsigned long ticks_M1=0;
unsigned long ticks_M2=0;
float Dr_giro_90pos=0;
float recorrido_90pos=PI*25/4;
bool control_automatico=HIGH;   //Control Automático --> HIGH (PID + Vc,Wc), Control Manual --> LOW
bool enable_PID1=HIGH;
bool enable_PID2=HIGH;
int num_motores_activos_PID=2;
//######################################################################################################################
//##                                                    Main                                                          ##
//######################################################################################################################

void setup(){

  init_serial(9600);
  init_adcExt();
  init_sharps(A0, A1, A2, A3);
  init_current(A4, A5);
  Timer1.initialize(1000);// Interrupt every 1 ms
  Timer1.attachInterrupt(time_motion);

  pasado_contIni=millis();
}

void loop() {
   contador_inicial(3520);
   if(contador_ini==LOW && motores_activados==LOW){
      //Configuración inicial de los motores
      init_Motores();

      setDir_Motor(1,0);
      setDir_Motor(2,1);
      setPWM_Motor(1, 0);
      setPWM_Motor(2, 0);

      Input_M1=RPM_M1;
      Setpoint_M1 = 0;
      //turn the PID on
      PID_M1.SetMode(AUTOMATIC);
      Input_M2=RPM_M2;
      Setpoint_M2 = 0;
      //turn the PID on
      PID_M2.SetMode(AUTOMATIC);
      enable_giro90pos=HIGH;
      //-----------------------------------------
      motores_activados=HIGH;
   }
   measure_sharps_raw(SHARP_1, SHARP_2, SHARP_3, SHARP_4);  //Mide los datos de A0, A1, A2, A3, donde estan los 4 sharps
   measureAll_adcExt();                                     //Mide los datos del acelerómetro (eje x, y,z) y los detectores de linea

   if(motores_activados==HIGH){
     measure_current(CURRENT_M1,CURRENT_M2);
     detect_limit_current();
     measure_rpm();
     //set_PID_motores(num_motores_activos_PID,enable_PID1,enable_PID2);
     //send_serial();
     //estrategia();
     //maquina_estados();

     if(enable_motion){
      ahora_motion = millis();
      deltaT_motion= ahora_motion - pasado_motion;
      if(deltaT_motion>= 500){
        estado_controlador=0;
        enable_motion=LOW;
        enable_PID1=HIGH;
        enable_PID2=HIGH;
        num_motores_activos_PID=2;
      }
    }else{
      estrategia();
      set_PID_motores(num_motores_activos_PID,enable_PID1,enable_PID2);
      maquina_estados();
    }
    //serial();           //Lee los comandos por serial
  }
}



