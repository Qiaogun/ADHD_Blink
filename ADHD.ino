#include <M5StickCPlus.h>

enum Mode {
  BPM120,
  BPM85,
  BPM70,
  PAUSE,
  NUM_MODES
};

Mode currentMode = BPM120;
unsigned long previousMillis = 0;
unsigned long lastBPMUpdateMillis = 0;
int ledState = LOW;
int currentBPM = 120;

void setup() {
  M5.begin();
  pinMode(M5_LED, OUTPUT);
  M5.Lcd.setRotation(3);
  M5.Lcd.fillScreen(BLACK);
  M5.Lcd.setTextColor(WHITE);
  M5.Lcd.setTextSize(4);
}

void displayNumber(int num) {
  M5.Axp.ScreenBreath(15);
  M5.Lcd.fillScreen(BLACK);
  M5.Lcd.setCursor((135 - M5.Lcd.textWidth(String(num))) / 2, 20);
  M5.Lcd.printf("BPM: %d", num);
}

void turnOffScreen() {
  M5.Lcd.fillScreen(BLACK);
  M5.Axp.ScreenBreath(7);
  delay(500);
}

void updateHeartbeat() {
  if (currentMode == PAUSE) {
    digitalWrite(M5_LED, HIGH);
    turnOffScreen();
    return;
  }

  unsigned long currentMillis = millis();
  if(currentMillis - previousMillis >= (60000 / currentBPM)) {
    previousMillis = currentMillis;
    ledState = !ledState;
    digitalWrite(M5_LED, ledState);
    displayNumber(currentBPM);
  }
}

void loop() {
  M5.update();
  if (M5.BtnA.wasPressed()) {
    currentMode = static_cast<Mode>((currentMode + 1) % NUM_MODES);
    switch(currentMode) {
      case BPM120: currentBPM = 120; break;
      case BPM85:  currentBPM = 85; break;
      case BPM70:  currentBPM = 70; break;
      case PAUSE:  break;
    }
    lastBPMUpdateMillis = millis();
  }

  if (currentMode != PAUSE && millis() - lastBPMUpdateMillis >= 60000) {
    lastBPMUpdateMillis = millis();
    if (currentBPM > 65) {
      currentBPM -= 5; // -5 BPM/min
    }
  }

  updateHeartbeat();
}
