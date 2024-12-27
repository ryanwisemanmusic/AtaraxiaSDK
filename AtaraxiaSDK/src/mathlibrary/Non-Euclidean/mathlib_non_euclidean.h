#ifndef MATHLIB_NON_EUCLIDEAN_H
#define MATHLIB_NON_EUCLIDEAN_H

typedef struct {
    float theta, phi;
} SphereCoords;

SphereCoords spherical_add(SphereCoords a, SphereCoords b);

#endif