#include <utility>

struct ListNode {
      int val;
      ListNode *next;
      ListNode() : val(0), next(nullptr) {}
      ListNode(int x) : val(x), next(nullptr) {}
      ListNode(int x, ListNode *next) : val(x), next(next) {}
 };
 
class Solution {
public:
    ListNode* swapPairs(ListNode* head) {
        if(head == nullptr || head->next == nullptr) return head;
        ListNode* prev = head;
        ListNode* current = head->next;
        int count = 2;
        while(current != nullptr){
            if(count == 2){
                std::swap(prev->val, current->val);
                count = 0;
            }
            count++;
            prev = prev->next;
            current = current->next;
        }
        return head;
    }
};