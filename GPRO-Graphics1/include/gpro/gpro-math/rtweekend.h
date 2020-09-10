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
	rtweekend.h
	various miscellanious functions and constants, including math stuff and randoms
*/

/*
	Some code taken and edited from https://raytracing.github.io/books/RayTracingInOneWeekend.html by Peter Shirley
*/

#ifndef RTWEEKEND_H
#define RTWEEKEND_H

#include <cmath>
#include <cstdlib>
#include <limits>
#include <memory>

// Usings

using std::shared_ptr;
using std::make_shared;
using std::sqrt;

// Constants

const float infinity = std::numeric_limits<float>::infinity();
const float pi = 3.1415926535897932385f;

// Utility Functions

inline float degrees_to_radians(float degrees) 
{
	return degrees * pi / 180.0f;
}

inline float random_float() 
{
	// Returns a random real in [0,1).
	return rand() / (RAND_MAX + 1.0f);
}

inline float random_float(float min, float max) 
{
	// Returns a random real in [min,max).
	return min + (max - min) * random_float();
}

inline double clamp(float x, float min, float max) 
{
	//clamps value between min and max
	if (x < min) return min;
	if (x > max) return max;
	return x;
}

// Common Headers

#include "ray.h"
#include "gproVector.h"

#endif