/**
 * @file
 * \brief Program to check if a number is an [Armstrong/Narcissistic
 * number](https://en.wikipedia.org/wiki/Narcissistic_number) in decimal system.
 *
 * \details
 * Armstrong number or [Narcissistic
 * number](https://en.wikipedia.org/wiki/Narcissistic_number) is a number that
 * is the sum of its own digits raised to the power of the number of digits.
 * @author iamnambiar
 */
#include <cassert>
#include <cmath>
#include <iostream>

/**
 * Function to calculate the total number of digits in the number.
 * @param num Number
 * @return Total number of digits.
 */

/**
* baseline method (with String.length): 2145ms
* log10 method: 711ms = 3.02 times as fast as baseline
* repeated divide: 2797ms = 0.77 times as fast as baseline
* divide-and-conquer: 74ms = 28.99 times as fast as baseline
* Mine is about 4x as fast as the divide-and-conquer solution
*/

int number_of_digits(long long n){
    return (n<100000)?((n<100)?((n<10)?1:2):(n<1000)?3:((n<10000)?4:5)):((n<10000000)?((n<1000000)?6:7):((n<100000000)?8:((n<1000000000)?9:10)));
}

/**
 * Function to check whether the number is armstrong number or not.
 * @param num Number
 * @return `true` if the number is armstrong.
 * @return `false` if the number is not armstrong.
 */
bool is_armstrong(int number) {
    // If the number is less than 0, then it is not a armstrong number.
    if (number < 0) {
        return false;
    }
    int sum = 0;
    int temp = number;
    // Finding the total number of digits in the number
    int total_digits = number_of_digits(number);
    while (temp > 0) {
        int rem = temp % 10;
        // Finding each digit raised to the power total digit and add it to the
        // total sum
        sum = sum + std::pow(rem, total_digits);
        temp = temp / 10;
    }
    return number == sum;
}

/**
 * Function for testing the is_armstrong() function
 * with all the test cases.
 */
void test() {
    // is_armstrong(370) returns true.
    assert(is_armstrong(370) == true);
    // is_armstrong(225) returns false.
    assert(is_armstrong(225) == false);
    // is_armstrong(-23) returns false.
    assert(is_armstrong(-23) == false);
    // is_armstrong(153) returns true.
    assert(is_armstrong(153) == true);
    // is_armstrong(0) returns true.
    assert(is_armstrong(0) == true);
    // is_armstrong(12) returns false.
    assert(is_armstrong(12) == false);
}

/**
 * Main Function
 */
int main() {
    test();
    return 0;
}
