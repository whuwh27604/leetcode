/* 巫师的总力量和.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
作为国王的统治者，你有一支巫师军队听你指挥。

给你一个下标从 0 开始的整数数组 strength ，其中 strength[i] 表示第 i 位巫师的力量值。对于连续的一组巫师（也就是这些巫师的力量值是 strength 的 子数组），总力量 定义为以下两个值的 乘积 ：

巫师中 最弱 的能力值。
组中所有巫师的个人力量值 之和 。
请你返回 所有 巫师组的 总 力量之和。由于答案可能很大，请将答案对 109 + 7 取余 后返回。

子数组 是一个数组里 非空 连续子序列。

 

示例 1：

输入：strength = [1,3,1,2]
输出：44
解释：以下是所有连续巫师组：
- [1,3,1,2] 中 [1] ，总力量值为 min([1]) * sum([1]) = 1 * 1 = 1
- [1,3,1,2] 中 [3] ，总力量值为 min([3]) * sum([3]) = 3 * 3 = 9
- [1,3,1,2] 中 [1] ，总力量值为 min([1]) * sum([1]) = 1 * 1 = 1
- [1,3,1,2] 中 [2] ，总力量值为 min([2]) * sum([2]) = 2 * 2 = 4
- [1,3,1,2] 中 [1,3] ，总力量值为 min([1,3]) * sum([1,3]) = 1 * 4 = 4
- [1,3,1,2] 中 [3,1] ，总力量值为 min([3,1]) * sum([3,1]) = 1 * 4 = 4
- [1,3,1,2] 中 [1,2] ，总力量值为 min([1,2]) * sum([1,2]) = 1 * 3 = 3
- [1,3,1,2] 中 [1,3,1] ，总力量值为 min([1,3,1]) * sum([1,3,1]) = 1 * 5 = 5
- [1,3,1,2] 中 [3,1,2] ，总力量值为 min([3,1,2]) * sum([3,1,2]) = 1 * 6 = 6
- [1,3,1,2] 中 [1,3,1,2] ，总力量值为 min([1,3,1,2]) * sum([1,3,1,2]) = 1 * 7 = 7
所有力量值之和为 1 + 9 + 1 + 4 + 4 + 4 + 3 + 5 + 6 + 7 = 44 。
示例 2：

输入：strength = [5,4,6]
输出：213
解释：以下是所有连续巫师组：
- [5,4,6] 中 [5] ，总力量值为 min([5]) * sum([5]) = 5 * 5 = 25
- [5,4,6] 中 [4] ，总力量值为 min([4]) * sum([4]) = 4 * 4 = 16
- [5,4,6] 中 [6] ，总力量值为 min([6]) * sum([6]) = 6 * 6 = 36
- [5,4,6] 中 [5,4] ，总力量值为 min([5,4]) * sum([5,4]) = 4 * 9 = 36
- [5,4,6] 中 [4,6] ，总力量值为 min([4,6]) * sum([4,6]) = 4 * 10 = 40
- [5,4,6] 中 [5,4,6] ，总力量值为 min([5,4,6]) * sum([5,4,6]) = 4 * 15 = 60
所有力量值之和为 25 + 16 + 36 + 36 + 40 + 60 = 213 。
 

提示：

1 <= strength.length <= 105
1 <= strength[i] <= 109

来源：力扣（LeetCode）
链接：https://leetcode.cn/problems/sum-of-total-strength-of-wizards
著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。
*/

#include <iostream>
#include <stack>
#include "../check/CheckResult.h"
#include "../tools/TestData.h"

using namespace std;

class Solution {
public:
    int totalStrength(vector<int>& strength) {
        int size = strength.size(), mod = 1000000007;
        vector<int> leftLess(size), rightLess(size);
        vector<long long> presums(size + 1, 0), prepresums(size + 2, 0);

        getLeftLess(strength, leftLess);
        getRightLess(strength, rightLess);
        getPresum(strength, presums, mod);
        getPrepresum(presums, prepresums, mod);

        return getTotalStrength(strength, leftLess, rightLess, prepresums, mod);
    }

    void getLeftLess(vector<int>& strength, vector<int>& leftLess) {
        stack<int> increasingIndices;

        for (int i = 0; i < (int)strength.size(); ++i) {
            while (!increasingIndices.empty() && strength[increasingIndices.top()] > strength[i]) {
                increasingIndices.pop();
            }

            leftLess[i] = increasingIndices.empty() ? -1 : increasingIndices.top();
            increasingIndices.push(i);
        }
    }

    void getRightLess(vector<int>& strength, vector<int>& rightLess) {
        stack<int> increasingIndices;

        for (int i = strength.size() - 1; i >= 0; --i) {
            while (!increasingIndices.empty() && strength[increasingIndices.top()] >= strength[i]) {
                increasingIndices.pop();
            }

            rightLess[i] = increasingIndices.empty() ? strength.size() : increasingIndices.top();
            increasingIndices.push(i);
        }
    }

    void getPresum(vector<int>& strength, vector<long long>& presums, int mod) {
        for (int i = 0; i < (int)strength.size(); ++i) {
            presums[i + 1] = (presums[i] + strength[i]) % mod;
        }
    }

    void getPrepresum(vector<long long>& presums, vector<long long>& prepresums, int mod) {
        for (int i = 0; i < (int)presums.size(); ++i) {
            prepresums[i + 1] = (prepresums[i] + presums[i]) % mod;
        }
    }

    int getTotalStrength(vector<int>& strength, vector<int>& leftLess, vector<int>& rightLess, vector<long long>& prepresums, int mod) {
        long long total = 0;

        for (int i = 0; i < (int)strength.size(); ++i) {
            int left = leftLess[i] + 1, right = rightLess[i] - 1;
            long long sum = ((long long)i + 1 - left) * ((prepresums[right + 2] + mod - prepresums[i + 1]) % mod) % mod;
            sum += mod;
            sum = (sum - ((long long)right + 1 - i) * ((prepresums[i + 1] + mod - prepresums[left]) % mod) % mod) % mod;
            total = (total + strength[i] * sum) % mod;
        }

        return (int)total;
    }
};

int main()
{
    CheckResult check;
    Solution o;

    vector<int> strength = { 1,3,1,2 };
    check.checkInt(44, o.totalStrength(strength));

    strength = { 5,4,6 };
    check.checkInt(213, o.totalStrength(strength));

    strength = { 747,812,112,1230,1426,1477,1388,976,849,1431,1885,1845,1070,1980,280,1075,232,1330,1868,1696,1361,1822,524,1899,1904,538,731,985,279,1608,1558,930,1232,1497,875,1850,1173,805,1720,33,233,330,1429,1688,281,362,1963,927,1688,256,1594,1823,743,553,1633,1898,1101,1278,717,522,1926,1451,119,1283,1016,194,780,1436,1233,710,1608,523,874,1779,1822,134,1984 };
    check.checkInt(471441678, o.totalStrength(strength));

    strength = getIntVector("./testcase1.txt");
    check.checkInt(121473332, o.totalStrength(strength));
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
