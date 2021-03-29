#include <bits/stdc++.h>
using namespace std;


/** \brief      Find 二维数组中查找
 *  \author     wzk
 *  \copyright  GNU Public License
 *  \version    1.0 
 *  \date       2020-1-31
 * 
 *  \param[in] target   目标值
 *  \param[in] array    输入二维数组
 *  \return             返回下标位置
 */
bool Find(int target, vector<vector<int>>& array) {
    int m = array.size();
    int n = array[0].size();
    
    int i = m-1, j = 0;                         /**<左下角开始搜索 */
    while (i>=0 && i<m && j>=0 && j<n){         /**<合法的下标范围 */
        if (array[i][j] == target)
            return true;
        else if(array[i][j] < target)           /**<向右走一步 */
            ++j;
        else                                    /**<向上走一步 */
            --i;
    }
    return false;
}


int main(int argc, char *argv[])
{
    vector<vector<int>> nums = { { 1, 2, 8, 9 }, { 2, 4, 9, 12 }, { 4, 7, 10, 13 }, { 6, 8, 11, 15 } };
    bool output = Find(7, nums);
    cout << output << '\n';

    return 0;
}