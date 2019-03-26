#include <iostream>

using namespace std;

struct nod
{
    nod *next,*prev;
    int info;
};
int push(int val, nod *&baza, nod *&varf)
{
    if(!baza)
    {
        baza=new nod;///initializam noul nod
        baza->info=val;
        baza->next=NULL;
        baza->prev=NULL;
        varf=baza;
    }
    else
    {   // altfel legam baza curenta de un nou nod pe care il adaugam
        nod *p=new nod;
        p->info=val;
        p->next=baza;
        p->prev=NULL;
        baza->prev=p;///legam baza
        baza=p;
    }

}
int pop(nod *&varf)///trebuie modificata coada deci e *&
{
    if(!varf)
        return -1;
    else
    {
        int x=varf->info;///pastram valoarea din varf
        nod *p=varf;///pastram adresa varfului
        varf=varf->prev;///mergem cu varful inapoi
        delete p;///stergem varful anterior
        return x;///returnam valoarea varfului anterior
    }
}
int peek(nod *varf)
{
    if(!varf)
        return -1;
    else
        return varf->info;
}
int empty(nod *varf)
{
    if(!varf)return 1;
    return 0;
}
void afisare(nod *varf)
{
    if(varf)
    {
        cout<<"out ";
        while(varf)
        {
            cout<<varf->info<<' ';
            varf=varf->prev;
        }
        cout<<"in "<<endl;
    }

    else cout<<"Coada vida"<<endl;
}
int main()
{
    nod *varf[1001]={NULL},*baza[1001]={NULL};
    struct
    {
        int in,out;
    }intrari[1001];



    int n,k,vagoane[1001];
    cin>>n>>k;
    for(int i=0; i<n; ++i)
      cin>>vagoane[i];

    for(int i=n-1; i>=0; --i)
    { int prop=0;
        for(int j=k-1; j>=0; --j)
          if(empty(varf[j]))//daca linia e goala pusham direct
            { prop=1;
              push(vagoane[i],baza[j],varf[j]);
              intrari[i].in=vagoane[i];
              intrari[i].out=j;
              break;
            }
          else if(baza[j]->info<vagoane[i])
              {prop=1;
               push(vagoane[i],baza[j],varf[j]);
               intrari[i].in=vagoane[i];
               intrari[i].out=j;
               break;
              }

       if(!prop)
       {
         cout<<"Nu exista strategie";
         return 0;
       }

    }


     for(int i=n-1; i>=0; --i)
     cout<<"vagonul "<<intrari[i].in<<" intra in linia "<<intrari[i].out<<endl;

     for(int i=1; i<=n; ++i)
       for(int  j=0; j<k; ++j)
         if(peek(varf[j])==i)
          {cout<<"Scoatem vagonul "<<i<<" de pe linia "<<j<<endl;
           pop(varf[j]);
          }

    return 0;
}
