#include <iostream>

using namespace std;

int main() {
  
  int start, f, s;

  cin >>  start;

  for( int i = 0; i < start ; i++)
  {
    cin >> f >> s;

    if (f > s)
    {
      cout << ">" << endl;
    }
    else if ( f < s)
    {
      cout << "<" << endl;
    }
    else{
      cout << "=" ;
    }
  }

}
