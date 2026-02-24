#include <cassert>
#include <iostream>
#include <vector>
using namespace std;

/*
clang++ -std=c++17 problems/2pointers.3sum.cpp && ./a.out
*/

/**
 * @problem 3Sum
 * @link https://leetcode.com/problems/3sum/?envType=problem-list-v2&envId=array
 * Time: O(n log n) + O(n²) = O(n²)
 * Space: O(n)
 */
class Solution {
public:
  vector<vector<int>> threeSum(vector<int> &nums) {
    vector<vector<int>> result;
    // Time: O(n log n)
    sort(nums.begin(), nums.end());

    // Time: O(n^2)
    for (int i = 0; i < nums.size(); i++) {
      if (i > 0 && nums[i] == nums[i - 1]) {
        continue;
      }

      int left = i + 1;
      int right = nums.size() - 1;

      while (left < right) {
        int sum = nums[i] + nums[left] + nums[right];

        if (sum == 0) {
          result.push_back({nums[i], nums[left], nums[right]});

          // Skip duplicates for second element
          while (left < right && nums[left] == nums[left + 1])
            left++;
          // Skip duplicates for third element
          while (left < right && nums[right] == nums[right - 1])
            right--;

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
};

int main() {
  Solution sol;

  vector<int> nums = {-1, 0, 1, 2, -1, -4};
  vector<vector<int>> result = sol.threeSum(nums);
  assert(result == vector<vector<int>>({{-1, -1, 2}, {-1, 0, 1}}));

  nums = {2, -3, 0, -2, -5, -5, -4, 1, 2, -2, 2, 0, 2, -4, 5, 5, -10};
  result = sol.threeSum(nums);
  // [[-10,5,5],[-5,0,5],[-4,2,2],[-3,-2,5],[-3,1,2],[-2,0,2]]
  assert(result == vector<vector<int>>({{-10, 5, 5},
                                        {-5, 0, 5},
                                        {-4, 2, 2},
                                        {-3, -2, 5},
                                        {-3, 1, 2},
                                        {-2, 0, 2}}));

  cout << "All tests passed!" << endl;
  return 0;
}