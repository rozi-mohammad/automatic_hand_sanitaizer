
#include <Wire.h> 
#include <LiquidCrystal_I2C.h>
#include <Wire.h>
#include <Adafruit_MLX90614.h>
Adafruit_MLX90614 mlx = Adafruit_MLX90614();

LiquidCrystal_I2C lcd(0x27,16,2);  

void setup()
{
  mlx.begin();  
  lcd.init();                      
  lcd.backlight();
}


void loop()
{
  //(mlx.readObjectTempC()+10);
  lcd.setCursor(0,0);
  if(mlx.readObjectTempC()>29){
    delay(1000);
    lcd.print("Suhu Anda Tinggi");
    
  }
  lcd.print("___NonContact___");
  lcd.setCursor(2,1);
  lcd.print("Suhu: ");
  lcd.print(mlx.readObjectTempC()+10);
  lcd.print("C    ");
  delay(500);
}
