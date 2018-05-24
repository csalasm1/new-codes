# include <iostream>

# include <vector>

# include <cmath>



bool is_orthogonal(const std::vector<double> & M, const double eps);





int main(void)

{

const int N = 4;

std::vector<double> A = {1, 0, 0, 0,

0, 0.8, 0.3, -0.52,

0, -0.6, 0.4, -0.69,

0, 0, 0.86, 0.5};

std::cout << is_orthogonal(A, 0.001) << std::endl;

std::cout << is_orthogonal(A, 0.012) << std::endl;

std::cout << is_orthogonal(A, 0.1) << std::endl;

return 0;

}





bool is_orthogonal(const std::vector<double> & M, const double eps){

//Traspuesta

std::vector<double> MT;

std::vector<double> MMT;

std::vector<double> I = {1,0,0,0,

0,1,0,0,

0,0,1,0,

0,0,0,1};

MT.resize(16);

MMT.resize(16);



//Llenando MT

for(int i = 0; i<4; ++i){

for(int j = 0; j<4; ++j){

MT[j*4+i]=M[i*4+j];

}

}

//Llenando MMT

for(int m = 0; m<4 ; m++){

for(int n = 0; n<4; n++){

double sum = 0;

for(int i=0;i<4;i++){

sum+= M[m*4+i]*MT[i*4+n];

}

MMT[m*4+n] = sum;

}



}





//Comparando

for(int i=0;i<16;i++){

if(std::fabs(MMT[i]-I[i])>eps){

return false;

}

}

return true;







}
