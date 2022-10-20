package Tests;
import Algorithms.MajorityElement;
import org.junit.jupiter.api.Assertions;
import org.junit.jupiter.api.Test;

import static org.junit.jupiter.api.Assertions.*;
class MajorityElementTest {

    @org.junit.jupiter.api.Test
    void majorityElementMethod() {

    }

    @Test
    void MajorityElement() {
        int[] risultatoElezioni = {1,1,2,2,1,3,3,2,2,2,2,2,2,2};
        Assertions.assertEquals(2, MajorityElement.MajorityElementMethod(risultatoElezioni));

    }

}