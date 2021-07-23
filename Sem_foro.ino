int orange = 13;
int green = 11;
int red = 12;
char Incoming_value = 0;

void setup() {
  Serial.begin(9600);
  pinMode(orange, OUTPUT);
  pinMode(green, OUTPUT);
  pinMode(red, OUTPUT);
}
void Semaforo(bool start) {
  if (start) {
    Serial.print("Ligando luzes...");
    digitalWrite(red, HIGH);
    digitalWrite(green, LOW);
    digitalWrite(orange, LOW);
    delay(1000);
    digitalWrite(red, LOW);
    digitalWrite(green, HIGH);
    digitalWrite(orange, LOW);
    delay(1000);
    digitalWrite(red, LOW);
    digitalWrite(green, LOW);
    digitalWrite(orange, HIGH);
    delay(1000);
  }
  if (!start) {
    Serial.print("Desligando luzes...");
    digitalWrite(red, LOW);
    digitalWrite(green, LOW);
    digitalWrite(orange, LOW);
  }
}
void loop() {
  if (Serial.available() > 0) {
    Incoming_value = Serial.read();
    Serial.print(Incoming_value);
    Serial.print("\n");
    if (Incoming_value == '1') Semaforo(true);
    else if (Incoming_value == '0') Semaforo(false);
  }
}
