#include <iostream>
#include <vector>

using namespace std;

/*
    Problem: Remove Duplicates from Sorted Array II

    Given a sorted integer array nums (in non-decreasing order), modify it in-place so that 
    each unique element appears at most twice. The relative order of the elements should be maintained.

    - You must do this in-place with O(1) extra memory.
    - The remaining elements beyond the returned length do not matter.

    Example 1:

    Input:
    nums = [1, 1, 1, 2, 2, 3]

    Output:
    New Length = 5
    nums (modified) = [1, 1, 2, 2, 3, _]  (The underscores represent ignored values)

    Example 2:

    Input:
    nums = [0, 0, 1, 1, 1, 1, 2, 3, 3]

    Output:
    New Length = 7
    nums (modified) = [0, 0, 1, 1, 2, 3, 3, _, _]

*/

int removeDuplicates(vector<int>& nums) {
    if (nums.size() <= 2) return nums.size(); // If array has 2 or fewer elements, return size as is

    int idx = 2; // Start from index 2 since the first two elements can always stay
    for (int i = 2; i < nums.size(); i++) {
        if (nums[i] != nums[idx - 2]) { // Ensure an element appears at most twice
            nums[idx] = nums[i];
            idx++;
        }
    }
    return idx; // Number of valid elements in the array
}

// Driver code to test the function
int main() {
    vector<int> nums = {1, 1, 1, 2, 2, 3}; // Input array

    int newLength = removeDuplicates(nums);

    // Print modified array (only valid elements)
    cout << "New Length: " << newLength << endl;
    cout << "Modified Array: ";
    for (int i = 0; i < newLength; i++) {
        cout << nums[i] << " ";
    }
    cout << endl;

    return 0;
}
