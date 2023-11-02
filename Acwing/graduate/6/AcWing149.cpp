//
// Created by Kahiva on 2023/11/1.
//
//https://www.acwing.com/problem/content/151/
//荷马史诗

#include "iostream"
#include "algorithm"
#include "queue"
#include "vector"

using namespace std;

//define a pair of data. long long for word_code and int for Huffman coding node depth.
typedef pair<long long, int> PLI;

int main(){
    priority_queue<PLI, vector<PLI>, greater<>> words;

    //k is the system of numeration
    long long words_num, k;
    cin>>words_num>>k;

    while (words_num--){
        long long word;
        cin>>word;
        words.push({word, 0});
    }
    //every loop for merge will delete k nodes and add a combined node,
    //so k-1 nodes decrease in each merge.
    //the loop will continues until there is only one node.
    //loop time = (words_num - 1) / (k-1).
    //if the time is not a integer, just add zero node until it can be a integer.
    while ((words.size() - 1) % (k - 1) != 0)
        words.push({0,0});

    //the with power length is the new coded book length
    long long wpl = 0;

    while (words.size() > 1){
        long long  combined_node_val = 0;
        int max_depth = 0;
        for (int i = 0; i < k; ++i) {
            //get the min node
            auto min_node = words.top();
            //merge
            combined_node_val += min_node.first;
            //save the highest son-tree's depth
            max_depth = max(max_depth, min_node.second);
            //delete the node
            words.pop();
        }
        //add the combined node.
        words.push({combined_node_val,max_depth + 1});
        //the new combined node value is a part of the WPL.
        wpl += combined_node_val;
    }

    cout<<wpl<<endl<<words.top().second;

    return 0;
}