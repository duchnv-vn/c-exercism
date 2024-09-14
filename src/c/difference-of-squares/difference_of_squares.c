#include "difference_of_squares.h"
#include "math.h"

unsigned int sum_of_squares(unsigned int number)
{
    unsigned int sum = 0;

    for (unsigned i = 1; i <= number; i++)
    {
        sum += pow(i, 2);
    }

    return sum;
}

unsigned int square_of_sum(unsigned int number)
{
    unsigned int sum = 0;

    for (unsigned int i = 1; i <= number; i++)
    {
        sum += i;
    }

    return pow(sum, 2);
}

unsigned int difference_of_squares(unsigned int number)
{
    unsigned int sumOfSquare = 0;
    unsigned int squareOfSum = 0;

    for (unsigned int i = 1; i <= number; i++)
    {
        sumOfSquare += pow(i, 2);
        squareOfSum += i;
    }

    return pow(squareOfSum, 2) - sumOfSquare;
}
