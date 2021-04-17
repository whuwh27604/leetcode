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
        lastSmallest = mNums.end();
        firstGreatest = mNums.end();
        lsIndex = 0;
        fgIndex = 0;
        smallestSum = 0;
        greatestSum = 0;
        mSum = 0;
        index = 1;
        M = m;
        K = k;
        N = m - 2 * k;
    }

    void addElement(int num) {
        if (index > M) {  // 已经有m个数了，需要先删除最前面一个，再添加
            deleteMBefore();
            addNum(num);
            addAdjust(num);
        }
        else if (index > K) {  // 多于k个数，添加的时候要调整最大最小指针的位置
            addNum(num);
            addAdjust(num);
        }
        else if (index == K) {  // 第k个数，初始化最大最小指针的位置
            addNum(num);
            smallestSum = greatestSum = mSum;
            lastSmallest = --mNums.end();
            firstGreatest = mNums.begin();
            lsIndex = lastSmallest->second;
            fgIndex = 1;
        }
        else {  // 小于k个数，直接添加就可以了
            addNum(num);
        }

        ++index;
    }

    void addNum(int num) {
        nums.push_back(num);
        mSum += num;
        ++mNums[num];
    }

    void addAdjust(int num) {
        if (num < lastSmallest->first) {  // 添加的数比最小数小，那么指针要左移一位
            smallestSum += ((long long)num - lastSmallest->first);

            if (lsIndex == 1) {  // 已经是当前数的第一个，那么指针会移动到前一个数的最后一个
                --lastSmallest;
                lsIndex = lastSmallest->second;
            }
            else {  // 相同数的非第一个，直接指向前一个就可以了
                --lsIndex;
            }
        }

        if (num >= firstGreatest->first) {  // 添加的数大于等于最大数，那么指针右移一位
            greatestSum += ((long long)num - firstGreatest->first);

            if (fgIndex == firstGreatest->second) {  // 已经是当前数的最后一个，那么指针移动到后一个数的第一个
                ++firstGreatest;
                fgIndex = 1;
            }
            else {
                ++fgIndex;  // 相同数的非最后一个，直接指向后一个就可以了
            }
        }
    }

    void deleteMBefore() {
        int mBefore = nums.front();
        mSum -= mBefore;
        nums.pop_front();
        deleteAdjust(mBefore);  // 删除的时候要先完成指针调整，最后再从mNums里面真正删除
        if (--mNums[mBefore] == 0) {
            mNums.erase(mBefore);
        }
    }

    void deleteAdjust(int num) {
        if (num <= lastSmallest->first) {  // 删除的数小于等于最小数，指针右移一位
            if (lsIndex == lastSmallest->second) {  // 相同数的最后一个，右移后指向下一个数的第一个
                ++lastSmallest;
                lsIndex = 1;
            }
            else {
                lsIndex += (num == lastSmallest->first ? 0 : 1);  // 非最后一个，指针加1。如果删除的就是最后一个数，那么不用加1。
            }

            smallestSum += ((long long)lastSmallest->first - num);
        }

        if (num >= firstGreatest->first) {  // 删除的数大于等于最大数，指针左移一位
            if (fgIndex == 1) {  // 相同数的第一个，左移一位指向前一个数的最后一个
                --firstGreatest;
                fgIndex = firstGreatest->second;
            }
            else {  // 非第一个，直接减1就可以了
                --fgIndex;
            }

            greatestSum += ((long long)firstGreatest->first - num);
        }
    }

    int calculateMKAverage() {
        return index <= M ? -1 : (int)((mSum - smallestSum - greatestSum) / N);
    }

private:
    list<int> nums;  // 保存m个数
    map<int, int> mNums;  // 最后m个数排序
    map<int, int>::iterator lastSmallest;  // k个最小数的最后一个
    map<int, int>::iterator firstGreatest;  // k个最大数的第一个
    int lsIndex;  // 第k个最小数在相同数字中的索引，从1开始
    int fgIndex;  // 第1个最大数在相同数字中的索引，从1开始
    int index;
    int M;
    int K;
    int N;
    long long smallestSum;
    long long greatestSum;
    long long mSum;
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
