# draadloze communicatie proof of concept
minimale hard- en software waarmee aangetoond wordt dat duplex kan gecommuniceerd worden tussen de microcontroller en een smartphone, gebruik makend van hc-06 bluetooth module
<br />
code :int ledPin = 12;

void setup() {
  pinMode(ledPin, OUTPUT);
  Serial.begin(9600); // Start de seriële communicatie met de computer
  Serial1.begin(9600); // Start de hardwarematige seriële communicatie met de HC-06
  Serial.println("Arduino is gereed voor Bluetooth-communicatie.");
}

void loop() {
  if (Serial1.available()) {
    char receivedChar = Serial1.read();
    Serial.print("Ontvangen: ");
    Serial.println(receivedChar);

    // Voer actie uit op basis van het ontvangen commando
    if (receivedChar == '1') {
      digitalWrite(ledPin, HIGH); // Schakel LED in
    } else if (receivedChar == '0') {
      digitalWrite(ledPin, LOW); // Schakel LED uit
    }
  }

  if (Serial.available()) {
    char sendChar = Serial.read();
    Serial1.print(sendChar);
    Serial.print("Verzonden: ");
    Serial.println(sendChar);
  }
}

schema:
![367957343_6847608351967677_620365559073186007_n](https://github.com/BramC2/linefollower/assets/146452484/5e21052e-f9ff-445f-bcd4-2718422f1b4c)




