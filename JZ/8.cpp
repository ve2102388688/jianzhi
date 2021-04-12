#include <bits/stdc++.h>
using namespace std;


/** \brief      jumpFloor 跳台阶
 *  \author     wzk
 *  \copyright  GNU Public License
 *  \version    1.0 
 *  \date       2020-4-6
 */
int jumpFloor(int number) {
    if (number <= 2)
        return number;
    
    int dp_1 = 1;
    int dp_2 = 2;
    for (int i = 3; i <= number; ++i) {
        int temp = dp_2;
        dp_2 += dp_1;
        dp_1 = temp;
    }
    return dp_2;
}

int main(int argc, char *argv[])
{
    int output = jumpFloor(4);
    cout << output << '\n';
    
    return 0;
}