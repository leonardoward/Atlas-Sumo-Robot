//######################################################################################################################
//##                                   Modelo de Drive Diferencial                                                    ##
//######################################################################################################################
//-------------                         Definir la RPM desada para cada motor                  -------------------------
void set_desRPM(float V, float W){
  //Unicycle
  V_right=Vright_unicycle(V, W);
  V_left=Vleft_unicycle(V, W);
  //------  Motor 1 -----------------------------
  if(V_right>=0){
    setDir_Motor(1,0);
    des_RPM_right=RPM_from_VEL(V_right);
  }else{
    setDir_Motor(1,1);
    des_RPM_right=RPM_from_VEL(abs(V_right));
  }
  //------  Motor 2 -----------------------------
  if(V_left>=0){
    setDir_Motor(2,1);
    des_RPM_left=RPM_from_VEL(V_left);
  }else{
    setDir_Motor(2,0);
    des_RPM_left=RPM_from_VEL(abs(V_left));
  }
}
//-------------                       Conversión de Vleft a RPM1 y Vright a RPM2                ------------------------
double RPM_from_VEL(float V){
  //Convertimos de V (m/s) a W (rad/s)
  float W = V/RADIUS_WHEEL;
  //Convertimos de rad/s a rev/min 
  double RPM = W*9.5492;
  return RPM;
}
//--------------  Conversión del modelo de uniciclo V,W al modelo de drive diferencial Vr,Vl  --------------------------
//-------------                       Conversión de V,W a Vleft y V,W a Vright                 -------------------------
float Vright_unicycle(float V, float W){              //V en m/s y W en rad/s, Vright en rad/s
  return (((2*V)+(W*LENGTH_ROBOT))/(2*RADIUS_WHEEL));
}

float Vleft_unicycle(float V, float W){                   //V en m/s y W en rad/s, Vleft en rad/s
  return ((2*V)-(W*LENGTH_ROBOT))/(2*RADIUS_WHEEL);
}
//------------  Manejo del tiempo para definir angulos y distancias en lugar de velocidades   --------------------------

void time_motion(){
  if(time_control<time_control_max){
    time_control=time_control+1;
  }else{
    time_control=0;
    motion();
  }
}

void motion(){
  //Vc=0;
  //Wc=0;
}

void maquina_estados(){
  if(estado_controlador==0){
    search_izq();
  }else if(estado_controlador==1){
    kill();
  }else if(estado_controlador==2){
    off();
  }else if(estado_controlador==3 && enable_giro90pos==HIGH){
    giro_90pos();
  }else if(estado_controlador==4){
    search_der();
  }else if(estado_controlador==5){
    kill_izq();
  }else if(estado_controlador==6){
    kill_der();
  }
}

void set_PID_motores(int motores_activos,bool enable_motor_1, bool enable_motor_2){
  if(motores_activos==2){ //2 motores activos
    set_desRPM(Vc, Wc);
    
    //PID Vel Motor 1
    Setpoint_M1=map(des_RPM_left, 0, RPM_MAX, 0, 255); 
    Input_M1=map(RPM_M1, 0, RPM_MAX, 0, 255); 
    PID_M1.Compute();
    setPWM_Motor(1, Output_M1);
     
    //PID Vel Motor 2
    Setpoint_M2 = map(des_RPM_right, 0, RPM_MAX, 0, 255); 
    Input_M2=map(RPM_M2, 0, RPM_MAX, 0, 255); 
    PID_M2.Compute();
    setPWM_Motor(2, Output_M2);
  }else{                //Un motor activo
    if(enable_motor_1==HIGH && enable_motor_2==LOW){
      set_desRPM(Vc, Wc);
      
      //PID Vel Motor 1
      Setpoint_M1=map(des_RPM_left, 0, RPM_MAX, 0, 255); 
      Input_M1=map(RPM_M1, 0, RPM_MAX, 0, 255); 
      PID_M1.Compute();
      setPWM_Motor(1, Output_M1);
       
      //PID Vel Motor 2 es cero
      setPWM_Motor(2, 0);
    }else if(enable_motor_1==LOW && enable_motor_2==HIGH){
      set_desRPM(Vc, Wc);
      
      //PID Vel Motor 1
      setPWM_Motor(1, 0);
       
      //PID Vel Motor 2
      Setpoint_M2 = map(des_RPM_right, 0, RPM_MAX, 0, 255); 
      Input_M2=map(RPM_M2, 0, RPM_MAX, 0, 255); 
      PID_M2.Compute();
      setPWM_Motor(2, Output_M2);
    }
  }
}

