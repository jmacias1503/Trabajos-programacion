#include <iostream>
#include <iomanip>
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

      double temp = arr[ValorMinimo];
      arr[ValorMinimo] = arr[i];
      arr[i] = temp;
   }
}

int main (int argc, char *argv[])
{
   int n;
   float Promedio, SumaPromedio;

   cout << "Numero de elementos: ";
   cin >> n;

   double arr[n];
   cout << "Elementos: \n";

   for (int i = 0; i < n; i++) {
      cin >> arr[i];
      SumaPromedio = SumaPromedio + arr[i];
   }

   Promedio = SumaPromedio / n;

   selectionSort(arr, n);

   cout << "Lista ordenada: ";
   for (int i = 0; i < n; i++) {
      cout << fixed << setprecision(2) << arr[i] << " ";
   }
   cout << endl;

   cout << "Promedio: " << Promedio;
   return 0;
}
