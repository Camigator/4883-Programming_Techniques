#include <iostream>

using namespace std;

int main() 
{
  int start, x ,y;

  cin >> start;

  for(int i= 0; i< start ; i++)
  {
    cin >> x >> y;

    if ( x == 0 || y == 0 )
    {
      cout << "divisa" << endl;
    }
    else if ( x > 0 && y >0)
    {
      cout << "NE" << endl;
    }
    else if ( x < 0 && y >0)
    {
      cout << "NO" << endl;
    }
    else if ( x < 0 && y < 0)
    {
      cout << "SO" << endl;
    }
    else{
      cout << "SE" << endl;
    }
  }

} 
 
