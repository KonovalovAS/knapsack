#include "knapsack.h"

int Problem::item::ID = 0;

Problem::item::item( int w0, int v0 ){
    val = v0;
    w = w0;
    spec_val = (w0>0) ? (double)v0/w0 : -1 ;
    id = ID;
    ID ++;
}

bool Problem::item::operator<( const item &right ){
    return this->spec_val > right.spec_val;
}

// Problem

Problem::Problem( int K_arg, vector<item> &I ){
    n = I.size();
    K = K_arg;
    Items = I;
    taken = vector<bool> (n, false);
    sol_value = 0;
    sol_weight = 0;
}

Problem::item Problem::operator[](int k){
    if(k<n)
        return Items[k];
    else{
        return item();
    }
}

// Solving

void Problem::Solve(){

    sort(Items.begin(),Items.end());

    int i = 0;
    bool keep_going = true;
    while( keep_going && (i < n) ){

        if( sol_weight + Items[i].w <= K ){
            taken[ Items[i].id ] = true;
            sol_weight += Items[i].w;
            sol_value += Items[i].val;
        }
        i++;
    }

};

void Problem::show_items(){
    for(auto i: Items)
        cout<<"( "<<i.id<<", "<<i.spec_val<<" ) ";
}

void Problem::show_taken(){
    for(auto f: taken)
        cout << f << " ";
}

int Problem::Solution_value(){
    return sol_value;
}

int Problem::Solution_weight(){
    return sol_weight;
}


