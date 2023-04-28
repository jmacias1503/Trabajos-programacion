#include <iostream>
#include <cmath>
#include <string>
using namespace std;

string Signo(float Coeficiente[], int i) {
   string valor = "+";
   if (Coeficiente[i] < 0) {
      valor = "-";
   }
   return valor;
}
int main () {
   int Terminos, Grado[Terminos];

   cout << "Terminos: "; cin >> Terminos;
   float Coeficiente[Terminos];
   string valor[Terminos];

   for (int i = 0; i < Terminos; i++) {
      cin >> Coeficiente[i]; 
      cout <<"\e[A" << Coeficiente[i] << "x^";
      cin >> Grado[i];
      valor[i] = Signo( Coeficiente, i);
   }
   cout << "f(x) = " << Coeficiente[0] << "x^" << Grado[0] << " ";
   for (int i =1; i < Terminos; i++) {
      cout << valor[i] << abs(Coeficiente[i]) <<"x^" << Grado[i] << " ";
   }
   cout << "\nf'(x) = " << Coeficiente[0] * Grado[0] << "x^" << Grado[0] - 1 << " ";
   for (int i = 1; i < Terminos; i++) {
      Coeficiente[i] *= Grado[i];
      Grado[i]--;
      valor[i] = Signo(Coeficiente, i);
      cout << valor[i] << abs(Coeficiente[i]) << "x^" << Grado[i] << " ";
   }
   cout << endl;
}
