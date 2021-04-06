#include <bits/stdc++.h>
using namespace std;


/** \brief      Power  数值的整数次方
 *  \author     wzk
 *  \copyright  GNU Public License
 *  \version    1.0 
 *  \date       2020-4-6
 *  \remark     递归快速幂
 */
double PowerUnsigned(double base, int exponent) {
    if (exponent == 1)
        return base;
    else if(exponent == 0)
        return 1;
    
    double res = PowerUnsigned(base, exponent>>1);  /**<不管是奇数还是偶数，都会向下取整 */
    res *= res;
    if (exponent&1)                                 /**<奇数 */
        res *= base;
    return res;
}

double Power(double base, int exponent) {
    if (exponent == 0)
        return 1;
    double res = PowerUnsigned(base, abs(exponent));
    if (exponent < 0)                               /**<负指数 */
        res = 1 / res;
    return res;
}

int main(int argc, char *argv[])
{
    double output = Power(4, 3);
    cout << output << '\n';
    
    return 0;
}