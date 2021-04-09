#include <bits/stdc++.h>
using namespace std;


/** \brief      Solution  包含min函数的栈
 *  \author     wzk
 *  \copyright  GNU Public License
 *  \version    1.0 
 *  \date       2020-4-9
 */
class Solution {
public:
    void push(int value) {
        m_sta.push(value);                      /**<原始数据直接压入 */
        
        /**<最小栈压入最小的，否则copy一份 */
        if (m_minSta.empty() || m_minSta.top()>=value)
            m_minSta.push(value);
        else
            m_minSta.push(m_minSta.top());
    }
    
    void pop() {                                /**<弹出两份 */
        m_sta.pop();
        m_minSta.pop();
    }
    
    int top() {
        return m_sta.top();                     /**<原始数据 */
    }
    
    int min() {
        return m_minSta.top();                  /**<最小栈顶是最小的元素 */
    }
    
private:
    stack<int> m_sta;                           /**<原始数据 */
    stack<int> m_minSta;                        /**<最小数据栈 */
};

int main(int argc, char *argv[])
{
    Solution myStack;

    myStack.push(1);
    myStack.push(2);
    myStack.push(3);
    myStack.push(4);

    cout << myStack.min() << '\n';
    
    myStack.pop();
    cout << myStack.min() << '\n';

    myStack.push(0);
    cout << myStack.min() << '\n';
    return 0;
}