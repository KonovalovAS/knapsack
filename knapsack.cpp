#include "knapsack.h"

Problem::item::item( int w0, int v0 ){
    val = v0;
    w = w0;
}

Problem::Problem( int K_arg, vector<item> &I ){
    n = I.size();
    K = K_arg;
    Items = I;
}

void Problem::add_item( item &newitem ){
    n++;
    Items.push_back(newitem);
}

Problem::item Problem::operator[](int k){
    if(k<n)
        return Items[k];
    else{
        return item();
    }
}

// Solution

Problem::Solution::Solution( Problem *p ){
    problem = p;
}

Problem::Solution::Solution( Problem *p, vector<int> &init ){
    problem = p;
    content = init;
}

int Problem::Solution::weight(){
    int wght(0);
    for(int k=0; k<problem->n; k++)
        wght += ((*problem)[k]).w * content[k];
    return wght;
}

int Problem::Solution::value(){
    int val(0);
    for(int k=0; k<problem->n; k++)
        val += ((*problem)[k]).val * content[k];
    return val;
}


