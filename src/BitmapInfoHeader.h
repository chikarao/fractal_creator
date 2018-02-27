/*
 * BitmapInfoHeader.h
 *
 *  Created on: Feb 9, 2018
 *      Author: okadachikara
 */

#ifndef BITMAPINFOHEADER_H_
#define BITMAPINFOHEADER_H_

#include <cstdint> // can use int32_t

#pragma pack(2) // remove padding

namespace caveofprogramming {

struct BitmapInfoHeader {
	int32_t headerSize{40}; //byte size of struct, when add all elements
	int32_t width;// initialized later
	int32_t height;
	int16_t planes{1}; // layer feature of bitmap
	int16_t bitsPerPixel{24}; //one byte 8, for each RGB
	int32_t compression{0}; //won't use
	int32_t dataSize{0}; //initialize to 0 but set later
	int32_t horizontalResolution{2400}; //2400 bits per pixel
	int32_t verticalResolution{2400};
	int32_t colors{0}; // probably not used
	int32_t importantColors{0}; // probably not used



	//could have ints and shorts if have 32bit ints
};
} // end of namespace

#endif /* BITMAPINFOHEADER_H_ */
