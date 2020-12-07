/************************************
/ 
/ Cameron O'Neal
/ UVA judge 10226 Hardwood Species
/ Programming Techniques
/
*************************************/
#include <iostream>
#include <bits/stdc++.h>
#include <string>
using namespace std;

int main()
{
    int n;
    map<string, int> HardWoodBaby;
    char s[35];

    scanf("%d\n\n", &n);
    while (n--)
    {
        int total = 0;
        while (gets(s))
        {
            if (strlen(s) == 0)
                break;
            HardWoodBaby[string(s)]++;
            total++;
        }

        map<string, int>::iterator it;
        for (it = HardWoodBaby.begin(); it != HardWoodBaby.end(); it++)
        {
            printf("%s %.4lf\n", (*it).first.data(),(double) (*it).second / (double) total * 100.0);
        }
        if (n > 0)
        {
            printf("\n");
            HardWoodBaby.clear();
        }
    }

    return 0;
}
