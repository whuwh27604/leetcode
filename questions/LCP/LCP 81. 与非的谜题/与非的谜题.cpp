/* 与非的谜题.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
在永恒之森中，封存着有关万灵之树线索的卷轴，只要探险队通过最后的考验，便可以获取前往万灵之树的线索。

探险队需要从一段不断变化的谜题数组中找到最终的密码，初始的谜题为长度为 n 的数组 arr（下标从 0 开始），数组中的数字代表了 k 位二进制数。 破解谜题的过程中，需要使用 与非（NAND） 运算方式，operations[i] = [type,x,y] 表示第 i 次进行的谜题操作信息：

若 type = 0，表示修改操作，将谜题数组中下标 x 的数字变化为 y；
若 type = 1，表示运算操作，将数字 y 进行 x*n 次「与非」操作，第 i 次与非操作为 y = y NAND arr[i%n]；
运算操作结果即：y NAND arr[0%n] NAND arr[1%n] NAND arr[2%n] ... NAND arr[(x*n-1)%n]

最后，将所有运算操作的结果按顺序逐一进行 异或（XOR）运算，从而得到最终解开封印的密码。请返回最终解开封印的密码。

注意:

「与非」（NAND）的操作为：先进行 与 操作，后进行 非 操作。
例如：两个三位二进制数2和3，其与非结果为 NOT ((010) AND (011)) = (101) = 5

示例 1：

输入: k = 3 arr = [1,2] operations = [[1,2,3],[0,0,3],[1,2,2]]

输出: 2

解释： 初始的谜题数组为 [1,2]，二进制位数为 3， 第 0 次进行运算操作，将数字 3(011) 进行 2*2 次「与非」运算， 运算操作结果为 3 NAND 1 NAND 2 NAND 1 NAND 2 = 5 第 1 次进行修改操作，谜题数组的第 0 个数字变化为 3，谜题变成 [3,2] 第 2 次进行运算操作，将数字 2(010) 进行 2*2 次「与非」运算， 运算操作结果为 2 NAND 3 NAND 2 NAND 3 NAND 2 = 7 所有运算操作结果进行「异或」运算为 5 XOR 7 = 2 因此得到的最终密码为 2。

示例 2：

输入: k = 4 arr = [4,6,4,7,10,9,11] operations = [[1,5,7],[1,7,14],[0,6,7],[1,6,5]] 输出: 9 解释: 初始的谜题数组为 [4,6,4,7,10,9,11], 第 0 次进行运算操作，运算操作结果为 5； 第 1 次进行运算操作，运算操作结果为 5； 第 2 次进行修改操作，修改后谜题数组为 [4, 6, 4, 7, 10, 9, 7]； 第 3 次进行运算操作，运算操作结果为 9； 所有运算操作结果进行「异或」运算为 5 XOR 5 XOR 9 = 9； 因此得到的最终密码为 9。

提示:

1 <= arr.length, operations.length <= 10^4
1 <= k <= 30
0 <= arr[i] < 2^k
若 type = 0，0 <= x < arr.length 且 0 <= y < 2^k
若 type = 1，1 <= x < 10^9 且 0 <= y < 2^k
保证存在 type = 1 的操作
*/

#include <iostream>
#include <set>
#include "../check/CheckResult.h"

using namespace std;

class Solution {
public:
    int getNandResult(int k, vector<int>& arr, vector<vector<int>>& operations) {
        vector<set<int>> zeroIndices(k);
        int n = arr.size(), ans = 0;

        initZeroIndices(n, k, arr, zeroIndices);

        for (auto& operation : operations) {
            if (operation[0] == 0) {
                updateZeroIndices(k, arr, zeroIndices, operation[1], operation[2]);
            }
            else {
                ans ^= calc(n, k, zeroIndices, operation[1], operation[2]);
            }
        }

        return ans;
    }

    void initZeroIndices(int n, int k, vector<int>& arr, vector<set<int>>& zeroIndices) {
        for (int i = 0; i < n; ++i) {
            for (int j = 0, bit = 1; j < k; ++j, bit <<= 1) {
                if ((arr[i] & bit) == 0) {
                    zeroIndices[j].insert(i);
                }
            }
        }
    }

    void updateZeroIndices(int k, vector<int>& arr, vector<set<int>>& zeroIndices, int x, int y) {
        int num = arr[x];

        for (int i = 0, bit = 1; i < k; ++i, bit <<= 1) {
            if ((num & bit) == 0 && (y & bit) != 0) {
                zeroIndices[i].erase(x);
            }

            if ((num & bit) != 0 && (y & bit) == 0) {
                zeroIndices[i].insert(x);
            }
        }

        arr[x] = y;
    }

    int calc(int n, int k, vector<set<int>>& zeroIndices, int x, int y) {
        int ans = 0;

        for (int i = 0, bit = 1; i < k; ++i, bit <<= 1) {
            int operand = 0, opers = 0;

            if (zeroIndices[i].empty()) {  // 这一位没有0，一共要进行n * x次操作
                operand = ((y & bit) == 0) ? 0 : 1;  // y的bit位
                opers = ((n & 1) == 0 || (x & 1) == 0) ? 0 : 1;  // n与x中有一个是偶数，就是偶数次操作，否则奇数次操作
            }
            else {  // 这一位有0，那么最后一个0前面的操作忽略不计，最后一个0操作后会变为1，然后看还剩下多少个1
                operand = 1;
                opers = ((n - *zeroIndices[i].rbegin() - 1) & 1);
            }

            ans |= ((operand ^ opers) == 0 ? 0 : bit);  // 0奇数次操作得1，偶数次操作得0；1奇数次操作得0，偶数次操作得1
        }

        return ans;
    }
};

int main()
{
    CheckResult check;
    Solution o;

    vector<int> arr = { 1,2 };
    vector<vector<int>> operations = { {1,2,3},{0,0,3},{1,2,2} };
    check.checkInt(2, o.getNandResult(3, arr, operations));

    arr = { 4,6,4,7,10,9,11 };
    operations = { {1,5,7},{1,7,14},{0,6,7},{1,6,5} };
    check.checkInt(9, o.getNandResult(4, arr, operations));
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
