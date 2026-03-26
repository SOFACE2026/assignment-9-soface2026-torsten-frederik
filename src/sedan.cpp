#include "sedan.hpp"
#include <array>

/*
 sedan is a concrete implementation of the behavioral "Template Method" pattern.
 It provides the specific data and logic steps that the Car base class uses to
 execute its simulation algorithm
*/

static const std::array<double, 7> gear_ratios = {-1, 1, 2, 3, 4, 5, 6};

Sedan::Sedan() : current_gear(0)
{
}

// Concrete implementation of shifting up; ensures the index stays within array bounds
void Sedan::shift_up()
{
    if (current_gear + 1 < (int)gear_ratios.size()) {
        current_gear++;
    }
}

// concrete implementation of shifting down; ensures the index doesn't go below 0
void Sedan::shift_down()
{
    if (current_gear > 0) {
        current_gear--;
    }
}

/*
 concrete implementation for torque calculation
 provides a simplified model where torque is a constant 640 Nm multiplied by throttle
 this is used by the base class 'step' algorithm to calculate acceleration
*/
double Sedan::get_torque(double engine_rpm, double throttle)
{
    return 640.0 * throttle;
}

// Provides the specific weight (2000 kg) for this Sedan implementatio
double Sedan::get_weight()
{
    return  2000.0;
}

// Provides the specific wheel radius (0.3 m) for this Sedan implementatio
double Sedan::get_wheel_radius()
{
    return 0.3;
}

// concrete implementation to retrieve the gear ratio value for the current gear index
double Sedan::get_current_gear_ratio()
{
    return gear_ratios[current_gear];
}