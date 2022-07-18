/*
Author: James Burns
Program: Change calculator
*/

#include <stdio.h>

double ReadChange()
{
	double change;
	do // This loop ensures that the user inputs a positive value
	{
		printf("Enter the amount of change: ");
		scanf("%lf", &change);
		if (change<=0)
			printf("\nYou have entered an invalid amount of change, Please try again\n");
	}while(change<=0);
	return(change);
}

int ReturnDollars(double change)
{
	int dollars;
	dollars = (int)change;
	return(dollars);
}

int ReturnCents(double change, int dollars)
{
	int cents;
	cents =(int)(((change-dollars)*100)+0.5);
	return(cents);
}

int CheckRange(int cents) //This function determines whether a number is equally divisible by 5 and is in the correct range of 5-95
{
	float multiple;
	multiple = 1;
		if (cents >= 0 && cents <=95)
			multiple = cents%5;
		if (multiple != 0)
			printf("\nYou have entered an invalid amount of cents, please try again\n");
	return(multiple);
}

void CalcChange(int change, int &fifty, int &twenty, int &ten, int &five, int &two, int &one)
{
		do
		{
			if ((change-50) >= 0)
			{
				change = change-50;
				fifty++;
			}
			else
				if ((change-20) >= 0)
				{
					change = change-20;
					twenty++;
				}
				else
					if ((change-10) >= 0)
					{
						change = change-10;
						ten++;
					}
					else
						if ((change-5) >= 0)
						{
						change = change-5;
						five++;
						}
						else
							if ((change-2) >= 0)
							{
								change = change-2;
								two++;
							}
							else
								if ((change-1) >= 0)
								{
									change = change-1;
									one++;
								}
		}while(change != 0);
	return;
}


void DispCents(int fiftycent, int twentycent, int tencent, int fivecent)
{
	if (fiftycent>=1)
		printf("\n %d fifty cent coin", fiftycent);
	if (twentycent>=1)
		printf("\n %d twenty cent coins", twentycent);
	if (tencent>=1)
		printf("\n %d ten cent coins", tencent);
	if (fivecent>=1)
		printf("\n %d five cent coins", fivecent);
	printf("\n");
	return;
}

void DispDollars(int fifty, int twenty, int ten, int five, int two, int one)
{
		printf("\nPlease give the customer:\n");
	if (fifty>=1)
		printf("\n %d fifty dollar notes", fifty);
	if (twenty>=1)
		printf("\n %d twenty dollar notes", twenty);
	if (ten>=1)
		printf("\n %d ten dollar notes", ten);
	if (five>=1)
		printf("\n %d five dollar notes", five);
	if (two>=1)
		printf("\n %d two dollar coins", two);
	if (one>=1)
		printf("\n %d one dollar coins", one);
	return;
}

int menu()
{
    int contin = 0;
    printf("\n 1. Enter Name\n 2. Exit\n");
    scanf("%d", &contin);
    return(contin);
}

int main()
{
	int dollars, cents, fifty, twenty, ten, five, two, one, multiple;
	double change;
	fifty = 0;
	twenty = 0;
	ten = 0;
	five = 0;
	two = 0;
	one = 0;
	int go;
	do
    {
	if (go = menu() == 1)
    {
        do
        {
            change = 0;
            change = ReadChange();
            dollars = ReturnDollars(change);
            cents = ReturnCents(change, dollars);
            multiple = CheckRange(cents);
        }while(multiple != 0);
        CalcChange(dollars, fifty, twenty, ten, five, two, one); // I'm re-using the same function to calculate cents
        DispDollars(fifty, twenty, ten, five, two, one);
        fifty = 0; // I need to zero these values so that the variables can be re-used
        twenty = 0;
        ten = 0;
        five = 0;
        CalcChange(cents, fifty, twenty, ten, five, two, one);
        DispCents(fifty, twenty, ten, five);
    }
    }while(go == 1);
    return(0);
}
