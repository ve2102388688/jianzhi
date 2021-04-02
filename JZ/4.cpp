#include <bits/stdc++.h>
using namespace std;


/** \brief      Solution  使用两个栈模拟队列
 *  \author     wzk
 *  \copyright  GNU Public License
 *  \version    1.0 
 *  \date       2020-3-31
 */
int minNumberInRotateArray(vector<int> rotateArray) {
    int low = 0, high = rotateArray.size()-1;
    
    while (low < high) {
        int mid = low + (high-low)/2;
        if (low+1 == high)
            return rotateArray[high];
        else if (rotateArray[mid] >= rotateArray[low]) {
            low = mid;
        } else if (rotateArray[mid] <= rotateArray[high]){
            high = mid;
        }
    }
    return 0;
}

int main(int argc, char *argv[])
{
    std::vector<int> nums = {3,4,5,1,2};
    int output = minNumberInRotateArray(nums);
    cout << output << '\n';
    
    return 0;
}