#include "utils/Vector.hpp"
#include "utils/Tetraeder.hpp"

#include <iostream>
#include <cmath>

using namespace linearAlgebra;
using namespace tetraeder;

int main() {
    auto r = Scalar(10);
    auto a = Angle(45);

    auto ang = a*M_PI/180.0;
    auto vecA = Vector3d{r*sin(ang), 0.0, -r*cos(ang)};

    std::cout << "vec0->A: " << vecA << ", length: " << vecA.length() << "\n\n";

    std::cout << "Expected value: " << std::pow(vecA.length(), 3)*std::sqrt(2.0)/12.0
        << ", Calculated value:\n" << calculateTetraederVolume(r, a) << "\n\n";
    
    std::cout << "Expected value: " << std::pow(vecA.length(), 2)*std::sqrt(3.0)
        << ", Calculated value:\n" << calculateTetraederSurface(r, a) << "\n";

    auto vec0 = Vector<Scalar, 3>{1.0, 1.0, 1.5};
    auto vec1 = Vector<Scalar, 3>{1.0, 2.0, 1.5};
    auto vec2 = Vector<Scalar, 3>{2.0, 1.0, 2.0};

    std::cout << "\nVectors 1 and 2:" << std::endl;
    std::cout << vec1 << std::endl;
    std::cout << vec2 << std::endl;

    std::cout << "\nAddition and Subtraction" << std::endl;
    std::cout << vec1+vec2 << std::endl;
    std::cout << vec1-vec2 << std::endl;

    std::cout << "\nDotProduct:" << std::endl;
    std::cout << vec1*vec2 << std::endl;

    std::cout << "\nMultiplication by Scalar" << std::endl;
    std::cout << vec0*5.0 << std::endl;

    const auto vecX = Vector<Scalar, 3>{r*sin(ang), 0.0, -r*cos(ang)};
    std::cout << "\nVector: " << vecX << " length:" << std::endl;
    std::cout << vecX.length() << std::endl;

    return 0;
}