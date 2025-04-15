#include "display.h"
#include "config.h"
#include <LiquidCrystal_I2C.h>

LiquidCrystal_I2C lcd(LCD_ADDRESS, LCD_COLS, LCD_ROWS);

void displayInit() {
  lcd.init();
  lcd.backlight();
  lcd.clear();
}

void displayMessage(String message) {
  lcd.clear();
  lcd.setCursor(0, 0);
  lcd.print(message);
}

void displayMessage(String line1, String line2) {
  lcd.clear();
  lcd.setCursor(0, 0);
  lcd.print(line1);
  lcd.setCursor(0, 1);
  lcd.print(line2);
}