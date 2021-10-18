
/*
A program to print any 3 digit number entered by the user in it's equivalent word form.

Examples:
32 will be thirty two

21 will be twenty one
*/
import java.util.*;

public class NumberInWords {
    public static void main(String[] args) {
        Scanner ob = new Scanner(System.in);
        // Taking input from user
        System.out.print("\nEnter the number (maximum 3 digits allowed) : ");
        int n = ob.nextInt();

        // Array to store the numbers in words till 19
        String b[] = { "zero", "one", "two", "three", "four", "five", "six", "seven", "eight", "nine", "ten", "eleven",
                "twelve", "thirteen", "fourteen", "fifteen", "sixteen", "seventeen", "eighteen", "nineteen" };

        // Array to store the tens and twentys and so on for displaying the number
        // entered by user
        String c[] = { "zero", "ten", "twenty", "thirty", "forty", "fifty", "sixty", "seventy", "eighty", "ninty" };

        System.out.println("The number is in word form is : ");

        // If number entered by user is less than 19, then directluy accessing array
        // data
        if (n <= 19)
            System.out.println(b[n]);
        else if (n > 19 && n < 100) {
            if (n % 10 == 0)
                // To display the ten twenty and so on ending numbers
                System.out.println(c[n / 10]);
            else
                // Printing the numbers which contains remainders
                System.out.println(c[n / 10] + b[n % 10]);
        }
        // If umber entred is within range but greater than 19
        else if (n <= 999) {
            // Analyzing each cases and displaying the results accordingly
            int m = (n % 100) / 10;
            if (n % 100 == 0)
                System.out.println(b[n / 100] + " hundred.");
            else if (n % 100 <= 19)
                System.out.println(b[n / 100] + " hundred " + b[n % 100] + ".");
            else if (n % 100 == 0)
                System.out.println(b[n / 100] + " hundred " + c[m]);
            else
                System.out.println(b[n / 100] + " hundred and " + c[m] + " " + b[n % 10] + ".");
        } else
            // In case the number specified by the user is not within the range specified
            System.out.println("Not in the range specified to user while entering data!!");
        System.out.println();
        ob.close();
    }
}
