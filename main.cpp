#include "knapsack.h"

int main()
{
    /*
    int K = 10;
    Problem::item a(2,2), // 0
                  b(3,1), // 1
                  c(4,1), // 2
                  d(5,6), // 3
                  e(8,1), // 4
                  f(7,2), // 5
                  g(1,5), // 6
                  h(8,10); // 7
    vector<Problem::item> I = { a,b,c,d,e,f,g,h };
    */

    int n,K;
    cin>>n>>K;
    vector<Problem::item> I(0);
    for(int i=0; i<n; i++){
        int w,v;
        cin>>v>>w;
        I.push_back( Problem::item(w,v) );
    }

    Problem P(K,I);
    P.Solve();

    cout << P.Solution_value() << endl;
    P.show_taken();

    return 0;
}
