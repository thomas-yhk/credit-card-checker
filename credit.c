#include <cs50.h>
#include <stdio.h>

int digits_calc(unsigned long long int cardNumber);
int type_check(unsigned long long int cardNumber);

int main(void)
{
    //get user input
    unsigned long long int cardNumber = get_long_long("please input your card number: ");
    int doubleSum;
    int singleSum;
    int totalSum;
    unsigned long long int doubleNumber;
    unsigned long long int singleNumber;
    int x1;
    int x2;
    int x3;

    //luhn's algo
    //multiply every other digit by 2 starting from 2nd last
    doubleNumber = cardNumber * 10;
    for (int i = 1; i <= digits_calc(cardNumber); i += 2)
    {
        doubleNumber = doubleNumber / 100;
        x1 = doubleNumber % 10;
        x1 = x1 * 2;
        if (x1 >= 10)
        {
            x2 = x1 % 10;
            x1 = x1 / 10;
            x1 = x1 + x2;
        }
        doubleSum = doubleSum + x1;
    };

    //add that sum along with the sum of the remaining digits
    singleNumber = cardNumber * 100;
    for (int i = 1; i <= digits_calc(cardNumber); i += 2)
    {
        singleNumber = singleNumber / 100;
        x3 = singleNumber % 10;
        singleSum = singleSum + x3;
    };

    //checking the type of card
    totalSum = doubleSum + singleSum;
    if (totalSum % 10 == 0)
    {
        if (digits_calc(cardNumber) == 15)
        {
            if (type_check(cardNumber) == 34 || type_check(cardNumber) == 37)
            {
                printf("AMEX\n");
            }
            else
            {
                printf("INVALID\n");
            }
        }
        else if (digits_calc(cardNumber) == 13)
        {
            if (type_check(cardNumber) == 4)
            {
                printf("VISA\n");
            }
            else
            {
                printf("INVALID\n");
            }
        }
        else if (digits_calc(cardNumber) == 16)
        {
            if (type_check(cardNumber) == 4)
            {
                printf("VISA\n");
            }
            else if (type_check(cardNumber) >= 51 && type_check(cardNumber) <= 55)
            {
                printf("MASTERCARD\n");
            }
            else
            {
                printf("INVALID\n");
            }
        }
        else
        {
            printf("INVALID\n");
        }
    }
    else
    {
        printf("INVALID\n");
    };
}

int digits_calc(unsigned long long int cardNumber)
{
    int digitNumber = 0;
    while (cardNumber > 9)
    {
        cardNumber = cardNumber / 10;
        digitNumber++;
    }
    return digitNumber + 1;
};

int type_check(unsigned long long int cardNumber)
{
    int i = digits_calc(cardNumber);

    while (cardNumber > 60)
    {
        cardNumber = cardNumber / 10;
    }

    if (cardNumber >= 40 && cardNumber <= 49)
    {
        cardNumber = cardNumber / 10;
        return cardNumber;
    }
    else
    {
        return cardNumber;
    };
};