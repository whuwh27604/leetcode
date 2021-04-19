/* 黑名单中的随机数.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
给定一个包含 [0，n ) 中独特的整数的黑名单 B，写一个函数从 [ 0，n ) 中返回一个不在 B 中的随机整数。

对它进行优化使其尽量少调用系统方法 Math.random() 。

提示:

1 <= N <= 1000000000
0 <= B.length < min(100000, N)
[0, N) 不包含 N，详细参见 interval notation 。
示例 1:

输入:
["Solution","pick","pick","pick"]
[[1,[]],[],[],[]]
输出: [null,0,0,0]
示例 2:

输入:
["Solution","pick","pick","pick"]
[[2,[]],[],[],[]]
输出: [null,1,1,1]
示例 3:

输入:
["Solution","pick","pick","pick"]
[[3,[1]],[],[],[]]
Output: [null,0,0,2]
示例 4:

输入:
["Solution","pick","pick","pick"]
[[4,[2]],[],[],[]]
输出: [null,1,3,1]
输入语法说明：

输入是两个列表：调用成员函数名和调用的参数。Solution的构造函数有两个参数，N 和黑名单 B。pick 没有参数，输入参数是一个列表，即使参数为空，也会输入一个 [] 空列表。

来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/random-pick-with-blacklist
著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。
*/

#include <iostream>
#include <unordered_set>
#include <unordered_map>
#include <random>
#include "../check/CheckResult.h"

using namespace std;

class Solution {
public:
    Solution(int N, vector<int>& blacklist) {
        int bSize = blacklist.size();
        n = N;
        k = N - bSize;
        unordered_set<int> whiteNolessK;

        initWhiteNolessK(whiteNolessK);
        eraseBlackNolessK(whiteNolessK, blacklist);
        mappingBlack2White(whiteNolessK, blacklist, b2w);
    }

    void initWhiteNolessK(unordered_set<int>& whiteNolessK) {
        for (int i = k; i < n; ++i) {
            whiteNolessK.insert(i);
        }
    }

    void eraseBlackNolessK(unordered_set<int>& whiteNolessK, vector<int>& blacklist) {
        for (int num : blacklist) {
            if (num >= k) {
                whiteNolessK.erase(num);
            }
        }
    }

    void mappingBlack2White(unordered_set<int>& whiteNolessK, vector<int>& blacklist, unordered_map<int, int>& b2w) {
        auto iter = whiteNolessK.begin();

        for (int num : blacklist) {
            if (num < k) {
                b2w[num] = *iter;
                ++iter;
            }
        }
    }

    int pick() {
        int rnum = rd() % k;
        return b2w.count(rnum) == 0 ? rnum : b2w[rnum];
    }

private:
    int n;
    int k;
    unordered_map<int, int> b2w;
    random_device rd;
};

int main()
{
    vector<int> blacklist;
    Solution o1(1, blacklist);
    cout << "{ ";
    for (int i = 0; i < 20; ++i) {
        cout << o1.pick() << " ";
    }
    cout << "}" << endl;

    blacklist;
    Solution o2(2, blacklist);
    cout << "{ ";
    for (int i = 0; i < 20; ++i) {
        cout << o2.pick() << " ";
    }
    cout << "}" << endl;

    blacklist = { 1 };
    Solution o3(3, blacklist);
    cout << "{ ";
    for (int i = 0; i < 20; ++i) {
        cout << o3.pick() << " ";
    }
    cout << "}" << endl;

    blacklist = { 2 };
    Solution o4(4, blacklist);
    cout << "{ ";
    for (int i = 0; i < 20; ++i) {
        cout << o4.pick() << " ";
    }
    cout << "}" << endl;

    blacklist = { 2,4 };
    Solution o5(6, blacklist);
    cout << "{ ";
    for (int i = 0; i < 20; ++i) {
        cout << o5.pick() << " ";
    }
    cout << "}" << endl;
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
