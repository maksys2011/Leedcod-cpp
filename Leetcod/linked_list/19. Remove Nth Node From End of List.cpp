struct ListNode {
      int val;
      ListNode *next;
      ListNode() : val(0), next(nullptr) {}
      ListNode(int x) : val(x), next(nullptr) {}
      ListNode(int x, ListNode *next) : val(x), next(next) {}
};
// Previous (предыдущий)
// Current (текущий)
// Next (следующий)

class Solution {
public:
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        
        if(head->next == nullptr && head->val == n) {
            ListNode* res(0);
            return res;
        }

        ListNode* tmp = head;
        int count = 0;
        while(tmp){
            count++;
            tmp = tmp->next;
        }
        int index = count - n;
        int position = 1;
        if(index == 1) return head->next;

        ListNode* previous = head;
        ListNode* current = head->next;

        while(current){
            if(position == index){
                ListNode* temp = current->next;
                delete current;
                current = temp;
                previous->next = current;
                return head;
            }
            previous = previous->next;
            current = current->next;
            position++;
        }
        return head;
    }
};
/*Input: head = [1,2,3,4,5], n = 2
Output: [1,2,3,5]
Example 2:

Input: head = [1], n = 1
Output: []
Example 3:

Input: head = [1,2], n = 1
Output: [1]*/

