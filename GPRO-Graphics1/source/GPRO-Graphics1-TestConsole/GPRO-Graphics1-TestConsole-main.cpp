/*
   Copyright 2020 Daniel S. Buckstein

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
	GPRO-Graphics1-TestConsole-main.c/.cpp
	Main entry point source file for a Windows console application.

	Modified by: ____________
	Modified because: ____________
*/


#include <stdio.h>
#include <stdlib.h>
#include <iostream>

#include "gpro/gpro-math/rtweekend.h"
#include "gpro/gpro-math/color.h"
#include "gpro/gpro-math/hittable_list.h"
#include "gpro/gpro-math/sphere.h"
#include "gpro/gpro-math/camera.h"


void testVector()
{
	// test array vector initializers and functions
	float3 av, bv, cv, dv;
	vec3default(av);								// -> a = (0, 0, 0)
	vec3init(bv, 1.0f, 2.0f, 3.0f);					// -> b = (1, 2, 3)
	vec3copy(dv, vec3init(cv, 4.0f, 5.0f, 6.0f));	// -> d = c = (4, 5, 6)
	vec3copy(av, dv);								// a = d			-> a = (4, 5, 6)
	vec3add(dv, bv);								// d += b			-> d = (4 + 1, 5 + 2, 6 + 3) = (5, 7, 9)
	vec3sum(dv, bv, bv);							// d = b + b		-> d = (1 + 1, 2 + 2, 3 + 3) = (2, 4, 6)
	vec3add(vec3sum(dv, cv, bv), av);				// d = c + b + a	-> d = (4 + 1 + 4, 5 + 2 + 5, 6 + 3 + 6) = (9, 12, 15)

#ifdef __cplusplus
	// test all constructors and operators
	vec3 a, b(1.0f, 2.0f, 3.0f), c(cv), d(c);		// default; init; copy array; copy
	a = d;											// assign						-> a = (4, 5, 6)
	d += b;											// add assign					-> d = (5, 7, 9)
	d = b + b;										// sum, init, assign			-> d = (2, 4, 6)
	d = c + b + a;									// sum, init, sum, init, assign	-> d = (9, 12, 15)
#endif	// __cplusplus
}

color ray_color(const ray& r, const hittable& world)
{
	hit_record rec; // output needed for getting normal
	if (world.hit(r, 0, infinity, rec)) // checks for collision
	{
		return (rec.normal + color(1, 1, 1)) * 0.5f; // returns color map based on normal
	}
	vec3 unit_direction = unit_vector(r.direction()); // makes it a unit vector to ease math
	float t = 0.5f * (unit_direction.y + 1.0f); // getting height
	return color(1.0f, 1.0f, 1.0f) * (1 - t) + color(0.5f, 0.7f, 1.0f) * t; //returns gradient
}

int main() {

	// Image

	const float aspect_ratio = 16.0f / 9.0f; // ratio for side of image
	const int image_width = 400; // image length
	const int image_height = static_cast<int>(image_width / aspect_ratio); // image height (got from width)s
	const int samples_per_pixel = 100;

	// World
	hittable_list world;
	world.add(make_shared<sphere>(point3(0, 0, -1), 0.5f));
	world.add(make_shared<sphere>(point3(0, -100.5, -1), 100.0f));

	// Camera
	camera cam;

	// Render

	std::cout << "P3\n" << image_width << ' ' << image_height << "\n255\n";

	for (int j = image_height - 1; j >= 0; --j) {
		std::cerr << "\rScanlines remaining: " << j << ' ' << std::flush;
		for (int i = 0; i < image_width; ++i) {
			color pixel_color(0, 0, 0);
			for (int s = 0; s < samples_per_pixel; ++s) // multiple rays to be averaged
			{ 
				float u = (i + random_float()) / (image_width - 1); // horizontal point
				float v = (j + random_float()) / (image_height - 1); // vertical point
				ray r = cam.get_ray(u, v); // ray that goes from viewport to space
				pixel_color += ray_color(r, world); // sets color for position (and checks for collision)
			}
			write_color(std::cout, pixel_color, samples_per_pixel); // writes color to file
		}
	}

	std::cerr << "\nDone.\n";
}
