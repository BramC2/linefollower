# Sensoren proof of concept

minimale hard- en software die aantoont dat minimaal 6 sensoren onafhankelijk van elkaar kunnen uitgelezen worden (geen calibratie, normalisatie of interpolatie). Hierbij moet een zo groot mogelijk bereik van de AD converter benut worden (indien van toepassing)


void setup() {
  Serial.begin(9600); // Start de seriële communicatie met een baudrate van 9600
  for (int i = 2; i <= 7; i++) {
    pinMode(i, INPUT); // Configureer pinnen 2 t/m 7 als invoer
  }
}

void loop() {
  int sensorValues[6]; // Array om de sensorwaarden op te slaan

  // Lees de sensorwaarden van pinnen A0 t/m A5 (analoge pinnen 0 t/m 5)
  for (int i = 0; i < 6; i++) {
    int sensorPin = A0 + i; // Bereken de analoge pin op basis van de index
    sensorValues[i] = analogRead(sensorPin);
  }

  // Toon de waarden van sensoren 2 t/m 7 in de seriële monitor
  for (int i = 0; i < 6; i++) {
    Serial.print("Sensor ");
    Serial.print(i + 2); // Voeg 2 toe om overeen te komen met de sensoren 2 t/m 7
    Serial.print(": ");
    Serial.println(sensorValues[i]);
  }

  // Wacht even voordat je de sensorwaarden opnieuw leest
  delay(1000);
}
