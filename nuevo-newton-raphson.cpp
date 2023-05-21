#include <iostream>
#include <cmath>
using namespace std;
int main () {
   int g;
   cout << "Grado de la ecuacion: ";
   cin >> g;

   float c[g], dc[g];

   for (int i = 0 ; i < g; i++) {
      float de = g-1-i;
      cout << "Termino " << i + 1 << ": " << endl;
      cin >> c[i];
      cout << "\e[A" << c[i] << "x^" << g - i << endl;
      dc[i] = c[i] * de;
   }
   int t;
   cout << "tolerancia: ";
   cin >> t;
   float x[t], f[t], df[t];
   for (int i = 0; i < g; i++) {
   }
}
