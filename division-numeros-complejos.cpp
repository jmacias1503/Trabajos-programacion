#include <iostream>
int main(){
   char s = ' ';
   float a, b, c, d, r, i;
   std::cout << "a =";   std::cin >> a;
   std::cout << "\nb ="; std::cin >> b;
   std::cout << "\nc ="; std::cin >> c;
   std::cout << "\nd ="; std::cin >> d;
   r = (a*c + b*d)/(c*c + d*d);
   i = (b*c - a*d)/(c*c + d*d);
   if (i > 0)
      s = '+';
   std::cout << "z =" << r << " " << s << i << "i" << std::endl;
   return 0;
}
