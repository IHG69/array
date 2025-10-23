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
