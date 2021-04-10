#include <bits/stdc++.h>
#include "mycommon.hpp"
using namespace std;


/** \brief      helper  辅助函数
 *  \author     wzk
 *  \copyright  GNU Public License
 *  \version    1.0 
 *  \date       2020-4-10
 * 
 *  \param[in]  sequence   输入数组
 *  \param[in]  start      起始位置
 *  \param[in]  end        终止位置
 *  \return                是否合法的后序遍历
 */
vector<vector<int>> res;
void backtrack(TreeNode *root, int number, vector<int>& track) {
    if (root==nullptr)
        return;

    /**<注意：做选择和撤销选择中间不能有return */
    track.push_back(root->val);
    if (root->left==nullptr && root->right==nullptr && number==root->val) {     /**<叶子节点，值等于最number，找到一条路径 */
        res.push_back(track);
    }
    backtrack(root->left, number-root->val, track);
    backtrack(root->right, number-root->val, track);
    track.pop_back();
}

vector<vector<int>>& FindPath(TreeNode* root, int expectNumber) {
    vector<int> track;
    backtrack(root, expectNumber, track);
    return res;
}

int main(int argc, char *argv[])
{
    std::vector<int> nums = {10, 5, 12, 4, 7};
    TreeNode *tree = creatTree(nums, 0);

    vector<vector<int>> output = FindPath(tree, 22);
    for (const auto& e : output) {
        for (const auto & i : e)
            cout << i << " ";
        cout << '\n';
    }

    freeTree(tree);
    return 0;
}