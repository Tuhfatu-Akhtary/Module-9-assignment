void merge(int nums[], int left, int mid, int right)  //Merge function to merge the divided arrays
 {
    int n1 = mid - left + 1;  //assignment of the first array size to n1 variable 
    int n2 = right - mid;     //assignment of the second Array size to n2 variable

    int* L = new int[n1];    //dynamic memory allocation of array L
    int* R = new int[n2];    //dynamic memory allocation of array R

    for (int i = 0; i < n1; i++)    //Assigning the elements to each array
        L[i] = nums[left + i];
    for (int j = 0; j < n2; j++)
        R[j] = nums[mid + 1 + j];

    int i = 0, j = 0, k = left;    //Initialization of the iterators

    while (i < n1 && j < n2)      // Merge L and R starting from the end
     {     
        if (L[i] <= R[j]) {
            nums[k++] = L[i++];
        } else {
            nums[k++] = R[j++];
        }
    }

    while (i < n1) {          // If there are remaining elements in L, copy them
        nums[k++] = L[i++];
    }

    while (j < n2) {         // If there are remaining elements in R, copy them
        nums[k++] = R[j++];
    }

    delete[] L;             //Delete L 
    delete[] R;             //Delete R
}

void mergeSort(int nums[], int left, int right)      //MergeSort function to divide the arrays
{
    if (left < right) {
        int mid = left + (right - left) / 2;        //If left is less than right then calculate mid and sort the array by dividing it into parts

        mergeSort(nums, left, mid);
        mergeSort(nums, mid + 1, right);

        merge(nums, left, mid, right);
    }
}

int findKthLargest(int nums[], int n, int k)    //Function to find the kth largest number
 {
    mergeSort(nums, 0, n - 1);      //Merge Sort the array
    return nums[n - k];             //Then return the n-k th index of the sorted array which points the kth largest number
}


Time complexity : O(nlogn)
Space complexity : O(n)