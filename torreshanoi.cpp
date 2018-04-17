#include <iostream>
#include <cmath>

void hanoi(int a,char A,char C,char B);

void hanoi(int a,char A,char C,char B)
{
    if(a==1)
    {
            std::cout<<"Mueva el bloque "<<a<<" desde "<<A<<" hasta  "<<C<<std::endl;

    }
    else
    {
        hanoi(a-1,A,B,C);
        std::cout<<"Mueva el bloque "<<a<<" desde "<<A<<" hasta  "<<C<<std::endl;
        hanoi(a-1,B,C,A);
    }
}
int main(void)
{
        int n;
        char A,B,C;

        std::cout<<"Los clavijas son A B C\n";
        hanoi(3,'A','C','B');

    return 0;
}
