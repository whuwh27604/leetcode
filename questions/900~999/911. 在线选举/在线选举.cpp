/* 在线选举.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
在选举中，第 i 张票是在时间为 times[i] 时投给 persons[i] 的。

现在，我们想要实现下面的查询函数： TopVotedCandidate.q(int t) 将返回在 t 时刻主导选举的候选人的编号。

在 t 时刻投出的选票也将被计入我们的查询之中。在平局的情况下，最近获得投票的候选人将会获胜。

示例：

输入：["TopVotedCandidate","q","q","q","q","q","q"], [[[0,1,1,0,0,1,0],[0,5,10,15,20,25,30]],[3],[12],[25],[15],[24],[8]]
输出：[null,0,1,1,0,0,1]
解释：
时间为 3，票数分布情况是 [0]，编号为 0 的候选人领先。
时间为 12，票数分布情况是 [0,1,1]，编号为 1 的候选人领先。
时间为 25，票数分布情况是 [0,1,1,0,0,1]，编号为 1 的候选人领先（因为最近的投票结果是平局）。
在时间 15、24 和 8 处继续执行 3 个查询。
 

提示：

1 <= persons.length = times.length <= 5000
0 <= persons[i] <= persons.length
times 是严格递增的数组，所有元素都在 [0, 10^9] 范围中。
每个测试用例最多调用 10000 次 TopVotedCandidate.q。
TopVotedCandidate.q(int t) 被调用时总是满足 t >= times[0]。

来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/online-election
著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。
*/

#include <iostream>
#include <map>
#include "../check/CheckResult.h"

using namespace std;

class TopVotedCandidate {
public:
    TopVotedCandidate(vector<int>& persons, vector<int>& times) {
        int i, size = times.size(), maxVotes = 0;
        vector<int> votes(size + 1, 0);

        for (i = 0; i < size; ++i) {
            if (++votes[persons[i]] >= maxVotes) {
                maxVotes = votes[persons[i]];
                winners.insert({ times[i], persons[i] });
            }
        }
    }

    int q(int t) {
        auto iter = winners.upper_bound(t);
        return (--iter)->second;
    }

private:
    map<int, int> winners;
};

int main()
{
    CheckResult check;

    vector<int> persons = { 0,1,1,0,0,1,0 };
    vector<int> times = { 0,5,10,15,20,25,30 };
    TopVotedCandidate o1(persons, times);
    check.checkInt(0, o1.q(3));
    check.checkInt(1, o1.q(12));
    check.checkInt(1, o1.q(25));
    check.checkInt(0, o1.q(15));
    check.checkInt(0, o1.q(24));
    check.checkInt(1, o1.q(8));

    persons = { 1 };
    times = { 5 };
    TopVotedCandidate o2(persons, times);
    check.checkInt(1, o2.q(5));
    check.checkInt(1, o2.q(10));

    persons = { 0,0,1,1,2 };
    times = { 0,67,69,74,87 };
    TopVotedCandidate o3(persons, times);
    check.checkInt(0, o3.q(4));
    check.checkInt(0, o3.q(62));
    check.checkInt(1, o3.q(100));
    check.checkInt(1, o3.q(88));
    check.checkInt(0, o3.q(70));
    check.checkInt(0, o3.q(73));
    check.checkInt(0, o3.q(22));
    check.checkInt(1, o3.q(75));
    check.checkInt(0, o3.q(29));
    check.checkInt(0, o3.q(10));
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
