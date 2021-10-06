import java.util.*;

class StrassenMatrixAlgorithm {
    public int[][] padArray(int[][] arr, int numOfPads) {
        int[][] temp = new int[arr.length + numOfPads][arr[0].length + numOfPads];
        for (int i = 0; i < temp.length; i++) {
            for (int j = 0; j < temp[i].length; j++)
                temp[i][j] = 0;
        }
        for (int i = 0; i < arr.length; i++) {
            for (int j = 0; j < arr[i].length; j++)
                temp[i + numOfPads][j + numOfPads] = arr[i][j];
        }
        return temp;
    }

    public int[][] sub(int[][] A, int[][] B) {
        int n = A.length;
        int[][] C = new int[n][n];
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++)
                C[i][j] = A[i][j] - B[i][j];
        }
        return C;
    }

    public int[][] add(int[][] A, int[][] B) {
        int n = A.length;
        int[][] C = new int[n][n];
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++)
                C[i][j] = A[i][j] + B[i][j];
        }
        return C;
    }

    public void split(int[][] P, int[][] C, int iB, int jB) {
        for (int i1 = 0, i2 = iB; i1 < C.length; i1++, i2++) {
            for (int j1 = 0, j2 = jB; j1 < C.length; j1++, j2++)
                C[i1][j1] = P[i2][j2];
        }
    }

    public void join(int[][] C, int[][] P, int iB, int jB) {
        for (int i1 = 0, i2 = iB; i1 < C.length; i1++, i2++) {
            for (int j1 = 0, j2 = jB; j1 < C.length; j1++, j2++)
                P[i2][j2] = C[i1][j1];
        }
    }

    public int[][] multiply(int[][] A, int[][] B) {
        int n = A.length;
        int[][] R = new int[n][n];
        if (n == 1)
            R[0][0] = A[0][0] * B[0][0];
        else {
            int[][] A11 = new int[n / 2][n / 2];
            int[][] A12 = new int[n / 2][n / 2];
            int[][] A21 = new int[n / 2][n / 2];
            int[][] A22 = new int[n / 2][n / 2];
            int[][] B11 = new int[n / 2][n / 2];
            int[][] B12 = new int[n / 2][n / 2];
            int[][] B21 = new int[n / 2][n / 2];
            int[][] B22 = new int[n / 2][n / 2];
            split(A, A11, 0, 0);
            split(A, A12, 0, n / 2);
            split(A, A21, n / 2, 0);
            split(A, A22, n / 2, n / 2);
            split(B, B11, 0, 0);
            split(B, B12, 0, n / 2);
            split(B, B21, n / 2, 0);
            split(B, B22, n / 2, n / 2);
            int[][] M1 = multiply(add(A11, A22), add(B11, B22));
            int[][] M2 = multiply(add(A21, A22), B11);
            int[][] M3 = multiply(A11, sub(B12, B22));
            int[][] M4 = multiply(A22, sub(B21, B11));
            int[][] M5 = multiply(add(A11, A12), B22);
            int[][] M6 = multiply(sub(A21, A11), add(B11, B12));
            int[][] M7 = multiply(sub(A12, A22), add(B21, B22));
            int[][] C11 = add(sub(add(M1, M4), M5), M7);
            int[][] C12 = add(M3, M5);
            int[][] C21 = add(M2, M4);
            int[][] C22 = add(sub(add(M1, M3), M2), M6);
            join(C11, R, 0, 0);
            join(C12, R, 0, n / 2);
            join(C21, R, n / 2, 0);
            join(C22, R, n / 2, n / 2);
        }
        return R;
    }

    public static void main(String[] args) {
        System.out.println("\nStrassen Multiplication Algorithm Implementation For Matrix Multipication :\n\n");
        Scanner ob = new Scanner(System.in);
        StrassenMatrixAlgorithm obj = new StrassenMatrixAlgorithm();
        System.out.print("Enter the order of the 1st square matrix: ");
        int n = ob.nextInt();
        System.out.print("Enter the order of the 2nd square matrix: ");
        int m = ob.nextInt();
        if (n != m)
            System.out.println("Matrix multiplication is not faeasible!");
        else {
            int[][] a = new int[n][n];
            int[][] b = new int[m][m];
            System.out.println("\nEnter the elements of the 1st square matrix :\n");
            for (int i = 0; i < n; i++) {
                for (int j = 0; j < n; j++) {
                    System.out.print("Enter the number : ");
                    a[i][j] = ob.nextInt();
                }
            }
            System.out.println("\nEnter the elements of the 2nd square matrix :\n");
            for (int i = 0; i < n; i++) {
                for (int j = 0; j < n; j++) {
                    System.out.print("Enter the number : ");
                    b[i][j] = ob.nextInt();
                }
            }
            System.out.println("\nMatrix 1 is :\n");
            for (int i = 0; i < n; i++) {
                for (int j = 0; j < n; j++)
                    System.out.print(a[i][j] + "\t");
                System.out.println();
            }
            System.out.println("\nMatrix 2 is :\n");
            for (int i = 0; i < n; i++) {
                for (int j = 0; j < n; j++)
                    System.out.print(b[i][j] + "\t");
                System.out.println();
            }
            int k = 0;
            while (Math.pow(2, k) < n) {
                k++;
            }
            int inc;
            int[][] e;
            if ((int) Math.pow(2, k) > n) {
                inc = (int) Math.pow(2, k) - n;
                int[][] c = obj.padArray(a, inc);
                int[][] d = obj.padArray(b, inc);
                System.out.println("\nMatrix 1 after padding is :\n");
                for (int i = 0; i < n + inc; i++) {
                    for (int j = 0; j < n + inc; j++)
                        System.out.print(c[i][j] + "\t");
                    System.out.println();
                }
                System.out.println("\nMatrix 2 after padding is :\n");
                for (int i = 0; i < n + inc; i++) {
                    for (int j = 0; j < n + inc; j++)
                        System.out.print(d[i][j] + "\t");
                    System.out.println();
                }
                e = obj.multiply(c, d);
                System.out.println("\nFinal Product Matrix is :\n");
                for (int i = 0; i < n + inc; i++) {
                    for (int j = 0; j < n + inc; j++)
                        System.out.print(e[i][j] + "\t");
                    System.out.println();
                }
            } else {
                e = obj.multiply(a, b);
                System.out.println("\nFinal Product Matrix is :\n");
                for (int i = 0; i < n; i++) {
                    for (int j = 0; j < n; j++)
                        System.out.print(e[i][j] + "\t");
                    System.out.println();
                }
            }
        }
        System.out.println();
        ob.close();
    }
}
