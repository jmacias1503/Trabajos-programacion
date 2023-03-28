#include <iostream>
#include <iomanip>
using namespace std;

void selectionSort(double arr[], int n) {

   int i, j, min_idx;

   for (i = 0; i < n-1; i++) {
      min_idx = i;
      for (j = i+1; j < n; j++){
         if (arr[j] < arr[min_idx]){
            min_idx = j;
         }
      }

      double temp = arr[min_idx];
      arr[min_idx] = arr[i];
      arr[i] = temp;
   }
}

int main (int argc, char *argv[])
{
   int n;
   cout << "Numero de elementos: ";
   cin >> n;

   double arr[n];
   cout << "Elementos: \n";

   for (int i = 0; i < n; i++) {
      cin >> arr[i];
   }

   selectionSort(arr, n);

   cout << "Lista ordenada: ";
   for (int i = 0; i < n; i++) {
      cout << fixed << setprecision(2) << arr[i] << " ";
   }
   return 0;
}
