//######################################################################################################################
//##                                             Máquina de estados                                                  ##
//######################################################################################################################

void estrategia(){
  //Condiciones de cambio de estados
  if(enable_giro90pos){
    estado_controlador=3;
  }else if(Sharp2_adc>173 && estado_controlador!=2 && estado_controlador!=3){
    estado_controlador=1;
  }else if(ult_f_der<0.78 && estado_controlador!=2 && estado_controlador!=3){
    estado_controlador=6;
  }else if(ult_f_izq<0.30 && estado_controlador!=2 && estado_controlador!=3){
    estado_controlador=5;
  }else if(Sharp3_adc>165 && estado_controlador!=2 && estado_controlador!=3){
    estado_controlador=0;
  }else if(Sharp1_adc>184 && estado_controlador!=2 && estado_controlador!=3){
    estado_controlador=4;
  }else{
    estado_controlador=0;
  }
  // Sharp_Front_Center Sharp2
  // Sharp_Izq Sharp3
  // Sharp_Der Sharp1
  // Ultrasonic_Back Sharp4
  // Ultrasonic_Front_Left Ult_F_Izq
  // Ultrasonic_Front_Right Ult_F_Der
}

void search_izq(){
  //Serial.println("Search izq");
  Vc=0;
  Wc=1.1*PI;
  //Wc=0;
  num_motores_activos_PID=2;
  enable_PID1=HIGH;
  enable_PID2=HIGH;
}

void search_der(){
  //Serial.println("Search der");
  Vc=0;
  Wc=-1.1*PI;
  //Wc=0;
  num_motores_activos_PID=2;
  enable_PID1=HIGH;
  enable_PID2=HIGH;
}

void kill(){
  //Serial.println("Kill");
  Vc=2;
  //Vc=0;
  Wc=0;
  num_motores_activos_PID=2;
  enable_PID1=HIGH;
  enable_PID2=HIGH;
}

void kill_der(){
  //Serial.println("Kill der");
  Vc=1;
  //Vc=0;
  Wc=-2;
  //Wc=0;
  num_motores_activos_PID=2;
  enable_PID1=HIGH;
  enable_PID2=HIGH;
}

void kill_izq(){
  //Serial.println("Kill izq");
  Vc=1;
  //Vc=0;
  Wc=2;
  //Wc=0;
  num_motores_activos_PID=2;
  enable_PID1=HIGH;
  enable_PID2=HIGH;
}

void off(){
  Wc=0;
  Vc=0;
  setPWM_Motor(1, 0);
  setPWM_Motor(2, 0);
  num_motores_activos_PID=2;
  enable_PID1=HIGH;
  enable_PID2=HIGH;
}

void giro_90pos(){
  //Serial.println("Giro 90");
  enable_giro90pos=LOW;
  Vc=1;
  Wc=2*PI;
  //Wc=0;
  //Giro de sobre la rueda izquierda

  //Giro de sobre la rueda derecha

  setDir_Motor(1,0);
  setDir_Motor(2,1);
  setPWM_Motor(1, 70);
  setPWM_Motor(2, 255);

  //setPWM_Motor(1, 255);
  //setPWM_Motor(2, 50);

  num_motores_activos_PID=2;
  enable_PID1=HIGH;
  enable_PID2=HIGH;
  pasado_motion=millis();
  enable_motion=HIGH;
}


