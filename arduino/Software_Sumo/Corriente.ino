//######################################################################################################################
//##                                             Medidores de Corriente                                               ##
//######################################################################################################################
// Medidor de corriente ACS12
// Medidor de -5A a 5A
// Valor estacionario Vcc/2
// 185 mV por amperios
// Límite sup Vcc/2+0.185*4; Para 4 Amperios positivos
// Límite sup Vcc/2+0.185*4; Para 4 Amperios negativos
void init_current(const int current_M1, const int  current_M2){
    pinMode(current_M1,INPUT); 
    pinMode(current_M2,INPUT);  
}
void measure_current(const int current_M1, const int  current_M2){
   current_M1_adc=analogRead(current_M1);
   current_M2_adc=analogRead(current_M2);
   //Convertimos el valor del ADC a voltaje
   current_M1_volt=current_M1_adc * (Vcc_ / 1023.0);
   current_M2_volt=current_M2_adc * (Vcc_ / 1023.0);
   //Restamos el voltaje estacionario
   current_M1_volt=current_M1_volt-(vref_pos/2);
   current_M2_volt=current_M2_volt-(vref_pos/2);
   //Convertimos el valor de voltaje a corriente
   current_M1_curr=current_M1_volt/0.185;
   current_M2_curr=current_M2_volt/0.185;
}
float get_current(int num_sensor){
  switch(num_sensor){
    case 1:
      return current_M1_curr;
    break;
    case 2:
      return current_M2_curr;
    break;
  }
}

void detect_limit_current(){
   if(abs(get_current(1))>CURRENT_LIMIT){   //Si la corriente del motor 1 supera el límite
    //setPWM_Motor(1, 0);
    out_limit_M1=out_limit_M1-FACTOR_DECENSO_PID;   //Se disminuye el valor límite al que puede llegar el PID
    PID_M1.SetOutputLimits(0, out_limit_M1);        //Se establece el nuevo límite
    //Serial.println("Motor 1 Exede el limite");
   }else{                                           //Si la corriente del motor 1 no supera el límite
    out_limit_M1=255;                               //Se define el valor máximo para el límite del PID 
    PID_M1.SetOutputLimits(0, out_limit_M1);        //Se establece el nuevo límite
   }
   
   if(abs(get_current(2))>CURRENT_LIMIT){
    //setPWM_Motor(2, 0);
    out_limit_M2=out_limit_M2-FACTOR_DECENSO_PID;   //Se disminuye el valor límite al que puede llegar el PID
    PID_M2.SetOutputLimits(0, out_limit_M2);        //Se establece el nuevo límite
    //Serial.println("Motor 2 Exede el limite");
   }else{                                           //Si la corriente del motor 1 no supera el límite
    out_limit_M2=255;                               //Se define el valor máximo para el límite del PID 
    PID_M2.SetOutputLimits(0, out_limit_M2);        //Se establece el nuevo límite
   }
}

