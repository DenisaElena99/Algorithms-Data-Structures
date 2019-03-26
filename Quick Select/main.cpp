#include <fstream>
#include <cstdlib>
#include <ctime>
using namespace std;

ifstream cin("select.in");
ofstream cout("select.out");


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

int quickSelect(int v[],int st,int dr, int element)
{
    int p=pivotare(v,st,dr);
    if(element<v[p])
      return quickSelect(v,st,p-1,element);
    else if(element>v[p])
           return  quickSelect(v,p+1,dr,element);
         else
              return v[p];
}

int main()
{int v[1001],n;
 cin>>n;
 for(int i=0;i<n;++i)cin>>v[i];
 cout<<quickSelect(v,0,n-1,8);
    return 0;
}
