#include<bits/stdc++.h>
#define MOD 1000000007
using namespace std;
int main(){
    string a, b;
    cin >> a >> b;
    int n = a.length();
    int m = b.length();
    vector<int>prev(m+1);
    vector<int>current(m+1);
    for(int i = 0; i <= n; i++){
        current[0] = i; 
    }
    for(int i = 1; i <= n; i++)
    { 
        for(int j = 1; j <= m; j++)
        { 
            char x = a[i - 1];
            char y = b[j - 1];
            if(x == y)
            { 
                current[j] = prev[j - 1];
            }
            else
            { 
                current[j] = prev[j - 1] + 1;
            }
            current[j] = min(current[j], prev[j] + 1);
            current[j] = min(current[j], current[j - 1] + 1);
        }
        prev=current;
    }
    cout << prev[m] << endl;
    return 0;
}