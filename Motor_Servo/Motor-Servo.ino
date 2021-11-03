/* KONTROL MOTOR SERVO ARDUINO
 * ==============================
 * Code in here by : Tambang Kode
 * ==============================
 * Kunjungi social media kami di :
 * Blog : www.blogtambangkode.wordpress.com
 * Youtube : Tambang Kode
 */

#include <Servo.h> // menyertakan library servo
Servo myservo; // membuat object dari class Servo

void setup() {
  myservo.attach(9); // pin 9 Arduino yang terhubung ke PWM servo
 
}

void loop() {
  myservo.write(0); // memutar servo 0 derajat
  delay(1000); // waktu delay 1000 ms (1 s)
  myservo.write(90);
  delay(1000);
  myservo.write(180);
  delay(1000);

}
