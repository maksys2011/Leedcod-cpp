#include <unordered_map>

struct ListNode {
      int val;
      ListNode *next;
      ListNode(int x) : val(x), next(NULL) {}
 };
 
class Solution {
public:
    bool hasCycle(ListNode *head) {
        std::unordered_map<ListNode*, int>hash_table;
        while (head != nullptr) {
            if (hash_table.count(head)) {
                return true;
            }
            else {
                hash_table.insert({ head, head->val });
            }
            head = head->next;
        }
        return false;
    }
};