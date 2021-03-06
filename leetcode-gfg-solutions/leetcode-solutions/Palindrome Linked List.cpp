// https : // leetcode.com/problems/palindrome-linked-list/

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
    bool isPalindrome(ListNode *head)
    {
        string str1 = "";
        ListNode *temp = head;

        while (temp != NULL)
        {
            str1 += temp->val;
            temp = temp->next;
        }

        string str2 = str1;
        reverse(str2.begin(), str2.end());

        return str1 == str2;
    }
};

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
    ListNode *reverseList(ListNode *head)
    {
        ListNode *dummy = NULL;

        while (head != NULL)
        {
            ListNode *n = head->next;
            head->next = dummy;
            dummy = head;
            head = n;
        }

        return dummy;
    }

    bool isPalindrome(ListNode *head)
    {

        ListNode *fast = head;
        ListNode *slow = head;

        while (fast->next != NULL and fast->next->next != NULL)
        {
            slow = slow->next;
            fast = fast->next->next;
        }

        slow->next = reverseList(slow->next);
        slow = slow->next;

        while (slow != NULL)
        {
            if (head->val != slow->val)
            {
                return false;
            }

            head = head->next;
            slow = slow->next;
        }

        return true;
    }
};