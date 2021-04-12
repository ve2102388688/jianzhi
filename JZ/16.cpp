#include <bits/stdc++.h>
#include "mycommon.hpp"
using namespace std;


/** \brief      ReverseList  合并两个排序的链表
 *  \author     wzk
 *  \copyright  GNU Public License
 *  \version    1.0 
 *  \date       2020-4-7
 * 
 *  \param[in]  pHead1 链表头节点1
 *  \param[in]  pHead2 链表头节点2
 */
ListNode* Merge(ListNode* pHead1, ListNode* pHead2) {
    /**<有一个为空，都会从这里出去 */
    if (pHead1 == nullptr)
        return pHead2;
    else if (pHead2 == nullptr)
        return pHead1;
    
    ListNode *p1 = nullptr;
    ListNode *p2 = nullptr;
    ListNode *newHead = nullptr;
    ListNode *p = nullptr;
    if (pHead1->val < pHead2->val) {        /**<这里没有用额外节点，只有判断小的元素作为开头 */
        newHead = pHead1;
        p = newHead;
        p1 = pHead1->next;
        p2 = pHead2;
    } else {
        newHead = pHead2;
        p = newHead;
        p1 = pHead1;
        p2 = pHead2->next;
    }
    
    
    while (p1 && p2) {
        if (p1->val <= p2->val) {           /**<比较小的元素加入进来 */
            p->next = p1;
            p = p->next;
            
            p1 = p1->next;
        } else {
            p->next = p2;
            p = p->next;
            
            p2 = p2->next;
        }
    }
    
    /**<只会有一个是空的 */
    if (p1)
        p->next= p1;
    else
        p->next= p2;
    return newHead;
}


int main(int argc, char *argv[])
{
    /**<创建链表 */
    vector<int> s = {1,3,5};
    ListNode *list = creatList(s);
    vector<int> s2 = {2,4,6};
    ListNode *list2 = creatList(s2);

    ListNode *output = Merge(list, list2);       /**<do some job */

    printList(output);
    std::cout << "\n";

    freeList(output);                            /**<删除链表 */
    return 0;
}