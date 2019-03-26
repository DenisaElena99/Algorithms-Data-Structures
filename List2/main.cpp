#include <iostream>

using namespace std;

struct nod
{
    float info;
    nod *next;
}*prim, *ultim;


int main()
{
    int n,x;
    cin>>n>>x;
    prim=new nod;
    prim->next=NULL;
    prim->info=x;
    ultim=prim;


    for(int i=2; i<=n; ++i)
    {
        cin>>x;
        nod *xx=new nod;
        xx->info=x;

        if(x<prim->info)///mai mic decat primul
         {xx->next=prim;
          prim=xx;
         }
        else
             if(x>ultim->info)///mai mare decat ultimul
              {ultim->next=xx;
               xx->next=NULL;
               ultim=xx;
              }
             else
                 for(nod *p=prim; p->next; p=p->next)///cautam unde sa il bagam pe x verificand constant pozitia urmatoare
                  if(p->next->info>x)
                  {xx->next=p->next;
                   p->next=xx;
                   break;
                  }

    }

    for(nod *p=prim;  p;  p=p->next)
    cout<<p->info<<" ";
    return 0;
}
