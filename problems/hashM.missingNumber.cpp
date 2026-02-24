#include <cassert>
#include <iostream>
#include <unordered_set>
#include <vector>
using namespace std;

/*
clang++ -std=c++17 problems/hashM.missingNumber.cpp && ./a.out
*/

/**
 * @problem Missing Number
 * @description Given an array nums containing n distinct numbers in the range
 * [0, n], return the only number in the range that is missing from the array.
 * @link https://leetcode.com/problems/missing-number
 * Time: O(n)
 * Space: O(n) | How to make it O(1)?
 */
class Solution {
public:
  int missingNumber(vector<int> &nums) {
    int n = nums.size();
    // Time: O(n)
    // Space: O(n)
    unordered_set<int> numSet(nums.begin(), nums.end());
    // Time: O(n)
    for (int i = 0; i <= n; i++) {
      // Time: O(1)
      if (!numSet.count(i)) {
        return i;
      }
    }
    return -1;
  }
};

int main() {
  Solution sol;

  vector<int> nums = {3, 0, 1};
  int result = sol.missingNumber(nums);
  assert(result == 2);
  cout << "Test 1 passed! " << endl;

  nums = {0, 1};
  result = sol.missingNumber(nums);
  assert(result == 2);
  cout << "Test 2 passed! " << endl;

  nums = {9, 6, 4, 2, 3, 5, 7, 0, 1};
  result = sol.missingNumber(nums);
  assert(result == 8);
  cout << "Test 3 passed! " << endl;

  cout << "All tests passed!" << endl;
  return 0;
}