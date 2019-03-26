#include <fstream>
#include <cstdlib>
#include <ctime>
using namespace std;

ifstream cin("quick.in");
ofstream cout("quick.out");

int setarePivot(int v[],int st, int dr)
{

    int i=st,j=dr,mod=1,aux;

    while(i<j)
    {
        if(v[i]>v[j])
         {
           aux=v[i];
           v[i]=v[j];
           v[j]=aux;
           mod=3-mod;
         }
         if(mod==1)++i;
         else --j;
    }
    return i;

}

int pivotare(int v[], int st, int dr)
{

        srand(time(NULL));
        int aux,random=st+rand()%(dr-st);
        aux=v[random];
        v[random]=v[dr];
        v[dr]=aux;
        return setarePivot(v,st,dr);

}

void quickSort(int v[],int st,int dr)
{
    if(st<dr)
    {
        int p=pivotare(v,st,dr);
        quickSort(v,st,p-1);
        quickSort(v,p+1,dr);
    }
}

int main()
{int v[1001],n;
 cin>>n;
 for(int i=0;i<n;++i)cin>>v[i];
 quickSort(v,0,n-1);
 for(int i=0;i<n;++i)cout<<v[i]<<" ";
    return 0;
}
