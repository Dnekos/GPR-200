#ifndef COLOR_H
#define COLOR_H

#include "gpro/gpro-math/gproVector.h"

#include <iostream>

void write_color(std::ostream& out, color pixel_color) {
	// Write the translated [0,255] value of each color component.
	out << static_cast<int>(pixel_color.x * 255.999f) << ' '
		<< static_cast<int>(pixel_color.y * 255.999f) << ' '
		<< static_cast<int>(pixel_color.z * 255.999f) << '\n';
}

#endif