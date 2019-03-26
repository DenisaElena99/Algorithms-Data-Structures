#include <iostream>

using namespace std;

struct nod
{
    nod *next;
    int info;
};
int push(int val, nod *&varf){
    if(!varf)
    {
        varf=new nod;
        varf->info=val;
        varf->next=NULL;
    }
    else
    {
        nod *p=new nod;
        p->info=val;
        p->next=varf;
        varf=p;

    }

}


int pop(nod *&varf)///trebuie modificata stiva deci e *&
{
    if(!varf)
        return -1;
    else
    {
        int x=varf->info;///pastram valoarea din varf
        nod *p=varf;///pastram adresa varfului
        varf=varf->next;///mergem cu varful mai departe
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
        cout<<"varf ";
        while(varf)
        {
            cout<<varf->info<<' ';
            varf=varf->next;
        }
        cout<<"baza "<<endl;
    }
    else cout<<"Stiva vida"<<endl;
}
int main()
{
  nod *varf=NULL;
  int n,x,a[101];
  cin>>n;
  cin>>a[0];
  push(a[0],varf);
  for(int i=1;i<n;++i)
  {
      cin>>a[i];
      if(!empty(varf) && a[i]!=peek(varf))pop(varf);
      else push(a[i],varf);
  }

   if(empty(varf))cout<<"Nu exista element majoritar";
   else
      { int ct=0;
        for(int i=0; i<n; ++i)
        if(a[i]==peek(varf))++ct;

        if(ct>=n/2+1)cout<<"Elementul majoritar este: "<<peek(varf);
        else cout<<"Nu exista element majoritar";
      }
    return 0;
}
