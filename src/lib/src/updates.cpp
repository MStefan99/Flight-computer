#include "lib/inc/updates.hpp"

static constexpr float ATT_LSB {20860.0f};

static AttitudeEstimator e {0.0f, 0.0f};
static PID rollPID {3, 1, 5, 256, 1536};
static PID pitchPID {3, 1, 5, 256, 1536};

#define ROLL_LIMIT ( 45 * DEG_TO_RAD )
#define PITCH_LIMIT ( 45 * DEG_TO_RAD )


void updates::init() {
    lsm6dso::init();
}

void updates::ms() {
    // Nothing to do here yet
}

void updates::fast() {
    lsm6dso::update();
    
    util::copy(data::STATUS_DESCRIPTOR.wAcc, lsm6dso::getRawAcc(), 3);
    util::copy(data::STATUS_DESCRIPTOR.wRot, lsm6dso::getRawRot(), 3);
    
    e.update(lsm6dso::getRot(), lsm6dso::getAcc(), 0.02f);
    
    data::STATUS_DESCRIPTOR.wRoll = e.getRoll() * ATT_LSB;
    data::STATUS_DESCRIPTOR.wPitch = e.getPitch() * ATT_LSB;
    
//    data::inputs[0][0] = e.getRoll() * RAD_TO_DEG;
//    data::inputs[0][1] = e.getPitch() * RAD_TO_DEG;
    
//    data::outputs = data::inputs * data::mux + data::trims;
}

void updates::slow() {
    // Nothing to do here yet
}
