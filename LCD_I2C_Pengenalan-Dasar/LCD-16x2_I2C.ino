/* 
Menampilkan data berupa teks di LCD 16x2 + I2C
------------------------------------
Oleh : Tambang Kode
kunjungi social media kami di
Blog : www.blogtambangkode.wordpress.com
Youtube : Tambang Kode
*/
#include <Wire.h>                 
#include <LiquidCrystal_I2C.h>    

LiquidCrystal_I2C lcd(0x27,16,2); // set alamat LCD

void setup() {
  // Inisiasi LCD
  lcd.init(); 
}

void loop() {
    lcd.backlight(); // menyalakan backlight                        
    lcd.print("Tambang Kode"); // menampilkan teks pada LCD
    delay(2000);

    lcd.clear(); // menghapus tampilan LCD
    lcd.noBacklight(); // mematikan backlight          
    lcd.print("Lampu Mati");    
    delay(2000);

    lcd.clear();                
    lcd.backlight();
    lcd.print("Lampu Hidup");   
    delay(2000);

    lcd.clear();                
    lcd.setCursor(0,0); // set posisi cursor di kolom 0 baris 0         
    lcd.print("Baris satu");    
    lcd.setCursor(3,1); // set posisi cursor di kolom 3 baris 1       
    lcd.print("Geser"); 
    delay(3000);

    lcd.clear();                
  }
/* 
Note : Jika LCD masih tidak menampilkan teks. 
Coba untuk mengganti alamat LCD menjadi 0x3F. 
Maka menjadi seperti ini,
LiquidCrystal_I2C lcd(0x3F, 16, 2)
*/
