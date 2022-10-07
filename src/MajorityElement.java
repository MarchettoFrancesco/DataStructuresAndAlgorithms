public class MajorityElement {
    public static void main(String[] args) {
        int[] risultatoElezioni = {1,1,2,2,1,3,3,1,1,1,1};
        System.out.println(MajorityElement1(risultatoElezioni));
        System.out.println(MajorityElement(risultatoElezioni));

    }

    /*
    ------ Da rivedere ------

    Boyer Moore Voting Algorithm

    @param precondition: array given are numbers representing groups
          only if there is someone that has 50% +1 votes the algorithm will give the correct answer
          its efficient because it is linear and require O(1) space extra but it is inpractical because
          if the group with most votes isnt above the 50%+1 the algorithm isn't correct
     */
    public static int MajorityElement(int[] A){
        int major = A[0];
        int count = 0;
        for (int i = 0; i < A.length; i++){
            if (A[i] == major){
                count++;
            }
                count--;
                if (count == 0){
                    major = A[i];
                    count = 1;
                }
            }

        return major;
    }
    //
    public static int MajorityElement1(int[] A) {
        int major = 0;
        int count = 0;
        for (int i = 0; i < A.length; i++) {
            if (count == 0) {
                major = A[i];
            }
            count += (A[i] == major) ? 1 : -1;

        }
        return major;
    }



}
