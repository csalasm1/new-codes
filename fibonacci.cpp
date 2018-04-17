#include <iostream>

int fibonacci(int number)
{
    if (number == 0)
        return 0; // base case (termination condition)
    if (number == 1)
        return 1; // base case (termination condition)
    return fibonacci(number-1) + fibonacci(number-2);
}

// And a main program to display the first 13 Fibonacci numbers
int main()
{
    std:: cout << fibonacci(20) << " ";
    for (int count=0; count < 21; ++count)
        std:: cout << fibonacci(count) << " ";


    return 0;
}
