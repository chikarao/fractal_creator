/*
 * Zoom.h
 *
 *  Created on: Feb 11, 2018
 *      Author: okadachikara
 */

#ifndef ZOOM_H_
#define ZOOM_H_

namespace caveofprogramming {

// store a list of zooms
struct Zoom {
	int x{0};
	int y{0};
	double scale{0.0};

	Zoom(int x, int y, double scale): x(x), y(y), scale(scale) {};
};

}

#endif /* ZOOM_H_ */
