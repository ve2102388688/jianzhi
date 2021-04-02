#include <bits/stdc++.h>
using namespace std;

struct Point {
    int x;
	int y;
};

/** \brief      evalRPN  多少个点位于同一直线
 *  \author     wzk
 *  \copyright  GNU Public License
 *  \version    1.0 
 *  \date       2020-3-30
 * 
 *  \param[in] points 点
 *  \return           最大的共线点数
 */
int maxPoints(vector<Point>& points) {
    int n = points.size();
    if (n <= 2)
        return n;
    
    int ans = 0;
    for (int i = 0; i < n-1; ++i){
        for (int j = i+1; j < n; ++j) {
            /**<相同点不能构成直线 */
            if (points[i].x == points[j].x && points[i].y == points[j].y)
                continue;
            int maxNum = 2;
            for (int k = 0; k < n; ++k) {
                if (k == i || k == j)
                    continue;
                /**<是否共线 */
                if((points[j].y-points[i].y)*(points[k].x-points[i].x) == (points[j].x-points[i].x)*(points[k].y-points[i].y))
                    ++maxNum;
            }
            ans = max(ans, maxNum);
        }
    }
    return ans;
}

int main(int argc, char *argv[])
{
    std::vector<string> nums = {"3","3", "-4", "+"};
    int output = evalRPN(nums);

    std::cout << output << '\n';

    return 0;
}