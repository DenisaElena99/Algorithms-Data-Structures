#include <fstream>

using namespace std;

ifstream cin("count.in");
ofstream cout("count.out");

void countSort(int n,int v[],int ct[],int maxim)
{   int a[10001];

    for(int i=1; i<=maxim; ++i)
      ct[i]+=ct[i-1];///cate elemente sunt inainte de elementul nostru practic

    for(int i=0; i<n; ++i)

     {
     a[ct[v[i]]-1]=v[i];///punem
     --ct[v[i]];///scadem contorul
     }


     for(int i=0; i<n; ++i)
     v[i]=a[i];

}

int main()
{

    int n,v[10001],ct[10001],maxim=-1e9;
    cin>>n;
    for(int i=0; i<n; ++i)
       {
           cin>>v[i];
           if(v[i]>maxim)maxim=v[i];
           ++ct[v[i]];
       }

    countSort(n,v,ct,maxim);

    for(int i=0; i<n; ++i)
    cout<<v[i]<<" ";
    return 0;
}
