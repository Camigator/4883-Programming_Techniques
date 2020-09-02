#include <iostream>

using namespace std;

int main() 
{
  int start, p1 ,p2 ,p3;

  cin >> start;

  for(int i= 1; i <= start ; i++)
  {
    
    cin >> p1 >> p2 >> p3;

    if ((p2 < p1 && p1 < p3) || (p2 > p1 && p1 > p3))
    {
      cout << "case " << i << ": " << p1 << endl;
    }
    else  if ((p1 < p2 && p2 < p3) || (p1 > p2 && p2 > p3))
    {
      cout << "case " << i << ": " << p2 << endl;
    }
    else
    {
      cout << "case " << i << ": " << p3 << endl;
    }

  }

} 
