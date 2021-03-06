EESchema Schematic File Version 2
LIBS:power
LIBS:device
LIBS:transistors
LIBS:conn
LIBS:linear
LIBS:regul
LIBS:74xx
LIBS:cmos4000
LIBS:adc-dac
LIBS:memory
LIBS:xilinx
LIBS:microcontrollers
LIBS:dsp
LIBS:microchip
LIBS:analog_switches
LIBS:motorola
LIBS:texas
LIBS:intel
LIBS:audio
LIBS:interface
LIBS:digital-audio
LIBS:philips
LIBS:display
LIBS:cypress
LIBS:siliconi
LIBS:opto
LIBS:atmel
LIBS:contrib
LIBS:valves
LIBS:d24v22f5
LIBS:GP2Y0A60SZLF
LIBS:qtr-1a
LIBS:u3v50ahv
LIBS:arduino_nano
LIBS:logic_level_shifter
LIBS:raspberry_pi_3_b
LIBS:camera_module_v2
LIBS:16gb_sdhc
LIBS:motor_ta0330
LIBS:mma7361
LIBS:tlc2543cn
LIBS:acs711
LIBS:Sumo-cache
EELAYER 25 0
EELAYER END
$Descr A4 11693 8268
encoding utf-8
Sheet 1 1
Title ""
Date ""
Rev ""
Comp ""
Comment1 ""
Comment2 ""
Comment3 ""
Comment4 ""
$EndDescr
$Comp
L D24V22F5 U1
U 1 1 579958EE
P 2400 2100
F 0 "U1" H 2400 2500 60  0000 C CNN
F 1 "D24V22F5" H 2400 1800 60  0000 C CNN
F 2 "" H 2400 2500 60  0000 C CNN
F 3 "" H 2400 2500 60  0000 C CNN
	1    2400 2100
	1    0    0    -1  
$EndComp
$Comp
L Battery 12V
U 1 1 57995A3B
P 700 2100
F 0 "12V" H 800 2150 50  0000 L CNN
F 1 "Battery" H 800 2050 50  0000 L CNN
F 2 "" V 700 2140 50  0000 C CNN
F 3 "" V 700 2140 50  0000 C CNN
	1    700  2100
	1    0    0    -1  
$EndComp
$Comp
L QTR-1A U15
U 1 1 579E1B29
P 2300 6200
F 0 "U15" H 2300 6400 60  0000 C CNN
F 1 "QTR-1A" H 2300 5950 60  0000 C CNN
F 2 "" H 2300 6200 60  0000 C CNN
F 3 "" H 2300 6200 60  0000 C CNN
	1    2300 6200
	1    0    0    -1  
$EndComp
$Comp
L QTR-1A U16
U 1 1 579E1BB4
P 3450 6200
F 0 "U16" H 3450 6400 60  0000 C CNN
F 1 "QTR-1A" H 3450 5950 60  0000 C CNN
F 2 "" H 3450 6200 60  0000 C CNN
F 3 "" H 3450 6200 60  0000 C CNN
	1    3450 6200
	1    0    0    -1  
$EndComp
$Comp
L QTR-1A U17
U 1 1 579E1C73
P 4650 6200
F 0 "U17" H 4650 6400 60  0000 C CNN
F 1 "QTR-1A" H 4650 5950 60  0000 C CNN
F 2 "" H 4650 6200 60  0000 C CNN
F 3 "" H 4650 6200 60  0000 C CNN
	1    4650 6200
	1    0    0    -1  
$EndComp
$Comp
L QTR-1A U18
U 1 1 579E1CD2
P 5750 6200
F 0 "U18" H 5750 6400 60  0000 C CNN
F 1 "QTR-1A" H 5750 5950 60  0000 C CNN
F 2 "" H 5750 6200 60  0000 C CNN
F 3 "" H 5750 6200 60  0000 C CNN
	1    5750 6200
	1    0    0    -1  
$EndComp
$Comp
L QTR-1A U19
U 1 1 579E1D31
P 6850 6200
F 0 "U19" H 6850 6400 60  0000 C CNN
F 1 "QTR-1A" H 6850 5950 60  0000 C CNN
F 2 "" H 6850 6200 60  0000 C CNN
F 3 "" H 6850 6200 60  0000 C CNN
	1    6850 6200
	1    0    0    -1  
