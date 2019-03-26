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

/* exemplu
11 33 60
88 44 56 65 33 38 36 40 25 28 30
*/

void afisare(nod *radacina, int k1, int k2)
{   if(!radacina)return;///daca nu exista nodul iesim
    if(radacina->info >k1 && radacina ->info<k2)///daca nodul este atunci afisam si ii facem si fiii, chiar daca sunt NULL deoarece instructiunea de mai sus va da return inainte sa afisam
      {
          cout<<radacina->info<<" ";
           afisare(radacina->st,k1,k2);
           afisare(radacina->dr,k1,k2);
      }
}

void cautare(nod *radacina, int k1, int k2)///cautam primul nod care apartine intervalului deoarece stim ca de la el va incepe un subarbore care apartine intervalului
{

    while(radacina &&  !(radacina->info>k1 && radacina ->info<k2) )///cat timp nodul poate exista si nu apartine intervalului continuam cautarea
     if(radacina->info>k2)radacina=radacina->st;///daca este >k2 cautam in subarborele drept
     else radacina=radacina->dr;///daca nu este <k2 atunci sigur este <k1 pt ca altfel nu ar fi intrat in while

    if(!radacina)cout<<"NU EXISTA NUMERE CUPRINSE IN INTERVALUL CERUT";
    else
         afisare(radacina,k1,k2);

}

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
    /*

    11
    88 44 56 65 33 38 36 40 25 28 30
*/
    cautare(radacina,7,22);

    return 0;
}
