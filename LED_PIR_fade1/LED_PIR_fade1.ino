#define LEDPIN 5
#define PIRPIN 1

int ledState = 0;
unsigned long previousMillis = 0;
unsigned long currentMillis = 0;
boolean alreadyfadedup  = false;
boolean alreadyfadeddown  = false;
const long interval = 200;  //amount of time the leds will stay up in millis

void setup() {
  pinMode(PIRPIN, INPUT);
}


void loop() {

  currentMillis = millis();

  if (digitalRead(PIRPIN) == 1) {
    ledState = 1;
    previousMillis = currentMillis;
    if (alreadyfadedup == false) {
      for (int i = 0; i < 256; i++) {
        analogWrite(LEDPIN, i);
        delay(2);
      }
      alreadyfadedup  = true;
      alreadyfadeddown = false;
    }
  }
  if (currentMillis - previousMillis >= interval) {
    if (ledState == 1) {
      if (alreadyfadeddown == false) {
        for (int i = 255; i >= 0; i--) {
          analogWrite(LEDPIN, i);
          delay(2);
        }
        alreadyfadeddown  = true;
        alreadyfadedup = false;
      }
      ledState = 0;
    }
  }
}
