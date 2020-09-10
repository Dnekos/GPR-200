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
	camera.h
	Header for Camera class class, which is a comtrols.
*/

/*
	Some code taken and edited from https://raytracing.github.io/books/RayTracingInOneWeekend.html by Peter Shirley
*/

#ifndef CAMERA_H
#define CAMERA_H

#include "rtweekend.h"

class Camera 
{
public:
	Camera() // default ctor, with the settings needed
	{
		float aspect_ratio = 16.0f / 9.0f; //defaults for our camera and viewports
		float viewport_height = 2.0f;
		float viewport_width = aspect_ratio * viewport_height;
		float focal_length = 1.0f;

		origin = point3(0, 0, 0);
		horizontal = vec3(viewport_width, 0.0, 0.0);
		vertical = vec3(0.0, viewport_height, 0.0);
		lower_left_corner = origin - horizontal / 2 - vertical / 2 - vec3(0, 0, focal_length);
	}

	Ray get_ray(float u, float v) const // returns a ray shooting from the camera to given coordinates
	{
		return Ray(origin, lower_left_corner + horizontal * u + vertical * v - origin);
	}

private:
	point3 origin;
	point3 lower_left_corner;
	vec3 horizontal;
	vec3 vertical;
};
#endif