/* 慧眼神瞳.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
【背景】
"慧眼神瞳"平台可以通过分析摄像头监控画面，进行自动化的识别场地形象是否符合标准、工具是否定置定位、火灾预警、防盗预警、异常人员入侵预警等情况。
出于运维考虑，要求场地对摄像头进行分组管理，每组有专门的负责人负责管理。

【问题】
假设平台部署摄像头的距离集合distance，为场地安排n个负责人，其中:
distance[i][j]表示摄像头i和摄像头j之间的距离，如果distance[i][j]<=2米说明它们属于同一组。

请你设计一个算法判断该场地是否可以保证每组摄像头至少有一个负责人管理。
输入: 摄像头部署之间距离集合m*m的二维数组distance[m][m]，人员数量n
输出：是否满足要求的结果:true/false

示例1：
假设存在三个摄像头1,2,3
image.png

输入：distance=[[0,1,3], [1,0,3], [3,3,0]], n = 2
输出：true
解释：
distance：摄像头部署之间距离集合，摄像头id=索引i+1；
distance=[
 [0,1,3], => 摄像头id1(i=0)分别到摄像头id1、2、3（j=0,1,2）的距离：id1->id1: 0米；id1->id2: 1米；id1->id3: 3米
 [1,0,3], => 摄像头id2(i=1)分别到摄像头id1、2、3（j=0,1,2）的距离：id2->id1: 1米；id2->id2: 0米；id2->id3: 3米
 [3,3,0]] => 摄像头id3(i=2)分别到摄像头id1、2、3（j=0,1,2）的距离：id3->id1: 3米；id3->id2: 1米；id3->id3: 3米
n：负责人个数
摄像头1与2的距离为1，摄像头1与3的距离为3，摄像头2与3的距离为3，所以摄像头1和2为一组，摄像头3自己一组，一共有2组摄像头，2<=n，所以能够满足每组至少有一个负责人管理。
示例2：
假设存在三个摄像头1,2,3
image.png

输入：distance=[[0,3,3],[3,0,3],[3,3,0]], n = 2
输出：false
解释：3个摄像头两两相聚3米，大于2米要求，故各为1组，一共3组；但是只有2个负责人，不能满足每组至少有1个负责人管理，所以输出为false
提示：

1 <= m <= 100
0 <= distance[i][j] < 100
0 < n < 100
*/

#include <iostream>
#include "../check/CheckResult.h"

using namespace std;

class DSU {
public:
    DSU(int size) {
        parents.resize(size);
        sizes.resize(size, 1);
        sets = size;

        for (int i = 0; i < size; ++i) {
            parents[i] = i;
        }
    }

    int find(int x) {
        if (parents[x] != x) {
            parents[x] = find(parents[x]);  // 路径压缩，父节点设置为根节点
        }

        return parents[x];
    }

    void merge(int x, int y) {
        int parentX = find(x), parentY = find(y);

        if (parentX != parentY) {
            if (sizes[parentX] < sizes[parentY]) {
                swap(parentX, parentY);
            }

            parents[parentY] = parentX;  // 把小的集合合并到大的
            sizes[parentX] += sizes[parentY];
            --sets;
        }
    }

    int getSets() {
        return sets;
    }

private:
    vector<int> parents;
    vector<int> sizes;
    int sets;
};

class Solution {
public:
    bool isCompliance(vector<vector<int>>& distance, int n) {
        int i, j, m = distance.size();
        DSU dsu(m);

        for (i = 0; i < m; ++i) {
            for (j = 0; j < m; ++j) {
                if (i != j && distance[i][j] <= 2) {
                    dsu.merge(i, j);
                }
            }
        }

        return dsu.getSets() <= n;
    }
};

int main()
{
    CheckResult check;
    Solution o;

    vector<vector<int>> distance = { {0,1,3},{1,0,3},{3,3,0} };
    check.checkBool(true, o.isCompliance(distance, 2));

    distance = { {0,3,3},{3,0,3},{3,3,0} };
    check.checkBool(false, o.isCompliance(distance, 2));
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
