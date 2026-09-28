// Problem: Two Sum in Sorted Array
// Approach: Two Pointers
// Why the pointers move: 
// If sum < target: Because the array is sorted, moving left forward gives a larger value and can increase the sum.
// If sum > target: Because the array is sorted, moving right backward gives a smaller value and can decrease the sum.
// Time Complexity: O(n)
// Space Complexity: O(1)
// Big-O: O(n) time and O(1) auxiliary space.

#include <iostream>
#include <vector>
#include <cassert>

using namespace std;

vector<int> twoSum(const vector<int>& nums, int target) {
    int left = 0;
    int right = nums.size() - 1;
    
    while (left < right) {
        int sum = nums[left] + nums[right];
        
        if (sum == target) {
            return {nums[left], nums[right]};
        } else if (sum < target) {
            left++; // Need a larger sum
        } else {
            right--; // Need a smaller sum
        }
    }
    return {};
}

int main() {
    // Test case 1: case where a pair exists
    vector<int> nums1 = {2, 7, 11, 15};
    vector<int> res1 = twoSum(nums1, 9);
    assert(res1.size() == 2 && res1[0] == 2 && res1[1] == 7);
    
    // Test case 2: another valid pair
    vector<int> nums2 = {1, 2, 3, 4, 5, 6};
    vector<int> res2 = twoSum(nums2, 8);
    assert(res2.size() == 2 && res2[0] == 2 && res2[1] == 6);
    
    // Test case 3: case where no pair exists
    vector<int> nums3 = {1, 2, 3, 4};
    vector<int> res3 = twoSum(nums3, 10);
    assert(res3.empty());
    
    cout << "All tests passed for Problem 4." << endl;
    return 0;
}
