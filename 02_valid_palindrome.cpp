// Problem: Valid Palindrome
// Approach: Two Pointers
// Why the pointers move: We compare the first and last characters. If they match, we move both pointers toward the center (left++ and right--). We stop if a mismatch is found or if the pointers cross, meaning all pairs matched.
// Time Complexity: O(n)
// Space Complexity: O(1)
// Big-O: O(n) time and O(1) auxiliary space.

#include <iostream>
#include <string>
#include <cassert>

using namespace std;

bool isPalindrome(const string& s) {
    if (s.empty()) return true;
    
    int left = 0;
    int right = s.length() - 1;
    
    while (left < right) {
        if (s[left] != s[right]) {
            return false;
        }
        left++;
        right--;
    }
    return true;
}

int main() {
    // Test case 1: valid palindrome
    assert(isPalindrome("racecar") == true);
    
    // Test case 2: non-palindrome
    assert(isPalindrome("hello") == false);
    
    // Test case 3: empty string
    assert(isPalindrome("") == true);
    
    cout << "All tests passed for Problem 2." << endl;
    return 0;
}
