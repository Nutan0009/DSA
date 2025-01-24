#include<iostream>
#include<vector>
using namespace std;
const int MOD = 1e9 + 7;
void solve()
{
  int n;
  int t_sum=0;
  cin>>n;
  for(int i=1;i<=n;i++)
  {
    t_sum=t_sum+i;
  }
  if(t_sum%2!=0)
  {
    cout<<"0";
    return;
  }
  vector<int> dp(t_sum/2 + 1, 0);
    dp[0] = 1; 
  for(int i=1;i<=n;i++)
  {
    for(int j=t_sum/2;j>=i;j--)
    {
      int pick=dp[j-i];
      int skip=dp[j];
      dp[j]=(pick+skip)%MOD;
    }
  }
  //cout<<(dp[t_sum/2]/2)%MOD;
  cout << (1LL * dp[t_sum / 2] * 500000004) % MOD;
}
int main()
{
  solve();
  return 0;
  
}