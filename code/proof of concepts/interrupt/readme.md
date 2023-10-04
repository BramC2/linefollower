# start/stop interrupt proof of concept
minimale hard- en software die de correcte werking van een start/stop drukknop aantoont, gebruik makend van een hardware interrupt
volatile boolean ledOn = false;
int button_state = 0;

void setup() {
  // put your setup code here, to run once:
  pinMode(13,OUTPUT);
  pinMode(2,INPUT);
  attachInterrupt(0,buttonPressed,RISING);
}

void loop() {
  // put your main code here, to run repeatedly:
  button_state = digitalRead(2);
  if(button_state == 1)
  {
    buttonPressed();
  }
  delay(100);
}

void buttonPressed(){
  if(ledOn)
  {
    ledOn = false;
    digitalWrite(13,LOW);
  }
  else
  {
    ledOn = true;
    digitalWrite(13,HIGH);
  }
  
}
