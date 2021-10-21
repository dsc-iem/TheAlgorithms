
/*
A program to check whether a date input by the user is a valid date or not.

Examples:
24/03/2020 is a valid date.

34/02/2019 is an invalid  date.

30/13/2019 is an invalid date.
*/
import java.util.*;

public class ValidDate {
    // method to check whether a particular year is a leap year or not
    public static boolean leapcheck(int n) {
        // conditions to chck for leap year
        if ((n % 4 == 0 && n % 100 != 0) || (n % 400 == 0))
            return true;
        else
            return false;
    }

    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        // array month to store the number of days in each month of a year
        int month[] = { 0, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31 };

        // Taking input from user
        System.out.print("\nEnter the date(dd/mm/yyyy) to check validity : ");
        String date = sc.nextLine();

        // Extracting the day number, month and year from the date input by the user
        int dd = Integer.parseInt(date.substring(0, 2));
        int mm = Integer.parseInt(date.substring(3, 5));
        int yyyy = Integer.parseInt(date.substring(6));

        // If year input by user is leap year, then the frbruary month will have 29 days
        // else will have 28 days in it.
        if (leapcheck(yyyy) == true)
            month[2] = 29;
        else
            month[2] = 28;

        // Validation check fro date with respect to day number, month and year
        if (mm >= 1 && mm <= 12 && dd >= 1 && dd <= month[mm] && yyyy >= 1000 && yyyy <= 9999)
            System.out.println(date + " is a vaild date.\n");
        else
            // If the date input by the user is an invalid date, then this message is
            // displayed.
            System.out.println(date + " is not a vaild date.\n");
        sc.close();
    }
}
