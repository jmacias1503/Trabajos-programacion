#include <iostream>
#include <cmath>
#include <string>

using namespace std;

int main () {

double const PI = 3.141592;
int NumeroDatos, ConstanteAngulo, MedidaGrados;

cout << "Numero de datos: "; cin >> NumeroDatos; cout << endl << endl;

float DireccionVector[NumeroDatos], MagnitudVector[NumeroDatos], ComponenteX[NumeroDatos], ComponenteY[NumeroDatos], SumaComponentesX, SumaComponentesY, Resultante, Angulo;

for (int i = 0; i < NumeroDatos; i++) {

   cout << "Unidad de grados:" << endl << "1: grados" << endl << "2: radianes" << endl; cin >> MedidaGrados; cout << endl;
   cout << "Direccion Vector " << i + 1 << ": "; cin >> DireccionVector[i]; cout << endl;
   cout << "Magnitud Vector " << i + 1 << ": "; cin >> MagnitudVector[i]; cout << endl;

   if (MedidaGrados == 1) {
      DireccionVector[i] = DireccionVector[i] * (PI / 180);
   }

   ComponenteX[i] = MagnitudVector[i] * cos(DireccionVector[i]);
   ComponenteY[i] = MagnitudVector[i] * sin(DireccionVector[i]);

   SumaComponentesX += ComponenteX[i];
   SumaComponentesY += ComponenteY[i];

}

Resultante = sqrt(pow(SumaComponentesX,2) + pow(SumaComponentesY,2));

if (SumaComponentesX == 0) {
   Angulo = (PI / 2);
}
else {
   Angulo = atan(SumaComponentesY/SumaComponentesX);
}

if (SumaComponentesX < 0) {

   Angulo += PI;
}
else {

   Angulo += 2*PI;
}
if (Angulo > 2*PI) {

   Angulo -= 2*PI;
}

cout << "Resultante: " << Resultante << endl << "Direccion: " << endl << Angulo << " radianes" << endl << Angulo * (180 / PI) << "grados";
cout << endl;
return 0;
}
