/*
  LCD display with PCF8574 I/O expander

  show information on the LCD display

  based on Arduino Examples "Blink"

  Date: 6 Mar 2023
  Author: Yen-Chen Chang @ makestraight
*/

#include <Arduino.h>
#include <Wire.h>
#include <LiquidCrystal_PCF8574.h>

LiquidCrystal_PCF8574 lcd(0x27);  // set the LCD address to 0x27 for a 16 chars and 2 line display

// the setup function runs once when you press reset or power the board
void setup() {
  // initialize digital pin LED_BUILTIN as an output.
  pinMode(LED_BUILTIN, OUTPUT);

  // initialize I2C communication between Arduino and PCF8574
  Wire.begin();
  // initialize the lcd
  lcd.begin(16, 2);

  lcd.setBacklight(255);
  lcd.home();
  lcd.clear();
  // first row
  lcd.setCursor(0, 0);
  lcd.print("Hello World");
  // second row
  lcd.setCursor(0, 1);
  lcd.print("Make Straight");
  delay(1000);
}

// the loop function runs over and over again forever
void loop() {
  // blink
  digitalWrite(LED_BUILTIN, HIGH);  // turn the LED on (HIGH is the voltage level)
  delay(1000);                      // wait for a second
  digitalWrite(LED_BUILTIN, LOW);   // turn the LED off by making the voltage LOW
  delay(1000);                      // wait for a second

  // print information
  lcd.clear();
  lcd.setCursor(0, 0);
  lcd.print("LED Blink");
  lcd.setCursor(0, 1);
  lcd.print("Operation good!!");
}
