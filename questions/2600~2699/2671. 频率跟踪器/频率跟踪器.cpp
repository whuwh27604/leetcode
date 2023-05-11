/* 频率跟踪器.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
请你设计并实现一个能够对其中的值进行跟踪的数据结构，并支持对频率相关查询进行应答。

实现 FrequencyTracker 类：

FrequencyTracker()：使用一个空数组初始化 FrequencyTracker 对象。
void add(int number)：添加一个 number 到数据结构中。
void deleteOne(int number)：从数据结构中删除一个 number 。数据结构 可能不包含 number ，在这种情况下不删除任何内容。
bool hasFrequency(int frequency): 如果数据结构中存在出现 frequency 次的数字，则返回 true，否则返回 false。


示例 1：

输入
["FrequencyTracker", "add", "add", "hasFrequency"]
[[], [3], [3], [2]]
输出
[null, null, null, true]

解释
FrequencyTracker frequencyTracker = new FrequencyTracker();
frequencyTracker.add(3); // 数据结构现在包含 [3]
frequencyTracker.add(3); // 数据结构现在包含 [3, 3]
frequencyTracker.hasFrequency(2); // 返回 true ，因为 3 出现 2 次
示例 2：

输入
["FrequencyTracker", "add", "deleteOne", "hasFrequency"]
[[], [1], [1], [1]]
输出
[null, null, null, false]

解释
FrequencyTracker frequencyTracker = new FrequencyTracker();
frequencyTracker.add(1); // 数据结构现在包含 [1]
frequencyTracker.deleteOne(1); // 数据结构现在为空 []
frequencyTracker.hasFrequency(1); // 返回 false ，因为数据结构为空
示例 3：

输入
["FrequencyTracker", "hasFrequency", "add", "hasFrequency"]
[[], [2], [3], [1]]
输出
[null, false, null, true]

解释
FrequencyTracker frequencyTracker = new FrequencyTracker();
frequencyTracker.hasFrequency(2); // 返回 false ，因为数据结构为空
frequencyTracker.add(3); // 数据结构现在包含 [3]
frequencyTracker.hasFrequency(1); // 返回 true ，因为 3 出现 1 次


提示：

1 <= number <= 105
1 <= frequency <= 105
最多调用 add、deleteOne 和 hasFrequency 共计 2 * 105 次
*/

#include <iostream>
#include <unordered_map>
#include "../check/CheckResult.h"

using namespace std;

class FrequencyTracker {
public:
    FrequencyTracker() {

    }

    void add(int number) {
        if (numsCount.count(number) != 0) {
            int freq = numsCount[number];
            if (--freqsCount[freq] == 0) {
                freqsCount.erase(freq);
            }
        }

        ++numsCount[number];
        ++freqsCount[numsCount[number]];
    }

    void deleteOne(int number) {
        if (numsCount.count(number) != 0) {
            int& freq = numsCount[number];
            if (--freqsCount[freq] == 0) {
                freqsCount.erase(freq);
            }

            if (--freq == 0) {
                numsCount.erase(number);
            }
            else {
                ++freqsCount[freq];
            }
        }
    }

    bool hasFrequency(int frequency) {
        return freqsCount.count(frequency) != 0;
    }

private:
    unordered_map<int, int> numsCount;
    unordered_map<int, int> freqsCount;
};

int main()
{
    CheckResult check;

    FrequencyTracker o1;
    o1.add(3);
    o1.add(3);
    check.checkBool(true, o1.hasFrequency(2));

    FrequencyTracker o2;
    o2.add(1);
    o2.deleteOne(1);
    check.checkBool(false, o2.hasFrequency(1));

    FrequencyTracker o3;
    check.checkBool(false, o3.hasFrequency(2));
    o3.add(3);
    check.checkBool(true, o3.hasFrequency(1));

    FrequencyTracker o4;
    o4.deleteOne(9);
    o4.deleteOne(8);
    o4.deleteOne(1);
    o4.deleteOne(4);
    check.checkBool(false, o4.hasFrequency(1));
    o4.add(10);  // 10
    o4.deleteOne(5);
    check.checkBool(true, o4.hasFrequency(1));
    o4.deleteOne(10);  // 
    o4.deleteOne(9);
    o4.deleteOne(10);
    check.checkBool(false, o4.hasFrequency(1));
    o4.add(4);  // 4
    check.checkBool(true, o4.hasFrequency(1));
    o4.deleteOne(4);  //
    check.checkBool(false, o4.hasFrequency(1));
    check.checkBool(false, o4.hasFrequency(1));
    o4.add(10);  // 10
    check.checkBool(true, o4.hasFrequency(1));
    o4.add(2);  // 10 2
    o4.deleteOne(1);
    check.checkBool(false, o4.hasFrequency(2));
    o4.add(7);  // 10 2 7
    check.checkBool(true, o4.hasFrequency(1));
    check.checkBool(true, o4.hasFrequency(1));
    o4.add(6);
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
