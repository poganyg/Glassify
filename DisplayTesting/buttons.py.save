# coding=utf-8
 
import RPi.GPIO as GPIO
import time

BUTTON1 = 17
BUTTON2 = 27
SENSOR = 22

GPIO.setmode(GPIO.BCM)

GPIO.setup(17, GPIO.IN, pull_up_down=GPIO.PUD_DOWN)
GPIO.setup(27, GPIO.IN, pull_up_down=GPIO.PUD_DOWN)
GPIO.setup(22, GPIO.IN, pull_up_down=GPIO.PUD_DOWN)

pB1 = GPIO.LOW
pB2 = GPIO.LOW
pS = GPIO.LOW

try:
 main()
except KeyboardInterrupt:
 pass
finally:
 lcd_write()

while True:
	B1 = GPIO.input(BUTTON1)
	B2 = GPIO.input(BUTTON2)
	S = GPIO.input(SENSOR)
	if  B1 != pB1:
		pB1 = B1
		if B1 == GPIO.HIGH:
			print('\n Button 1 down')
		if B1 == GPIO.LOW:
			print('\n Button 1 up')
		time.sleep(0.05)
	if  B2 != pB2:
		pB2 = B2
		if B2 == GPIO.HIGH:
			print('\n Button 2 down')
		if B2 == GPIO.LOW:
			print('\n Button 2 up')
		time.sleep(0.05)
	if  S != pS:
		pS = S
		if S == GPIO.HIGH:
			print('\n Sensor  down')
		if S == GPIO.LOW:
			print('\n Sensor  up')
		time.sleep(0.05)
