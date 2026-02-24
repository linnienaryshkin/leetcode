#include <cassert>
#include <iostream>
#include <vector>
using namespace std;

/*
clang++ -std=c++17 problems/stack.makeGood.cpp && ./a.out
*/

/**
 * @problem Make Good
 * @link https://leetcode.com/problems/make-the-string-great
 * Time: O(n)
 * Space: O(1)
 */
class Solution {
public:
  string makeGood(string s) {
    string result;

    for (char c : s) {
      if (!result.empty() && abs(result.back() - c) == 32) {
        result.pop_back();
      } else {
        result.push_back(c);
      }
    }

    return result;
  }
};

int main() {
  Solution sol;

  string s = "abBAD";
  string result = sol.makeGood(s);
  assert(result == "D");

  s = "kaAbBcCE";
  result = sol.makeGood(s);
  assert(result == "kE");

  cout << "All tests passed!" << endl;
  return 0;
}