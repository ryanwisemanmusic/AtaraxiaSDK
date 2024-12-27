#ifndef MATHLIB_EUCLIDEAN_H
#define MATHLIB_EUCLIDEAN_H

typedef struct {
    float x, y, z;
} Vector3;

Vector3 vec3_add(Vector3 a, Vector3 b);

#endif
