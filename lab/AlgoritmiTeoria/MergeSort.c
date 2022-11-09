#include <stdio.h>
#include <stdlib.h>



/*  
    merge, tot di cicli for, alloco un nuovo vettore di dimensione q-p+1, 
    piazzo i su p, j su r e k all’inizio del vettore, for su k e copio in 
    B[j] il più piccolo tra A[i] e A[j], secondo for  su k, copio b[k] in A[p-1+k]
    
*/
void Merge(int A[], int p, int q, int r);
void MergeSort(int A[], int p,int q);


int main(){

    int arr[] ={1,4,3,8,6,7,2,5};
    MergeSort(arr,0,7);
   
    for (int i = 0; i < 8; i++)
    {
        printf("%d",arr[i]);
    }
    
    return 0;
}
void MergeSort(int A[], int p,int q){
    if (p<q){
        int r = p+(q-p)/2;
		MergeSort(A,p,r);
		MergeSort(A,r+1, q);
		Merge(A,p,q,r);
    }
    
}

void Merge(int A[], int p, int q, int r){
    int B[q-p+1];
    int i,j,k;
    int left_length = r-p+1;
    int right_length = q-r;

	int temp_left[left_length];
    int temp_right[right_length];
    
    for (int i = 0; i < left_length; i++)
    {
        temp_left[i] = A[p+i];
    }
    for (int i = 0; i < right_length; i++)
    {
        temp_right[i] = A[r+i+1];
    }
    
    
    for (int k = p,i = 0,j = 0; k <= q; k++)
    {
        if ((i < left_length) &&
        (j >= right_length || temp_left[i] <= temp_right[j]) )
        {
            A[k] = temp_left[i];
            i++;
        } else {
            A[k] = temp_right[j];
            j++;
        }
        
    }
    
}

/*
    Example visualization of the merge sort algorithm:

            [38, 27, 43, 3, 9, 82, 10]
                        /   \
        [38, 27, 43, 3]   [9, 82, 10]
        /         |         |      \
    [38, 27]    [43, 3]   [9, 82]   [10]
    /   |      /    |    /    \      |
    [38]  [27]  [43]  [3]  [9]   [82]  [10]
    \  /       \   /     \     /     |
    [27, 38]    [3, 43]   [9, 82]    [10]
        \         /          \        /
        [3, 27, 38, 43]        [9, 10, 82]
            \                  /
            [3, 9, 10, 27, 38, 43, 82]

    The array is first broken up into progressively smaller unsorted portions of
    the array, and once we have "sub-arrays" of 1 element they are by definition
    sorted arrays.  From here the "sorted arrays" are merged together until we 
    arrive at the complete sorted array.
*/