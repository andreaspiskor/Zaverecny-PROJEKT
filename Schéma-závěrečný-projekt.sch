EESchema Schematic File Version 4
EELAYER 30 0
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
L Display_Character:NHD-C0220BIZ U1
U 1 1 5FEC1A04
P 7050 4500
F 0 "U1" H 7050 5181 50  0000 L CNN
F 1 "Display 16x2 I2C" H 7050 5090 50  0000 L TNN
F 2 "Display:NHD-C0220BiZ" H 7050 3900 50  0001 C CNN
F 3 "http://www.newhavendisplay.com/specs/NHD-C0220BiZ-FSW-FBW-3V3M.pdf" H 6750 5100 50  0001 C CNN
	1    7050 4500
	1    0    0    1   
$EndComp
$Comp
L Device:Speaker S1
U 1 1 5FED3413
P 3300 3300
F 0 "S1" H 3470 3296 50  0000 L CNN
F 1 "Speaker" H 3470 3205 50  0000 L CNN
F 2 "" H 3300 3100 50  0001 C CNN
F 3 "~" H 3290 3250 50  0001 C CNN
	1    3300 3300
	1    0    0    -1  
$EndComp
$Comp
L Switch:SW_Push B1
U 1 1 5FED4BFB
P 7750 2950
F 0 "B1" H 7750 3235 50  0000 C CNN
F 1 "Button" H 7750 3144 50  0000 C CNN
F 2 "" H 7750 3150 50  0001 C CNN
F 3 "~" H 7750 3150 50  0001 C CNN
	1    7750 2950
	1    0    0    -1  
$EndComp
$Comp
L Device:R R2
U 1 1 5FEDACD0
P 4100 2750
F 0 "R2" H 4170 2796 50  0000 L CNN
F 1 "220" H 4170 2705 50  0000 L CNN
F 2 "" V 4030 2750 50  0001 C CNN
F 3 "~" H 4100 2750 50  0001 C CNN
	1    4100 2750
	1    0    0    -1  
$EndComp
$Comp
L Device:R R3
U 1 1 5FEDBE1D
P 4450 2750
F 0 "R3" H 4520 2796 50  0000 L CNN
F 1 "220" H 4520 2705 50  0000 L CNN
F 2 "" V 4380 2750 50  0001 C CNN
F 3 "~" H 4450 2750 50  0001 C CNN
	1    4450 2750
	1    0    0    -1  
$EndComp
$Comp
L Device:R R1
U 1 1 5FEDCA9E
P 3100 2800
F 0 "R1" H 3170 2846 50  0000 L CNN
F 1 "100" H 3170 2755 50  0000 L CNN
F 2 "" V 3030 2800 50  0001 C CNN
F 3 "~" H 3100 2800 50  0001 C CNN
	1    3100 2800
	1    0    0    -1  
$EndComp
Wire Bus Line
	2900 2500 8650 2500
Wire Bus Line
	2800 5500 8800 5500
Text Notes 8650 5450 0    50   ~ 0
GND
Text Notes 8450 2450 0    50   ~ 0
+ 5V
$Comp
L Device:Battery +9V1
U 1 1 5FEE3F95
P 8500 5050
F 0 "+9V1" H 8608 5096 50  0000 L CNN
F 1 "Battery" H 8608 5005 50  0000 L CNN
F 2 "" V 8500 5110 50  0001 C CNN
F 3 "~" V 8500 5110 50  0001 C CNN
	1    8500 5050
	1    0    0    -1  
$EndComp
Wire Wire Line
	8500 5250 8500 5500
$Comp
L MCU_Module:Arduino_Nano_Every U0
U 1 1 5FEB9331
P 5650 4000
F 0 "U0" H 5650 2911 50  0000 L CNN
F 1 "Arduino_Nano" H 5650 2820 50  0000 L CNN
F 2 "Module:Arduino_Nano" H 5650 4000 50  0001 C CIN
F 3 "https://content.arduino.cc/assets/NANOEveryV3.0_sch.pdf" H 5650 4000 50  0001 C CNN
	1    5650 4000
	1    0    0    -1  
$EndComp
Wire Wire Line
	8500 4850 8500 2950
Wire Wire Line
	8500 2950 7950 2950
Wire Wire Line
	7550 2950 5550 2950
Wire Wire Line
	5550 2950 5550 3000
Wire Wire Line
	6650 4500 6150 4500
Wire Wire Line
	6650 4600 6400 4600
Wire Wire Line
	6400 4600 6400 4400
Wire Wire Line
	6400 4400 6150 4400
Wire Wire Line
	7050 5000 7050 5500
Wire Wire Line
	7050 4000 7050 2500
Wire Wire Line
	5650 5000 5650 5500
Wire Wire Line
	5850 3000 5850 2500
Wire Wire Line
	5150 4100 3100 4100
Wire Wire Line
	3100 4100 3100 3400
Wire Wire Line
	3100 3300 3100 2950
Wire Wire Line
	3100 2650 3100 2500
Wire Wire Line
	5150 3800 4100 3800
Wire Wire Line
	4100 3800 4100 3350
Wire Wire Line
	5150 3700 4450 3700
Wire Wire Line
	4450 3700 4450 3350
Wire Wire Line
	4450 3050 4450 2900
Wire Wire Line
	4100 3050 4100 2900
Wire Wire Line
	4100 2600 4100 2500
Wire Wire Line
	4450 2600 4450 2500
$Comp
L Device:LED D1
U 1 1 5FEDD561
P 4100 3200
F 0 "D1" H 4093 3417 50  0000 C CNN
F 1 "LED" H 4093 3326 50  0000 C CNN
F 2 "" H 4100 3200 50  0001 C CNN
F 3 "~" H 4100 3200 50  0001 C CNN
	1    4100 3200
	0    1    1    0   
$EndComp
Wire Wire Line
	4050 5000 4050 5500
Wire Wire Line
	4050 4400 3000 4400
Wire Wire Line
	3000 4400 3000 2500
Wire Wire Line
	4450 4800 4950 4800
Wire Wire Line
	4950 4800 4950 4200
Wire Wire Line
	4950 4200 5150 4200
Wire Wire Line
	4450 4600 5050 4600
Wire Wire Line
	5050 4600 5050 4300
Wire Wire Line
	5050 4300 5150 4300
$Comp
L Sensor:SHT1x U2
U 1 1 5FF3B6C9
P 4150 4700
F 0 "U2" H 3921 4746 50  0000 R CNN
F 1 "HC-SR04" H 3921 4655 50  0000 R CNN
F 2 "Sensor:SHT1x" H 4300 4950 50  0001 C CNN
F 3 "https://www.sensirion.com/fileadmin/user_upload/customers/sensirion/Dokumente/0_Datasheets/Humidity/Sensirion_Humidity_Sensors_SHT1x_Datasheet.pdf" H 4300 4950 50  0001 C CNN
	1    4150 4700
	1    0    0    -1  
$EndComp
$Comp
L Device:LED D2
U 1 1 5FEDE17A
P 4450 3200
F 0 "D2" H 4443 3417 50  0000 C CNN
F 1 "LED" H 4443 3326 50  0000 C CNN
F 2 "" H 4450 3200 50  0001 C CNN
F 3 "~" H 4450 3200 50  0001 C CNN
	1    4450 3200
	0    1    1    0   
$EndComp
Text Notes 7400 7500 0    50   ~ 0
Distance Warning Device
Text Notes 8150 7650 0    50   ~ 0
29.12. 2020
Text Notes 10600 7650 0    50   ~ 0
Andreas Piskoř
$EndSCHEMATC
