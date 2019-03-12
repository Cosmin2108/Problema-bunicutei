/*
Bunicuta vrea sa faca prajituri. Pentru aceasta ea are la dispozitie n forme de copt. Formele de copt
sunt niste obiecte tridimensionale care au la baza patru categorii de figuri geometrice plane:
1. cerc - determinat de raza
2. dreptunghi - determinat de latura mica si latura mare
3. patrat - determinat de latura
4. triunghi dreptunghic - determinat de cateta mica si cateta mare.
Pe langa baza, formele de copt au si o inaltime (h).
Bunicuta intentioneaza sa umple toate formele de copt in interior cu gem iar dupa coacere doreste sa
le unga pe intreaga suprafata exterioara cu frisca. Conform retetei, bunicuta foloseste 2 grame de gem
pentru fiecare centimetru cub de prajitura umplut si 1 gram de frisca
pentru fiecare centimetru patrat de prajitura uns.
Scrieti un program care sa o ajute pe Bunicuta sa determine cantitatile necesare de gem si frisca
astfel:
Bunicuta va putea adauga o forma de copt (Comanda ADD) caz in care:
- Se citeste pentru forma tipul bazei ei (cerc, dreptunghi, patrat, triunghi)
- Se citesc apoi caracteristicele bazei
- Se citeste apoi inaltimea formei de copt (h)
- Inainte de a trece la urmatoarea comanda se afiseaza cantitatile de gem si frisca necesare pentru
aceasta.
Bunicuta va putea elimina a x-a forma de copt (Comanda REMOVE x) existenta in ordinea introducerii
(numerotarea incepe de la 1).
Bunicuta va putea afisa caracteristicile tuturor prajiturilor existente (forma bazei, caracteristicile
bazei si inaltimea) - comanda STOC.
Bunicuta va putea afisa necesarul curent total al fiecarui ingredient (gem, frisca) (comanda TOTAL).
Programul se incheie prin comanda STOP.*/

#include <stdio.h>
#include <stdlib.h>
#include<string.h>
#include<math.h>
#include<windows.h>




struct forme
{
     char baza[15];
    int h;

struct cerc{
    int r;

}c;

struct dreptunghi{

int l,L;
}d;

struct patrat{
    int l;

}p;

struct triunghi{
int c1,c2;

}t;



};
struct forme v[100];

void ADD (int i  )
{

printf("baza=");
scanf("%s",v[i].baza);
  if( strcmp(v[i].baza,"cerc")==0)
  {    printf("raza=");
        scanf("%d",&v[i].c.r);}
        else
        if( strcmp(v[i].baza,"dreptunghi")==0)
        {
          printf( " latime=\n lungime=\n");
          scanf("%d%d",&v[i].d.l,&v[i].d.L); }
         else
            if(strcmp(v[i].baza,"patrat")==0)
            { printf("latura=");
             scanf("%d",&v[i].p.l); }
             else
        {    printf("cateta1=\n cateta2=\n");
             scanf("%d%d", &v[i].t.c1, &v[i].t.c2); }

printf("h="); /// inaltimea formei prajiturii
scanf("%d",&v[i].h);

}

int CANTITATI_GEM (int i)
{ int x;
    if(strcmp(v[i].baza,"cerc")==0)
   x= (int)2*3.14*pow(v[i].c.r,2)*v[i].h;
    else
        if( strcmp(v[i].baza, "triunghi")==0)
          x=2*v[i].t.c1*v[i].t.c2/2*v[i].h;
        else
             if( strcmp(v[i].baza, "patrat")==0)
             x= 2*pow(v[i].p.l,2)*v[i].h;
            else
                x=2*v[i].d.l*v[i].d.L*v[i].h;

return x;
}

int CANTITATI_FRISCA (int i)
{   int x;
    if(strcmp(v[i].baza,"cerc")==0)
    x= (int)3.14*pow(v[i].c.r,2)+ 2*3.14*v[i].c.r*v[i].h ;
     else
        if( strcmp(v[i].baza, "triunghi")==0)
          x=v[i].t.c1*v[i].t.c2/2+v[i].h*(v[i].t.c1+v[i].t.c2+ sqrt( pow(v[i].t.c1,2)+pow(v[i].t.c2,2)));
        else
             if( strcmp(v[i].baza, "patrat")==0)
             x= 4*v[i].p.l*v[i].h+ pow(v[i].p.l,2);
            else
                x=2*v[i].h*(v[i].d.l+v[i].d.L)+v[i].d.l*v[i].d.L;

  return x;
}

void STOC (int n) ///afiseaza caracteristicile tuturor formelor ( tip baza, dimensiuni, inaltime)
{
    for(int i=0;i<n;i++)
    {
    if(strcmp(v[i].baza,"cerc")==0)
        printf("Forma prejitura%d:%s\nRaza prajitura:%d\nInaltime prajitura:%d\n",i,v[i].baza,v[i].c.r,v[i].h);
     else
        if( strcmp(v[i].baza, "triunghi")==0)
         printf("Forma prejitura%d:%s\nCateta1 prajitura:%d\nCateta2 prajitura:%d\nInaltime prajitura:%d\n",i,v[i].baza,v[i].t.c1,v[i].t.c2,v[i].h);
        else
             if( strcmp(v[i].baza, "patrat")==0)
             printf("Forma prejitura%d:%s\nLatura prajitura:%d\nInaltime prajitura:%d\n",i,v[i].baza,v[i].p.l,v[i].h);
            else
                 printf("Forma prejitura%d:%s\nLatime prajitura:%d\nLungime prajitura:%d\nInaltime prajitura:%d\n",i,v[i].baza,v[i].d.l,v[i].d.L,v[i].h);
    }
}

void STOP ( int n) ///opreste programul si afiseaza cantitatea de gem si frisca necesare
{  int s1=0,s2=0,i;
    for(i=0;i<n;i++)
    {  s1+= CANTITATI_GEM(i);
       s2+= CANTITATI_FRISCA(i);
       }
       printf("Cantitatea totala necesara de gem este %d grame\n",s1);
        printf("Cantitatea totala necesara de frisca este %d grame\n",s2);
}

int main()
{ int i,n;
 char s[37];

   n=0;
   while( printf("Comanda:")&&scanf("%s",s))
   {
       if( strcmp(s,"ADD")==0)
        {  ADD(n);
         printf( "Bunica foloseste %d grame gem pentru a %d-a prajitura\n", CANTITATI_GEM(n),n);
      printf( "Bunica foloseste %d grame frisca pentru a %d-a prajitura\n", CANTITATI_FRISCA(n),n);

     /* Sleep(1400); /// ramane afisat cateva secunde pana la stergere
      system("cls"); ///sterge ecran */
       n++;
        }
        else
        if( strcmp(s,"STOC")==0)
            {  STOC(n);
               Sleep(10000);
               system("cls");
            }
         else
            if( strcmp(s,"STOP")==0)
             {
                 STOP(n); return 0;
             }


   }
    return 0;
}

