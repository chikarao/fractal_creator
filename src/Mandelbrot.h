/*
 * Mandelbrot.h
 *
 *  Created on: Feb 10, 2018
 *      Author: okadachikara
 */

#ifndef MANDELBROT_H_
#define MANDELBROT_H_

namespace caveofprogramming {

class Mandelbrot {
public:
	static const int MAX_ITERATIONS = 1000;// more iterations done for pixel get better image

public:
	Mandelbrot();
	virtual ~Mandelbrot();

	static int getIterations(double x, double y);
// static since don't need instance variables
};

}

#endif /* MANDELBROT_H_ */
