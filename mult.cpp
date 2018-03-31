// El objetivo de este programa fue pedir un número entero y devolverselo multiplicado por 2
// se hizo uso de ¨float¨ para poder usar números racionales además de los enteros, por último se usó ¨cmath¨ para poder añadir la constante M=2.
#include <iostream>
#include <cfloat>
#include <cmath>

using namespace std;

int main()

{
    const int M = 2;
    float a;
    float multiplica;
    std:: cout << "dame un numero entero\n";
    std:: cin >> a;
    multiplica = M*a;
    std:: cout << "tu numero multiplicado por 2 es: "<< multiplica<<endl;

    return 0;
}
