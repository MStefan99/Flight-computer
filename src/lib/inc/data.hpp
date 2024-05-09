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
    constexpr uint8_t inputChannelCount {8};
    constexpr uint8_t outputChannelCount {8};
    constexpr uint8_t muxLength {inputChannelCount * outputChannelCount};

    enum class CommandType : uint8_t {
        GetVariable = 0x0,
        SetVariable = 0x1,
        Calibration = 0x2
    };
    
    enum class ResponseType : uint8_t {
        ReturnVariable = 0x0
    };

    enum class VariableID : uint8_t {
        Status = 0x0,
        Settings = 0x1,
        Inputs = 0x2,
        Mux = 0x3,
        Trims = 0x4,
        Limits = 0x5,
        Outputs = 0x6,
    };

    struct __attribute__((packed)) usb_data_status_descriptor {
        const uint8_t responseType {static_cast<uint8_t>(ResponseType::ReturnVariable)};
        const uint8_t variableID {static_cast<uint8_t>(VariableID::Status)};
        int8_t temperature;
        uint8_t activeSensors;
        int16_t accelerations[3];  // ZYX
        int16_t angularRates[3];  // Yaw - pitch - roll
        int16_t pitch;
        int16_t roll;
    };

    struct __attribute__((packed)) usb_data_settings_descriptor {
        const uint8_t responseType {static_cast<uint8_t>(ResponseType::ReturnVariable)};
        const uint8_t variableID {static_cast<uint8_t>(VariableID::Settings)};
        uint8_t inputChannelCount {inputChannelCount};
        uint8_t outputChannelCount {outputChannelCount};
    };

    struct __attribute__((packed)) usb_data_inputs_descriptor {
        const uint8_t responseType {static_cast<uint8_t>(ResponseType::ReturnVariable)};
        const uint8_t variableID {static_cast<uint8_t>(VariableID::Inputs)};
        int16_t inputs[inputChannelCount];
    };

    struct __attribute__((packed)) usb_data_mux_descriptor {
        const uint8_t responseType {static_cast<uint8_t>(ResponseType::ReturnVariable)};
        const uint8_t variableID {static_cast<uint8_t>(VariableID::Mux)};
        int16_t mux[muxLength];
    };

    struct __attribute__((packed)) usb_data_trims_descriptor {
        const uint8_t responseType {static_cast<uint8_t>(ResponseType::ReturnVariable)};
        const uint8_t variableID {static_cast<uint8_t>(VariableID::Trims)};
        int16_t trims[outputChannelCount];
    };

    struct __attribute__((packed)) usb_data_outputs_descriptor {
        const uint8_t responseType {static_cast<uint8_t>(ResponseType::ReturnVariable)};
        const uint8_t variableID {static_cast<uint8_t>(VariableID::Outputs)};
        int16_t outputs[outputChannelCount];
    };

    
    extern usb_data_status_descriptor statusDescriptor;
    extern usb_data_settings_descriptor settingsDescriptor;
    extern usb_data_inputs_descriptor inputsDescriptor;
    extern usb_data_mux_descriptor muxDescriptor;
    extern usb_data_trims_descriptor trimsDescriptor;
    extern usb_data_outputs_descriptor outputsDescriptor;
    
    extern InlineMatrix<int16_t, uint8_t, inputChannelCount, 1> inputs;
    extern InlineMatrix<int16_t, uint8_t, inputChannelCount, outputChannelCount> mux;
    extern InlineMatrix<int16_t, uint8_t, 1, outputChannelCount> trims;
    extern InlineMatrix<int16_t, uint8_t, 1, outputChannelCount> outputs;
}

#endif	/* DATA_HPP */
