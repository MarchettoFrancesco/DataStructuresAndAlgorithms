public class MajorityElement {
    public static void main(String[] args) {
        int[] risultatoElezioni = {1,1,2,2,1,3,3,2,2,2,2};
        System.out.println(MajorityElement1(risultatoElezioni));
        System.out.println(MajorityElement(risultatoElezioni));
    }

    /*
    Boyer Moore Voting Algorithm expanded to every case

    precondition: array of numbers representing groups, can be unordered, and repeated
    post: returns -1 if there is no 50% +1 and returns the group number if it exists

    @param count number of times a group is voted
    @param major the group that has the most votes

    expanded boyer moore, with a check, if the major is more than half of the array size then the major is true
    if not return -1

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
        count = 0;
        for (int i = 0; i<A.length;i++){
            if (A[i] == major){
                count++;
            }
        }
        if (count > A.length/2 ){
            return major;
        } else {
            return -1;
        }
    }
    /*
     Boyer Moore Voting Algorithm

     @param precondition: array given are numbers representing groups
             only if there is someone that has 50% +1 votes the algorithm will give the correct answer
             its efficient because it is linear and require O(1) space extra but it is inpractical because
             if the group with most votes isnt above the 50%+1 the algorithm isn't correct
    */

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
