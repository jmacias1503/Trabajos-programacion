#include <iostream>
#include <cmath>
#include <string>
using namespace std;
int main (){

   int alumnos[3];
   string L;
   float sum[3], prom[3], max;

   for (int i = 0; i < 3; i++) {
      cout << "Alumnos en el grupo " << i+1 << ": ";
      cin >> alumnos[i];

      float calif[alumnos[i]];

      for (int j = 0; j < alumnos[i]; j++) {
         cout << "\nCalificacion " << j+1 << ": ";
         cin >> calif[j];
         sum[i] += calif[j];
      }
      prom[i] = sum[i]/alumnos[i];
   }
   for (int i = 0; i < 3; i++) {
      cout << "\nPromedio " << i+1 << ": " << prom[i];
   }

   max = prom[0];
   L = "A";
   if (max < prom[1]) {
      max = prom[1];
      L = "B";
   }
   if (max < prom[2]) {
      max = prom[2];
      L = "C";
   }
   cout << "\nEl grupo " << L << " tuvo el mejor promedio grupal con " << max << endl;
}
