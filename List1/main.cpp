#include <iostream>

using namespace std;
struct nod
{
    float info;
    nod *next;
}*prim,*ultim;

int main()
{
  int n,x;
  cin>>n;
  cin>>x;
  nod *p=new nod;
  p->info=x;
  p->next=NULL;
  prim=ultim=p;
  for(int i=2;i<=n;++i)
  {
      nod *p=new nod;
      cin>>p->info;
      p->next=NULL;
      ultim->next=p;
      ultim=p;
  }

  for(nod *p=prim; p->next /*trebuie sa stim ca exista nodul urmator ca sa putem face media, altfel da bucla*/ ;   )
  {
      nod *xx=new nod;
      xx->info=(p->info+p->next->info)/2;
      xx->next=p->next;
      p->next=xx;
      p=xx->next;

  }

  for(nod *p=prim; p; p=p->next)
    cout<<p->info<<" ";
    return 0;
}
