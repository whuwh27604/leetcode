/* 美观的花束.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
力扣嘉年华的花店中从左至右摆放了一排鲜花，记录于整型一维矩阵 flowers 中每个数字表示该位置所种鲜花的品种编号。你可以选择一段区间的鲜花做成插花，且不能丢弃。 在你选择的插花中，如果每一品种的鲜花数量都不超过 cnt 朵，那么我们认为这束插花是 「美观的」。

例如：[5,5,5,6,6] 中品种为 5 的花有 3 朵， 品种为 6 的花有 2 朵，每一品种 的数量均不超过 3
请返回在这一排鲜花中，共有多少种可选择的区间，使得插花是「美观的」。

注意：

答案需要以 1e9 + 7 (1000000007) 为底取模，如：计算初始结果为：1000000008，请返回 1
示例 1：

输入：flowers = [1,2,3,2], cnt = 1

输出：8

解释：相同的鲜花不超过 1 朵，共有 8 种花束是美观的； 长度为 1 的区间 [1]、[2]、[3]、[2] 均满足条件，共 4 种可选择区间 长度为 2 的区间 [1,2]、[2,3]、[3,2] 均满足条件，共 3 种可选择区间 长度为 3 的区间 [1,2,3] 满足条件，共 1 种可选择区间。 区间 [2,3,2],[1,2,3,2] 都包含了 2 朵鲜花 2 ，不满足条件。 返回总数 4+3+1 = 8

示例 2：

输入：flowers = [5,3,3,3], cnt = 2

输出：8

提示：

1 <= flowers.length <= 10^5
1 <= flowers[i] <= 10^5
1 <= cnt <= 10^5
*/

#include <iostream>
#include <unordered_map>
#include "../check/CheckResult.h"

using namespace std;

class Solution {
public:
    int beautifulBouquet(vector<int>& flowers, int cnt) {
        unordered_map<int, int> count;
        int left = 0, size = (int)flowers.size();
        long long ans = 0;

        for (int right = 0; right < size; ++right) {
            int num = flowers[right];
            ++count[num];

            while (count[num] > cnt) {
                --count[flowers[left++]];
            }

            ans += ((long long)right - left + 1);
        }

        return (int)(ans % 1000000007);
    }
};

int main()
{
    Solution o;
    CheckResult check;

    vector<int> flowers = { 1,2,3,2 };
    check.checkInt(8, o.beautifulBouquet(flowers, 1));

    flowers = { 5,3,3,3 };
    check.checkInt(8, o.beautifulBouquet(flowers, 2));
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
