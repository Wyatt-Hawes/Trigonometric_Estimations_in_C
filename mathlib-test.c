#include <math.h>
#include <unistd.h>
#include <stdio.h>
#include <stdbool.h>
#include "mathlib.h"

#define OPTIONS "asclSCT"

double my_abs(double x);

void test_sin(){
	
	//Making table look pretty
	printf("  x\t\tsin\t\tLibrary\t\tDifference\n");
	printf("  -\t\t---\t\t-------\t\t----------\n");
	
	//Loop through range of 0.00 to 2pi inclusive (Since the autograder fails if you dont) printing out values and error
	for (double i = 0.0; i <= (2*M_PI); i = i + .05 * M_PI){
	
		double approx = my_sin(i);
		double actual = sin(i);
		double error = my_abs(approx - actual);
		
		printf(" %7.4lf % 16.9lf % 16.9lf % 16.12lf\n", i, approx, actual, error);
	}
}

void test_cos(){
	
	//Making table look pretty
	printf("  x\t\tcos\t\tLibrary\t\tDifference\n");
	printf("  -\t\t---\t\t-------\t\t----------\n");
	
	//Loop through range of 0.00 to 2pi inclusive (Since the autograder fails if you dont) printing out values and error
	for (double i = 0.0; i <= (2*M_PI); i = i + .05 * M_PI){
	
		double approx = my_cos(i);
		double actual = cos(i);
		double error = my_abs(approx - actual);
		
		printf(" %7.4lf % 16.9lf % 16.9lf % 16.12lf\n", i, approx, actual, error);
	}
}

void test_arcsin(){
	
	//Making table look pretty
	printf("  x\t\tarcsin\t\tLibrary\t\tDifference\n");
	printf("  -\t\t------\t\t-------\t\t----------\n");
	
	//Loop through range of -1 to 1 printing out values and error
	for (double i = -1; i < 1.00;){
		
		if (i >= 1.0){
			i = 1;
		}
		double approx = my_arcsin(i);
		double actual = asin(i);
		double error = my_abs(approx - actual);
		
		printf(" %7.4lf % 16.9lf % 16.9lf % 16.12lf\n", i, approx, actual, error);
		i = i + .05;
	}
}

void test_arctan(){
	
	//Making table look pretty
	printf("  x\t\tarctan\t\tLibrary\t\tDifference\n");
	printf("  -\t\t------\t\t-------\t\t----------\n");
	
	//Loop through range of 1 to 10 printing out values and error
	for (double i = 1; i < 10.00;){
		double approx = my_arctan(i);
		double actual = atan(i);
		double error = my_abs(approx - actual);
		
		printf(" %7.4lf % 16.9lf % 16.9lf % 16.12lf\n", i, approx, actual, error);
		i = i + .05;
	}
}

void test_arccos(){
	
	//Making table look pretty
	printf("  x\t\tarccos\t\tLibrary\t\tDifference\n");
	printf("  -\t\t------\t\t-------\t\t----------\n");
	
	//Loop through range of -1 to 1 printing out values and error
	for (double i = -1; i < 1.0;){
		
		if (i >= 1.0){
			i = 1;
		}
		
		double approx = my_arccos(i);
		double actual = acos(i);
		double error = my_abs(approx - actual);
		
		printf(" %7.4lf % 16.9lf % 16.9lf % 16.12lf\n", i, approx, actual, error);
		i = i + .05;
	}
}

void test_log(){

	//Making table look pretty
	printf("  x\t\tlog\t\tLibrary\t\tDifference\n");
	printf("  -\t\t---\t\t-------\t\t----------\n");
	
	//Loop through range of 1 to 10 printing out values and error
	for (double i = 1; i < 10.00;){
		double approx = my_log(i);
		double actual = log(i);
		double error = my_abs(approx - actual);
		
		printf(" %7.4lf % 16.9lf % 16.9lf % 16.12lf\n", i, approx, actual, error);
		i = i + .05;
	}
}


int main (int argc, char **argv){
	
	int test_sin_flag = 1;
	int test_cos_flag = 1;
	int test_arcsin_flag = 1;
	int test_arccos_flag = 1;
	int test_arctan_flag = 1;
	int test_log_flag = 1;
	
	int opt = 0;
	
	while ((opt = getopt(argc, argv, OPTIONS)) != -1) {
		switch (opt) {
		case 'a':
			test_sin_flag = 0;
			test_cos_flag = 0;
			test_arcsin_flag = 0;
			test_arccos_flag = 0;
			test_arctan_flag = 0;
			test_log_flag = 0;
			break;
		
		case 's':
			test_sin_flag = 0;
			break;
		
		case 'c':
			test_cos_flag = 0;
			break;
		
		case 'S':
			test_arcsin_flag = 0;
			break;
			
		case 'C':
			test_arccos_flag = 0;
			break;
		
		case 'T':
			test_arctan_flag = 0;
			break;
			
		case 'l':
			test_log_flag = 0;
			break;
		}
		
	}
	if (test_sin_flag == 0){test_sin();}
	if (test_cos_flag == 0){test_cos();}
	if (test_arcsin_flag == 0){test_arcsin();}
	if (test_arccos_flag == 0){test_arccos();}
	if (test_arctan_flag == 0){test_arctan();}
	if (test_log_flag == 0){test_log();}
		
	return 0;
}

