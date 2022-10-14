public class BinarySearch {
    //dato A ordinato e k intero trovare k in A O(log n)
    public static void main(String[] args) {
        int[] Aordinato ={1,2,3,4,5,6,7,8,10};
        System.out.println(BinarySearchMethod(Aordinato, 1));
    }


    public static boolean BinarySearchMethod(int A[], int k){ // A ordinato
        if (k >= A[A.length/2]){
            return Cerca( A, k, A.length/2, A.length-1 );
        } else {
            return Cerca(A, k, 0, A.length / 2);
        }
    }


    // RICORSIONE not in place O(logn) but space has the stack of calls may reach logn
    /***
     * Boolean BinarySearch
     * @param A
     * @param k number to search
     * @param a start index, must be 0<=a<=b
     * @param b end index
     * @return false if k isnt in A[0,..,b], otherwise true
     */
    public static boolean Cerca(int A[], int k, int a, int b){
        if (a==b){
            return (A[a] == k);
        }
        else {
            int r = (a+b)/2;
            if (A[r] == k){
                return true;
            } else if (A[r] > k){
                return Cerca(A,k,a,r);
            } else {
                return Cerca(A,k,r+1,b);
            }
        }
    }

    // ITERAZIONE inplace O(logn) extra space O(1)

    /***
     * Position Binary search Iterative
     * @param A
     * @param k Number to search
     * @return position of k if it is in A[0,..A.length-1], -1 otherwise
     */
    public static int searchIteration(int A[], int k){
        int a = 0, b = A.length-1, media;

        while (a<=b){
            media = (A.length % 2 == 0)?  a+b/2 : (a+b+1)/2;
            if (k == A[media]) {
                return media;
            }else if(k > A[media]){
                a = media+1;
            } else{
                b = media-1;
            }
        }
        return -1;
    }
}
