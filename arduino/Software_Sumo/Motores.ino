//######################################################################################################################
//##                                                  Motores                                                         ##
//######################################################################################################################

/*########################################################################################
## ------------------------------    init_Motores    ---------------------------------- ##
##                                                                                      ##
## Esta función se utiliza para configurar los puertos del micro que manejan los motores##
## configura los puertos del encoder (ENC_M), el pwm (PWM_M), el pin de encendido y     ##
## apagado (EN_M), y el cambio de dirección, forward/reverse (FR_M). Luego  se establece##
## la configuración inicial, se establece la dirección, un PWM cero para cada motor, y  ##
## luego se habilitan los motores                                                       ##
##                                                                                      ##
##------------------------------------Variables---------------------------------------- ##
##                                                                                      ##
## Tamaño   Nombre      Tipo      Función                                               ##
##                                                                                      ##
########################################################################################*/

void init_Motores(){
    //----------------  Configuración de los pines      ------------------------
    pinMode(ENC_M1,INPUT);
    attachInterrupt(digitalPinToInterrupt(ENC_M1),tick_M1,FALLING);
    pinMode(ENC_M2,INPUT);
    attachInterrupt(digitalPinToInterrupt(ENC_M2),tick_M2,FALLING);
    pinMode(PWM_M1,OUTPUT);
    pinMode(PWM_M2,OUTPUT);
    pinMode(EN_M1,OUTPUT);
    pinMode(EN_M2,OUTPUT);
    pinMode(FR_M1,OUTPUT);
    pinMode(FR_M2,OUTPUT);

    //----------------  Configuración inicial de los motores ---------------------
    //Se inician ambos motores deshabilitados.
    enable_motor(1,0);    //Motor 1 apagado
    enable_motor(2,0);    //Motor 2 apagado
    //Sentido de Giro de cada motor contrario el uno del otro para desplazamiento
    //en un solo sentido.
    setDir_Motor(1,0);
    setDir_Motor(2,1);
    //PWM de cada motor
    setPWM_Motor(1, 0);   //PWM de inicio 0%
    setPWM_Motor(2, 0);   //PWM de inicio 0%
    //Se habilitan ambos motores deshabilitados.
    enable_motor(1,1);    //Motor 1 encendido
    enable_motor(2,1);    //Motor 2 encendido
}

/*########################################################################################
## ------------------------------    enable_motor    ---------------------------------- ##
##                                                                                      ##
## Esta función se utiliza para encender o apagar los motores (motor 1 y motor 2)       ##
## con enable==1 coloca 5 voltios en el pin ON/OFF del motor y con enable==0            ##
## coloca 0 voltios en el pin respectivo                                                ##
##                                                                                      ##
##------------------------------------Variables---------------------------------------- ##
##                                                                                      ##
## Tamaño   Nombre      Tipo      Función                                               ##
##                                                                                      ##
## int      num_motor   Entrada   - 1 o 2, representa el número del motor a utilizar    ##
## int      enable      Entrada   - 0 para apagar y 1 para encender                     ##
##                                                                                      ##
########################################################################################*/

void enable_motor(int num_motor, int enable){
  switch(num_motor){
    case 1:         //Para el Motor 1
      if(enable==0){
        digitalWrite(EN_M1,LOW);
      }else{
        digitalWrite(EN_M1,HIGH);
      }
    break;
    case 2:         //Para el Motor 2
      if(enable==0){
        digitalWrite(EN_M2,LOW);
      }else{
        digitalWrite(EN_M2,HIGH);
      }
    break;
  }
}

/*########################################################################################
## ------------------------------    setPWM_Motor    ---------------------------------- ##
##                                                                                      ##
## Esta función se utiliza para aplicar una señal pwm (con analogWrite) a los motores   ##
## (1 o 2)                                                                              ##
##                                                                                      ##
##------------------------------------Variables---------------------------------------- ##
##                                                                                      ##
## Tamaño   Nombre      Tipo      Función                                               ##
##                                                                                      ##
## int      num_motor   Entrada   - 1 o 2, representa el número del motor a utilizar    ##
## int      pwm_        Entrada   - numero entre 0 y 255, donde 0 es el valor min y 255 ##
##                                  el valor max                                        ##
##                                                                                      ##
########################################################################################*/

void setPWM_Motor(int num_motor, int pwm_){
switch(num_motor){
    case 1:         //Para el Motor 1
      analogWrite(PWM_M1,pwm_);
      pwm1=pwm_;
    break;

    case 2:         //Para el Motor 2
       analogWrite(PWM_M2,pwm_);
       pwm2=pwm_;
    break;
  }
}

