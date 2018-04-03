#include <iostream>
#include <cmath>

int sumnum (int max);
int whilesumnum (int max);
int evennum(int max);

int sumnum (int max)
{
     int sum=0;

    for(int ii=0;ii <= max; ii++){
        sum = ii+sum;
    }
        return sum;
}
int whilesumnum (int max){
    int sum=0;
    int ii=0;
    while (ii<= max)
    {
        sum = ii+sum;
        ii++;
    }
    return sum;
}
int evennum(int max)
{
    for(int ii=1; ii<=max; ii++){
        if(ii%2 ==0){
            std::cout << ii << std::endl;
        }
    }
    return 0;
}

int main(void)
{
    std::cout << sumnum(20) << std::endl;
    std::cout << whilesumnum(20) << std::endl;
    std::cout << evennum(20) << std::endl;


    return 0;
}

