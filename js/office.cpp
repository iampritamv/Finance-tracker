#include<iostream>
#include<bits/stdc++.h>
using namespace std;

int main()
{
  int n1 , m1 , k1 ;
  int d1=1;
  int r=0;
  
  cin>> n1 >> m1 ;
  
  vector<set<int>> a(n1);
  
  for(int i = 0 ; i<m1 ;  ++i)
  {
    int b , c;
    cin>>b>>c;
    a[b].insert(c);
    a[c].insert(b);
  }
  
  cin>>k1;
  vector<bool> x(n1,true);
  r=n1;
  while(r < k1)
  {
    vector<bool> z(n1,false);
    for(int i = 0 ; i < n1 ; i++)
    {
      int cnt = 0;
      for(int f : a[i]) cnt+=x[f];
      if(x[i] && cnt == 3) z[i] =true;
      else if (!x[i] && cnt< 3 ) z[i] = true;
    }
    x=z;
      r +=count(x.begin(),x.end(),true);
    	d1++;
  }
  cout<< d1;
}
  