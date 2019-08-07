#include <stdio.h>

int main() {
	int number;
	printf("Please enter a number: \n");
	scanf("%d",&number);
	printf("\n");

	func1(number);
	func2(number);
	func3(number);

	return 0;
}

func1(int number) {
	int i=0, j=0;
	for(i=0 ; i<number ; i++) {
		for(j=0 ; j<=i ; j++) {
			printf("*");
		}
		printf("\n");
	}
	printf("\n");

	return;
}

func2(int number) {
	int i=0, j=0;
	for(i=0 ; i<number ; i++) {
		for(j=0 ; j<=i ; j++) {
			printf("*");
		}
	printf("\n");
	}
	for(i=number-1 ; i>0 ; i--) {
		for(j=0 ; j<i ; j++) {
			printf("*");
		}
		printf("\n");
	}
	printf("\n");

	return;
}

func3(int number) {
	int i=0, j=0;
	for(i=0 ; i<number ; i++) {
		for(j=(number-i-1) ; j>0 ; j--) {
			printf(" ");
		}
		for(j=0 ; j<(2*i+1) ; j++) {
			printf("*");
		}		
		printf("\n");
	}
	printf("\n");
	return;
}
