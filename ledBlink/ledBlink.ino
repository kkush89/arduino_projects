
void turnOnLight(int pin);
void turnOffLight(int pin);

void setup() {
  // put your setup code here, to run once:

  pinMode(7, OUTPUT);
  pinMode(12, OUTPUT);
  pinMode(10, OUTPUT);
}

void loop() {
  // put your main code here, to run repeatedly:

  int LED_PIN_RED = 7;
  int LED_PIN_YELLOW = 10;
  int LED_PIN_GREEN = 12;

  turnOnLight(LED_PIN_RED);
  turnOffLight(LED_PIN_RED);
  turnOnLight(LED_PIN_YELLOW);
  turnOffLight(LED_PIN_YELLOW);
  turnOnLight(LED_PIN_GREEN);
  turnOffLight(LED_PIN_GREEN);
  
}

void turnOnLight(int pin){

  digitalWrite(pin, HIGH);
  delay(5000);
}

void turnOffLight(int pin){

  digitalWrite(pin, LOW);
}
