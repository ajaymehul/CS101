#include <iostream>
using namespace std;
#include "dList.cpp"
#include <string.h>
#define SMALL 200
#define MAX 50
#define ROUNDS 1000

dList *temp;
int x[MAX],i;
char ch[MAX];




void swap(char *x, char *y)
{
    char temp;
    temp = *x;
    *x = *y;
    *y = temp;
}

node* test_run(char,node*);
void permute(char *a, int l, int r)
{
    int i;
    if (l == r){
        temp = new dList(x,ch, MAX);
        node* p=NULL;
        for(int i=0;i<8;i++){
        p=test_run(a[i],p);
        }
        
        delete temp;
        }
    else
    {
        for (i = l; i <= r; i++)
        {
            swap((a+l), (a+i));
            permute(a, l+1, r);
            swap((a+l), (a+i)); //backtrack
        }
    }
}

node* test_run( char a, node* b){
switch(a){
case 'A': temp->addFront(51,'z'); break;
case 'B': temp->addBack(52, 'j'); break;
case 'C': return temp->search(2); break;
case 'D': temp->find('a');break;
case 'E': temp->sort();break;
case 'F': if(b!=NULL){temp->moveBack(b);} break;
case 'G': if(b!=NULL){temp->moveFront(b);} break;
case 'H': temp->out(10);break;
case 'I': temp->out(10,'b'); break;
}
if(b!=NULL)return b;
else return NULL;

}


int main(){
char seq[] = "ABCDEFGHI";
for(i=0;i<MAX;i++){x[i] = i; ch[i] = 'a'+ (i%26);}

for(int j=0;j<ROUNDS;j++){
    permute(seq,0,7);
    
    cout<<"DONEONEOENOENE"<<endl;
    strcpy(seq, "ABCDEFGHI");
    }


return 0;
}
