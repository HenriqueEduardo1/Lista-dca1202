#include <stdio.h>

int main(){
    char c[4] = {'a','a','a','a'};
    int i[4] = {1,1,1,1};
    float f[4] = {1.0,1.0,1.0,1.0};
    double d[4] = {1.0,1.0,1.0,1.0};
    
    for (int i = 0; i < 4; i++){
        printf("char = %p, ",(c + i));
        printf("int = %p, ",(i + i));
        printf("float = %p, ",(f + i));
        printf("double = %p\n",(d + i));
    }
}