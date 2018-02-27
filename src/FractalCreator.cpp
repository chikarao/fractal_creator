/*
 * FractalCreator.cpp
 *
 *  Created on: Feb 12, 2018
 *      Author: okadachikara
 */

#include<iostream>
#include "FractalCreator.h"
#include "Zoom.h"
#include "ZoomList.h"
#include "Mandelbrot.h"
#include "Bitmap.h"
#include <memory> // create unique pointer
#include <math.h>
#include <cstdint>
#include<assert.h>

using namespace std;

namespace caveofprogramming {

void FractalCreator::run(string name) {

	calculateIterations();
	calculateTotalIterations();
	calculateRangeTotals();
	drawFractal();
	writeBitmap("test.bmp");
}

void FractalCreator::addZoom(const Zoom& zoom) {
	m_zoomList.add(zoom);
}

void FractalCreator::addRange(double rangeEnd, const RGB& rgb) {
	m_ranges.push_back(rangeEnd * Mandelbrot::MAX_ITERATIONS);
	//	cout << rangeEnd << endl;

	m_colors.push_back(rgb);

	if (m_bGotFirstRange) {
		m_rangeTotals.push_back(0);
	}
	m_bGotFirstRange = true;

}

int FractalCreator::getRange(int iterations) const {
	int range = 0;
	for (int i = 1; i < m_ranges.size(); i++) {
		range = i;
		if (m_ranges[i] > iterations) {
			break;
		}
	}
	range--;

	// assert checks condition, and if not, will crash
	// i should not go out of the range or it will run sometimes but will crash
	assert(range > -1);
	assert(range < m_ranges.size());

	return range;
}

FractalCreator::FractalCreator(int width, int height) :
	m_width(width), m_height(height),
			m_histogram(new int[Mandelbrot::MAX_ITERATIONS] { 0 }),
			m_fractal(new int[m_width * m_height] { 0 }),
			m_bitmap(m_width, m_height), m_zoomList(m_width, m_height) {// TODO Auto-generated constructor stub
	m_zoomList.add(Zoom(m_width / 2, m_height / 2, 4.0 / m_width));

}

void FractalCreator::calculateIterations() {
	for (int y = 0; y < m_height; y++) {
		for (int x = 0; x < m_width; x++) {
			//			bitmap.setPixel(x, y, 255, 0, 0); // sets all to red
			//			double xFractal = (x - WIDTH / 2 - 200) * 2.0 / HEIGHT; //range of -1 to +1; offset by +-, scaling by */;
			//			double yFractal = (y - HEIGHT / 2) * 2.0 / HEIGHT;

			pair<double, double> coords = m_zoomList.doZoom(x, y);

			int iterations = Mandelbrot::getIterations(coords.first,
					coords.second);
			// getIterations return iterations until c goes to infinity

			m_fractal[y * m_width + x] = iterations;

			if (iterations != Mandelbrot::MAX_ITERATIONS) {
				m_histogram[iterations]++;
			}

			//increment array


			//			if (yFractal < min)
			//				min = yFractal; //if no bracket, first statement only apply after if
			//			if (yFractal > max)
			//				max = yFractal; //if no bracket, first statement only apply after if
		}

	}
}

void FractalCreator::calculateRangeTotals() {

	int rangeIndex = 0;

	for (int i = 0; i < Mandelbrot::MAX_ITERATIONS; i++) {
		int pixels = m_histogram[i];
		//		cout << i << ": "<< m_ranges[rangeIndex+1] << endl;

		if (i >= m_ranges[rangeIndex + 1]) {
			rangeIndex++;
		}
		m_rangeTotals[rangeIndex] += pixels;
	}
	int testRangeTotal = 0;

for(int value: m_rangeTotals) {
	//			cout << "Range sub total: " << value << endl;
	testRangeTotal += value;

}
//	cout << "Range total: " << testRangeTotal << endl;


//	for(int value: m_ranges) {
//				cout << "m_ranges: " << value << endl;
//			}
}

void FractalCreator::calculateTotalIterations() {

for (int i = 0; i < Mandelbrot::MAX_ITERATIONS; i++) {
	m_total += m_histogram[i];
}

//	cout << "Overall total: " << m_total << endl;

}

void FractalCreator::drawFractal() {

for (int y = 0; y < m_height; y++) {
	for (int x = 0; x < m_width; x++) {

		int iterations = m_fractal[y * m_width + x];
		//			uint8_t color = (uint8_t) (256 * (double) iterations / Mandelbrot::MAX_ITERATIONS);

		int range = getRange(iterations);
		int rangeTotal = m_rangeTotals[range];
		int rangeStart = m_ranges[range];
		// number of iterations at start of the range

		RGB& startColor = m_colors[range];
		// start color for range
		RGB& endColor = m_colors[range+1];
		RGB colorDiff = endColor - startColor;

		uint8_t red = 0;
		uint8_t green = 0;
		uint8_t blue = 0;

		if (iterations != Mandelbrot::MAX_ITERATIONS) {

			int totalPixels = 0;
			//			double hue = 0.0;

			for (int i = rangeStart; i <= iterations; i++) {

				totalPixels += m_histogram[i];

//				hue += ((double) m_histogram[i]) / m_total;
				//darkest for most pixel with number of iterations
			}

			red = startColor.r + colorDiff.r * (double)totalPixels/rangeTotal;
			green = startColor.g + colorDiff.g * (double)totalPixels/rangeTotal;
			blue = startColor.b + colorDiff.b * (double)totalPixels/rangeTotal;

//			green = startColor.g + colorDiff.g * hue;
//			blue = startColor.b + colorDiff.b * hue;

			//				green = hue * 255;
		}
		//			color = color * color * color;
		m_bitmap.setPixel(x, y, red, green, blue);
		//			if (color < min)
		//				min = color; //if no bracket, first statement only apply after if
		//			if (color > max)
		//				max = color;
	}
}
}

void FractalCreator::writeBitmap(string name) {
m_bitmap.write(name);
}

FractalCreator::~FractalCreator() {
// TODO Auto-generated destructor stub
}

}
