#include <cmath>
#include <iostream>
#include <string>
#include <fstream>
using namespace std;
int Literales(float c[], int i, float e[], string v[]){
   if (c[i] == 0) {
      return 0;
   }
   if (i!=0) {
      cout << v[i];
   }
      cout << abs(c[i]);
   if (e[i] != 0) {
      cout << "x";
   }
   if (e[i] != 0 && e[i] != 1) {
      cout << "^" << e[i];
   }
   cout << " ";
   return 0;
}
void SumaTerminos (float c[], float e[], int n, int i){

   for (i = 0; i < n ; i++) {
      for (int j = i + 1; j < n; j++) {
         if (e[i] == e [j]) {
            c[i] += c[j];
            c[j] = 0;
         }
      }
   }
}

string Signo(float c[], int i) {
   string v = "+";
   if (c[i] < 0) {
      v = "-";
   }
   return v;
}

float FuncionIteracion(float c[], float e[], float x[], int n, int i, int j) {
   float resultado;
   for (i = 0; i < n; i++) {
      resultado += c[i] * pow(x[j],e[i]);
   }
   return resultado;
}
float DerivadaIteracion(float dc[], float de[], float x[], int n, int i, int j) {
   float resultado;
   for (i = 0; i < n; i++) {
      resultado += dc[i] * pow(x[j], de[i]);
   }
   return resultado;
}

int main () {
   int n, i;
   cout << "Terminos: "; cin >> n;
   float c[n], e[n], dc[n], de[n];
   string v[n], derivadaValor[n];

   for (i = 0; i < n; i++) {
      cout << "Termino" << i + 1 << ": " << endl;
      cin >> c[i]; 
      cout <<"\e[A" << c[i] << "x^";
      cin >> e[i];
      v[i] = Signo( c, i);
      cout << endl;
   }
   cout << "f(x) = ";
   for (int i =0; i < n; i++) {
   Literales(c, i, e, v);
   }
   cout << "\nf'(x) = " ;
   for (i = 0; i < n; i++) {
      dc[i] = c[i] * e[i];
      de[i] = e[i] - 1;
      v[i] = Signo(dc, i);
      Literales(dc, i, de, derivadaValor);
   }
   cout << endl;
   // Empieza solucion de la ecuacion
   int t;
   cout << "tolerancia: ";
   cin >> t;
   float x[t], f[t], df[t];
   cout << "Primer valor (distinto de 0): ";
   cin >> x[0];
   int j = 0;
   f[j] = FuncionIteracion(c, e, x, n, i, j);
   df[j] = DerivadaIteracion(dc, de, x, n, i, j);
   cout << "f resuelta: " << FuncionIteracion(c, e, x, n, i, j) << "  " << f[j];
   cout << endl << "f derivada: " << DerivadaIteracion(dc, de, x, n, i, j) << "  " << df[j] - f[j] << endl << endl;

   for (j = 1; j <= t; j++) {
      x[j] = x[j-1] - (f[j-1]/(df[j-1]-f[j-1]));
      f[j] = FuncionIteracion(c, e, x, n, i, j);
      df[j] = DerivadaIteracion(dc, de, x, n, i, j);
      cout << "x[" << j << "] = " << x[j] << endl;
      if (x[j] - x[j-1] == 0 || x[j] == 0) {
         break;
      }
   }
   cout << "Solucion mas cercana a " << x[0] << ": " << x[j];
}
