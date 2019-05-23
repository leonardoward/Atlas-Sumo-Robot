//######################################################################################################################
//##                                                      ADC                                                         ##
//######################################################################################################################
void init_adcExt(){
  // initialize SPI:
  SPI.begin();
  // set the slaveSelectPin as an output:
  pinMode(chipSelectPin, OUTPUT);
}

void measureAll_adcExt(){
  SPI.beginTransaction(settings);
  switch(adc_state){
    
    case 0: //Z Axis
      line_f_der=readAdc_volt(8);
      adc_state=1;
      break;
    case 1: //X Axis
      ult_f_izq=readAdc_volt(7);
      adc_state=2;
      break;
    case 2: //Y Axis
      ult_f_der=readAdc_volt(6);
      adc_state=3;
      break;
    case 3: //Z Axis
      line_f_izq=readAdc_volt(5);
      adc_state=4;
      break;
    case 4: //Y Axis
      line_b_izq=readAdc_volt(4);
      adc_state=5;
      break;
    case 5: //Z Axis
      line_b_der=readAdc_volt(3);
      adc_state=6;
      break;
    case 6: //X Axis
      z_acc=readAdc_volt(2);
      adc_state=7;
      break;
    case 7: //Y Axis
      x_acc=readAdc_volt(1);
      adc_state=8;
      break;
    case 8: //Z Axis
      y_acc=readAdc_volt(0);
      adc_state=0;
      break;
    
    /*
    case 0: //X Axis
      ult_f_izq=readAdc_volt(7);
      adc_state=1;
      break;
    case 1: //Y Axis
      ult_f_der=readAdc_volt(6);
      adc_state=0;
      break;
    */
  }
  SPI.endTransaction();
}

uint16_t readAdc_raw(uint8_t chx) {
  uint8_t first_byte;
  uint8_t second_byte;
  uint16_t result;
  //Construccion del comando(chx << 4) | 0x0C
  //Ejemplo chx=2--> Comando: 0010 1100, donde 0x0C define las configuraciones
  //Output data length 16 bits
  //MSB First
  //Unipolar Binary
  /*
  uint8_t command;
  command=(chx << 4) | 0x0C;
  Serial.print(command);
  */
  digitalWrite(chipSelectPin, LOW);
  delayMicroseconds(10);
  first_byte = SPI.transfer((chx << 4) | 0x0C);
  second_byte = SPI.transfer(0);
  result=(first_byte << 8) | second_byte;
  result= result >> 4;
  digitalWrite (chipSelectPin, HIGH);
  /*
  Serial.print(first_byte);
  Serial.print("\t");
  Serial.print(second_byte);
  Serial.print("\t");
  Serial.print(result);
  */
  delay(10);  // EOC
  return result;
}

float readAdc_volt(uint8_t chx) {
  uint16_t raw = readAdc_raw(chx);
  float volt =(raw*(vref_pos-vref_neg))/4095;
  return volt;
}

