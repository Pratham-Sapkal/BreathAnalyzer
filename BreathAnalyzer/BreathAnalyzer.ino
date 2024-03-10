#include <Wire.h>
#include <Adafruit_GFX.h>
#include <Adafruit_SSD1306.h>
#include <Adafruit_Sensor.h>
#include <DHT.h>

#define SCREEN_WIDTH 128 // OLED display width, in pixels
#define SCREEN_HEIGHT 64 // OLED display height, in pixels

// Declaration for an SSD1306 display connected to I2C (SDA, SCL pins)
Adafruit_SSD1306 display(SCREEN_WIDTH, SCREEN_HEIGHT, &Wire, -1);

#define DHTPIN 4     // Digital pin connected to the DHT sensor
#define buzzerPin 2

#define DHTTYPE    DHT11     // DHT 11

DHT dht(DHTPIN, DHTTYPE);
int gasSensor;
void setup() {
  Serial.begin(115200);
  dht.begin();
  
  pinMode(13,OUTPUT);
  pinMode(14,OUTPUT);
  pinMode(buzzerPin,OUTPUT);
  
  if(!display.begin(SSD1306_SWITCHCAPVCC, 0x3C)) {
    Serial.println(F("SSD1306 allocation failed"));
    for(;;);
  }
  delay(200);
  display.clearDisplay();
  display.setTextColor(WHITE);
}

void loop() {
  delay(500);
  float t = dht.readTemperature();
  float h = dht.readHumidity();
  if (isnan(h) || isnan(t)) {
    Serial.println("Failed to read from DHT sensor!");
  }
  // clear display
  display.clearDisplay();
  
  // display temperature
  display.setTextSize(1);
  display.setCursor(0,0);
  display.print("Temperature: ");
  display.setTextSize(1);
  display.setCursor(0,10);
  display.print(t);
  display.print(" ");
  display.setTextSize(1);
  display.cp437(true);
  display.write(167);
  display.setTextSize(1);
  display.print("C");
  
  // display humidity
  display.setTextSize(1);
  display.setCursor(0, 25);
  display.print("Humidity: ");
  display.setTextSize(1);
  display.setCursor(0, 35);
  display.print(h);
  display.print(" %"); 
  
  display.display(); 

  gasSensor=analogRead(A0);
  Serial.println(gasSensor);
  
  if(gasSensor>500)
  {
    digitalWrite(13,LOW);
    digitalWrite(14,HIGH); 
    display.setTextSize(1);
    display.setCursor(0, 45);
    display.print("Alcohol detected");
    display.setTextSize(1);
    display.setCursor(0, 55);
    display.print(gasSensor);
    display.print("ppm");
    display.display();
     tone(buzzerPin,800,40); 
    
  }
  if(gasSensor<500)
  {
      digitalWrite(13,HIGH);
      digitalWrite(14,LOW);
      display.setTextSize(1);
      display.setCursor(0, 45);
      display.print("No Alcohal detected");      
      display.setTextSize(1);
      display.setCursor(0, 55);
      display.print(gasSensor);
      display.print("ppm");
      display.display();
      noTone(buzzerPin);
  }  
}
