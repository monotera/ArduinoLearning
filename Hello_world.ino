
int myValue = 100;
void setup() {
  // put your setup code here, to run once:
  pinMode(2, OUTPUT);
  pinMode(3, OUTPUT);
  pinMode(4, OUTPUT);
  Serial.begin(9600);

}

void loop() {
  // put your main code here, to run repeatedly:
  int randNumber = random(1,5);
  Serial.print(randNumber);
  digitalWrite(randNumber, HIGH);
  delay(100);
  digitalWrite(randNumber, LOW);
  delay(10000);
}

