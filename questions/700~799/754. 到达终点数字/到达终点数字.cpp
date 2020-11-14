/* 到达终点数字.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
在一根无限长的数轴上，你站在0的位置。终点在target的位置。

每次你可以选择向左或向右移动。第 n 次移动（从 1 开始），可以走 n 步。

返回到达终点需要的最小移动次数。

示例 1:

输入: target = 3
输出: 2
解释:
第一次移动，从 0 到 1 。
第二次移动，从 1 到 3 。
示例 2:

输入: target = 2
输出: 3
解释:
第一次移动，从 0 到 1 。
第二次移动，从 1 到 -1 。
第三次移动，从 -1 到 2 。
注意:

target是在[-10^9, 10^9]范围中的非零整数。

来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/reach-a-number
著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。
*/

#include <iostream>
#include "../check/CheckResult.h"

using namespace std;

class Solution {
public:
    int reachNumber(int target) {
        /* 简单模拟一下：
           1: -1,1
           2: -3,-1,1,3
           3: -6,-4,-2,0,2,4,6
           4: -10,-8,-6,-4,-2,0,2,4,6,8,10
           5: -15,-13,-11,-9,-7,-5,-3,-1,1,3,5,7,9,11,13,15
           数学归纳法可以证明每一个...n-6,n-4,n-2,n,n+2,n+4,n+6...都是可达的，数列出现的顺序是奇奇偶偶...*/
        target = abs(target);
        int root = (int)sqrt(target * 2);
        if ((root * (root + 1) / 2) < target) {
            root++;  //  加1后，root * (root + 1) / 2一定会大于target
        }

        if (target % 2 == 0) {
            if ((root % 4) == 1) {  // root落在[奇奇偶偶]的第1个，要使结果为偶数，需要调整到第3个，所以加2
                root += 2;
            }
            else if ((root % 4) == 2) {  // root落在[奇奇偶偶]的第2个，要使结果为偶数，需要调整到第3个，所以加1
                root += 1;
            }
        }
        else {
            if ((root % 4) == 3) {  // root落在[奇奇偶偶]的第3个，要使结果为奇数，需要调整到下一轮第1个，所以加2
                root += 2;
            }
            else if ((root % 4) == 0) {  // root落在[奇奇偶偶]的第4个，要使结果为奇数，需要调整到下一轮第1个，所以加1
                root += 1;
            }
        }

        return root;
    }
};

int main()
{
    Solution o;
    CheckResult check;

    check.checkInt(0, o.reachNumber(0));  // 到底是0还是3，题目没有说清楚
    check.checkInt(1, o.reachNumber(1));
    check.checkInt(1, o.reachNumber(-1));
    check.checkInt(5, o.reachNumber(5));
    check.checkInt(4, o.reachNumber(8));
    check.checkInt(4, o.reachNumber(10));
    check.checkInt(5, o.reachNumber(11));
    check.checkInt(7, o.reachNumber(12));
    check.checkInt(5, o.reachNumber(13));
    check.checkInt(7, o.reachNumber(14));
    check.checkInt(5, o.reachNumber(15));
    check.checkInt(7, o.reachNumber(16));
    check.checkInt(6, o.reachNumber(17));
    check.checkInt(14143, o.reachNumber(100000000));
    check.checkInt(14143, o.reachNumber(-100000000));
    check.checkInt(44723, o.reachNumber(1000000000));
    check.checkInt(44723, o.reachNumber(-1000000000));
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
