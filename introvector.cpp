#include <iostream>
#include <cmath>
#include <vector>

double vec(int N);
double promed(int N);
double prom( const std::vector <double> &a);
void initialize(std::vector<double> & a);
void print(const std::vector<double> & a);

double vec(int N)
{
    std::vector <double> array(N);
    for(int ii=0; ii<N;++ii){
        array[ii]=ii;
        std::cout << array[ii] << " ";
    }
    std::cout <<"\n";
    return 0;
}
double promed(int N)
{
    double sum=0;
    std::vector <double> array(N);
    for(int ii=0; ii<N;++ii){
        array[ii]=ii;
        std::cout << array[ii] << " ";
            sum += array[ii];
    }
    std::cout <<"\n";
    return sum/N;

}
double prom( const std::vector <double> & a)
{
    double sum = 0.0;
    for(int ii=0; ii < a.size();++ii){
        sum += a[ii];
    }
    return sum/a.size();
}
void initialize(std::vector<double> & a)
{
  for(int ii = 0; ii < a.size(); ++ii){
    a[ii] = ii;
  }
}
void print(const std::vector<double> & a)
{
  for(int ii = 0; ii < a.size(); ++ii){
    std::cout << a[ii] << " ";
  }
  std::cout <<"\n";
}
int main(void)
{
    std::vector<double>  array(7);
    initialize(array);
    print(array);
    std::cout << prom(array) << "\n";
    std::cout << promed(7) << "\n";

    return 0;
}
