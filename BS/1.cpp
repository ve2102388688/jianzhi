#include <bits/stdc++.h>
#include "mycommon.hpp"
using namespace std;


/** \brief      run  二叉树的最小深度
 *  \author     wzk
 *  \copyright  GNU Public License
 *  \version    1.0 
 *  \date       2020-3-31
 *  \remark     层序遍历，一定是最近的
 * 
 *  \param[in] root   二叉树根结点
 *  \return           二叉树的最小深度
 */
int run(TreeNode* root) {
    if (root == nullptr)
        return 0;
    
    int minDepth = 1;                                                   /**<起始深度 */
    queue<TreeNode*> Q;
    Q.push(root);
    while(!Q.empty()) {
        int size = Q.size();
        while (size) {
            TreeNode *node = Q.front(); Q.pop();
            if (node->left == nullptr && node->right == nullptr)        /**<最小的深度 */
                return minDepth;
            if (node->left != nullptr) Q.push(node->left);
            if (node->right != nullptr) Q.push(node->right);
            --size;
        }
        ++minDepth;
    }
    return minDepth;
}


/** \brief      run  二叉树的最小深度
 *  \author     wzk
 *  \copyright  GNU Public License
 *  \version    1.0 
 *  \date       2020-3-31
 *  \remark     递归，框架不变，只是用minDepth记住了答案而已
 * 
 *  \param[in] root   二叉树根结点
 *  \return           二叉树的最小深度
 */
int run(TreeNode* root) {
    if (root == nullptr)
        return 0;
    if (root->left==nullptr && root->right==nullptr)
        return 1;
    
    int minDepth = INT_MAX;
    if (root->left != nullptr)
        minDepth = min(minDepth, run(root->left));
    if (root->right != nullptr)
        minDepth = min(minDepth, run(root->right));
    return minDepth + 1;
}

int main(int argc, char *argv[])
{
    std::vector<int> nums = {4, 2, 7, -1, -1, -1, 9};
    TreeNode *tree = creatTree(nums, 0);

    std::cout << run(tree) << '\n';

    freeTree(tree);
    return 0;
}