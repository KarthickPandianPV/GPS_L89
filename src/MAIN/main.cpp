#include "main.hpp"

SoftwareSerial gps_serial_(GPS_RX_PIN, GPS_TX_PIN);
Gps gps;
void setup() {
  gps.initialize(gps_serial_);
  gps.get_target_coordinates(target_latitude, target_longitude);
  Serial.print("Target latitude : ");
  Serial.println(target_latitude);
  Serial.print("Target longitude : ");
  Serial.println(target_longitude);
  delay(1000);
}

void loop() {
  gps.get_gps_data(gps_serial_);
  if (gps.gps_data_.gps_status) {
    Serial.println("GPS is locked.");
    gps.get_distance(target_distance, target_latitude, target_longitude);
    Serial.print("Distance to target : ");
    Serial.println(target_distance);
    gps.get_direction(target_bearing, target_latitude, target_longitude);
    Serial.print("Direction to target : ");
    Serial.println(target_bearing);
  } else {
    Serial.println("GPS is not locked..!");
  }
  delay(1000);
}

