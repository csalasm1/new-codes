#include <cmath>
#include <iostream>

using fptr = double(double);
double recurbisection (double xl, double xu, double eps, fptr func);
double fun(double x);

int main (void)
{
    const double eps = 1.0e-4;
    int nmax = 50;
    double xl =0.1, xu = 5, xr =0;
        std::cout << recurbisection(xl,xu,eps,fun) << "\n";

    return 0;
}

double recurbisection (double xl, double xu, double eps, fptr func)
{
    std::cout.precision(16);
    std::cout.setf(std::ios::scientific);

    double xr= 0;

    xr = 0.5*(xu + xl);
    if (std::fabs(fun(xr)) < eps){
        return xr;
    }
    else if(fun(xl)*fun(xr)<0){
    return recurbisection(xl,xr,eps,fun);

    }
    else{
        return recurbisection(xr,xu,eps,fun);

    }
    return xr;
}
  double fun(double x)
  {
    double y= pow(x,3.0)-27;
    return y;
  }
