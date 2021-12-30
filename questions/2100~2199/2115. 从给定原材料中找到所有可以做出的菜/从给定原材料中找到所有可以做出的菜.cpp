/* 从给定原材料中找到所有可以做出的菜.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
你有 n 道不同菜的信息。给你一个字符串数组 recipes 和一个二维字符串数组 ingredients 。第 i 道菜的名字为 recipes[i] ，如果你有它 所有 的原材料 ingredients[i] ，那么你可以 做出 这道菜。一道菜的原材料可能是 另一道 菜，也就是说 ingredients[i] 可能包含 recipes 中另一个字符串。

同时给你一个字符串数组 supplies ，它包含你初始时拥有的所有原材料，每一种原材料你都有无限多。

请你返回你可以做出的所有菜。你可以以 任意顺序 返回它们。

注意两道菜在它们的原材料中可能互相包含。

 

示例 1：

输入：recipes = ["bread"], ingredients = [["yeast","flour"]], supplies = ["yeast","flour","corn"]
输出：["bread"]
解释：
我们可以做出 "bread" ，因为我们有原材料 "yeast" 和 "flour" 。
示例 2：

输入：recipes = ["bread","sandwich"], ingredients = [["yeast","flour"],["bread","meat"]], supplies = ["yeast","flour","meat"]
输出：["bread","sandwich"]
解释：
我们可以做出 "bread" ，因为我们有原材料 "yeast" 和 "flour" 。
我们可以做出 "sandwich" ，因为我们有原材料 "meat" 且可以做出原材料 "bread" 。
示例 3：

输入：recipes = ["bread","sandwich","burger"], ingredients = [["yeast","flour"],["bread","meat"],["sandwich","meat","bread"]], supplies = ["yeast","flour","meat"]
输出：["bread","sandwich","burger"]
解释：
我们可以做出 "bread" ，因为我们有原材料 "yeast" 和 "flour" 。
我们可以做出 "sandwich" ，因为我们有原材料 "meat" 且可以做出原材料 "bread" 。
我们可以做出 "burger" ，因为我们有原材料 "meat" 且可以做出原材料 "bread" 和 "sandwich" 。
示例 4：

输入：recipes = ["bread"], ingredients = [["yeast","flour"]], supplies = ["yeast"]
输出：[]
解释：
我们没法做出任何菜，因为我们只有原材料 "yeast" 。
 

提示：

n == recipes.length == ingredients.length
1 <= n <= 100
1 <= ingredients[i].length, supplies.length <= 100
1 <= recipes[i].length, ingredients[i][j].length, supplies[k].length <= 10
recipes[i], ingredients[i][j] 和 supplies[k] 只包含小写英文字母。
所有 recipes 和 supplies 中的值互不相同。
ingredients[i] 中的字符串互不相同。

来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/find-all-possible-recipes-from-given-supplies
著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。
*/

#include <iostream>
#include <unordered_map>
#include "../check/CheckResult.h"

using namespace std;

class Solution {
public:
    vector<string> findAllRecipes(vector<string>& recipes, vector<vector<string>>& ingredients, vector<string>& supplies) {
        int i, n = recipes.size();
        unordered_map<string, pair<int, int>> recipeIngredients;  // recipe需要几个ingredients， 当前已经有几个
        unordered_map<string, vector<string>> ingredientRecipes;  // 每个ingredient，哪些recipe需要它
        vector<string> ans;

        for (i = 0; i < n; ++i) {
            recipeIngredients[recipes[i]] = { ingredients[i].size(), 0 };
        }

        for (i = 0; i < n; ++i) {
            for (string& ingredient : ingredients[i]) {
                ingredientRecipes[ingredient].push_back(recipes[i]);
            }
        }

        for (i = 0; i < (int)supplies.size(); ++i) {
            if (ingredientRecipes.count(supplies[i]) != 0) {
                for (string& recipe : ingredientRecipes[supplies[i]]) {
                    if (++recipeIngredients[recipe].second == recipeIngredients[recipe].first) {
                        ans.push_back(recipe);
                        supplies.push_back(recipe);
                    }
                }
            }
        }

        return ans;
    }
};

int main()
{
    CheckResult check;
    Solution o;

    vector<string> recipes = { "bread" };
    vector<vector<string>> ingredients = { {"yeast","flour"} };
    vector<string> supplies = { "yeast","flour","corn" };
    vector<string> actual = o.findAllRecipes(recipes, ingredients, supplies);
    vector<string> expected = { "bread" };
    check.checkStringVector(expected, actual);

    recipes = { "bread","sandwich" };
    ingredients = { {"yeast","flour"},{"bread","meat"} };
    supplies = { "yeast","flour","meat" };
    actual = o.findAllRecipes(recipes, ingredients, supplies);
    expected = { "bread","sandwich" };
    check.checkStringVector(expected, actual);

    recipes = { "bread","sandwich","burger" };
    ingredients = { {"yeast","flour"},{"bread","meat"},{"sandwich","meat","bread"} };
    supplies = { "yeast","flour","meat" };
    actual = o.findAllRecipes(recipes, ingredients, supplies);
    expected = { "bread","sandwich","burger" };
    check.checkStringVector(expected, actual);

    recipes = { "bread" };
    ingredients = { {"yeast","flour"} };
    supplies = { "yeast" };
    actual = o.findAllRecipes(recipes, ingredients, supplies);
    expected = {};
    check.checkStringVector(expected, actual);

    recipes = { "a","b" };
    ingredients = { {"b"},{"a"} };
    supplies = { "c" };
    actual = o.findAllRecipes(recipes, ingredients, supplies);
    expected = {};
    check.checkStringVector(expected, actual);
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
