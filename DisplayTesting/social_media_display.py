import lcd1602 as lcd
import RPi.GPIO as GPIO
import time

lcd.lcd_init()

GPIO.setmode(GPIO.BCM)

lcd.lcd_text("Beep Boop",lcd.LCD_LINE_1)
lcd.lcd_text("Its me, Glassify",lcd.LCD_LINE_2)
time.sleep(2)
lcd.lcd_text("Printing parts",lcd.LCD_LINE_1)
lcd.lcd_text("C-ing glass",lcd.LCD_LINE_2)
time.sleep(2)
lcd.lcd_text("To sort bottles",lcd.LCD_LINE_1)
lcd.lcd_text("of 3 kinds.",lcd.LCD_LINE_2)
time.sleep(6)
GPIO.cleanup()
