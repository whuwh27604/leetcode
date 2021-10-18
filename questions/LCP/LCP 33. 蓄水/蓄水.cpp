/* 蓄水.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
给定 N 个无限容量且初始均空的水缸，每个水缸配有一个水桶用来打水，第 i 个水缸配备的水桶容量记作 bucket[i]。小扣有以下两种操作：

升级水桶：选择任意一个水桶，使其容量增加为 bucket[i]+1
蓄水：将全部水桶接满水，倒入各自对应的水缸
每个水缸对应最低蓄水量记作 vat[i]，返回小扣至少需要多少次操作可以完成所有水缸蓄水要求。

注意：实际蓄水量 达到或超过 最低蓄水量，即完成蓄水要求。

示例 1：

输入：bucket = [1,3], vat = [6,8]

输出：4

解释：
第 1 次操作升级 bucket[0]；
第 2 ~ 4 次操作均选择蓄水，即可完成蓄水要求。


示例 2：

输入：bucket = [9,0,1], vat = [0,2,2]

输出：3

解释：
第 1 次操作均选择升级 bucket[1]
第 2~3 次操作选择蓄水，即可完成蓄水要求。

提示：

1 <= bucket.length == vat.length <= 100
0 <= bucket[i], vat[i] <= 10^4

来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/o8SXZn
著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。
*/

#include <iostream>
#include <algorithm>
#include "../check/CheckResult.h"

using namespace std;

class Solution {
public:
    int storeWater(vector<int>& bucket, vector<int>& vat) {
        int minOpers = INT_MAX, maxVat = *max_element(vat.begin(), vat.end());

        if (maxVat == 0) {
            return 0;
        }

        for (int stores = 1; stores <= maxVat; ++stores) {
            minOpers = min(minOpers, getOpers(bucket, vat, stores));
        }

        return minOpers;
    }

    int getOpers(vector<int>& bucket, vector<int>& vat, int stores) {
        int i, size = bucket.size(), opers = 0;

        for (i = 0; i < size; ++i) {
            int buck = vat[i] / stores + (vat[i] % stores == 0 ? 0 : 1);
            opers += (buck > bucket[i] ? buck - bucket[i] : 0);
        }

        return opers + stores;
    }
};

int main()
{
    CheckResult check;
    Solution o;

    vector<int> bucket = { 1,3 };
    vector<int> vat = { 6,8 };
    check.checkInt(4, o.storeWater(bucket, vat));

    bucket = { 9,0,1 };
    vat = { 0,2,2 };
    check.checkInt(3, o.storeWater(bucket, vat));

    bucket = { 0,0,0 };
    vat = { 0,0,0 };
    check.checkInt(0, o.storeWater(bucket, vat));

    bucket = { 0,0,0 };
    vat = { 1,2,3 };
    check.checkInt(6, o.storeWater(bucket, vat));

    bucket = {21, 56 };
    vat = { 3230, 8299 };
    check.checkInt(138, o.storeWater(bucket, vat));

    bucket = { 9811, 9336, 21, 9309, 8999, 56 };
    vat = { 9982, 9532, 3230, 9951, 9034, 8299 };
    check.checkInt(138, o.storeWater(bucket, vat));

    bucket = { 9988,5017,5130,2445,9896,9151,3625,7801,608,3283,1386,979,5209,4182,8234,9870,8714,6435,3800,956,4006,5620,7474,1205,6993,3320,1201,7593,905,3816,4522,4560,8027,8219,6686,3779,2141,1240,6504,6612,6921,7329,8145,5745,7652,4340,7933,6246,5157,9447,107,9665,3653,2978,9832,4945,4312,2199,449,8432,3230,8163,800,6547,1110,1194,9384,632,3275,1229,7230,8643,7613,8256,5043,1288,3088,8997,4554,4755,7433,8146,9722,3469,8863,5831,7816,5058,4316,7946,8402,975,2450,4958,9811,9336,21,9309,8999,56 };
    vat = { 9991,6973,7192,9876,9910,9549,3700,8814,1308,9981,9234,7292,7732,8458,8441,9939,9621,7285,7452,2718,6589,7555,8788,3202,7832,4781,8798,9299,2112,9963,8755,7240,9217,8587,6782,9703,8954,3759,6907,7218,7333,8020,8323,5750,9510,8571,8664,8510,9363,9741,8643,9825,4227,8530,9961,8511,8949,7486,9086,9690,5316,9581,9314,8817,7234,8998,9485,5394,7365,1501,7984,9802,9778,8314,7482,7117,5117,9609,8732,9728,9330,8800,9775,6210,8966,7700,8802,7607,8950,9730,9855,1231,5228,5329,9982,9532,3230,9951,9034,8299 };
    check.checkInt(138, o.storeWater(bucket, vat));
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
