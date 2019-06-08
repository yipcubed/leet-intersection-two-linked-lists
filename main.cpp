#include <iostream>
#include <set>

using namespace std;

/**
 * Definition for singly-linked list.
*/

 struct ListNode {
  int val;
  ListNode *next;
  ListNode(int x) : val(x), next(NULL) {}
 };

class Solution {
public:
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
        ListNode *pA = headA;
        ListNode *pB = headB;
        bool swapA = false;
        bool swapB = false;
        if (!pA || ! pB)
            return nullptr;
        while (pA && pB && pA != pB) {
          pA = pA->next;
          pB = pB->next;
          if (!pA && !swapA) {
            pA = headB;
            swapA = true;
          }
          if (!pB && !swapB) {
            pB = headA;
            swapB = true;
          }
        }
        return pA;
    }
    ListNode *getIntersectionNodeOld(ListNode *headA, ListNode *headB) {
        set<ListNode*> seen;
        while (headA) {
          seen.insert(headA);
          headA = headA->next;
        }
        while (headB && !seen.count(headB)) {
          headB = headB->next;
        }
        if (headB)
          return headB;
        else
          return nullptr;
    }
};

int main() {
  Solution S;

  ListNode *l1 = new ListNode(4);
  l1->next =  new ListNode(1);
  l1->next->next =  new ListNode(8);
  l1->next->next->next =  new ListNode(4);
  l1->next->next->next->next =  new ListNode(5);

  ListNode *l2 = new ListNode(5);
  l2->next =  new ListNode(0);
  l2->next->next =  new ListNode(1);
  l2->next->next->next = l1->next->next;

  cout << "8? " << S.getIntersectionNode(l1, l2)->val << endl;
  cout << "8? " << S.getIntersectionNode(l2, l1)->val << endl;

  ListNode *l3 = new ListNode(2);
  l3->next =  new ListNode(6);
  l3->next->next =  new ListNode(4);

  cout << "null? " << S.getIntersectionNode(l3, l2) << endl;
  cout << "null? " << S.getIntersectionNode(l2, l3) << endl;

  std::cout << "Hello World!\n";
}