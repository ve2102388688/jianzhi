#include <bits/stdc++.h>
using namespace std;


/** \brief      Solution  使用两个栈模拟队列
 *  \author     wzk
 *  \copyright  GNU Public License
 *  \version    1.0 
 *  \date       2020-4-1
 */
class Solution
{
public:
    void push(int node) {
        stack1.push(node);
    }

    int pop() {
        if (stack2.empty())                         /**<将第一个栈中数据全部入栈2 */
            while (!stack1.empty()){
                stack2.push(stack1.top());
                stack1.pop();
            }
        int ans = 0;
        if (!stack2.empty()){                       /**<栈2空，说明从空队列取数据，异常 */
            ans = stack2.top();
            stack2.pop();
        } else 
            throw runtime_error("Can't pop from empty queue");
        return ans;
    }

private:
    stack<int> stack1;              /**<始终从stack1入队列 */
    stack<int> stack2;              /**<始终从stack2出队列 */
};

int main(int argc, char *argv[])
{
    Solution myQueue;

    myQueue.push(1);
    myQueue.push(2);
    myQueue.push(3);

    cout << myQueue.pop() << '\n';
    cout << myQueue.pop() << '\n';
    cout << myQueue.pop() << '\n';
    // cout << myQueue.pop() << '\n';           // Can't pop from empty queue

    return 0;
}