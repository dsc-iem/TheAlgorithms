/*
In linear algebra, the Strassen algorithm, named after Volker Strassen, is an algorithm for matrix multiplication. It is faster than the standard matrix multiplication algorithm for large matrices, with a better asymptotic complexity, although the naive algorithm is often better for smaller matrices. 
The idea of Strassen’s method is to reduce the number of recursive calls to 7.
It follows divide and conquer approach to split  the matrices to sub matrices, apply recursive call on each sub matrix and finally combine them to form the final matrix.
In case the matrices are not of the order of the power of 2, then padding of zeros is performed to make the order of the power of 2 so that splitting and combining of mtrices can take place.
The multiplication only occurs for square matrices.
Both the matrices need to be of the same order in oredre to make the matrix multiplication feasible.

The following formulaes are used to solve the recursive calls of the multiplication:
M1:=(A1+A3)×(B1+B2)
M2:=(A2+A4)×(B3+B4)
M3:=(A1−A4)×(B1+A4)
M4:=A1×(B2−B4)
M5:=(A3+A4)×(B1)
M6:=(A1+A2)×(B4)
M7:=A4×(B3−B1)

Then,

P:=M2+M3−M6−M7
Q:=M4+M6
R:=M5+M7
S:=M1−M3−M4−M5
*/

import java.util.*;

class StrassenMatrixAlgorithm {
    // This function is used to pad the matrix with zeros in case the order of the
    // matrix entered is not in the power of 2 and make it of the order of power of
    // 2.
    public int[][] padArray(int[][] arr, int numOfPads) {
        int[][] temp = new int[arr.length + numOfPads][arr[0].length + numOfPads];
        for (int i = 0; i < temp.length; i++) {
            for (int j = 0; j < temp[i].length; j++)
                // Padding new matrix with zeros first
                temp[i][j] = 0;
        }
        for (int i = 0; i < arr.length; i++) {
            for (int j = 0; j < arr[i].length; j++)
                // Inserting elements from the matrix after padding of zeros completed
                temp[i + numOfPads][j + numOfPads] = arr[i][j];
        }
        return temp;
    }

