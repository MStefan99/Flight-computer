#include "lib/inc/data.hpp"
#include "lib/inc/nvm.hpp"

data::usb_data_status_descriptor data::statusDescriptor {};
data::usb_data_inputs_descriptor data::inputsDescriptor {};
data::usb_data_outputs_descriptor data::outputsDescriptor {};

const uint8_t& data::activeSensors {data::statusDescriptor.bmActiveSensors};

InlineMatrix<const int16_t, uint8_t, data::inputChannelCount, 1> data::inputs {data::inputsDescriptor.wInputs};
InlineMatrix<const int16_t, uint8_t, data::inputChannelCount, data::outputChannelCount> data::mux {nvm::options.mux.wMux};
InlineMatrix<const int16_t, uint8_t, 1, data::outputChannelCount> data::trims {nvm::options.trims.wTrims};
InlineMatrix<const int16_t, uint8_t, 1, data::outputChannelCount> data::outputs {data::outputsDescriptor.wOutputs};
