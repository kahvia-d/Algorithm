//
// Created by Kahiva on 2023/11/10.
//
//https://www.acwing.com/problem/content/851/
//Dijkstra算法求有向图（无负边权）最短路

#include "iostream"
#include "algorithm"
#include "cstring"
using namespace std;

const int N = 501, M = 100001, INF = 0x3f3f3f3f;

//用邻接矩阵存储图
int graph[N][N];
bool alreadyMin[N];

int dist[N];    //distance

int n, m;


int dijkstra(){
    memset(dist, 0x3f, sizeof dist);
    dist[1] = 0;

    //要循环n次，寻找到达n个顶点的最短距离
    for (int i = 1; i <= n; ++i) {
        //寻找顶点1到达外部顶点的最短距离
        int minIndex = -1;
        for (int j = 1; j <= n; ++j) {
            if (!alreadyMin[j] && (minIndex == -1 || dist[j] < dist[minIndex]))
                minIndex = j;
        }
        //找到最短距离了，标记对应顶点已经找到最短路径
        alreadyMin[minIndex] = true;
        //由于新点加入可能导致捷径产生，需要更新顶点1到达其它顶点的最小距离
        for (int j = 1; j <= n; ++j) {
            //因为现在顶点1到达顶点minIndex的当前最短距离被找到了，所以判断顶点1能否通过该点中转使得到达其余点的距离缩短
            dist[j] = min(dist[j], dist[minIndex] + graph[minIndex][j]);
        }
    }

    return dist[n];
}

int main(){
    cin>>n>>m;
    memset(graph, 0x3f, sizeof graph);

    for (int i = 0; i < m; ++i) {
        //ab顶点，c为权（距离）
        int a, b, c;
        cin>>a>>b>>c;
        //保存边和边权，考虑到有重边的情况，边权只保存最小的那个。毕竟最短路径只走短的那条，
        graph[a][b] = min(graph[a][b], c);
    }

    int result = dijkstra();

    if(result == INF)
        puts("-1");
    else
        cout<<result;

    return 0;
}