$EndComp
$Comp
L QTR-1A U20
U 1 1 579E1D78
P 7950 6200
F 0 "U20" H 7950 6400 60  0000 C CNN
F 1 "QTR-1A" H 7950 5950 60  0000 C CNN
F 2 "" H 7950 6200 60  0000 C CNN
F 3 "" H 7950 6200 60  0000 C CNN
	1    7950 6200
	1    0    0    -1  
$EndComp
$Comp
L QTR-1A U21
U 1 1 579E1DCB
P 9050 6200
F 0 "U21" H 9050 6400 60  0000 C CNN
F 1 "QTR-1A" H 9050 5950 60  0000 C CNN
F 2 "" H 9050 6200 60  0000 C CNN
F 3 "" H 9050 6200 60  0000 C CNN
	1    9050 6200
	1    0    0    -1  
$EndComp
$Comp
L QTR-1A U22
U 1 1 579E1E2C
P 10350 6200
F 0 "U22" H 10350 6400 60  0000 C CNN
F 1 "QTR-1A" H 10350 5950 60  0000 C CNN
F 2 "" H 10350 6200 60  0000 C CNN
F 3 "" H 10350 6200 60  0000 C CNN
	1    10350 6200
	1    0    0    -1  
$EndComp
Text GLabel 850  2450 2    60   Input ~ 0
GND
Text GLabel 850  1700 2    60   Output ~ 0
12V
Text GLabel 1750 2050 0    55   Input ~ 0
12V
Text GLabel 1750 2150 0    55   Output ~ 0
GND
Text GLabel 1700 2250 0    55   Output ~ 0
5V
Text GLabel 1750 6200 0    55   Input ~ 0
5V
Text GLabel 2900 6200 0    55   Input ~ 0
5V
Text GLabel 4100 6200 0    55   Input ~ 0
5V
Text GLabel 5200 6200 0    55   Input ~ 0
5V
Text GLabel 6300 6200 0    55   Input ~ 0
5V
Text GLabel 7400 6200 0    55   Input ~ 0
5V
Text GLabel 8500 6200 0    55   Input ~ 0
5V
Text GLabel 9800 6200 0    55   Input ~ 0
5V
Text GLabel 1800 6300 0    55   Output ~ 0
GND
Text GLabel 2950 6300 0    55   Output ~ 0
GND
Text GLabel 4150 6300 0    55   Output ~ 0
GND
Text GLabel 5250 6300 0    55   Output ~ 0
GND
Text GLabel 6350 6300 0    55   Output ~ 0
GND
Text GLabel 7450 6300 0    55   Output ~ 0
GND
Text GLabel 8550 6300 0    55   Output ~ 0
GND
Text GLabel 9850 6300 0    55   Output ~ 0
GND
$Comp
L GP2Y0A60SZLF U10
U 1 1 579E6C28
P 1050 5400
F 0 "U10" H 1050 5700 55  0000 C CNN
F 1 "GP2Y0A60SZLF" H 1050 5050 55  0000 C CNN
F 2 "" H 1050 5400 55  0000 C CNN
F 3 "" H 1050 5400 55  0000 C CNN
	1    1050 5400
	1    0    0    -1  
$EndComp
$Comp
L GP2Y0A60SZLF U11
U 1 1 579E6C97
P 3100 5400
F 0 "U11" H 3100 5700 55  0000 C CNN
F 1 "GP2Y0A60SZLF" H 3100 5050 55  0000 C CNN
F 2 "" H 3100 5400 55  0000 C CNN
F 3 "" H 3100 5400 55  0000 C CNN
	1    3100 5400
	1    0    0    -1  
$EndComp
$Comp
L GP2Y0A60SZLF U13
U 1 1 579E6D10
P 7450 5400
F 0 "U13" H 7450 5700 55  0000 C CNN
F 1 "GP2Y0A60SZLF" H 7450 5050 55  0000 C CNN
F 2 "" H 7450 5400 55  0000 C CNN
F 3 "" H 7450 5400 55  0000 C CNN
	1    7450 5400
	1    0    0    -1  
$EndComp
$Comp
L GP2Y0A60SZLF U12
U 1 1 579E6D8B
P 5100 5400
F 0 "U12" H 5100 5700 55  0000 C CNN
F 1 "GP2Y0A60SZLF" H 5100 5050 55  0000 C CNN
F 2 "" H 5100 5400 55  0000 C CNN
F 3 "" H 5100 5400 55  0000 C CNN
	1    5100 5400
	1    0    0    -1  
