#include <bits/stdc++.h>
#include "mycommon.hpp"
using namespace std;


bool isSame(TreeNode *s, TreeNode *t) {
    if (t == nullptr)               /**<注意顺序，t树空，已经到头了 */
        return true;
    if (s == nullptr)               /**<注意顺序，s树空，失败 */
        return false;
    if (s->val != t->val)
        return false;
    return isSame(s->left, t->left) && isSame(s->right, t->right);
}


/** \brief      HasSubtree  反转链表
 *  \author     wzk
 *  \copyright  GNU Public License
 *  \version    1.0 
 *  \date       2020-4-7
 */
bool HasSubtree(TreeNode* pRoot1, TreeNode* pRoot2) {
    bool ans = false;
    if (pRoot2 != nullptr && pRoot1 != nullptr) {
        if (pRoot1->val == pRoot2->val)                         /**<根结点相等，判断子树是否相等 */
            ans = isSame(pRoot1, pRoot2);
        /**<不相等继续判断左右子树 */
        if (!ans)
            ans = HasSubtree(pRoot1->left, pRoot2);     
        if (!ans)
            ans = HasSubtree(pRoot1->right, pRoot2);
    }
    return ans;
}


int main(int argc, char *argv[])
{
    std::vector<int> nums = {1, 2, 3, 4, 5};
    std::vector<int> nums2 = {1, 2, -1, 4};
    TreeNode *tree = creatTree(nums, 0);
    TreeNode *tree2 = creatTree(nums2, 0);

    bool output = HasSubtree(tree, tree2);
    std::cout << output << '\n';

    freeTree(tree);
    freeTree(tree2);
    return 0;
    return 0;
}