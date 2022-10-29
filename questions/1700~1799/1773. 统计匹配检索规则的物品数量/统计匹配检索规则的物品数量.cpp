/* 统计匹配检索规则的物品数量.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
给你一个数组 items ，其中 items[i] = [typei, colori, namei] ，描述第 i 件物品的类型、颜色以及名称。

另给你一条由两个字符串 ruleKey 和 ruleValue 表示的检索规则。

如果第 i 件物品能满足下述条件之一，则认为该物品与给定的检索规则 匹配 ：

ruleKey == "type" 且 ruleValue == typei 。
ruleKey == "color" 且 ruleValue == colori 。
ruleKey == "name" 且 ruleValue == namei 。
统计并返回 匹配检索规则的物品数量 。

 

示例 1：

输入：items = [["phone","blue","pixel"],["computer","silver","lenovo"],["phone","gold","iphone"]], ruleKey = "color", ruleValue = "silver"
输出：1
解释：只有一件物品匹配检索规则，这件物品是 ["computer","silver","lenovo"] 。
示例 2：

输入：items = [["phone","blue","pixel"],["computer","silver","phone"],["phone","gold","iphone"]], ruleKey = "type", ruleValue = "phone"
输出：2
解释：只有两件物品匹配检索规则，这两件物品分别是 ["phone","blue","pixel"] 和 ["phone","gold","iphone"] 。注意，["computer","silver","phone"] 未匹配检索规则。
 

提示：

1 <= items.length <= 104
1 <= typei.length, colori.length, namei.length, ruleValue.length <= 10
ruleKey 等于 "type"、"color" 或 "name"
所有字符串仅由小写字母组成

来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/count-items-matching-a-rule
著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。
*/

#include <iostream>
#include "../check/CheckResult.h"

using namespace std;

class Solution {
public:
    int countMatches(vector<vector<string>>& items, string ruleKey, string ruleValue) {
        int count = 0;

        for (auto& item : items) {
            if (ruleKey == "type") {
                if (item[0] == ruleValue) {
                    ++count;
                }
            }
            else if (ruleKey == "color") {
                if (item[1] == ruleValue) {
                    ++count;
                }
            }
            else {
                if (item[2] == ruleValue) {
                    ++count;
                }
            }
        }

        return count;
    }
};

int main()
{
    CheckResult check;
    Solution o;

    vector<vector<string>> items = { {"phone", "blue", "pixel"},{"computer", "silver", "lenovo"},{"phone", "gold", "iphone"} };
    check.checkInt(1, o.countMatches(items, "color", "silver"));

    items = { {"phone", "blue", "pixel"},{"computer", "silver", "phone"},{"phone", "gold", "iphone"} };
    check.checkInt(2, o.countMatches(items, "type", "phone"));
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