/*########################################################################################
## ------------------------------    setDir_Motor    ---------------------------------- ##
##                                                                                      ##
## Esta función se utiliza para cambiar la dirección de los motores (1 o 2). Para que   ##
## el cambio de dirección tenga efecto el motor debe estar deshabilitado, por eso antes ##
## de cambiar la dirección, se coloca el pwm de dicho motor en cero, luego se desabilita##
## el motor, se cambia la dirección, y luego se vuelve a colocar el pwm anterior y se   ##
## habilita el motor                                                                    ##
##------------------------------------Variables---------------------------------------- ##
##                                                                                      ##
## Tamaño   Nombre      Tipo      Función                                               ##
##                                                                                      ##
## int      num_motor   Entrada   - 1 o 2, representa el número del motor a utilizar    ##
## int      dir         Entrada   - 0 para una dirección y 1 para la dirección opuesta  ##
##                                                                                      ##
########################################################################################*/

void setDir_Motor(int num_motor, int dir){
  int pwm_copy;
  switch(num_motor){
    case 1:                                 //Para el Motor 1
      pwm_copy=pwm1;                        //Guarda el último valor del pwm
      setPWM_Motor(1,0);                    //Coloca el pwm en 0
      enable_motor(1,0);                    //Deshabilita el motor
      if(dir==0){                           //Si dir indica 0
        digitalWrite(FR_M1,LOW);
      }else{                                //Si dir indica 1
        digitalWrite(FR_M1,HIGH);
      }
      setPWM_Motor(1,pwm_copy);             //Coloca el pwm anterior al cambio de giro
      enable_motor(1,1);                    //Habilita el motor
    break;

    case 2:                                 //Para el Motor 2
      pwm_copy=pwm2;                        //Guarda el último valor del pwm
      setPWM_Motor(2,0);                    //Coloca el pwm en 0
      enable_motor(2,0);                    //Deshabilita el motor
      if(dir==0){                           //Si dir indica 0
        digitalWrite(FR_M2,LOW);
      }else{                                //Si dir indica 1
        digitalWrite(FR_M2,HIGH);
      }
      setPWM_Motor(2,pwm_copy);             //Coloca el pwm anterior al cambio de giro
      enable_motor(2,1);                    //Habilita el motor
    break;

  }
}

/*########################################################################################
## ------------------------------      tick_M1       ---------------------------------- ##
##                                                                                      ##
## Esta función se activa con cada interrupción del pin que va conectado a la salida    ##
## el enconder del motor 1, aumenta el contador cont_encoder1 (que se utiliza para la   ##
## medición de rpm), y el contador ticks_M1 que cuenta todas las interrupciones que     ##
## han ocurrido debido a ese encoder, desde el incio del programa                       ##
##                                                                                      ##
##------------------------------------Variables---------------------------------------- ##
##                                                                                      ##
## Tamaño   Nombre      Tipo      Función                                               ##
##                                                                                      ##
########################################################################################*/

void tick_M1(){
  cont_encoder1++;
  ticks_M1++;
}

/*########################################################################################
## ------------------------------      tick_M2       ---------------------------------- ##
##                                                                                      ##
## Esta función se activa con cada interrupción del pin que va conectado a la salida    ##
## el enconder del motor 2, aumenta el contador cont_encoder2 (que se utiliza para la   ##
## medición de rpm), y el contador ticks_M1 que cuenta todas las interrupciones que     ##
## han ocurrido debido a ese encoder, desde el incio del programa                       ##
##                                                                                      ##
##------------------------------------Variables---------------------------------------- ##
##                                                                                      ##
## Tamaño   Nombre      Tipo      Función                                               ##
##                                                                                      ##
########################################################################################*/

void tick_M2(){
  cont_encoder2++;
  ticks_M2++;
}

/*########################################################################################
## ---------------------------      measure_rpm       --------------------------------- ##
##                                                                                      ##
## Esta función mide las rpm de los dos motores, calcula y actualiza dicho valor cada   ##
## 100 ms (TiempoDeMuestreo), los valores de las rpm se guardan en las variables        ##
## globales RPM_M1 y RPM_M2                                                             ##
##                                                                                      ##
##------------------------------------Variables---------------------------------------- ##
##                                                                                      ##
## Tamaño   Nombre      Tipo      Función                                               ##
##                                                                                      ##
########################################################################################*/

void measure_rpm(){
   ahora = millis();
   deltaT= ahora - pasado;
   //Medicion de rpm cada 100 ms
   if(deltaT>= TiempoDeMuestreo){
    noInterrupts();
    copy_cont_encoder1 = cont_encoder1;
    copy_cont_encoder2 = cont_encoder2;
    cont_encoder1 = 0;
    cont_encoder2 = 0;
    interrupts();
    //Numero de vueltas cada 100 ms (0.1s)
    double num_vueltas_M1=copy_cont_encoder1/div_por_vuelta;
    double num_vueltas_M2=copy_cont_encoder2/div_por_vuelta;
    //num_vueltas ------> TiempoDeMuestreo (en milis)
    // RPM        ------> 60 seg
    //Tiempo de muestreo/1000 = 0.1 Se convierte el TiempoDeMuestreo de milisegundos a segundos
    RPM_M1 = num_vueltas_M1*60*10;
    RPM_M2 = num_vueltas_M2*60*10;
    pasado = ahora;
    }
}


