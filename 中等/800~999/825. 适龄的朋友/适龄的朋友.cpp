/* 适龄的朋友.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
人们会互相发送好友请求，现在给定一个包含有他们年龄的数组，ages[i] 表示第 i 个人的年龄。

当满足以下任一条件时，A 不能给 B（A、B不为同一人）发送好友请求：

age[B] <= 0.5 * age[A] + 7
age[B] > age[A]
age[B] > 100 && age[A] < 100
否则，A 可以给 B 发送好友请求。

注意如果 A 向 B 发出了请求，不等于 B 也一定会向 A 发出请求。而且，人们不会给自己发送好友请求。 

求总共会发出多少份好友请求?

 

示例 1：

输入：[16,16]
输出：2
解释：二人可以互发好友申请。
示例 2：

输入：[16,17,18]
输出：2
解释：好友请求可产生于 17 -> 16, 18 -> 17.
示例 3：

输入：[20,30,100,110,120]
输出：3
解释：好友请求可产生于 110 -> 100, 120 -> 110, 120 -> 100.
 

提示：

1 <= ages.length <= 20000.
1 <= ages[i] <= 120.

来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/friends-of-appropriate-ages
著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。
*/

#include <iostream>
#include "../check/CheckResult.h"

using namespace std;

class Solution {
public:
    int numFriendRequests(vector<int>& ages) {
        int ageCount[121] = { 0 }, requests = 0;

        countAges(ages, ageCount);

        for (int age = 15; age <= 120; ++age) {
            for (int i = age / 2 + 8; i < age; ++i) {
                requests += (ageCount[i] * ageCount[age]);
            }

            requests += (ageCount[age] * (ageCount[age] - 1));
        }

        return requests;
    }

    void countAges(vector<int>& ages, int* ageCount) {
        for (int age : ages) {
            ++ageCount[age];
        }
    }
};

int main()
{
    Solution o;
    CheckResult check;

    vector<int> ages = { 14,15 };
    check.checkInt(0, o.numFriendRequests(ages));

    ages = { 15,15 };
    check.checkInt(2, o.numFriendRequests(ages));

    ages = { 16,16 };
    check.checkInt(2, o.numFriendRequests(ages));

    ages = { 16,17,18 };
    check.checkInt(2, o.numFriendRequests(ages));

    ages = { 20,30,100,110,120 };
    check.checkInt(3, o.numFriendRequests(ages));
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
