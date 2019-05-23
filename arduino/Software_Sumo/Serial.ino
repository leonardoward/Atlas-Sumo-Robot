//######################################################################################################################
//##                                                    Serial                                                        ##
//######################################################################################################################
void init_serial(int baud){
  Serial.begin(baud);                       //Start serial for output
  Serial.println("Inicio");
}
void serial(){
    //Lee todos los comandos de la forma $comando/n , donde "\n" es "enter" (salto de línea)
    //Protocolo que permita acceso por serial a:
     while (Serial.available()) { //Mientras hayan datos en el buffer de entrada de serial
        // get the new byte:
        char inChar = (char)Serial.read();  //Lee los valores y los guarda en forma de caracteres
        if(inChar=='$'){                    //Si el caracter es igual al caracter de inicio de trama "$"
          serial_buffer=Serial.readStringUntil('\n'); //Guarda en un string todos los valores entre "$" y "\n"
                                                      //(salto de linea)
          Serial.println(serial_buffer);              //Imprime el comando recibido
        }else{
          serial_buffer=""; //Si no encuentra el valor de inicio de trama $ no guarda nada
        }
     }
}

void send_serial(){
  ahora_print = millis();
  deltaT_print= ahora_print - pasado_print;
  //Medicion de rpm cada 100 ms
  if(deltaT_print>= 150){
    //###################
    //Serial.println(estado_controlador);
    //print_sharps_volt();
    //print_sharps_raw();
    //print_line_detect();
    //Serial.println();
    print_curr_rpm_pwm();
    //###################
    pasado_print = ahora_print;
  }
}

void print_curr_rpm_pwm(){
  Serial.print("CURR1 ");
  Serial.print(abs(get_current(1)));
  Serial.print('\t');
  Serial.print("RPM1 ");
  //Serial.print(map(RPM_M1, 0, 1023, 0, 255));
  Serial.print(RPM_M1);
  Serial.print('\t');
  Serial.print("PWM1 ");
  Serial.print(pwm1);
  Serial.print('\t');
  Serial.print("CURR2 ");
  Serial.print(abs(get_current(2)));
  Serial.print('\t');
  Serial.print("RPM2 ");
  //Serial.print(map(RPM_M2, 0, 1023, 0, 255));
  Serial.print(RPM_M2);
  Serial.print('\t');
  Serial.print("PWM2 ");
  Serial.print(pwm2);
  Serial.println();
}

void print_sharps_volt(){
  Serial.print("Sharp1 ");
  Serial.print(getADC_sharp(1));
  Serial.print('\t');
  Serial.print("Sharp2 ");
  Serial.print(getADC_sharp(2));
  Serial.print('\t');
  Serial.print("Sharp3 ");
  Serial.print(getADC_sharp(3));
  Serial.print('\t');
  Serial.print("Sharp4 ");
  Serial.print(getADC_sharp(4));
  Serial.print('\t');
  Serial.print("Ult F Der ");
  Serial.print(ult_f_der);
  Serial.print('\t');
  Serial.print("Ult F Izq ");
  Serial.print(ult_f_izq);
  Serial.print('\t');
  Serial.println();
}


// Sharp_Front_Center Sharp2
// Sharp_Izq Sharp3
// Sharp_Der Sharp1
// Ultrasonic_Back Sharp4
// Ultrasonic_Front_Left Ult_F_Izq
// Ultrasonic_Front_Right Ult_F_Der
void print_sharps_raw(){
  Serial.print("Sharp Der ");
  Serial.print(Sharp1_adc);
  Serial.print('\t');
  Serial.print("Sharp Frente ");
  Serial.print(Sharp2_adc);
  Serial.print('\t');
  Serial.print("Sharp Izq ");
  Serial.print(Sharp3_adc);
  Serial.print('\t');
  Serial.print("Ult Atras ");
  Serial.print(Sharp4_adc);
  Serial.print('\t');
  Serial.print("Ult F Der ");
  Serial.print(ult_f_der);
  Serial.print('\t');
  Serial.print("Ult F Izq ");
  Serial.print(ult_f_izq);
  Serial.print('\t');
  //Serial.println();
}

void print_line_detect(){
  Serial.print("Front Izq ");
  Serial.print(line_f_izq);
  Serial.print('\t');
  Serial.print("Font Der ");
  Serial.print(line_f_der);
  Serial.print('\t');
  Serial.print("Back Izq ");
  Serial.print(line_b_izq);
  Serial.print('\t');
  Serial.print("Back der ");
  Serial.print(line_b_der);
  Serial.println();
}

