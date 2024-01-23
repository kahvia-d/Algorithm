//
// Created by Kahiva on 2024/1/23.
//
#include <iostream>

using namespace std;

const int N = 1010;
int a[N][N], s[N][N];

int main(){
    //n行m列，q个询问
    int n, m, q;
    scanf("%d%d%d", &n, &m, &q);

    for(int i = 1; i <= n; i++)
        for(int j = 1; j <=m; j++)
            scanf("%d", &a[i][j]);

    for(int i = 1; i <= n; i++)
        for(int j = 1; j <= m; j++)
            /*
             *  a11 a12 | a13
             *  a21 a22 | a23
             *  --------|----
             *  a31 a32 | a33
             * 比如s[3][3] = s[3][2] + s[2][3] - s[2][2]（这是去除重复加的部分）+ a[3][3]
             * */
            s[i][j] = s[i][j - 1] + s[i - 1][j] - s[i - 1][j - 1] + a[i][j];

    while(q--){
        int x1, y1, x2, y2;
        scanf("%d%d%d%d", &x1, &y1, &x2, &y2);
        /*
         *  a11 a12 a13 | a14 a15
         *  a21 a22 a23 | a24 a25
         *  ------------|--------
         *  a31 a32 a33 | a34 a35
         *  a41 a42 a43 | a44 a45
         * s[[3][4], [4][5]] = s[4][5] - s[4][3] - s[2][5] + s[2][3]（补回多减的重叠部分）
         * 实际上，这里的s[[3][4], [4][5]]整体类似于上一个注释位置中的a[3][3]，都是被夹的一部分，只是包含数据个数不同的区别。
         * */
        printf("%d\n", s[x2][y2] - s[x2][y1 - 1] - s[x1 - 1][y2] + s[x1 - 1][y1 - 1]);
    }

    return 0;
}
