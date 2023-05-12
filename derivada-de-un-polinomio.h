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
   }
      cout << abs(Coeficiente[i]);
   if (Grado[i] != 0) {
      cout << "x";
   }
   if (Grado[i] != 0 && Grado[i] != 1) {
      cout << "^" << Grado[i];
   }
   cout << " ";
   return 0;
}

void SumaTerminos (float Coeficiente[], float Grado[], int Terminos, int i){

   for (i = 0; i < Terminos ; i++) {
      for (int j = i + 1; j < Terminos; j++) {
         if (Grado[i] == Grado [j]) {
            Coeficiente[i] += Coeficiente[j];
            Coeficiente[j] = 0;
         }
      }
   }
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
      cout << "Termino" << i + 1 << ": " << endl;
      cin >> Coeficiente[i]; 
      cout <<"\e[A" << Coeficiente[i] << "x^";
      cin >> Grado[i];
      valor[i] = Signo( Coeficiente, i);
      cout << endl;
   }
   cout << "f(x) = ";
   for (int i =0; i < Terminos; i++) {
   Literales(Coeficiente, i, Grado, valor);
   }
   cout << "\nf'(x) = " ;
   for (i = 0; i < Terminos; i++) {
      Coeficiente[i] *= Grado[i];
      Grado[i]--;
      valor[i] = Signo(Coeficiente, i);
      Literales(Coeficiente, i, Grado, valor);
   }
   cout << endl;
}
