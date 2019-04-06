import RPi.GPIO as GPIO
import time
import lcd1602 as lcd


def main ():
    lcd.lcd_init()

    BUTTON1 = 2
    BUTTON2 = 27
    SENSOR = 17
    SWITCH = 4
    SERVO = 3
    dutyCycle = 2.5

    GPIO.setmode(GPIO.BCM)

    GPIO.setup(BUTTON1, GPIO.OUT)
    GPIO.setup(BUTTON2, GPIO.IN, pull_up_down=GPIO.PUD_DOWN)
    GPIO.setup(SENSOR, GPIO.IN, pull_up_down=GPIO.PUD_DOWN)
    GPIO.setup(SWITCH, GPIO.OUT)
    GPIO.setup(SERVO, GPIO.OUT)

    GPIO.output(BUTTON1, GPIO.LOW)
    print("output set")
    pB1 = GPIO.LOW
    pB2 = GPIO.LOW
    pS = GPIO.LOW
    GPIO.output(SWITCH, GPIO.LOW)
    GPIO.output(SERVO, GPIO.LOW)

    p = GPIO.PWM(SERVO, 50) # setting up PWM to be @ 50Hz
    print("starting loop")
    while True:
    	#B1 = GPIO.input(BUTTON1)
    	B2 = GPIO.input(BUTTON2)
    	S = GPIO.input(SENSOR)
    	if  pB1 != pB1:
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
                time.sleep(2)
                p.start(dutyCycle)
                for i in range(4):
                    lcd.lcd_text("Duty cycle:",lcd.LCD_LINE_1)
                    lcd.lcd_text(str(dutyCycle+(i+1)*2.5),lcd.LCD_LINE_2)
                    p.ChangeDutyCycle(dutyCycle+(i+1)*2.5)
                    time.sleep(2)
                p.stop()
                GPIO.output(SWITCH, GPIO.LOW)
                lcd.lcd_text(" ",lcd.LCD_LINE_2)
    		if S == GPIO.LOW:
    			lcd.lcd_text("Sensor up",lcd.LCD_LINE_1)
                #GPIO.output(SWITCH, GPIO.LOW)
    		time.sleep(0.05)



try:
  main()

except KeyboardInterrupt:
  pass

finally:
  lcd.lcd_write(0x01, lcd.LCD_CMD)
  lcd.lcd_text("---GlassyBye!---",lcd.LCD_LINE_1)
GPIO.cleanup()
