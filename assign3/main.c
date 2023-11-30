#include<stdio.h>
#include"circle.c"
#include"rectangle.c"
#include"square.c"


int main(){
        float radius;
        float l,w;
        float a;

        printf("area of circle is %f",circle(radius));
        printf("area of circle is %f",rectangle(l,w));
        printf("area of circle is %f",square(a));
        

}