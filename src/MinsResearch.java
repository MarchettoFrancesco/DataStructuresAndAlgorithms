public class MinsResearch {


    public static void main(String[] args) {
        // int[] s = {1,4,5,2,6,7,8,9,3};
        int[] a ={2,1,3};
        System.out.println(MinsResearchMethod(a));
    }

     /**
      * Minimum and second minimum research
      * @param A given an array of numbers, order not important
      * @return the algo returns the min and sec. min
      */
    public static String MinsResearchMethod(int[] A){
        int min1 = A[0];
        int min2 = A[1];
        int i = 2;

        if (A.length < 2)
        {
            return "Array size less than two.";
        }

        while(i < A.length){
            if (A[i] > min1 && A[i] < min2){
                min2 = A[i];
            } else if(A[i] < min2){
                min1 = A[i];
            }
            i++;
        }

        return " " + min1 + " " + min2;
    }
}
