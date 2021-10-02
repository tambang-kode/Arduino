/* 
Mengukur jarak benda dengan sensor HC-SR04

------------------------------------
oleh : Tambang Kode
kunjungi social media kami di
Blog : www.blogtambangkode.wordpress.com
Youtube : Tambang Kode
*/

// setting pin trig dan echo sensor
const int trigPin = 8;
const int echoPin = 9;

long durasi;
int jarak;

void setup() {
  pinMode(trigPin, OUTPUT);
  pinMode(echoPin, INPUT);  
  Serial.begin(9600);
}

void loop() {
  // memastikan pin trig dalam keadaan mati
  digitalWrite(trigPin, LOW);
  delayMicroseconds(2);

  // menyalakan pin trig untuk memancarkan gelombang ultrasonik
  digitalWrite(trigPin, HIGH);
  delayMicroseconds(10);
  digitalWrite(trigPin, LOW);
  
  // membaca durasi gelombang
  durasi = pulseIn(echoPin, HIGH);
  jarak = durasi*0.034/2;

  // output serial monitor
  Serial.print("Jarak : ");
  Serial.println(jarak);
  delay(500);
}
