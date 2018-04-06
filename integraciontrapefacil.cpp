#include <iostream>
#include <cmath>

using fptr = double(double);

double trapecio_reg(const double a,const double b,const int n, fptr func);
double trapecio_richardson(const double a,const double b,const int n, fptr func);
double simpson(const double a,const double b,const int n, fptr func);
double simpson_richardson(const double a,const double b,const int n, fptr func);
double funcio(double x);
double valormedio_newton(const double a,const double b, const int n, fptr funcio);
double newvalormedio (const double a,const double b, const int n, fptr funcio);

int main (void)
{
    const  int N=20;
    std::cout.precision(16);

    std::cout << "la integral por trapecio para n=20 es: " << trapecio_reg(0,M_PI,N, std::sin) << std::endl;
    std::cout << "la integral por trapecio para n=200 es: " << trapecio_reg(0,M_PI,10*N, std::sin) << std::endl;
    std::cout << "la integral por trapecio richard para n=200 es: " << trapecio_richardson(0,M_PI,10*N, std::sin) << std::endl;
    std::cout << "la integral por simpson para n=200 es: " << simpson(0,M_PI,10*N, std::sin) << std::endl;
    std::cout << atan(1) <<std::endl;
    std::cout << "la integral por simpson richard para n=200 es: " << simpson_richardson(0,1,10*N, std::atan) << std::endl;
    std::cout << "la integral por simpson richard para n=200 es: " << simpson_richardson(0,2,10*N,funcio) << std::endl;
    std::cout << "la integral por simpson richard para n=200 es: " << valormedio_newton(0,2,10*N,funcio) << std::endl;
    std::cout << "la integral por simpson richard para n=200 es: " << newvalormedio(0,2,10*N,funcio) << std::endl;
}
double funcio(double x)
{
   double ya= x*x;
    return ya;
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
double valormedio_newton(const double a,const double b, const int n, fptr funcio)
{
    double sum=0;
    double me=(funcio(a)+funcio(b))/2;
    double h=(b-a)/n;
    for(int ii=0;ii<=n/2;ii++){
        double x = a + (2*ii-1)*h;
        sum += funcio(x);
    }
    return sum*2*h;
}
double newvalormedio (const double a,const double b, const int n, fptr funcio)
{
  const double h =(b-a)/n;
    double sum=0;
    for(int ii=0; ii<=n; ii++){
     double x= a+ (ii*h);
     sum +=funcio(x);
    }
    return (sum*h)-((h*h*h/3.0)*1);
}
