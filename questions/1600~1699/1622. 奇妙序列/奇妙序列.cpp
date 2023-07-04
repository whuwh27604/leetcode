/* 奇妙序列.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
请你实现三个 API append，addAll 和 multAll 来实现奇妙序列。

请实现 Fancy 类 ：

Fancy() 初始化一个空序列对象。
void append(val) 将整数 val 添加在序列末尾。
void addAll(inc) 将所有序列中的现有数值都增加 inc 。
void multAll(m) 将序列中的所有现有数值都乘以整数 m 。
int getIndex(idx) 得到下标为 idx 处的数值（下标从 0 开始），并将结果对 109 + 7 取余。如果下标大于等于序列的长度，请返回 -1 。


示例：

输入：
["Fancy", "append", "addAll", "append", "multAll", "getIndex", "addAll", "append", "multAll", "getIndex", "getIndex", "getIndex"]
[[], [2], [3], [7], [2], [0], [3], [10], [2], [0], [1], [2]]
输出：
[null, null, null, null, null, 10, null, null, null, 26, 34, 20]

解释：
Fancy fancy = new Fancy();
fancy.append(2);   // 奇妙序列：[2]
fancy.addAll(3);   // 奇妙序列：[2+3] -> [5]
fancy.append(7);   // 奇妙序列：[5, 7]
fancy.multAll(2);  // 奇妙序列：[5*2, 7*2] -> [10, 14]
fancy.getIndex(0); // 返回 10
fancy.addAll(3);   // 奇妙序列：[10+3, 14+3] -> [13, 17]
fancy.append(10);  // 奇妙序列：[13, 17, 10]
fancy.multAll(2);  // 奇妙序列：[13*2, 17*2, 10*2] -> [26, 34, 20]
fancy.getIndex(0); // 返回 26
fancy.getIndex(1); // 返回 34
fancy.getIndex(2); // 返回 20


提示：

1 <= val, inc, m <= 100
0 <= idx <= 105
总共最多会有 105 次对 append，addAll，multAll 和 getIndex 的调用。
*/

#include <iostream>
#include "../check/CheckResult.h"

using namespace std;

class Fancy {
public:
    Fancy() {
        a = 1;
        b = 0;
        mod = 1000000007;
    }

    void append(int val) {
        // 在当前已经存在a、b的情况下，我们需要找到一个原始的v保存在values中，使得(a * v + b) % mod = val，这样后续对val的变换，可以统一到系数a、b上。解得v = (val - b) / a，使用乘法逆元解决除法问题
        values.push_back((int)((val + mod - b) % mod * fastPower(a, mod - 2, mod) % mod));
    }

    void addAll(int inc) {
        b = (b + inc) % mod;
    }

    void multAll(int m) {
        a = a * m % mod;
        b = b * m % mod;
    }

    int getIndex(int idx) {
        return idx < (int)values.size() ? (int)((values[idx] * a + b) % mod) : -1;
    }

    long long fastPower(long long x, long long n, long long mod) {
        long long ans = 1;

        while (n != 0) {
            if ((n & 1) == 1) {
                ans = ans * x % mod;
            }

            x = x * x % mod;
            n >>= 1;
        }

        return ans;
    }

private:
    vector<int> values;
    long long a;
    long long b;
    long long mod;
};

int main()
{
    CheckResult check;

    Fancy o1;
    o1.append(2);
    o1.addAll(3);
    o1.append(7);
    o1.multAll(2);
    check.checkInt(10, o1.getIndex(0));
    o1.addAll(3);
    o1.append(10);
    o1.multAll(2);
    check.checkInt(26, o1.getIndex(0));
    check.checkInt(34, o1.getIndex(1));
    check.checkInt(20, o1.getIndex(2));

    Fancy o2;
    o2.append(12);
    o2.append(8);
    check.checkInt(8, o2.getIndex(1));
    o2.append(12);
    check.checkInt(12, o2.getIndex(0));
    o2.addAll(12);
    o2.append(8);
    check.checkInt(24, o2.getIndex(2));
    check.checkInt(24, o2.getIndex(2));
    o2.append(4);
    o2.append(13);
    check.checkInt(4, o2.getIndex(4));
    o2.append(12);
    check.checkInt(12, o2.getIndex(6));
    o2.append(11);
    check.checkInt(20, o2.getIndex(1));
    o2.append(10);
    check.checkInt(24, o2.getIndex(2));
    o2.multAll(3);
    o2.addAll(1);
    check.checkInt(37, o2.getIndex(6));
    o2.append(14);
    o2.addAll(5);
    check.checkInt(42, o2.getIndex(6));
    o2.multAll(12);
    check.checkInt(360, o2.getIndex(3));
    o2.multAll(12);
    o2.addAll(15);
    o2.addAll(6);
    o2.append(7);
    o2.multAll(8);
    o2.append(13);
    o2.append(15);
    o2.append(15);
    o2.multAll(10);
    check.checkInt(220560, o2.getIndex(9));
    o2.multAll(12);
    o2.multAll(12);
    o2.multAll(9);
    check.checkInt(285845760, o2.getIndex(9));
    o2.addAll(9);
    o2.append(9);
    o2.multAll(4);
    o2.addAll(8);
    o2.addAll(11);
    o2.multAll(15);
    o2.addAll(9);
    o2.addAll(1);
    o2.append(4);
    o2.append(10);
    check.checkInt(150746316, o2.getIndex(9));
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
