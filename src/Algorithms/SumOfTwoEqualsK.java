package Algorithms;

public class SumOfTwoEqualsK {

    public static void main(String[] args) {
        int[] array = {1,2,3,4,5,6,7,8,9};
        System.out.println(SumOfTwoEqualsToK(array, 17));
    }

    /***
     *  DA RIVEDERE
     * @param A Ordered
     * @param k
     * @return
     */
    public static String SumOfTwoEqualsToK(int[] A, int k) {


        for (int i = 0; i<=A.length-1;i++) {
            int n = A.length-1;
            while (n>i) {
                if (A[i] + A[n] == k) {
                    return i + " " + n;
                } else if (A[i] + A[n] > k) {
                    n--;
                } else {
                    n = i;
                }
            }
        }
        return "There are no elements which sum is equals to k";
    }
}
