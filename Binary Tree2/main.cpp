#include <iostream>
#include <cstring>
using namespace std;
struct nod
{
    char sir[20];
    nod *st,*dr;
};


void inserare (nod *&radacina, char s[20])
{
    if(!radacina)
    {
        radacina=new nod;
        radacina->st = radacina->dr = NULL;
        strcpy(radacina->sir,s);

    }

    else

        if( strcmp( radacina->sir,s)>0 )
             inserare(radacina->st,s);
        else inserare(radacina->dr,s);

}



void SRD( nod *radacina)
{
    if(radacina)
    {
        SRD(radacina->st);
        cout<<radacina->sir<<" ";
        SRD(radacina->dr);
    }
}

int main()
{ nod *radacina=NULL;

  char s[20];
  int n,x;
  cin>>n;
  for(int i=0; i<n; ++i)
 {
  cin>>s;
  inserare(radacina,s);
 }
 SRD(radacina);
 cout<<endl;

    return 0;
}
