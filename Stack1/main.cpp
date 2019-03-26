#include <iostream>

using namespace std;

struct nod
{
    nod *next;
    int info;
};

int push(int val, nod *&varf)/// trebuie *& DEOARECE
// & = MERGEM LA ADRESA LUI varf
//*mergem la valoarea de la adresa lui varf deci lucram direct cu locul respectiv
///DACA FOLOSEAM DOAR *varf atunci noi lucram doar cu valoarea varf dar nu cu valoarea de la ADRESA lui varf, deci practic varf nu se schimba ci noi lucram cu o copie a valorii acestuia
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

void afisare(nod *varf)///aici nu lucram cu *& deoarece noi lucram doar cu VALOAREA lui varf, nu trebuie sa mergem la adresa lui ca atunci s-ar fi schimbat si el
/*Spre exemplu daca apelam
afisare();
afisare();
iar functia este void afisare(nod *&varf) ne va fi afisat

varf 8 41217 414 12 42 baza
STIVA VIDA

DEOARECE noi am mers cu varful pana la baza in prima afisare dar am folosit ADRESA lui varf deci acesta s-a schimbat in memorie.
La a doua afisare varf va fi de fapt NULL pt ca asa a ramas de la prima afisare (vezi $$$ mai jos) deci va fi nulla stiva
De asta noi lucram doar cu *varf, nu cu *&varf
*/
{

    if(varf)
    {
        cout<<"varf ";
        while(varf) //$$$
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
    afisare(varf);
    push(1,varf);
    push(2,varf);
    push(3,varf);
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
