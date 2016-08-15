#ifndef OPENAG_BINARY_ACTUATOR_H
#define OPENAG_BINARY_ACTUATOR_H

#include "Arduino.h"
#include <std_msgs/Bool.h>
#include <openag_module.h>

class BinaryActuator : public Module {
  public:
    // Constructor
    BinaryActuator(int pin, bool is_active_low);

    // Public functions
    void begin();
    void update();
    void set_cmd(std_msgs::Bool cmd);

  private:
    // Private variables
    int _pin;
    bool _is_active_low;
    uint32_t _last_cmd;
    const static int _max_update_interval = 10000;
};

#endif
