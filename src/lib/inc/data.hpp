/* 
 * File:   data.hpp
 * Author: Mikhail
 *
 * Created on June 22, 2023, 17:58 PM
 */

#ifndef DATA_HPP
#define	DATA_HPP

#include "device.h"

#include "lib/inc/Matrix.hpp"


namespace data {
    constexpr uint8_t inputChannelNumber {2};
    constexpr uint8_t outputChannelNumber {2};
    
    enum class DATA_DESCRIPTOR_TYPE : uint8_t {
        SETTINGS = 0x00,
        INPUTS = 0x01,
        MUX = 0x02,
        TRIMS = 0x03,
        OUTPUTS = 0x04
    };
    
    typedef struct {
        uint8_t bLength;
        uint8_t bDescriptorType; // 0x0
        uint8_t bInputChannels;
        uint8_t bOutputChannels;
        uint8_t bmActiveSensors;
    } usb_data_settings_descriptor;
    
    typedef struct {
        uint8_t bLength;
        uint8_t bDescriptorType; // 0x01
        int16_t wInputs[inputChannelNumber];
    } usb_data_inputs_descriptor;
    
    typedef struct {
        uint8_t bLength;
        uint8_t bDescriptorType; // 0x02
        int16_t wMux[inputChannelNumber * outputChannelNumber];
    } usb_data_mux_descriptor;
    
    typedef struct {
        uint8_t bLength;
        uint8_t bDescriptorType; // 0x03
        int16_t wTrims[outputChannelNumber];
    } usb_data_trims_descriptor;
    
    typedef struct {
        uint8_t bLength;
        uint8_t bDescriptorType; //0x04
        int16_t wOutputs[outputChannelNumber];
    } usb_data_outputs_descriptor;
    
    extern usb_data_settings_descriptor SETTINGS_DESCRIPTOR;
    extern usb_data_inputs_descriptor INPUTS_DESCRIPTOR;
    extern usb_data_mux_descriptor MUX_DESCRIPTOR;
    extern usb_data_trims_descriptor TRIMS_DESCRIPTOR;
    extern usb_data_outputs_descriptor OUTPUTS_DESCRIPTOR;
    
    uint8_t& activeSensors {SETTINGS_DESCRIPTOR.bmActiveSensors};
    
    Matrix<int16_t> inputs {inputChannelNumber, 1, INPUTS_DESCRIPTOR.wInputs};
    Matrix<int16_t> mux {outputChannelNumber, inputChannelNumber, MUX_DESCRIPTOR.wMux};
    Matrix<int16_t> trims {1, outputChannelNumber, TRIMS_DESCRIPTOR.wTrims};
    Matrix<int16_t> outputs {1, outputChannelNumber, OUTPUTS_DESCRIPTOR.wOutputs};
}

#endif	/* DATA_HPP */
