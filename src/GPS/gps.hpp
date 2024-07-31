#ifndef GPS_L89
#define GPS_L89
#include <SoftwareSerial.h>

#include "Arduino.h"

typedef struct {
  char gprmc_message[100];
  double latitude_in_degrees;
  double longitude_in_degrees;
  char latitude_direction;
  char longitude_direction;
  double latitude_in_ddmmss;
  double longitude_in_ddmmss;
  double altitude;
  double speed;
  double time;
  double date;
  bool gps_status;
} gps_data;

namespace gps_l89{
class Gps {
 private:
  void get_gprmc_message(SoftwareSerial& gps_serial_);
  void get_gps_status();
  void get_speed();
  void get_time();
  void get_date();
  void get_lat_long();
  void get_lat_long_in_degrees();
  void get_lat_long_in_radians();

 public:
  Gps(/* args */);
  ~Gps();
  gps_data gps_data_;
  void initialize(SoftwareSerial& gps_serial_);
  void cold_start(SoftwareSerial& gps_serial_);
  void warm_start(SoftwareSerial& gps_serial_);
  void hot_start(SoftwareSerial& gps_serial_);
  void get_target_coordinates(double& target_latitude,
                              double& target_longitude);
  void get_gps_data(SoftwareSerial& gps_serial_);
  void get_distance(double& distance, double target_latitude,
                    double target_longitude);
  void get_direction(double& direction, double target_latitude,
                     double target_longitude);
};

}  // namespace gps_l89

#endif