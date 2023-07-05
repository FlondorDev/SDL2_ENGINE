#ifndef _VECTOR2_H_
#define _VECTOR2_H_
#include "math.h"

class Vector2
{
public:
    float X;
    float Y;
    inline Vector2(float x, float y);
    inline Vector2(int x, int y);
    inline float Lenght();
    inline float LenghtSquared();
    inline void Normalize();
    inline Vector2 Normalized();
    inline Vector2 operator-();
    inline bool operator==(Vector2 rhs);
    inline bool operator!=(Vector2 rhs);
    inline Vector2 operator-(Vector2 rhs);
    inline Vector2 operator+(Vector2 rhs);
    inline Vector2 operator*(Vector2 rhs);
    inline Vector2 operator*(float rhs);
    inline Vector2 operator/(Vector2 rhs);
    inline Vector2 operator/(float rhs);
};

Vector2::Vector2(int x, int y) : X{static_cast<float>(x)}, Y{static_cast<float>(y)}
{
}

Vector2::Vector2(float x, float y) : X{x}, Y{y}
{
}

float Vector2::Lenght()
{
    return sqrt((X * X) + (Y * Y));
}

float Vector2::LenghtSquared()
{
    return (X * X) + (Y * Y);
}

void Vector2::Normalize()
{
    float lenght = Lenght();
    X = X / lenght;
    Y = Y / lenght;
}

Vector2 Vector2::Normalized()
{
    float lenght = Lenght();
    return Vector2{X / lenght, Y / lenght};
}

bool Vector2::operator==(Vector2 rhs)
{
    return (X == rhs.X) && (Y == rhs.Y);
}

bool Vector2::operator!=(Vector2 rhs)
{
    return (X != rhs.X) || (Y != rhs.Y);
}

Vector2 Vector2::operator-()
{
    return Vector2{-X, -Y};
}

Vector2 Vector2::operator-(Vector2 rhs)
{
    return Vector2{X - rhs.X, Y - rhs.Y};
}

Vector2 Vector2::operator+(Vector2 rhs)
{
    return Vector2{X + rhs.X, Y + rhs.Y};
}

Vector2 Vector2::operator*(Vector2 rhs)
{
    return Vector2{X * rhs.X, Y * rhs.Y};
}

Vector2 Vector2::operator*(float rhs)
{
    return Vector2{X * rhs, Y * rhs};
}

Vector2 Vector2::operator/(Vector2 rhs)
{
    return Vector2{X / rhs.X, Y / rhs.Y};
}

Vector2 Vector2::operator/(float rhs)
{
    return Vector2{X / rhs, Y / rhs};
}

#endif
