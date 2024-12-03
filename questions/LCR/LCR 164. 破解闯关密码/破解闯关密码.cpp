/* 破解闯关密码.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
闯关游戏需要破解一组密码，闯关组给出的有关密码的线索是：

一个拥有密码所有元素的非负整数数组 password
密码是 password 中所有元素拼接后得到的最小的一个数
请编写一个程序返回这个密码。



示例 1:

输入: password = [15, 8, 7]
输出: "1578"
示例 2:

输入: password = [0, 3, 30, 34, 5, 9]
输出: "03033459"


提示:

0 < password.length <= 100
说明:

输出结果可能非常大，所以你需要返回一个字符串而不是整数
拼接起来的数字可能会有前导 0，最后结果不需要去掉前导 0
*/

#include <iostream>
#include <map>
#include "../check/CheckResult.h"

using namespace std;

struct StringCompare {
    bool operator()(const string& s1, const string& s2) const {
        string t1 = s1 + s2, t2 = s2 + s1;

        if (t1 == t2) {
            return s1.size() < s2.size();
        }
        else {
            return t1 < t2;
        }
    }
};

class Solution {
public:
    string crackPassword(vector<int>& password) {
        map<string, int, StringCompare> pass;
        string ans;

        for (int num : password) {
            ++pass[to_string(num)];
        }

        for (auto& num : pass) {
            for (int i = 0; i < num.second; ++i) {
                ans += num.first;
            }
        }

        return ans;
    }
};

int main()
{
    Solution o;
    CheckResult check;

    vector<int> password = { 15,8,7 };
    check.checkString("1578", o.crackPassword(password));

    password = { 0,3,30,34,5,9 };
    check.checkString("03033459", o.crackPassword(password));

    password = { 3,43,48,94,85,33,64,32,63,66 };
    check.checkString("3233343486364668594", o.crackPassword(password));

    password = { 0,3,30,34,5,9,15,8,7,0,3,30,34,5,9,15,8,7,0,3,30,34,5,9,15,8,7,0,3,30,34,5,9,15,8,7 };
    check.checkString("000015151515303030303333343434345555777788889999", o.crackPassword(password));
}

// 运行程序: Ctrl + F5 或调试 >“开始执行(不调试)”菜单
// 调试程序: F5 或调试 >“开始调试”菜单

// 入门使用技巧: 
//   1. 使用解决方案资源管理器窗口添加/管理文件
//   2. 使用团队资源管理器窗口连接到源代码管理
//   3. 使用输出窗口查看生成输出和其他消息
//   4. 使用错误列表窗口查看错误
//   5. 转到“项目”>“添加新项”以创建新的代码文件，或转到“项目”>“添加现有项”以将现有代码文件添加到项目
//   6. 将来，若要再次打开此项目，请转到“文件”>“打开”>“项目”并选择 .sln 文件
