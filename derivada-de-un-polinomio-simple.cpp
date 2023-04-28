#include <iostream>
#include <cmath>
#include <string>
using namespace std;

string Signo(float c[], int i) {
   string v = "+";
   if (c[i] < 0) {
      v = "-";
   }
   return v;
}
int main () {
   int n, e[n];

   cout << "Terminos: "; cin >> n;
   float c[n];
   string v[n];

   for (int i = 0; i < n; i++) {
      cin >> c[i]; 
      cout <<"\e[A" << c[i] << "x^";
      cin >> e[i];
      v[i] = Signo( c, i);
   }
   cout << "f(x) = " << c[0] << "x^" << e[0] << " ";
   for (int i =1; i < n; i++) {
      cout << v[i] << abs(c[i]) <<"x^" << e[i] << " ";
   }
   cout << "\nf'(x) = " << c[0] * e[0] << "x^" << e[0] - 1 << " ";
   for (int i = 1; i < n; i++) {
      c[i] *= e[i];
      e[i]--;
      v[i] = Signo(c, i);
      cout << v[i] << abs(c[i]) << "x^" << e[i] << " ";
   }
   cout << endl;
}
