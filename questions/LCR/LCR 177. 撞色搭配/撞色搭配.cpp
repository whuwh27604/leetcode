/* 撞色搭配.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
整数数组 sockets 记录了一个袜子礼盒的颜色分布情况，其中 sockets[i] 表示该袜子的颜色编号。礼盒中除了一款撞色搭配的袜子，每种颜色的袜子均有两只。请设计一个程序，在时间复杂度 O(n)，空间复杂度O(1) 内找到这双撞色搭配袜子的两个颜色编号。



示例 1：

输入：sockets = [4, 5, 2, 4, 6, 6]
输出：[2,5] 或 [5,2]
示例 2：

输入：sockets = [1, 2, 4, 1, 4, 3, 12, 3]
输出：[2,12] 或 [12,2]


提示：

2 <= sockets.length <= 10000
*/

#include <iostream>
#include "../check/CheckResult.h"

using namespace std;

class Solution {
public:
    vector<int> sockCollocation(vector<int>& sockets) {
        int sum = 0, bit = 1;
        vector<int> ans(2, 0);  // 假设不配对的是x，y

        for (int num : sockets) {
            sum ^= num;
        }  // sum = x ^ y;

        while ((sum & bit) == 0) {
            bit <<= 1;
        }  // 在bit位，x、y有一个是0，另一个是1

        for (int num : sockets) {
            if ((num & bit) == 0) {  // 所有bit位为0的放入一组，除了x其它都是一对，异或结果只剩x
                ans[0] ^= num;
            }
            else {  // bit位为1的放入另一组，除了y其它都是一对，异或结果只剩y
                ans[1] ^= num;
            }
        }

        return ans;
    }
};

int main()
{
    Solution o;
    CheckResult check;

    vector<int> sockets = { 4,5,2,4,6,6 };
    vector<int> actual = o.sockCollocation(sockets);
    vector<int> expected = { 2,5 };
    check.checkIntVectorRandomOrder(expected, actual);

    sockets = { 1,2,4,1,4,3,12,3 };
    actual = o.sockCollocation(sockets);
    expected = { 2,12 };
    check.checkIntVectorRandomOrder(expected, actual);
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
