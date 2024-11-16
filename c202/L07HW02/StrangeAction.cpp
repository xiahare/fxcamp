
#include <iostream>
#include <queue>

using namespace std;

int gcd(int a, int b) {
    return b == 0 ? a : gcd(b, a % b);
}

int gcdOfFour(int a, int b, int c, int d) {
    return gcd(gcd(a, b), gcd(c, d));
}

int main() {
    int start, end , a, b;
    cin>> start >> end;
    
    if(start==end){
        cout<<1<<endl;
        return 0;
    }
    
    cin>> a >> b;
    
    // gcd()
    int cd = gcdOfFour(start,end,a,b);
    
    // update init data
    start = start/cd;
    end = end/cd;
    a=a/cd;
    b=b/cd;
    
    int n = start - end +1;
    
    // init
    vector<int> dp(n,0);
    dp[0]=1;
    // dp process
    for( int i=1; i<n; i++){
            // dp(i) = dp(i-a) + dp(i-b)
        int ia = i-a, ib = i-b;
        dp[i] = (ia>=0?dp[ia]:0) + (ib>=0?dp[ib]:0);
        
    }
    
    cout<<dp[n-1]<<endl;
    return 0;
}

/**
10 3
2 3
-------
3
 
200 100
20 30
-------
7
 
 
300000 100000
5000 9000
-------
102342019
 
686 256
12 26
-------
1494584
 */
