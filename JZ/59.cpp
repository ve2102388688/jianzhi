#include <bits/stdc++.h>
#include "mycommon.hpp"
using namespace std;


/** \brief      Print  s形打印二叉树
 *  \author     wzk
 *  \copyright  GNU Public License
 *  \version    1.0 
 *  \date       2020-4-10
 * 
 *  \param[in]  root    二叉树的根结点
 *  \return             层序输出
 */
vector<vector<int>> Print2(TreeNode* pRoot) {
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


vector<vector<int>> Print(TreeNode* pRoot) {
    if (pRoot == nullptr)
        return {};
    
    vector<vector<int>> res;
    stack<TreeNode *> sta[2];               /**<一共两个栈，从每层取数据并从另外一个栈存数据 */
    int cur = 0, next = 1;                 /**<cur取数据，next存数据 */
    
    sta[cur].push(pRoot);
    while (!sta[0].empty() || !sta[1].empty()) {
        int size = sta[cur].size();
        vector<int> temp;
        while (size) {
            TreeNode *node = sta[cur].top(); sta[cur].pop();
            temp.push_back(node->val);

            if (cur==0) {                                       /**<先左后右 */
                if (node->left) sta[next].push(node->left);
                if (node->right) sta[next].push(node->right);
            } else {                                            /**<先右后左 */
                if (node->right) sta[next].push(node->right);
                if (node->left) sta[next].push(node->left);
            }
            --size;
        }
        cur = 1-cur;
        next = 1-next;
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