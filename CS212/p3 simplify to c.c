/*
Program 3: Simplify to C, zyBooks 4.11.2
Gary Tou <gary@garytou.com> (https://garytou.com)
4/28/2021
*/
#include <stdio.h>
#include <math.h>

int p3()
{
	int annualSalary;
	double taxRate;
	int taxToPay;

	printf("Enter annual salary: \n"); // Prompt the user into input their annual salary
	scanf_s("%i", &annualSalary); // scan the user's annual salary

	// Determine the tax rate from the annual salary
	if (annualSalary < 0) {
		printf("ERROR: salary must be positive.");
		return 0; // prevent the program from calculating taxes with a negative salary
	}
	else if (annualSalary <= 20000) {
		taxRate = 0.10;
	}
	else if (annualSalary <= 50000) {
		taxRate = 0.20;
	}
	else if (annualSalary <= 100000) {
		taxRate = 0.30;
	}
	else {
		taxRate = 0.40;
	}

	taxToPay = round(annualSalary * taxRate); // rounds the amount of tax to pay

	// print the results
	printf("Annual Salary: %d\n", annualSalary);
	printf("Tax rate: %f\n", taxRate);
	printf("Tax to pay: %d\n", taxToPay);

	return 0;
}