#include "linearAlgebra.hpp"

#include <cmath>
#include <iostream>
#include <variant>

namespace linearAlgebra {
 
    auto Vector3d::toString() -> std::string {
        using namespace std;
        auto ret = std::string();
        ret += "[ "
            + to_string(std::get<0>(p)) + ", "
            + to_string(std::get<1>(p)) + ", "
            + to_string(std::get<2>(p))
            + " ]";
        return ret;
    }

    auto Vector3d::operator+(Vector3d other) -> Vector3d {
        double px, py, pz,
            ox, oy, oz;
        std::tie(px, py, pz) = p;
        std::tie(ox, oy, oz) = other.p;
        return Vector3d(Point3d{
            px+ox,
            py+oy,
            pz+oz
        });
    }

    auto Vector3d::operator-(Vector3d other) -> Vector3d {
        double px, py, pz,
            ox, oy, oz;
        std::tie(px, py, pz) = p;
        std::tie(ox, oy, oz) = other.p;
        return Vector3d(Point3d{
            px-ox,
            py-oy,
            pz-oz
        });
    }

    auto Vector3d::operator*(Scalar s) -> Vector3d {
        double px, py, pz;
        std::tie(px, py, pz) = p;
        return Vector3d(Point3d{
            s*px,
            s*py,
            s*pz
        });
    }

    auto Vector3d::operator*(Vector3d other) -> Scalar {
        double px, py, pz,
            ox, oy, oz;
        std::tie(px, py, pz) = p;
        std::tie(ox, oy, oz) = other.p;
        return px*ox
            + py*oy
            + pz*oz;
    }

    auto Vector3d::x(Vector3d other) -> Vector3d {
        double px, py, pz,
            ox, oy, oz;
        std::tie(px, py, pz) = p;
        std::tie(ox, oy, oz) = other.p;
        return Vector3d(Point3d{
            py*oz - pz*oy,
            pz*ox - px*oz,
            px*oy - py*ox
        });
    }

    auto Vector3d::length() -> Scalar {
        double px, py, pz;
        std::tie(px, py, pz) = p;
        return std::sqrt(
            px*px
            + py*py
            + pz*pz
        );
    }

    auto calculateTetraederVolume(Scalar r, Angle a) -> Scalar {
        using namespace std;
        auto ang = a*M_PI/180.0;
        auto vecA = Vector3d{Point3d{r*sin(ang), 0.0, -r*cos(ang)}};
        auto vecB = Vector3d{Point3d{r*cos(ang), r*sin(ang), 0.0}};
        auto vecC = Vector3d{Point3d{0.0, r*cos(ang), -r*sin(ang)}};

        cout << "vec0->A: " << vecA << ", length: " << vecA.length() << "\n";
        cout << "vec0->B: " << vecB << ", length: " << vecB.length() << "\n";
        cout << "vec0->C: " << vecC << ", length: " << vecC.length() << "\n";

        return 1.0/6.0*(abs((vecA.x(vecB))*vecC));
    }

    auto calculateTetraederSurface(Scalar r, Angle a) -> Scalar {
        using namespace std;
        auto ang = a*M_PI/180.0;
        auto vecA = Vector3d{Point3d{r*sin(ang), 0.0, -r*cos(ang)}};
        auto vecB = Vector3d{Point3d{r*cos(ang), r*sin(ang), 0.0}};
        auto vecC = Vector3d{Point3d{0.0, r*cos(ang), -r*sin(ang)}};
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