#include <Wire.h>
#include <Adafruit_GFX.h>
#include <Adafruit_SSD1306.h>
#include <Adafruit_MPU6050.h>
#include <Adafruit_Sensor.h>

// OLED display dimensions
#define SCREEN_WIDTH 128
#define SCREEN_HEIGHT 64
#define OLED_RESET    -1

// Pin definitions
#define BUZZER_PIN    15

// Initialize components
Adafruit_SSD1306 display(SCREEN_WIDTH, SCREEN_HEIGHT, &Wire, OLED_RESET);
Adafruit_MPU6050 mpu;

void setup() {
  Serial.begin(115200);
  pinMode(BUZZER_PIN, OUTPUT);

  // Initialize OLED
  if(!display.begin(SSD1306_SWITCHCAPVCC, 0x3C)) {
    Serial.println(F("SSD1306 allocation failed"));
    for(;;); // Loop forever if display fails
  }
  
  display.clearDisplay();
  display.setTextSize(1);
  display.setTextColor(SSD1306_WHITE);
  display.setCursor(0, 10);
  display.println("SentinelX Booting...");
  display.display();
  delay(1000);

  // Initialize MPU6050
  if (!mpu.begin()) {
    Serial.println("Failed to find MPU6050 chip");
    while (1) {
      delay(10);
    }
  }
  Serial.println("MPU6050 Found!");
  
  // Set accelerometer range for testing
  mpu.setAccelerometerRange(MPU6050_RANGE_8_G);
}

void loop() {
  // Get new sensor events with the readings
  sensors_event_t a, g, temp;
  mpu.getEvent(&a, &g, &temp);

  // Print values to Serial Monitor for debugging
  Serial.print("Accel Z: "); 
  Serial.print(a.acceleration.z);
  Serial.println(" m/s^2");

  display.clearDisplay();
  display.setCursor(0, 0);
  display.setTextSize(1);
  display.println("SentinelX Status:");

  // MOCK LOGIC: Standard gravity on Z is ~9.8 m/s^2. 
  // We simulate a sudden fall or heavy stumble if Z spikes > 15 or drops < 2 (freefall),
  // or if X/Y axes experience sudden lateral movement > 8 m/s^2.
  if (a.acceleration.z > 15.0 || a.acceleration.z < 2.0 || a.acceleration.x > 8.0 || a.acceleration.y > 8.0) {
    
    // Trigger Alert
    digitalWrite(BUZZER_PIN, HIGH);
    
    // Update OLED
    display.setTextSize(2);
    display.setCursor(0, 20);
    display.println("RISK/FALL");
    display.setCursor(0, 40);
    display.println("DETECTED!");
    display.display();
    
    Serial.println("WARNING: Instability/Fall Detected!");
    delay(1500); // Keep the alert buzzing for 1.5 seconds
    
  } else {
    // Safe State
    digitalWrite(BUZZER_PIN, LOW);
    
    // Update OLED
    display.setTextSize(2);
    display.setCursor(0, 25);
    display.println("SAFE");
    display.display();
  }

  delay(100); // Short delay for stability
}