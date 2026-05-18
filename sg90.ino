/*
 * SG90 Servo — Sweep Demo
 * ------------------------
 * Sweeps an SG90 micro servo from 0° to 180° and back.
 * Uses the built-in Arduino Servo library.
 *
 * Target board: Arduino Uno (or any Arduino)
 * Wiring (SG90 has three wires):
 *   SG90 brown  -> Arduino GND
 *   SG90 red    -> Arduino 5V (see note below)
 *   SG90 orange -> Arduino D9 (signal)
 *
 * Power note: a single SG90 idle draws ~10 mA but can spike to 600+ mA
 * under stall. The Arduino's 5 V pin can usually handle one SG90 if
 * the motion isn't aggressive. For multiple servos, use a separate 5–6 V
 * supply that shares GND with the Arduino.
 *
 * (c) 2026 Circuitrocks. Released under the MIT License.
 * https://github.com/circuitrocks
 */

#include <Servo.h>

Servo servo;
const uint8_t SERVO_PIN = 9;

void setup() {
  Serial.begin(9600);
  servo.attach(SERVO_PIN);
  Serial.println(F("SG90 sweep demo. 0 -> 180 -> 0, repeating."));
}

void loop() {
  // Sweep 0 -> 180 degrees
  for (int angle = 0; angle <= 180; angle++) {
    servo.write(angle);
    delay(15);   // ~3 s for a full sweep
  }

  delay(500);

  // Sweep 180 -> 0 degrees
  for (int angle = 180; angle >= 0; angle--) {
    servo.write(angle);
    delay(15);
  }

  delay(500);
}
