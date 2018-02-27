//============================================================================
// Name        : fractalCreator1.cpp
// Author      : 
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================

#include <iostream>
#include"RGB.h"
#include "FractalCreator.h"
#include"Zoom.h"

using namespace std;
using namespace caveofprogramming;

int main() {

//	RGB rgb1(4, 5, 6);
//	RGB rgb2(1, 2, 3);
//	RGB rgb3 = rgb1 - rgb2;
//	cout << rgb3.r << ", " << rgb3.g << ", " << rgb3.b << endl;


	FractalCreator fractalCreator(800, 600);

	fractalCreator.addRange(0.0, RGB(0, 0, 255));
	fractalCreator.addRange(0.3, RGB(255, 0, 0));
	fractalCreator.addRange(0.5, RGB(255,0, 0));
	fractalCreator.addRange(1.0, RGB(255, 255, 255));

//	fractalCreator.addRange(0.0, RGB(0, 0, 200));
//	fractalCreator.addRange(0.1, RGB(125, 0, 125));
//	fractalCreator.addRange(0.25, RGB(255, 0, 0));
//	fractalCreator.addRange(0.5, RGB(0, 255, 125));
//	fractalCreator.addRange(0.6, RGB(255, 0, 125));
//	fractalCreator.addRange(0.75, RGB(255,125, 0));
//	fractalCreator.addRange(1.0, RGB(255, 255, 255));

//	cout << "Range: " << fractalCreator.getRange(999) << endl;

	fractalCreator.addZoom(Zoom(295, 202, 0.1));
	fractalCreator.addZoom(Zoom(312, 304, 0.1));
	fractalCreator.run("test.bmp");

	cout << "Finished" << endl;
	return 0;
}
