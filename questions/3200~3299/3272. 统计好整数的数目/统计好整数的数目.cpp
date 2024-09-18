/* 统计好整数的数目.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
给你两个 正 整数 n 和 k 。

如果一个整数 x 满足以下条件，那么它被称为 k 回文 整数 。

x 是一个
回文整数 。
x 能被 k 整除。
如果一个整数的数位重新排列后能得到一个 k 回文整数 ，那么我们称这个整数为 好 整数。比方说，k = 2 ，那么 2020 可以重新排列得到 2002 ，2002 是一个 k 回文串，所以 2020 是一个好整数。而 1010 无法重新排列数位得到一个 k 回文整数。

请你返回 n 个数位的整数中，有多少个 好 整数。

注意 ，任何整数在重新排列数位之前或者之后 都不能 有前导 0 。比方说 1010 不能重排列得到 101 。



示例 1：

输入：n = 3, k = 5

输出：27

解释：

部分好整数如下：

551 ，因为它可以重排列得到 515 。
525 ，因为它已经是一个 k 回文整数。
示例 2：

输入：n = 1, k = 4

输出：2

解释：

两个好整数分别是 4 和 8 。

示例 3：

输入：n = 5, k = 6

输出：2468



提示：

1 <= n <= 10
1 <= k <= 9
*/

#include <iostream>
#include <unordered_set>
#include <map>
#include <algorithm>
#include "../check/CheckResult.h"

using namespace std;

class Solution {
public:
    long long countGoodIntegers(int n, int k) {
        if (n == 1) {
            return get1Goods(k);
        }

        vector<long long> factorials(n + 1, 1);
        for (int i = 1; i <= n; ++i) {
            factorials[i] = factorials[i - 1] * i;
        }

        long long goods = 0;
        int m = n / 2, start = (int)pow(10, m - 1), end = start * 10 - 1;
        unordered_set<string> keys;

        for (int left = start; left <= end; ++left) {  // 枚举回文串的左边
            string num = to_string(left);
            if ((n & 1) == 0) {
                num += string(num.rbegin(), num.rend());  // 拼接完整回文串
                goods += getGoods(num, k, keys, factorials);
            }
            else {
                for (char c = '0'; c <= '9'; ++c) {  // 奇数，枚举中间字符
                    string tmp = num + c;
                    tmp += string(num.rbegin(), num.rend());  // 拼接完整回文串
                    goods += getGoods(tmp, k, keys, factorials);
                }
            }
        }

        return goods;
    }

    long long get1Goods(int k) {
        long long goods = 0;

        for (int num = 1; num < 10; ++num) {
            if (num % k == 0) {
                ++goods;
            }
        }

        return goods;
    }

    long long getGoods(string& num, int k, unordered_set<string>& keys, vector<long long>& factorials) {
        long long number = stoll(num);
        if (number % k != 0) {  // 不能被k整除
            return 0;
        }

        string key = num;
        sort(key.begin(), key.end());  // 一个序列的key
        if (keys.count(key) != 0) {  // 这个序列已经统计过了
            return 0;
        }
        keys.insert(key);

        map<char, int> digitals;  // 统计每个数字的个数
        for (char c : num) {
            ++digitals[c];
        }

        int len = (int)num.size();
        long long goods = digitals.begin()->first == '0' ? (len - digitals.begin()->second) * factorials[len - 1] : factorials[len];  // 第一个数字不能取0，剩下的全排列

        for (auto& kv : digitals) {
            goods /= factorials[kv.second];  // 对于相同的数字，排列一样无法区分，所以要除以相同个数的排列数
        }

        return goods;
    }
};

int main()
{
    Solution o;
    CheckResult check;

    vector<vector<long long>> expected = { {0,0,0,0,0,0,0,0,0,0,},
                                        {0,9,4,3,2,1,1,1,1,1,},
                                        {0,9,4,3,2,1,1,1,1,1,},
                                        {0,243,108,69,54,27,30,33,27,23,},
                                        {0,252,172,84,98,52,58,76,52,28,},
                                        {0,10935,7400,3573,4208,2231,2468,2665,2231,1191,},
                                        {0,10944,9064,3744,6992,3256,3109,3044,5221,1248,},
                                        {0,617463,509248,206217,393948,182335,170176,377610,292692,68739,},
                                        {0,617472,563392,207840,494818,237112,188945,506388,460048,69280,},
                                        {0,41457015,37728000,13726509,33175696,15814071,12476696,36789447,30771543,4623119,},
                                        {0,41457024,39718144,13831104,37326452,19284856,13249798,40242031,35755906,4610368,} };

    for (int n = 1; n <= 10; ++n) {
        for (int k = 1; k <= 9; ++k) {
            check.checkLongLong(expected[n][k], o.countGoodIntegers(n, k));
        }
    }
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
