#include <Wire.h>
#include <LiquidCrystal_I2C.h>
#include <Wire.h>
#include <Adafruit_MLX90614.h>

Adafruit_MLX90614 mlx = Adafruit_MLX90614();
LiquidCrystal_I2C lcd (0x27, 20, 4);
float n;

void setup() {
  Serial.begin(9600);
  lcd.init ();
  lcd.backlight();

  if (!mlx.begin()) {
    Serial.println("Error connecting to MLX sensor. Check wiring.");
    while (1);
  };
}

void loop() {
 // Serial.print("Ambient = "); Serial.print(mlx.readAmbientTempC());
    Serial.print("*C\tObject = "); Serial.print(mlx.readObjectTempC()); Serial.println("*C");
    Serial.print("*C\tObject = "); Serial.print((mlx.readObjectTempC()) + 2); Serial.println("*D");
//  Serial.print("Ambient = "); Serial.print(mlx.readAmbientTempF());
//  Serial.print("*F\tObject = "); Serial.print(mlx.readObjectTempF()); Serial.println("*F");
  if (mlx.readObjectTempC() > 34){
     delay (1000);
     lcd.setCursor (0,1);
     lcd.print ("Suhu Anda : ");
     lcd.print ((mlx.readObjectTempC()) + 1);
    }
  else if (mlx.readObjectTempC() <= 34) {
    lcd.clear();
    lcd.setCursor (5,0);
    lcd.print ("Smart Door");
    lcd.setCursor (0,2);
    lcd.print ("Kapasitas ruang = 10");
    lcd.setCursor (3,3);
    lcd.print ("Salam Sehat !");
  }
  
  delay (1000);
}
