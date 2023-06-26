#include <stdio.h>
int main() {
   char s = ' ';
   float a,b,c,d,r,i;
   printf("a =");   scanf("%f",&a);
   printf("\nb ="); scanf("%f", &b);
   printf("\nc ="); scanf("%f", &c);
   printf("\nd ="); scanf("%f", &d);
   r = (a*c + b*d)/(c*c + d*d);
   i = (b*c - a*d)/(c*c + d*d);
   if (i > 0)
      s = '+';
   printf("\nz = %f %c%fi\n", r, s, i);
   return 0;
}
