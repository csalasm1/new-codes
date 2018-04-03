#include <iostream>
#include <cmath>
int isprime (int x);

int isprime(int x)
{
    if(x==2){
        return 1;
    }
    for(int ii=2; ii<x; ii++)
    {
        if(ii!=x){
        if(x%ii ==0){
                return 0;
        }
        else return 1;
        }
    }
    return 0;
}

int main(void)
{
    std::cout << isprime(-2) << std::endl;
std::cout << isprime(0) << std::endl;
std::cout << isprime(2) << std::endl;
std::cout << isprime(3) << std::endl;
std::cout << isprime(4) << std::endl;
std::cout << isprime(41) << std::endl;
std::cout << isprime(7) << std::endl;
std::cout << isprime(17) << std::endl;
std::cout << isprime(10) << std::endl;
std::cout << isprime(1) << std::endl;


    return 0;
}
