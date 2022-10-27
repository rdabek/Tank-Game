#include "linearAlgebra.hpp"

#include <cmath>
#include <iostream>
#include <variant>

namespace linearAlgebra {

    auto calculateTetraederVolume(Scalar r, Angle a) -> Scalar {
        using namespace std;
        auto ang = a*M_PI/180.0;
        auto vecA = Vector3d{r*sin(ang), 0.0, -r*cos(ang)};
        auto vecB = Vector3d{r*cos(ang), r*sin(ang), 0.0};
        auto vecC = Vector3d{0.0, r*cos(ang), -r*sin(ang)};

        cout << "vec0->A: " << vecA << ", length: " << vecA.length() << "\n";
        cout << "vec0->B: " << vecB << ", length: " << vecB.length() << "\n";
        cout << "vec0->C: " << vecC << ", length: " << vecC.length() << "\n";

        return 1.0/6.0*(abs((vecA.x(vecB))*vecC));
    }

    auto calculateTetraederSurface(Scalar r, Angle a) -> Scalar {
        using namespace std;
        auto ang = a*M_PI/180.0;
        auto vecA = Vector3d{r*sin(ang), 0.0, -r*cos(ang)};
        auto vecB = Vector3d{r*cos(ang), r*sin(ang), 0.0};
        auto vecC = Vector3d{0.0, r*cos(ang), -r*sin(ang)};
        auto vecAB = vecB - vecA;
        auto vecAC = vecC - vecA;

        cout << "vec0->A: " << vecA << ", length: " << vecA.length() << "\n";
        cout << "vec0->B: " << vecB << ", length: " << vecB.length() << "\n";
        cout << "vec0->C: " << vecC << ", length: " << vecC.length() << "\n";
        cout << "vecA->B: " << vecAB << ", length: " << vecAB.length() << "\n";
        cout << "vecA->C: " << vecAC << ", length: " << vecAC.length() << "\n";

        return 1.0/2.0*vecA.x(vecB).length()
            + 1.0/2.0*vecA.x(vecC).length()
            + 1.0/2.0*vecB.x(vecC).length()
            + 1.0/2.0*vecAB.x(vecAC).length();
    }

}