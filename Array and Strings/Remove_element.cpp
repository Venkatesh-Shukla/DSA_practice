#include <iostream>
#include <vector>

using namespace std;

/*
    Problem: Remove Element

    Given an integer array nums and an integer val, remove all occurrences of val in-place 
    and return the new length of the array. The order of the remaining elements may change.

    - You must do this in-place with O(1) extra memory.
    - The relative order of the elements can be changed.

    Example:

    Input:
    nums = [3, 2, 2, 3], val = 3

    Output:
    New Length = 2
    nums (modified) = [2, 2, _]  (The underscores represent ignored values)

    Explanation:
    The function returns 2, which is the number of elements that are not equal to val.
    The first two elements of nums are now 2 and 2. The order may change, and the remaining
    elements beyond the returned length do not matter.
*/

int removeElement(vector<int>& nums, int val) {
    int index = 0; // Pointer for placing non-val elements
    for (int i = 0; i < nums.size(); i++) {
        if (nums[i] != val) {
            nums[index] = nums[i];
            index++;
        }
    }
    return index; // New length of the modified array
}

// Driver code to test the function
int main() {
    vector<int> nums = {3, 2, 2, 3}; // Array with elements to remove
    int val = 3; // Value to remove

    int newLength = removeElement(nums, val);

    // Print modified array (only valid elements)
    cout << "New Length: " << newLength << endl;
    cout << "Modified Array: ";
    for (int i = 0; i < newLength; i++) {
        cout << nums[i] << " ";
    }
    cout << endl;

    return 0;
}
