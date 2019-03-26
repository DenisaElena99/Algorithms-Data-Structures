#include <iostream>
using namespace std;
struct nod
{
    int info;
    nod *st,*dr;
};


void inserare (nod *&radacina, int valoare)
{
    if(!radacina)
    {
        radacina=new nod;
        radacina->st = radacina->dr = NULL;
        radacina->info=valoare;

    }

    else

        if( radacina->info >valoare )
            inserare(radacina->st,valoare);
        else inserare(radacina->dr,valoare);

}



bool cauta(nod *radacina, int x)
{
    if(!radacina)return 0;


    if(radacina->info==x)return 1;
    else if(radacina->info>x) return cauta(radacina->st, x);
    else return cauta(radacina->dr, x);

}

void afisareMaxim(nod *radacina)///mergem in dreapta pana nu mai putem
{
    if(!(radacina->dr))cout<<"Maximum este"<<radacina->info<<endl;
    else afisareMaxim(radacina->dr);
}


void SRD( nod *radacina)
{
    if(radacina)
    {
        SRD(radacina->st);
        cout<<radacina->info<<" ";
        SRD(radacina->dr);
    }
}

void SDR( nod *radacina)
{
    if(radacina)
    {
        SDR(radacina->st);
        SDR(radacina->dr);
        cout<<radacina->info<<" ";

    }
}


void RSD(nod *radacina)
{
    if(radacina)
    {
        cout<<radacina->info<<" ";
        RSD(radacina->st);
        RSD(radacina->dr);
    }
}



void stergere(nod *&radacina,int x)
{


    ///nodul pe care il stergem are maxim un fiu
    nod *anterior,*nodsters;
    anterior=radacina;
    bool exista=0,unde; //unde se afla nodul nostru fata de nodul anterior 0 =stanga ;  1=dreapta

    while(anterior)
    {
        if(anterior->st)///daca exista stang
            if(anterior->st->info==x)///veriicam
            {
                unde=0;
                exista=1;
                break;
            }

        if(anterior->dr)///daca exista drept
            if(anterior->dr->info==x)///verificam
            {
                unde=1;
                exista=1;
                break;
            }


        if(x<anterior->info)
            anterior=anterior->st;
        else
            anterior=anterior->dr;

    }
    if(!exista)
    {
        cout<<"Nodul nu exista in arbore";
        return;
    }

    /// in UNDE pastram daca X se afla in stanga sau dreapta lui ANTERIOR

    if(unde==0)nodsters=anterior->st;///salvam nodul pe care il stergem
    else nodsters=anterior->dr;

    if(   !(nodsters->st) && nodsters->dr) ///daca nodul nostru are un singur fiu la dreapta
    {
        if(unde==0)///daca se afla in stanga nodului anterior  cuplam stanga de anterior cu dreapta de curent
        {
            anterior->st=nodsters->dr;
            delete nodsters;
        }
        else
        {
            anterior->dr=nodsters->dr;///altfel cuplam dreapta de anterior cu dreapta de curent
            delete nodsters;
        }
        return;///iesim
    }


    if(nodsters->st  && !(nodsters->dr))
    {
        if(unde==0)
        {
            anterior->st=nodsters->st;
            delete nodsters;
        }
        else
        {
            anterior->dr=nodsters->st;
            delete nodsters;
        }
        return;
    }


    if( !(nodsters->st) && !(nodsters->dr) )///daca nu are fii il stergem efectiv
    {
        delete nodsters;
        return;
    }



    //daca nodul nostru are 2 FII, treaba e mai interesanta
    //luam stanga nodului si o ducem in STANGA celui mai din stanga nod din subarmorele drept al nodului
    /*

                         44
             33     <
        25<      >38
          >28  36<  >40
             >30

            REZULTA DACA TAIEM 33
                          44
             38     <
        36<      >40
     25<
       >28
         >30
    */

    nod *limita;
    limita=nodsters->dr;
    while(limita->st)limita=limita->st;///cautam limita stanga a subarborelui drept

    if(unde==0)anterior->st=nodsters->dr; ///punem subarborele drept an nodului nostru in locul nodului
    else anterior->dr=nodsters->dr;

    limita->st=nodsters->st;///unim limita stanga a subarborelui drept cu subarborele stang
    delete nodsters;


}

void afisareSmechera(nod *radacina, int nivel)
{
    if(radacina)
    {
        afisareSmechera(radacina->st,nivel+1);
        cout<<nivel<<" "<<radacina->info<<endl;
        afisareSmechera(radacina->dr,nivel+1);
    }

}

/* exemplu
11
88 44 56 65 33 38 36 40 25 28 30
*/

int main()
{
    nod *radacina=NULL;


    int n,x;
    cin>>n;
    for(int i=0; i<n; ++i)
    {
        cin>>x;
        inserare(radacina,x);
    }
    SRD(radacina);
    cout<<endl;
    stergere(radacina,33);
    afisareSmechera(radacina,0);
    cout<<endl;

    return 0;
}
