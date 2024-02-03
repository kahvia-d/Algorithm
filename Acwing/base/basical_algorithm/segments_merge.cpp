//
// Created by Kahiva on 2024/2/3.
//
#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

const int N = 100010;
vector<pair<int, int>> segs;

/*维护一个区间，扫描其后的区间，查看是否能合并。
 *若是能合并，则更新维护区间的右边界。
 *若是不能合并，则将现有的维护区间放至结果中，将下一个区间作为新的维护区间。
 */
void merge(){
    vector<pair<int, int>> res;

    //将各个区间从小到大排列
    sort(segs.begin(), segs.end());

    //初始化维护区间
    int l = -2e9, r = -2e9;

    for(auto seg : segs){
        //如果扫描到的区间与当前区间无交集
        if(seg.first > r){
            //如果当前维护的区间不是初始区间，就保存至结果中
            if(r != -2e9) res.push_back({l, r});
            //原区间维护完毕，更新维护区间
            l = seg.first;
            r = seg.second;
        }else{
            //维护区间右边界
            r = max(r, seg.second);
        }
    }

    //将最后一个维护的区间加入到结果之中
    if(l != -2e9) res.push_back({l, r});

    segs = res;
}

int main(){
    int n;
    scanf("%d", &n);

    for(int i = 0; i < n; i++){
        int l, r;
        scanf("%d%d", &l, &r);
        segs.push_back({l ,r});
    }

    merge();

    cout << segs.size();


    return 0;
}