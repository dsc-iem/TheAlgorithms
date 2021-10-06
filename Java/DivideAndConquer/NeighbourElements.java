/*
Finding out the neighbours of the median element in an array using partitioning strategy of Quick-Sorting method.
Here we use Quick Sort algorithm to array the array inserted by the user to find the median element in the sorted array and find out
the neighbours of the median element. If even number of elements present within the array, then will show the elements forming
the median else will show the neighbour elements of the median element of the array having odd number of elements.
Here Divide and Conquer algorithm is used since quick sort uses it to sort the array first by splitting, then combining to form the
resultant sorted array. 
In partition we randomly choose an elemnt as pivot to place all the elemnrts smaller than it before it and all the elements greater
than it after the pivot element, thereby sorting the array. Here we have started with teh last element in the array as pivot.
*/

import java.util.*;

public class NeighbourElements {

    // Utility function to swapping of element
    public void swap(int[] arr, int i, int j) {
        int temp = arr[i];
        arr[i] = arr[j];
        arr[j] = temp;
    }

    // Returns the correct position of pivot element
    public int partition(int[] arr, int low, int high) {
        int pivot = arr[high];
        int i = (low - 1);
        for (int j = low; j <= high - 1; j++) {
            if (arr[j] < pivot) {
                i++;
                swap(arr, i, j);
            }
        }
        swap(arr, i + 1, high);
        return (i + 1);
    }

    // The recursive call to be applied on the array and the sub parts of the array
    // untill a single element is reached to sort the array
    public void quickSort(int[] arr, int low, int high) {
        if (low < high) {
            // Finding out the pivot point
            int pi = partition(arr, low, high);
            // Applying recursive method quickSort on the sub array of elements before the
            // pivot that is smaller than pivot element
            quickSort(arr, low, pi - 1);
            // Applying recursive method quickSort on the sub array of elements after the
            // pivot that is greater than pivot element
            quickSort(arr, pi + 1, high);
        }
    }

    // Returns the array passed to it as arguments, with elements separated by a tab
    // space
    public void printArray(int[] arr, int size) {
        for (int i = 0; i < size; i++)
            System.out.print(arr[i] + "\t");
        System.out.println();
    }

    public static void main(String[] args) {
        Scanner ob = new Scanner(System.in);

        // Creating object instance of the NeighbourElements class to use the methods in
        // it
        NeighbourElements obj = new NeighbourElements();
        System.out.println();

        // Inputting size of the array
        System.out.print("Enter the size of array : ");
        int n = ob.nextInt();
        int[] a = new int[n];

        // Inputting elements into the array
        for (int i = 0; i < n; i++) {
            System.out.print("Enter  the number : ");
            a[i] = ob.nextInt();
        }

        // Printing the original array formed
        System.out.println("\nArray formed : ");
        obj.printArray(a, n);

        // Applying Quick Sort on the array to sort it
        obj.quickSort(a, 0, n - 1);

        // Printing the sorted array formed after Quick SOrt
        System.out.println("Sorted Array formed : ");
        obj.printArray(a, n);

        if (n % 2 == 0) {
            // If even number of elements present within the array, then will show the
            // elements forming the median
            System.out.println("\nEven number of elements present in the array.");
            System.out.println("Two elements forming the median are : " + a[n / 2] + " and " + a[n / 2 - 1]);
        } else {
            // If odd number of elements present within the array, then will show the two
            // neighbour elements of the median
            System.out.println("\nOdd number of elements present in the array.");
            System.out.println("The median element is : " + a[n / 2]);
            System.out.println("The neighbours of the median element are : " + a[n / 2 - 1] + " and " + a[n / 2 + 1]);
        }
        System.out.println();
        ob.close();
    }
}
