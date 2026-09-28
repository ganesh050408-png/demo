# Two-Pointer Technique in C++

This repository contains five C++ problems based on the two-pointer technique. It demonstrates how to turn O(n²) brute-force solutions into clean O(n) ones by smartly iterating over elements.

## Problems Covered

1. Reverse a String In-Place
2. Valid Palindrome
3. Remove Duplicates from a Sorted Array
4. Two Sum in a Sorted Array
5. Three Sum Equals Zero

## What I Learned

The main goal was understanding why the pointers move, not just getting the correct answer. The two-pointer technique is powerful because it skips unnecessary comparisons.

## 1. Reverse a String In-Place

We use a left pointer starting at the beginning and a right pointer starting at the end. We swap the characters at these positions, moving both pointers toward the center. This lets us reverse the string in one pass.
- **Complexity**: O(n) time, O(1) space.

## 2. Check for a Palindrome

We use a left pointer at the beginning and a right pointer at the end, comparing both ends. If they match, we move toward the center. If we find any mismatch, it's not a palindrome.
- **Complexity**: O(n) time, O(1) space.

## 3. Remove Duplicates from a Sorted Array

Because the array is sorted, all duplicates are adjacent. We use a read pointer to scan the array and a write pointer to store the unique values, allowing in-place modification without extra memory.
- **Complexity**: O(n) time, O(1) space.

## 4. Two Sum in a Sorted Array

We use left and right pointers at opposite ends. 
- Why left moves when sum is too small: Since the array is sorted, a larger element is to the right. 
- Why right moves when sum is too large: A smaller element is to the left.
- **Complexity**: O(n) time, O(1) space.

## 5. Three Sum Equals Zero

First, we sort the array to handle duplicates and enable the two-pointer search. We fix one element and use the two-pointer technique on the remaining elements.
- Pointer movement is just like Two Sum (left moves if sum < 0, right moves if sum > 0).
- We handle duplicate handling by skipping adjacent identical values for both the fixed element and the two pointers.
- **Complexity**: O(n²) time, O(1) auxiliary space. Sorting takes O(n log n), but the O(n²) search dominates.

## Complexity Summary

| Problem | Time | Space |
|---|---:|---:|
| Reverse String | O(n) | O(1) |
| Palindrome | O(n) | O(1) |
| Remove Duplicates | O(n) | O(1) |
| Two Sum | O(n) | O(1) |
| Three Sum | O(n²) | O(1)* |

*Space for Three Sum is O(1) auxiliary space, but the returned result itself requires output space.

## Testing

Every problem contains at least three test cases using `assert()`. Tests run silently if they pass and print a success message at the end.

## How to Run

Compile and run using `g++` with C++17.

Example (Linux/macOS):

```bash
g++ -std=c++17 01_reverse_string.cpp -o reverse
./reverse
```

Example (Windows PowerShell):

```powershell
g++ -std=c++17 01_reverse_string.cpp -o reverse.exe
.\reverse.exe
```

The same approach can be used for the other files.

## Repository Structure

```text
two-pointer-technique-cpp/
├── 01_reverse_string.cpp
├── 02_valid_palindrome.cpp
├── 03_remove_duplicates_sorted_array.cpp
├── 04_two_sum_sorted_array.cpp
├── 05_three_sum_zero.cpp
├── README.md
└── .gitignore
```

## Conclusion

Understanding how two pointers reduce unnecessary comparisons provides a solid foundation for solving more advanced array and string problems. It's an elegant technique that can be reused in many different contexts.
