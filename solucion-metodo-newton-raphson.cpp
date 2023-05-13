#include <iostream>
#include <cmath>
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

void SumaTerminos (float Coeficiente[], float Grado[], int terminos, int i){

   for (i = 0; i < terminos ; i++) {
      for (int j = i + 1; j < terminos; j++) {
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
   int terminos, i;

   cout << "terminos: "; cin >> terminos;
   float Coeficiente[terminos], Grado[terminos], derivadaCoeficiente[terminos], derivadaGrado[terminos];
   string valor[terminos], derivadaValor[terminos];

   for (i = 0; i < terminos; i++) {
      cout << "Termino" << i + 1 << ": " << endl;
      cin >> Coeficiente[i]; 
      cout <<"\e[A" << Coeficiente[i] << "x^";
      cin >> Grado[i];
      valor[i] = Signo( Coeficiente, i);
      cout << endl;
   }
   cout << "f(x) = ";
   for (int i =0; i < terminos; i++) {
   Literales(Coeficiente, i, Grado, valor);
   }
   cout << "\nf'(x) = " ;
   for (i = 0; i < terminos; i++) {
      derivadaCoeficiente[i] = Coeficiente[i] * Grado[i];
      derivadaGrado[i] = Grado[i]--;
      derivadaValor[i] = Signo(derivadaCoeficiente, i);
      Literales(derivadaCoeficiente, i, derivadaGrado, derivadaValor);
   }
   cout << endl;

   // empieza la solución de la ecuación
   // Utilizar if's para saber si x_n+1 + x_n == 0

   int precision;
   cout << "precision para el valor (iteraciones): ";
   cin >> precision;
   float iteracion[precision], funcion[precision], funcionDerivada[precision];
   cout << "Valor de primer iteracion: ";
   cin >> iteracion[0];

   for (int j = 0; i < precision; precision++) {
      for (int i = 0; i < terminos; i++) {
         funcion[j] += Coeficiente[i] * pow(iteracion[j],Grado[i]);
         funcionDerivada[j] += derivadaCoeficiente[i] * pow(iteracion[j], derivadaGrado[i]);
      }
      iteracion[j + 1] = iteracion[j] - (funcion[j]/funcionDerivada[j]);
   }
   cout << "Solucion mas cercana a " << iteracion[0] << ": " << iteracion[precision];
}
