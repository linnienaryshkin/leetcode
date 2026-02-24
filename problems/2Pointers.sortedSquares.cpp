#include <cassert>
#include <iostream>
#include <vector>
using namespace std;

/*
clang++ -std=c++17 problems/2Pointers.sortedSquares.cpp && ./a.out
*/

/**
 * @problem Sorted Squares
 * @link https://leetcode.com/problems/squares-of-a-sorted-array
 * Time: O(n)
 * Space: O(n)
 */
class Solution {
public:
  vector<int> sortedSquares(vector<int> &nums) {
    int left = 0;
    int right = nums.size() - 1;
    vector<int> result(nums.size());
    int index = nums.size() - 1;

    while (left <= right) {
      if (abs(nums[left]) > abs(nums[right])) {
        result[index] = nums[left] * nums[left];
        left++;
      } else {
        result[index] = nums[right] * nums[right];
        right--;
      }
      index--;
    }
    return result;
  }
};

int main() {
  Solution sol;

  vector<int> nums = {-4, -1, 0, 3, 10};
  vector<int> result = sol.sortedSquares(nums);
  assert(result == vector<int>({0, 1, 9, 16, 100}));

  cout << "All tests passed!" << endl;
  return 0;
}