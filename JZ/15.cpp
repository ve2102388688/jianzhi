#include <bits/stdc++.h>
#include "mycommon.hpp"
using namespace std;


/** \brief      ReverseList  反转链表
 *  \author     wzk
 *  \copyright  GNU Public License
 *  \version    1.0 
 *  \date       2020-4-7
 */
ListNode* ReverseList(ListNode* pHead) {
    if (pHead == nullptr)
        return nullptr;
    
    ListNode *newHead = nullptr;
    ListNode *p = pHead; 
    while(p != nullptr) {
        ListNode *temp = p->next;
        p->next = newHead;
        newHead = p;
        p = temp;
    }
    return newHead;
}


int main(int argc, char *argv[])
{
    /**<创建链表 */
    vector<int> s = {1,2,3,4,5};
    ListNode *list = creatList(s);

    list = ReverseList(list);       /**<do some job */

    printList(list);
    std::cout << "\n";

    freeList(list);                  /**<删除链表 */
    return 0;
}