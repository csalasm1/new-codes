#include <cstdlib>
#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>

void rk4(std::vector<double> & data, double t, double h);
double f(int idx, double t, const std::vector<double> & y);

const double G=9.81;// m/s2
const double M=90.0;//Kg
const double Cd=0.225;//Kg/m
const double H = 0.001;
const double eps = 0.0001;
const int steps =1000000;

int main(void)
{
    std::vector<double> y = {1000.0,0.0};//[y,v0]

    for (int ii = 0; ii < steps; ++ii) {
    double t = 0.0 + ii*H;
    std::cout << t << "  " << y[0] << "   " << y[1] << "\n";
    rk4(y, t, H);
    if(y[0]<eps) break;
  }

  return 0;
}

void rk4(std::vector<double> & data, double t, double h)
{
  std::vector<double> k1, k2, k3, k4, aux;
  k1.resize(data.size());
  k2.resize(data.size());
  k3.resize(data.size());
  k4.resize(data.size());
  aux.resize(data.size());

  // k1
  for(int ii = 0; ii < data.size(); ++ii) {
    k1[ii] = h*f(ii, t, data);
  }
  // k2 aux
  for(int ii = 0; ii < data.size(); ++ii) {
    aux[ii] = data[ii] + k1[ii]/2;
  }
  //k2
  for(int ii = 0; ii < data.size(); ++ii) {
    k2[ii] = h*f(ii, t + h/2, aux);
  }
  // k3 aux
  for(int ii = 0; ii < data.size(); ++ii) {
    aux[ii] = data[ii] + k2[ii]/2;
  }
  //k3
  for(int ii = 0; ii < data.size(); ++ii) {
    k3[ii] = h*f(ii, t + h/2, aux);
  }
  // k4 aux
  for(int ii = 0; ii < data.size(); ++ii) {
    aux[ii] = data[ii] + k3[ii];
  }
  //k4
  for(int ii = 0; ii < data.size(); ++ii) {
    k4[ii] = h*f(ii, t + h, aux);
  }

  // write new data
  for(int ii = 0; ii < data.size(); ++ii) {
    data[ii] = data[ii] + (k1[ii] + 2*k2[ii] + 2*k3[ii] + k4[ii])/6.0;
  }
}

double f(int idx, double t, const std::vector<double> & y)
{
  if (0 == idx) {
    return y[1];
  }
  else if (1 == idx) {
    return -G+(Cd/M)*y[1]*y[1];
  }
  else {
    std::cerr << "BAD index : " << idx << std::endl;
    return 0;
  }
}
