#include <cmath>
#include <iostream>
#include <string>
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

float FuncionIteracion(float coeficiente[], float grado[], float iteracion[], int terminos, int i, int j) {
   float resultado;
   for (int i = 0; i < terminos; i++) {
      resultado += coeficiente[i] * pow(iteracion[j],grado[i]);
   }
   return resultado;
}
float DerivadaIteracion(float derivadaCoeficiente[], float derivadaGrado[], float iteracion[], int terminos, int i, int j) {
   float resultado;
   for (int i = 0; i < terminos; i++) {
      resultado += derivadaCoeficiente[i] * pow(iteracion[j], derivadaGrado[i]);
   }
   return resultado;
}

int main () {
   int terminos, i;

   cout << "terminos: "; cin >> terminos;
   float coeficiente[terminos], grado[terminos], derivadaCoeficiente[terminos], derivadaGrado[terminos];
   string valor[terminos], derivadaValor[terminos];

   for (i = 0; i < terminos; i++) {
      cout << "Termino" << i + 1 << ": " << endl;
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
      valor[i] = Signo(derivadaCoeficiente, i);
      Literales(derivadaCoeficiente, i, derivadaGrado, derivadaValor);
   }
   cout << endl;

   // Empieza solucion de la ecuacion
   
   int tolerancia;
   cout << "tolerancia: ";
   cin >> tolerancia;
   float iteracion[tolerancia], funcion[tolerancia], derivada[tolerancia];
   cout << "Primer valor: ";
   cin >> iteracion[0];
   int j = 0;
   funcion[j] = FuncionIteracion(coeficiente, grado, iteracion, terminos, i, j);
   derivada[j] = DerivadaIteracion(derivadaCoeficiente, derivadaGrado, iteracion, terminos, i, j);
   cout << "funcion resuelta: " << FuncionIteracion(coeficiente, grado, iteracion, terminos, i, j) << "  " << funcion[j];
   cout << endl << "funcion derivada: " << DerivadaIteracion(derivadaCoeficiente, derivadaGrado, iteracion, terminos, i, j) << "  " << derivada[j];
}
