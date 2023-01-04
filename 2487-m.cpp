// https://leetcode.com/problems/remove-nodes-from-linked-list/description/

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
class Solution
{
public:
    ListNode *removeNodes(ListNode *head)
    {
        ListNode *res = new ListNode(0), *curr = res;
        vector<int> rev = reverseList(head);

        stack<int> m;
        m.push(INT_MIN);

        for (auto r : rev)
            m.push(max(m.top(), r));

        for (; head != nullptr; head = head->next)
        {
            if (head->val >= m.top())
                curr->next = new ListNode(head->val), curr = curr->next;
            m.pop();
        }

        return res->next;
    }

private:
    vector<int> reverseList(ListNode *head)
    {
        vector<int> res;

        for (; head != nullptr; head = head->next)
            res.push_back(head->val);

        reverse(res.begin(), res.end());
        return res;
    }
};