$EndComp
Text GLabel 1700 5500 2    55   Input ~ 0
5V
Text GLabel 3750 5500 2    55   Input ~ 0
5V
Text GLabel 5750 5500 2    55   Input ~ 0
5V
Text GLabel 8100 5500 2    55   Input ~ 0
5V
Text GLabel 1650 5650 2    55   Output ~ 0
GND
Text GLabel 3700 5650 2    55   Output ~ 0
GND
Text GLabel 5700 5650 2    55   Output ~ 0
GND
Text GLabel 8050 5650 2    55   Output ~ 0
GND
$Comp
L ARDUINO_NANO U4
U 1 1 57A79BAF
P 9650 2400
F 0 "U4" H 9800 3350 60  0000 C CNN
F 1 "ARDUINO_NANO" H 10100 1500 60  0000 C CNN
F 2 "" H 9650 2400 60  0000 C CNN
F 3 "" H 9650 2400 60  0000 C CNN
	1    9650 2400
	1    0    0    -1  
$EndComp
$Comp
L LOGIC_LEVEL_SHIFTER U3
U 1 1 57A7A26C
P 6950 1950
F 0 "U3" H 6950 2300 60  0000 C CNN
F 1 "LOGIC_LEVEL_SHIFTER" H 6950 1550 60  0000 C CNN
F 2 "" H 6950 1950 60  0000 C CNN
F 3 "" H 6950 1950 60  0000 C CNN
	1    6950 1950
	1    0    0    -1  
$EndComp
$Comp
L RASPBERRY_PI_3_B U2
U 1 1 57A7A89A
P 4800 2450
F 0 "U2" H 4800 3600 60  0000 C CNN
F 1 "RASPBERRY_PI_3_B" H 4800 3450 60  0000 C CNN
F 2 "" H 4800 2450 60  0000 C CNN
F 3 "" H 4800 2450 60  0000 C CNN
	1    4800 2450
	1    0    0    -1  
$EndComp
$Comp
L CAMERA_MODULE_V2 U5
U 1 1 57A7B4D8
P 3400 3950
F 0 "U5" H 3400 4200 60  0000 C CNN
F 1 "CAMERA_MODULE_V2" H 3400 3700 60  0000 C CNN
F 2 "" H 3450 3950 60  0000 C CNN
F 3 "" H 3450 3950 60  0000 C CNN
	1    3400 3950
	1    0    0    -1  
$EndComp
$Comp
L 16GB_SDHC U6
U 1 1 57A7C377
P 5700 3950
F 0 "U6" H 5700 4150 60  0000 C CNN
F 1 "16GB_SDHC" H 5750 3750 60  0000 C CNN
F 2 "" H 5700 3950 60  0000 C CNN
F 3 "" H 5700 3950 60  0000 C CNN
	1    5700 3950
	1    0    0    -1  
$EndComp
Wire Wire Line
	700  2250 700  2450
Wire Wire Line
	700  2450 850  2450
Wire Wire Line
	850  1700 700  1700
Wire Wire Line
	700  1700 700  1950
Wire Wire Line
	1750 2150 1900 2150
Wire Wire Line
	1750 2050 1900 2050
Wire Wire Line
	1700 2250 1900 2250
Wire Wire Line
	9800 6200 9900 6200
Wire Wire Line
	8500 6200 8600 6200
Wire Wire Line
	7500 6200 7400 6200
Wire Wire Line
	6400 6200 6300 6200
Wire Wire Line
	5300 6200 5200 6200
Wire Wire Line
	4200 6200 4100 6200
Wire Wire Line
	3000 6200 2900 6200
Wire Wire Line
	1850 6200 1750 6200
Wire Wire Line
	9850 6300 9900 6300
Wire Wire Line
	8550 6300 8600 6300
Wire Wire Line
	7450 6300 7500 6300
Wire Wire Line
	6350 6300 6400 6300
Wire Wire Line
	5250 6300 5300 6300
Wire Wire Line
	4150 6300 4200 6300
Wire Wire Line
	2950 6300 3000 6300
Wire Wire Line
	1800 6300 1850 6300
Wire Wire Line
	7950 5500 8100 5500
