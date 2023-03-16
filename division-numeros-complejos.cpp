#include <iostream>
#include <math.h>
#include <cmath>
using namespace std;

int main(){

    int a, b, c, d;
    float real, imaginario;

    cout << "a =";
    cin >> a; cout << endl;

    cout << "b =";
    cin >> b; cout << endl;

    cout << "c =";
    cin >> c; cout << endl;

    cout << "d =";
    cin >> d; cout << endl;

    real = (a*c + b*d)/(pow(c,2) + pow(d,2));
    imaginario = (b*c - a*d)/(pow(c,2) + pow(d,2));

    cout << "z =" << real << " ";

    if (imaginario > 0){

        cout << "+";
    }

    cout << imaginario << "i";
    cout << endl;
}
