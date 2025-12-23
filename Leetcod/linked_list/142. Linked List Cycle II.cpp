struct ListNode {
      int val;
      ListNode *next;
      ListNode(int x) : val(x), next(nullptr) {}
 };
 
class Solution {
public:
    ListNode *detectCycle(ListNode *head) {
        if(!head  || !head->next) return nullptr;

        ListNode* turtle = head;
        ListNode* cheetah = head;

        while(cheetah && cheetah->next){
            turtle = turtle->next;
            cheetah = cheetah->next->next;

          if(turtle == cheetah){
            ListNode* ptr1 = head;
            ListNode* ptr2 = cheetah;

            while(ptr1 != ptr2){
              ptr1 = ptr1->next;
              ptr2 = ptr2->next;
            }
            return ptr1;
          }
        }
        return nullptr;
    }
};