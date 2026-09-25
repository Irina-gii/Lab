#include <stdio.h>
#include <math.h>

int main(void){
    float u, u1, u2;
    double e_val = exp(1.0);
    for (float x = 1; x <= 3; x += 1.3){
        for (float y = 2; y <= 4; y += 1.5){
            if ((x / (y - 1.5)) < 1){
                u1 = pow(e_val, 2 * x) + log10(x);
                u2 = sin(-(1 - fabs(x - y)/pow(x, 1/3)));
                if (u1 < u2){
                    u = u1;
                } else{
                    u = u2;
                }
            } else{
                u = pow(cos(pow(x, 2) - y), 2);
            }
            printf("x=%f y=%f u=%f\n", x, y, u);
        }
    }

    return 0;
}