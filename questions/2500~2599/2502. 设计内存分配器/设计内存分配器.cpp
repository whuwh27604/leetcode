/* 设计内存分配器.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
给你一个整数 n ，表示下标从 0 开始的内存数组的大小。所有内存单元开始都是空闲的。

请你设计一个具备以下功能的内存分配器：

分配 一块大小为 size 的连续空闲内存单元并赋 id mID 。
释放 给定 id mID 对应的所有内存单元。
注意：

多个块可以被分配到同一个 mID 。
你必须释放 mID 对应的所有内存单元，即便这些内存单元被分配在不同的块中。
实现 Allocator 类：

Allocator(int n) 使用一个大小为 n 的内存数组初始化 Allocator 对象。
int allocate(int size, int mID) 找出大小为 size 个连续空闲内存单元且位于  最左侧 的块，分配并赋 id mID 。返回块的第一个下标。如果不存在这样的块，返回 -1 。
int free(int mID) 释放 id mID 对应的所有内存单元。返回释放的内存单元数目。


示例：

输入
["Allocator", "allocate", "allocate", "allocate", "free", "allocate", "allocate", "allocate", "free", "allocate", "free"]
[[10], [1, 1], [1, 2], [1, 3], [2], [3, 4], [1, 1], [1, 1], [1], [10, 2], [7]]
输出
[null, 0, 1, 2, 1, 3, 1, 6, 3, -1, 0]

解释
Allocator loc = new Allocator(10); // 初始化一个大小为 10 的内存数组，所有内存单元都是空闲的。
loc.allocate(1, 1); // 最左侧的块的第一个下标是 0 。内存数组变为 [1, , , , , , , , , ]。返回 0 。
loc.allocate(1, 2); // 最左侧的块的第一个下标是 1 。内存数组变为 [1,2, , , , , , , , ]。返回 1 。
loc.allocate(1, 3); // 最左侧的块的第一个下标是 2 。内存数组变为 [1,2,3, , , , , , , ]。返回 2 。
loc.free(2); // 释放 mID 为 2 的所有内存单元。内存数组变为 [1, ,3, , , , , , , ] 。返回 1 ，因为只有 1 个 mID 为 2 的内存单元。
loc.allocate(3, 4); // 最左侧的块的第一个下标是 3 。内存数组变为 [1, ,3,4,4,4, , , , ]。返回 3 。
loc.allocate(1, 1); // 最左侧的块的第一个下标是 1 。内存数组变为 [1,1,3,4,4,4, , , , ]。返回 1 。
loc.allocate(1, 1); // 最左侧的块的第一个下标是 6 。内存数组变为 [1,1,3,4,4,4,1, , , ]。返回 6 。
loc.free(1); // 释放 mID 为 1 的所有内存单元。内存数组变为 [ , ,3,4,4,4, , , , ] 。返回 3 ，因为有 3 个 mID 为 1 的内存单元。
loc.allocate(10, 2); // 无法找出长度为 10 个连续空闲内存单元的空闲块，所有返回 -1 。
loc.free(7); // 释放 mID 为 7 的所有内存单元。内存数组保持原状，因为不存在 mID 为 7 的内存单元。返回 0 。


提示：

1 <= n, size, mID <= 1000
最多调用 allocate 和 free 方法 1000 次
*/

#include <iostream>
#include "../check/CheckResult.h"

using namespace std;

class Allocator {
public:
    Allocator(int n) {
        maxSize = n;
        mems.resize(n, 0);
    }

    int allocate(int size, int mID) {
        int i = 0;

        while (i < maxSize) {
            if (mems[i] == 0) {
                int j = i;
                while (j < maxSize && mems[j] == 0) {
                    ++j;
                    if (j - i == size) {
                        mems[i] = ((size << 16) | mID);
                        return i;
                    }
                }

                i = j;
            }
            else {
                i += (mems[i] >> 16);
            }
        }

        return -1;
    }

    int free(int mID) {
        int i = 0, units = 0;

        while (i < maxSize) {
            if (mems[i] == 0) {
                ++i;
            }
            else {
                int size = (mems[i] >> 16);
                if ((mems[i] & 0xffff) == mID) {
                    units += size;
                    mems[i] = 0;
                }
                i += size;
            }
        }

        return units;
    }

private:
    vector<int> mems;
    int maxSize;
};

int main()
{
    CheckResult check;

    Allocator o1(10);
    check.checkInt(0, o1.allocate(1, 1));
    check.checkInt(1, o1.allocate(1, 2));
    check.checkInt(2, o1.allocate(1, 3));
    check.checkInt(1, o1.free(2));
    check.checkInt(3, o1.allocate(3, 4));
    check.checkInt(1, o1.allocate(1, 1));
    check.checkInt(6, o1.allocate(1, 1));
    check.checkInt(3, o1.free(1));
    check.checkInt(-1, o1.allocate(10, 2));
    check.checkInt(0, o1.free(7));

    Allocator o2(7);
    check.checkInt(0, o2.allocate(3, 1));
    check.checkInt(-1, o2.allocate(5, 2));
    check.checkInt(3, o2.free(1));
    check.checkInt(0, o2.free(3));
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
