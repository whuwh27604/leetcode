/* 设计位集.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
位集 Bitset 是一种能以紧凑形式存储位的数据结构。

请你实现 Bitset 类。

Bitset(int size) 用 size 个位初始化 Bitset ，所有位都是 0 。
void fix(int idx) 将下标为 idx 的位上的值更新为 1 。如果值已经是 1 ，则不会发生任何改变。
void unfix(int idx) 将下标为 idx 的位上的值更新为 0 。如果值已经是 0 ，则不会发生任何改变。
void flip() 翻转 Bitset 中每一位上的值。换句话说，所有值为 0 的位将会变成 1 ，反之亦然。
boolean all() 检查 Bitset 中 每一位 的值是否都是 1 。如果满足此条件，返回 true ；否则，返回 false 。
boolean one() 检查 Bitset 中 是否 至少一位 的值是 1 。如果满足此条件，返回 true ；否则，返回 false 。
int count() 返回 Bitset 中值为 1 的位的 总数 。
String toString() 返回 Bitset 的当前组成情况。注意，在结果字符串中，第 i 个下标处的字符应该与 Bitset 中的第 i 位一致。
 

示例：

输入
["Bitset", "fix", "fix", "flip", "all", "unfix", "flip", "one", "unfix", "count", "toString"]
[[5], [3], [1], [], [], [0], [], [], [0], [], []]
输出
[null, null, null, null, false, null, null, true, null, 2, "01010"]

解释
Bitset bs = new Bitset(5); // bitset = "00000".
bs.fix(3);     // 将 idx = 3 处的值更新为 1 ，此时 bitset = "00010" 。
bs.fix(1);     // 将 idx = 1 处的值更新为 1 ，此时 bitset = "01010" 。
bs.flip();     // 翻转每一位上的值，此时 bitset = "10101" 。
bs.all();      // 返回 False ，bitset 中的值不全为 1 。
bs.unfix(0);   // 将 idx = 0 处的值更新为 0 ，此时 bitset = "00101" 。
bs.flip();     // 翻转每一位上的值，此时 bitset = "11010" 。
bs.one();      // 返回 True ，至少存在一位的值为 1 。
bs.unfix(0);   // 将 idx = 0 处的值更新为 0 ，此时 bitset = "01010" 。
bs.count();    // 返回 2 ，当前有 2 位的值为 1 。
bs.toString(); // 返回 "01010" ，即 bitset 的当前组成情况。
 

提示：

1 <= size <= 105
0 <= idx <= size - 1
至多调用 fix、unfix、flip、all、one、count 和 toString 方法 总共 105 次
至少调用 all、one、count 或 toString 方法一次
至多调用 toString 方法 5 次

来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/design-bitset
著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。
*/

#include <iostream>
#include "../check/CheckResult.h"

using namespace std;

class Bitset {
public:
    Bitset(int s) {
        size = s;
        cnt = 0;
        isFlip = false;
        nums.resize(size, 0);
    }

    void fix(int idx) {
        if (isFlip) {
            if (nums[idx] == 1) {
                nums[idx] = 0;
                ++cnt;
            }
        }
        else {
            if (nums[idx] == 0) {
                nums[idx] = 1;
                ++cnt;
            }
        }
    }

    void unfix(int idx) {
        if (isFlip) {
            if (nums[idx] == 0) {
                nums[idx] = 1;
                --cnt;
            }
        }
        else {
            if (nums[idx] == 1) {
                nums[idx] = 0;
                --cnt;
            }
        }
    }

    void flip() {
        isFlip = !isFlip;
        cnt = size - cnt;
    }

    bool all() {
        return cnt == size;
    }

    bool one() {
        return cnt > 0;
    }

    int count() {
        return cnt;
    }

    string toString() {
        string ans(size, 0);

        for (int i = 0; i < size; ++i) {
            if (isFlip) {
                ans[i] = (nums[i] == 0 ? '1' : '0');
            }
            else {
                ans[i] = (nums[i] == 0 ? '0' : '1');
            }
        }

        return ans;
    }

private:
    int size;
    int cnt;
    bool isFlip;
    vector<int> nums;
};

int main()
{
    CheckResult check;

    Bitset o1(5);
    o1.fix(3);
    o1.fix(1);
    o1.flip();
    check.checkString("10101", o1.toString());
    check.checkBool(false, o1.all());
    o1.unfix(0);
    o1.flip();
    check.checkBool(true, o1.one());
    o1.unfix(0);
    check.checkInt(2, o1.count());
    check.checkString("01010", o1.toString());
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
