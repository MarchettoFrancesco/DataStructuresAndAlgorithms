package Algorithms;

public class MoveToEnd {
    public static void main(String[] args) {
        int[] array = {1,2,3,4,5,6,7};
        MovePast(array, 2);
        for (int i = 0; i<array.length;i++){
            System.out.println(array[i]);
        }

    }

    /***
     * SBAGLIATO - LASCIA BUCO NEI DISPARI
     * @param A Array not null
     * @param i in A[0,n-1]
     * modifies the array into an array that contains elements from A[i+1] to A[n-1] concatenated with elements
     *          from 0 to A[i]
     */
    public static void MovePast(int A[], int i){
        int n = A.length;
        int k = n-i-1,key;
        while (i >= 0 && n != k){
            key = A[n-1];
            A[n-1] = A[i];
            A[i] = key;
            i--;
            n--;
        }
    }
}
