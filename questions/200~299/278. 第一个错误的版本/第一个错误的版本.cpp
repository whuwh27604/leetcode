/* 第一个错误的版本.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
你是产品经理，目前正在带领一个团队开发新的产品。不幸的是，你的产品的最新版本没有通过质量检测。由于每个版本都是基于之前的版本开发的，所以错误的版本之后的所有版本都是错的。

假设你有 n 个版本 [1, 2, ..., n]，你想找出导致之后所有版本出错的第一个错误的版本。

你可以通过调用 bool isBadVersion(version) 接口来判断版本号 version 是否在单元测试中出错。实现一个函数来查找第一个错误的版本。你应该尽量减少对调用 API 的次数。

示例:

给定 n = 5，并且 version = 4 是第一个错误的版本。

调用 isBadVersion(3) -> false
调用 isBadVersion(5) -> true
调用 isBadVersion(4) -> true

所以，4 是第一个错误的版本。 

来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/first-bad-version
著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。
*/

#include <iostream>
#include "../check/CheckResult.h"

using namespace std;

// The API isBadVersion is defined for you.
// bool isBadVersion(int version);
/*
// testcase1
bool isBadVersion(int version) {
    return (version >= 4);
}

// testcase2
bool isBadVersion(int version) {
    return (version >= 1);
}

// testcase3
bool isBadVersion(int version) {
    return (version >= 5);
}

// testcase4
bool isBadVersion(int version) {
    return (version >= 6);
}

// testcase5
bool isBadVersion(int version) {
    return (version >= 1);
}

// testcase6
bool isBadVersion(int version) {
    return (version >= 6);
}

// testcase7
bool isBadVersion(int version) {
    return (version >= 4);
}
*/
// testcase8
bool isBadVersion(int version) {
    return (version >= INT_MAX);
}

class Solution {
public:
    int firstBadVersion(int n) {
        return (int)findFirstBadVersion(1, n);
    }

    long long findFirstBadVersion(long long left, long long right) {
        long long middle = ((left + right) / 2);
        if (!isBadVersion((int)middle)) {
            if (middle == right) {
                return -1;
            }
            return findFirstBadVersion((middle + 1), right);
        }

        if (middle == left) {
            return middle;
        }

        if (!isBadVersion((int)(middle - 1))) {
            return middle;
        }

        return findFirstBadVersion(left, (middle - 1));
    }
};

int main()
{
    Solution o;
    CheckResult check;

    // testcase1
    check.checkInt(4, o.firstBadVersion(5));

    // testcase2
    check.checkInt(1, o.firstBadVersion(5));

    // testcase3
    check.checkInt(5, o.firstBadVersion(5));

    // testcase4
    check.checkInt(-1, o.firstBadVersion(5));

    // testcase5
    check.checkInt(1, o.firstBadVersion(1));

    // testcase6
    check.checkInt(-1, o.firstBadVersion(1));

    // testcase7
    check.checkInt(4, o.firstBadVersion(INT_MAX));

    // testcase8
    check.checkInt(INT_MAX, o.firstBadVersion(INT_MAX));
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
