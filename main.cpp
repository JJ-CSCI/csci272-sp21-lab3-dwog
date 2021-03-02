//------------------------------
//  DO NOT MODIFY NEXT LINE
//------------------------------
#include "catch.hpp"
//------------------------------

// Put the assignment code here
#include <array>



class Quaternion
{

public:
    std::array<double, 4> coefficients;

    Quaternion() : coefficients({0.0, 0.0, 0.0, 0.0}) {};
    Quaternion(double, double, double, double);
    bool operator==(const Quaternion&) const;
    Quaternion operator+(const Quaternion&) const;
    Quaternion operator-(const Quaternion&) const;
    Quaternion operator*(const double) const;

};





Quaternion::Quaternion(double a, double b, double c, double d)
{
    coefficients = {a, b, c, d};
}

bool Quaternion::operator==(const Quaternion& obj) const
{
    return coefficients == obj.coefficients;
}

Quaternion Quaternion::operator+(const Quaternion& obj) const
{
    Quaternion result;
    int index{ 0 };

    for (const auto& i : coefficients)
    {
        result.coefficients[index] = result.coefficients[index] + (i + obj.coefficients[index]);
        index++;
    }

    return result;
}

Quaternion Quaternion::operator-(const Quaternion& obj) const
{
    Quaternion result;
    int index{0};

    for (const auto& i : coefficients)
    {
        result.coefficients[index] = result.coefficients[index] + (i - obj.coefficients[index]);
        index++;
    }

    return result;
}


Quaternion Quaternion::operator*(const double number) const
{
    Quaternion result;
    int index{ 0 };

    for (const auto& i : coefficients)
    {
        result.coefficients[index] = result.coefficients[index] + (i * number);
        index++;
    }

    return result;
}


//------------------------------
//   DO NOT MODIFY TEST CASES
//------------------------------
TEST_CASE( "Assignment" ) {
    SECTION( "q1" ) {
        Quaternion q{1.0, 2.0, 3.0, 4.0};
        Quaternion p{1.0, 2.0, 3.0, 4.0};
        REQUIRE( q == p );
    }
    SECTION( "q2" ) {
        Quaternion q{1.0, 2.0, 3.0, 4.0};
        Quaternion p{1.0, 2.0, 3.0, 4.0};
        Quaternion r{2.0, 4.0, 6.0, 8.0};
        REQUIRE( (q + p) == r );
    }
    SECTION( "q3" ) {
        Quaternion q{1.0, 2.0, 3.0, 4.0};
        Quaternion p{1.0, 2.0, 3.0, 4.0};
        Quaternion r{0.0, 0.0, 0.0, 0.0};
        REQUIRE( (q - p) == r );
    }
    SECTION( "q3" ) {
        Quaternion q{1.0, 2.0, 3.0, 4.0};
        Quaternion r{2.0, 4.0, 6.0, 8.0};
        REQUIRE( (q * 2.0) == r );
    }
}
//------------------------------
