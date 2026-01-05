#include <cassert>
#include <iostream>
#include <vector>
using namespace std;

/*
clang++ -std=c++17 problems/reverseString.cpp && ./a.out
*/

/**
 * @problem Reverse String
 * @link
 * https://leetcode.com/explore/featured/card/leetcodes-interview-crash-course-data-structures-and-algorithms/703/arraystrings/4592/
 * Time: O(n)
 * Space: O(1)
 */
class Solution {
public:
  void reverseString(vector<char> &s) {
    int left = 0;
    int right = s.size() - 1;

    while (left < right) {
      swap(s[left], s[right]);
      left++;
      right--;
    }
  }

  void swap(char &a, char &b) {
    char temp = a;
    a = b;
    b = temp;
  }
};

int main() {
  Solution sol;

  vector<char> s = {'h', 'e', 'l', 'l', 'o'};
  sol.reverseString(s);
  assert(s == vector<char>({'o', 'l', 'l', 'e', 'h'}));
  cout << "Test 1 passed! " << endl;

  s = {'H', 'a', 'n', 'n', 'a', 'h'};
  sol.reverseString(s);
  assert(s == vector<char>({'h', 'a', 'n', 'n', 'a', 'H'}));
  cout << "Test 2 passed! " << endl;

  cout << "All tests passed!" << endl;
  return 0;
}