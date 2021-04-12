#include <bits/stdc++.h>
#include "mycommon.hpp"
using namespace std;


/** \brief      printListFromTailToHead  从尾到头打印链表
 *  \author     wzk
 *  \copyright  GNU Public License
 *  \version    1.0 
 *  \date       2020-3-30
 * 
 *  \param[in] head     输入链表头节点
 *  \return             倒序输出链表
 */
vector<int> printListFromTailToHead(ListNode* head) {
    if (head == nullptr)
        return {};

    vector<int> res;
    stack<ListNode*> sta;
    for (ListNode *p = head; p != nullptr; p = p->next)
        sta.push(p);
    
    while(!sta.empty()) {
        res.push_back(sta.top()->val);
        sta.pop();
    }
    return  res;
}

int main(int argc, char *argv[])
{
    /**<创建链表 */
    vector<int> s = {1,2,3,4,5};
    ListNode *list = creatList(s);

    vector<int> output = printListFromTailToHead(list);       /**<do some job */
    for (const auto &e : output)
        cout << e << ' ';

    std::cout << "\n";

    freeList(list);                                          /**<删除链表 */

    return 0;
}