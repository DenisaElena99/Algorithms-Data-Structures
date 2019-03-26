#include <fstream>

using namespace std;

ifstream cin("radix.in");
ofstream cout("radix.out");

void countSort(int bits, int v[], int n)
{
  int output[n],ct[16]={0};
  ///alegem galeata sa fie si perechi de cate 4 pentru eficienta

  for(int i=0;i<n;++i)
  ++ct[(v[i]>>bits)&15];///scapam de ultimii "bits" biti si ii luam pe cei 4 biti ramasi


  for(int i=1;i<=15;++i)///pentru fiecare rest de 4 biti
  ct[i]+=ct[i-1];

  for(int i=n-1;i>=0;--i)///luam de la final
  {output[ ct[(v[i]>>bits)&15]-1 ]=v[i];
   --ct[(v[i]>>bits)&15];
  }

  for(int i=n-1;i>=0;--i)
  v[i]=output[i];

}

void radix(int v[],int n)
{
    int bits=0,maxim=-1e9;///initial nu shiftam niciun bit in dreapta

    for(int i=0;i<n;++i)
      if(maxim<v[i])maxim=v[i];

    while((1<<bits)<maxim)///cati biti scoatem sa nu treaca de maxim

    countSort(bits,v,n),bits+=4;


}

int main()
{
    int n,v[10001];
    cin>>n;
    for(int i=0;i<n;++i)cin>>v[i];

    radix(v,n);

    for(int i=0;i<n;++i)cout<<v[i]<<" ";
    return 0;
}
