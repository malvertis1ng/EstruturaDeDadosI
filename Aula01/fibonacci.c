#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int chamadas = 0, aux = 0;
int fib (int num){
    if(num == 0){
        chamadas++;
        return 0;
    }else if(num == 1){
        aux++;
        chamadas++;
        return 1;
    }else{
        chamadas++;
        return(fib(num - 1) + fib(num - 2));
    }
}

int main(){
    int quantidade, num, i, j;
    scanf("%d", &quantidade);
    for(i=0;i<quantidade;i++){
        chamadas = 0;
        aux = 0;
        scanf("%d", &num);
        j = fib(num);
        printf("fib(%d) = %d calss = %d\n", num, chamadas - 1, aux);
    }
    return 0;
}