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
	hittable_list.h
	Header for Hittable_List class, which holds a vector of hittables, and functions to handle that.
*/

/*
	Some code taken and edited from https://raytracing.github.io/books/RayTracingInOneWeekend.html by Peter Shirley
*/

#ifndef HITTABLE_LIST_H
#define HITTABLE_LIST_H

#include "hittable.h"

#include <memory>
#include <vector>

using std::shared_ptr;
using std::make_shared;

class Hittable_List : public Hittable // holds a vector of hittables, and functions to handle that
{
public:
	Hittable_List() {}
	Hittable_List(shared_ptr<Hittable> object) { add(object); }

	void clear() { objects.clear(); }
	void add(shared_ptr<Hittable> object) { objects.push_back(object); }

	virtual bool hit(
		const Ray& r, float tmin, float tmax, hit_record& rec) const override;

public:
	std::vector<shared_ptr<Hittable>> objects;
};

bool Hittable_List::hit(const Ray& r, float t_min, float t_max, hit_record& rec) const {
	hit_record temp_rec;
	bool hit_anything = false;
	float closest_so_far = t_max;

	for (int i = 0; i < objects.size(); i++) // iterate through vector
	{
		if (objects[i]->hit(r, t_min, closest_so_far, temp_rec))  // checks hit function on each of its items
		{
			hit_anything = true;
			closest_so_far = temp_rec.t; // updates to that the reported collision is the one closest to the camera
			rec = temp_rec; // hit record output
		}
	}
	return hit_anything; // true if found any collision
}

#endif