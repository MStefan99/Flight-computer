#include "lib/inc/data.hpp"
#include "lib/inc/nvm.hpp"

data::usb_data_status_descriptor data::statusDescriptor {};
data::usb_data_settings_descriptor data::settingsDescriptor {};
data::usb_data_inputs_descriptor data::inputsDescriptor {};
data::usb_data_mux_descriptor data::muxDescriptor {};
data::usb_data_trims_descriptor data::trimsDescriptor {};
data::usb_data_outputs_descriptor data::outputsDescriptor {};

InlineMatrix<int16_t, uint8_t, data::inputChannelCount, 1> data::inputs {data::inputsDescriptor.inputs};
InlineMatrix<int16_t, uint8_t, data::inputChannelCount, data::outputChannelCount> data::mux {data::muxDescriptor.mux};
InlineMatrix<int16_t, uint8_t, 1, data::outputChannelCount> data::trims {data::trimsDescriptor.trims};
InlineMatrix<int16_t, uint8_t, 1, data::outputChannelCount> data::outputs {data::outputsDescriptor.outputs};
