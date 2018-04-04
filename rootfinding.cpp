#include <iostream>
#include <cmath>

using fptr = double(double);
double f(double x);
double bisection(double xl, double xu, double eps, int nmax, fptr func);
double regulafalsi(double xl, double xu, double eps, int nmax, fptr func);

int main (void)
{
    const double eps = 1.0e-8;
    int nmax = 50;
    double xl =12, xu = 18, xr =0;
    xr = bisection(xl,xu,eps,nmax,f);
    xr = regulafalsi(xl,xu,eps,nmax,f);
    return 0;
}

  double f(double x)
  {
      return (9.81*68.1/x)*(1-std::exp(-10*x/68.1)) - 40;
  }
double bisection(double xl, double xu, double eps, int nmax, fptr func)
{
   std::cout.precision(16);
   std::cout.setf(std::ios::scientific);
   double xr= 0;

    for(int ii = 0; ii <= nmax; ++ii){
        xr = 0.5*(xu + xl);
        if (std::fabs(f(xr)) < eps) break;
        if (f(xr)*f(xl) < 0)
            xu = xr;
        else xl = xr;
    }
    std::cout << xr << std::endl;

    return xr;
}
double regulafalsi(double xl, double xu, double eps, int nmax, fptr func)
{
    std::cout.precision(16);
    std::cout.setf(std::ios::scientific);
    double xr=0;
    for(int ii=0; ii<=nmax; ii++){
    xr = xu - (f(xu)*(xl-xu))/(f(xl) - f(xu)) ;
        if (std::fabs(f(xr)) < eps) break;
        if (f(xr)*f(xl) < 0)
            xu = xr;
        else xl = xr;
    }
    std::cout << xr << std::endl;

    return xr;
}
