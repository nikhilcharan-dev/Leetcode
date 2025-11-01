/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
public:
    ListNode* modifiedList(vector<int>& nums, ListNode* head) {
        unordered_map<int, int> mp;
        for(auto& num: nums) mp[num]++;
        while(head && mp[head->val] && head->next) {
            head = head->next;
        }

        if(!head || !head->next) return head;

        ListNode* prev = head;
        ListNode* temp = head->next;
        while(temp) {
            if(mp[temp->val]) {
                prev->next = temp->next;
                prev = prev->next;
            }
            prev = temp;
            temp = temp->next;
        }

        return head;
    }
};