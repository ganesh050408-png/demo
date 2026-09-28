// Problem: Remove Duplicates from Sorted Array
// Approach: Two Pointers (Slow/Fast or Write/Read)
// Why the pointers move: Because the array is sorted, duplicates are adjacent. The write pointer keeps track of where the next unique element should go. The read pointer scans the array. When the read pointer finds a new unique value, we copy it to the write pointer's position and move the write pointer forward.
// Time Complexity: O(n)
// Space Complexity: O(1)
// Big-O: O(n) time and O(1) auxiliary space.

#include <iostream>
#include <vector>
#include <cassert>

using namespace std;

int removeDuplicates(vector<int>& nums) {
    if (nums.empty()) return 0;
    
    int write = 1;
    for (int read = 1; read < nums.size(); read++) {
        if (nums[read] != nums[read - 1]) {
            nums[write] = nums[read];
            write++;
        }
    }
    return write;
}

int main() {
    // Test case 1: normal array with duplicates
    vector<int> nums1 = {1, 1, 2, 2, 3};
    int k1 = removeDuplicates(nums1);
    assert(k1 == 3);
    assert(nums1[0] == 1 && nums1[1] == 2 && nums1[2] == 3);
    
    // Test case 2: all identical elements
    vector<int> nums2 = {1, 1, 1, 1};
    int k2 = removeDuplicates(nums2);
    assert(k2 == 1);
    assert(nums2[0] == 1);
    
    // Test case 3: empty array
    vector<int> nums3 = {};
    int k3 = removeDuplicates(nums3);
    assert(k3 == 0);
    
    cout << "All tests passed for Problem 3." << endl;
    return 0;
}
