/*
 * Mandelbrot.cpp
 *
 *  Created on: Feb 10, 2018
 *      Author: okadachikara
 */
#include <complex.h>
#include "Mandelbrot.h"

using namespace std;

namespace caveofprogramming {

Mandelbrot::Mandelbrot() {
	// TODO Auto-generated constructor stub

}

Mandelbrot::~Mandelbrot() {
	// TODO Auto-generated destructor stub
}

int Mandelbrot::getIterations(double x, double y){
	//implement mandelbrot
	complex<double> z = 0; // z is number made of 2 numbers
	complex<double> c(x, y);
	// see how many interations needed before c shoots to infinity

	int iterations = 0;

	while(iterations < MAX_ITERATIONS) {
		z = z*z + c;
		//magnitude of complex number, plot 2 numbers, is length of the line from origin to point
	if(abs(z) > 2) { //abs gets magnitude of complex number
		//if magnitude greater than 2, not part of the mandelbrot set break loop
		break;
	}
	iterations++;
	}

return iterations;
}

} //namespace caveofprogramming
