#ifndef _VECTOR2_H_
#define _VECTOR2_H_

struct Vector2
{
    float X;
    float Y;

    inline float Lenght();
    inline float LenghtSquared();
    inline void Normalize();
    inline Vector2 Normalized();
    inline Vector2 operator-(Vector2 rhs);
    inline Vector2 operator+(Vector2 rhs);
};

float Vector2::Lenght(){
    return sqrt((X*X) + (Y*Y));
}

float Vector2::LenghtSquared(){
    return (X*X) + (Y*Y);
}

void Vector2::Normalize(){
    float lenght = Lenght();
    X = X/lenght;
    Y = Y/lenght;
}

Vector2 Vector2::Normalized(){
    float lenght = Lenght();
    return Vector2 {X/lenght, Y/lenght};
}

Vector2 Vector2::operator-(Vector2 rhs){
    return Vector2{X - rhs.X, Y - rhs.Y};
}

Vector2 Vector2::operator+(Vector2 rhs){
    return Vector2{X + rhs.X, Y + rhs.Y};
}


#endif