Wire Wire Line
	5600 5500 5750 5500
Wire Wire Line
	3600 5500 3750 5500
Wire Wire Line
	1550 5500 1700 5500
Wire Wire Line
	7950 5650 8050 5650
Wire Wire Line
	5600 5650 5700 5650
Wire Wire Line
	3600 5650 3700 5650
Wire Wire Line
	1550 5650 1650 5650
Wire Wire Line
	4100 3950 4400 3950
Wire Wire Line
	4400 3950 4400 3700
Wire Wire Line
	5200 3700 5200 3950
Wire Wire Line
	5200 3950 5300 3950
Wire Wire Line
	6550 1750 6300 1750
Wire Wire Line
	3550 1150 3550 1550
Wire Wire Line
	3550 1550 3800 1550
Wire Wire Line
	5900 1850 6550 1850
Wire Wire Line
	6550 1950 5900 1950
Text GLabel 8950 1800 0    60   Input ~ 0
TX_RASPB
Text GLabel 8950 1700 0    60   Output ~ 0
RX_RASPB
Wire Wire Line
	9050 1800 8950 1800
Wire Wire Line
	3550 1150 6300 1150
Wire Wire Line
	6300 1150 6300 1750
Text GLabel 7550 1700 2    60   Input ~ 0
5V
Text GLabel 7550 1850 2    60   Output ~ 0
TX_RASPB
Text GLabel 7550 2000 2    60   Input ~ 0
RX_RASPB
Wire Wire Line
	7350 1950 7450 1950
Wire Wire Line
	7450 1950 7450 2000
Wire Wire Line
	7450 2000 7550 2000
Wire Wire Line
	7550 1850 7350 1850
Wire Wire Line
	7350 1700 7550 1700
Wire Wire Line
	7350 1700 7350 1750
Text GLabel 10400 1800 2    60   Output ~ 0
GND
Wire Wire Line
	10250 1800 10400 1800
Wire Wire Line
	9050 1700 8950 1700
Text GLabel 1650 5350 2    60   Output ~ 0
SHARP_1
Text GLabel 3750 5350 2    60   Output ~ 0
SHARP_2
Text GLabel 5700 5350 2    60   Output ~ 0
SHARP_3
Text GLabel 8050 5350 2    60   Output ~ 0
SHARP_4
Wire Wire Line
	7950 5350 8050 5350
Wire Wire Line
	5600 5350 5700 5350
Wire Wire Line
	3600 5350 3750 5350
Wire Wire Line
	1550 5350 1650 5350
Text GLabel 10350 2800 2    60   Input ~ 0
SHARP_1
Text GLabel 10350 2700 2    60   Input ~ 0
SHARP_2
Text GLabel 10350 2600 2    60   Input ~ 0
SHARP_3
Text GLabel 10350 2500 2    60   Input ~ 0
SHARP_4
Wire Wire Line
	10250 2500 10350 2500
Wire Wire Line
	10250 2600 10350 2600
Wire Wire Line
	10250 2700 10350 2700
Wire Wire Line
	10250 2800 10350 2800
$Comp
L MOTOR_TA0330 U23
U 1 1 57A8E821
P 2250 7300
F 0 "U23" H 2250 7650 60  0000 C CNN
F 1 "MOTOR_TA0330" H 2250 6900 60  0000 C CNN
F 2 "" H 2250 7300 60  0000 C CNN
F 3 "" H 2250 7300 60  0000 C CNN
	1    2250 7300
	1    0    0    -1  
$EndComp
$Comp
L MOTOR_TA0330 U24
U 1 1 57A8E8EA
P 4750 7300
F 0 "U24" H 4750 7650 60  0000 C CNN
F 1 "MOTOR_TA0330" H 4750 6900 60  0000 C CNN
F 2 "" H 4750 7300 60  0000 C CNN
F 3 "" H 4750 7300 60  0000 C CNN
	1    4750 7300
	1    0    0    -1  
$EndComp
Text GLabel 1500 7050 0    60   Input ~ 0
12V
Text GLabel 1500 7550 0    60   Input ~ 0
5V
Text GLabel 1500 7300 0    60   Output ~ 0
IP1+
Wire Wire Line
	1500 7050 1600 7050
Wire Wire Line
	1500 7300 1600 7300
Wire Wire Line
	1500 7550 1600 7550
