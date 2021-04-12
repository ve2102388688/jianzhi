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


/** \brief      Clone  拷贝复制链表
 *  \author     wzk
 *  \copyright  GNU Public License
 *  \version    1.0 
 *  \date       2020-4-12
 * 
 *  \param[in]  pHead   输入头节点
 *  \return             拷贝链表
 */
RandomListNode* Clone(RandomListNode* pHead) {
    if (pHead == nullptr)
        return nullptr;
    
    /**<拷贝一份一样的结点 */
    for (RandomListNode *p = pHead; p != nullptr; p = p->next->next) {
        RandomListNode *copy1Time = new RandomListNode(p->label);
        copy1Time->next = p->next;
        
        p->next = copy1Time;
    }
    
    /**<修改random指针 */
    for (RandomListNode *p = pHead; p != nullptr; p = p->next->next) {
        if (p->random != nullptr) {
            p->next->random = p->random->next;
        }
    }
    
    /**<奇偶链表 */
    RandomListNode *evenHead = pHead->next;
    RandomListNode *pEven = pHead->next;
    RandomListNode *pOdd = pHead;
    while (pEven->next != nullptr) {
        pOdd->next = pOdd->next->next;
        pEven->next = pEven->next->next;
        pOdd = pOdd->next;
        pEven = pEven->next;
    }
    pOdd->next = nullptr;                   /**<需要加上 */
    return evenHead;
}

void PrintRandomListNode(RandomListNode* head) {
	if (head == NULL) {
		printf("%s", "{}");
		return;
	}
	RandomListNode* current = head;
	printf("%s", "{");
	while (current != NULL) {
		if (current == head) {
			printf("%d", current->label);
		} else {
			printf(",%d", current->label);
		}
		current = current->next;
	}
	current = head;
	while (current != NULL) {
		if (current->random != NULL) {
			printf(",%d", current->random->label);
		} else {
			printf("%s", ",#");
		}
		current = current->next;
	}
	printf("%s", "}");
}

void freeRandomListNode(RandomListNode *head) {
    if (head == nullptr)
        return ;
    freeRandomListNode(head->next);
    head->random = nullptr;
    delete head;
}

int main(int argc, char *argv[])
{
   	// { -1, 8, 7, -3,4, 4,-3,#,#,8}
	RandomListNode* rlnode1 = new RandomListNode(-1);
	RandomListNode* rlnode2 = new RandomListNode(8);
	RandomListNode* rlnode3 = new RandomListNode(7);
	RandomListNode* rlnode4 = new RandomListNode(-3);
	RandomListNode* rlnode5 = new RandomListNode(4);
	rlnode1->next = rlnode2;
	rlnode2->next = rlnode3;
	rlnode3->next = rlnode4;
	rlnode4->next = rlnode5;
	rlnode1->random = rlnode5;
	rlnode2->random = rlnode4;
	rlnode5->random = rlnode2;
	PrintRandomListNode(rlnode1);
	printf("\n");

    RandomListNode *output = Clone(rlnode1);
    PrintRandomListNode(output);
	printf("\n");

    freeRandomListNode(rlnode1);
    freeRandomListNode(output);

    return 0;
}