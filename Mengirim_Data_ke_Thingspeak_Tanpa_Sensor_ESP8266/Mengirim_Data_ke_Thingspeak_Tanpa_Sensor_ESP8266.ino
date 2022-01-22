//--- Mengirim Data Nilai Random ke Website Thingspeak ---//
//          www.blogtambangkode.wordpress.com             //

/*  Nilai variabel yang harus disesuaikan :
 *  1. ssid[]
 *  2. pass[]
 *  3. Channel_ID
 *  4. WriteAPIKey
 */

#include "ThingSpeak.h"
#include <ESP8266WiFi.h>
float nilai = 0;
int x = 0;

//------------- Detail WiFi -----------------//
char ssid[] = "isi di dalam sini";   // network SSID (nama WiFi)
char pass[] = "Isi di dalam sini";   // network password

//-------- Detail Channel Thingspeak ----------//
unsigned long Channel_ID = 000000; // Channel ID
const int No_field = 1; // Nomor field (biarkan nilainya 1)
const char * WriteAPIKey = "Isi di dalam sini"; // Write API Key

WiFiClient  client;

void setup()
{
  Serial.begin(115200);
  WiFi.mode(WIFI_STA);
  ThingSpeak.begin(client);
}

void loop()
{
  internet();
  get_value();
  upload();
}

void internet()
{
  if (WiFi.status() != WL_CONNECTED)
  {
    Serial.print("Mencoba terhubung ke: ");
    Serial.println(ssid);
    while (WiFi.status() != WL_CONNECTED)
    {
      WiFi.begin(ssid, pass);
      Serial.print(".");
      delay(5000);
    }
    Serial.println("\nBerhasil terhubung");
  }
}

void get_value()
{
 nilai = random(0, 100);
 Serial.println("----------------------");
 Serial.print("Nilai Selanjutnya :"); Serial.println(nilai);
 delay(15000);
}

void upload()
{
  internet();
  x = ThingSpeak.writeField(Channel_ID, No_field, nilai, WriteAPIKey);
  if (x == 200)Serial.println("Data telah terupdate");
  if (x != 200)
  {
    Serial.println("Data gagal diupload, mencoba mengirim kembali..");
    delay(15000);
    upload();
  }
}
