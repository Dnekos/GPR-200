#ifndef HITTABLE_H
#define HITTABLE_H

#include "ray.h"

struct hit_record {
	point3 p; // the point
	vec3 normal; // normal vector
	float t; // time
	bool front_face; // wether it hit the inside or outside of the hittable (true=outside)

	//determines which side the 
	inline void set_face_normal(const ray& r, const vec3& outward_normal) {
		front_face = dot(r.direction(), outward_normal) < 0;
		normal = front_face ? outward_normal : outward_normal * -1.0f;
	}
};

class hittable {
public:
	virtual bool hit(const ray& r, float t_min, float t_max, hit_record& rec) const = 0;
};

#endif