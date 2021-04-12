#include <bits/stdc++.h>
#include "mycommon.hpp"
using namespace std;

struct RandomListNode {
    int label;
    struct RandomListNode *next, *random;
    RandomListNode(int x) :
            label(x), next(NULL), random(NULL) {
    }
};



/** \brief      ReverseList  反转链表
 *  \author     wzk
 *  \copyright  GNU Public License
 *  \version    1.0 
 *  \date       2020-4-7
 */
void copyCurr(RandomListNode* pHead) {
    for (RandomListNode *p = pHead; p != nullptr; p = p->next->next) {
        RandomListNode *copy1Time = new RandomListNode(p->label);
        copy1Time->next = p->next;
        copy1Time->random = nullptr;
        
        p->next = copy1Time;
    }
}

void cennectRandom(RandomListNode* pHead) {
    for (RandomListNode *p = pHead; p != nullptr; p = p->next->next) {
        if (p->random != nullptr) {
            p->next->random = p->random->next;
        }
    }
}

RandomListNode* split(RandomListNode* pHead) {
    RandomListNode *newHead = pHead->next;
    RandomListNode *p1 = pHead->next;
    for (RandomListNode *p = pHead; p != nullptr;) {
        p->next = p1->next;
        p1->next = p1->next->next;
        
        p = p->next->next;
        p1 = p1->next;
    }
    return newHead;
}

RandomListNode* Clone(RandomListNode* pHead) {
    if (pHead == nullptr)
        return nullptr;
    copyCurr(pHead);
    cennectRandom(pHead);
    return split(pHead);
}


int main(int argc, char *argv[])
{
    vector<vector<int>> matrix = {{1, 2,3}, {4, 5,6}, {7,8,9}};
    vector<int> output = printMatrix(matrix);
    for (const auto&e : output)
        cout << e << ' ';
    cout << '\n';

    return 0;
}