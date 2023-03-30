#include <cmath>
#include <math.h>
#include <iostream>
using namespace std;

void selectionSort(double arr[], int n) {

   int i, j, ValorMinimo;

   for (i = 0; i < n-1; i++) {
      ValorMinimo = i;
      for (j = i+1; j < n; j++){
         if (arr[j] < arr[ValorMinimo]){
            ValorMinimo = j;
         }
      }

      double CambioDeValor = arr[ValorMinimo];
      arr[ValorMinimo] = arr[i];
      arr[i] = CambioDeValor;
   }
}

int main () {
   int n;
   float Promedio, SumaPromedio, DesviacionEstandar, SumaDesviacion, Mediana;

   cout << "Numero de elementos: ";
   cin >> n;

   double arr[n];
   cout << "Elementos: \n";

   for (int i = 0; i < n; i++) {
      cin >> arr[i];
      SumaPromedio = SumaPromedio + arr[i];
   }

   Promedio = SumaPromedio / n;

   for (int i = 0; i < n; i++) {
      SumaDesviacion = SumaDesviacion + pow((arr[i] - Promedio),2);
   }
   DesviacionEstandar = sqrt((SumaDesviacion)/n);

   selectionSort(arr, n);

   if (n % 2 == 0) {

      Mediana = (arr[n/2] + arr[(n/2)-1])/2;
   }
   else {
      Mediana = arr[(n-1)/2];
   }

   cout << "Lista ordenada: ";
   for (int i = 0; i < n; i++) {
      cout << arr[i] << " ";
   }
   cout << endl;

   cout << "Promedio: " << Promedio << endl;
   cout << "DesviacionEstandar: " << DesviacionEstandar << endl;
   cout << "Mediana: " << Mediana << endl;
   return 0;
}
