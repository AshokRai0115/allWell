#include<stdio.h>

int sum(int);

int main(){
	int n;
	printf("Enter the number: ");
    scanf("%d", &n);
	printf("Sum of %d natural num: %d", n, sum(n));
}

int sum(int num){
	if(num == 1){
		return 1;
	}
	else{
		return num + sum(num-1);
	}

}
