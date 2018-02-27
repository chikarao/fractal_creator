/*
 * BitmapFileHeader.h
 *
 *  Created on: Feb 9, 2018
 *      Author: okadachikara
 */

#ifndef BITMAPFILEHEADER_H_
#define BITMAPFILEHEADER_H_

#include <cstdint> // make 32 bit int; can use int32_t
using namespace std;
// above is preprocessor language before file compiled
// saying if BITMAPFILEHEADER_H_ is not defined, will be defined
// and paste in code below

#pragma pack(2) // makes c++ align in 2byte boundaries with no hidden padding

namespace caveofprogramming {


struct BitmapFileHeader {
	//public by default
	char header[2] { 'B', 'M' }; // array of two, b and m for bitmap
	int32_t fileSize; //bitmap file need to guarantee to make 32 bit int or 4 bytes
	int32_t reserved { 0 }; // not used; initialized to 0
	int32_t dataOffset; //how long into the file the data begins

};
} // end of namespace


#endif /* BITMAPFILEHEADER_H_ */
