#include <iostream>
#include <cmath>

using namespace std; //ahorra paso de poner std::cout

int main () { //funcion principal

   float const PI = 3.14159265358979323846264338;
   int NumeroDatos, MedidaGrados, Cuadrante;

   cout << "Numero de datos: "; 
   cin >> NumeroDatos; 
   cout << endl << endl;

   float DireccionVector[NumeroDatos], MagnitudVector[NumeroDatos], ComponenteX[NumeroDatos], ComponenteY[NumeroDatos], SumaComponentesX, SumaComponentesY, Resultante, Angulo;

   for (int i = 0; i < NumeroDatos; i++) {

      cout << "Unidad de grados:" << endl << "1: grados" << endl << "2: radianes" << endl;
      cin >> MedidaGrados; 
      cout << endl;

      cout << "Direccion Vector " << i + 1 << ": "; 
      cin >> DireccionVector[i]; 
      cout << endl;

      cout << "Magnitud Vector " << i + 1 << ": "; 
      cin >> MagnitudVector[i]; 
      cout << endl;

      if (MedidaGrados == 1) {
         DireccionVector[i] = (DireccionVector[i] * PI) / 180;
      }

      ComponenteX[i] = MagnitudVector[i] * cos(DireccionVector[i]);
      ComponenteY[i] = MagnitudVector[i] * sin(DireccionVector[i]);

      cout << "Componente x: " << ComponenteX[i] << endl << "Componente y: " << ComponenteY[i] << endl << endl;

      SumaComponentesX += ComponenteX[i];
      SumaComponentesY += ComponenteY[i];
   }
   Resultante = sqrt(pow(SumaComponentesX,2) + pow(SumaComponentesY,2));

   if (SumaComponentesX == 0 && SumaComponentesY > 0) {
      Angulo = (PI / 2);
   }
   else if (SumaComponentesX == 0 && SumaComponentesY < 0) {
      Angulo = (3*PI)/2;
   }
   else if (SumaComponentesX != 0){
      Angulo = atan(SumaComponentesY/SumaComponentesX);
   }

   if (SumaComponentesX < 0) {
      Angulo += PI;
   }
   else {
      Angulo += (2*PI);
   }

   while (Angulo >= (2*PI)) {
      Angulo -= (2*PI);
   }

   Cuadrante = 4;
   if (Angulo < (3*PI/2)) {
      Cuadrante = 3;
   }
   else if (Angulo < PI) {
      Cuadrante = 2;
   }
   else if (Angulo < (PI/2)) {
      Cuadrante = 1;
   }
   cout << "Resultante: " << Resultante << endl << "Direccion: " << endl << Angulo << " radianes" << endl << (Angulo * 180) / PI << " grados" << endl; //imprime resultados
   return 0;
}
