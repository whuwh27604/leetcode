/* Range 模块.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
Range模块是跟踪数字范围的模块。设计一个数据结构来跟踪表示为 半开区间 的范围并查询它们。

半开区间 [left, right) 表示所有 left <= x < right 的实数 x 。

实现 RangeModule 类:

RangeModule() 初始化数据结构的对象。
void addRange(int left, int right) 添加 半开区间 [left, right)，跟踪该区间中的每个实数。添加与当前跟踪的数字部分重叠的区间时，应当添加在区间 [left, right) 中尚未跟踪的任何数字到该区间中。
boolean queryRange(int left, int right) 只有在当前正在跟踪区间 [left, right) 中的每一个实数时，才返回 true ，否则返回 false 。
void removeRange(int left, int right) 停止跟踪 半开区间 [left, right) 中当前正在跟踪的每个实数。
 

示例 1：

输入
["RangeModule", "addRange", "removeRange", "queryRange", "queryRange", "queryRange"]
[[], [10, 20], [14, 16], [10, 14], [13, 15], [16, 17]]
输出
[null, null, null, true, false, true]

解释
RangeModule rangeModule = new RangeModule();
rangeModule.addRange(10, 20);
rangeModule.removeRange(14, 16);
rangeModule.queryRange(10, 14); 返回 true （区间 [10, 14) 中的每个数都正在被跟踪）
rangeModule.queryRange(13, 15); 返回 false（未跟踪区间 [13, 15) 中像 14, 14.03, 14.17 这样的数字）
rangeModule.queryRange(16, 17); 返回 true （尽管执行了删除操作，区间 [16, 17) 中的数字 16 仍然会被跟踪）
 

提示：

1 <= left < right <= 109
在单个测试用例中，对 addRange 、  queryRange 和 removeRange 的调用总数不超过 104 次

来源：力扣（LeetCode）
链接：https://leetcode.cn/problems/range-module
著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。
*/

#include <iostream>
#include <map>
#include <algorithm>
#include "../check/CheckResult.h"

using namespace std;

class RangeModule {
public:
    RangeModule() {

    }

    void addRange(int left, int right) {
        auto iter = intervals.upper_bound(left);  // 找到第一个大于left的区间

        if (iter == intervals.begin()) {  // 如果是第一个，那么直接在它前面插入[left, right)
            intervals[left] = right;
            iter = intervals.begin();
        }
        else {
            --iter;  // 第一个小于left的区间

            if (iter->second >= left) {  // 有交集，合并它们
                iter->second = max(iter->second, right);
            }
            else {  // 没有交集，直接插入[left, right)
                intervals[left] = right;
                ++iter;  // iter指向插入的区间
            }
        }

        auto next = iter;
        ++next;

        while (next != intervals.end() && next->first <= iter->second) {  // 插入[left, right)之后，和后面的区间有交集，调整right位置，并删除后面的区间
            iter->second = max(iter->second, next->second);
            next = intervals.erase(next);
        }
    }

    bool queryRange(int left, int right) {
        auto iter = intervals.upper_bound(left);  // 找到第一个大于left的区间

        if (iter == intervals.begin()) {  // 第一个区间就大于left，无法覆盖
            return false;
        }

        --iter;

        return iter->second >= right;
    }

    void removeRange(int left, int right) {
        auto iter = intervals.upper_bound(left);  // 找到第一个大于left的区间
        if (iter != intervals.begin()) {
            --iter;
        }

        while (iter != intervals.end() && iter->first < right) {  // 将[left, right)范围内的区间删除
            if (iter->first < left) {
                if (iter->second < left) {  // 小于left的区间，直接跳过
                    ++iter;
                }
                else if (iter->second <= right) {  // 保留[iter->first, left)
                    iter->second = left;
                    ++iter;
                }
                else {  //  保留[iter->first, left) 和 [right, iter->second)
                    intervals[right] = iter->second;
                    iter->second = left;
                    break;
                }
            }
            else {
                if (iter->second <= right) {  // [left, right)内部的区间，直接删除
                    iter = intervals.erase(iter);
                }
                else {  // 保留[right, iter->second)
                    intervals[right] = iter->second;
                    intervals.erase(iter);
                    break;
                }
            }
        }
    }

private:
    map<int, int> intervals;
};

int main()
{
    CheckResult check;

    RangeModule o1;
    o1.addRange(10, 20);
    o1.removeRange(14, 16);
    check.checkBool(true, o1.queryRange(10, 14));
    check.checkBool(false, o1.queryRange(13, 15));
    check.checkBool(true, o1.queryRange(16, 17));
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
