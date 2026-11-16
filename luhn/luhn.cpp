#include <string>
#include "luhn.h"
using namespace std;

bool isValidFormat(string input)
{

    if (input.length() != 16)
    {
        return false;
    }

    for (int i = 0; i < 16; i++)
    {
        if (input[i] < '0' || input[i] > '9')
        {
            return false;
        }
    }

    return true;
}

bool checkLuhn(string number)
{
    int sum = 0;
    int position = 1;

    for (int i = 15; i >= 0; i--)
    {

        int digit = number[i] - '0';

        if (position % 2 == 0)
        {
            digit = digit * 2;

            if (digit > 9)
            {
                digit = digit - 9;
            }
        }

        sum = sum + digit;
        position = position + 1;
    }

    if (sum % 10 == 0)
    {
        return true;
    }
    else
    {
        return false;
    }
}