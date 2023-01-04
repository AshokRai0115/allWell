#include<stdio.h>
int main(){
	int i, n, first = 0, second = 1, fib = 0;
	printf("Enter the number: ");
    scanf("%d", &n);
    printf("%d\t", first);
    printf("%d\t", second);
    for(i = 2; i<= n; i++){
    	fib = first + second;
    	printf("%d\t", fib);
    	first = second;
    	second = fib;
	}
}
