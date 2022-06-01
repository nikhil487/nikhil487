#include<iostream>
#include<vector>

using namespace std;
int sum(int idx,vector<int>arr)
{
    int ans = 0;
    while(idx > 0)
    {
        ans += arr[idx];
        idx = idx - (idx&-idx);// idx&-idx gives the last set bit of the number ;
    }
    return ans;
}
void update(int idx,int val,vector<int>&arr)
{
    while(idx <= arr.size()-1)
    {
        arr[idx] += val;
        idx = idx + (idx&-idx);
    }

}
void display(vector<int>arr)
{
    for(int i = 1;i<arr.size();i++) cout<<arr[i]<<" ";

    cout<<endl;
}
int main()
{
    //  #ifndef ONLINE_JUDGE
    //     freopen("input.txt","r",stdin);
    //     freopen("output.txt","w",stdout); 
    //  #endif
    int n;
    cin>>n;
    vector<int>arr(n+1,0);
    vector<int>csum(n+1,0);
    vector<int>farr(n+1);
    for(int i = 1;i<=n;i++)
    {
        cin>>arr[i];
         csum[i] += csum[i-1] + arr[i];
    }
     for(int i = 1;i<=n;i++)
     {
         farr[i] = csum[i] - csum[i - (i&-i)];
     }
    //  display(csum);
    //  display(farr);
     int q;
     cin>>q;
     while(q--)
     {
         char ch;
         int i,j;
         cin>>ch>>i>>j;
         if(ch == 'q')
         {
             cout<<sum(j,farr) - sum(i,farr) + arr[i]<<endl;
         }
         else
         {
             arr[i] += j;
             update(i,j,farr);
         }
     }

   
}