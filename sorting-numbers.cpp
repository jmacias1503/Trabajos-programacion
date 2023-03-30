#include <cmath>
#include <math.h>
#include <iostream>
using namespace std;

void OrdenarNumeros(double ListaDeNumeros[], int NumeroDatos) { //Ordenar numeros

   int i, j, ValorMinimo;

   for (i = 0; i < NumeroDatos-1; i++) {
      ValorMinimo = i;
      for (j = i+1; j < NumeroDatos; j++){
         if (ListaDeNumeros[j] < ListaDeNumeros[ValorMinimo]){
            ValorMinimo = j;
         }
      }

      double CambioDeValor = ListaDeNumeros[ValorMinimo];
      ListaDeNumeros[ValorMinimo] = ListaDeNumeros[i];
      ListaDeNumeros[i] = CambioDeValor;
   }
}

int main () {
   int NumeroDatos;
   float Promedio, SumaPromedio, DesviacionEstandar, SumaDesviacion, Mediana; //Declaracion de variables

   cout << "Numero de elementos: ";
   cin >> NumeroDatos;

   double ListaDeNumeros[NumeroDatos];
   cout << "Elementos: \n";

   for (int i = 0; i < NumeroDatos; i++) {
      cout << "Elemento " << i+1;
      cin >> ListaDeNumeros[i]; //Conocer numeros
      SumaPromedio = SumaPromedio + ListaDeNumeros[i]; //Sumar los numeros mientras se van conociendo para el promedio
   }

   Promedio = SumaPromedio / NumeroDatos;

   for (int i = 0; i < NumeroDatos; i++) {
      SumaDesviacion = SumaDesviacion + pow((ListaDeNumeros[i] - Promedio),2); //Suma repetitiva para la desviacion
   }
   DesviacionEstandar = sqrt((SumaDesviacion)/NumeroDatos);

   OrdenarNumeros(ListaDeNumeros, NumeroDatos);

   if (NumeroDatos % 2 == 0) { //Calcular mediana si el numero de datos es par

      Mediana = (ListaDeNumeros[NumeroDatos/2] + ListaDeNumeros[(NumeroDatos/2)-1])/2;
   }
   else { //Calcular mediana si el numero de datos es impar
      Mediana = ListaDeNumeros[(NumeroDatos-1)/2];
   }

   cout << "Lista ordenada: "; //Imprime la lista ordenada
   for (int i = 0; i < NumeroDatos; i++) {
      cout << ListaDeNumeros[i] << " ";
   }
   cout << endl;

   //Imprime los demas parametros solicitados
   cout << "Promedio: " << Promedio << endl;
   cout << "DesviacionEstandar: " << DesviacionEstandar << endl;
   cout << "Mediana: " << Mediana << endl;
   cout << "Rango: " << ListaDeNumeros[NumeroDatos-1] - ListaDeNumeros[0] << endl;
   return 0;
}
