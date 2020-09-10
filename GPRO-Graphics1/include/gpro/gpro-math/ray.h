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
	ray.h
	Header for Ray class, which has both an origin position and directional vector members
*/

/*
	Some code taken and edited from https://raytracing.github.io/books/RayTracingInOneWeekend.html by Peter Shirley
*/

#ifndef RAY_H
#define RAY_H

#include "gproVector.h"

class Ray 
{
public:
	Ray() {} // default ctor
	Ray(const point3& origin, const vec3& direction) : orig(origin), dir(direction)	{} // ctor with given variables

	point3 origin() const { return orig; } // position of the ray
	vec3 direction() const { return dir; } // vector direction from the ray

	point3 at(float t) const // returns point from origin in direction at specific time
	{
		return orig + (dir * t);
	}

public:
	point3 orig;
	vec3 dir;
};

#endif