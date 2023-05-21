#include <iostream>
#include <cmath>
using namespace std;
int main () {
   int g;
   cout << "Grado de la ecuacion: ";
   cin >> g;

   float c[g+1], dc[g];

   for (int i = 0 ; i <= g; i++) {
      float de = g-1-i;
      cout << "Termino " << i + 1 << ": " << endl;
      cin >> c[i];
      cout << "\e[A" << c[i] << "x^" << g - i << endl;
   }
   cout << "f'(x) = ";
   for (int i = 0; i < g; i++) {
      dc[i] = c[i] * (g - i);
   }
   cout << endl;
   int t, i, j, k;
   cout << "tolerancia: ";
   cin >> t;
   float x[t], f[t], df[t], r[g];
   for (i = 0; i <g; i++) {
      cout << "Valor " << i + 1 << " a evaluar: ";
      cin >> x[0];
      for (j = 0; j <= t; j++) {
         f[j] = 0;
         df[j] = 0;
         for (int k = 0; k <= g; k++) {
            f[j] += c[k] * pow(x[j],(g-k));
         }
         for (k = 0; k < g; k++) {
            df[j] += dc[k] * pow(x[j],(g-k-1));
         }
         if (df[j] != 0) {
            x[j+ 1] = x[j] - (f[j]/df[j]);
         }
         else if (df[j] == 0){
            x[j] = -123456789.09876543210;
         }
         if (x[j+1] - x[j] == 0 || x[j] == -123456789.09876543210) {
            break;
         }
      }
      r[i] = x[j];
      if ((i != 0 && r[i] == r[i-1]) || r[i] == -123456789.09876543210) {
         i--;
         cout << "\nINTRODUCE OTRO VALOR\n";
      }
   }
   cout << "Soluciones: " << endl << endl;
   for (i = 0; i < g; i++) {
      cout << "Solucion " << i + 1 << ": " << r[i] << endl;
   }
}
