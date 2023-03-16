#include <functional>
#include <iostream>
#include <math.h>
#include <cmath>

using namespace std;

float a, b, c, Radicando, Solucion1, Solucion2;

void ValorImaginario() {

    Solucion1 = (-b)/(2*a);
    Solucion2 = (sqrt(-Radicando))/(2*a);

    if (Solucion2 > 0) {

        cout << "x_1 = " << Solucion1 << " +" << Solucion2 << "i" << endl;
        cout << "x_2 = " << Solucion1 << " " << -Solucion2 << "i" << endl;
    }

    else {

        cout << "x_1 = " << Solucion1 << " " << Solucion2 << endl;
        cout << "x_2 = " << Solucion2 << " +" << -Solucion2 << endl;
    }
}


int main (int argc, char *argv[]) {

    cout << "Valor de a = "; cin >> a;
    cout << "Valor de b = "; cin >> b;
    cout << "Valor de c = "; cin >> c;

    Radicando = (pow(b,2))-(4*a*c);

    if (a == 0) {
        Solucion1 = -c/b;
        cout << "x = " << Solucion1;
    }

    else if (Radicando < 0) {
        ValorImaginario();
    }

    else if (Radicando == 0) {
        Solucion1 = (-b)/(2*a);
        cout << "x = " << Solucion1;
    }

    else {
        Solucion1 = (-b + sqrt(Radicando))/(2*a);
        Solucion2 = (-b - sqrt(Radicando))/(2*a);

        cout << "x_1 = " << Solucion1 << endl;
        cout << "x_2 = " << Solucion2 << endl;
    }

    cout << endl;

    return 0;
}
