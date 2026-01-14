#include <cassert>
#include <chrono>
#include <iostream>
#include <vector>
using namespace std;

/*
clang++ -std=c++17 problems/longestOnes.cpp && ./a.out
*/

/**
 * @problem Longest Ones
 * @link
 * https://leetcode.com/explore/featured/card/leetcodes-interview-crash-course-data-structures-and-algorithms/703/arraystrings/4595/
 * Time: O(n)
 * Space: O(1)
 */
class Solution {
public:
  int longestOnes(vector<int> &nums, int k) {
    int left = 0;
    int zeros = 0;
    int best = 0;
    int n = nums.size();

    for (int right = 0; right < n; ++right) {
      zeros += (nums[right] == 0);

      while (zeros > k) {
        zeros -= (nums[left] == 0);
        ++left;
      }

      best = max(best, right - left + 1);
    }

    return best;
  }
};

int main() {
  Solution sol;

  vector<int> nums = {1, 1, 1, 0, 0, 0, 1, 1, 1, 1, 0};
  int k = 2;

  auto start = std::chrono::high_resolution_clock::now();
  int result = sol.longestOnes(nums, k);
  auto end = std::chrono::high_resolution_clock::now();
  assert(result == 6);
  cout << "Test 1 passed! " << "result: " << result << " execution time: "
       << std::chrono::duration_cast<std::chrono::nanoseconds>(end - start)
              .count()
       << " ns" << endl;

  cout << "All tests passed!" << endl;
  return 0;
}