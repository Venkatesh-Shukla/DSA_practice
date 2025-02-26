/*
Problem: Rotate Array

Given an array, rotate the array to the right by `k` steps.

Example 1:
Input: nums = [1,2,3,4,5,6,7], k = 3
Output: [5,6,7,1,2,3,4]

Example 2:
Input: nums = [-1,-100,3,99], k = 2
Output: [3,99,-1,-100]

Constraints:
- `n == nums.length`
- `1 <= n <= 10^5`
- `-10^9 <= nums[i] <= 10^9`
- `0 <= k <= 2 * 10^9`

Follow-up: Could you solve this problem in O(n) time and O(1) space?
*/

#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

class Solution {
public:
    void rotate(vector<int>& nums, int k) {
        int n = nums.size();
        k %= n; // Handle cases where k > n
        reverse(nums.begin(), nums.end());
        // Reverse the first k elements
        reverse(nums.begin(), nums.begin() + k);
        // Reverse the remaining n - k elements
        reverse(nums.begin() + k, nums.end());        
    }
};

int main() {
    vector<int> rotate_nums = {1,2,3,4,5,6,7};
    int k = 3;
    Solution solution;
    solution.rotate(rotate_nums, k);
    cout << "Rotated Array: ";
    for (int num : rotate_nums) {
        cout << num << " ";
    }
    cout << endl;
    
    return 0;
}

/*
Solution Approach:

1. Reverse the entire array.
2. Reverse the first `k` elements.
3. Reverse the remaining `n - k` elements.
4. This runs in O(n) time and O(1) space.
*/
