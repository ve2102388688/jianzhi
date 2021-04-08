#include <bits/stdc++.h>
using namespace std;


/** \brief      reOrderArray  调整数组顺序使奇数位于偶数前面
 *  \author     wzk
 *  \copyright  GNU Public License
 *  \version    1.0 
 *  \date       2020-4-6
 */
vector<int> reOrderArray(vector<int>& array) {
    int size = array.size();
    
    for (int i = 0; i < size-1; ++i) {
        while(i>=0 && (array[i]&1)==0 && (array[i+1]&1)==1) {       /**<当前是偶数，下一个是奇数，交换 */
            int temp = array[i];
            array[i] = array[i+1];
            array[i+1] = temp;
            --i;
        }
    }
    return array;
}

int main(int argc, char *argv[])
{
    std::vector<int> nums = {3,4,5,1,2};
    vector<int> output = reOrderArray(nums);
    for (const auto&e : output)
        cout << e << ' ';

    cout << '\n';
    return 0;
}