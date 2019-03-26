#include <iostream>

using namespace std;

struct nod
{
    nod *next,*prev;
    int info;
};///facem o COADA DUBLU INLANTUITA CA SA FACEM POP IN O(1)

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

int search(int val, nod *varf)
{
    int distanta=1;
    while(varf)
        if(varf->info==val)return distanta;
        else ++distanta,varf=varf->prev;

    return -1;
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
    nod *varf=NULL,*baza=NULL;
    afisare(varf);
    push(1,baza,varf);
    push(2,baza,varf);
    push(3,baza,varf);
    afisare(varf);
    cout<<search(2,varf)<<endl;
    cout<<search(4,varf)<<endl;
    cout<<empty(varf)<<endl;
    cout<<pop(varf)<<endl;
    afisare(varf);
    cout<<peek(varf)<<endl;
    afisare(varf);
    pop(varf);
    pop(varf);
    afisare(varf);
    cout<<pop(varf)<<endl;
    cout<<empty(varf)<<endl;
    return 0;
}
