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
   nod *varf=NULL;///foarte IMPORTANT, daca varf nu e NULL atunci cand cautam peek la ($), peek nu va returna -1 ci va da CRASH
   //codificam '('=0   si   ')'=1
   char a[10001], prop=1;
   cin.getline(a,10001);

   for(int i=0; a[i] && prop; ++i)
      {

       if(a[i]==')')
/*($)*/   if(peek(varf)==0)pop(varf);///daca inainte avem paranteza (
          else prop=0;///altfel deja e paranteza prost
       else
          push(0,varf);

      }
   if(!empty(varf) || !prop)cout<<"Incorect";
   else cout<<"Corect";
    return 0;
}
