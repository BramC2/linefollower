const byte Start = 2;
int Led = 8; 

bool Run; 

void setup() {
  analogReference(DEFAULT);
  pinMode(Start, INPUT_PULLUP);
  pinMode(Led, OUTPUT);
  
  attachInterrupt(digitalPinToInterrupt(Start),ProgrammaRun, FALLING);
}

void loop() {
  if(Run == true){
    digitalWrite(8, HIGH);
    delay(1000);
    digitalWrite(8, LOW);
    delay(1000);
  }
  else {
    digitalWrite(8, HIGH);
  }  
}

void ProgrammaRun() {
    Run =! Run; 
}
