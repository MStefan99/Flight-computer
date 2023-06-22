#include "lib/inc/data.hpp"


data::usb_data_settings_descriptor data::SETTINGS_DESCRIPTOR = {
    .bLength = sizeof (data::usb_data_settings_descriptor),
    .bDescriptorType = static_cast<uint8_t>(data::DATA_DESCRIPTOR_TYPE::SETTINGS),
    .bInputChannels = data::inputChannelNumber,
    .bOutputChannels = data::outputChannelNumber,
    .bmActiveSensors = 0
};

data::usb_data_inputs_descriptor data::INPUTS_DESCRIPTOR = {
    .bLength = sizeof (data::usb_data_inputs_descriptor),
    .bDescriptorType = static_cast<uint8_t>(data::DATA_DESCRIPTOR_TYPE::INPUTS),
    .wInputs = {}
};

data::usb_data_mux_descriptor data::MUX_DESCRIPTOR = {
    .bLength = sizeof (data::usb_data_mux_descriptor),
    .bDescriptorType = static_cast<uint8_t>(data::DATA_DESCRIPTOR_TYPE::MUX),
    .wMux = {}
};

data::usb_data_trims_descriptor data::TRIMS_DESCRIPTOR = {
    .bLength = sizeof (data::usb_data_trims_descriptor),
    .bDescriptorType = static_cast<uint8_t>(data::DATA_DESCRIPTOR_TYPE::TRIMS),
    .wTrims = {}
};

data::usb_data_outputs_descriptor data::OUTPUTS_DESCRIPTOR = {
    .bLength = sizeof (data::usb_data_outputs_descriptor),
    .bDescriptorType = static_cast<uint8_t>(data::DATA_DESCRIPTOR_TYPE::OUTPUTS),
    .wOutputs = {}
};

