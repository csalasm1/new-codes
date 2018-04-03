#include <iostream> //metodo de simpson
#include <cmath>

double funcion(double x)
{
    double ya= 2*x*asin(x*x);
    return ya;
}
int main ()
{
    int n,i;
    double a,b,h, sum=0,integral;

    std::cout << "dame los limites de integracion\n";
    std::cin >> a;
    std::cin >> b;
    std::cout << "dame el numero de intervalos, que sea numero par\n";
    std::cin >> n;

    double x[n+1],y[n+1];
    h= (b-a)/n;
    for(i=0;i<n+1;i++)
    {
        x[i]=a+(i*h);
        y[i]=funcion(x[i]);
    }
    for (i=1;i<n;i+=2)
    {
        sum=sum+4.0*y[i];
    }
    for(i=2;i<n-1;i+=2)
    {
        sum=sum+(2.0*y[i]);
    }
    integral=h/3.0*(y[0]+y[n]+sum);
    std::cout << "la integral definida es " << integral << "\n";

    return 0;
}



