#include <iostream>
#include <cmath>
using namespace std;

int main (int argc, char *argv[]) {

   int grado, rango;
   cout << "Grado de la ecuacion: ";
   cin >> grado;
   float coeficiente[grado], derivadaCoeficiente[grado], precision;
   int derivadasConstantes[grado - 1];
   for (int i = 0; i <= grado; i++) {
      cout << "Termino " << i+1 << ": " << endl;
      cin >> coeficiente[i];
      cout << "\e[A" << coeficiente[i] << "x^" << grado - i << endl;
   }
   cout << "\nf'(x) = ";
   for (int i = grado; i > 0; i--) {
      derivadaCoeficiente[i] = coeficiente[i] * i;
   }
   return 0;
}
