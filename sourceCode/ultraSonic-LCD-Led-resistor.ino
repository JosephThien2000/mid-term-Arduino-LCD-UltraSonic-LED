#include <LiquidCrystal_I2C.h>
//khai bao man hinh
int totalColumns = 16;
int totalRows = 2;

const int TRIG_PIN = 3; // Arduino pin connected to Ultrasonic Sensor's TRIG pin
const int ECHO_PIN = 2; // Arduino pin connected to Ultrasonic Sensor's ECHO pin
const int LED_PIN  = 4; // Arduino pin connected to LED's pin

const int DISTANCE_THRESHOLD = 200; // centimeters

float duration_us, distance_cm;

LiquidCrystal_I2C lcd(0x27, totalColumns, totalRows);

String line1 = "Nguyen Thai Minh Thien Pham Ho Tan Dat";


int scrollSpeed = 100;
void setup(){
  Serial.begin(9000);
  lcd.init(); 
  lcd.backlight(); // use to turn on and turn off LCD back light

  pinMode(TRIG_PIN, OUTPUT); // set arduino pin to output mode
  pinMode(ECHO_PIN, INPUT);  // set arduino pin to input mode
  pinMode(LED_PIN, OUTPUT);  // set arduino pin to output mode
}

void loop()
{
    digitalWrite(TRIG_PIN, HIGH);
    delayMicroseconds(10);
    digitalWrite(TRIG_PIN, LOW);

    duration_us = pulseIn(ECHO_PIN, HIGH);
    // calculate the distance
    distance_cm = 0.017 * duration_us;
    s
    lcd.setCursor(0,0);
    lcd.print(line1);
    lcd.setCursor(0,1);
    // print the value to Serial Monitor
    lcd.print("distance: ");
    lcd.print(distance_cm);
    lcd.println(" cm");
    
    for (int i = 0; i < 100; i++) {
      lcd.scrollDisplayRight();
      delay(scrollSpeed);
    }

    if(distance_cm <= DISTANCE_THRESHOLD)
    {
      digitalWrite(LED_PIN, HIGH); // turn on LED
      //lcd.print(distance_cm);
    }
    else
    {
      digitalWrite(LED_PIN, LOW);
      lcd.print("Out of Range");
    }  // turn off LED



  delay(1000);


  lcd.clear();
}