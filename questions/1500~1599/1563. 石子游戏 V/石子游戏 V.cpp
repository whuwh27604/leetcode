﻿/* 石子游戏 V.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
几块石子 排成一行 ，每块石子都有一个关联值，关联值为整数，由数组 stoneValue 给出。

游戏中的每一轮：Alice 会将这行石子分成两个 非空行（即，左侧行和右侧行）；Bob 负责计算每一行的值，即此行中所有石子的值的总和。Bob 会丢弃值最大的行，Alice 的得分为剩下那行的值（每轮累加）。如果两行的值相等，Bob 让 Alice 决定丢弃哪一行。下一轮从剩下的那一行开始。

只 剩下一块石子 时，游戏结束。Alice 的分数最初为 0 。

返回 Alice 能够获得的最大分数 。

 

示例 1：

输入：stoneValue = [6,2,3,4,5,5]
输出：18
解释：在第一轮中，Alice 将行划分为 [6，2，3]，[4，5，5] 。左行的值是 11 ，右行的值是 14 。Bob 丢弃了右行，Alice 的分数现在是 11 。
在第二轮中，Alice 将行分成 [6]，[2，3] 。这一次 Bob 扔掉了左行，Alice 的分数变成了 16（11 + 5）。
最后一轮 Alice 只能将行分成 [2]，[3] 。Bob 扔掉右行，Alice 的分数现在是 18（16 + 2）。游戏结束，因为这行只剩下一块石头了。
示例 2：

输入：stoneValue = [7,7,7,7,7,7,7]
输出：28
示例 3：

输入：stoneValue = [4]
输出：0
 

提示：

1 <= stoneValue.length <= 500
1 <= stoneValue[i] <= 10^6

来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/stone-game-v
著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。
*/

#include <iostream>
#include <algorithm>
#include "../check/CheckResult.h"

using namespace std;

class Solution {
public:
    int stoneGameV(vector<int>& stoneValue) {
        int size = stoneValue.size();
        vector<int> memo(size * size, -1), presums(size + 1, 0);

        getPresums(stoneValue, size, presums);

        return getMaxValue(stoneValue, size, 0, size - 1, presums, memo);
    }

    void getPresums(vector<int>& stoneValue, int size, vector<int>& presums) {
        for (int i = 0; i < size; ++i) {
            presums[i + 1] = presums[i] + stoneValue[i];
        }
    }

    int getMaxValue(vector<int>& stoneValue, int size, int left, int right, vector<int>& presums, vector<int>& memo) {
        int& maxValue = memo[left * size + right];

        if (maxValue != -1) {
            return maxValue;
        }

        if (left == right) {
            return maxValue = 0;
        }

        for (int i = left; i < right; ++i) {
            int leftValue = presums[i + 1] - presums[left], rightValue = presums[right + 1] - presums[i + 1];

            if (leftValue < rightValue) {
                maxValue = max(maxValue, leftValue + getMaxValue(stoneValue, size, left, i, presums, memo));
            }
            else if (leftValue > rightValue) {
                maxValue = max(maxValue, rightValue + getMaxValue(stoneValue, size, i + 1, right, presums, memo));
            }
            else {
                maxValue = max(maxValue, leftValue + getMaxValue(stoneValue, size, left, i, presums, memo));
                maxValue = max(maxValue, rightValue + getMaxValue(stoneValue, size, i + 1, right, presums, memo));
            }
        }

        return maxValue;
    }
};

