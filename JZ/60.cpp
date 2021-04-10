#include <bits/stdc++.h>
#include "mycommon.hpp"
using namespace std;


/** \brief      Print  从上往下打印二叉树
 *  \author     wzk
 *  \copyright  GNU Public License
 *  \version    1.0 
 *  \date       2020-4-10
 * 
 *  \param[in]  root    二叉树的根结点
 *  \return             层序输出
 */
vector<vector<int>> Print(TreeNode* pRoot) {
    if (pRoot == nullptr)
        return {};
    
    vector<vector<int>> res;
    queue<TreeNode*> Q;
    Q.push(pRoot);
    while (!Q.empty()) {
        vector<int> temp;
        int size = Q.size();
        while (size) {
            TreeNode *node = Q.front(); Q.pop();
            temp.push_back(node->val);
            if (node->left) Q.push(node->left);
            if (node->right) Q.push(node->right);
            --size;
        }
        res.push_back(temp);
    }
    return res;
}


int main(int argc, char *argv[])
{
    std::vector<int> nums = {1, 2, 3, 4, 5};
    TreeNode *tree = creatTree(nums, 0);

    vector<vector<int>> output = Print(tree);
    for (const auto& e : output) {
        for (const auto & i : e)
            cout << i << " ";
        cout << '\n';
    }

    freeTree(tree);
    return 0;
}