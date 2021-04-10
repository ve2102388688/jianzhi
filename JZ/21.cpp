#include <bits/stdc++.h>
using namespace std;


/** \brief      IsPopOrder  合法出栈顺序
 *  \author     wzk
 *  \copyright  GNU Public License
 *  \version    1.0 
 *  \date       2020-4-9
 * 
 *  \param[in]  pushV   压栈顺序
 *  \param[in]  popV    出栈顺序
 *  \return             是否是合法出栈顺序
 */
bool IsPopOrder(vector<int> pushV,vector<int> popV) {
    int size = pushV.size();
    int size2 = popV.size();
    if (size != size2)
        return false;

    stack<int> sta;
    for (int i = 0, j = 0; i < size; ++i) {
        sta.push(pushV[i]);
        
        /**<只要和栈顶元素相等，需要一直弹出 */
        while (!sta.empty() && sta.top() == popV[j]) {
            sta.pop();
            ++j;                                        /**<出栈数组下标 */ 
        }        
    }
    return sta.empty();                                 /**<为空则是合法出栈顺序 */
}


int main(int argc, char *argv[])
{
    vector<int> num = {1, 2, 3, 4, 5};
    vector<int> num2 = {4, 5, 3, 2, 1};

    bool output = IsPopOrder(num, num2);
    cout << output << '\n';


    return 0;
}