Text GLabel 3900 7050 0    60   Input ~ 0
12V
Text GLabel 3900 7550 0    60   Input ~ 0
5V
Text GLabel 3900 7300 0    60   Output ~ 0
IP2+
Wire Wire Line
	3900 7050 4100 7050
Wire Wire Line
	3900 7300 4100 7300
Wire Wire Line
	3900 7550 4100 7550
Text GLabel 3050 7000 2    60   Output ~ 0
ENC_M1
Text GLabel 3000 7150 2    60   Input ~ 0
F/W_M1
Text GLabel 3000 7350 2    60   Input ~ 0
PWM_M1
Text GLabel 3000 7550 2    60   Input ~ 0
EN_M1
Wire Wire Line
	2900 7050 3000 7050
Wire Wire Line
	2900 7150 3000 7150
Wire Wire Line
	2900 7350 3000 7350
Wire Wire Line
	2900 7550 3000 7550
Text GLabel 5550 7000 2    60   Output ~ 0
ENC_M2
Text GLabel 5500 7150 2    60   Input ~ 0
F/W_M2
Text GLabel 5500 7350 2    60   Input ~ 0
PWM_M2
Text GLabel 5500 7550 2    60   Input ~ 0
EN_M2
Wire Wire Line
	5400 7050 5500 7050
Wire Wire Line
	5400 7150 5500 7150
Wire Wire Line
	5400 7350 5500 7350
Wire Wire Line
	5400 7550 5500 7550
Text GLabel 8950 2100 0    60   Input ~ 0
ENC_M1
Wire Wire Line
	3050 7000 3000 7000
Wire Wire Line
	3000 7000 3000 7050
Wire Wire Line
	5500 7050 5500 7000
Wire Wire Line
	5500 7000 5550 7000
Text GLabel 8950 2200 0    60   Input ~ 0
ENC_M2
Wire Wire Line
	8950 2100 9050 2100
Wire Wire Line
	8950 2200 9050 2200
Text GLabel 8950 2400 0    60   Output ~ 0
PWM_M1
Text GLabel 8950 2500 0    60   Output ~ 0
PWM_M2
Wire Wire Line
	8950 2400 9050 2400
Wire Wire Line
	8950 2500 9050 2500
Text GLabel 8950 2600 0    60   Output ~ 0
EN_M1
Text GLabel 8950 2700 0    60   Output ~ 0
EN_M2
Text GLabel 8950 2800 0    60   Output ~ 0
F/R_M1
Text GLabel 8950 2300 0    60   Output ~ 0
F/R_M2
Wire Wire Line
	8950 2600 9050 2600
Wire Wire Line
	8950 2700 9050 2700
Wire Wire Line
	8950 2800 9050 2800
Wire Wire Line
	5900 2050 6550 2050
Wire Wire Line
	9050 1900 8150 1900
Wire Wire Line
	8150 1900 8150 2100
Wire Wire Line
	8150 2100 7500 2100
Wire Wire Line
	7500 2100 7500 2050
Wire Wire Line
	7500 2050 7350 2050
Text GLabel 10400 1700 2    60   Input ~ 0
12V
Wire Wire Line
	10400 1700 10250 1700
Wire Wire Line
	8950 2900 9050 2900
$Comp
L R 10K
U 1 1 57A9A312
P 1800 1650
F 0 "10K" V 1880 1650 50  0000 C CNN
F 1 "R" V 1800 1650 50  0000 C CNN
F 2 "" V 1730 1650 50  0000 C CNN
F 3 "" H 1800 1650 50  0000 C CNN
	1    1800 1650
	1    0    0    -1  
$EndComp
Wire Wire Line
	1800 1500 2950 1500
Wire Wire Line
	2950 1500 2950 2500
Wire Wire Line
	2950 2500 1800 2500
Wire Wire Line
	1800 2500 1800 2250
Connection ~ 1800 2250
$Comp
L MMA7361 U14
U 1 1 57B46672
P 9850 5450
F 0 "U14" H 9850 5800 60  0000 C CNN
F 1 "MMA7361" H 9850 5050 60  0000 C CNN
F 2 "" H 9850 5450 60  0000 C CNN
F 3 "" H 9850 5450 60  0000 C CNN
	1    9850 5450
	1    0    0    -1  
