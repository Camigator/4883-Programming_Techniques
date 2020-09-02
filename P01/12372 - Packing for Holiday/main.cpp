#include <iostream>

using namespace std;

int main() 
{
  int start, H, L ,W;

  cin >> start;

  for(int i= 1; i <= start ; i++)
  {
    cin >> L >> W >> H ;

    if ( L > 20 || W > 20 || H > 20)
    {
      cout << "case " << i << ": bad" << endl; 
    }
    else 
      cout << "case " << i << ": good" << endl;    

  }

} 
 
    
