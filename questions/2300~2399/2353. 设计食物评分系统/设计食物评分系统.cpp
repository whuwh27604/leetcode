/* 设计食物评分系统.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
设计一个支持下述操作的食物评分系统：

修改 系统中列出的某种食物的评分。
返回系统中某一类烹饪方式下评分最高的食物。
实现 FoodRatings 类：

FoodRatings(String[] foods, String[] cuisines, int[] ratings) 初始化系统。食物由 foods、cuisines 和 ratings 描述，长度均为 n 。
foods[i] 是第 i 种食物的名字。
cuisines[i] 是第 i 种食物的烹饪方式。
ratings[i] 是第 i 种食物的最初评分。
void changeRating(String food, int newRating) 修改名字为 food 的食物的评分。
String highestRated(String cuisine) 返回指定烹饪方式 cuisine 下评分最高的食物的名字。如果存在并列，返回 字典序较小 的名字。
注意，字符串 x 的字典序比字符串 y 更小的前提是：x 在字典中出现的位置在 y 之前，也就是说，要么 x 是 y 的前缀，或者在满足 x[i] != y[i] 的第一个位置 i 处，x[i] 在字母表中出现的位置在 y[i] 之前。

 

示例：

输入
["FoodRatings", "highestRated", "highestRated", "changeRating", "highestRated", "changeRating", "highestRated"]
[[["kimchi", "miso", "sushi", "moussaka", "ramen", "bulgogi"], ["korean", "japanese", "japanese", "greek", "japanese", "korean"], [9, 12, 8, 15, 14, 7]], ["korean"], ["japanese"], ["sushi", 16], ["japanese"], ["ramen", 16], ["japanese"]]
输出
[null, "kimchi", "ramen", null, "sushi", null, "ramen"]

解释
FoodRatings foodRatings = new FoodRatings(["kimchi", "miso", "sushi", "moussaka", "ramen", "bulgogi"], ["korean", "japanese", "japanese", "greek", "japanese", "korean"], [9, 12, 8, 15, 14, 7]);
foodRatings.highestRated("korean"); // 返回 "kimchi"
                                    // "kimchi" 是分数最高的韩式料理，评分为 9 。
foodRatings.highestRated("japanese"); // 返回 "ramen"
                                      // "ramen" 是分数最高的日式料理，评分为 14 。
foodRatings.changeRating("sushi", 16); // "sushi" 现在评分变更为 16 。
foodRatings.highestRated("japanese"); // 返回 "sushi"
                                      // "sushi" 是分数最高的日式料理，评分为 16 。
foodRatings.changeRating("ramen", 16); // "ramen" 现在评分变更为 16 。
foodRatings.highestRated("japanese"); // 返回 "ramen"
                                      // "sushi" 和 "ramen" 的评分都是 16 。
                                      // 但是，"ramen" 的字典序比 "sushi" 更小。
 

提示：

1 <= n <= 2 * 104
n == foods.length == cuisines.length == ratings.length
1 <= foods[i].length, cuisines[i].length <= 10
foods[i]、cuisines[i] 由小写英文字母组成
1 <= ratings[i] <= 108
foods 中的所有字符串 互不相同
在对 changeRating 的所有调用中，food 是系统中食物的名字。
在对 highestRated 的所有调用中，cuisine 是系统中 至少一种 食物的烹饪方式。
最多调用 changeRating 和 highestRated 总计 2 * 104 次

来源：力扣（LeetCode）
链接：https://leetcode.cn/problems/design-a-food-rating-system
著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。
*/

#include <iostream>
#include <unordered_map>
#include <set>
#include "../check/CheckResult.h"

using namespace std;

class RatingFood {
public:
    int rating;
    string food;

    RatingFood(int r, string& f) : rating(r), food(f) {}

    bool operator<(const RatingFood& o) const {
        return rating == o.rating ? food < o.food : rating > o.rating;
    }
};

class FoodRatings {
public:
    FoodRatings(vector<string>& foods, vector<string>& cuisines, vector<int>& ratings) {
        for (int i = 0; i < (int)foods.size(); ++i) {
            foodCuisineRatings[foods[i]] = { cuisines[i], ratings[i] };
            cuisineRatingFoods[cuisines[i]].insert(RatingFood(ratings[i], foods[i]));
        }
    }

    void changeRating(string food, int newRating) {
        string cuisine = foodCuisineRatings[food].first;
        int rating = foodCuisineRatings[food].second;
        cuisineRatingFoods[cuisine].erase(RatingFood(rating, food));
        cuisineRatingFoods[cuisine].insert(RatingFood(newRating, food));
        foodCuisineRatings[food] = { cuisine, newRating };
    }

    string highestRated(string cuisine) {
        return cuisineRatingFoods[cuisine].begin()->food;
    }

private:
    unordered_map<string, pair<string, int>> foodCuisineRatings;
    unordered_map<string, set<RatingFood>> cuisineRatingFoods;
};

int main()
{
    CheckResult check;

    vector<string> foods = { "kimchi", "miso", "sushi", "moussaka", "ramen", "bulgogi" };
    vector<string> cuisines = { "korean", "japanese", "japanese", "greek", "japanese", "korean" };
    vector<int> ratings = { 9,12,8,15,14,7 };
    FoodRatings o1(foods, cuisines, ratings);
    check.checkString("kimchi", o1.highestRated("korean"));
    check.checkString("ramen", o1.highestRated("japanese"));
    o1.changeRating("sushi", 16);
    check.checkString("sushi", o1.highestRated("japanese"));
    o1.changeRating("ramen", 16);
    check.checkString("ramen", o1.highestRated("japanese"));

    foods = { "cpctxzh","bryvgjqmj","wedqhqrmyc","ee","lafzximxh","lojzxfel","flhs" };
    cuisines = { "wbhdgqphq","wbhdgqphq","mxxajogm","wbhdgqphq","wbhdgqphq","mxxajogm","mxxajogm" };
    ratings = { 15,5,7,16,16,10,13 };
    FoodRatings o2(foods, cuisines, ratings);
    o2.changeRating("lojzxfel", 1);
    check.checkString("flhs", o2.highestRated("mxxajogm"));
    check.checkString("ee", o2.highestRated("wbhdgqphq"));
    check.checkString("flhs", o2.highestRated("mxxajogm"));
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
