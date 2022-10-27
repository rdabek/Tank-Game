#pragma once

#include <cmath>
#include <concepts>
#include <functional>
#include <iostream>
#include <string>
#include <type_traits>
#include <vector>

namespace linearAlgebra {

    using Point3d = std::tuple<double, double, double>;

    using Scalar = double;

    using Angle = double;


    // Combine concepts
    template<typename T>
    concept ScalarType
        = std::floating_point<T>
        || std::integral<T>
        && requires(T a, T b) {
        requires a+b;
        requires a*b;
    };

    template<ScalarType T, size_t Dim>
    class Vector {
        public:
            template <ScalarType ...Xn>
            requires(sizeof...(Xn) == Dim)      // Only activate if number of elements in list == Dim of the Vector
            Vector(Xn ... xn) {
                vec = std::initializer_list<T>{xn...};
            }

            auto operator+(Vector other) -> Vector<T, Dim> {        // Vector addition
                std::vector<T> ret;
                std::transform(vec.begin(), vec.end(),
                    other.vec.begin(),
                    std::back_inserter(ret),
                    std::plus<T>());
                return ret;
            };

            auto operator-(Vector other) -> Vector<T, Dim> {        // Vector subtraction
                std::vector<T> ret;
                std::transform(vec.begin(), vec.end(),
                    other.vec.begin(),
                    std::back_inserter(ret),
                    std::minus<T>());
                return ret;
            };

            auto operator*(Scalar s) -> Vector<T, Dim> {            // Multiplication with Scalar on Vector
                std::vector<T> ret;
                std::transform(vec.begin(), vec.end(),
                    std::back_inserter(ret),
                    [&s](Scalar elem){ return s*elem; });
                return ret;
            }

            auto operator*(Vector other) -> Scalar {                // Dotproduct
                Scalar ret = 0.0;
                for(size_t i=0; i<vec.size(); i++)
                    ret += vec[i]*other.vec[i];
                return ret;
            }

            auto length() -> Scalar {
                Scalar ret = 0.0;
                for(size_t i=0; i<vec.size(); i++)
                    ret += vec[i]*vec[i];
                return std::sqrt(ret);
            }

            auto toString() -> std::string {                        // Convert to string to output
                std::string str = "[ ";
                for(size_t i=0; i<vec.size()-1; i++) {
                    str += std::to_string(vec[i]) + ", ";
                }
                str += std::to_string(vec[vec.size()-1]) + " ]";
                return str;
            }

            auto operator<<(std::ostream& ostr) -> std::ostream&;   // No idea yet

        private:
            Vector(std::vector<T> v) {
                vec = v;
            }

            std::vector<T> vec;
    };

    class Vector3d {
        public:
            Vector3d() {
                p = Point3d{0.0, 0.0, 0.0};
            }

            Vector3d(Point3d p) {
                this->p = p;
            }

            auto toString() -> std::string;

            auto operator+(Vector3d other) -> Vector3d;     // Vector addition
            
            auto operator-(Vector3d other) -> Vector3d;     // Vector subtraction

            auto operator*(Scalar scalar) -> Vector3d;      // Scalar multiplication
            
            auto operator*(Vector3d other) -> Scalar;       // Dot Product

            auto x(Vector3d other) -> Vector3d;             // Crossproduct

            auto length() -> Scalar;                        // Vector Length

        private:
            Point3d p;
    };

    inline auto operator<<(std::ostream& os, Vector3d v) -> std::ostream&
    {
        os << v.toString();
        return os;
    }
    
    auto calculateTetraederVolume(Scalar r, Angle a) -> Scalar;

    auto calculateTetraederSurface(Scalar r, Angle a) -> Scalar;

}