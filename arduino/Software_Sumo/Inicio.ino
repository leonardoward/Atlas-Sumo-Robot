//######################################################################################################################
//##                                           Tiempo de espera inicial                                               ##
//######################################################################################################################

/*########################################################################################
## ------------------------------    contador_inicial    ------------------------------ ##
##                                                                                      ##
## Esta función utiliza la función millis() para leer el tiempo del programa y esperar  ##
## a que transcurra un tiempo llamado "tiempo_espera" después del cual la variable      ##
## booleana contador_ini pasa a LOW (por lo que la función solo se ejecuta una vez)     ##
## cuando la variable contador_ini pasa a LOW, se incia el movimiento de los motores    ##
##                                                                                      ##
##------------------------------------Variables---------------------------------------- ##
##                                                                                      ##
## Tamaño   Nombre          Tipo      Función                                           ##
## int      tiempo_espera   Entrada   -Define el tiempo que la función espera para      ##
##                                     igualar la variable contador_ini a LOW           ##
##                                                                                      ##
########################################################################################*/

void contador_inicial(int tiempo_espera){
    if(contador_ini){
      ahora_contIni = millis();
      deltaT_contIni= ahora_contIni - pasado_contIni;
      if(deltaT_contIni>= tiempo_espera){
        //Serial.println("Iniciado");
        contador_ini=LOW;
      }
  }
}
