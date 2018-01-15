//Cirlan Ana MAria
#include<iostream>
using namespace std;
typedef struct termen {
                struct termen *next;
                int info;
                } element;
typedef struct
              {
               element *start,*current,*finalist;
               int length;
              } lista;
lista *L;
int isempty( lista *L)
{return (L->length==0);}
int show_me(lista *L)
{ cout<<endl;
if (!isempty(L))     {element *carrier;
                     carrier=L->start;
                     while (carrier!=NULL) { cout<<carrier->info<" ";
                                             carrier=carrier->next;}
                     return 1;}
                     cout<<"Empty list.";
return 0;}
lista *add(lista *L,int value)
{if (isempty(L))  {
                    element *new_one=new element;
                    if (new_one!=NULL)
                       {
                        new_one->info=value;
                        new_one->next=NULL;
                        L->length=1;
                        L->start=L->current=L->finalist=new_one;
                       }
                    return L;
                  }
element *new_one=new element;
if (new_one!=NULL) { new_one->info=value;
                     new_one->next=NULL;
                     L->length++;
                     L->finalist->next=new_one;
                     L->finalist=new_one;
                  }
return L;
}

lista *serve(lista *L,int *old)
{
    if(isempty(L))
    {
        return L;
    }
    else
    {
        *old=L->finalist->info;
        if (L->length==1) { delete L->current;
                    L->start=L->current=L->finalist=NULL;
                    L->length--;
                    return L;}
element *carrier=L->start;
while (carrier->next!=L->finalist) { carrier=carrier->next;}
carrier->next=NULL;
delete L->finalist;
L->finalist=carrier;
L->current=carrier;
L->length--;
return L;
    }


}

lista *initlist()
{lista *result=new lista;
if (result!=NULL) {
                    result->length=0;
                    result->start=result->current=result->finalist=NULL;
                  }
return result;}


int main()
{
L=initlist();
int topvalue;
cout<<" Build stack : ";
for(int i=1;i<=10;i++) L=add(L,i);
show_me(L);
cout<<endl<<" Decrease stack :";
while (L->start!=NULL)
{L=serve(L,&topvalue);
 cout<<endl<<" Picked "<<topvalue<<endl<<"Generated : ";
 show_me(L);}
}
