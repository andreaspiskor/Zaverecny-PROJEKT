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
	1    0    0    -1  
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
P 7950 5200
F 0 "B1" H 7950 5485 50  0000 C CNN
F 1 "Button" H 7950 5394 50  0000 C CNN
F 2 "" H 7950 5400 50  0001 C CNN
F 3 "~" H 7950 5400 50  0001 C CNN
	1    7950 5200
	1    0    0    -1  
$EndComp
$Comp
L Device:R R2
U 1 1 5FEDACD0
P 3900 2750
F 0 "R2" H 3970 2796 50  0000 L CNN
F 1 "220" H 3970 2705 50  0000 L CNN
F 2 "" V 3830 2750 50  0001 C CNN
F 3 "~" H 3900 2750 50  0001 C CNN
	1    3900 2750
	1    0    0    -1  
$EndComp
$Comp
L Device:R R3
U 1 1 5FEDBE1D
P 4250 2750
F 0 "R3" H 4320 2796 50  0000 L CNN
F 1 "220" H 4320 2705 50  0000 L CNN
F 2 "" V 4180 2750 50  0001 C CNN
F 3 "~" H 4250 2750 50  0001 C CNN
	1    4250 2750
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
+5V
Text Notes 8450 2450 0    50   ~ 0
GND
$Comp
L Device:Battery +9V1
U 1 1 5FEE3F95
P 8350 5000
F 0 "+9V1" H 8458 5046 50  0000 L CNN
F 1 "Battery" H 8458 4955 50  0000 L CNN
F 2 "" V 8350 5060 50  0001 C CNN
F 3 "~" V 8350 5060 50  0001 C CNN
	1    8350 5000
	1    0    0    1   
$EndComp
Wire Wire Line
	3100 3300 3100 2950
Wire Wire Line
	4250 3050 4250 2900
Wire Wire Line
	3900 3050 3900 2900
$Comp
L Device:LED D1
U 1 1 5FEDD561
P 3900 3200
F 0 "D1" H 3893 3417 50  0000 C CNN
F 1 "LED" H 3893 3326 50  0000 C CNN
F 2 "" H 3900 3200 50  0001 C CNN
F 3 "~" H 3900 3200 50  0001 C CNN
	1    3900 3200
	0    1    1    0   
$EndComp
$Comp
L Sensor:SHT1x U2
U 1 1 5FF3B6C9
P 3550 4700
F 0 "U2" H 3321 4746 50  0000 R CNN
F 1 "HC-SR04" H 3321 4655 50  0000 R CNN
F 2 "Sensor:SHT1x" H 3700 4950 50  0001 C CNN
F 3 "https://www.sensirion.com/fileadmin/user_upload/customers/sensirion/Dokumente/0_Datasheets/Humidity/Sensirion_Humidity_Sensors_SHT1x_Datasheet.pdf" H 3700 4950 50  0001 C CNN
	1    3550 4700
	1    0    0    1   
$EndComp
$Comp
L Device:LED D2
U 1 1 5FEDE17A
P 4250 3200
F 0 "D2" H 4243 3417 50  0000 C CNN
F 1 "LED" H 4243 3326 50  0000 C CNN
F 2 "" H 4250 3200 50  0001 C CNN
F 3 "~" H 4250 3200 50  0001 C CNN
	1    4250 3200
	0    1    1    0   
$EndComp
Text Notes 7400 7500 0    50   ~ 0
Distance Warning Device
Text Notes 8150 7650 0    50   ~ 0
29.12. 2020
Text Notes 10600 7650 0    50   ~ 0
Andreas Piskoř
$Comp
L Switch:SW_Push B2
U 1 1 5FF5BA4D
P 4900 2900
F 0 "B2" H 4900 3185 50  0000 C CNN
F 1 "Button" H 4900 3094 50  0000 C CNN
F 2 "" H 4900 3100 50  0001 C CNN
F 3 "~" H 4900 3100 50  0001 C CNN
	1    4900 2900
	1    0    0    -1  
$EndComp
Wire Wire Line
	3450 4400 2950 4400
Wire Wire Line
	2950 4400 2950 2500
Wire Wire Line
	3100 2650 3100 2500
Wire Wire Line
	3900 2600 3900 2500
Wire Wire Line
	4250 2600 4250 2500
Wire Wire Line
	4700 2900 4700 2500
Wire Wire Line
	7050 4000 7050 2500
Wire Wire Line
	3450 5000 3450 5500
Wire Wire Line
	7050 5000 7050 5500
Wire Wire Line
	5850 5000 5850 5500
Wire Wire Line
	5650 3000 5650 2500
Wire Wire Line
	8350 4800 8350 2500
Wire Wire Line
	8350 5200 8150 5200
Wire Wire Line
	7750 5200 5550 5200
Wire Wire Line
	5550 5200 5550 5000
Wire Wire Line
	6650 4500 6450 4500
Wire Wire Line
	6450 4500 6450 3500
Wire Wire Line
	6450 3500 6150 3500
Wire Wire Line
	6650 4400 6350 4400
Wire Wire Line
	6350 4400 6350 3600
Wire Wire Line
	6350 3600 6150 3600
$Comp
L MCU_Module:Arduino_Nano_Every U0
U 1 1 5FEB9331
P 5650 4000
F 0 "U0" H 5650 2911 50  0000 L CNN
F 1 "Arduino_Nano" H 5650 2820 50  0000 L CNN
F 2 "Module:Arduino_Nano" H 5650 4000 50  0001 C CIN
F 3 "https://content.arduino.cc/assets/NANOEveryV3.0_sch.pdf" H 5650 4000 50  0001 C CNN
	1    5650 4000
	1    0    0    1   
$EndComp
Wire Wire Line
	3900 4200 5150 4200
Wire Wire Line
	3900 3350 3900 4200
Wire Wire Line
	4250 4300 5150 4300
Wire Wire Line
	4250 3350 4250 4300
Wire Wire Line
	3850 4800 4900 4800
Wire Wire Line
	4900 4800 4900 3700
Wire Wire Line
	4900 3700 5150 3700
Wire Wire Line
	3850 4600 4800 4600
Wire Wire Line
	4800 4600 4800 3800
Wire Wire Line
	4800 3800 5150 3800
Wire Wire Line
	5150 3900 3100 3900
Wire Wire Line
	3100 3900 3100 3400
Wire Wire Line
	5100 2900 5100 4700
Wire Wire Line
	5100 4700 5150 4700
$EndSCHEMATC
