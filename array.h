// MIT License

// Copyright (c) 2025 IHG69

// Permission is hereby granted, free of charge, to any person obtaining a copy
// of this software and associated documentation files (the "Software"), to deal
// in the Software without restriction, including without limitation the rights
// to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
// copies of the Software, and to permit persons to whom the Software is
// furnished to do so, subject to the following conditions:

// The above copyright notice and this permission notice shall be included in all
// copies or substantial portions of the Software.

// THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
// IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
// FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
// AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
// LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
// OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE
// SOFTWARE.

#ifndef __ARRAY_H__
#define __ARRAY_H__

#include <stdlib.h>
#include <string.h>

#ifndef ASSERT
#	include <assert.h>
#	define ASSERT assert
#endif // ASSERT

#define arrayof(type)    \
	struct {             \
		type *data;      \
		size_t length;   \
		size_t capacity; \
	}                    \

#define append(arr, value)                       \
	do {                                         \
		if (arr.length >= arr.capacity) {        \
			if (arr.capacity == 0) {             \
				arr.capacity = 2;                \
			} else {                             \
				arr.capacity *= 2;               \
			}                                    \
			arr.data = realloc(                  \
				arr.data,                        \
				arr.capacity * sizeof(*arr.data) \
			);                                   \
		}                                        \
		arr.data[arr.length] = value;            \
		arr.length++;                            \
	} while (0);                                 \

#define pop(arr)                        \
	do {                                \
		ASSERT(                         \
			arr.length > 0 &&           \
			"pop(): No elements to pop" \
		);                              \
		arr.data[arr.length-1] = 0;     \
		arr.length--;                   \
	} while (0);                        \

#define shift(arr)                           \
	do {                                     \
		ASSERT(                              \
			arr.length > 0 &&                \
			"shift(): No elements to shift"  \
		);                                   \
		memmove(                             \
			&arr.data[0],                    \
			&arr.data[1],                    \
			arr.capacity * sizeof(*arr.data) \
		);                                   \
		arr.length--;                        \
	} while (0);                             \

#define unshift(arr)                             \
	do {                                         \
		if (arr.length >= arr.capacity) {        \
			if (arr.capacity == 0) {             \
				arr.capacity = 2;                \
			} else {                             \
				arr.capacity *= 2;               \
			}                                    \
			arr.data = realloc(                  \
				arr.data,                        \
				arr.capacity * sizeof(*arr.data) \
			);                                   \
		}                                        \
		memmove(                                 \
			&arr.data[1],                        \
			&arr.data[0],                        \
			arr.capacity * sizeof(*arr.data);    \
		);                                       \
		arr.length++;                            \
	} while (0);                                 \

#define insert(arr, idx, value)                  \
	do {                                         \
		if (arr.length >= arr.capacity) {        \
			if (arr.capacity == 0) {             \
				arr.capacity = 2;                \
			} else {                             \
				arr.capacity *= 2;               \
			}                                    \
			arr.data = realloc(                  \
				arr.data,                        \
				arr.capacity * sizeof(*arr.data) \
			);                                   \
		}                                        \
		memmove(                                 \
			&arr.data[idx+1],                    \
			&arr.data[idx],                      \
			arr.capacity * sizeof(*arr.data)     \
		);                                       \
		arr.data[idx] = value;                   \
		arr.length++;                            \
	} while (0);                                 \

#define clear(arr)                                 \
	do {                                           \
		for (size_t i = 0; i < arr.length; ++i) {  \
			arr.data[i] = 0;                       \
		}                                          \
		arr.length = 0;                            \
	} while (0);                                   \

#define delete(arr)     \
	do {                \
		free(arr.data); \
	} while (0);        \

// Helpers
#define at(arr, idx) arr.data[i]

#define length(arr) arr.length

#endif // __ARRAY_H__
