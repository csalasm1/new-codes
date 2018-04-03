#include <iostream>
#include <cmath>

double fsen(double x);
double fderforward (double x, double h);
double fdercentral (double x, double h);

int main (void)
{
    double x= M_PI/3;
    double h= 0.1;
    double a= 1;

    std::cout << fsen(x) << std::endl;
    std::cout << cos(x) << std::endl;
    std::cout << fderforward(x,h) << std::endl;
    std::cout << asin(a) << std::endl;

    return 0;
}
double fsen(double x)
{
    double result;
    result= std::sin(x);

    return result;

}
double fderforward(double x, double h)
{
    double result;
    result = (fsen(x+h)-fsen(x))/h;

    return result;
}
double fdercentral (double x, double h)
{
    double result;
    result = (fsen(x+h/2)-fsen(x-h/2))/h;

    return result;
}
