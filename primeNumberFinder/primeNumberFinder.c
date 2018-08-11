// Canberk Sinangil 2018

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <math.h>
#include <time.h>

//Declaration of all functions.
void primeNumberCalculator();
int welcome();
void welcomeText();
void errorText();
void againText();
void goodbyeText();
void process1Text();
void process234Text();
void alright();
void userDecision(int userOption);
int again();
void process1();
void process2();
void process3();
void process4();
int method1 (int number);
int method2 (int number);
int method11 (bool print, int range);
int method22 (bool print, int range);

void main() {
	primeNumberCalculator();
	printf("\n\n\n\n\nCanberk Sinangil :)");
}

void primeNumberCalculator(){
	
	userDecision(welcome());

}

int welcome(){
	unsigned short int option;

	welcomeText();
	scanf("%d",&option);
	
	while(option < 1 || option > 4){
		errorText();
		welcomeText();
		scanf("%d",&option);
	}
	alright();
	
	return option;
}

void welcomeText(){
	printf("Select an optiom bellow.\n");
	printf("\t1. Is it prime? Number tester.\n");
	printf("\t2. Prime number finder.(n/2 method)\n");
	printf("\t3. Prime number finder.(square root of n method)\n");
	printf("\t4. Prime number finders comparisons.(square root of n vs n/2)\n");
	printf("Your option is =");
}

void errorText(){ 
	system("COLOR C"); 
	system("cls"); 
	printf("Please enter acceptable value!\n\n\n\n\n");
}

void process1Text(){
	printf("\nPlease enter a positive number to test. =");
}

void alright(){
	system("cls"); 
	system("COLOR A");
}

void againText(){
	printf("\n\nWould you like to try again?(0 = NO, 1 = YES)\nPlease enter 0 or 1 (to resart the program enter 2). =");
}

void goodbyeText(){
	alright();
	system("cls"); 
	printf("\n\nThank you for using this application!");
}

void process234Text(){
	printf("\nPlease Enter a positive number to test (Max = 1.000.000). =");
}

void userDecision(int userOption){
	switch(userOption){

		case 1 : 
			process1();
			break;
		
		case 2 : 
			process2();
			break;
		
		case 3 : 
			process3();
			break;
		
		case 4 :
			process4();
			break;
	}
}

int again(){
	int input;
	againText();
	scanf("%d",&input);
	
	while(input !=0 && input != 1 && input != 2){
		errorText();
		againText();
		scanf("%d",&input);
	}
	
	
	
	if(input == 0){
		alright();
		return 0;
	}
	
	else{
		alright();
		return input;
	}
	
}

void process1(){
	bool flag = true;
	int isThisPrime;
	process1Text();
	scanf("%d",&isThisPrime);
	
	while(flag){
		int userChoice;
		
		if(isThisPrime == 0 || isThisPrime ==1){
			printf("\nIt is not a prime number!, smallest prime number is 2!");
		} 
		else if(isThisPrime < 0 ){
			errorText();
			process1Text();
			scanf("%d",&isThisPrime);
			alright();
			continue;
		}
		
		if (isThisPrime >= 2){
			if(method1(isThisPrime) == 0){
				printf("\n\n\tResult = It is a prime number!");
			}
			else{
				printf("\n\n\tResult = It is not a prime number!");
			}
		}
		
		userChoice = again();
	
		if(userChoice == 0){
			goodbyeText();
			break;
		} 
		else if(userChoice == 2){
			primeNumberCalculator();
			break;
		}
		
		process1Text();
		scanf("%d",&isThisPrime);
	}
}

void process2(){
	bool flag = true;
	int range;
	process234Text();
	scanf("%d",&range);
	
	while(flag){
		int userChoice;
		
		if(range == 0 || range == 1){
			printf("\nThere is no prime number!, smallest prime number is 2!");
		} 
		else if(range < 0 || range > 1000000){
			errorText();
			process234Text();
			scanf("%d",&range);
			alright();
			continue;
		}
		
		if (range >= 2){
			method22(true, range);
		}
		
		userChoice = again();
	
		if(userChoice == 0){
			goodbyeText();
			break;
		} 
		else if(userChoice == 2){
			primeNumberCalculator();
			break;
		}
		
		process234Text();
		scanf("%d",&range);
	}
}
	
void process3(){	
	bool flag = true;
	int range;
	process234Text();
	scanf("%d",&range);
	
	while(flag){
		int userChoice;
		
		if(range == 0 || range == 1){
			printf("\nThere is no prime number!, smallest prime number is 2!");
		} 
		else if(range < 0 || range > 1000000){
			errorText();
			process234Text();
			scanf("%d",&range);
			alright();
			continue;
		}
		
		if (range >= 2){
			method11(true, range);
		}
		
		userChoice = again();
	
		if(userChoice == 0){
			goodbyeText();
			break;
		} 
		else if(userChoice == 2){
			primeNumberCalculator();
			break;
		}
		
		process234Text();
		scanf("%d",&range);
	}
}

void process4(){
	bool flag = true;
	int range;
	process234Text();
	scanf("%d",&range);
	
	while(flag){
		int userChoice;
		
		if(range == 0 || range == 1){
			printf("\nThere is no prime number!, smallest prime number is 2!");
		} 
		else if(range < 0 || range > 1000000){
			errorText();
			process234Text();
			scanf("%d",&range);
			alright();
			continue;
		}
		
		if (range >= 2){
			printf("\n\nResult of n/2 method. =");
			method22(false, range);
			printf("\n\nResult of square root of n method. =");
			method11(false, range);
		}
		
		userChoice = again();
	
		if(userChoice == 0){
			goodbyeText();
			break;
		} 
		else if(userChoice == 2){
			primeNumberCalculator();
			break;
		}
		
		process234Text();
		scanf("%d",&range);
	}
}

int method1 (int number){
	int i;
	int counter = 0;
	for(i = 2; i <= sqrt(number); i++){
		if(number%i==0){
			counter++;
			break;
			}
		}	
	return counter;		
}

int method2 (int number){
	int i;
	int counter = 0;
	for(i = 2; i <= number/2; i++){
		if(number%i==0){
			counter++;
			break;
			}
		}	
	return counter;		
}

int method11 (bool print, int range){
	int currentNumber;
	clock_t begin = clock();
	for(currentNumber = 2; currentNumber <= range; currentNumber++){
		if(method1(currentNumber) == 0 && print == true){
		printf("%d\t", currentNumber);
		}
	}
	clock_t end = clock();
	double timeSpent = (double)(end - begin) / CLOCKS_PER_SEC;
	printf("\n\nTime spent (second) = %lf", timeSpent);
}

int method22 (bool print, int range){
	int currentNumber;
	clock_t begin = clock();
	for(currentNumber = 2; currentNumber <= range; currentNumber++){
		if(method2(currentNumber) == 0 && print == true){
		printf("%d\t", currentNumber);
		}
	}
	clock_t end = clock();
	double timeSpent = (double)(end - begin) / CLOCKS_PER_SEC;
	printf("\n\nTime spent (second) = %lf", timeSpent);
}
