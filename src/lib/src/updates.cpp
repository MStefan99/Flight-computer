#include "lib/inc/updates.hpp"


static AttitudeEstimator e {0.0f, 0.0f};
static PID rollPID {3, 1, 5, MAX_INT16 / 4, MAX_INT16};
static PID pitchPID {3, 1, 5, MAX_INT16 / 4, MAX_INT16};

#define ROLL_LIMIT ( 45 * DEG_TO_RAD )
#define PITCH_LIMIT ( 45 * DEG_TO_RAD )


void updates::init() {
    mpu6050::init();
}

void updates::ms() {
    // Nothing to do here yet
}

void updates::fast() {
    mpu6050::update();
    e.update(mpu6050::getRot(), mpu6050::getAcc(), 0.02f);
    
    data::inputs[0][0] = e.getRoll() * RAD_TO_DEG;
    data::inputs[0][1] = e.getPitch() * RAD_TO_DEG;
    
    data::outputs = data::inputs * data::mux + data::trims;
}

void updates::slow() {
    // Nothing to do here yet
}
