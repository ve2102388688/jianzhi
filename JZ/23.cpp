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
bool helper(vector<int>& sequence, int start, int end) {
    if(start > end)
        return false;
    int rootVal = sequence[end];
    
    int i = start;
    for (; i < end; ++i)                            /**<找到第一个大于根结点的结点 */
        if (sequence[i] > rootVal)
            break;
    
    int j = i;
    for (; j < end; ++j)                            /**<后续结点有小于根结点，false */
        if (sequence[j] < rootVal)
            return false;
    
    bool left = true;                               /**<i只有大于start才有左子树 */
    if (i > start)
        left = helper(sequence, start, i-1);        /**<[start, i-1] */
    
    bool right = true;                              /**<i只有小于end才有右子树，不能取等于，因为最后一个是根结点 */
    if (i < end)
        right = helper(sequence, i, end-1);
    
    return (left&&right);
}

bool VerifySquenceOfBST(vector<int>& sequence) {
    return helper(sequence, 0, sequence.size()-1);
}

int main(int argc, char *argv[])
{
    std::vector<int> nums = {7,4,6,5};
    bool output = VerifySquenceOfBST(nums);
    cout << output << '\n';

    return 0;
}