#pragma once

#include "vec3.h"

inline double random_double() {
	return rand() / (RAND_MAX + 1.0);
}

inline vec3 random_in_unit_sphere() {
	vec3 p;
	do {
		p = 2.0 * vec3(random_double(), random_double(), random_double()) - vec3(1, 1, 1);
	} while (p.squared_length() >= 1.0);
	return p;
}

inline vec3 random_in_unit_disk() {
	vec3 p;
	do {
		p = 2.0 * vec3(random_double(), random_double(), 0) - vec3(1, 1, 0);
	} while (dot(p, p) >= 1.0);
	return p;
}

inline vec3 reflect(const vec3& v, const vec3& n) {
	return v - 2 * dot(v, n) * n;
}

