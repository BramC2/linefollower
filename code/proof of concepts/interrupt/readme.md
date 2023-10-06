# start/stop interrupt proof of concept
minimale hard- en software die de correcte werking van een start/stop drukknop aantoont, gebruik makend van een hardware interrupt

const int Button = 2; 
const int ledPin = 7; 
bool Running; 

void setup() {
  analogReference(DEFAULT);
  pinMode(Button, INPUT_PULLUP);
  pinMode(ledPin, OUTPUT);
  attachInterrupt(digitalPinToInterrupt(Button),Interrupt, RISING);
}

void loop() {
  if(Running == true){
    digitalWrite(ledPin, HIGH);
    delay(50);
    digitalWrite(ledPin, LOW);
    delay(50);
  }
  else {
    digitalWrite(ledPin, HIGH);
  }  
}

void Interrupt() {
    Running =! Running; 
}

