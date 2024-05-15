#include "lib/inc/data.hpp"
#include "lib/inc/nvm.hpp"


data::USBStatusResponse data::usbStatusResponse {};
data::USBSensorsResponse data::usbSensorsResponse {};
data::USBSettingsResponse data::usbSettingsResponse {};
data::USBInputsResponse data::usbInputsResponse {};
data::USBMixesResponse data::usbMixesResponse {};
data::USBTrimsResponse data::usbTrimsResponse {};
data::USBLimitsResponse data::usbLimitsResponse {};
data::USBOutputsResponse data::usbOutputsResponse {};
data::USBPIDsResponse data::usbPIDsResponse {};

InlineMatrix<int16_t, uint8_t, data::inputChannelNumber, 1> data::inputs {data::usbInputsResponse.inputs};
InlineMatrix<int16_t, uint8_t, data::outputChannelNumber, data::inputChannelNumber> data::mixes {data::usbMixesResponse.mixes};
InlineMatrix<int16_t, uint8_t, data::outputChannelNumber, 1> data::trims {data::usbTrimsResponse.trims};
InlineMatrix<int16_t, uint8_t, data::outputChannelNumber, 2> data::limits {data::usbLimitsResponse.limits};
InlineMatrix<int16_t, uint8_t, data::outputChannelNumber, 1> data::outputs {data::usbOutputsResponse.outputs};

InlinePID<float> data::pids[data::pidNumber] {
    {data::usbPIDsResponse.coefficients, PI / 8}, 
    {data::usbPIDsResponse.coefficients + 1, PI / 8},
    {data::usbPIDsResponse.coefficients + 2, PI / 8}
};

InlinePID<float>& data::rollPID {data::pids[0]};
InlinePID<float>& data::pitchPID {data::pids[2]};
InlinePID<float>& data::headingPID {data::pids[2]};

void data::calculateOutputs() {
    auto out = mixes.multiplyAndScale(inputs, static_cast<int16_t>(1000)) + trims;
    
    for (uint8_t i {0}; i < outputChannelNumber; ++i) {
        outputs[i][0] = util::clamp(out[i][0], limits[i][0], limits[i][1]);
    }
}
