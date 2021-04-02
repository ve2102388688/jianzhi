#include <bits/stdc++.h>
using namespace std;


/** \brief      evalRPN  多少个点位于同一直线
 *  \author     wzk
 *  \copyright  GNU Public License
 *  \version    1.0 
 *  \date       2020-3-30
 * 
 *  \param[in] points 点
 *  \return           最大的共线点数
 */
ListNode* sortList(ListNode* head) {
    // write code here
}

int main(int argc, char *argv[])
{
    std::vector<string> nums = {"3","3", "-4", "+"};
    int output = evalRPN(nums);

    std::cout << output << '\n';

    return 0;
}