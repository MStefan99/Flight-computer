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
    constexpr uint8_t inputChannelNumber {8};
    constexpr uint8_t outputChannelNumber {8};
    constexpr uint8_t mixesNumber {inputChannelNumber * outputChannelNumber};

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
        Sensors = 0x1,
        Settings = 0x2,
        Inputs = 0x3,
        Mux = 0x4,
        Trims = 0x5,
        Limits = 0x6,
        Outputs = 0x7,
    };

    struct __attribute__((packed)) USBStatusResponse {
        const uint8_t responseType {static_cast<uint8_t>(ResponseType::ReturnVariable)};
        const uint8_t variableID {static_cast<uint8_t>(VariableID::Status)};
        uint8_t mode;
        uint8_t _reserved0;
        int16_t yaw;
        int16_t pitch;
        int16_t roll;
    };
    
    struct __attribute__((packed)) USBSensorsResponse {
        const uint8_t responseType {static_cast<uint8_t>(ResponseType::ReturnVariable)};
        const uint8_t variableID {static_cast<uint8_t>(VariableID::Sensors)};
        int8_t temperature;
        uint8_t activeSensors;
        int16_t accelerations[3];  // ZYX
        int16_t angularRates[3];  // Yaw - pitch - roll
        int16_t magneticFields[3];
        uint16_t airPressure;
    };

    struct __attribute__((packed)) USBSettingsResponse {
        const uint8_t responseType {static_cast<uint8_t>(ResponseType::ReturnVariable)};
        const uint8_t variableID {static_cast<uint8_t>(VariableID::Settings)};
        const uint8_t inputChannelNumber {data::inputChannelNumber};
        const uint8_t outputChannelNumber {data::outputChannelNumber};
    };

    struct __attribute__((packed)) USBInputsResponse {
        const uint8_t responseType {static_cast<uint8_t>(ResponseType::ReturnVariable)};
        const uint8_t variableID {static_cast<uint8_t>(VariableID::Inputs)};
        int16_t inputs[inputChannelNumber];
    };

    struct __attribute__((packed)) USBMixesResponse {
        const uint8_t responseType {static_cast<uint8_t>(ResponseType::ReturnVariable)};
        const uint8_t variableID {static_cast<uint8_t>(VariableID::Mux)};
        int16_t mixes[mixesNumber];
    };

    struct __attribute__((packed)) USBTrimsResponse {
        const uint8_t responseType {static_cast<uint8_t>(ResponseType::ReturnVariable)};
        const uint8_t variableID {static_cast<uint8_t>(VariableID::Trims)};
        int16_t trims[outputChannelNumber];
    };
    
    struct __attribute__((packed)) USBLimitsResponse {
        const uint8_t responseType {static_cast<uint8_t>(ResponseType::ReturnVariable)};
        const uint8_t variableID {static_cast<uint8_t>(VariableID::Limits)};
        int16_t limits[outputChannelNumber * 2];
    };

    struct __attribute__((packed)) USBOutputsResponse {
        const uint8_t responseType {static_cast<uint8_t>(ResponseType::ReturnVariable)};
        const uint8_t variableID {static_cast<uint8_t>(VariableID::Outputs)};
        int16_t outputs[outputChannelNumber];
    };

    
    extern USBStatusResponse usbStatusResponse;
    extern USBSensorsResponse usbSensorsResponse;
    extern USBSettingsResponse usbSettingsResponse;
    extern USBInputsResponse usbInputsResponse;
    extern USBMixesResponse usbMixesResponse;
    extern USBTrimsResponse usbTrimsResponse;
    extern USBLimitsResponse usbLimitsResponse;
    extern USBOutputsResponse usbOutputsResponse;
    
    extern InlineMatrix<int16_t, uint8_t, inputChannelNumber, 1> inputs;
    extern InlineMatrix<int16_t, uint8_t, outputChannelNumber, inputChannelNumber> mixes;
    extern InlineMatrix<int16_t, uint8_t, outputChannelNumber, 1> trims;
    extern InlineMatrix<int16_t, uint8_t, outputChannelNumber, 2> limits;
    extern InlineMatrix<int16_t, uint8_t, outputChannelNumber, 1> outputs;
    
    
    void calculateOutputs();
}

#endif	/* DATA_HPP */
