[环形链表II](https://leetcode.cn/problems/linked-list-cycle-ii/)

第一次做思路很难想到

![思路图](https://code-thinking-1253855093.file.myqcloud.com/pics/20220925103433.png)

设置快慢指针，快指针一次步进两步、慢指针一次步进一步，如果遇到 `next` 为空则没有环。

如果有环的话快指针和慢指针一定会相遇：快指针每次与慢指针的步进只差一步，所以相对慢指针来说，快指针在一步一步追上它。

这时慢指针走了 `x + y` 步，快指针走了 `x + y + (y + z) * n` 步，而快指针的步数一共是慢指针的二倍，所以得出等式 `(x + y) * 2 = x + y + (y + z) * n`，约得 `x + y = (y + z) * n`。

我们要求的环形入口点即 x ，再次约分得出 `x = (n - 1)(y + z) + z`

此时在快慢指针相遇的地点设置指针 `meet` ，在头指针设置 `cur` 

观察得出，当 n = 1 时，等式变成 `x = z` 即 `meet` 和 `cur` 指针同时步进，相遇点即为环形入口。

注意 n 一定是大于等于 1 的，因为快指针先入环，慢指针后入环，所以快指针至少要走一圈才可能追上慢指针。

当 n 大于 1 时，上述方法同样适用，因为在等式 `x = (n - 1)(y + z) + z` 中，另一边除开 z 以外，只是多循环了几次环路而已，不影响两指针在环形入口处相遇。

```c++
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    ListNode* detectCycle(ListNode* head) {
        ListNode* slow = head;
        ListNode* fast = head;
        do {
            if (fast == NULL || fast->next == NULL) {
                return NULL;
            }
            slow = slow->next;
            fast = fast->next->next;
        } while (slow != fast);
        ListNode* cur = head;
        ListNode* meet = slow;
        while (cur != meet) {
            cur = cur->next;
            meet = meet->next;
        }
        return cur;
    }
};

```