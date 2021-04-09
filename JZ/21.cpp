#include <bits/stdc++.h>
#include "mycommon.hpp"
using namespace std;


/** \brief      IsPopOrder  反转链表
 *  \author     wzk
 *  \copyright  GNU Public License
 *  \version    1.0 
 *  \date       2020-4-7
 * 
 *  \param[in]  pushV   压栈顺序
 *  \param[in]  popV    出栈顺序
 *  \return             是否是合法出栈顺序
 */
bool IsPopOrder(vector<int> pushV,vector<int> popV) {
    
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