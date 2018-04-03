#include <iostream>
#include <cmath>

using fptr = double(double);

double trapecio_reg(const double a,const double b,const int n, fptr func);
double trapecio_richardson(const double a,const double b,const int n, fptr func);
double simpson(const double a,const double b,const int n, fptr func);
double simpson_richardson(const double a,const double b,const int n, fptr func);

int main (void)
{
    const  int N=20;
    std::cout.precision(16);

    std::cout << "la integral por trapecio para n=20 es: " << trapecio_reg(0,M_PI,N, std::sin) << std::endl;
    std::cout << "la integral por trapecio para n=200 es: " << trapecio_reg(0,M_PI,10*N, std::sin) << std::endl;
    std::cout << "la integral por trapecio richard para n=200 es: " << trapecio_richardson(0,M_PI,10*N, std::sin) << std::endl;
    std::cout << "la integral por simpson para n=200 es: " << simpson(0,M_PI,10*N, std::sin) << std::endl;
    std::cout << "la integral por simpson richard para n=200 es: " << simpson_richardson(0,M_PI,10*N, std::sin) << std::endl;

}
double trapecio_reg(const double a,const double b,const int n, fptr func)
{
    const double h = (b-a)/n;
    double sum = 0.5*(func(a)+func(b));
    for (int ii=1; ii<= n-1;++ii){
        double x = ii*h;
        sum += func(x);
    }
        return h*sum;
}
double trapecio_richardson(const double a,const double b, const int n,fptr func)
{
    return (4*trapecio_reg(a,b,2*n,func)- trapecio_reg(a, b, n, func))/3;
}
double simpson(const double a,const double b,const int n, fptr func)
{
    double sum = 0, result = func(a)+func(b);
    double x;
    const double h = (b-a)/n;

    sum = 0;
    for(int ii = 1; ii<= n/2 -1; ++ii){
        x = a + 2*ii*h;
        sum += func(x);
    }
    result += 2*sum;

    sum = 0;
    for(int ii=1; ii <= n/2; ++ii){
        x = a + (2*ii-1)*h;
        sum += func(x);
    }
    result += 4*sum;

    return result*h/3;
}
double simpson_richardson(const double a,const double b, const int n,fptr func)
{
    return (4*simpson(a,b,2*n,func)- simpson(a, b, n, func))/3;
}

