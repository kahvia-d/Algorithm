//
// Created by Kahiva on 2023/10/31.
//
//https://www.acwing.com/problem/content/150/
//使用哈夫曼树的知识合并果子堆，计算最小花费体力

#include <iostream>
#include <algorithm>
#include <queue>
#include <vector>

using namespace std;

int main(){
    //定义一个优先队列，第一个参数是队列元素的类型，第二个是使用的容器类型，第三个是排序方式。
    //此处使用升序排序，即小的元素优先出队。
    priority_queue<int, vector<int>, greater<int>> stones_heap;

    int n;
    cin>>n;
    while (n--){
        int stones;
        cin>>stones;
        stones_heap.push(stones);
    }

    int strength_used = 0;

    while (stones_heap.size() > 1){
        //取出最小的两个结点（果子堆）
        int min1 = stones_heap.top();
        stones_heap.pop();
        int min2 = stones_heap.top();
        stones_heap.pop();
        //将这两个果子堆合并
        stones_heap.push(min1 + min2);
        //累计合并果子堆花费的体力
        strength_used += (min1 + min2);
    }

    cout<<strength_used;

}