$EndComp
Text GLabel 9050 5250 0    60   Output ~ 0
X_acc
Text GLabel 9050 5350 0    60   Output ~ 0
Y_acc
Text GLabel 9050 5450 0    60   Output ~ 0
Z_acc
Text GLabel 10650 5250 2    60   Input ~ 0
5V
Text GLabel 10650 5450 2    60   Output ~ 0
GND
Wire Wire Line
	10650 5250 10500 5250
Wire Wire Line
	10650 5450 10500 5450
Wire Wire Line
	9050 5250 9200 5250
Wire Wire Line
	9050 5350 9200 5350
Wire Wire Line
	9050 5450 9200 5450
Text GLabel 8600 5550 0    60   Input ~ 0
5V
$Comp
L R 10K
U 1 1 57B47518
P 8850 5550
F 0 "10K" V 8930 5550 50  0000 C CNN
F 1 "R" V 8850 5550 50  0000 C CNN
F 2 "" V 8780 5550 50  0000 C CNN
F 3 "" H 8850 5550 50  0000 C CNN
	1    8850 5550
	0    1    1    0   
$EndComp
Wire Wire Line
	9000 5550 9200 5550
Wire Wire Line
	8600 5550 8700 5550
Text GLabel 10650 5550 2    60   Output ~ 0
GND
Wire Wire Line
	10500 5550 10650 5550
Wire Wire Line
	8950 3000 9050 3000
Wire Wire Line
	10250 2300 10350 2300
Wire Wire Line
	10250 2400 10350 2400
Text GLabel 5500 7250 2    60   Output ~ 0
GND
Text GLabel 3000 7250 2    60   Output ~ 0
GND
Wire Wire Line
	5500 7250 5400 7250
Wire Wire Line
	2900 7250 3000 7250
$Comp
L TLC2543CN U7
U 1 1 57B4E62D
P 8500 4200
F 0 "U7" H 8500 4700 60  0000 C CNN
F 1 "TLC2543CN" H 8500 3550 60  0000 C CNN
F 2 "" H 8500 4200 60  0000 C CNN
F 3 "" H 8500 4200 60  0000 C CNN
	1    8500 4200
	1    0    0    -1  
$EndComp
Text GLabel 1800 6100 0    60   Output ~ 0
QTR1
Text GLabel 2950 6100 0    60   Output ~ 0
QTR2
Text GLabel 4150 6100 0    60   Output ~ 0
QTR3
Text GLabel 5250 6100 0    60   Output ~ 0
QTR4
Text GLabel 6350 6100 0    60   Output ~ 0
QTR5
Text GLabel 7450 6100 0    60   Output ~ 0
QTR6
Text GLabel 8550 6100 0    60   Output ~ 0
QTR7
Text GLabel 9850 6100 0    60   Output ~ 0
QTR8
Wire Wire Line
	9850 6100 9900 6100
Wire Wire Line
	8550 6100 8600 6100
Wire Wire Line
	7450 6100 7500 6100
Wire Wire Line
	6350 6100 6400 6100
Wire Wire Line
	5250 6100 5300 6100
Wire Wire Line
	4150 6100 4200 6100
Wire Wire Line
	1800 6100 1850 6100
Wire Wire Line
	2950 6100 3000 6100
Text GLabel 7700 3800 0    60   Input ~ 0
QTR1
Text GLabel 7700 3900 0    60   Input ~ 0
QTR2
Text GLabel 7700 4000 0    60   Input ~ 0
QTR3
Text GLabel 7700 4100 0    60   Input ~ 0
QTR4
Text GLabel 7700 4200 0    60   Input ~ 0
QTR5
Text GLabel 7700 4300 0    60   Input ~ 0
QTR6
Text GLabel 7700 4400 0    60   Input ~ 0
QTR7
Text GLabel 7700 4500 0    60   Input ~ 0
QTR8
Wire Wire Line
	7700 3800 7800 3800
Wire Wire Line
	7800 3900 7700 3900
Wire Wire Line
	7700 4000 7800 4000
Wire Wire Line
	7700 4100 7800 4100
Wire Wire Line
	7700 4200 7800 4200
Wire Wire Line
	7700 4300 7800 4300
Wire Wire Line
	7700 4400 7800 4400
Wire Wire Line
	7700 4500 7800 4500
