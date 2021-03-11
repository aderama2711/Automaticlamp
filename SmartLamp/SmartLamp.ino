int relay = 4;
int pir = 2;
int ldr = A0;
int statuspir = 0;
int statusldr = 0;

void setup()
{
  pinMode(relay, OUTPUT);
  pinMode(pir, INPUT);
  pinMode(ldr, INPUT);
  Serial.begin(9600);
}

void loop()
{
  digitalWrite(relay, LOW);
  statuspir = digitalRead(pir);
  statusldr = analogRead(ldr);
  statusldr = map(statusldr, 1, 310, 1, 25000);
  
  if(statuspir == HIGH && statusldr < 200){
    Serial.println("Lampu Menyala");
    digitalWrite(relay, HIGH);
    delay(50000);
  }
  else{
    Serial.println(statuspir);
    Serial.println(statusldr);
  }
}
