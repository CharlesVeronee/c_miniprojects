#include <stdio.h>

// leaf procedure since it does not call any other procedures/functions
long leaf1(long *a, long b){
    long val = 0;
    *a = *a + b;    // changes what a points to
    val = *a * b;   // uses new value to compute return value
    return val;
}

// call leaf1 to both return a value and modify a local variable.
long caller(long x) {
    long val = 8;
    long tmp = 2;
    val = val + leaf1(&tmp,x) + tmp;  // pass address of tmp so leaf1 can modify as needed
    return val;
}

long my_args(int *a, long b, short *c, long d, long e, long f, long g, long h){
    long val = 0;
    val = b + d + e - f + g - h;
    *a = 3;
    *c = 8;
    return val;
}


long my_recur(long a){
    long val = 0;
    if (a <= 0)
        return 1;
    else
        val = my_recur(a-1) + a;
    return val;
}

int main (int argc, char** argv){
    long x, y, foo, a2,a4,a5,a6,a7,a8;
    int i1, a1;
    short a3;
    x = 6; y = 4;
    i1 = 6; a1 = 7; a2 = 2; a4 = 1; a5 = 5; a6 = 6; a7 = 7; a8 = 3;
    a3 = 3;
    

    foo = caller(x);
    printf("caller: x %ld, foo %ld\n", x, foo);

    printf("before my_args a1 %d a2 %ld a3 %d a4 %ld a5 %ld a6 %ld a7 %ld a8 %ld\n",a1,a2,a3,a4,a5,a6,a7,a8);
    foo = my_args(&a1,a2,&a3,a4,a5,a6,a7,a8);
    printf("before my_args a1 %d a2 %ld a3 %d a4 %ld a5 %ld a6 %ld a7 %ld a8 %ld foo %ld\n",a1,a2,a3,a4,a5,a6,a7,a8,foo);

    foo = my_recur(y);
    printf("my_recur: y %ld, foo %ld\n", y, foo);

    return 0;
}