Text GLabel 7700 4600 0    60   Input ~ 0
X_acc
Text GLabel 9350 4700 2    60   Input ~ 0
Y_acc
Text GLabel 9350 4600 2    60   Input ~ 0
Z_acc
Wire Wire Line
	7700 4600 7800 4600
Wire Wire Line
	9200 4600 9350 4600
Wire Wire Line
	9200 4700 9350 4700
Text GLabel 7700 4700 0    60   Output ~ 0
GND
Wire Wire Line
	7700 4700 7800 4700
Text GLabel 9350 3800 2    60   Input ~ 0
5V
Wire Wire Line
	9200 3800 9350 3800
$Comp
L ACS711 U8
U 1 1 57B58BD8
P 2450 4700
F 0 "U8" H 2450 5000 60  0000 C CNN
F 1 "ACS711" H 2450 4400 60  0000 C CNN
F 2 "" H 2450 4700 60  0000 C CNN
F 3 "" H 2450 4700 60  0000 C CNN
	1    2450 4700
	1    0    0    -1  
$EndComp
$Comp
L ACS711 U9
U 1 1 57B58C39
P 4400 4700
F 0 "U9" H 4400 5000 60  0000 C CNN
F 1 "ACS711" H 4400 4400 60  0000 C CNN
F 2 "" H 4400 4700 60  0000 C CNN
F 3 "" H 4400 4700 60  0000 C CNN
	1    4400 4700
	1    0    0    -1  
$EndComp
Text GLabel 1900 4600 0    60   Input ~ 0
IP1+
Text GLabel 3850 4600 0    60   Input ~ 0
IP2+
Text GLabel 2950 4600 2    60   Output ~ 0
CURRENT1
Text GLabel 4900 4600 2    60   Output ~ 0
CURRENT2
Text GLabel 2950 4700 2    60   Input ~ 0
5V
Text GLabel 4900 4700 2    60   Input ~ 0
5V
Text GLabel 4900 4800 2    60   Output ~ 0
GND
Text GLabel 2950 4800 2    60   Output ~ 0
GND
Text GLabel 1900 4850 0    60   Output ~ 0
GND
Text GLabel 3850 4850 0    60   Output ~ 0
GND
Wire Wire Line
	1900 4600 2000 4600
Wire Wire Line
	1900 4850 2000 4850
Wire Wire Line
	2950 4600 2900 4600
Wire Wire Line
	2900 4700 2950 4700
Wire Wire Line
	2900 4800 2950 4800
Wire Wire Line
	3950 4600 3850 4600
Wire Wire Line
	3950 4850 3850 4850
Wire Wire Line
	4900 4600 4850 4600
Wire Wire Line
	4900 4700 4850 4700
Wire Wire Line
	4900 4800 4850 4800
Text GLabel 10350 2400 2    60   Input ~ 0
CURRENT1
Text GLabel 10350 2300 2    60   Input ~ 0
CURRENT2
Text GLabel 8950 2900 0    60   Input ~ 0
CS_ADC
Text GLabel 8950 3000 0    60   Output ~ 0
MOSI_ADC
Text GLabel 9350 4100 2    60   Input ~ 0
MOSI_ADC
Text GLabel 9350 4200 2    60   Output ~ 0
MISO_ADC
Wire Wire Line
	9200 4100 9350 4100
Wire Wire Line
	9200 4200 9350 4200
Text GLabel 9350 4300 2    60   Input ~ 0
CS_ADC
Text GLabel 9350 4400 2    60   Input ~ 0
5V
Text GLabel 9350 4500 2    60   Output ~ 0
GND
Wire Wire Line
	9350 4300 9200 4300
Wire Wire Line
	9200 4400 9350 4400
Wire Wire Line
	9350 4500 9200 4500
Text GLabel 9350 4000 2    60   Input ~ 0
SCK_ADC
Wire Wire Line
	9200 4000 9350 4000
Text GLabel 10350 3100 2    60   Output ~ 0
SCK_ADC
Wire Wire Line
	10250 3100 10350 3100
Text GLabel 8950 3100 0    60   Output ~ 0
MISO_ADC
Wire Wire Line
	8950 3100 9050 3100
Wire Wire Line
	8950 2300 9050 2300
Wire Wire Line
	1900 1850 1800 1850
Wire Wire Line
	1800 1850 1800 1800
$EndSCHEMATC
