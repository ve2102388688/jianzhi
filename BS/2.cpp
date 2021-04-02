#include <bits/stdc++.h>
using namespace std;


/** \brief      evalRPN  后缀表达式求值
 *  \author     wzk
 *  \copyright  GNU Public License
 *  \version    1.0 
 *  \date       2020-3-30
 * 
 *  \param[in] tokens 后缀表达式
 *  \return           表达式值
 */
int evalRPN(vector<string>& tokens) {
    int n = tokens.size();
    if (n == 0)
        return 0;

    stack<int> sta;
    for (const auto &e : tokens) {
        if (e.size()==1 && (e[0]=='+' || e[0]=='-' || e[0]=='*' || e[0]=='/')) {
            if (sta.size() < 2)
                throw runtime_error("invaild expression!");
            int num2 = sta.top(); sta.pop();
            int num1 = sta.top(); sta.pop();
            if (e[0]=='+') 
                sta.push(num1 + num2);
            else if(e[0]=='-')
                sta.push(num1 - num2);
            else if(e[0]=='*')
                sta.push(num1 * num2);
            else
                sta.push(num1 / num2);
        } else
            sta.push(atoi(e.c_str()));
    }

    return sta.size()==1 ? sta.top() : throw runtime_error("error expression");
}

int main(int argc, char *argv[])
{
    std::vector<string> nums = {"3","3", "-4", "+"};
    int output = evalRPN(nums);

    std::cout << output << '\n';

    return 0;
}