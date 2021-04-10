#include <bits/stdc++.h>
#include "mycommon.hpp"
using namespace std;


/** \brief      PrintFromTopToBottom  从上往下打印二叉树
 *  \author     wzk
 *  \copyright  GNU Public License
 *  \version    1.0 
 *  \date       2020-4-10
 * 
 *  \param[in]  root    二叉树的根结点
 *  \return             层序输出
 */
vector<int> PrintFromTopToBottom(TreeNode* root) {
    if (root == nullptr)
        return {};
    vector<int> res;
    queue<TreeNode*> Q;
    Q.push(root);
    while (!Q.empty()) {
        int size = Q.size();
        while (size) {
            TreeNode *node = Q.front(); Q.pop();
            res.push_back(node->val);
            if (node->left) Q.push(node->left);
            if (node->right) Q.push(node->right);
            --size;
        }
    }
    return res;
}


int main(int argc, char *argv[])
{
    std::vector<int> nums = {1, 2, 3, 4, 5};
    TreeNode *tree = creatTree(nums, 0);

    vector<int> output = PrintFromTopToBottom(tree);
    for (const auto& e : output)
        cout << e << " ";
    cout << '\n';

    freeTree(tree);
    return 0;
}