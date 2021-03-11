int relay = 4; //inisialisasi relay sebagai 4(pin dari relay)
int pir = 2; //inisialisasi pir sebagai 2(pin dari pir)
int ldr = A0; //inisialisasi ldr sebagai A0(pin dari ldr)
int statuspir = 0; //inisialisasi variabel pembacaan pir
int statusldr = 0; //inisialisasi variabel pembacaan ldr

void setup()
{
  pinMode(relay, OUTPUT); //relay(pin 4) sebagai output
  pinMode(pir, INPUT); //pir(pin 2) sebagai input
  pinMode(ldr, INPUT); //ldr(pin A0) sebagai input
  Serial.begin(9600); //inisialisasi serial dengan 9600 baud
}

void loop()
{
  digitalWrite(relay, LOW); //set relay low(lampu mati)
  statuspir = digitalRead(pir); //membaca data pir
  statusldr = analogRead(ldr); //membaca data ldr
  statusldr = map(statusldr, 1, 310, 1, 25000); //konversi pembacaan ldr ke lux
  
  if(statuspir == HIGH && statusldr < 200){ //cek kondisi jika ada gerakan(statuspir == HIGH) dan cahaya kurang(statusldr < 200)
    Serial.println("Lampu Menyala"); //output "Lampu Menyala" pada serial
    digitalWrite(relay, HIGH); //set relay high(lampu menyala)
    delay(300000); //delay 300 second/5 minute
  }
  else{ //jika kondisi diatas tidak terpenuhi
    Serial.println(statuspir); //output nilai pir pada serial
    Serial.println(statusldr); //output nilai ldr pada serial
  }
}
