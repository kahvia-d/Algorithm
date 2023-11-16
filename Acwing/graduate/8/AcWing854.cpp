//
// Created by Kahiva on 2023/11/16.
//
//https://www.acwing.com/problem/content/description/856/
//Floyd求最短路(O(n^3))

#include "iostream"
#include "algorithm"
#include "cstring"
using namespace std;

const int N = 210, M = 20010, INF = 0x3f3f3f3f;

int graph[N][N];

int main(){
    int n, m, k;
    cin>>n>>m>>k;

    //初始化各点之间不可到达
    memset(graph, 0x3f, sizeof graph);
    //各点自己到自己距离为0
    for (int i = 1; i <= n; ++i)
        graph[i][i] = 0;
    //保存图边
    while (m--){
        int a, b, c;
        cin>>a>>b>>c;
        //可能有重边，只取权值最小
        graph[a][b] = min(graph[a][b], c);
    }

    //Floyd算法，依次加入第k个中转站，更新可能存在的捷径
    for (int k = 1; k <= n; ++k)
        for (int i = 1; i <= n; i++)
            for (int j = 1; j <= n; j++)
                graph[i][j] = min(graph[i][j], graph[i][k] + graph[k][j]);

    //回应询问
    while (k--){
        int a, b;
        cin>>a>>b;
        if (graph[a][b] > INF/2)
            puts("impossible");
        else
            cout<<graph[a][b]<<endl;
    }


    return 0;
}