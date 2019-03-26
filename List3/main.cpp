#include <iostream>

using namespace std;
struct nod
{
    int info;
    nod *next;
}*prim,*ultim;

int main()
{
    int n,x;
    cin>>n>>x;
    prim=new nod;
    prim->info=x;
    prim->next=NULL;
    ultim=prim;


    for(int i=2;i<=n;++i)
    {cin>>x;

     nod *p=new nod;
     p->info=x;
     ultim->next=p;
     p->next=NULL;
     ultim=p;
    }

    nod *anterior,*urmator, *curent;
    anterior=prim;
    curent=prim->next;
    urmator=prim->next->next;
   while(urmator)
    {
        curent->next=anterior;
        anterior=curent;
        curent=urmator;
        if(curent)urmator=urmator->next;///daca elementul curent e NULL atunci nu TREBUIE sa mai continuam cu urmator deoarece el deja are adresa NULL si daca facem urmator->next pt o adresa NULLA ne va da c
    }

    curent->next=anterior;///facem ultima legatura doarece ma oprisem cand am ajuns la urmator cu NULL deci nu am facut ultima sinapsa

    prim->next=NULL;///prim va deveni ultim si invers
    curent=prim;
    prim=ultim;
    ultim=curent;

    for(nod *p=prim; p;p=p->next)
      cout<<p->info<<" ";
    return 0;
}
