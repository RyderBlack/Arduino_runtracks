#include <LiquidCrystal.h>

// Initialize LCD: (rs, en, d4, d5, d6, d7)
LiquidCrystal lcd(12, 11, 5, 4, 3, 2);

void setup() {
  lcd.begin(16, 2);
  Serial.begin(9600);
  lcd.print("Waiting data...");
}

void loop() {
  if (Serial.available()) {
    String input = Serial.readStringUntil('\n'); // Get full line
    lcd.clear();
    lcd.setCursor(0, 0);
    lcd.print("CPU: ");
    lcd.print(getValue(input, ',', 0));
    lcd.print("%");

    lcd.setCursor(0, 1);
    lcd.print("RAM: ");
    lcd.print(getValue(input, ',', 1));
    lcd.print("%");
  }
}

// Helper function to split incoming string
String getValue(String data, char separator, int index) {
  int found = 0;
  int start = 0;
  int end = -1;

  for (int i = 0; i <= data.length(); i++) {
    if (data.charAt(i) == separator || i == data.length()) {
      found++;
      if (found > index) {
        return data.substring(start, i);
      }
      start = i + 1;
    }
  }
  return "";
}
