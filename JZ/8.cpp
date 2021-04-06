#include <bits/stdc++.h>
using namespace std;


/** \brief      jumpFloorII  跳台阶扩展问题
 *  \author     wzk
 *  \copyright  GNU Public License
 *  \version    1.0 
 *  \date       2020-4-6
 */
int jumpFloorII(int number) {
    int res = 1;
    return res<<(number-1);
}

int main(int argc, char *argv[])
{
    int output = jumpFloorII(4);
    cout << output << '\n';
    
    return 0;
}