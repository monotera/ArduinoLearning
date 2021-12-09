
int turnLightOn(int light);

void setup() {
  // put your setup code here, to run once:
  pinMode(2, OUTPUT);
  pinMode(3, OUTPUT);
  pinMode(4, OUTPUT);
  pinMode(7, INPUT);
  Serial.begin(9600);
}

void loop() {
  // put your main code here, to run repeatedly:
  int btnValue = digitalRead(7); 
  static bool isLightOn = false; //SE REALIZAR LECTURA DIGITAL PIN 7
  delay(1);
  int randNumber = random(2,5);
  if(btnValue == 1)
  {
    turnLightOn(randNumber);
  }
}

int turnLightOn(int light) {
  Serial.println(light);
  digitalWrite(light, HIGH);
  delay(1000);
  digitalWrite(light, LOW);
}

