#include <stdio.h>

int palindrome(int);
int ascending(int);
int perfect(int);
int reverse(int);
int prime(int);

int main() {
	int number;
	printf("Please enter a number: \n");
	scanf("%d",&number);
/* if number is negative, can't run the functions */
	while(number<0) {
		printf("Number is negative, please enter positive number\n");
		scanf("%d",&number);
	}

/* run 5 functions */	
	if(palindrome(number)) {
		printf("%d is a palindrome\n",number);
	} else {
		printf("%d is not a palindrome\n",number);
	}
	if(ascending(number)) {
		printf("%d is ascending number\n",number);
	} else {
		printf("%d is not ascending number\n",number);
	}
	if(perfect(number)) {
		printf("%d is a perfect number\n",number);
	} else {
		printf("%d is not a perfect number\n",number);
	}
	printf("The reversed number of %d is %d\n",number,reverse(number));
	if(prime(number)) {
		printf("%d is a prime number\n",number);
	} else {
		printf("%d is not a prime number\n",number);
	}
	return 0;
}

/* function to check if a number is palindrome */
int palindrome(int number) {
	int original=number, reversed=0, remainder;
	while(number!=0) {
		remainder=number%10;
		reversed=reversed*10+remainder;
		number/=10;
	}
	if(original==reversed) {
		return 1;
	}
	return 0;
}

/* function to check if the digits of a number are in ascending order */
int ascending(int number) {
	int next=20, current=0;
	while(number!=0) {
		current=number%10;
/* if digit is larger or equal to the next one, its not in ascending order */
		if(current>=next) {
			return 0;
		}
		next=current;
		number/=10;
	}
	return 1;
}

/* function to check if a number is perfect */
int perfect(int number) {
	int i, reminder, sum=0;
	
	for(i=1 ; i<=number-1 ; i++) {
		reminder=number%i;
		if(reminder==0) {
			sum+=i;
		}
	}
	if(number==sum) {
		return 1;
	}
	return 0;
}

/* function to reverse the order of the digits in a number */
int reverse(int number) {
	int reversed=0, remainder;
	while(number!=0) {
		remainder=number%10;
		reversed=reversed*10+remainder;
		number/=10;
	}
	return reversed;
}

/* function to check if a number is prime */
int prime(int number) {
	int i;
/* 1 is not prime and not not prime, can handle it specially */
	if(number==1) {
		return 0;
	}
	for(i=2 ; i<=(number/2) ; i++) {
		if(number%i==0) {
			return 0;
		}
	}
	return 1;
}
