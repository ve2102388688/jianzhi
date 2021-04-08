#include <bits/stdc++.h>
#include "mycommon.hpp"
using namespace std;


/** \brief      Mirror  二叉树的镜像
 *  \author     wzk
 *  \copyright  GNU Public License
 *  \version    1.0 
 *  \date       2020-4-8
 * 
 *  \param[in]  pRoot   二叉树跟结点
 *  \return             镜像二叉树
 */
TreeNode* Mirror(TreeNode* pRoot) {
    if (pRoot == nullptr)
        return nullptr;
    Mirror(pRoot->left);
    Mirror(pRoot->right);
    std::swap(pRoot->left, pRoot->right);
    
    return pRoot;
}


int main(int argc, char *argv[])
{
    std::vector<int> nums = {1, 2, 3, 4, 5};
    TreeNode *tree = creatTree(nums, 0);

    tree = Mirror(tree);
    printTree(tree);
    cout << '\n';

    freeTree(tree);
    return 0;
}