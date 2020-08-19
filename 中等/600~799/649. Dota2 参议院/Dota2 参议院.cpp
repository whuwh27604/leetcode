/* Dota2 参议院.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
Dota2 的世界里有两个阵营：Radiant(天辉)和 Dire(夜魇)

Dota2 参议院由来自两派的参议员组成。现在参议院希望对一个 Dota2 游戏里的改变作出决定。他们以一个基于轮为过程的投票进行。在每一轮中，每一位参议员都可以行使两项权利中的一项：

禁止一名参议员的权利：

参议员可以让另一位参议员在这一轮和随后的几轮中丧失所有的权利。

宣布胜利：

          如果参议员发现有权利投票的参议员都是同一个阵营的，他可以宣布胜利并决定在游戏中的有关变化。

 

给定一个字符串代表每个参议员的阵营。字母 “R” 和 “D” 分别代表了 Radiant（天辉）和 Dire（夜魇）。然后，如果有 n 个参议员，给定字符串的大小将是 n。

以轮为基础的过程从给定顺序的第一个参议员开始到最后一个参议员结束。这一过程将持续到投票结束。所有失去权利的参议员将在过程中被跳过。

假设每一位参议员都足够聪明，会为自己的政党做出最好的策略，你需要预测哪一方最终会宣布胜利并在 Dota2 游戏中决定改变。输出应该是 Radiant 或 Dire。

 

示例 1:

输入: "RD"
输出: "Radiant"
解释:  第一个参议员来自  Radiant 阵营并且他可以使用第一项权利让第二个参议员失去权力，因此第二个参议员将被跳过因为他没有任何权利。然后在第二轮的时候，第一个参议员可以宣布胜利，因为他是唯一一个有投票权的人
示例 2:

输入: "RDD"
输出: "Dire"
解释:
第一轮中,第一个来自 Radiant 阵营的参议员可以使用第一项权利禁止第二个参议员的权利
第二个来自 Dire 阵营的参议员会被跳过因为他的权利被禁止
第三个来自 Dire 阵营的参议员可以使用他的第一项权利禁止第一个参议员的权利
因此在第二轮只剩下第三个参议员拥有投票的权利,于是他可以宣布胜利
 

注意:

给定字符串的长度在 [1, 10,000] 之间.

来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/dota2-senate
著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。
*/

#include <iostream>
#include <queue>
#include "../check/CheckResult.h"

using namespace std;

class Solution {
public:
    string predictPartyVictory(string senate) {
        // 贪心算法，每次禁掉自己后面对方阵营的人
        queue<char> senators;
        int countR = 0, countD = 0, banR = 0, banD = 0;

        for (char c : senate) {
            if (c == 'R') {
                countR++;
            }
            else {
                countD++;
            }
            senators.push(c);
        }

        while ((countR > 0) && (countD > 0)) {
            char c = senators.front();
            senators.pop();

            if (c == 'R') {
                if (banR > 0) {
                    banR--;  // 兑现对方的禁言
                    countR--;  // 自己消失了
                }
                else {
                    banD++;  // 不用马上去找下一个对方，先记账，等他出现时再兑现。
                    senators.push(c);  // 自己行使了权力，跑到队列尾去
                }
            }
            else {
                if (banD > 0) {
                    banD--;
                    countD--;
                }
                else {
                    banR++;
                    senators.push(c);
                }
            }
        }

        return countR == 0 ? "Dire" : "Radiant";
    }
};

int main()
{
    Solution o;
    CheckResult check;

    check.checkString("Radiant", o.predictPartyVictory("R"));
    check.checkString("Dire", o.predictPartyVictory("D"));
    check.checkString("Radiant", o.predictPartyVictory("RD"));
    check.checkString("Dire", o.predictPartyVictory("DR"));
    check.checkString("Dire", o.predictPartyVictory("RDD"));
    check.checkString("Dire", o.predictPartyVictory("DDRRR"));
    check.checkString("Radiant", o.predictPartyVictory("DRRDRDRDRDDRDRDR"));
    check.checkString("Radiant", o.predictPartyVictory("DRRDRDRDDDRDDRRRRRDR"));
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
