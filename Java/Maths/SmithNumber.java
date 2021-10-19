
/*
A program to check whether the number input by the user is a Smith number or not.
A Smith Number is a composite number whose sum of digits is equal to the sum of digits in its prime factorization.

Examples:
Input   : n = 666
Output  : Yes
Prime factorization = 2, 3, 3, 37 and
2 + 3 + 3 + (3 + 7) = 6 + 6 + 6 = 18
Therefore, 666 is a smith number.

Input  : n = 6
Output : No
Prime factorization = 2, 3  and 2 + 3 is
not 6. Therefore, 6 is not a smith number.
*/
import java.util.*;

public class SmithNumber {

    // method to check whether the number is composite number or not since all Smith
    // numbers are composite numbers
    boolean isComposite(int num) {
        // Corner cases
        if (num <= 1)
            System.out.println(num + " is not a Smith Number.\n");

        if (num <= 3)
            System.out.println(num + " is not a Smith Number.\n");

        // This is checked so that we can skip
        // middle five numbers in below loop
        if (num % 2 == 0 || num % 3 == 0)
            return true;

        for (int i = 5; i * i <= num; i = i + 6)
            if (num % i == 0 || num % (i + 2) == 0)
                return true;

        return false;
    }

    // method to find the sum of digits
    int sod(int num) {
        int s = 0;
        while (num != 0) {
            int d = num % 10;
            // summing up the digits
            s = s + d;
            num = num / 10;
        }
        // returning the sum of digits to the main method on call
        return s;
    }

    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        // Taking input from user
        System.out.print("\nEnter the number of your choice : ");
        int n = sc.nextInt();

        // Calling instance of object
        SmithNumber obj = new SmithNumber();
        int num = n, s = 0;

        // Checking if number is composite or not
        if (obj.isComposite(num) == false) {
            System.out.println(num + " is not a Smith Number.\n");
        } else {
            for (int i = 2; i <= n; i++) {
                // finding sum of digits of the factors of the number
                if (n % i == 0) {
                    s = s + obj.sod(i);
                    n = n / i;
                    i = 1;
                }
            }

            // finding sum of digits of the number
            if (obj.sod(num) == s)

                // Printing the result if the crietria for Smith number is fulfilled
                System.out.println(num + " is a Smith Number.\n");
            else
                // Printing the result if the crietria for Smith number is not fulfilled
                System.out.println(num + " is not a Smith Number.\n");
        }
        sc.close();
    }
}
