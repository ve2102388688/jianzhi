#include <bits/stdc++.h>
#include "mycommon.hpp"
using namespace std;


bool helper(TreeNode *root1, TreeNode *root2) {
    if (root1 == nullptr && root2 == nullptr)
        return true;
    else if (root1 == nullptr || root2 == nullptr)
        return false;
    
    return (root1->val==root2->val) && helper(root1->left, root2->right) && helper(root1->right, root2->left);
}

/** \brief      isSymmetrical  对称的二叉树
 *  \author     wzk
 *  \copyright  GNU Public License
 *  \version    1.0 
 *  \date       2020-4-9
 * 
 *  \param[in]  pRoot   二叉树跟结点
 *  \return             是否是对称二叉树
 */
bool isSymmetrical(TreeNode* pRoot) {
    return helper(pRoot->left, pRoot->right);           /**<左右子树是否对称 */
}


int main(int argc, char *argv[])
{
    std::vector<int> nums = {1, 2, 3, 4, 5};
    TreeNode *tree = creatTree(nums, 0);

    bool output = isSymmetrical(tree);
    cout << output << '\n';

    freeTree(tree);
    return 0;
}