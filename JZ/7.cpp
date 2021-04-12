#include <bits/stdc++.h>
using namespace std;


/** \brief      Fibonacci  斐波那契数列
 *  \author     wzk
 *  \copyright  GNU Public License
 *  \version    1.0 
 *  \date       2020-4-6
 */
int Fibonacci(int n) {
    if (n <= 1)
        return n;
    
    int dp_1 = 0;   
    int dp_2 = 1;
    for (int i = 2; i <= n; ++i) {
        int temp = dp_2;                    /**<先缓存dp_2 */
        dp_2 = dp_1 + dp_2;                 /**<f(n) = f(n-1)+f(n-2) */
        dp_1 = temp;
    }
    
    return dp_2;
}

int main(int argc, char *argv[])
{
    int output = Fibonacci(4);
    cout << output << '\n';
    
    return 0;
}