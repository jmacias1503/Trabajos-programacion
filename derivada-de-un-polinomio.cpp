#include <cmath>
#include <iostream>
#include <string>
using namespace std;

int Literales(float Coeficiente[], int i, float Grado[], string valor[]){
   //if (Coeficiente[i] != 0) {
   //   if (i != 0) {
   //      cout << valor[i];
   //   }
   //   cout << abs(Coeficiente[i]);
   //   if (Grado[i] != 0) {
   //      cout << "x";
   //   }
   //   if (Grado[i] !=1 && Grado[i] != 0) {
   //      cout << "^" << Grado[i];
   //   }
   //   cout << " ";
   //}

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
   // if (Coeficiente[i] == 0) {
   // }
   // else {
   // cout << valor << abs(Coeficiente[i]);
   // }


   //if (Grado[i] == 0) {
   //}
   //else if (Grado[i]==1) {
   //   cout << "x";
   //}
   //else {
   //   cout << "x^" << Grado[i];
   //}
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
      cin >> Coeficiente[i]; 
      cout <<"\e[A" << Coeficiente[i] << "x^";
      cin >> Grado[i];
      valor[i] = Signo( Coeficiente, i);
   }
   i = 0;
   cout << "f(x) =";
   for (int i =0; i < Terminos; i++) {
      Literales(Coeficiente, i, Grado, valor);
      //cout << valor[i] << abs(Coeficiente[i]) <<"x^" << Grado[i] << " ";
   }
   i = 0;
   cout << "\nf'(x) = " ;
   for (i = 0; i < Terminos; i++) {
      Coeficiente[i] *= Grado[i];
      Grado[i]--;
      valor[i] = Signo(Coeficiente, i);
      Literales(Coeficiente, i, Grado, valor);
      //cout << valor[i] << abs(Coeficiente[i]) << "x^" << Grado[i] << " ";
   }
   cout << endl;
}
