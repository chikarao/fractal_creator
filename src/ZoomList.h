/*
 * ZoomList.h
 *
 *  Created on: Feb 11, 2018
 *      Author: okadachikara
 */

#ifndef ZOOMLIST_H_
#define ZOOMLIST_H_

#include <vector>
#include <utility> // for pair type
#include"Zoom.h"

using namespace std;

namespace caveofprogramming {

class ZoomList {
private:
	double m_xCenter{0};
	double m_yCenter{0};
	double m_scale{1.0}; // default; no scaling at all; as is at 1

	int m_width { 0 };
	int m_height { 0 };
	std::vector<Zoom> zooms;
	// better to use std:: as std has a lot of
	// other stuff that can conflict with other libraries
public:
	ZoomList(int width, int height);

	void add(const Zoom& zoom);
	// take coordinates of pixel that want to do algorithm to

	pair<double, double> doZoom(int x, int y);
	// return pair of values
};
}

#endif /* ZOOMLIST_H_ */
