#include "utils/linearAlgebra.hpp"

#include <iostream>
#include <cmath>

using namespace linearAlgebra;

int main() {
    auto r = Scalar(10);
    auto a = Angle(45);

    auto ang = a*M_PI/180.0;
    auto vecA = Vector3d{Point3d{r*sin(ang), 0.0, -r*cos(ang)}};

    std::cout << "vec0->A: " << vecA << ", length: " << vecA.length() << "\n\n";

    std::cout << "Expected value: " << std::pow(vecA.length(), 3)*std::sqrt(2.0)/12.0
        << ", Calculated value:\n" << calculateTetraederVolume(r, a) << "\n\n";
    
    std::cout << "Expected value: " << std::pow(vecA.length(), 2)*std::sqrt(3.0)
        << ", Calculated value:\n" << calculateTetraederSurface(r, a) << "\n";

    auto vec1 = Vector<Scalar, 2>{1.0, 0.0, 2.0};
    auto vec2 = Vector<Scalar, 2>{0.0, 1.0, -1.0};
    std::cout << "\nVectors to add:" << std::endl;
    std::cout << vec1.toString() << std::endl;
    std::cout << vec2.toString() << std::endl;

    std::cout << (vec1+vec2).toString() << std::endl;
    std::cout << (vec1-vec2).toString() << std::endl;

    return 0;
}