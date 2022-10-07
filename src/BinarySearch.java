public class BinarySearch {
    //dato A ordinato e k intero trovare k in A O(log n)
    public static void main(String[] args) {
        int[] Aordinato ={1,2,3,4,5,6,7,8,10};
        System.out.println(searchIteration(Aordinato, 8));
    }


    // RICORSIONE
    public static int BinarySearch(int A[], int k){ // A ordinato
        if (k >= A[A.length/2]){
            return searchRecursion( A, k, A.length/2, A.length-1 );
        } else {
            return searchRecursion(A, k, 0, A.length / 2);
        }
    }
    public static int searchRecursion(int A[], int k, int a, int b){
        if (b-a == 1 && k != A[a] && k != A[b]){
            return -1;
        }
        else if (k == A[(a+b)/2]){
            return (a+b)/2;
        } else {
            if (k > A[(a+b)/2]){
                return searchRecursion(A,k,(a+b)/2+1,b);
            } else {
                return searchRecursion(A,k,a,(a+b)/2-1);
            }
        }
    }

    // ITERAZIONE

    public static int searchIteration(int A[], int k){
        int a = 0, b = A.length-1, risultato = 0, media;

        while (a<b){
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
