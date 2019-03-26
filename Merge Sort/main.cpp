#include <fstream>

using namespace std;
ifstream cin("merge.in");
ofstream cout("merge.out");

void merge(int v[], int st, int mij, int dr)
{
    int d1,d2,jum1[10001],jum2[10001];

    d1=mij-st+1;
    d2=dr-mij;

    for(int i=0;i<d1;++i)
    jum1[i]=v[st+i];

    for(int i=0;i<d2;++i)
    jum2[i]=v[mij+i+1];

    int i=0,j=0;
    while(i<d1 && j<d2)
      if(jum1[i]<jum2[j])
           v[st++]=jum1[i++];
      else v[st++]=jum2[j++];

    while(i<d1) v[st++]=jum1[i++];
    while(j<d2) v[st++]=jum2[j++];


}
void Divide(int v[],int st, int dr)
{
    if(st<dr)
    {
        int m=(st+dr)/2;
        Divide(v,st,m);
        Divide(v,m+1,dr);
        merge(v,st,m,dr);
    }
}

int main()
{  int v[1001],n;

   cin>>n;
   for(int i=0; i<n; ++i)
      cin>>v[i];

   Divide(v,0,n-1);

   for(int i=0; i<n; ++i)
   cout<<v[i]<<" ";



    return 0;
}
