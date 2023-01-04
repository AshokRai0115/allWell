//Write a program to read n number and find sum and average of those numbers.
#include<stdio.h>
int main(){
	int n,i,sum=0;
	printf("Enter the value of n: ");
	scanf("%d",&n);
	int arr[n];
	printf("Enter %d numbers:\n",n);
	for (i=0;i<n;i++){
		scanf("%d",&arr[i]);
	}
	for(i=0;i<n;i++){
		sum=sum+arr[i];
		
	}
	float average= (float)sum/n;
	printf("The sum of numbers is: %d,",sum);
		printf("\nThe average  of numbers is: %.2f,",average);
}
