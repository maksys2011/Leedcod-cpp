struct ListNode {
      int val;
      ListNode *next;
      ListNode() : val(0), next(nullptr) {}
      ListNode(int x) : val(x), next(nullptr) {}
     ListNode(int x, ListNode *next) : val(x), next(next) {}
};
 
class Solution {
public:
    ListNode* rotateRight(ListNode* head, int k) {
      if(head == nullptr || head->next == nullptr) return head;
      ListNode* temporary = head;
      int count = 0;
      while(temporary != nullptr){
        count++;
        temporary = temporary->next;
      }
      int effective_k = k % count;
      ListNode* tmp = head;
      while(effective_k > 0){
        ListNode* res = rotate(tmp, k);
        tmp = res;
        effective_k--;
      }
      return tmp; 
    }
    ListNode* rotate(ListNode* head, int k){
      if(head->next == nullptr) return head;
      
      ListNode* current = head;
      ListNode* next = head->next;
      
      while(next->next != nullptr){
        current = current->next;
        next = next->next;
      }

      next->next = head;
      current->next = nullptr;
      
      return next;
    }
};