#include <cstdlib>
#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>

struct Quaternion{
    double a=0.0;
    double b=0.0;
    double c=0.0;
    double d=0.0;
    void print(void){
    std::cout << a << " , " << b << " , " << c << " , " << d <<std::endl;
    }
    Quaternion operator+(const Quaternion & q2);
    Quaternion operator-(const Quaternion & q2);
    Quaternion operator*(const Quaternion & q2);
};

Quaternion Quaternion::operator+(const Quaternion & q2) //q1 ∗ q2 = (a1a2 − b1b2 − c1c2 − d1d2, a1b2 + b1a2 + c1d2 − d1c2, a1c2 − b1d2 + c1a2 + d1b2, a1d2 + b1c2 − c1b2 + d1a2)
{
    Quaternion tmp;
    tmp.a= a + q2.a;
    tmp.b= b + q2.b;
    tmp.c= c + q2.c;
    tmp.d= d + q2.d;

    return tmp;
}
Quaternion Quaternion::operator-(const Quaternion & q2) //q1 ∗ q2 = (a1a2 − b1b2 − c1c2 − d1d2, a1b2 + b1a2 + c1d2 − d1c2, a1c2 − b1d2 + c1a2 + d1b2, a1d2 + b1c2 − c1b2 + d1a2)
{
    Quaternion tmp;
    tmp.a= a - q2.a;
    tmp.b= b - q2.b;
    tmp.c= c - q2.c;
    tmp.d= d - q2.d;

    return tmp;
}

Quaternion Quaternion::operator*(const Quaternion & q2) //q1 ∗ q2 = (, a1c2 − b1d2 + c1a2 + d1b2, a1d2 + b1c2 − c1b2 + d1a2)
{
    Quaternion tmp;
    tmp.a= a*q2.a - b*q2.b - c*q2.c - d*q2.d;
    tmp.b= a*q2.b + b*q2.a + c*q2.d - d*q2.c;
    tmp.c= a*q2.c - b*q2.d + c*q2.a + d*q2.b;
    tmp.d= a*q2.d + b*q2.c - c*q2.b + d*q2.a;

    return tmp;
}
//void print(const Quaternion & c);

// q1 = (1, 2, 3, 0) y q2 = (0, 2, −3.4, −1).


int main(void)
{
Quaternion q1, q2;
q1.a = 1; q1.b = 2; q1.c = 3; q1.d = 0;
q2.a = 0; q2.b = 2; q2.c = -3.4; q2.d = -1;

Quaternion q3;
q3 = q1 + q2;
q3.print();
q3 = q1 - q2;
q3.print();
q3 = q1 * q2;
q3.print();
return 0;
}


void print(const Quaternion & c)
{
    std::cout << c.a << " " << c.b << " " << c.c << " " << c.d <<std::endl;
}
