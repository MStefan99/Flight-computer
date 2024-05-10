#include "lib/inc/data.hpp"
#include "lib/inc/nvm.hpp"

data::USBStatusResponse data::usbStatusResponse {};
data::USBSettingsResponse data::usbSettingsResponse {};
data::USBInputsResponse data::usbInputsResponse {};
data::USBMixesResponse data::usbMixesResponse {};
data::USBTrimsResponse data::usbTrimsResponse {};
data::USBOutputsResponse data::usbOutputsResponse {};

InlineMatrix<int16_t, uint8_t, data::inputChannelCount, 1> data::inputs {data::usbInputsResponse.inputs};
InlineMatrix<int16_t, uint8_t, data::inputChannelCount, data::outputChannelCount> data::mixes {data::usbMixesResponse.mixes};
InlineMatrix<int16_t, uint8_t, data::outputChannelCount, 1> data::trims {data::usbTrimsResponse.trims};
InlineMatrix<int16_t, uint8_t, data::outputChannelCount, 1> data::outputs {data::usbOutputsResponse.outputs};
