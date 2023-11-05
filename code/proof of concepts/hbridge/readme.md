# H-Bridge proof of concept

minimale hard- & software die aantoont dat 2 motoren onafhankelijk van elkaar kunnen draaien, en (traploos) regelbaar zijn in snelheid en draairichting.
const int nSleepPin = 8;
const int AIN1Pin = 9;
const int AIN2Pin = 10;
const int BIN1Pin = 11;
const int BIN2Pin = 12;

void setup() {
  pinMode(nSleepPin, OUTPUT);
  pinMode(AIN1Pin, OUTPUT);
  pinMode(AIN2Pin, OUTPUT);
  pinMode(BIN1Pin, OUTPUT);
  pinMode(BIN2Pin, OUTPUT);

  digitalWrite(nSleepPin, HIGH); // Activeer de DRV8833

  // Motor A (bijvoorbeeld links)
  digitalWrite(AIN1Pin, LOW);  // Draairichting A
  digitalWrite(AIN2Pin, LOW);  // Draairichting A

  // Motor B (bijvoorbeeld rechts)
  digitalWrite(BIN1Pin, LOW);  // Draairichting B
  digitalWrite(BIN2Pin, LOW);  // Draairichting B
}

void loop() {
  // Motor A vooruit met traploze snelheid
  analogWrite(AIN1Pin, 255); // Volle snelheid
  analogWrite(AIN2Pin, 0);   // Stilstaan

  // Motor B achteruit met traploze snelheid
  analogWrite(BIN1Pin, 0);   // Stilstaan
  analogWrite(BIN2Pin, 127); // half vermogen

  delay(2000);  // Wacht 2 seconden

  // Motor A achteruit met traploze snelheid
  analogWrite(AIN1Pin, 0);   // Stilstaan
  analogWrite(AIN2Pin, 127); // Half vermogen

  // Motor B vooruit met traploze snelheid
  analogWrite(BIN1Pin, 127); // Half vermogen
  analogWrite(BIN2Pin, 255); // Volle snelheid

  delay(2000);  // Wacht 2 seconden

  // Stop beide motoren
  analogWrite(AIN1Pin, 0);
  analogWrite(AIN2Pin, 0);
  analogWrite(BIN1Pin, 0);
  analogWrite(BIN2Pin, 0);

  delay(2000);  // Wacht 2 seconden
}
