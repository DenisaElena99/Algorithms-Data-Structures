#include <iostream>

using namespace std;

struct nod
{
    int info;
    nod *next;
}*prim1,*prim2,*ultim1,*ultim2;

int main()
{
    int n,m,x;
    cin>>n>>x;
    prim1=new nod;
    prim1->next=NULL;
    prim1->info=x;
    ultim1=prim1;
    for(int i=2; i<=n; ++i)
    {
        cin>>x;
        nod*p=new nod;
        p->info=x;
        p->next=NULL;
        ultim1->next=p;
        ultim1=p;
    }

    cin>>m>>x;
    prim2=new nod;
    prim2->next=NULL;
    prim2->info=x;
    ultim2=prim2;
    for(int i=2; i<=m; ++i)
    {
        cin>>x;
        nod*p=new nod;
        p->info=x;
        p->next=NULL;
        ultim2->next=p;
        ultim2=p;
    }



    nod *q=prim2, *antq;///cu astea vom pastra cate 2 elemente consecutime din lista 2, astfel vom putea insera un element intre ELE 2
    ///parcurgem primul vector si il adaugam in prima lista
    for(nod *p=prim1;  p && q;  p=prim1)
    {
        while(q && q->info <= p->info)
           antq=q,q=q->next;

        if(q)
            if(q==prim2)///bagam la inceputul listei 2
            {
                prim1=p->next;
                p->next=q;
                prim2=p;

            }
            else///bagam intre 2 elemente
            {
                prim1=p->next;
                antq->next=p;
                antq=p;
                p->next=q;
            }
        else antq->next=p,ultim2=ultim1;///lista 2 nu mai are elemente

    }

    for(nod *p=prim2; p; p=p->next)
        cout<<p->info<<" ";




    return 0;
}
