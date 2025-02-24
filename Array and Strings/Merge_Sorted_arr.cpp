#include <iostream>
#include <vector>

using namespace std;

/*
    Problem: Merge Sorted Arrays

    Given two sorted integer arrays nums1 and nums2, merge nums2 into nums1 as one sorted array.

    - The first array, nums1, has a size of `m + n`, where the first `m` elements are sorted, 
      and the rest are set to 0 and should be ignored.
    - The second array, nums2, has a size of `n` and is sorted.
    - Merge nums2 into nums1 in-place such that nums1 remains sorted.

    Example:
    
    Input:
    nums1 = [1, 2, 3, 0, 0, 0], m = 3
    nums2 = [2, 5, 6], n = 3

    Output:
    nums1 = [1, 2, 2, 3, 5, 6]
*/

void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {
    int temp1 = m - 1; // Pointer for the last element in nums1 (excluding trailing zeros)
    int temp2 = n - 1; // Pointer for the last element in nums2
    int temp3 = m + n - 1; // Pointer for the last position in nums1 (including trailing zeros)

    // Merge from the back of nums1 to avoid overwriting elements
    while (temp1 >= 0 && temp2 >= 0) {
        if (nums1[temp1] > nums2[temp2]) {
            nums1[temp3] = nums1[temp1];
            temp1--;
        } else {
            nums1[temp3] = nums2[temp2];
            temp2--;
        }
        temp3--;
    }

    // If there are remaining elements in nums2, copy them
    while (temp2 >= 0) {
        nums1[temp3] = nums2[temp2];
        temp3--;
        temp2--;
    }
}

// Driver code to test the function
int main() {
    vector<int> nums1 = {1, 2, 3, 0, 0, 0}; // Array with extra space for merging
    int m = 3; // Number of actual elements in nums1
    vector<int> nums2 = {2, 5, 6}; // Second sorted array
    int n = 3; // Number of elements in nums2

    merge(nums1, m, nums2, n);

    // Print merged array
    cout << "Merged Array: ";
    for (int num : nums1) {
        cout << num << " ";
    }
    cout << endl;

    return 0;
}
