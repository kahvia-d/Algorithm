//
// Created by Kahiva on 2024/1/30.
//
#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

const int N = 300010; //离散化后，使用的坐标个数最多为30w。含数据的10w，查询的区间左右坐标各10w。
vector<int> alls; //存储使用的所有坐标，即原坐标
vector<pair<int, int>> add, query; //两个pair数组存储操作

int a[N], s[N];

//利用二分根据原坐标查找离散坐标
int find(int x){
    int l = 0, r = alls.size() - 1;
    while(l < r){
        int mid = l + r >> 1;
        if(alls[mid] >= x) r = mid;
        else l = mid + 1;
    }

    //因为涉及到求前缀和等操作，所以下标从1开始更好。
    return l + 1;
}

int main(){
    int n, m;
    scanf("%d%d", &n, &m);

    for(int i = 0; i < n; i++){
        int x, c;
        scanf("%d%d", &x, &c);
        alls.push_back(x); //记录使用到的原坐标
        add.push_back({x, c}); //记录添加的操作
    }

    for(int i = 0; i < m; i++){
        int l, r;
        scanf("%d%d", &l, &r);
        alls.push_back(l); //记录原坐标
        alls.push_back(r);
        query.push_back({l, r}); //记录查询的操作
    }

    sort(alls.begin(), alls.end()); //将使用到的原坐标排序
    //去重。unique会将重复的放在数组的最后面去，并返回重复部分的起始位置。erase用于删除这重复的一部分。
    alls.erase(unique(alls.begin(), alls.end()), alls.end());

    //操作离散数组
    for(auto item : add){
        int index = find(item.first);
        a[index] += item.second;
    }

    //计算前缀和
    for(int i = 1; i <= alls.size(); i++)
        s[i] = s[i - 1] + a[i];

    //查询离散数组
    for(auto item : query){
        int l = find(item.first), r = find(item.second);
        printf("%d\n", s[r] - s[l - 1]);
    }

    return 0;
}