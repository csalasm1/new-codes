#include <iostream>
#include <cmath>

int main()
{
    const int n=2,m=3;
    const int l=2,g=3;

    double A[n][m]={{0.0}} ;

   for (int ii = 0; ii < n; ++ii) {
     for (int jj = 0; jj < m; ++jj) {
       A[ii][jj] =   ii*n+jj;
     }
   }
    for (int ii = 0; ii < n; ++ii) {
     for (int jj = 0; jj < m; ++jj) {
      std::cout << A[ii][jj] << "  ";
        }
    std::cout <<std::endl;
   }
   std::cout <<std::endl;
   double B[l][g]={{0.0}} ;
   for (int ii = 0; ii < g; ++ii) {
     for (int jj = 0; jj < l; ++jj) {
       B[ii][jj] =   ii*2+jj;
     }
   }
    for (int ii = 0; ii < g; ++ii) {
     for (int jj = 0; jj < l; ++jj) {
      std::cout << B[ii][jj] << "  ";
        }
    std::cout <<std::endl;
   }
   std::cout <<std::endl;
    int r = n;
    int t = l;
   double C[m][n]={{0.0}};

   for(int ii = 0; ii < n; ++ii){
    for(int jj = 0; jj < l; ++jj){
        for(int zz=0; zz<g; ++zz){
                C[ii][jj] += A[ii][zz] * B[zz][jj];
        }
    }
   }
   for (int ii = 0; ii < n; ++ii) {
     for (int jj = 0; jj < l; ++jj) {
            for(int zz=0; zz<m; ++zz){
        }
        std::cout << C[ii][jj] << "  ";
   }
   std::cout <<std::endl;
   }
   std::cout <<std::endl;
       for(int ii=0; ii<n; ++ii)
    {
        for(int jj=0; jj<l; ++jj)
        {
            std::cout<<C[ii][jj]<<" ";
        }
        std::cout<<std::endl;
    }
    std::cout << A[0][0]*B[0][0] << std::endl;
    std::cout << A[0][1] << std::endl;
    std::cout << B[1][0] << std::endl;
    std::cout << A[0][1]*B[1][0] << std::endl;
    std::cout << C[0][0] << std::endl;


    return 0;
}
