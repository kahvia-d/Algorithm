//
// Created by Kahiva on 2023/11/6.
//
//https://www.acwing.com/problem/content/850/
//拓扑排序(采用深度优先遍历实现)

#include "iostream"
#include "algorithm"
#include "queue"

using namespace std;

//n个顶点m条边
int n, m;
//定义一个常量N，即最大可能用到的顶点数。定义入度数组和模拟队列的数组时可以用到。
const int N = 100010;

struct Node {
    int nodeId;
    Node* next;
    Node(int id):nodeId(id), next(NULL){};
}*link[N];

//采用数组模拟队列，出队移动头索引，入队移动尾索引。这样可以在模拟队列的同时，保留原队列中的元素。
int checked[N], result[N], rear;

//将某个点和另一个点的边加入邻接表表示的图中。
void addLink(int fromNodeId, int toNodeId){
    Node* node = new Node(toNodeId);
    node->next = link[fromNodeId];
    link[fromNodeId] = node;
}

//在深搜的过程中可能发现经过重复的点，代表出现了回环，说明拓扑排序不存在
bool dfs(int nodeId){
    //标记当前点被遍历
    checked[nodeId] = 1;

    //深度优先遍历当前顶点可以通往的顶点
    for (auto node = link[nodeId]; node; node = node->next){
        //如果要通往的顶点没被遍历过，但是dfs遍历过程中出现了回环，返回dfs结果false
        if (!checked[node->nodeId] && !dfs(node->nodeId))
            return false;
        //如果要通往的顶点已经被遍历过了，说明出现该处是一个回环，返回dfs结果false
        else if(checked[node->nodeId] == 1)
            return false;
    }

    //如果当前顶点的dfs遍历完毕，说明当前顶点的dfs过程中不存在回环。
    checked[nodeId] = 2;
    result[rear++] = nodeId;
    return true;

}


bool topSort(){
    //考虑到图可能不连通，或者选择的深搜起点不能一次全部遍历完，所以需要切换起点反复深搜
    for (int i = 1; i <= n; ++i) {
        if (!checked[i]){
            bool haveLoopPath = !dfs(i);
            if(haveLoopPath)
                return false;
        }
    }
    return true;
}

int main() {

    cin>>n>>m;

    while (m--){
        int from, to;
        cin>>from>>to;
        addLink(from, to);
    }

    //如果拓扑排序无效，则输出-1
    if (!topSort())
        cout<<"-1";
    else
        for (int i = n - 1; i >= 0; --i)
            cout<<result[i]<<' ';

    return 0;

}