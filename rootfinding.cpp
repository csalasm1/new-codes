#include <iostream>
#include <cmath>

using fptr = double(double);
double f(double x);
double bisection(double xl, double xu, double eps, int nmax, fptr func);
double regulafalsi(double xl, double xu, double eps, int nmax, fptr func);
double newton_meth(double x1, double eps, int nmax, fptr func);
double newf(double x);
double dnewf(double x);

int main (void)
{
    const double eps = 1.0e-4;
    int nmax = 50;
    double xl =0.1, xu = 5, xr =0;
    xr = bisection(xl,xu,eps,nmax,f);
    xr = regulafalsi(xl,xu,eps,nmax,f);
    xr = bisection(xl,xu,eps,nmax,newf);
    xr = regulafalsi(xl,xu,eps,nmax,newf);
    xr = regulafalsi(xl,xu,eps,nmax,newf);
    std::cout << newton_meth(0,0.00000001,100,newf) << std::endl;
    std::cout << pow(2,3.0) << std::endl;

    return 0;
}

  double f(double x)
  {
      return (9.81*68.1/x)*(1-std::exp(-10*x/68.1)) - 40;
  }
  double newf(double x)
  {
    double y= pow(x,3.0)-27;
    return y;
  }
    double dnewf(double x)
    {
        double y= pow(3*x,2.0);
        return y;
    }
double bisection(double xl, double xu, double eps, int nmax, fptr func)
{
   std::cout.precision(16);
   std::cout.setf(std::ios::scientific);
   double xr= 0;

    for(int ii = 0; ii <= nmax; ++ii){
        xr = 0.5*(xu + xl);
        if (std::fabs(newf(xr)) < eps) break;
        if (newf(xr)*newf(xl) < 0)
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
double newton_meth(double x1, double eps, int nmax, fptr func)
{
    std::cout.precision(16);
    std::cout.setf(std::ios::scientific);
    double x0,h;
    for(int ii=1;ii<=nmax; ii++){
        h= newf(x0)/dnewf(x0);
        x1= x0-h;
        if(fabs(h)<0){
            std::cout << ii << "    " << x1 << std::endl;
            return 0;
        }
        else {
            std::cout << ii << "    " << x1 << std::endl;
            x0=x1;
        }
    }
    return x1;
}
