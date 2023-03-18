#include <iostream>

using namespace std;

int Contador, Comparador;
int NumeroElementos;

int main (int argc, char *argv[]) {

   int array[NumeroElementos];

   cout << "Numero de elementos = "; cin >> NumeroElementos;
   cout << endl;

   cout << "Ingresa los numeros" << endl;

   for (Contador = 0; Contador <= (NumeroElementos - 1); Contador++) {

      cin >> array[Contador];
   }
   cout << "Lista de numeros sin organizar: " << endl;

   for (Contador = 0; Contador <=(NumeroElementos -1); Contador++) {

      cout << array[Contador] << " ";
   }
   cout << endl;

   for (Contador = 0; Contador <=(NumeroElementos -1); Contador++) {

      for (Comparador = Contador + 1; Comparador <= (NumeroElementos -1); Comparador++) {

         if (array[Comparador] < array[Contador]) {

            array[Contador] = array[Comparador];
         }
      }
   }

   cout << "Lista de numeros organizados: " << endl;

   for (Contador = 0; Contador <=(NumeroElementos -1); Contador++) {

      cout << array[Contador] << " ";
   }

   return 0;
}
