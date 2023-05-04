#include <cmath>
#include <iostream>
#include <string>
using namespace std;

int Literales(float Coeficiente[], int i, float Grado[], string valor[]){

   if (Coeficiente[i] == 0) {
      return 0;
   }
   if (i!=0) {
      cout << valor[i];
      Coeficiente[i] = abs(Coeficiente[i]);
   }
   cout << Coeficiente[i];
   if (Grado[i] != 0) {
      cout << "x";
   }
   if (Grado[i] != 0 && Grado[i] != 1) {
      cout << "^" << Grado[i];
   }
   return 0;
}

string Signo(float Coeficiente[], int i) {
   string valor = "+";
   if (Coeficiente[i] < 0) {
      valor = "-";
   }
   return valor;
}
int main () {
   int Terminos, i;

   cout << "Terminos: "; cin >> Terminos;
   float Coeficiente[Terminos], Grado[Terminos];
   string valor[Terminos];

   for (i = 0; i < Terminos; i++) {
      cout << i + 1 << ": " << endl;
      cin >> Coeficiente[i]; 
      cout <<"\e[A" << Coeficiente[i] << "x^";
      cin >> Grado[i];
      valor[i] = Signo( Coeficiente, i);
      cout << endl;
   }
   i = 0;
   cout << "f(x) =";
   for (int i =0; i < Terminos; i++) {
   Literales(Coeficiente, i, Grado, valor);
   }
   i = 0;
   cout << "\nf'(x) = " ;
   for (i = 0; i < Terminos; i++) {
      Coeficiente[i] *= Grado[i];
      Grado[i]--;
      valor[i] = Signo(Coeficiente, i);
      Literales(Coeficiente, i, Grado, valor);
   }
   cout << endl;
}
