// Problem: Three Sum Equals Zero
// Approach: Sort + Two Pointers
// Why the pointers move: 
// Sorting is useful because it allows us to avoid duplicates easily and use the two-pointer technique on the remaining elements.
// left moves when the sum is too small (sum < 0) because we need a larger value.
// right moves when the sum is too large (sum > 0) because we need a smaller value.
// Duplicate values are skipped for both the fixed element and the two pointers so duplicate triplets are not returned.
// Time Complexity: O(n²)
// Space Complexity: O(1) auxiliary space, excluding output.
// Big-O: O(n²) time and O(1) auxiliary space.
// Note: Sorting takes O(n log n), but the overall O(n²) two-pointer search dominates.

#include <iostream>
#include <vector>
#include <algorithm>
#include <cassert>

using namespace std;

vector<vector<int>> threeSum(vector<int>& nums) {
    vector<vector<int>> result;
    if (nums.size() < 3) return result;
    
    sort(nums.begin(), nums.end());
    
    for (int i = 0; i < (int)nums.size() - 2; i++) {
        // Skip duplicate fixed elements
        if (i > 0 && nums[i] == nums[i - 1]) continue;
        
        int left = i + 1;
        int right = nums.size() - 1;
        
        while (left < right) {
            int sum = nums[i] + nums[left] + nums[right];
            
            if (sum == 0) {
                result.push_back({nums[i], nums[left], nums[right]});
                
                // Skip duplicate elements for left and right pointers
                while (left < right && nums[left] == nums[left + 1]) left++;
                while (left < right && nums[right] == nums[right - 1]) right--;
                
                left++;
                right--;
            } else if (sum < 0) {
                left++;
            } else {
                right--;
            }
        }
    }
    
    return result;
}

int main() {
    // Test case 1: standard example
    vector<int> nums1 = {-1, 0, 1, 2, -1, -4};
    vector<vector<int>> res1 = threeSum(nums1);
    assert(res1.size() == 2);
    // Expected: {-1,-1,2} and {-1,0,1}
    assert(res1[0][0] == -1 && res1[0][1] == -1 && res1[0][2] == 2);
    assert(res1[1][0] == -1 && res1[1][1] == 0 && res1[1][2] == 1);
    
    // Test case 2: all zeros
    vector<int> nums2 = {0, 0, 0, 0};
    vector<vector<int>> res2 = threeSum(nums2);
    assert(res2.size() == 1);
    assert(res2[0][0] == 0 && res2[0][1] == 0 && res2[0][2] == 0);
    
    // Test case 3: no triplets
    vector<int> nums3 = {1, 2, 3};
    vector<vector<int>> res3 = threeSum(nums3);
    assert(res3.empty());
    
    cout << "All tests passed for Problem 5." << endl;
    return 0;
}
