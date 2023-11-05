//
// Created by Kahiva on 2023/11/5.
//
//https://www.acwing.com/problem/content/850/
//拓扑排序(采用广度遍历实现)

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

//保存各顶点的入度
int inDegree[N];
//采用数组模拟队列，出队移动头索引，入队移动尾索引。这样可以在模拟队列的同时，保留原队列中的元素。
int checkQueue[N];

//将某个点和另一个点的边加入邻接表表示的图中。
void addLink(int fromNodeId, int toNodeId){
    Node* node = new Node(toNodeId);
    node->next = link[fromNodeId];
    link[fromNodeId] = node;
}

bool topSort(){
    //head指向队头，rear指向队列最后一个元素
    int head = 0, rear = -1;
    //因为顶点编号从1开始，所以入度数组从索引1开始遍历
    for (int i = 1; i <= n; ++i) {
        //遍历顶点，如果顶点入度为0，就入队
        if (!inDegree[i]){
            checkQueue[++rear] = i;
        }
    }
    while (head <= rear){
        //取出队头元素
        auto top = checkQueue[head++];
        //遍历它的邻边，将邻边那头对应点的入度减一
        for (auto p = link[top]; p ; p = p->next){
            inDegree[p->nodeId]--;
            //如果没有了前置结点，代表可以入队(即被遍历，或者说该工程任务可以执行了)
            if (inDegree[p->nodeId] == 0){
                checkQueue[++rear] = p->nodeId;
            }
        }
    }

    //如果队列中的元素个数刚好等于顶点个数，就代表拓扑排序成立，即不存在闭环。
    //因为如果有闭环，闭环上结点的入度始终不为0，无法入队。
    return n == rear + 1;
}

int main() {

    cin>>n>>m;

    while (m--){
        int from, to;
        cin>>from>>to;
        addLink(from, to);
        inDegree[to]++;
    }

    //如果拓扑排序无效，则输出-1
    if (!topSort())
        cout<<"-1";
    else
        for (int i = 0; i < n; ++i)
            cout<<checkQueue[i]<<' ';

    return 0;

}