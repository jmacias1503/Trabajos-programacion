#include <functional>
#include <iostream>
#include <math.h>
#include <cmath>

using namespace std;

float a, b, c, Radicando, x_1, x_2;

void ValorImaginario() {

    x_1 = (-b)/(2*a);
    x_2 = (sqrt(-Radicando))/(2*a);

    if (x_2 > 0) {

        cout << "x_1 = " << x_1 << " +" << x_2 << "i" << endl;
        cout << "x_2 = " << x_1 << " " << -x_2 << "i" << endl;
    }

    else {

        cout << "x_1 = " << x_1 << " " << x_2 << endl;
        cout << "x_2 = " << x_2 << " +" << -x_2 << endl;
    }
}


int main (int argc, char *argv[]) {

    cout << "Valor de a = "; cin >> a;
    cout << "Valor de b = "; cin >> b;
    cout << "Valor de c = "; cin >> c;

    Radicando = (pow(b,2))-(4*a*c);

    if (a == 0) {
        x_1 = -c/b;
        cout << "x = " << x_1;
    }

    else if (Radicando < 0) {
        ValorImaginario();
    }

    else if (Radicando == 0) {
        x_1 = (-b)/(2*a);
        cout << "x = " << x_1;
    }

    else {
        x_1 = (-b + sqrt(Radicando))/(2*a);
        x_2 = (-b - sqrt(Radicando))/(2*a);

        cout << "x_1 = " << x_1 << endl;
        cout << "x_2 = " << x_2 << endl;
    }

    return 0;
}
