/* ====================
 * Custom Character LCD
 * ====================
 * By : Tambang Kode
 * 
 * Kunjungi social media kami di :
 * Blog : www.blogtambangkode.wordpress.com
 * Youtube : Tambang Kode
 */

#include <Wire.h>
#include <LiquidCrystal_I2C.h>

LiquidCrystal_I2C lcd(0x27,16,2);

byte love[] = {
  B00000,
  B00000,
  B01010,
  B11111,
  B11111,
  B01110,
  B00100,
  B00000
};

byte petir[] = { 
  B00000, 
  B00001, 
  B00110,
  B01100,
  B11111,
  B00110,
  B01100, 
  B10000 
};

void setup() {
  lcd.init(); // Insialisasi LCD
  lcd.backlight(); // Mengaktifkan backlight LCD

  // Menggunakan method lcd.createChar() untuk membuat custom char
  // Sintaks -> lcd.createChar(noLokasi, namaArray);
  lcd.createChar(0, love);
  lcd.createChar(1, petir);
  lcd.home();
  
  lcd.write(1); // Untuk menampilkan custom character pada layar LCD sesuai location
  lcd.setCursor(1,0);
  lcd.write(0);
  
}

void loop() {
  
}
