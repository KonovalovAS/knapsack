#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

void read_and_solve();

class Problem{
public:
    struct item{
        int id;
        int val,w;
        double spec_val;
        static int ID;

        item( int w0=0, int v0=0 );
        bool operator<( const item &right );
    };

    Problem( int K_arg, vector<item> &I );

    void Solve();

    item operator[](int k);

    void show_taken();
    void show_items();

    int Solution_value();
    int Solution_weight();

private:
    int n,K;
    vector<item> Items;

    int sol_weight, sol_value;
    vector<bool> taken;
};
