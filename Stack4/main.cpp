#include <iostream>
#include <cstring>

using namespace std;

struct nod
{
    nod *next;
    int info;
};
int push(int val, nod *&varf)
{
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
int search(int val, nod *varf)
{
    int distanta=0;
    while(varf)
        if(varf->info==val)return distanta;
        else ++distanta,varf=varf->next;

    return -1;
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
  int n,x;
  cin>>n;
  for(int i=0; i<n; ++i)
  {
      cin>>x;
      if(peek(varf)==x)pop(varf);///pe perechi, daca elementul anterior e x atunci il scoatem
      else push(x,varf);///altfel in adaugam
  }
  if(!empty(varf))cout<<"Invalid";///daca la final stiva nu e VIDA atunci configuratia e invalida
  else cout<<"Valid";///altfel e valida
    return 0;
}
