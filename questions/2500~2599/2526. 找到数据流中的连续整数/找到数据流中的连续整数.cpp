/* 找到数据流中的连续整数.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
给你一个整数数据流，请你实现一个数据结构，检查数据流中最后 k 个整数是否 等于 给定值 value 。

请你实现 DataStream 类：

DataStream(int value, int k) 用两个整数 value 和 k 初始化一个空的整数数据流。
boolean consec(int num) 将 num 添加到整数数据流。如果后 k 个整数都等于 value ，返回 true ，否则返回 false 。如果少于 k 个整数，条件不满足，所以也返回 false 。


示例 1：

输入：
["DataStream", "consec", "consec", "consec", "consec"]
[[4, 3], [4], [4], [4], [3]]
输出：
[null, false, false, true, false]

解释：
DataStream dataStream = new DataStream(4, 3); // value = 4, k = 3
dataStream.consec(4); // 数据流中只有 1 个整数，所以返回 False 。
dataStream.consec(4); // 数据流中只有 2 个整数
                      // 由于 2 小于 k ，返回 False 。
dataStream.consec(4); // 数据流最后 3 个整数都等于 value， 所以返回 True 。
dataStream.consec(3); // 最后 k 个整数分别是 [4,4,3] 。
                      // 由于 3 不等于 value ，返回 False 。


提示：

1 <= value, num <= 109
1 <= k <= 105
至多调用 consec 次数为 105 次。
*/

#include <iostream>
#include "../check/CheckResult.h"

using namespace std;

class DataStream {
public:
    DataStream(int value, int k_) {
        val = value;
        k = k_;
        last = 0;
        count = 0;
    }

    bool consec(int num) {
        if (num == last) {
            ++count;
        }
        else {
            last = num;
            count = 1;
        }

        return last == val && count >= k;
    }

private:
    int val;
    int k;
    int last;
    int count;
};

int main()
{
    CheckResult check;

    DataStream o1(4, 3);
    check.checkBool(false, o1.consec(4));
    check.checkBool(false, o1.consec(4));
    check.checkBool(true, o1.consec(4));
    check.checkBool(false, o1.consec(3));
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
