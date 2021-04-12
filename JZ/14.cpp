#include <bits/stdc++.h>
#include "mycommon.hpp"
using namespace std;


/** \brief      FindKthToTail  链表中倒数第k个结点
 *  \author     wzk
 *  \copyright  GNU Public License
 *  \version    1.0 
 *  \date       2020-4-7
 * 
 *  \param[in]  pHead   链表头结点
 *  \param[in]  k       输入k
 */
ListNode* FindKthToTail(ListNode* pHead, int k) {
    if (pHead == nullptr)
        return nullptr;

    ListNode *fast = pHead;                     /**<快指针先走K步 */
    while (k--) {
        if (fast == nullptr)
            return nullptr;
        fast = fast->next;
    }
    
    ListNode *slow = pHead;                     /**<快慢指针同时走 */
    while (fast != nullptr) {
        fast = fast->next;
        slow = slow->next;
    }
    return slow;
}

int main(int argc, char *argv[])
{
    /**<创建链表 */
    vector<int> s = {1,2,3,4,5};
    ListNode *list = creatList(s);

    list = FindKthToTail(list, 2);       /**<do some job */

    printList(list);
    std::cout << "\n";

    freeList(list);                      /**<删除链表 */
    return 0;
}