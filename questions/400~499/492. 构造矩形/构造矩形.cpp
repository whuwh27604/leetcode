/* 构造矩形.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
作为一位web开发者， 懂得怎样去规划一个页面的尺寸是很重要的。 现给定一个具体的矩形页面面积，你的任务是设计一个长度为 L 和宽度为 W 且满足以下要求的矩形的页面。要求：

1. 你设计的矩形页面必须等于给定的目标面积。

2. 宽度 W 不应大于长度 L，换言之，要求 L >= W 。

3. 长度 L 和宽度 W 之间的差距应当尽可能小。
你需要按顺序输出你设计的页面的长度 L 和宽度 W。

示例：

输入: 4
输出: [2, 2]
解释: 目标面积是 4， 所有可能的构造方案有 [1,4], [2,2], [4,1]。
但是根据要求2，[1,4] 不符合要求; 根据要求3，[2,2] 比 [4,1] 更能符合要求. 所以输出长度 L 为 2， 宽度 W 为 2。
说明:

给定的面积不大于 10,000,000 且为正整数。
你设计的页面的长度和宽度必须都是正整数。

来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/construct-the-rectangle
著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。
*/

#include <iostream>
#include "../check/CheckResult.h"

using namespace std;

class Solution {
public:
    vector<int> constructRectangle(int area) {
        int W = (int)sqrt(area);

        while ((area % W) != 0) {
            W--;
        }

        return { (area / W), W };
    }
};

int main()
{
    Solution o;
    CheckResult check;

    vector<int> actual = o.constructRectangle(4);
    vector<int> expected = { 2,2 };
    check.checkIntVector(expected, actual);

    actual = o.constructRectangle(1);
    expected = { 1,1 };
    check.checkIntVector(expected, actual);

    actual = o.constructRectangle(2);
    expected = { 2,1 };
    check.checkIntVector(expected, actual);

    actual = o.constructRectangle(3);
    expected = { 3,1 };
    check.checkIntVector(expected, actual);

    actual = o.constructRectangle(6);
    expected = { 3,2 };
    check.checkIntVector(expected, actual);

    actual = o.constructRectangle(10000000);
    expected = { 3200,3125 };
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
