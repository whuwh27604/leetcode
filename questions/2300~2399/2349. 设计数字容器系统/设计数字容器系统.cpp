/* 设计数字容器系统.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
设计一个数字容器系统，可以实现以下功能：

在系统中给定下标处 插入 或者 替换 一个数字。
返回 系统中给定数字的最小下标。
请你实现一个 NumberContainers 类：

NumberContainers() 初始化数字容器系统。
void change(int index, int number) 在下标 index 处填入 number 。如果该下标 index 处已经有数字了，那么用 number 替换该数字。
int find(int number) 返回给定数字 number 在系统中的最小下标。如果系统中没有 number ，那么返回 -1 。
 

示例：

输入：
["NumberContainers", "find", "change", "change", "change", "change", "find", "change", "find"]
[[], [10], [2, 10], [1, 10], [3, 10], [5, 10], [10], [1, 20], [10]]
输出：
[null, -1, null, null, null, null, 1, null, 2]

解释：
NumberContainers nc = new NumberContainers();
nc.find(10); // 没有数字 10 ，所以返回 -1 。
nc.change(2, 10); // 容器中下标为 2 处填入数字 10 。
nc.change(1, 10); // 容器中下标为 1 处填入数字 10 。
nc.change(3, 10); // 容器中下标为 3 处填入数字 10 。
nc.change(5, 10); // 容器中下标为 5 处填入数字 10 。
nc.find(10); // 数字 10 所在的下标为 1 ，2 ，3 和 5 。因为最小下标为 1 ，所以返回 1 。
nc.change(1, 20); // 容器中下标为 1 处填入数字 20 。注意，下标 1 处之前为 10 ，现在被替换为 20 。
nc.find(10); // 数字 10 所在下标为 2 ，3 和 5 。最小下标为 2 ，所以返回 2 。
 

提示：

1 <= index, number <= 109
调用 change 和 find 的 总次数 不超过 105 次。

来源：力扣（LeetCode）
链接：https://leetcode.cn/problems/design-a-number-container-system
著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。
*/

#include <iostream>
#include <unordered_map>
#include <set>
#include "../check/CheckResult.h"

using namespace std;

class NumberContainers {
public:
    NumberContainers() {

    }

    void change(int index, int number) {
        if (indexNums.count(index) != 0) {
            int old = indexNums[index];
            numIndices[old].erase(index);

            if (numIndices[old].empty()) {
                numIndices.erase(old);
            }
        }

        indexNums[index] = number;
        numIndices[number].insert(index);
    }

    int find(int number) {
        if (numIndices.count(number) == 0) {
            return -1;
        }

        return *numIndices[number].begin();
    }

private:
    unordered_map<int, int> indexNums;
    unordered_map<int, set<int>> numIndices;
};

int main()
{
    CheckResult check;

    NumberContainers o1;
    check.checkInt(-1, o1.find(10));
    o1.change(2, 10);
    o1.change(1, 10);
    o1.change(3, 10);
    o1.change(5, 10);
    check.checkInt(1, o1.find(10));
    o1.change(1, 20);
    check.checkInt(2, o1.find(10));

    NumberContainers o2;
    o2.change(1, 10);
    check.checkInt(1, o2.find(10));
    o2.change(1, 20);
    check.checkInt(-1, o2.find(10));
    check.checkInt(1, o2.find(20));
    check.checkInt(-1, o2.find(30));
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
