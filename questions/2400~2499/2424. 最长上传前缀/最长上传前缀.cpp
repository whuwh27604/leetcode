/* 最长上传前缀.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
给你一个 n 个视频的上传序列，每个视频编号为 1 到 n 之间的 不同 数字，你需要依次将这些视频上传到服务器。请你实现一个数据结构，在上传的过程中计算 最长上传前缀 。

如果 闭区间 1 到 i 之间的视频全部都已经被上传到服务器，那么我们称 i 是上传前缀。最长上传前缀指的是符合定义的 i 中的 最大值 。

请你实现 LUPrefix 类：

LUPrefix(int n) 初始化一个 n 个视频的流对象。
void upload(int video) 上传 video 到服务器。
int longest() 返回上述定义的 最长上传前缀 的长度。
 

示例 1：

输入：
["LUPrefix", "upload", "longest", "upload", "longest", "upload", "longest"]
[[4], [3], [], [1], [], [2], []]
输出：
[null, null, 0, null, 1, null, 3]

解释：
LUPrefix server = new LUPrefix(4);   // 初始化 4个视频的上传流
server.upload(3);                    // 上传视频 3 。
server.longest();                    // 由于视频 1 还没有被上传，最长上传前缀是 0 。
server.upload(1);                    // 上传视频 1 。
server.longest();                    // 前缀 [1] 是最长上传前缀，所以我们返回 1 。
server.upload(2);                    // 上传视频 2 。
server.longest();                    // 前缀 [1,2,3] 是最长上传前缀，所以我们返回 3 。
 

提示：

1 <= n <= 105
1 <= video <= 105
video 中所有值 互不相同 。
upload 和 longest 总调用 次数至多不超过 2 * 105 次。
至少会调用 longest 一次。

来源：力扣（LeetCode）
链接：https://leetcode.cn/problems/longest-uploaded-prefix
著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。
*/

#include <iostream>
#include "../check/CheckResult.h"

using namespace std;

class LUPrefix {
public:
    LUPrefix(int n) {
        videoes.resize(n + 2, false);
        LUP = 0;
    }

    void upload(int video) {
        videoes[video] = true;

        while (videoes[LUP + 1]) {
            ++LUP;
        }
    }

    int longest() {
        return LUP;
    }

private:
    vector<bool> videoes;
    int LUP;
};


int main()
{
    CheckResult check;

    LUPrefix o1(4);
    o1.upload(3);
    check.checkInt(0, o1.longest());
    o1.upload(1);
    check.checkInt(1, o1.longest());
    o1.upload(2);
    check.checkInt(3, o1.longest());
    o1.upload(4);
    check.checkInt(4, o1.longest());
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
