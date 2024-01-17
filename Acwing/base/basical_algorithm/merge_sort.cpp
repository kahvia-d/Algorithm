//
// Created by Kahiva on 2024/1/16.
//
#include <iostream>

using namespace std;

const int N = 100010;
int t[N], tmp[N];

void merge_sort(int l, int r){
    if(l >= r) return;
    //右移等同除以二
    int mid = l + r >> 1;

    //从数组中间一分为二，各自归并排序
    merge_sort(l, mid), merge_sort(mid + 1, r);

    //k是结果数组的下一个放置元素的位置，ij为数组左右两部分的起始指针
    int k = 0, i = l, j = mid + 1;
    //比较ij指针值的大小，择其小存于结果中
    while(i <= mid && j <= r){
        if(t[i] <= t[j]) tmp[k++] = t[i++];
        else tmp[k++] = t[j++];
    }
    //当某一部分已经全部加入结果后，另一部分的剩余元素直接加入结果
    while(i <= mid) tmp[k++] = t[i++];
    while(j <= r) tmp[k++] = t[j++];

    //用有序的结果覆盖原来无序的数组
    for(int i = l, j = 0; i <= r; i++,j++)
        t[i] = tmp[j];
}

int main(){
    int n;
    scanf("%d", &n);

    for(int i = 0; i < n; i++) scanf("%d", &t[i]);

    merge_sort(0, n - 1);

    for(int i = 0; i < n; i++) printf("%d ", t[i]);

    return 0;
}