// Problem: Reverse a String In-Place
// Approach: Two Pointers
// Why the pointers move: The left pointer starts at the beginning, and the right pointer starts at the end. We swap the characters at these positions, moving the outer elements inward. Then we increment left and decrement right to process the next pair.
// Time Complexity: O(n)
// Space Complexity: O(1)
// Big-O: O(n) time and O(1) auxiliary space.

#include <iostream>
#include <string>
#include <cassert>

using namespace std;

void reverseString(string& s) {
    int left = 0;
    int right = s.length() - 1;
    
    while (left < right) {
        swap(s[left], s[right]);
        left++;
        right--;
    }
}

int main() {
    // Test case 1: normal string
    string s1 = "hello";
    reverseString(s1);
    assert(s1 == "olleh");
    
    // Test case 2: palindrome string
    string s2 = "racecar";
    reverseString(s2);
    assert(s2 == "racecar");
    
    // Test case 3: empty string
    string s3 = "";
    reverseString(s3);
    assert(s3 == "");
    
    cout << "All tests passed for Problem 1." << endl;
    return 0;
}
