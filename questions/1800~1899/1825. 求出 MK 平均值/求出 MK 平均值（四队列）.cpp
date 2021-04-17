/* 求出 MK 平均值.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
给你两个整数 m 和 k ，以及数据流形式的若干整数。你需要实现一个数据结构，计算这个数据流的 MK 平均值 。

MK 平均值 按照如下步骤计算：

如果数据流中的整数少于 m 个，MK 平均值 为 -1 ，否则将数据流中最后 m 个元素拷贝到一个独立的容器中。
从这个容器中删除最小的 k 个数和最大的 k 个数。
计算剩余元素的平均值，并 向下取整到最近的整数 。
请你实现 MKAverage 类：

MKAverage(int m, int k) 用一个空的数据流和两个整数 m 和 k 初始化 MKAverage 对象。
void addElement(int num) 往数据流中插入一个新的元素 num 。
int calculateMKAverage() 对当前的数据流计算并返回 MK 平均数 ，结果需 向下取整到最近的整数 。
 

示例 1：

输入：
["MKAverage", "addElement", "addElement", "calculateMKAverage", "addElement", "calculateMKAverage", "addElement", "addElement", "addElement", "calculateMKAverage"]
[[3, 1], [3], [1], [], [10], [], [5], [5], [5], []]
输出：
[null, null, null, -1, null, 3, null, null, null, 5]

解释：
MKAverage obj = new MKAverage(3, 1);
obj.addElement(3);        // 当前元素为 [3]
obj.addElement(1);        // 当前元素为 [3,1]
obj.calculateMKAverage(); // 返回 -1 ，因为 m = 3 ，但数据流中只有 2 个元素
obj.addElement(10);       // 当前元素为 [3,1,10]
obj.calculateMKAverage(); // 最后 3 个元素为 [3,1,10]
                          // 删除最小以及最大的 1 个元素后，容器为 [3]
                          // [3] 的平均值等于 3/1 = 3 ，故返回 3
obj.addElement(5);        // 当前元素为 [3,1,10,5]
obj.addElement(5);        // 当前元素为 [3,1,10,5,5]
obj.addElement(5);        // 当前元素为 [3,1,10,5,5,5]
obj.calculateMKAverage(); // 最后 3 个元素为 [5,5,5]
                          // 删除最小以及最大的 1 个元素后，容器为 [5]
                          // [5] 的平均值等于 5/1 = 5 ，故返回 5
 

提示：

3 <= m <= 105
1 <= k*2 < m
1 <= num <= 105
addElement 与 calculateMKAverage 总操作次数不超过 105 次。

来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/finding-mk-average
著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。
*/

#include <iostream>
#include <map>
#include <set>
#include <list>
#include "../check/CheckResult.h"

using namespace std;

class MKAverage {
public:
    MKAverage(int m, int k) {
        smallestSum = 0;
        greatestSum = 0;
        mSum = 0;
        index = 1;
        M = m;
        K = k;
        N = m - 2 * k;
    }

    void addElement(int num) {
        nums.push_back(num);

        if (index > M) {
            deleteMBefore(nums.front());
            nums.pop_front();
        }

        addNum(num);
        ++index;
    }

    void addNum(int num) {
        mSum += num;

        if (index > K) {
            auto iter = --smallest.end();
            if (num < iter->first) {
                smallestSum += ((long long)num - iter->first);
                ++smallest[num];
                ++smallestCand[iter->first];
                if (--iter->second == 0) {
                    smallest.erase(iter);
                }
            }
            else {
                ++smallestCand[num];
            }

            iter = greatest.begin();
            if (num > iter->first) {
                greatestSum += ((long long)num - iter->first);
                ++greatest[num];
                ++greatestCand[iter->first];
                if (--iter->second == 0) {
                    greatest.erase(iter);
                }
            }
            else {
                ++greatestCand[num];
            }
        }
        else {
            smallestSum += num;
            ++smallest[num];
            greatestSum += num;
            ++greatest[num];
        }
    }

    void deleteMBefore(int num) {
        mSum -= num;

        auto iter = --smallest.end();
        if (num <= iter->first) {
            smallestSum -= num;
            if (--smallest[num] == 0) {
                smallest.erase(iter);
            }

            iter = smallestCand.begin();
            smallestSum += iter->first;
            ++smallest[iter->first];
            if (--iter->second == 0) {
                smallestCand.erase(iter);
            }
        }
        else {
            if (--smallestCand[num] == 0) {
                smallestCand.erase(num);
            }
        }

        iter = greatest.begin();
        if (num >= iter->first) {
            greatestSum -= num;
            if (--greatest[num] == 0) {
                greatest.erase(num);
            }

            iter = --greatestCand.end();
            greatestSum += iter->first;
            ++greatest[iter->first];
            if (--iter->second == 0) {
                greatestCand.erase(iter);
            }
        }
        else {
            if (--greatestCand[num] == 0) {
                greatestCand.erase(num);
            }
        }
    }

