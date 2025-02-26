/*
Problem: Majority Element

Given an array `nums` of size `n`, find the majority element. The majority element is the element that appears more than ⌊n / 2⌋ times.

You may assume that the majority element always exists in the array.

Example 1:
Input: nums = [3,2,3]
Output: 3

Example 2:
Input: nums = [2,2,1,1,1,2,2]
Output: 2

Constraints:
- `n == nums.length`
- `1 <= n <= 5 * 10^4`
- `-10^9 <= nums[i] <= 10^9`

Follow-up: Could you solve the problem in linear time and O(1) space?
*/

#include <vector>
#include <iostream>
using namespace std;

class Solution {
public:
    int majorityElement(vector<int>& nums) {
        int max_ele = nums[0];
        int max_freq = 1;
        
        // Boyer-Moore Voting Algorithm
        for (int i = 1; i < nums.size(); i++) {
            if (nums[i] == max_ele) {
                max_freq++;
            } else {
                if (max_freq == 0) {
                    max_ele = nums[i];
                    max_freq = 1;
                } else {
                    max_freq--;
                }
            }
        }
        return max_ele;
    }
};

int main() {
    vector<int> nums = {2,2,1,1,1,2,2};
    Solution solution;
    cout << "Majority Element: " << solution.majorityElement(nums) << endl;
    return 0;
}

/*
Solution Approach:
This problem is efficiently solved using the Boyer-Moore Voting Algorithm.

1. We maintain a `max_ele` variable to store the potential majority element and a `max_freq` counter to track its frequency.
2. Traverse the array:
   - If the current element matches `max_ele`, increase `max_freq`.
   - Otherwise, decrease `max_freq`. If `max_freq` reaches zero, update `max_ele` to the current element and reset `max_freq` to 1.
3. The majority element is guaranteed to exist, so `max_ele` will always be the answer after one pass.

Time Complexity: O(n) — We iterate through the array once.
Space Complexity: O(1) — We use only a few extra variables.
*/
