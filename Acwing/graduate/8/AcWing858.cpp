//
// Created by Kahiva on 2023/11/7.
//
//https://www.acwing.com/problem/content/860/
//Prim算法求无向图的最小生成树

#include "iostream"
#include "algorithm"
#include "cstring"
using namespace std;

const int N = 501, M = 100001, INF = 0x3f3f3f3f;

//用邻接矩阵存储图
int graph[N][N];
bool linked[N];

int dist[N];    //distance

int n, m;


int grim(){
    memset(dist, 0x3f, sizeof dist);
    dist[1] = 0;

    int res = 0;

    //要循环n次，将n个点加入最小生成树中
    for (int i = 1; i <= n; ++i) {
        //寻找当前连通部分到达外部顶点的最短距离
        int minIndex = -1;
        for (int j = 1; j <= n; ++j) {
            if (!linked[j] && (minIndex == -1 || dist[j] < dist[minIndex]))
                minIndex = j;
        }
        //如果抵达不了，说明最小生成树不存在
        if (dist[minIndex] == INF)
            return INF;
        //找到最短距离了，将对应的点加入连通的部分
        else{
            //加入连通部分
            linked[minIndex] = true;
            //总权值和增加
            res+=dist[minIndex];
            //由于新点加入可能导致捷径产生，需要更新连通部分整体到达外部顶点的距离
            for (int j = 1; j <= n; ++j) {
                if (graph[minIndex][j] < dist[j])
                    dist[j] = graph[minIndex][j];
            }
        }
    }

    return res;
}

int main(){
    cin>>n>>m;
    memset(graph, 0x3f, sizeof graph);

    for (int i = 0; i < m; ++i) {
        //ab顶点，c为权（距离）
        int a, b, c;
        cin>>a>>b>>c;
        //保存边和边权，考虑到有重边的情况，边权只保存最小的那个。毕竟最小生成树是由小边权生成，
        graph[a][b] = graph[b][a] = min(graph[a][b], c);
    }

    int result = grim();

    if(result == INF)
        puts("impossible");
    else
        cout<<result;

    return 0;
}