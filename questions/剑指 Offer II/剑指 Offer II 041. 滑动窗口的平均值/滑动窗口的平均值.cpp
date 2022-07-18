/* 滑动窗口的平均值.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
给定一个整数数据流和一个窗口大小，根据该滑动窗口的大小，计算滑动窗口里所有数字的平均值。

实现 MovingAverage 类：

MovingAverage(int size) 用窗口大小 size 初始化对象。
double next(int val) 成员函数 next 每次调用的时候都会往滑动窗口增加一个整数，请计算并返回数据流中最后 size 个值的移动平均值，即滑动窗口里所有数字的平均值。
 

示例：

输入：
inputs = ["MovingAverage", "next", "next", "next", "next"]
inputs = [[3], [1], [10], [3], [5]]
输出：
[null, 1.0, 5.5, 4.66667, 6.0]

解释：
MovingAverage movingAverage = new MovingAverage(3);
movingAverage.next(1); // 返回 1.0 = 1 / 1
movingAverage.next(10); // 返回 5.5 = (1 + 10) / 2
movingAverage.next(3); // 返回 4.66667 = (1 + 10 + 3) / 3
movingAverage.next(5); // 返回 6.0 = (10 + 3 + 5) / 3
 

提示：

1 <= size <= 1000
-105 <= val <= 105
最多调用 next 方法 104 次
 

注意：本题与主站 346 题相同： https://leetcode-cn.com/problems/moving-average-from-data-stream/

来源：力扣（LeetCode）
链接：https://leetcode.cn/problems/qIsx9U
著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。
*/

#include <iostream>
#include <queue>
#include "../check/CheckResult.h"

using namespace std;

class MovingAverage {
public:
    /** Initialize your data structure here. */
    MovingAverage(int size) {
        window = size;
        sum = 0;
    }

    double next(int val) {
        nums.push(val);
        sum += val;

        if ((int)nums.size() > window) {
            sum -= nums.front();
            nums.pop();
        }

        return (double)sum / nums.size();
    }

private:
    int window;
    int sum;
    queue<int> nums;
};

int main()
{
    CheckResult check;

    MovingAverage o1(3);
    check.checkDouble(1, o1.next(1));
    check.checkDouble(5.5, o1.next(10));
    check.checkDouble(4.666667, o1.next(3));
    check.checkDouble(6.0, o1.next(5));
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