    // Function to subtract two matrices
    public int[][] sub(int[][] A, int[][] B) {
        int n = A.length;
        int[][] C = new int[n][n];
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++)
                // Subtracting corresponding elements of matrices
                C[i][j] = A[i][j] - B[i][j];
        }
        return C;
    }

    // Function to add two matrices
    public int[][] add(int[][] A, int[][] B) {
        int n = A.length;
        int[][] C = new int[n][n];
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++)
                // Adding corresponding elements of matrices
                C[i][j] = A[i][j] + B[i][j];
        }
        return C;
    }

    // Function to split parent matrix into child matrices
    public void split(int[][] P, int[][] C, int iB, int jB) {
        for (int i1 = 0, i2 = iB; i1 < C.length; i1++, i2++) {
            for (int j1 = 0, j2 = jB; j1 < C.length; j1++, j2++)
                C[i1][j1] = P[i2][j2];
        }
    }

    // Function to join child matrices into parent matrix
    public void join(int[][] C, int[][] P, int iB, int jB) {
        for (int i1 = 0, i2 = iB; i1 < C.length; i1++, i2++) {
            for (int j1 = 0, j2 = jB; j1 < C.length; j1++, j2++)
                P[i2][j2] = C[i1][j1];
        }
    }

    // Function to multiply matrices
    public int[][] multiply(int[][] A, int[][] B) {
        int n = A.length;
        int[][] R = new int[n][n];
        // If there is only single element
        if (n == 1)
            // Returning the simple multiplication of two elements in matrices
            R[0][0] = A[0][0] * B[0][0];
        else {
            // Step 1: Dividing Matrix into parts by storing sub-parts to variables
            int[][] A11 = new int[n / 2][n / 2];
            int[][] A12 = new int[n / 2][n / 2];
            int[][] A21 = new int[n / 2][n / 2];
            int[][] A22 = new int[n / 2][n / 2];
            int[][] B11 = new int[n / 2][n / 2];
            int[][] B12 = new int[n / 2][n / 2];
            int[][] B21 = new int[n / 2][n / 2];
            int[][] B22 = new int[n / 2][n / 2];

            // Step 2: Dividing matrix A into 4 halves
            split(A, A11, 0, 0);
            split(A, A12, 0, n / 2);
            split(A, A21, n / 2, 0);
            split(A, A22, n / 2, n / 2);

            // Step 2: Dividing matrix B into 4 halves
            split(B, B11, 0, 0);
            split(B, B12, 0, n / 2);
            split(B, B21, n / 2, 0);
            split(B, B22, n / 2, n / 2);

            // Using Formulas as described in algorithm

            // M1:=(A1+A3)×(B1+B2)
            int[][] M1 = multiply(add(A11, A22), add(B11, B22));

            // M2:=(A2+A4)×(B3+B4)
            int[][] M2 = multiply(add(A21, A22), B11);

            // M3:=(A1−A4)×(B1+A4)
            int[][] M3 = multiply(A11, sub(B12, B22));

            // M4:=A1×(B2−B4)
            int[][] M4 = multiply(A22, sub(B21, B11));

            // M5:=(A3+A4)×(B1)
            int[][] M5 = multiply(add(A11, A12), B22);

            // M6:=(A1+A2)×(B4)
            int[][] M6 = multiply(sub(A21, A11), add(B11, B12));

            // M7:=A4×(B3−B1)
            int[][] M7 = multiply(sub(A12, A22), add(B21, B22));

            // P:=M2+M3−M6−M7
            int[][] C11 = add(sub(add(M1, M4), M5), M7);

            // Q:=M4+M6
            int[][] C12 = add(M3, M5);

            // R:=M5+M7
            int[][] C21 = add(M2, M4);

            // S:=M1−M3−M4−M5
            int[][] C22 = add(sub(add(M1, M3), M2), M6);

            // Step 3: Joining 4 halves into one result matrix
            join(C11, R, 0, 0);
            join(C12, R, 0, n / 2);
            join(C21, R, n / 2, 0);
            join(C22, R, n / 2, n / 2);
        }

        // Step 4: Returning result
        return R;
    }

    public static void main(String[] args) {
        System.out.println("\nStrassen Multiplication Algorithm Implementation For Matrix Multipication :\n\n");
        // Inputting via Scanner class
        Scanner ob = new Scanner(System.in);
        // Creating object of the StrassenMatrixAlgorithm class
        StrassenMatrixAlgorithm obj = new StrassenMatrixAlgorithm();
        System.out.print("Enter the order of the 1st square matrix: ");
        // Entering oredr of first square matrx
        int n = ob.nextInt();
        System.out.print("Enter the order of the 2nd square matrix: ");
        // Entering oredr of second square matrx
        int m = ob.nextInt();

        // If the orders of both the matrices do not match, then matrix multiplication
        // is not feasible
        if (n != m)
            System.out.println("Matrix multiplication is not faeasible!");
        else {
            // Matrix A created
            int[][] a = new int[n][n];

            // Matrix B created
            int[][] b = new int[m][m];

            // Entering elements for the 1st square matrix
            System.out.println("\nEnter the elements of the 1st square matrix :\n");
            for (int i = 0; i < n; i++) {
                for (int j = 0; j < n; j++) {
                    System.out.print("Enter the number : ");
                    a[i][j] = ob.nextInt();
                }
            }

            // Entering elements for the 2nd square matrix
            System.out.println("\nEnter the elements of the 2nd square matrix :\n");
            for (int i = 0; i < n; i++) {
                for (int j = 0; j < n; j++) {
                    System.out.print("Enter the number : ");
                    b[i][j] = ob.nextInt();
                }
            }

            // Displaying the first square matrix
            System.out.println("\nMatrix 1 is :\n");
            for (int i = 0; i < n; i++) {
                for (int j = 0; j < n; j++)
                    System.out.print(a[i][j] + "\t");
                System.out.println();
            }

            // Displaying the second square matrix
            System.out.println("\nMatrix 2 is :\n");
            for (int i = 0; i < n; i++) {
                for (int j = 0; j < n; j++)
                    System.out.print(b[i][j] + "\t");
                System.out.println();
            }
            int k = 0;

            // If matrix not of the order of power of 2, calculating nuber of rows and
            // columns to pad with zeros
            while (Math.pow(2, k) < n) {
                k++;
            }
            int inc;
            int[][] e;
            if ((int) Math.pow(2, k) > n) {
                inc = (int) Math.pow(2, k) - n;
                // Padding matrix A with zeros
                int[][] c = obj.padArray(a, inc);

                // Padding matrix B with zeros
                int[][] d = obj.padArray(b, inc);

                // Displaying Matrix 1 after padding
                System.out.println("\nMatrix 1 after padding is :\n");
                for (int i = 0; i < n + inc; i++) {
                    for (int j = 0; j < n + inc; j++)
                        System.out.print(c[i][j] + "\t");
                    System.out.println();
                }

                // Displaying Matrix 2 after padding
                System.out.println("\nMatrix 2 after padding is :\n");
                for (int i = 0; i < n + inc; i++) {
                    for (int j = 0; j < n + inc; j++)
                        System.out.print(d[i][j] + "\t");
                    System.out.println();
                }

                // Matrix e calling multiply method to get Result in case padding is required
                e = obj.multiply(c, d);
                System.out.println("\nFinal Product Matrix is :\n");
                for (int i = 0; i < n + inc; i++) {
                    for (int j = 0; j < n + inc; j++)
                        // Printing elements of resultant matrix separated by a tab space
                        System.out.print(e[i][j] + "\t");
                    // New line once the all elements are printed for specific row
                    System.out.println();
                }
            } else {
                // Matrix e calling multiply method to get Result in case padding is not
                // required
                e = obj.multiply(a, b);
                System.out.println("\nFinal Product Matrix is :\n");
                for (int i = 0; i < n; i++) {
                    for (int j = 0; j < n; j++)
                        // Printing elements of resultant matrix separated by a tab space
                        System.out.print(e[i][j] + "\t");
                    // New line once the all elements are printed for specific row
                    System.out.println();
                }
            }
        }
        System.out.println();
        ob.close();
    }
}
