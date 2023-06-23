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
#include "lib/inc/usb.hpp"


namespace data {
    constexpr uint8_t inputChannelNumber{2};
    constexpr uint8_t outputChannelNumber{2};

    enum class DATA_REQUEST : uint8_t {
        READ = 0x00,
        WRITE = 0x01,
    };

    enum class DATA_DESCRIPTOR_TYPE : uint8_t {
        SETTINGS = 0x00,
        INPUTS = 0x01,
        MUX = 0x02,
        TRIMS = 0x03,
        OUTPUTS = 0x04
    };

    typedef struct __attribute__((packed)) {
        uint8_t bLength;
        int8_t bTemp;
        int16_t wAcc[3];
        int16_t wRot[3];
    } usb_data_status_descriptor;

    typedef struct __attribute__((packed)) {
        uint8_t bLength;
        uint8_t bDescriptorType; // 0x0
        uint8_t bInputChannels;
        uint8_t bOutputChannels;
        uint8_t bmActiveSensors;
    } usb_data_settings_descriptor;

    typedef struct __attribute__((packed)) {
        uint8_t bLength;
        uint8_t bDescriptorType; // 0x01
        int16_t wInputs[inputChannelNumber];
    } usb_data_inputs_descriptor;

    typedef struct __attribute__((packed)) {
        uint8_t bLength;
        uint8_t bDescriptorType; // 0x02
        int16_t wMux[inputChannelNumber * outputChannelNumber];
    } usb_data_mux_descriptor;

    typedef struct __attribute__((packed)) {
        uint8_t bLength;
        uint8_t bDescriptorType; // 0x03
        int16_t wTrims[outputChannelNumber];
    } usb_data_trims_descriptor;

    typedef struct __attribute__((packed)) {
        uint8_t bLength;
        uint8_t bDescriptorType; //0x04
        int16_t wOutputs[outputChannelNumber];
    } usb_data_outputs_descriptor;

    extern usb_data_status_descriptor STATUS_DESCRIPTOR;
    extern usb_data_settings_descriptor SETTINGS_DESCRIPTOR;
    extern usb_data_inputs_descriptor INPUTS_DESCRIPTOR;
    extern usb_data_mux_descriptor MUX_DESCRIPTOR;
    extern usb_data_trims_descriptor TRIMS_DESCRIPTOR;
    extern usb_data_outputs_descriptor OUTPUTS_DESCRIPTOR;

    extern uint8_t& activeSensors;
    extern Matrix<int16_t> inputs;
    extern Matrix<int16_t> mux;
    extern Matrix<int16_t> trims;
    extern Matrix<int16_t> outputs;
}

#endif	/* DATA_HPP */
