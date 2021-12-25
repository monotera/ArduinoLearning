//Pin constants
const int gameButtonPin = 2;
const int initButtonPin = 3;
const int redLedPin = 4;
const int blueLedPin = 5;
const int yellowLedPin = 6;
const int piezoPin = 8;
const int rgbRedPin = 9;
const int rgbGreenPin = 10;
const int rgbBluePin = 11;

void loading();
void game();

void setup() {
  pinMode(redLedPin, OUTPUT);
  pinMode(blueLedPin, OUTPUT);
  pinMode(yellowLedPin, OUTPUT);
  pinMode(initButtonPin, INPUT);
  pinMode(gameButtonPin, INPUT);
  pinMode(rgbRedPin, OUTPUT);
  pinMode(rgbGreenPin, OUTPUT);
  pinMode(rgbBluePin, OUTPUT);
  Serial.begin(9600);
}

void loop() {
  analogWrite(rgbRedPin, map(0, 0, 1023, 0, 255));
  analogWrite(rgbGreenPin, map(0, 0, 1023, 0, 255));
  analogWrite(rgbBluePin, map(128, 0, 1023, 0, 255));
  int initButtonState = digitalRead(initButtonPin);
  int initLastButtonState = 0;
  if (initButtonState != initLastButtonState) {
    if (initButtonState == HIGH) {
      Serial.println("Start game function");
      int randNumber = random(4, 7);
      game(randNumber);
    } else {
      Serial.println("End game");
    }
    delay(50);
  }
  initLastButtonState = initButtonState;
  loading();
}


void game(int randNumber) {
  delay(500);
  int initButtonState = 0;
  int buttonPushCounter = 0; 
  Serial.print("Game has started, the random number is: ");
  Serial.println(randNumber);
  int gameLastButtonState = 0;

  do {
    initButtonState = 0;
    int gameButtonState = digitalRead(gameButtonPin);
    delay(100);
    if (gameButtonState != gameLastButtonState) {
      if (gameButtonState == HIGH) {
        buttonPushCounter++;
        Serial.print("number of button pushes: ");
        Serial.println(buttonPushCounter);
      }
      delay(50);
    }
    initButtonState = digitalRead(initButtonPin);
    gameLastButtonState = gameButtonState;
  } while (initButtonState == 0);

  if (buttonPushCounter >= 1 && buttonPushCounter <= 3) {
    if (buttonPushCounter + 3 == randNumber) {
      Serial.println("You won!");
      analogWrite(rgbRedPin, map(0, 0, 1023, 0, 255));
      analogWrite(rgbGreenPin, map(202, 0, 1023, 0, 255));
      analogWrite(rgbBluePin, map(0, 0, 1023, 0, 255));
      digitalWrite(randNumber, HIGH);
      tone(piezoPin, 1500, 100);
      delay(300);
      tone(piezoPin, 1000, 100);
      delay(300);
      tone(piezoPin, 800, 100);
      delay(1000);
      digitalWrite(randNumber, LOW);
    } else {
      Serial.println("You loose!");
      analogWrite(rgbRedPin, map(202, 0, 1023, 0, 255));
      analogWrite(rgbGreenPin, map(0, 0, 1023, 0, 255));
      analogWrite(rgbBluePin, map(0, 0, 1023, 0, 255));
      digitalWrite(randNumber, HIGH);
      digitalWrite(buttonPushCounter + 3, HIGH);
      for (int i = 0; i < 2; i++) {
        tone(piezoPin, 100, 800);
        delay(1000);
      }
      delay(1000);
      digitalWrite(randNumber, LOW);
      digitalWrite(buttonPushCounter + 3, LOW);
    }
  } else {
    Serial.println("Error!");
    analogWrite(rgbRedPin, map(255, 0, 1023, 0, 255));
    analogWrite(rgbGreenPin, map(128, 0, 1023, 0, 255));
    tone(piezoPin, 300, 100);
    delay(300);
    tone(piezoPin, 100, 100);
    delay(300);
    tone(piezoPin, 500, 100);
    delay(2000);
  }
}
void loading() {
  digitalWrite(blueLedPin, HIGH);
  delay(50);
  digitalWrite(blueLedPin, LOW);
  digitalWrite(redLedPin, HIGH);
  delay(60);
  digitalWrite(redLedPin, LOW);
  digitalWrite(yellowLedPin, HIGH);
  delay(70);
  digitalWrite(yellowLedPin, LOW);
}