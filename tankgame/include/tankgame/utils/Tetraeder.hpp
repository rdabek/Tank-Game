#pragma once

#include "Vector.hpp"

using namespace linearAlgebra;

namespace tetraeder {

    auto calculateTetraederVolume(Scalar r, Angle a) -> Scalar;

    auto calculateTetraederSurface(Scalar r, Angle a) -> Scalar;
}