/*
A program to print the Kaprekar numbers within a specified range and also show the frequency of the kaprekar numbers present within that range.
A Kaprekar number is a number whose square when divided into two parts and such that sum of parts is equal to the original number and none of the parts has value 0.
Example:
Input :  n = 45  
Output : Kaprekar number
Explanation : 45^2 = 2025 and 20 + 25 is 45
*/

import java.util.*;

public class KaprekarNumbers {
    // method to check whether a particular number is kaprekar number or not
    public static boolean isKap(int n) {
        int cop = n;
        int cop2 = n * n; // square of the number taken from the user
        int d = 1;
        // checking the number of didgits of the square of the numbers so that it can be
        // separated into two halves to b summed up
        while (cop > 0) {
            d *= 10;
            cop = cop / 10;
        }
        int r = cop2 / d;
        int t = cop2 % d;
        int s = r + t;
        // If the added number is same as the input number, then it is a kaprekar number
        if (s == n)
            return true;
        else
            // If the number formed by adding is not same as the input number
            return false;
    }

    public static void main(String[] args) {
        Scanner ob = new Scanner(System.in);
        // Taking lower limit input from user
        System.out.print("\nEnter the lower limit : ");
        int p = ob.nextInt();
        System.out.print("\nEnter the upper limit : ");
        int q = ob.nextInt();
        int v = 0;

        // Printing all kaprekar numbers within the particular range specified by user
        System.out.println("\nThe Kaprekar numbers between " + p + " and " + q + " are : ");
        for (int i = p; i <= q; i++) {
            if (isKap(i) == true) {
                System.out.print(i + " ");
                // Incrementing the value of v to find the frequesncy of kaprekar numbers
                v++;
            }
        }
        // Displaying the frequency of kaprekar numbers found within that range
        System.out.println("\n\nFrequency of Kaprekar numbers is : " + v);
        System.out.println();
        ob.close();
    }
}
