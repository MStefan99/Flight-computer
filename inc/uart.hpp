/*
 * File:   uart.hpp
 * Author: mikha
 *
 * Created on November 20, 2021, 7:55 PM
 */

#ifndef UART_HPP
#define UART_HPP

#include "device.h"

#include "dma.hpp"
#include "util.hpp"

namespace uart {
	template <class size_type, size_type C>
	struct Buffer {
		uint8_t   buffer[C] {};
		size_type transferred {0};
		size_type remaining {0};

		constexpr static size_type capacity {C};
	};

	template <class size_type, size_type C>
	struct Callback {
		using buffer_type = Buffer<size_type, C>;
		using callback_type = void (*)(const Buffer<size_type, C>&);
	};

	using DefaultCallback = Callback<uint8_t, 8>;
	using DefaultQueue = RingBuffer<uart::Buffer<uint8_t, 16>, uint8_t, 4>;

	void    init();
	uint8_t print(const char* buf);

	uint8_t sendTo1(const uint8_t* buf, uint8_t len);
	void    set1Callback(DefaultCallback::callback_type cb);

	uint8_t sendTo2(const uint8_t* buf, uint8_t len);
	void    set2Callback(uart::DefaultCallback::callback_type cb);
}


#endif /* UART_HPP */
