/* 强整数.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
给定两个正整数 x 和 y，如果某一整数等于 x^i + y^j，其中整数 i >= 0 且 j >= 0，那么我们认为该整数是一个强整数。

返回值小于或等于 bound 的所有强整数组成的列表。

你可以按任何顺序返回答案。在你的回答中，每个值最多出现一次。

 

示例 1：

输入：x = 2, y = 3, bound = 10
输出：[2,3,4,5,7,9,10]
解释：
2 = 2^0 + 3^0
3 = 2^1 + 3^0
4 = 2^0 + 3^1
5 = 2^1 + 3^1
7 = 2^2 + 3^1
9 = 2^3 + 3^0
10 = 2^0 + 3^2
示例 2：

输入：x = 3, y = 5, bound = 15
输出：[2,4,6,8,10,14]
 

提示：

1 <= x <= 100
1 <= y <= 100
0 <= bound <= 10^6

来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/powerful-integers
著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。
*/

#include <iostream>
#include <unordered_set>
#include "../check/CheckResult.h"

using namespace std;

class Solution {
public:
    vector<int> powerfulIntegers(int x, int y, int bound) {
        unordered_set<int> allSums;

        // 2^19 < 10^6 < 2^20
        for (int i = 0; i < 20; i++) {
            int powerX = (int)pow(x, i);
            if (powerX > bound) {
                break;
            }

            for (int j = 0; j < 20; j++) {
                int sum = (int)pow(y, j) + powerX;
                if (sum > bound) {
                    break;
                }

                allSums.insert(sum);
            }
        }

        vector<int> ans;
        for (auto iter = allSums.begin(); iter != allSums.end(); iter++) {
            ans.push_back(*iter);
        }

        return ans;
    }
};

int main()
{
    Solution o;
    CheckResult check;

    vector<int> actual = o.powerfulIntegers(2, 3, 10);
    vector<int> expected = { 10,2,4,3,5,7,9 };
    check.checkIntVector(expected, actual);

    actual = o.powerfulIntegers(3, 5, 15);
    expected = { 10,2,14,6,4,8 };
    check.checkIntVector(expected, actual);

    actual = o.powerfulIntegers(3, 5, 0);
    expected = {  };
    check.checkIntVector(expected, actual);

    actual = o.powerfulIntegers(3, 5, 1);
    expected = {  };
    check.checkIntVector(expected, actual);

    actual = o.powerfulIntegers(10, 10, 1000000);
    expected = { 2,100001,11,100010,101,1001,20,10001,20000,110,1010,10010,200000,200,100100,1100,10100,2000,11000,101000,110000 };
    check.checkIntVector(expected, actual);
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
