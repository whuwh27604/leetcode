/* 快照数组.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
实现支持下列接口的「快照数组」- SnapshotArray：

SnapshotArray(int length) - 初始化一个与指定长度相等的 类数组 的数据结构。初始时，每个元素都等于 0。
void set(index, val) - 会将指定索引 index 处的元素设置为 val。
int snap() - 获取该数组的快照，并返回快照的编号 snap_id（快照号是调用 snap() 的总次数减去 1）。
int get(index, snap_id) - 根据指定的 snap_id 选择快照，并返回该快照指定索引 index 的值。
 

示例：

输入：["SnapshotArray","set","snap","set","get"]
     [[3],[0,5],[],[0,6],[0,0]]
输出：[null,null,0,null,5]
解释：
SnapshotArray snapshotArr = new SnapshotArray(3); // 初始化一个长度为 3 的快照数组
snapshotArr.set(0,5);  // 令 array[0] = 5
snapshotArr.snap();  // 获取快照，返回 snap_id = 0
snapshotArr.set(0,6);
snapshotArr.get(0,0);  // 获取 snap_id = 0 的快照中 array[0] 的值，返回 5
 

提示：

1 <= length <= 50000
题目最多进行50000 次set，snap，和 get的调用 。
0 <= index < length
0 <= snap_id < 我们调用 snap() 的总次数
0 <= val <= 10^9

来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/snapshot-array
著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。
*/

#include <iostream>
#include <map>
#include "../check/CheckResult.h"

using namespace std;

class SnapshotArray {
public:
    SnapshotArray(int length) {
        data.resize(length, map<int, int>({ {0,0} }));
        snapId = 0;
    }

    void set(int index, int val) {
        data[index][snapId] = val;
    }

    int snap() {
        return snapId++;
    }

    int get(int index, int snap_id) {
        auto iter = data[index].upper_bound(snap_id);
        return (--iter)->second;
    }

private:
    vector<map<int, int>> data;
    int snapId;
};

int main()
{
    CheckResult check;

    SnapshotArray o1(3);
    o1.set(0, 5);
    check.checkInt(0, o1.snap());
    o1.set(0, 6);
    check.checkInt(5, o1.get(0, 0));

    SnapshotArray o2(1);
    o2.set(0, 15);
    check.checkInt(0, o2.snap());
    check.checkInt(1, o2.snap());
    check.checkInt(2, o2.snap());
    check.checkInt(15, o2.get(0, 2));
    check.checkInt(3, o2.snap());
    o2.set(0, 20);
    check.checkInt(4, o2.snap());
    check.checkInt(5, o2.snap());
    check.checkInt(15, o2.get(0, 0));
    check.checkInt(15, o2.get(0, 3));
    check.checkInt(20, o2.get(0, 4));
    check.checkInt(20, o2.get(0, 5));

    SnapshotArray o3(4);
    check.checkInt(0, o3.snap());
    check.checkInt(1, o3.snap());
    check.checkInt(0, o3.get(3, 1));
    o3.set(2, 4);
    check.checkInt(2, o3.snap());
    o3.set(1, 4);
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