int main()
{
    CheckResult check;
    Solution o;

    vector<int> stoneValue = { 6,2,3,4,5,5 };
    check.checkInt(18, o.stoneGameV(stoneValue));

    stoneValue = { 7,7,7,7,7,7,7 };
    check.checkInt(28, o.stoneGameV(stoneValue));

    stoneValue = { 4 };
    check.checkInt(0, o.stoneGameV(stoneValue));

    stoneValue = { 98,77,24,49,6,12,2,44,51,96 };
    check.checkInt(330, o.stoneGameV(stoneValue));

    stoneValue = { 9,8,2,4,6,3,5,1,7 };
    check.checkInt(34, o.stoneGameV(stoneValue));

    stoneValue = { 68,75,25,50,34,29,77,1,2,69 };
    check.checkInt(304, o.stoneGameV(stoneValue));

    stoneValue = { 994672,993818,993084,989999,987842,987066,983037,975809,973734,968839,968633,966654,965755,960683,956663,953903,952771,950816,948975,944510,942862,940323,939518,935794,933692,924216,922805,922350,921131,920065,919728,913559,911599,910413,910185,910112,905335,904933,904734,903001,902468,899904,898774,897742,896030,887874,887161,885950,884661,884119,881495,880069,879368,878825,871818,868908,868463,866835,866504,866384,862794,862243,860903,858936,855527,854113,853798,852591,849927,847850,846285,841386,839806,836669,836535,835286,835265,832318,830479,827678,825693,825226,824728,821059,819811,805913,802305,799427,797771,796625,795380,794411,789342,784857,783641,779870,778530,775066,773622,770232,768961,755122,752801,752645,751010,745217,740097,737025,736226,726543,725930,722661,716656,714583,713502,712828,712076,710644,709990,708825,708581,705776,704206,703747,693253,692652,691059,691017,685908,680802,676015,672544,672508,669793,667212,666450,664336,663540,662475,660399,657971,654552,653698,650397,644254,643446,639307,638525,638167,637163,632999,631170,626794,625865,622939,620122,617924,617713,614530,609531,609327,609295,607958,607769,605428,604204,602414,601318,586577,586148,585454,580833,580181,578000,573597,569279,566771,563017,557557,556775,556488,551105,548265,541901,537405,534010,533832,533443,529974,513111,510312,509039,506185,505701,504531,499569,495054,493895,489609,484202,481648,478160,468951,467321,461618,460907,457249,451822,449903,449166,445179,441624,438218,433542,431077,428564,426074,422876,418750,409746,402450,402156,401094,398663,394306,390226,389229,380698,379623,379453,369357,369110,367331,363698,358890,354706,354325,352101,351098,349756,346941,336004,334574,321679,319038,315450,314656,313340,310847,309057,303702,297846,297786,296947,296072,295696,295530,293883,292003,290947,290260,285316,281556,280294,279416,278491,277525,277380,276924,275519,275028,274954,273936,273701,273504,271771,269450,260653,259873,257090,252451,251832,245265,244772,241868,239181,237735,237521,228774,227340,226892,225400,225244,224807,222690,216564,212154,210694,210468,209257,206828,204490,198329,193783,191441,188187,186402,183595,180164,174305,171488,167430,161201,155217,150142,149649,149083,148999,147372,144752,144160,135830,135690,128887,126075,123732,123676,122027,121617,119664,118981,115617,111810,110969,108620,108198,106318,102756,102128,96948,92090,92013,82512,81045,79276,73069,72703,70792,68797,61806,61108,59891,59133,48043,47858,45888,44634,41871,41352,40385,38847,38136,31959,26395,24900,24531,23616,21396,20285,19537,16402,12925,12390,9360,3201 };
    check.checkInt(190284037, o.stoneGameV(stoneValue));

    stoneValue = { 262655,846610,647629,410715,732868,821725,390146,431376,318458,134036,47871,913532,526765,643942,934143,474476,63691,519138,601227,347521,870801,76015,656153,823511,147815,834809,419011,699799,434561,407417,124375,672198,666120,312800,198094,730742,36404,685751,397067,30832,313218,545991,63231,45260,691908,215481,378358,677354,297261,302337,737794,215440,695419,460360,294680,740689,221767,993926,419574,475286,882248,57797,565712,81561,344660,396907,717233,570960,768962,452252,206485,737835,741841,90404,786924,925795,914873,2707,75737,725935,346335,931984,687149,211077,840018,590335,197324,246398,466992,608124,576151,478124,147479,400155,733600,775952,586326,65929,152140,77583,694870,270565,808485,606988,932784,458397,392300,594074,841799,142615,958712,460989,442764,381888,793978,694844,587396,826832,221735,889655,54652,288776,914737,514406,14013,461204,812942,268909,133542,786853,213052,836122,30561,886265,681800,489723,733578,537475,417297,784164,106032,167642,145385,527691,56337,823439,298749,7174,618325,292925,654577,908616,212954,955789,769433,102420,109491,983189,33968,23257,536313,253331,506768,763624,945830,585321,597110,996477,962530,54741,131800,836924,916397,852008,114553,765073,84371,643428,390143,182722,455647,193552,737405,284914,876339,651217,439736,22184,343147,923947,156850,545275,11657,603428,665809,434097,414829,854394,821335,111788,116007,632200,194612,26390,324860,730450,596221,723501,822825,904100,949744,257533,746008,536190,831491,396005,455010,306410,953329,843057,740523,911963,981590,82355,444066,275522,235229,503062,911011,365207,451173,36309,807281,425612,200670,796823,652332,744134,433544,685170,596421,649484,575571,351212,427230,911558,279711,414450,424233,247459,812586,807136,626417,516980,412817,677932,729396,557069,174675,668389,507998,104696,452747,549028,353746,218549,635165,860426,716849,444824,227966,769801,454501,525141,69308,337871,11583,802232,527875,808770,355612,284126,11247,691675,292702,854338,217446,348471,820370,634004,894744,695365,759532,716036,430552,670788,7042,410887,283643,897,360597,659084,322922,146280,415855,308402,979927,741660,447507,661595,201770,952581,846492,317179,528925,369059,495860,180450,371760,253428,793266,295549,164945,958242,870565,324096,246771,468198,765352,785307,13790,782737,780973,791506,951398,58443,466483,533427,387415,846608,858260,685041,508423,570304,78487,442386,69098,951139,906257,159256,989386,250799,501877,408601,950885,438629,123493,489265,178701,426786,74931,700105,305685,517424,91528,621269,397653,890144,166639,760746,831269,64219,628662,770451,598961,456082,121039,250606,923432,668336,391880,407545,524188,551444,151343,695827,71653,665510,23955,942912,500514,397699,247174,183088,203978,18643,812414,409069,72111,102059,69621,998317,452657,601605,337600,581915,931651,93047,573653,140301,228486,337560,299922,818089,787088,586302,388238,667210,610894,476787,65711,990357,610719,323118,116785,895235,148872,163536,848570,295687,944704,748260,632928,304276,159881,937704,43626,961411,937780,468133,355634,777584,166655,804200,227606,108596,719256,445688,884458,133714,499548,445423,890847,177588,599152 };
    check.checkInt(222655082, o.stoneGameV(stoneValue));

    stoneValue = { 1000000,1000000,1000000,1000000,1000000,1000000,1000000,1000000,1000000,1000000,1000000,1000000,1000000,1000000,1000000,1000000,1000000,1000000,1000000,1000000,1000000,1000000,1000000,1000000,1000000,1000000,1000000,1000000,1000000,1000000,1000000,1000000,1000000,1000000,1000000,1000000,1000000,1000000,1000000,1000000,1000000,1000000,1000000,1000000,1000000,1000000,1000000,1000000,1000000,1000000,1000000,1000000,1000000,1000000,1000000,1000000,1000000,1000000,1000000,1000000,1000000,1000000,1000000,1000000,1000000,1000000,1000000,1000000,1000000,1000000,1000000,1000000,1000000,1000000,1000000,1000000,1000000,1000000,1000000,1000000,1000000,1000000,1000000,1000000,1000000,1000000,1000000,1000000,1000000,1000000,1000000,1000000,1000000,1000000,1000000,1000000,1000000,1000000,1000000,1000000,1000000,1000000,1000000,1000000,1000000,1000000,1000000,1000000,1000000,1000000,1000000,1000000,1000000,1000000,1000000,1000000,1000000,1000000,1000000,1000000,1000000,1000000,1000000,1000000,1000000,1000000,1000000,1000000,1000000,1000000,1000000,1000000,1000000,1000000,1000000,1000000,1000000,1000000,1000000,1000000,1000000,1000000,1000000,1000000,1000000,1000000,1000000,1000000,1000000,1000000,1000000,1000000,1000000,1000000,1000000,1000000,1000000,1000000,1000000,1000000,1000000,1000000,1000000,1000000,1000000,1000000,1000000,1000000,1000000,1000000,1000000,1000000,1000000,1000000,1000000,1000000,1000000,1000000,1000000,1000000,1000000,1000000,1000000,1000000,1000000,1000000,1000000,1000000,1000000,1000000,1000000,1000000,1000000,1000000,1000000,1000000,1000000,1000000,1000000,1000000,1000000,1000000,1000000,1000000,1000000,1000000,1000000,1000000,1000000,1000000,1000000,1000000,1000000,1000000,1000000,1000000,1000000,1000000,1000000,1000000,1000000,1000000,1000000,1000000,1000000,1000000,1000000,1000000,1000000,1000000,1000000,1000000,1000000,1000000,1000000,1000000,1000000,1000000,1000000,1000000,1000000,1000000,1000000,1000000,1000000,1000000,1000000,1000000,1000000,1000000,1000000,1000000,1000000,1000000,1000000,1000000,1000000,1000000,1000000,1000000,1000000,1000000,1000000,1000000,1000000,1000000,1000000,1000000,1000000,1000000,1000000,1000000,1000000,1000000,1000000,1000000,1000000,1000000,1000000,1000000,1000000,1000000,1000000,1000000,1000000,1000000,1000000,1000000,1000000,1000000,1000000,1000000,1000000,1000000,1000000,1000000,1000000,1000000,1000000,1000000,1000000,1000000,1000000,1000000,1000000,1000000,1000000,1000000,1000000,1000000,1000000,1000000,1000000,1000000,1000000,1000000,1000000,1000000,1000000,1000000,1000000,1000000,1000000,1000000,1000000,1000000,1000000,1000000,1000000,1000000,1000000,1000000,1000000,1000000,1000000,1000000,1000000,1000000,1000000,1000000,1000000,1000000,1000000,1000000,1000000,1000000,1000000,1000000,1000000,1000000,1000000,1000000,1000000,1000000,1000000,1000000,1000000,1000000,1000000,1000000,1000000,1000000,1000000,1000000,1000000,1000000,1000000,1000000,1000000,1000000,1000000,1000000,1000000,1000000,1000000,1000000,1000000,1000000,1000000,1000000,1000000,1000000,1000000,1000000,1000000,1000000,1000000,1000000,1000000,1000000,1000000,1000000,1000000,1000000,1000000,1000000,1000000,1000000,1000000,1000000,1000000,1000000,1000000,1000000,1000000,1000000,1000000,1000000,1000000,1000000,1000000,1000000,1000000,1000000,1000000,1000000,1000000,1000000,1000000,1000000,1000000,1000000,1000000,1000000,1000000,1000000,1000000,1000000,1000000,1000000,1000000,1000000,1000000,1000000,1000000,1000000,1000000,1000000,1000000,1000000,1000000,1000000,1000000,1000000,1000000,1000000,1000000,1000000,1000000,1000000,1000000,1000000,1000000,1000000,1000000,1000000,1000000,1000000,1000000,1000000,1000000,1000000,1000000,1000000,1000000,1000000,1000000,1000000,1000000,1000000,1000000,1000000,1000000,1000000,1000000,1000000,1000000,1000000,1000000,1000000,1000000,1000000,1000000,1000000,1000000,1000000,1000000,1000000,1000000,1000000,1000000,1000000,1000000,1000000,1000000,1000000,1000000,1000000,1000000,1000000 };
    check.checkInt(494000000, o.stoneGameV(stoneValue));
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
