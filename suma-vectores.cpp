#include <iostream>
#include <cmath>

using namespace std; //ahorra paso de poner std::cout

int main () { //funcion principal

   float const PI = 3.14159265358979323846264338; //El calculo de las funciones trigonometricas es en radianes
   int NumeroDatos, MedidaGrados;

   cout << "Numero de datos: "; cin >> NumeroDatos; cout << endl << endl; //conocer numero de datos 

   float DireccionVector[NumeroDatos], MagnitudVector[NumeroDatos], ComponenteX[NumeroDatos], ComponenteY[NumeroDatos], SumaComponentesX, SumaComponentesY, Resultante, Angulo; //declaracion de variables

   for (int i = 0; i < NumeroDatos; i++) { //Conocer direccion y magnitud

      cout << "Unidad de grados:" << endl << "1: grados" << endl << "2: radianes" << endl; cin >> MedidaGrados; cout << endl;
      cout << "Direccion Vector " << i + 1 << ": "; cin >> DireccionVector[i]; cout << endl;
      cout << "Magnitud Vector " << i + 1 << ": "; cin >> MagnitudVector[i]; cout << endl;

      if (MedidaGrados == 1) {
         DireccionVector[i] = (DireccionVector[i] * PI) / 180; //conversion de grados a radianes
      }

      ComponenteX[i] = MagnitudVector[i] * cos(DireccionVector[i]); //Calculo de componentes
      ComponenteY[i] = MagnitudVector[i] * sin(DireccionVector[i]);

      cout << "Componente x: " << ComponenteX[i] << endl << "Componente y: " << ComponenteY[i] << endl << endl;

      SumaComponentesX += ComponenteX[i]; //Calculo de la suma
      SumaComponentesY += ComponenteY[i];

   }

   Resultante = sqrt(pow(SumaComponentesX,2) + pow(SumaComponentesY,2)); //calculo de la resultante

   if (SumaComponentesX == 0 && SumaComponentesY > 0) { // Si la componente x = 0
      Angulo = (PI / 2);
   }
   else if (SumaComponentesX == 0 && SumaComponentesY < 0) {
      Angulo = (3*PI)/2;
   }
   else if (SumaComponentesX != 0){
      Angulo = atan(SumaComponentesY/SumaComponentesX); //calculo del angulo
   }

   if (SumaComponentesX < 0) { //En caso de que el vector este en cuadrante 2 o 3 (180 grados)
      Angulo += PI;
   }
   else { // en caso de que el vector este en el cuadrante 1 o 4 (360 grados)
      Angulo += (2*PI);
   }

   while (Angulo >= (2*PI)) { // Se completa una vuelta de 360 grados
      Angulo -= (2*PI);
   }

   cout << "Resultante: " << Resultante << endl << "Direccion: " << endl << Angulo << " radianes" << endl << (Angulo * 180) / PI << " grados" << endl; //imprime resultados
   return 0;
}
