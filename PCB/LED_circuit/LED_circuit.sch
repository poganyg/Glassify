EESchema Schematic File Version 4
LIBS:LED_circuit-cache
EELAYER 26 0
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
L Device:LED LW-TTSD_SMD_LED1
U 1 1 5C964CBB
P 5550 3950
F 0 "LW-TTSD_SMD_LED1" H 5300 4050 50  0000 C CNN
F 1 "3.2V" H 5250 3950 50  0000 C CNN
F 2 "LED_SMD:LED_PLCC-2" H 5550 3950 50  0001 C CNN
F 3 "~" H 5550 3950 50  0001 C CNN
	1    5550 3950
	-1   0    0    1   
$EndComp
Wire Wire Line
	5400 3950 5400 3450
Wire Wire Line
	7050 3950 7050 3450
Wire Wire Line
	6750 3950 6750 3750
Wire Wire Line
	5700 3750 5700 3950
Connection ~ 5400 3950
$Comp
L Device:LED LW-TTSD_SMD_LED2
U 1 1 5C97F03B
P 5750 3600
F 0 "LW-TTSD_SMD_LED2" V 6050 3600 50  0000 C CNN
F 1 "3.2V" V 5950 3600 50  0000 C CNN
F 2 "LED_SMD:LED_PLCC-2" H 5750 3600 50  0001 C CNN
F 3 "~" H 5750 3600 50  0001 C CNN
	1    5750 3600
	0    -1   -1   0   
$EndComp
$Comp
L Device:LED LW-TTSD_SMD_LED3
U 1 1 5C97F075
P 6600 3600
F 0 "LW-TTSD_SMD_LED3" V 6800 3600 50  0000 C CNN
F 1 "3.2V" V 6600 3450 50  0000 C CNN
F 2 "LED_SMD:LED_PLCC-2" H 6600 3600 50  0001 C CNN
F 3 "~" H 6600 3600 50  0001 C CNN
	1    6600 3600
	0    -1   -1   0   
$EndComp
$Comp
L Device:LED LW-TTSD_SMD_LED4
U 1 1 5C97F0B5
P 6900 3950
F 0 "LW-TTSD_SMD_LED4" H 6900 3750 50  0000 C CNN
F 1 "3.2V" H 6900 3850 50  0000 C CNN
F 2 "LED_SMD:LED_PLCC-2" H 6900 3950 50  0001 C CNN
F 3 "~" H 6900 3950 50  0001 C CNN
	1    6900 3950
	1    0    0    -1  
$EndComp
Wire Wire Line
	5700 3750 5750 3750
Wire Wire Line
	5400 3450 5750 3450
Connection ~ 6600 3750
Wire Wire Line
	6600 3750 6750 3750
Connection ~ 6600 3450
Wire Wire Line
	6600 3450 7050 3450
Connection ~ 5750 3750
Wire Wire Line
	5750 3750 6600 3750
Connection ~ 5750 3450
Wire Wire Line
	5750 3450 6600 3450
$Comp
L Device:R CURRENT_LIMITER_R1
U 1 1 5C97F861
P 5400 4300
F 0 "CURRENT_LIMITER_R1" V 5300 3900 50  0000 L CNN
F 1 "16" V 5400 4250 50  0000 L CNN
F 2 "Resistor_THT:R_Axial_DIN0207_L6.3mm_D2.5mm_P10.16mm_Horizontal" V 5330 4300 50  0001 C CNN
F 3 "~" H 5400 4300 50  0001 C CNN
	1    5400 4300
	1    0    0    -1  
$EndComp
Wire Wire Line
	5400 3950 5400 4150
Wire Wire Line
	4750 4700 5400 4700
Text Notes 4500 4850 2    54   ~ 0
VCC [4.5V]\nGND
Wire Wire Line
	5400 4700 5400 4450
Wire Wire Line
	5700 3950 5700 4800
Connection ~ 5700 3950
$Comp
L Connector:Conn_01x02_Male Conn_01x02_Male1
U 1 1 5C98C2BF
P 4550 4700
F 0 "Conn_01x02_Male1" H 4650 4850 50  0000 C CNN
F 1 "2mm pitch" H 4650 4950 50  0000 C CNN
F 2 "Connector_Molex:Molex_KK-254_AE-6410-02A_1x02_P2.54mm_Vertical" H 4550 4700 50  0001 C CNN
F 3 "~" H 4550 4700 50  0001 C CNN
	1    4550 4700
	1    0    0    -1  
