# coding=utf-8

import RPi.GPIO as GPIO
import time
import lcd1602 as lcd


def main ():
    lcd.lcd_init()

    BUTTON1 = 17
    BUTTON2 = 27
    SENSOR = 22
    SWITCH = 5

    GPIO.setmode(GPIO.BCM)

    GPIO.setup(17, GPIO.IN, pull_up_down=GPIO.PUD_DOWN)
    GPIO.setup(27, GPIO.IN, pull_up_down=GPIO.PUD_DOWN)
    GPIO.setup(22, GPIO.IN, pull_up_down=GPIO.PUD_DOWN)
    GPIO.setup(5, GPIO.OUT)

    pB1 = GPIO.LOW
    pB2 = GPIO.LOW
    pS = GPIO.LOW
    GPIO.output(SWITCH, 0)

    while True:
    	B1 = GPIO.input(BUTTON1)
    	B2 = GPIO.input(BUTTON2)
    	S = GPIO.input(SENSOR)
    	if  B1 != pB1:
    		pB1 = B1
    		if B1 == GPIO.HIGH:
    			lcd.lcd_text("Button 1 down",lcd.LCD_LINE_1)
    		if B1 == GPIO.LOW:
    			lcd.lcd_text("Button 1 up",lcd.LCD_LINE_1)
    		time.sleep(0.05)
    	if  B2 != pB2:
    		pB2 = B2
    		if B2 == GPIO.HIGH:
    			lcd.lcd_text("Button 2 down",lcd.LCD_LINE_1)
    		if B2 == GPIO.LOW:
    			lcd.lcd_text("Button 2 up",lcd.LCD_LINE_1)
    		time.sleep(0.05)
    	if  S != pS:
    		pS = S
    		if S == GPIO.HIGH:
    			lcd.lcd_text("Sensor down",lcd.LCD_LINE_1)
                GPIO.output(SWITCH, GPIO.HIGH)
    		if S == GPIO.LOW:
    			lcd.lcd_text("Sensor up",lcd.LCD_LINE_1)
                #GPIO.output(SWITCH, 0)
    		time.sleep(0.05)



try:
  main()

except KeyboardInterrupt:
  pass

finally:
  lcd.lcd_write(0x01, lcd.LCD_CMD)
  lcd.lcd_text("---GlassyBye!---",lcd.LCD_LINE_1)
  GPIO.cleanup()