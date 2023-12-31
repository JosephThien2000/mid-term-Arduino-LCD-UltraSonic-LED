# MidTerm - How to setup UltraSonic Sensor on Arduino (I2C)
Today, Our team are going to use UltraSonic Sensor to detect the distance of the object. If we detect the distance under 200cm, then it will light up the LED and print out the result via LCD. Let's get it started!

## What do we need?

Here is our Component list:

![Diagram](./images/component_view.png)

## How does it look like?
Here is the circuit view of our project:

![Diagram](./images/diagram.png) 

And our schematic view:

![Diagram](./images/schematic_view.png) 

## Install the library
First of all, we need to install the library on Arduino IDE. Here we use <LiquidCrystal_I2C.h> library to control the LCD. Open the ***Library Manager*** and clidk the "<code style="color : red">INSTALL</code>" button:

![Library Manager](./images/library_manager.png)

## Let's code!
Now we put our main code to the editor and upload it to the Arduino (We use ***Arduino IDE v2.2.2***). Here is our code:
```
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
```
Then, we upload and verify code. Finish!

## Conclusion
Here is our project that shown in above. Hope everyone like and enjoy it! Thank you!