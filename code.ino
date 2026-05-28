#include <LiquidCrystal.h>
#include <DHT.h>

// ---------------- LCD ----------------
LiquidCrystal lcd(12, 11, 10, 9, 8, 6);

// ---------------- DHT11 ----------------
#define DHTPIN 16        // A2 acts as digital pin 16
#define DHTTYPE DHT11

DHT dht(DHTPIN, DHTTYPE);

// ---------------- SENSOR PINS ----------------
int moisturePin = A0;
int rainPin = 2;
int switchPin = 3;
int flowPin = 4;
int relayPin = 7;

// ---------------- FLOW SENSOR ----------------
volatile int pulseCount = 0;
float flowRate = 0;

// Interrupt function for flow sensor
void countPulse() {
  pulseCount++;
}

void setup() {

  // Pin modes
  pinMode(rainPin, INPUT);
  pinMode(switchPin, INPUT_PULLUP);
  pinMode(flowPin, INPUT);
  pinMode(relayPin, OUTPUT);

  // Relay OFF initially
  digitalWrite(relayPin, HIGH);

  // Flow sensor interrupt
  attachInterrupt(digitalPinToInterrupt(flowPin), countPulse, RISING);

  // LCD setup
  lcd.begin(16, 2);

  // DHT sensor setup
  dht.begin();

  // Serial Monitor
  Serial.begin(9600);

  delay(2000);
}

void loop() {

  // ---------------- READ SENSORS ----------------

  int moistureValue = analogRead(moisturePin);

  int rainValue = digitalRead(rainPin);

  int switchState = digitalRead(switchPin);

  float temperature = dht.readTemperature();

  float humidity = dht.readHumidity();

  // DHT safety check
  if (isnan(temperature) || isnan(humidity)) {
    temperature = 0;
    humidity = 0;
  }

  // ---------------- PUMP CONTROL LOGIC ----------------

  bool pumpState = false;

  // Manual override switch
  if (switchState == LOW) {

    pumpState = true;

  } 
  else {

    // Rain detected
    if (rainValue == LOW) {

      pumpState = false;

    } 
    else {

      // Dry soil condition
      if (moistureValue < 400) {

        pumpState = true;

      } 
      else {

        pumpState = false;
      }
    }
  }

  // ---------------- RELAY CONTROL ----------------
  // Relay is ACTIVE LOW

  if (pumpState == true) {

    digitalWrite(relayPin, LOW);

  } 
  else {

    digitalWrite(relayPin, HIGH);
  }

  // ---------------- FLOW SENSOR ----------------

  flowRate = pulseCount * 0.1;

  pulseCount = 0;

  // ---------------- LCD DISPLAY ----------------

  lcd.clear();

  lcd.setCursor(0, 0);

  lcd.print("M:");
  lcd.print(moistureValue);

  lcd.print(" F:");
  lcd.print(flowRate);

  lcd.setCursor(0, 1);

  lcd.print("T:");
  lcd.print(temperature);

  lcd.print(" H:");
  lcd.print(humidity);

  // ---------------- SERIAL MONITOR ----------------

  Serial.println("========= SMART IRRIGATION SYSTEM =========");

  Serial.print("Soil Moisture Value: ");
  Serial.println(moistureValue);

  Serial.print("Rain Status: ");

  if (rainValue == LOW) {
    Serial.println("RAIN DETECTED");
  } 
  else {
    Serial.println("NO RAIN");
  }

  Serial.print("Manual Switch: ");

  if (switchState == LOW) {
    Serial.println("ON");
  } 
  else {
    Serial.println("OFF");
  }

  Serial.print("Pump Status: ");

  if (pumpState == true) {
    Serial.println("PUMP ON");
  } 
  else {
    Serial.println("PUMP OFF");
  }

  Serial.print("Water Flow Rate: ");
  Serial.println(flowRate);

  Serial.print("Temperature: ");
  Serial.print(temperature);
  Serial.println(" C");

  Serial.print("Humidity: ");
  Serial.print(humidity);
  Serial.println(" %");

  Serial.println("===========================================");

  delay(1000);
}