#include <cmath>
#include <iostream>
#include <string>
using namespace std;
int Literales(float c[], int i, float g[], string v[]){
   if (c[i] == 0) {
      return 0;
   }
   if (i!=0) {
      cout << v[i];
      c[i] = abs(c[i]);
   }
   if (c[i] != 1 && g[i] != 0) {
      cout << c[i];
   }
   if (g[i] != 0) {
      cout << "x";
   }
   if (g[i] != 0 && g[i] != 1) {
      cout << "^" << g[i];
   }
   cout << " ";
   return 0;
}
void SumaTerminos (float c[], float g[], int n, int i){
   for (i = 0; i < n ; i++) {
      for (int j = i + 1; j < n; j++) {
         if (g[i] == g [j]) {
            c[i] += c[j];
            c[j] = 0;
         }
      }
   }
}
string Signo(float c[], int i) {
   string v = "+";
   if (c[i] < 0) {
      v = "-";
   }
   return v;
}
int main () {
   int n, i;
   cout << "Terminos: "; cin >> n;
   float c[n], g[n];
   string v[n];
   for (i = 0; i < n; i++) {
      cout << i + 1 << ": " << endl;
      cin >> c[i]; 
      cout <<"\e[A" << c[i] << "x^";
      cin >> g[i];
      v[i] = Signo( c, i);
      cout << endl;
   }
   cout << "f(x) =";
   SumaTerminos(c, g, n, i);
   for (int i =0; i < n; i++) {
   Literales(c, i, g, v);
   }
   cout << "\nf'(x) = " ;
   for (i = 0; i < n; i++) {
      c[i] *= g[i];
      g[i]--;
      v[i] = Signo(c, i);
      Literales(c, i, g, v);
   }
   cout << endl;
}
