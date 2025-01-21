#include <iostream>
#include<vector>
using namespace std;

int main() 
{
  int count=0;
    int n;
    cin>>n;
    vector<int>a(n);
    for(int i=0;i<n;i++)
    {
      cin>>a[i];
    }
    int maxSum = 0;
    for (int coin : a) {
        maxSum += coin;
    }
    vector<bool>prev(maxSum+1,false);
    prev[0]=true;
    for(int i=1;i<=n;i++)
    {
      vector<bool>current(maxSum+1,false);
      for(int j=0;j<=maxSum;j++)
      {
        if(prev[j])
        {
          current[j]=true;
          current[j+a[i-1]]=true;
        }
      }
      prev=current;
    }
    for (int i = 1; i <= maxSum; i++)
    {
        if (prev[i]) count++;
    }
    cout << count << endl;

    for (int i = 1; i <= maxSum; i++)
    {
        if (prev[i])
        {
            cout << i << " ";
        }
    }
    cout << endl;
    return 0;
}