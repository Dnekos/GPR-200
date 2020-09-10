/*
	Copyright 2020 Demetrius Nekos

	Licensed under the Apache License, Version 2.0 (the "License");
	you may not use this file except in compliance with the License.
	You may obtain a copy of the License at

		http://www.apache.org/licenses/LICENSE-2.0

	Unless required by applicable law or agreed to in writing, software
	distributed under the License is distributed on an "AS IS" BASIS,
	WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
	See the License for the specific language governing permissions and
	limitations under the License.
*/

/*
	color.h
	holds function that writes the color to output
*/

/*
	Some code taken and edited from https://raytracing.github.io/books/RayTracingInOneWeekend.html by Peter Shirley
*/

#ifndef COLOR_H
#define COLOR_H

#include "gproVector.h"

#include <iostream>

void write_color(std::ostream& out, color pixel_color, int samples_per_pixel) {
	// Getting the values from the color class
	float r = pixel_color.x;
	float g = pixel_color.y;
	float b = pixel_color.z;

	// Divide the color by the number of samples.
	float scale = 1.0f / samples_per_pixel;
	r *= scale;
	g *= scale;
	b *= scale;

	// Write the translated [0,255] value of each color component.
	out << static_cast<int>(256 * clamp(r, 0.0f, 0.999f)) << ' '
		<< static_cast<int>(256 * clamp(g, 0.0f, 0.999f)) << ' '
		<< static_cast<int>(256 * clamp(b, 0.0f, 0.999f)) << '\n';
}

#endif