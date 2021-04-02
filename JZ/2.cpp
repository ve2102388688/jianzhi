#include <bits/stdc++.h>
using namespace std;


/** \brief      replaceSpace 替换空格
 *  \author     wzk
 *  \copyright  GNU Public License
 *  \version    1.0 
 *  \date       2020-3-29
 * 
 *  \param[in] s  输入字符串
 *  \return       替换后的字符串
 */
string replaceSpace(string& s) {
    string res;
    for (const auto& e : s) {
        if (e == ' ')
            res.append("%20");
        else
            res.push_back(e);
    }
    return res;
}


int main(int argc, char *argv[])
{
    string nums = "We Are Happy";
    string output = replaceSpace(nums);
    cout << output << '\n';

    return 0;
}