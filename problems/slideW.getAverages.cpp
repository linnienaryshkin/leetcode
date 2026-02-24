#include <cassert>
#include <iostream>
#include <vector>
using namespace std;

/*
clang++ -std=c++17 problems/slideW.getAverages.cpp && ./a.out
*/

/**
 * @problem K Radius Subarray Averages
 * @link https://leetcode.com/problems/k-radius-subarray-averages/
 * Time: O(n)
 * Space: O(n)
 */
class Solution {
public:
  vector<int> getAverages(vector<int> &nums, int k) {
    int n = nums.size();

    vector<long long> prefix(n);
    prefix[0] = nums[0];

    for (int i = 1; i < n; i++) {
      prefix[i] = prefix[i - 1] + nums[i];
    }

    vector<int> output(n, -1);

    long long windowSize = 2LL * k + 1;

    for (int i = k; i + k < n; i++) {
      long long left = (i - k - 1 >= 0) ? prefix[i - k - 1] : 0;
      long long right = prefix[i + k];

      // Note: Use implicit or explicit casting if needed, though windowSize
      // handles it
      output[i] = (right - left) / windowSize;
    }

    return output;
  }
};

int main() {
  Solution sol;

  vector<int> nums = {7, 4, 3, 9, 1, 8, 5, 2, 6};
  vector<int> result = sol.getAverages(nums, 3);
  assert(result == vector<int>({-1, -1, -1, 5, 4, 4, -1, -1, -1}));

  cout << "All tests passed!" << endl;
  return 0;
}