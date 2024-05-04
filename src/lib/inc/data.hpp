/* 
 * File:   data.hpp
 * Author: Mikhail
 *
 * Created on June 22, 2023, 17:58 PM
 */

#ifndef DATA_HPP
#define	DATA_HPP

#include "device.h"

#include "lib/inc/InlineMatrix.hpp"
#include "lib/inc/util.hpp"


namespace data {
    constexpr uint8_t inputChannelCount {12};
    constexpr uint8_t outputChannelCount {8};
    constexpr uint8_t muxLength {inputChannelCount * outputChannelCount};

    enum class DATA_REQUEST : uint8_t {
        READ = 0x00,
        WRITE = 0x01,
    };

    enum class DATA_DESCRIPTOR_TYPE : uint8_t {
        STATUS = 0x00,
        SETTINGS = 0x01,
        INPUTS = 0x02,
        MUX = 0x03,
        TRIMS = 0x04,
        OUTPUTS = 0x05
    };

    struct __attribute__((packed)) usb_data_status_descriptor {
        const uint8_t bLength {sizeof(usb_data_status_descriptor)};
        const uint8_t bDescriptorType {0x00};
        int8_t bTemp;
        uint8_t bmActiveSensors;
        int16_t wAcc[3];
        int16_t wRot[3];
        int16_t wRoll;
        int16_t wPitch;
    };

    struct __attribute__((packed)) usb_data_settings_descriptor {
        const uint8_t bLength {sizeof(usb_data_settings_descriptor)};
        const uint8_t bDescriptorType {0x01};
        uint8_t bInputChannels;
        uint8_t bOutputChannels;
    };

    struct __attribute__((packed)) usb_data_inputs_descriptor {
        const uint8_t bLength {sizeof(usb_data_settings_descriptor)};
        const uint8_t bDescriptorType {0x02};
        int16_t wInputs[inputChannelCount];
    };

    struct __attribute__((packed)) usb_data_mux_descriptor {
        const uint8_t bLength {sizeof(usb_data_mux_descriptor)};
        const uint8_t bDescriptorType {0x03};
        int16_t wMux[muxLength];
    };

    struct __attribute__((packed)) usb_data_trims_descriptor {
        const uint8_t bLength {sizeof(usb_data_trims_descriptor)};
        const uint8_t bDescriptorType {0x04};
        int16_t wTrims[outputChannelCount];
    };

    struct __attribute__((packed)) usb_data_outputs_descriptor {
        const uint8_t bLength {sizeof(usb_data_outputs_descriptor)};
        const uint8_t bDescriptorType {0x05};
        int16_t wOutputs[outputChannelCount];
    };

    
    extern usb_data_status_descriptor statusDescriptor;
    extern usb_data_inputs_descriptor inputsDescriptor;
    extern usb_data_outputs_descriptor outputsDescriptor;
    
    extern InlineMatrix<const int16_t, uint8_t, inputChannelCount, 1> inputs;
    extern InlineMatrix<const int16_t, uint8_t, inputChannelCount, outputChannelCount> mux;
    extern InlineMatrix<const int16_t, uint8_t, 1, outputChannelCount> trims;
    extern InlineMatrix<const int16_t, uint8_t, 1, outputChannelCount> outputs;
}

#endif	/* DATA_HPP */
