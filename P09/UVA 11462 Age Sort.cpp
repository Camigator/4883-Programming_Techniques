/************************************
/ 
/ Cameron O'Neal
/ UVA judge 11462 Age sort
/ Programming Techniques
/
*************************************/


#include <iostream>
#include<stdio.h>
#include<algorithm>
using namespace std;

int main()
{
    int PersonsAge[200],p,i;
    freopen("input.txt","r",stdin);
    scanf("%d",&p);
    while(p!=0)
        {
            for(i=0;i<p;i++)
				scanf("%d",&PersonsAge[i]);
			
			//Sorts the elements in the range [first,last) into ascending order.
            sort(PersonsAge,PersonsAge+p);
            for(i=0;i<p-1;i++)
				printf("%d ",PersonsAge[i]);
			
            printf("%d\n",PersonsAge[p-1]);
            scanf("%d",&p);
        }

    return 0;
}