/* 探险营地.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
探险家小扣的行动轨迹，都将保存在记录仪中。expeditions[i] 表示小扣第 i 次探险记录，用一个字符串数组表示。其中的每个「营地」由大小写字母组成，通过子串 -> 连接。

例："Leet->code->Campsite"，表示到访了 "Leet"、"code"、"Campsite" 三个营地。

expeditions[0] 包含了初始小扣已知的所有营地；对于之后的第 i 次探险(即 expeditions[i] 且 i > 0)，如果记录中包含了之前均没出现的营地，则表示小扣 新发现 的营地。

请你找出小扣发现新营地最多且索引最小的那次探险，并返回对应的记录索引。如果所有探险记录都没有发现新的营地，返回 -1

注意：

大小写不同的营地视为不同的营地；
营地的名称长度均大于 0。
示例 1：

输入：expeditions = ["leet->code","leet->code->Campsite->Leet","leet->code->leet->courier"]

输出：1

解释： 初始已知的所有营地为 "leet" 和 "code" 第 1 次，到访了 "leet"、"code"、"Campsite"、"Leet"，新发现营地 2 处："Campsite"、"Leet" 第 2 次，到访了 "leet"、"code"、"courier"，新发现营地 1 处："courier" 第 1 次探险发现的新营地数量最多，因此返回 1

示例 2：

输入：expeditions = ["Alice->Dex","","Dex"]

输出：-1

解释： 初始已知的所有营地为 "Alice" 和 "Dex" 第 1 次，未到访任何营地； 第 2 次，到访了 "Dex"，未新发现营地； 因为两次探险均未发现新的营地，返回 -1

示例 3：

输入：expeditions = ["","Gryffindor->Slytherin->Gryffindor","Hogwarts->Hufflepuff->Ravenclaw"]

输出：2

解释： 初始未发现任何营地； 第 1 次，到访 "Gryffindor"、"Slytherin" 营地，其中重复到访 "Gryffindor" 两次， 因此新发现营地为 2 处："Gryffindor"、"Slytherin" 第 2 次，到访 "Hogwarts"、"Hufflepuff"、"Ravenclaw" 营地； 新发现营地 3 处："Hogwarts"、"Hufflepuff"、"Ravenclaw"； 第 2 次探险发现的新营地数量最多，因此返回 2

提示：

1 <= expeditions.length <= 1000
0 <= expeditions[i].length <= 1000
探险记录中只包含大小写字母和子串"->"
*/

#include <iostream>
#include <unordered_set>
#include "../check/CheckResult.h"

using namespace std;

class Solution {
public:
    int adventureCamp(vector<string>& expeditions) {
        int index = -1, size = (int)expeditions.size(), maxUnvisited = 0;
        unordered_set<string> allCamps;
        (void)getUnvisited(expeditions[0], allCamps);

        for (int i = 1; i < size; ++i) {
            int unvisited = getUnvisited(expeditions[i], allCamps);
            if (unvisited > maxUnvisited) {
                maxUnvisited = unvisited;
                index = i;
            }
        }

        return index;
    }

    int getUnvisited(string& expedition, unordered_set<string>& allCamps) {
        int unvisited = 0;
        char* p = const_cast<char*>(expedition.c_str());
        const char* delimit = "->";
        char* context = NULL;
        p = strtok_s(p, delimit, &context);

        while (p != NULL) {
            string camp(p);
            p = strtok_s(NULL, delimit, &context);

            if (allCamps.count(camp) == 0) {
                allCamps.insert(camp);
                ++unvisited;
            }
        }

        return unvisited;
    }
};

int main()
{
    Solution o;
    CheckResult check;

    vector<string> expeditions = { "leet->code","leet->code->Campsite->Leet","leet->code->leet->courier" };
    check.checkInt(1, o.adventureCamp(expeditions));

    expeditions = { "Alice->Dex","","Dex" };
    check.checkInt(-1, o.adventureCamp(expeditions));

    expeditions = { "","Gryffindor->Slytherin->Gryffindor","Hogwarts->Hufflepuff->Ravenclaw" };
    check.checkInt(2, o.adventureCamp(expeditions));
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
