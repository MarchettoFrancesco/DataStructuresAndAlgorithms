package Algorithms;

public class SelectionSort {

    public static void main(String[] args) {
        int[] s = {1,3,4,2,5,10,6};

        for (int i : Selection(s)) {
            System.out.print(i);
            System.out.print(", ");
        }

    }
    // complexity always O(n^2) ma n swaps

    /**
     * 
     * @param A Array of ints, can be unordered
     * @return ordered array, finds the minimum in an inside group and moves it to the left multiple times
     */
    public static int[] Selection(int[] A){
        int key = 0;
        for (int i = 0; i<A.length-1; i++){
            int min = i;
            for (int j = i+1; j<A.length; j++){
                if (A[j] < A[min]){
                    min = j;
                }
            }
            if (min != i){
                 key = A[i];
                 A[i] = A[min];
                 A[min] = key;
            }
        }
        return A;
    }
}