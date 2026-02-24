#include <cassert>
#include <iostream>
#include <unordered_set>
#include <vector>
using namespace std;

/*
clang++ -std=c++17 problems/linkedL.reverseBetween.cpp && ./a.out
*/

struct ListNode {
  int val;
  ListNode *next;
  ListNode(int x) : val(x), next(nullptr) {}
};

/**
 * @problem Reverse Between
 * @description Given the head of a singly linked list and two integers left and
 * right where left <= right, reverse the nodes of the list from position left
 * to position right, and return the reversed list.
 * @link https://leetcode.com/problems/reverse-linked-list-ii
 * Time: O(n)
 * Space: O(1)
 */
class Solution {
public:
  ListNode *reverseBetween(ListNode *head, int left, int right) {
    if (!head || left == right)
      return head;

    ListNode dummy(0);
    dummy.next = head;
    ListNode *prev = &dummy;

    // Step 1: move prev to node before left
    for (int i = 1; i < left; i++) {
      prev = prev->next;
    }

    ListNode *curr = prev->next;

    // Step 2: reverse sublist
    for (int i = 0; i < right - left; i++) {
      ListNode *temp = curr->next;
      curr->next = temp->next;
      temp->next = prev->next;
      prev->next = temp;
    }

    return dummy.next;
  }
};

int main() {
  Solution sol;

  ListNode *input = new ListNode(1);
  input->next = new ListNode(2);
  input->next->next = new ListNode(3);
  input->next->next->next = new ListNode(4);
  input->next->next->next->next = new ListNode(5);
  ListNode *result = sol.reverseBetween(input, 2, 4);

  ListNode *output = new ListNode(1);
  output->next = new ListNode(4);
  output->next->next = new ListNode(3);
  output->next->next->next = new ListNode(2);
  output->next->next->next->next = new ListNode(5);

  while (result && output) {
    assert(result->val == output->val);
    result = result->next;
    output = output->next;
  }
  cout << "Test 1 passed! " << endl;

  cout << "All tests passed!" << endl;
  return 0;
}