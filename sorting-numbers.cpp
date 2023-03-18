#include <iostream>

using namespace std;

int main(){

   int NumeroElementos;

   cout << "Numero de elementos = "; cin >> NumeroElementos;
   cout << endl;
   int array[NumeroElementos];

   cout << "Ingresa los numeros" << endl;

   for (int i = 0; i <= (NumeroElementos - 1); i++) {

      cin >> array[i];
   }

   for (int i = 0; i <=(NumeroElementos -1); i++) {

      cout << array[i];
   }
}
