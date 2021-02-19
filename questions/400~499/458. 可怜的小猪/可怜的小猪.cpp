/* 可怜的小猪.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
有 buckets 桶液体，其中 正好 有一桶含有毒药，其余装的都是水。它们从外观看起来都一样。为了弄清楚哪只水桶含有毒药，你可以喂一些猪喝，通过观察猪是否会死进行判断。不幸的是，你只有 minutesToTest 分钟时间来确定哪桶液体是有毒的。

喂猪的规则如下：

选择若干活猪进行喂养
可以允许小猪同时饮用任意数量的桶中的水，并且该过程不需要时间。
小猪喝完水后，必须有 minutesToDie 分钟的冷却时间。在这段时间里，你只能观察，而不允许继续喂猪。
过了 minutesToDie 分钟后，所有喝到毒药的猪都会死去，其他所有猪都会活下来。
重复这一过程，直到时间用完。
给你桶的数目 buckets ，minutesToDie 和 minutesToTest ，返回在规定时间内判断哪个桶有毒所需的 最小 猪数。

 

示例 1：

输入：buckets = 1000, minutesToDie = 15, minutesToTest = 60
输出：5
示例 2：

输入：buckets = 4, minutesToDie = 15, minutesToTest = 15
输出：2
示例 3：

输入：buckets = 4, minutesToDie = 15, minutesToTest = 30
输出：2
 

提示：

1 <= buckets <= 1000
1 <= minutesToDie <= minutesToTest <= 100

来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/poor-pigs
著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。
*/

#include <iostream>
#include "../check/CheckResult.h"

using namespace std;

class Solution {
public:
    int poorPigs(int buckets, int minutesToDie, int minutesToTest) {
        /* 有x=minutesToTest/minutesToDie次机会，可以携带的信息量为base=x+1。y只小猪总的信息量是pow(base,y)。
           所以有pow(base,y)>=buckets，y=buckets以base为底取对数=log(buckets)/log(base) */
        return (int)ceil(log(buckets) / log(minutesToTest / minutesToDie + 1));
    }
};

int main()
{
    CheckResult check;
    Solution o;

    check.checkInt(5, o.poorPigs(1000, 15, 60));
    check.checkInt(2, o.poorPigs(4, 15, 15));
    check.checkInt(2, o.poorPigs(4, 15, 30));
    check.checkInt(0, o.poorPigs(1, 1, 1));
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
