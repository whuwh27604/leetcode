/* 转变日期格式.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
给你一个字符串 date ，它的格式为 Day Month Year ，其中：

Day 是集合 {"1st", "2nd", "3rd", "4th", ..., "30th", "31st"} 中的一个元素。
Month 是集合 {"Jan", "Feb", "Mar", "Apr", "May", "Jun", "Jul", "Aug", "Sep", "Oct", "Nov", "Dec"} 中的一个元素。
Year 的范围在 ​[1900, 2100] 之间。
请你将字符串转变为 YYYY-MM-DD 的格式，其中：

YYYY 表示 4 位的年份。
MM 表示 2 位的月份。
DD 表示 2 位的天数。
 

示例 1：

输入：date = "20th Oct 2052"
输出："2052-10-20"
示例 2：

输入：date = "6th Jun 1933"
输出："1933-06-06"
示例 3：

输入：date = "26th May 1960"
输出："1960-05-26"
 

提示：

给定日期保证是合法的，所以不需要处理异常输入。

来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/reformat-date
著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。
*/

#include <iostream>
#include <unordered_map>
#include "../check/CheckResult.h"

using namespace std;

class Solution {
public:
    string reformatDate(string date) {
        unordered_map<string, string> transMonth = { {"Jan","01"},{"Feb","02"},{"Mar","03"},{"Apr","04"},{"May","05"},{"Jun","06"},
            {"Jul","07"},{"Aug","08"},{"Sep","09"},{"Oct","10"},{"Nov","11"},{"Dec","12"} };
        unordered_map<string, string> transDay = { {"1st","01"},{"2nd","02"},{"3rd","03"},{"4th","04"},{"5th","05"},{"6th","06"},
            {"7th","07"},{"8th","08"},{"9th","09"},{"10th","10"},{"11th","11"},{"12th","12"},{"13th","13"},{"14th","14"},{"15th","15"},
            {"16th","16"},{"17th","17"},{"18th","18"},{"19th","19"},{"20th","20"},{"21st","21"},{"22nd","22"},{"23rd","23"},{"24th","24"},
            {"25th","25"},{"26th","26"},{"27th","27"},{"28th","28"},{"29th","29"},{"30th","30"},{"31st","31"} };

        int position = date.find(' ');
        string day(date, 0, position);
        int start = position + 1;
        position = date.find(' ', start);
        string month(date, start, position - start);
        start = position + 1;
        string year(date, start, date.size() - start);

        return year + "-" + transMonth[month] + "-" + transDay[day];
    }
};

int main()
{
    Solution o;
    CheckResult check;

    check.checkString("2052-10-20", o.reformatDate("20th Oct 2052"));
    check.checkString("1933-06-06", o.reformatDate("6th Jun 1933"));
    check.checkString("1960-05-26", o.reformatDate("26th May 1960"));
    check.checkString("1960-01-01", o.reformatDate("1st Jan 1960"));
    check.checkString("1960-02-02", o.reformatDate("2nd Feb 1960"));
    check.checkString("1960-03-03", o.reformatDate("3rd Mar 1960"));
    check.checkString("1960-04-04", o.reformatDate("4th Apr 1960"));
    check.checkString("1960-07-05", o.reformatDate("5th Jul 1960"));
    check.checkString("1960-08-06", o.reformatDate("6th Aug 1960"));
    check.checkString("1960-09-07", o.reformatDate("7th Sep 1960"));
    check.checkString("1960-11-08", o.reformatDate("8th Nov 1960"));
    check.checkString("1960-12-09", o.reformatDate("9th Dec 1960"));
    check.checkString("1960-12-10", o.reformatDate("10th Dec 1960"));
    check.checkString("1960-12-11", o.reformatDate("11th Dec 1960"));
    check.checkString("1960-12-12", o.reformatDate("12th Dec 1960"));
    check.checkString("1960-12-13", o.reformatDate("13th Dec 1960"));
    check.checkString("1960-12-14", o.reformatDate("14th Dec 1960"));
    check.checkString("1960-12-15", o.reformatDate("15th Dec 1960"));
    check.checkString("1960-12-16", o.reformatDate("16th Dec 1960"));
    check.checkString("1960-12-17", o.reformatDate("17th Dec 1960"));
    check.checkString("1960-12-18", o.reformatDate("18th Dec 1960"));
    check.checkString("1960-12-19", o.reformatDate("19th Dec 1960"));
    check.checkString("1960-12-20", o.reformatDate("20th Dec 1960"));
    check.checkString("1960-12-21", o.reformatDate("21st Dec 1960"));
    check.checkString("1960-12-22", o.reformatDate("22nd Dec 1960"));
    check.checkString("1960-12-23", o.reformatDate("23rd Dec 1960"));
    check.checkString("1960-12-24", o.reformatDate("24th Dec 1960"));
    check.checkString("1960-12-25", o.reformatDate("25th Dec 1960"));
    check.checkString("1960-12-26", o.reformatDate("26th Dec 1960"));
    check.checkString("1960-12-27", o.reformatDate("27th Dec 1960"));
    check.checkString("1960-12-28", o.reformatDate("28th Dec 1960"));
    check.checkString("1960-12-29", o.reformatDate("29th Dec 1960"));
    check.checkString("1960-12-30", o.reformatDate("30th Dec 1960"));
    check.checkString("1960-12-31", o.reformatDate("31st Dec 1960"));
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
