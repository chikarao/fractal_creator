/*
 * RGB.h
 *
 *  Created on: Feb 12, 2018
 *      Author: okadachikara
 */

#ifndef RGB_H_
#define RGB_H_

namespace caveofprogramming {

struct RGB {

	double r;
	double g;
	double b;

	RGB(double r, double g, double b);

};
RGB operator-(const RGB& first, const RGB& second);
// needs a header so other classes can see it instead of friending
}

#endif /* RGB_H_ */
