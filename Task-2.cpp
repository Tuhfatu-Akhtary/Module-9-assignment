void merge(int nums1[], int m, int nums2[], int n)   //Merge Function
 {
    int i = m - 1; // Pointer to the end of the first part of nums1
    int j = n - 1; // Pointer to the end of nums2
    int k = m + n - 1; // Pointer to the end of nums1

    // Merge nums1 and nums2 starting from the end
    while (i >= 0 && j >= 0) {
        if (nums1[i] > nums2[j]) {
            nums1[k--] = nums1[i--];
        } else {
            nums1[k--] = nums2[j--];
        }
    }

    // If there are remaining elements in nums2, copy them
    while (j >= 0) {
        nums1[k--] = nums2[j--];
    }
}


Time complexity : O(n+m)
space complexity : O(1)