/*
A program to accept two positive integers m and n, where m is less than n as user input. Then display the number of Composite magic 
numbers that are in the range between m and n (both inclusive) and output them along with the frequency.

Composite number:
A composite number is a number that has more than two factors.
For example: 10
Factors are: 1, 2, 5, 10

Magic number:
A magic number is a number in which the eventual sum of the digits is equal to 1
For example: 28=2+8=10=1+0=1
*/

import java.util.*;

public class CompositeMagic {
    // Function to check for Composite number
    boolean isComposite(int n) {
        int count = 0;
        for (int i = 1; i <= n; i++) {
            if (n % i == 0)
                count++;
        }
        if (count > 2)
            return true;
        else
            return false;
    }

    // Function to return sum of digits of a number
    int sod(int n) {
        int s = 0;
        while (n > 0) {
            s = s + n % 10;
            n = n / 10;
        }
        return s;
    }

    // Function to check for Magic number
    boolean isMagic(int n) {
        int a = sod(n);
        while (a > 9) {
            a = sod(a);
        }

        // If eventual sum is 1 then returning true else false
        if (a == 1)
            return true;
        else
            return false;
    }

    public static void main(String[] args) {
        Scanner ob = new Scanner(System.in);
        // Taking the ranges input from the user
        System.out.print("\nEnter the lower limit(m) : ");
        int m = ob.nextInt();
        System.out.print("\nEnter the upper limit(n) : ");
        int n = ob.nextInt();

        CompositeMagic obj = new CompositeMagic();

        // Variable that counts the frequency of the composite magic numbers
        int c = 0;

        if (m < n) {
            System.out.println("\nThe Composite Magic Numbers are: ");
            for (int i = m; i <= n; i++) {
                if (obj.isComposite(i) == true && obj.isMagic(i) == true) {
                    // Printing the first number without any comma
                    if (c == 0)
                        System.out.print(i);
                    else
                        System.out.print(", " + i);
                    // Variable c incrementing on each successfull case of composite magic number
                    c++;
                }
            }
            // Printing the frequency of the Composite Magic Numbers
            System.out.println("\n\nThe frequency of Composite Magic Numbers is : " + c);
        } else
            // Incase the range entered by the user is invalid
            System.out.println("\nINVALID RANGE!!");

        System.out.println();
        ob.close();
    }
}
