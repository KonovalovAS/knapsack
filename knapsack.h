#include <iostream>
#include <vector>

using namespace std;

class Problem{
public:
    struct item{
        int val,w;
        item( int w0=0, int v0=0 );
    };

    Problem( int K_arg, vector<item> &I );
    void add_item( item &newitem );
    item operator[](int k);

private:
    int n,K;
    vector<item> Items;

    class Solution{
    private:
        vector<int> content;
        Problem *problem;
    public:
        Solution( Problem *p );
        Solution( Problem *p, vector<int> &init );
        int weight();
        int value();
    };
};
