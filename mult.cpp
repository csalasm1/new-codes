// El objetivo de este programa fue pedir un n�mero entero y devolverselo multiplicado por 2
// se hizo uso de �float� para poder usar n�meros racionales adem�s de los enteros, por �ltimo se us� �cmath� para poder a�adir la constante M=2.
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
