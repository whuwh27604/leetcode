/* 跳水板.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
你正在使用一堆木板建造跳水板。有两种类型的木板，其中长度较短的木板长度为shorter，长度较长的木板长度为longer。你必须正好使用k块木板。编写一个方法，生成跳水板所有可能的长度。

返回的长度需要从小到大排列。

示例：

输入：
shorter = 1
longer = 2
k = 3
输出： {3,4,5,6}
提示：

0 < shorter <= longer
0 <= k <= 100000

来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/diving-board-lcci
著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。
*/

#include <iostream>
#include "../check/CheckResult.h"

using namespace std;

class Solution {
public:
    vector<int> divingBoard(int shorter, int longer, int k) {
        if (k == 0) {
            return {};
        }

        int shortest = shorter * k;
        int diff = longer - shorter;
        vector<int> lengths;
        lengths.push_back(shortest);

        if (diff != 0) {
            for (int i = 0; i < k; i++) {
                shortest += diff;
                lengths.push_back(shortest);
            }
        }

        return lengths;
    }
};

int main()
{
    Solution o;
    CheckResult check;

    vector<int> actual = o.divingBoard(1, 2, 3);
    vector<int> expected = { 3,4,5,6 };
    check.checkIntVector(expected, actual);

    actual = o.divingBoard(1, 1, 0);
    expected = {  };
    check.checkIntVector(expected, actual);

    actual = o.divingBoard(1, 1, 1);
    expected = { 1 };
    check.checkIntVector(expected, actual);

    actual = o.divingBoard(1, 1, 2);
    expected = { 2 };
    check.checkIntVector(expected, actual);

    actual = o.divingBoard(1, 1, 3);
    expected = { 3 };
    check.checkIntVector(expected, actual);

    actual = o.divingBoard(3, 5, 0);
    expected = {  };
    check.checkIntVector(expected, actual);

    actual = o.divingBoard(3, 5, 1);
    expected = { 3,5 };
    check.checkIntVector(expected, actual);

    actual = o.divingBoard(3, 5, 2);
    expected = { 6,8,10 };
    check.checkIntVector(expected, actual);

    actual = o.divingBoard(3, 5, 3);
    expected = { 9,11,13,15 };
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
