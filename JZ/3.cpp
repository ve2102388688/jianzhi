#include <bits/stdc++.h>
#include "mycommon.hpp"
using namespace std;


/** \brief      createTree  辅助函数
 *  \author     wzk
 *  \copyright  GNU Public License
 *  \version    1.0 
 *  \date       2020-3-30
 * 
 *  \param[in] preorder 输入pre数组
 *  \param[in] preStart 输入preStart左闭
 *  \param[in] preEnd   输入preEnd右闭
 *  \param[in] vin      输入vin数组
 *  \param[in] vinStart 输入inStart左闭
 *  \param[in] vinEnd   输入inEnd右闭
 *  \param[in] memo     输入中序遍历的hash表
 *  \return             返回二叉树
 */
TreeNode* createTree(vector<int>& pre, int preStart, int preEnd, vector<int>& vin, int vinStart, int vinEnd, unordered_map<int, int>& memo) {
    if (preStart>preEnd || vinStart>vinEnd)         /**<非法输入 */
        return nullptr;

    TreeNode *root = new TreeNode(pre[preStart]);                   /**<创建根结点 */
    int posRootInVin = memo.find(pre[preStart])->second;            /**<查找位置 */
    int leftNum = posRootInVin-vinStart;
    root->left = createTree(pre, preStart+1, preStart+leftNum, vin, vinStart, posRootInVin-1, memo);
    root->right = createTree(pre, preStart+leftNum+1, preEnd, vin, posRootInVin+1,vinEnd, memo);
    return root;
}

TreeNode* reConstructBinaryTree(vector<int>& pre,vector<int>& vin) {
    int sizePre = pre.size();
    int sizeVin = vin.size();
    if (sizePre == 0)
        return nullptr;
    
    unordered_map<int, int> memo;       /**<提高查找速度 */
    for(int i = 0; i < sizeVin; ++i)
        memo[vin[i]] = i;
    
    return createTree(pre, 0, sizePre-1, vin, 0, sizeVin-1, memo);
}

int main(int argc, char *argv[])
{
    std::vector<int> preorder = {3,9,20,15,7};
    std::vector<int> inorder = {9,3,15,20,7};
    TreeNode *tree = reConstructBinaryTree(preorder, inorder);

    printTree(tree);
    std::cout << '\n';

    freeTree(tree);

    return 0;
}