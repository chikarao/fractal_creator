/*
 * FractalCreator.h
 *
 *  Created on: Feb 12, 2018
 *      Author: okadachikara
 */

#ifndef FRACTALCREATOR_H_
#define FRACTALCREATOR_H_

#include<string>
#include"Zoom.h"
#include"Bitmap.h"
#include"ZoomList.h"
#include<vector>
#include"RGB.h"
using namespace std;
// string an std for using string

namespace caveofprogramming {

class FractalCreator {
private:
	int m_width;
	int m_height;
	unique_ptr<int[]> m_histogram;
	// use unique pointer to save having to delete
	// store number of pixels with certain number of iterations
	//{} to initialize array to zero

	unique_ptr<int[]> m_fractal;
	// pointer for each pixel on screen; note not *3 since they are not colors just pixels
	Bitmap m_bitmap;
	ZoomList m_zoomList;
	int m_total { 0 };

	vector<double> m_ranges;
	vector<RGB> m_colors;
	vector<int> m_rangeTotals;

	bool m_bGotFirstRange{false};

private:

	void calculateIterations();
	void calculateTotalIterations();
	void calculateRangeTotals();
	void drawFractal();

	void writeBitmap(string name);

	int getRange(int iterations) const;
	// const since doesn't change any members of fractalcreator

public:
	FractalCreator(int width, int height);
	void addRange(double rangeEnd, const RGB& rgb);
	// need vector of int of iterations for rangeEnd and one for RGB
	void addZoom(const Zoom& zoom);
	void run(string name);
	virtual ~FractalCreator();

};

}

#endif /* FRACTALCREATOR_H_ */
