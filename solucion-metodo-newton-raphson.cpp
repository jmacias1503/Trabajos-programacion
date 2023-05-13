#include <iostream>
#include <cmath>
using namespace std;

int Literales(float coeficiente[], int i, float grado[], string valor[]){

   if (coeficiente[i] == 0) {
      return 0;
   }
   if (i!=0) {
      cout << valor[i];
   }
      cout << abs(coeficiente[i]);
   if (grado[i] != 0) {
      cout << "x";
   }
   if (grado[i] != 0 && grado[i] != 1) {
      cout << "^" << grado[i];
   }
   cout << " ";
   return 0;
}

void SumaTerminos (float coeficiente[], float grado[], int terminos, int i){

   for (i = 0; i < terminos ; i++) {
      for (int j = i + 1; j < terminos; j++) {
         if (grado[i] == grado [j]) {
            coeficiente[i] += coeficiente[j];
            coeficiente[j] = 0;
         }
      }
   }
}

string Signo(float coeficiente[], int i) {
   string valor = "+";
   if (coeficiente[i] < 0) {
      valor = "-";
   }
   return valor;
}
int main () {
   int terminos, i;

   cout << "Terminos: "; cin >> terminos;
   float coeficiente[terminos], grado[terminos], derivadaCoeficiente[terminos], derivadaGrado[terminos];
   string valor[terminos], derivadaValor[terminos];

   for (i = 0; i < terminos; i++) {
      cout << "Termino " << i + 1 << ": " << endl;
      cin >> coeficiente[i]; 
      cout <<"\e[A" << coeficiente[i] << "x^";
      cin >> grado[i];
      valor[i] = Signo( coeficiente, i);
      cout << endl;
   }
   cout << "f(x) = ";
   for (int i =0; i < terminos; i++) {
   Literales(coeficiente, i, grado, valor);
   }
   cout << "\nf'(x) = " ;
   for (i = 0; i < terminos; i++) {
      derivadaCoeficiente[i] = coeficiente[i] * grado[i];
      derivadaGrado[i] = grado[i] - 1;
      derivadaValor[i] = Signo(derivadaCoeficiente, i);
      Literales(derivadaCoeficiente, i, derivadaGrado, derivadaValor);
   }
   cout << endl;

   // empieza la solución de la ecuación
   // Utilizar if's para saber si x_n+1 + x_n == 0

   int precision;
   cout << "Precision para el valor (iteraciones): ";
   cin >> precision;
   float iteracion[precision], funcion[precision], funcionDerivada[precision];
   cout << "Valor de primer iteracion: ";
   cin >> iteracion[0];

   for (int j = 0; i < precision; precision++) {
      for (int i = 0; i < terminos; i++) {
         funcion[j] += coeficiente[i] * pow(iteracion[j],grado[i]);
         funcionDerivada[j] += derivadaCoeficiente[i] * pow(iteracion[j], derivadaGrado[i]);
      }
      iteracion[j + 1] = iteracion[j] - (funcion[j]/funcionDerivada[j]);
   }
   cout << "Solucion mas cercana a " << iteracion[0] << ": " << iteracion[precision];
}