    int calculateMKAverage() {
        return index <= M ? -1 : (int)((mSum - smallestSum - greatestSum) / N);
    }

private:
    list<int> nums;
    map<int, int> smallest;
    map<int, int> smallestCand;
    map<int, int> greatest;
    map<int, int> greatestCand;
    long long smallestSum;
    long long greatestSum;
    long long mSum;
    int index;
    int M;
    int K;
    int N;
};

int main()
{
    CheckResult check;

    MKAverage o1(3, 1);
    o1.addElement(3);
    check.checkInt(-1, o1.calculateMKAverage());
    o1.addElement(1);
    check.checkInt(-1, o1.calculateMKAverage());
    o1.addElement(10);
    check.checkInt(3, o1.calculateMKAverage());
    o1.addElement(5);
    check.checkInt(5, o1.calculateMKAverage());
    o1.addElement(5);
    check.checkInt(5, o1.calculateMKAverage());
    o1.addElement(5);
    check.checkInt(5, o1.calculateMKAverage());

    MKAverage o2(3, 1);
    o2.addElement(17612);
    check.checkInt(-1, o2.calculateMKAverage());
    o2.addElement(74607);
    check.checkInt(-1, o2.calculateMKAverage());
    o2.addElement(8272);
    check.checkInt(17612, o2.calculateMKAverage());
    o2.addElement(33433);
    check.checkInt(33433, o2.calculateMKAverage());
    o2.addElement(15456);
    check.checkInt(15456, o2.calculateMKAverage());
    o2.addElement(64938);
    check.checkInt(33433, o2.calculateMKAverage());
    o2.addElement(99741);
    check.checkInt(64938, o2.calculateMKAverage());

    MKAverage o3(5, 2);
    o3.addElement(1);
    check.checkInt(-1, o3.calculateMKAverage());
    o3.addElement(1);
    check.checkInt(-1, o3.calculateMKAverage());
    o3.addElement(1);
    check.checkInt(-1, o3.calculateMKAverage());
    o3.addElement(2);
    check.checkInt(-1, o3.calculateMKAverage());
    o3.addElement(2);
    check.checkInt(1, o3.calculateMKAverage());
    o3.addElement(2);
    check.checkInt(2, o3.calculateMKAverage());
    o3.addElement(3);
    check.checkInt(2, o3.calculateMKAverage());
    o3.addElement(3);
    check.checkInt(2, o3.calculateMKAverage());
    o3.addElement(3);
    check.checkInt(3, o3.calculateMKAverage());

    MKAverage o4(7, 3);
    o4.addElement(9);
    check.checkInt(-1, o4.calculateMKAverage());
    o4.addElement(7);
    check.checkInt(-1, o4.calculateMKAverage());
    o4.addElement(8);
    check.checkInt(-1, o4.calculateMKAverage());
    o4.addElement(6);
    check.checkInt(-1, o4.calculateMKAverage());
    o4.addElement(8);
    check.checkInt(-1, o4.calculateMKAverage());
    o4.addElement(7);
    check.checkInt(-1, o4.calculateMKAverage());
    o4.addElement(9);
    check.checkInt(8, o4.calculateMKAverage());
    o4.addElement(6);
    check.checkInt(7, o4.calculateMKAverage());
    o4.addElement(9);
    check.checkInt(8, o4.calculateMKAverage());
    o4.addElement(8);
    check.checkInt(8, o4.calculateMKAverage());
    o4.addElement(9);
    check.checkInt(8, o4.calculateMKAverage());
    o4.addElement(7);
    check.checkInt(8, o4.calculateMKAverage());
    o4.addElement(8);
    check.checkInt(8, o4.calculateMKAverage());
    o4.addElement(6);
    check.checkInt(8, o4.calculateMKAverage());
    o4.addElement(8);
    check.checkInt(8, o4.calculateMKAverage());
    o4.addElement(7);
    check.checkInt(8, o4.calculateMKAverage());
    o4.addElement(9);
    check.checkInt(8, o4.calculateMKAverage());
    o4.addElement(6);
    check.checkInt(7, o4.calculateMKAverage());
    o4.addElement(9);
    check.checkInt(8, o4.calculateMKAverage());
    o4.addElement(8);
    check.checkInt(8, o4.calculateMKAverage());
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
