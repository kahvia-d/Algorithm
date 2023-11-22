//
// Created by Kahiva on 2023/11/22.
//
//https://www.acwing.com/problem/content/842/
//拉链法模拟散列表

#include "iostream"
#include "algorithm"

using namespace std;


const int N = 200003;
const int null = 0x3f3f3f3f;

int n;

struct Node{
    int value;
    Node* next;

    Node():value(0),next(NULL){};
    Node(int val):value(val),next(NULL){};
};

struct Node* links[N];

//头插法插入对应位置的链表
void insert(int x){
    //负数取余为负数，而hash表索引为正，所以需要将余数加上N转换成正数（也可以不是N，总之要为正）
    //负数取余（参考https://www.cnblogs.com/renzmin/p/12054775.html）
    int index = (x % N + N) % N;
    //头插法
    Node* p = links[index];
    Node* node = new Node(x);
    node->next = p;
    links[index] = node;
}

//查询
bool find(int x){
    int index = (x % N + N) % N;
    Node* p = links[index];
    while (p != NULL){
        if(p->value == x)
            return true;
        else
            p = p->next;
    }

    return false;
}

int main(){
    cin>>n;

    while (n--){
        char op;
        int x;
        cin>>op>>x;

        if (op == 'I')
            insert(x);
        else{
            if (find(x))
                puts("Yes");
            else
                puts("No");
        }

    }

    return 0;
}