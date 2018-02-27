/*
 * Bitmap.h
 *
 *  Created on: Feb 9, 2018
 *      Author: okadachikara
 */

#ifndef BITMAP_H_
#define BITMAP_H_

#include<string>
#include <cstdint>
using namespace std;

namespace caveofprogramming {

class Bitmap {
private:
	int m_width { 0 }; // initialize to 0 to avoid bugs
	int m_height { 0 };
	unique_ptr<uint8_t[]> m_pPixels{nullptr}; // allocating memory; array of char, set to null to start

public:
	Bitmap(int width, int height); // say how big it s
	bool write(string filename);
	void setPixel(int x, int y, uint8_t red, uint8_t green, uint8_t blue ); // specify colors
	virtual ~Bitmap();
};

}


#endif /* BITMAP_H_ */
