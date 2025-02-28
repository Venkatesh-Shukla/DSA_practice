#include<iostream>
#include<vector>
using namespace std;

int main()
{
    int n;
    cin>>n;
    int temp=2*n+2;
    vector<int> seq(n);
    for(int i=0;i<n;i++)
    {
        int temp;
        cin>>temp;
        seq[i]=temp;
    }
    vector<int> gen(temp,0);
    for(int i=0;i<n;i++)
    {
        gen[2*(i+1)]=gen[seq[i]]+1;
        gen[2*(i+1)+1]=gen[seq[i]]+1;        
    }
    for(int i=1;i<gen.size();i++)
    {
        cout<<gen[i]<<"\n";
    }

}