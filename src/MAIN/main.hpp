#ifndef MAIN_HPP
#define MAIN_HPP

#include <Arduino.h>
#include <SoftwareSerial.h>
#include <string.h>

#include "GPS/gps.hpp"

using namespace gps_l89;
#define GPS_TX_PIN 1
#define GPS_RX_PIN 0

extern SoftwareSerial gps_serial_;
extern Gps gps;
double target_latitude, target_longitude, target_distance,
    target_bearing;
#endif // MAIN_HPP