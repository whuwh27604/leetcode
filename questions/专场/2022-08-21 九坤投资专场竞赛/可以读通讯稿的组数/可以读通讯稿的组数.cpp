/* 可以读通讯稿的组数.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
校运动会上，所有参赛同学身上都贴有他的参赛号码。某班参赛同学的号码记于数组 nums 中。假定反转后的号码称为原数字的「镜像号码」。如果 两位同学 满足条件：镜像号码 A + 原号码 B = 镜像号码 B + 原号码 A，则这两位同学可以到广播站兑换一次读通讯稿的机会，为同班同学加油助威。请返回所有参赛同学可以组成的可以读通讯稿的组数，并将结果对10^9+7取余。

注意：

镜像号码中如存在前置零，则忽略前置零。
同一位同学可有多次兑换机会。
示例 1：

输入：nums = [17,28,39,71]

输出：3

解释：
共有三对同学，分别为 [17,28]、[17,39]、[28,39]。其中：
第一对同学：17 + 82 = 71 + 28；
第二对同学：17 + 93 = 71 + 39；
第三对同学：28 + 93 = 82 + 39。

示例 2：

输入：nums = [71, 60]

输出：1

解释：
共有一对同学，为 [71, 60]。
因为 71 + 6 = 17 + 60，此处 60 的镜像号码为 6，前导零被忽略。

提示：

0 <= nums.length <= 10^6
0 <= nums[i] <= 10^9
*/

#include <iostream>
#include <unordered_map>
#include "../check/CheckResult.h"

using namespace std;

class Solution {
public:
    int numberOfPairs(vector<int>& nums) {
        unordered_map<long long, long long> diffCount;
        long long pairs = 0;

        for (int num : nums) {
            string snum = to_string(num);
            reverse(snum.begin(), snum.end());
            ++diffCount[num - stoll(snum)];
        }

        for (auto& kv : diffCount) {
            pairs += kv.second * (kv.second - 1) / 2;
        }

        return (int)(pairs % 1000000007);
    }
};

int main()
{
    CheckResult check;
    Solution o;

    vector<int> nums = { 17,28,39,71 };
    check.checkInt(3, o.numberOfPairs(nums));

    nums = { 71,60 };
    check.checkInt(1, o.numberOfPairs(nums));
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