$EndComp
Wire Wire Line
	5700 4800 4750 4800
$Comp
L Mechanical:MountingHole H7
U 1 1 5C9A16B0
P 4500 4000
F 0 "H7" H 4600 4046 50  0000 L CNN
F 1 "MountingHole" H 4600 3955 50  0000 L CNN
F 2 "MountingHole:MountingHole_2.5mm_Pad" H 4500 4000 50  0001 C CNN
F 3 "~" H 4500 4000 50  0001 C CNN
	1    4500 4000
	1    0    0    -1  
$EndComp
$Comp
L Mechanical:MountingHole H6
U 1 1 5C9A1C3F
P 4500 3700
F 0 "H6" H 4600 3746 50  0000 L CNN
F 1 "MountingHole" H 4600 3655 50  0000 L CNN
F 2 "MountingHole:MountingHole_2.5mm_Pad" H 4500 3700 50  0001 C CNN
F 3 "~" H 4500 3700 50  0001 C CNN
	1    4500 3700
	1    0    0    -1  
$EndComp
$Comp
L Mechanical:MountingHole H8
U 1 1 5C9A1C69
P 4550 3350
F 0 "H8" H 4650 3396 50  0000 L CNN
F 1 "MountingHole" H 4650 3305 50  0000 L CNN
F 2 "MountingHole:MountingHole_2.5mm_Pad" H 4550 3350 50  0001 C CNN
F 3 "~" H 4550 3350 50  0001 C CNN
	1    4550 3350
	1    0    0    -1  
$EndComp
$Comp
L Mechanical:MountingHole H5
U 1 1 5C9A1CA5
P 4250 3750
F 0 "H5" H 4350 3796 50  0000 L CNN
F 1 "MountingHole" H 4350 3705 50  0000 L CNN
F 2 "MountingHole:MountingHole_2.5mm_Pad" H 4250 3750 50  0001 C CNN
F 3 "~" H 4250 3750 50  0001 C CNN
	1    4250 3750
	1    0    0    -1  
$EndComp
$Comp
L Mechanical:MountingHole H3
U 1 1 5C9A1CD7
P 4200 4100
F 0 "H3" H 4300 4146 50  0000 L CNN
F 1 "MountingHole" H 4300 4055 50  0000 L CNN
F 2 "MountingHole:MountingHole_2.5mm_Pad" H 4200 4100 50  0001 C CNN
F 3 "~" H 4200 4100 50  0001 C CNN
	1    4200 4100
	1    0    0    -1  
$EndComp
$Comp
L Mechanical:MountingHole H4
U 1 1 5C9A1D07
P 4250 3400
F 0 "H4" H 4350 3446 50  0000 L CNN
F 1 "MountingHole" H 4350 3355 50  0000 L CNN
F 2 "MountingHole:MountingHole_2.5mm_Pad" H 4250 3400 50  0001 C CNN
F 3 "~" H 4250 3400 50  0001 C CNN
	1    4250 3400
	1    0    0    -1  
$EndComp
$Comp
L Mechanical:MountingHole H2
U 1 1 5C9A1DC2
P 4050 3650
F 0 "H2" H 4150 3696 50  0000 L CNN
F 1 "MountingHole" H 4150 3605 50  0000 L CNN
F 2 "MountingHole:MountingHole_2.5mm_Pad" H 4050 3650 50  0001 C CNN
F 3 "~" H 4050 3650 50  0001 C CNN
	1    4050 3650
	1    0    0    -1  
$EndComp
$Comp
L Mechanical:MountingHole H1
U 1 1 5C9A1DFA
P 3950 3400
F 0 "H1" H 4050 3446 50  0000 L CNN
F 1 "MountingHole" H 4050 3355 50  0000 L CNN
F 2 "MountingHole:MountingHole_2.5mm_Pad" H 3950 3400 50  0001 C CNN
F 3 "~" H 3950 3400 50  0001 C CNN
	1    3950 3400
	1    0    0    -1  
$EndComp
$EndSCHEMATC
