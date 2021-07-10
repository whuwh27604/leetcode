/* 邻位交换的最小次数.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
给你一个表示大整数的字符串 num ，和一个整数 k 。

如果某个整数是 num 中各位数字的一个 排列 且它的 值大于 num ，则称这个整数为 妙数 。可能存在很多妙数，但是只需要关注 值最小 的那些。

例如，num = "5489355142" ：
第 1 个最小妙数是 "5489355214"
第 2 个最小妙数是 "5489355241"
第 3 个最小妙数是 "5489355412"
第 4 个最小妙数是 "5489355421"
返回要得到第 k 个 最小妙数 需要对 num 执行的 相邻位数字交换的最小次数 。

测试用例是按存在第 k 个最小妙数而生成的。

 

示例 1：

输入：num = "5489355142", k = 4
输出：2
解释：第 4 个最小妙数是 "5489355421" ，要想得到这个数字：
- 交换下标 7 和下标 8 对应的位："5489355142" -> "5489355412"
- 交换下标 8 和下标 9 对应的位："5489355412" -> "5489355421"
示例 2：

输入：num = "11112", k = 4
输出：4
解释：第 4 个最小妙数是 "21111" ，要想得到这个数字：
- 交换下标 3 和下标 4 对应的位："11112" -> "11121"
- 交换下标 2 和下标 3 对应的位："11121" -> "11211"
- 交换下标 1 和下标 2 对应的位："11211" -> "12111"
- 交换下标 0 和下标 1 对应的位："12111" -> "21111"
示例 3：

输入：num = "00123", k = 1
输出：1
解释：第 1 个最小妙数是 "00132" ，要想得到这个数字：
- 交换下标 3 和下标 4 对应的位："00123" -> "00132"
 

提示：

2 <= num.length <= 1000
1 <= k <= 1000
num 仅由数字组成

来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/minimum-adjacent-swaps-to-reach-the-kth-smallest-number
著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。
*/

#include <iostream>
#include <algorithm>
#include "../check/CheckResult.h"

using namespace std;

class Solution {
public:
    int getMinSwaps(string num, int k) {
        string target = num;

        getKthPermutation(target, k);

        return getSwaps(num, target);
    }

    void getKthPermutation(string& num, int k) {
        for (int i = 0; i < k; ++i) {
            next_permutation(num.begin(), num.end());
        }
    }

    int getSwaps(string& num, string& target) {
        int i, j, size = num.size(), swaps = 0;

        for (i = 0, j = 0; i < size; ++i, ++j) {
            if (target[i] == num[j]) {
                continue;
            }

            int tmp = j;

            for (; j < size && num[j] != target[i]; ++j) {
                if (num[j] != 'a') {
                    ++swaps;
                }
            }

            num[j] = 'a';
            j = tmp - 1;
        }

        return swaps;
    }
};

int main()
{
    CheckResult check;
    Solution o;

    check.checkInt(2, o.getMinSwaps("5489355142", 4));
    check.checkInt(4, o.getMinSwaps("11112", 4));
    check.checkInt(1, o.getMinSwaps("00123", 1));
    check.checkInt(1, o.getMinSwaps("01", 1));
    check.checkInt(6, o.getMinSwaps("123456789", 100));
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
