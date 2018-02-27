/*
 * Bitmap.cpp
 *
 *  Created on: Feb 9, 2018
 *      Author: okadachikara
 */

#include <fstream>
#include <iostream>
#include "Bitmap.h"
#include "BitmapInfoHeader.h"
#include "BitmapFileHeader.h"

using namespace caveofprogramming;
//using namespace std;
namespace caveofprogramming {

Bitmap::Bitmap(int width, int height) :
	m_width(width), m_height(height),
			m_pPixels(new uint8_t[width * height * 3] { }) {
	//smart pointer
	//allocating 3(RGB) color values for each pixel * width * height
	//m_pPixels points to block of memory array
	//new uint8_t[width*height*3]{} or new uint8_t[width*height*3]() initializes memory pointed to zeros
	// () like calling constructor before c++2004,
}

bool Bitmap::write(string filename) {
	BitmapFileHeader fileHeader;
	BitmapInfoHeader infoHeader;

	fileHeader.fileSize = sizeof(BitmapFileHeader) + sizeof(BitmapInfoHeader)
			+ m_width * m_height * 3;
	fileHeader.dataOffset = sizeof(BitmapFileHeader) + sizeof(BitmapInfoHeader);

	infoHeader.width = m_width;
	infoHeader.height = m_height;

	ofstream file;
	//	file.open(filename.c_str())
	file.open(filename, ios::out | ios::binary);

	if (!file) {
		return false;
	}

	file.write((char *) &fileHeader, sizeof(fileHeader));
	file.write((char *) &infoHeader, sizeof(infoHeader));
	file.write((char *) m_pPixels.get(), m_width * m_height * 3);
	// expects char star pointer so cast, number of bytes to write
	// using &m_pPixels.get() to get normal pointer;
	file.close();
	// if can't close file don't know if data written

	//	cout << "after file close" << endl;

	if (!file) {
		return false;
	}

	return true;
}

void Bitmap::setPixel(int x, int y, uint8_t red, uint8_t green, uint8_t blue) {
	// leave blank for later
	uint8_t *pPixel = m_pPixels.get(); // smart pointer so use .get() method to get normal pointer
	// now have pointer to entire memory block
	pPixel += (y * 3) * m_width + (x * 3);
	// moves to the desired pixel
	pPixel[0] = blue;
	pPixel[1] = green;
	pPixel[2] = red;
// use array subscript operator so pPixel[i] is equal to pPixel+i

	// reversing in memory
	//0xFF8833 FF red 88 green 33 blue
	// 33 is least significant and smallest effect
	//like 1234004983 1 is most significant, 3 is least
	// 1111101001010101 mem address: left most is smallest memory address
	// and right most is biggest memory address
	// so blue in RGB has to come first
	// little endian file format
}

Bitmap::~Bitmap() {
	// TODO Auto-generated destructor stub
}

}

