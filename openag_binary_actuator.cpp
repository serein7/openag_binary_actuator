#include "openag_binary_actuator.h"

BinaryActuator::BinaryActuator(int pin, bool is_active_low) {
  _pin = pin;
  _is_active_low = is_active_low;
  _last_cmd = 0;
}

void BinaryActuator::begin() {
  pinMode(_pin, OUTPUT);
}

void BinaryActuator::update() {
  uint32_t curr_time = millis();
  if ((curr_time - _last_cmd) > _max_update_interval) {
    if (_is_active_low) {
      digitalWrite(_pin, HIGH);
    }
    else {
      digitalWrite(_pin, LOW);
    }
  }
}

void BinaryActuator::set_cmd(std_msgs::Bool cmd) {
  _last_cmd = millis();
  if (cmd.data ^ _is_active_low) {
    digitalWrite(_pin, HIGH);
  }
  else {
    digitalWrite(_pin, LOW);
  }
}
