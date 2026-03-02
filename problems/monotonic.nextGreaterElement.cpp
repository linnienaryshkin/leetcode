#include <cassert>
#include <iostream>
#include <unordered_set>
#include <vector>
using namespace std;

/*
clang++ -std=c++17 problems/monotonic.nextGreaterElement.cpp && ./a.out
*/

/**
 * @link https://leetcode.com/problems/next-greater-element-i/
 * Time: O(n + m)
 * Space: O(n)
 */
class Solution {
public:
  vector<int> nextGreaterElement(vector<int> &nums1, vector<int> &nums2) {
    unordered_map<int, int> nextGreater;
    stack<int> st;

    /**
     * Process nums2 to build the next greater element map
     * For each element in nums2, we check if it is greater than the top of the
     * stack. If it is, we pop the stack and add the element to the next greater
     * element map. If it is not, we push the element onto the stack. Time: O(m)
     * Space: O(m)
     */
    for (int num : nums2) {
      while (!st.empty() && num > st.top()) {
        nextGreater[st.top()] = num;
        st.pop();
      }
      st.push(num);
    }

    /**
     * Remaining elements have no greater element
     * For each element in the stack, we add it to the next greater element map
     * with a value of -1. Time: O(m) Space: O(m)
     */
    while (!st.empty()) {
      nextGreater[st.top()] = -1;
      st.pop();
    }

    /**
     * Build result for nums1
     * For each element in nums1, we add the next greater element to the result.
     * Time: O(n)
     * Space: O(n)
     */
    vector<int> result;
    for (int num : nums1) {
      result.push_back(nextGreater[num]);
    }

    return result;
  }
};

int main() {
  Solution sol;

  vector<int> nums1 = {4, 1, 2};
  vector<int> nums2 = {1, 3, 4, 2};
  vector<int> result = sol.nextGreaterElement(nums1, nums2);
  assert(result == vector<int>({-1, 3, -1}));
  cout << "Test 1 passed! " << endl;

  nums1 = {2, 4};
  nums2 = {1, 2, 3, 4};
  result = sol.nextGreaterElement(nums1, nums2);
  assert(result == vector<int>({3, -1}));
  cout << "Test 2 passed! " << endl;

  cout << "All tests passed!" << endl;
  return 0;
}