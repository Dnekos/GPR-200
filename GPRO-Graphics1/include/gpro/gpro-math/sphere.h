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
	sphere.h
	Header for Sphere class, which is a subclass of Hittable.
*/

/*
	Some code taken and edited from https://raytracing.github.io/books/RayTracingInOneWeekend.html by Peter Shirley
*/

#ifndef SPHERE_H
#define SPHERE_H

#include "hittable.h"
#include "gproVector.h"

class Sphere : public Hittable 
{
public:
	Sphere() {} // default ctor
	Sphere(point3 cen, float r) : center(cen), radius(r) {}; // ctor with values

	virtual bool hit(const Ray& r, float tmin, float tmax, hit_record& rec) const override;

public:
	point3 center;
	float radius;
};

bool Sphere::hit(const Ray& r, float t_min, float t_max, hit_record& rec) const 
{
	vec3 oc = r.origin() - center;
	float a = r.direction().length_squared();
	float half_b = dot(oc, r.direction());
	float c = oc.length_squared() - radius * radius;
	float discriminant = half_b * half_b - a * c;

	if (discriminant > 0) // if ray hits sphere
	{
		float root = sqrt(discriminant);

		float temp = (-half_b - root) / a;
		if (temp < t_max && temp > t_min) 
		{
			rec.t = temp;
			rec.p = r.at(rec.t);
			vec3 outward_normal = (rec.p - center) / radius; // surface side detection for normals
			rec.set_face_normal(r, outward_normal);
			return true;
		}

		temp = (-half_b + root) / a;
		if (temp < t_max && temp > t_min) 
		{
			rec.t = temp;
			rec.p = r.at(rec.t);
			vec3 outward_normal = (rec.p - center) / radius; // surface side detection for normals
			rec.set_face_normal(r, outward_normal);
			return true;
		}
	}

	return false;
}


#endif