//######################################################################################################################
//##                                                Sharps                                                            ##
//######################################################################################################################

/*########################################################################################
##-------------------    Tablas de Calibración de los medidores   --------------------- ##
##                                                                                      ##
## Sharp Frente    Sharp Der      Sharp Izq      Ult-F-Izq       Ult-F-Der              ##
##                                                                                      ##
## 10cm - 727      10cm - 775     10cm - 727                                            ##
## 20cm - 400      20cm - 431     20cm - 415                                            ##
## 30cm - 307      30cm - 320     30cm - 305                                            ##
## 40cm - 256      40cm - 268     40cm - 248     40 cm - 0.16    40 cm - 0.42           ##
## 50cm - 224      50cm - 234     50cm - 216                                            ##
## 60cm - 206      60cm - 213     60cm - 195                                            ##
## 70cm - 190      70cm - 199     70cm - 180                                            ##
## 80cm - 173      80cm - 184     80cm - 165     80 cm - 0.30    80 cm - 0.78           ##
## 90cm - 162      90cm - 172     90cm - 157                                            ##
## 100cm - 151     100cm - 161    100cm - 147                                           ##
## 110cm - 145     110cm - 151    110cm - 139                                           ##
## 120cm - 137     120cm - 140    120cm - 132                                           ##
## 130cm - 130     130cm - 132    130cm - 128                                           ##
## 140cm - 120     140cm - 125    140cm - 121                                           ##
## 150cm - 111     150cm - 115    150cm - 117                                           ##
##                                                                                      ##
########################################################################################*/

/*########################################################################################
## ------------------------------    init_sharps     ---------------------------------- ##
##                                                                                      ##
## Esta función se utiliza para configurar los puertos del micro que leen los           ##
## medidores de distancia principales.                                                  ##
##                                                                                      ##
##------------------------------------Variables---------------------------------------- ##
##                                                                                      ##
## Tamaño       Nombre      Tipo      Función                                           ##
##                                                                                      ##
## const int    sharp1      Entrada   - Puerto del micro que lee el medidor 1           ##
## const int    sharp2      Entrada   - Puerto del micro que lee el medidor 2           ##
## const int    sharp3      Entrada   - Puerto del micro que lee el medidor 3           ##
## const int    sharp4      Entrada   - Puerto del micro que lee el medidor 4           ##
##                                                                                      ##
########################################################################################*/

void init_sharps(const int sharp1, const int sharp2, const int sharp3, const int sharp4){
    pinMode(sharp1,INPUT);  //Verde
    pinMode(sharp2,INPUT);  //Blanco
    pinMode(sharp3,INPUT);  //Azul
    pinMode(sharp4,INPUT);  //Naranja
}

/*########################################################################################
## ---------------------------  measure_sharps_raw     -------------------------------- ##
##                                                                                      ##
## Esta función se utiliza para tomar las medidas de los ADC de los puertos             ##
## conectados a los 4 medidores de distancia principales, las medidas son almacenadas   ##
## en las variables globales Sharp1_adc, Sharp2_adc, Sharp3_adc, Sharp4_adc             ##
##                                                                                      ##
##------------------------------------Variables---------------------------------------- ##
##                                                                                      ##
## Tamaño       Nombre      Tipo      Función                                           ##
##                                                                                      ##
## const int    sharp1      Entrada   - Puerto del micro que lee el medidor 1           ##
## const int    sharp2      Entrada   - Puerto del micro que lee el medidor 2           ##
## const int    sharp3      Entrada   - Puerto del micro que lee el medidor 3           ##
## const int    sharp4      Entrada   - Puerto del micro que lee el medidor 4           ##
##                                                                                      ##
########################################################################################*/

void measure_sharps_raw(const int sharp1, const int sharp2, const int sharp3, const int sharp4){
    Sharp1_adc=analogRead(sharp1);
    Sharp2_adc=analogRead(sharp2);
    Sharp3_adc=analogRead(sharp3);
    Sharp4_adc=analogRead(sharp4);
}

/*########################################################################################
## ---------------------------  measure_sharps_volt    -------------------------------- ##
##                                                                                      ##
## Esta función convierte a voltaje las medidas de los ADC conectados a los medidores   ##
## de distancia principales, los valores son almacenados en las variables globales      ##
## Sharp1_volt, Sharp2_volt, Sharp3_volt, Sharp4_volt                                   ##
##                                                                                      ##
##------------------------------------Variables---------------------------------------- ##
##                                                                                      ##
########################################################################################*/

void measure_sharps_volt(){
    Sharp1_volt=Sharp1_adc * (Vcc_ / 1023.0);
    Sharp2_volt=Sharp2_adc * (Vcc_ / 1023.0);
    Sharp3_volt=Sharp3_adc * (Vcc_ / 1023.0);
    Sharp4_volt=Sharp4_adc * (Vcc_ / 1023.0);
}

/*########################################################################################
## ---------------------------       getADC_sharp      -------------------------------- ##
##                                                                                      ##
## Esta función devuelve la medida del ADC de cualquiera de los 4 medidores principales,##
## es decir, regrasa las variables globales Sharp1_adc, Sharp2_adc, Sharp3_adc          ##
## Sharp4_adc, dependiendo del num_sharp especificado                                   ##
##                                                                                      ##
##------------------------------------Variables---------------------------------------- ##
##                                                                                      ##
## Tamaño       Nombre      Tipo      Función                                           ##
##                                                                                      ##
## int          num_sharp   Entrada   - 1,2,3 o 4; especifica el número del medidor     ##
## int                      Salida    - Medida del ADC del medidor de distancia         ##
##                                                                                      ##
########################################################################################*/

int getADC_sharp(int num_sharp){
  switch(num_sharp){
    case 1:
      return Sharp1_adc;
      break;
    case 2:
      return Sharp2_adc;
      break;
    case 3:
      return Sharp3_adc;
      break;
    case 4:
      return Sharp4_adc;
      break;
  }
}

/*########################################################################################
## ---------------------------       getVolt_sharp      ------------------------------- ##
##                                                                                      ##
## Esta función devuelve la medida en voltaje del ADC de cualquiera de los 4 medidores  ##
## principales, es decir, regrasa las variables globales Sharp1_volt, Sharp2_volt,      ##
## Sharp3_volt, Sharp4_volt, dependiendo del num_sharp especificado                     ##
##                                                                                      ##
##------------------------------------Variables---------------------------------------- ##
##                                                                                      ##
## Tamaño       Nombre      Tipo      Función                                           ##
##                                                                                      ##
## int          num_sharp   Entrada   - 1,2,3 o 4; especifica el número del medidor     ##
## int                      Salida    - Medida en voltaje del ADC del medidor de        ##
##                                      distancia                                       ##
##                                                                                      ##
########################################################################################*/

float getVolt_sharp(int num_sharp){
  switch(num_sharp){
    case 1:
      return Sharp1_volt;
      break;
    case 2:
      return Sharp2_volt;
      break;
    case 3:
      return Sharp3_volt;
      break;
    case 4:
      return Sharp4_volt;
      break;
  }
}
