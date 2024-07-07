// Source: https://usaco.guide/general/io

#include <bits/stdc++.h>
using namespace std;

int main() {
int n;
cin>>n;
vector<int>arr(n);
for(int i=0;i<n;i++){
	cin>>arr[i];
}
int start = 0;
int cur_start = -1;
int end = -1;
int sum = 0;
int maxi = INT_MIN;

for(int i=0;i<n;i++){
	if(sum  == 0)cur_start = i;
   sum += arr[i];
   if(sum >  maxi){
	   maxi = sum;
	   start = cur_start;
	   end = i;
   }
   if(sum < 0){
	   sum = 0;
   }
}
for(int i =start ; i<=end;i++){
	cout<<arr[i] << " ";
}cout<<endl;
}
