/*
Designing a class to represent a Basic Banking System Account that includes the following things:

Fields
• Name of the depositor
• Address of the depositor
• Account number
• Balance amount in the account

Methods
• To assign initial values
• To deposit an amount
• To withdraw an amount after checking balance
• To display the name, address, and balance of a customer
• Imposing penalty on customer in case the amount present in bank is lower than the minimum amount.

This program mainly works as the admin side of the bank, where the admin can regulate all the fields of the customers it has.
*/

import java.util.*;

class BasicBankSystem {
    // The fields that an account holder in the bank should have like name, address,
    // account number and balance
    String name, address;
    int account;
    double balance;

    // Initializing values with Constructor
    BasicBankSystem(String n, String ad, int a, double b) {
        name = n;
        address = ad;
        account = a;
        balance = b;
    }

    // Function to deposit amount into the particular account of a customer
    public void deposit(double dep) {
        balance += dep;
        // Displaying the amount present after depositing amount
        System.out.println("Amount present in account : Rs " + balance);
    }

    // Function to withdraw amount from the particular account of a customer and
    // imposing penalty in case amount goes below minimum amount of Rs 450.0
    public void withdraw(double amt) {
        if (amt > balance) {
            // In case user tries to withdarw an amount greater than the amount present in
            // his or her account
            System.out.println("Withdraw amount greater than amount present!");
        } else {
            balance -= amt;
            // Displaying the amount present after withdrawing amount
            System.out.println("Amount present in account : Rs " + balance);
            if (balance < 450.0) {
                // Imposing a penalty of Rs 100.0 incase the amount in account goes below thee
                // minimum amount of Rs 450.0
                System.out.println("Penalty of Rs 100.0 imposed");
                balance -= 100.0;
                System.out.println("Amount after penalty : Rs " + balance);
            }
        }
    }

    public void display() {
        // Displaying the details of the customer
        System.out.println(
                "Name of customer is : " + name + ", has address : " + address + ", and has amount of : Rs " + balance);
    }

    public static void main(String[] args) {
        // Integer to assign user with an account number
        int i = -1;
        // Declaring an array of objects having maximum capacity of 1000 users
        BasicBankSystem[] newac = new BasicBankSystem[1000];
        Scanner ob = new Scanner(System.in);
        Scanner ob1 = new Scanner(System.in);
        // Calling an infinite loop to keep iterating untill user wants to exit the
        // application
        while (true) {
            System.out.println("\nWelcome to our Banking System!!\n");
            // Giving options to the user to choose one at a time
            System.out.println("\nEnter 1. To create account");
            System.out.println("Enter 2. To deposit amount");
            System.out.println("Enter 3. To withdraw amount and check balance");
            System.out.println("Enter 4. To display customer details");
            System.out.println("Enter 5. To exit");
            // Taking choice input from the user
            System.out.print("\nEnter your choice: ");
            int ch = ob.nextInt();
            System.out.println();
            // Using switch case to perform actions based on the particular choice
            switch (ch) {
                case 1:
                    // Taking basic details from the customer for creating account and depositing
                    // amount
                    System.out.println("Enter name: ");
                    String nm = ob1.nextLine();
                    System.out.println("Enter address: ");
                    String add = ob1.nextLine();
                    System.out.println("Enter amount to start: ");
                    double am = ob.nextDouble();
                    if (am >= 450.0) {
                        // Successfull creation of account
                        i += 1;
                        newac[i] = new BasicBankSystem(nm, add, i, am);
                        System.out.println("Your account is created and your account number is: " + i);
                    } else {
                        // In case user tries to open an account with an amount less tahn the minimum
                        // amount of Rs 450.0, error message displayed
                        System.out.println("Sorry! Minimum balance to create account is Rs 450.0");
                    }
                    break;

                case 2:
                    // Taking account number input from user to deposit amount
                    System.out.println("Enter account number: ");
                    int acc = ob.nextInt();
                    int f = -1;
                    if (i == -1) {
                        // In case no user is present in the bank
                        System.out.println("No such account numer exists in records!");
                    } else {
                        for (int j = 0; j <= i; j++) {
                            if (newac[j].account == acc) {
                                f = j;
                                break;
                            }
                        }

                        if (f != -1) {
                            // Entering amount to deposit from user
                            System.out.println("Enter amount to deposit: ");
                            double dp = ob.nextDouble();
                            newac[f].deposit(dp);
                        } else {
                            // In case the particular account number is not allocated to any person in the
                            // bank
                            System.out.println("No such account numer exists in records!");
                        }
                    }
                    break;

                case 3:
                    // Taking account number input from user to withdraw amount
                    System.out.println("Enter account number: ");
                    int acs = ob.nextInt();
                    int fl = -1;
                    if (i == -1) {
                        // In case no user is present in the bank
                        System.out.println("No such account numer exists in records!");
                    } else {
                        for (int j = 0; j <= i; j++) {
                            if (newac[j].account == acs) {
                                fl = j;
                                break;
                            }
                        }

                        if (fl != -1) {
                            // Dispalying amount before withdrawing amount from account
                            System.out.println("User balance present: Rs " + newac[fl].balance);
                            if (newac[fl].balance < 450.0) {
                                System.out.println(
                                        // In case the balance in the account is less than the minimum balance of Rs
                                        // 450.0
                                        "Sorry your current balance is less than the minimum balance Rs 450.0. Please deposit some amount in your account before withdrawing!!");
                            } else {
                                // Entering amount to withdraw from user
                                System.out.println("Enter amount to withdraw: ");
                                double wd = ob.nextDouble();
                                // Withdrawing the amount requested for
                                newac[fl].withdraw(wd);
                            }
                        } else {
                            // In case the particular account number is not allocated to any person in the
                            // bank
                            System.out.println("No such account numer exists in records!");
                        }
                    }
                    break;

                case 4:
                    // Taking account number input from user to display details of the particular
                    // account
                    System.out.println("Enter account number: ");
                    int acd = ob.nextInt();
                    int fld = -1;
                    if (i == -1) {
                        // In case no user is present in the bank
                        System.out.println("No such account numer exists in records!");
                    } else {
                        for (int j = 0; j <= i; j++) {
                            if (newac[j].account == acd) {
                                fld = j;
                                break;
                            }
                        }

                        if (fld != -1) {
                            // Dispalying the details of the customer
                            newac[fld].display();
                        } else {
                            // In case the particular account number is not allocated to any person in the
                            // bank
                            System.out.println("No such account numer exists in records!");
                        }
                    }
                    break;

                case 5:
                    // In case the user wants to exit the banking system
                    System.out.println("\nThankyou for using our banking services!!\n");
                    System.exit(1);
                    ob.close();
                    ob1.close();
                    break;

                default:
                    // In case user tries to choose any otehr choice different from the options he
                    // is provided with
                    System.out.println("\nWrong choice.. Please choose among the options given!");
            }
        }
    }
}