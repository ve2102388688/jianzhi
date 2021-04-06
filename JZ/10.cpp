#include <bits/stdc++.h>
using namespace std;


/** \brief      NumberOf1  二进制中1的个数
 *  \author     wzk
 *  \copyright  GNU Public License
 *  \version    1.0 
 *  \date       2020-4-6
 */
int NumberOf1(int n) {
    int res = 0;    
    while (n) {
        ++res;
        n = n & (n-1);      /**<Brian Kernighan算法 */
    }
    return res;
}

int main(int argc, char *argv[])
{
    int output = NumberOf1(4);
    cout << output << '\n';
    
    return 0;
}