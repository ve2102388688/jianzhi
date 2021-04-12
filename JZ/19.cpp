#include <bits/stdc++.h>
#include "mycommon.hpp"
using namespace std;


/** \brief      printMatrix  顺时针打印矩阵
 *  \author     wzk
 *  \copyright  GNU Public License
 *  \version    1.0 
 *  \date       2020-4-7
 */
vector<int> printMatrix(vector<vector<int>>& matrix) {
    int m = matrix.size();
    int n = matrix[0].size();
    
    int size = m * n;
    vector<int> res;
    for (int k = 0, cycle = 0, i = 0, j = 0; k < size; ) {
        while (j < n-cycle) {
            res.push_back(matrix[i][j]);
            ++j, ++k;
        }
        if (k >= size)
            break;

        --j;                                    /**<每次遍历方向回退一个，另外一个方向前进1 */
        while (++i < m-cycle) {
            res.push_back(matrix[i][j]);
            ++k;
        }
        if (k >= size)
            break;

        --i;
        while (--j >= cycle) {
            res.push_back(matrix[i][j]);
            ++k;
        }
        if (k >= size)
            break;

        ++j;
        while (--i >= cycle+1) {
            res.push_back(matrix[i][j]);
            ++k;
        }
        if (k >= size)
            break;

        ++i, ++j;
        ++cycle;                                /**<圈的数目加1 */
    }
    return res;
}


int main(int argc, char *argv[])
{
    vector<vector<int>> matrix = {{1, 2,3}, {4, 5,6}, {7,8,9}};
    vector<int> output = printMatrix(matrix);
    for (const auto&e : output)
        cout << e << ' ';
    cout << '\n';

    return 0;
}