#include <iostream>
#include <vector>

using namespace std;

/*
    Problem: Remove Duplicates from Sorted Array

    Given a sorted integer array nums (in non-decreasing order), remove the duplicates in-place 
    so that each unique element appears only once. The relative order of the elements should be preserved.

    - You must do this in-place with O(1) extra memory.
    - The remaining elements beyond the returned length do not matter.

    Example:

    Input:
    nums = [1, 1, 2]

    Output:
    New Length = 2
    nums (modified) = [1, 2, _]  (The underscores represent ignored values)

    Explanation:
    The function returns 2, meaning the first two elements of nums are now unique: 1 and 2.
    The order is maintained, and the rest of the array is ignored.

*/

int removeDuplicates(vector<int>& nums) {
    if (nums.empty()) return 0; // Handle edge case when the array is empty

    int idx = 1; // Pointer for unique elements
    for (int i = 1; i < nums.size(); i++) {
        if (nums[i] != nums[i - 1]) { // Compare with previous element
            nums[idx] = nums[i];
            idx++;
        }
    }
    return idx; // Number of unique elements
}

// Driver code to test the function
int main() {
    vector<int> nums = {1, 1, 2}; // Input array

    int newLength = removeDuplicates(nums);

    // Print modified array (only unique elements)
    cout << "New Length: " << newLength << endl;
    cout << "Modified Array: ";
    for (int i = 0; i < newLength; i++) {
        cout << nums[i] << " ";
    }
    cout << endl;

    return 0;
}
