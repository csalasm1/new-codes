#include <iostream> //metodo del trapecio
#include <cmath>

double funcion(double x)
{
    double ya= 1/(x*(x+2.0));
    return ya;
}
int main ()
{
    int n,i;
    double a,b,h, sum=0,integral;
    std::cout.precision(16);
    std::cout << "dame los limites de integracion\n";
    std::cin >> a;
    std::cin >> b;
    std::cout << "dame el numero de intervalos, que sea entero\n";
    std::cin >> n;

    double x[n+1],y[n+1];
    h= (b-a)/n;
    for(i=0;i<=n;i++)
    {
        x[i]=a+(i*h);
        y[i]=funcion(x[i]);
    }
    for (i=1;i<n;i++)
    {
        sum=sum+(y[i]*h);
    }
    integral=h/2.0*(y[0]+y[n])+sum;
    std::cout << "la integral definida es " << integral << "\n";

    return 0;
}


