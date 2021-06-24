/*
Program 4: 2-D arrays, zyBooks 7.13
Gary Tou <gary@garytou.com> (https://garytou.com)
5/5/2021
*/

#include <stdio.h>

#define MAX_ELEMENTS 10
#define NUM_TIERS 5

int p4() {

    int annualSalary;
    double taxRate;
    int taxToPay;
    int totalSalaries;
    int totalTaxes;
    int numSalaries;
    int keepLooking; // representing a boolean (1==true, 0==false)
    unsigned int i;
    int j;

    double dollars[4][MAX_ELEMENTS];
    
    // Use index enum rather than 0,1,2,3 to help remember which row is which:
    enum index { SALARY_BASE, TAX_BASE, ANNUAL_SAL, TAX_TO_PAY };

    dollars[SALARY_BASE][0] = 0;
    dollars[SALARY_BASE][1] = 20000;
    dollars[SALARY_BASE][2] = 50000;
    dollars[SALARY_BASE][3] = 100000;
    dollars[SALARY_BASE][4] = 99999999;
                          
    dollars[TAX_BASE][0] = 0.0;
    dollars[TAX_BASE][1] = 0.10;
    dollars[TAX_BASE][2] = 0.20;
    dollars[TAX_BASE][3] = 0.30;
    dollars[TAX_BASE][4] = 0.40;

    numSalaries = 0;

    printf("\nEnter annual salary (0 to exit): \n");
    scanf_s("%i", &annualSalary);

    while ((annualSalary > 0) && (numSalaries < MAX_ELEMENTS)) {
        i = 0;
        taxRate = 0;
        keepLooking = 1;

        // Search for appropriate table row for given annualSalary
        while ((i < NUM_TIERS) && keepLooking == 1) {
            if (annualSalary <= (int) dollars[SALARY_BASE][i]) {
                taxRate = dollars[TAX_BASE][i];
                keepLooking = 0;
            }
            else {
                ++i;
            }
        } // End inner while loop (search for appropriate table row)

        taxToPay = (int) (annualSalary * taxRate);
        dollars[ANNUAL_SAL][numSalaries] = annualSalary;
        dollars[TAX_TO_PAY][numSalaries] = taxToPay;

        printf("Annual salary: %i\tTax rate: %.1f\tTax to pay: %i\n", (int) dollars[ANNUAL_SAL][numSalaries], taxRate, (int) dollars[TAX_TO_PAY][numSalaries]);
        ++numSalaries;

        // Get the next annual salary
        printf("\nEnter annual salary (0 to exit): \n");
        scanf_s("%i", &annualSalary);
    } // End outer while loop (valid annualSalary entered)

    // Sum the annual salaries and taxes to pay and print the totals
    totalSalaries = 0;
    totalTaxes = 0;

    for (j = 0; j < numSalaries; ++j) {
        totalSalaries += (int) dollars[ANNUAL_SAL][j];
        totalTaxes += (int) dollars[TAX_TO_PAY][j];
    }
    printf("\nTotal salaries: %i\tTotal taxes: %i\n", totalSalaries, totalTaxes);

    return 0;
}