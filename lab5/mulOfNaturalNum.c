#include<stdio.h>

int mul(int);

int main(){
	int n;
	printf("Enter the number: ");
    scanf("%d", &n);
	printf("Multiplication of %d natural num: %d", n, mul(n));
}

int mul(int num){
	if(num == 1){
		return 1;
	}
	else{
		return num * mul(num-1);
	}

}
