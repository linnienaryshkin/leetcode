#include <cassert>
#include <iostream>
#include <unordered_set>
#include <vector>
using namespace std;

/*
clang++ -std=c++17 problems/hashM.findWinners.cpp && ./a.out
*/

/**
 * @problem Find Winners
 * @description Given an array matches where matches[i] = [winneri, loseri]
 * indicates that the player winneri defeated loseri in a match.
 * Return a list answer of size 2 where:
 * answer[0] is a list of all players that have not lost any matches.
 * answer[1] is a list of all players that have lost exactly one match.
 * The values in the two lists should be returned in increasing order.
 * @link https://leetcode.com/problems/find-players-with-zero-or-one-losses
 * Time: O(n log n)
 * Space: O(n)
 */
class Solution {
public:
  vector<vector<int>> findWinners(vector<vector<int>> &matches) {
    unordered_map<int, int> losses;

    for (auto &m : matches) {
      losses[m[0]] += 0; // ensure winner exists
      losses[m[1]] += 1; // loser gets a loss
    }

    vector<int> noLoss, oneLoss;

    for (auto &[player, cnt] : losses) {
      if (cnt == 0)
        noLoss.push_back(player);
      else if (cnt == 1)
        oneLoss.push_back(player);
    }

    sort(noLoss.begin(), noLoss.end());
    sort(oneLoss.begin(), oneLoss.end());

    return {noLoss, oneLoss};
  }

  vector<vector<int>>
  findWinnersMyOriginalSolution(vector<vector<int>> &matches) {
    unordered_set<int> winners;
    unordered_set<int> losers;
    unordered_set<int> outsiders;

    for (auto &match : matches) {
      int winner = match[0];
      int loser = match[1];

      // process loser
      if (!outsiders.count(loser)) {
        if (losers.count(loser)) {
          losers.erase(loser);
          outsiders.insert(loser);
        } else if (winners.count(loser)) {
          winners.erase(loser);
          losers.insert(loser);
        } else {
          losers.insert(loser);
        }
      }

      // process winner
      if (!outsiders.count(winner) && !losers.count(winner)) {
        winners.insert(winner);
      }
    }

    vector<int> winnersVec(winners.begin(), winners.end());
    vector<int> losersVec(losers.begin(), losers.end());

    sort(winnersVec.begin(), winnersVec.end());
    sort(losersVec.begin(), losersVec.end());

    return {winnersVec, losersVec};
  }
};

int main() {
  Solution sol;

  vector<vector<int>> matches = {{1, 3}, {2, 3}, {3, 6}, {5, 6},  {5, 7},
                                 {4, 5}, {4, 8}, {4, 9}, {10, 4}, {10, 9}};
  vector<vector<int>> result = sol.findWinners(matches);
  assert(result == vector<vector<int>>({{1, 2, 10}, {4, 5, 7, 8}}));
  cout << "Test 1 passed! " << endl;

  cout << "All tests passed!" << endl;
  return 0;
}