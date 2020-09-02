#include <iostream>
#include <string>

using namespace std;

int main() 
{
  int start, amount , total = 0;
  string word;

  cin >> start;

  for(int i= 1; i <= start ; i++)
  {
   cin >> word;
   if (word == "report")
   {
     cout << total;
   }   
   else if (word == "donate")
   {
     cin >> amount;
     total += amount;
   }

  }

} 
 
