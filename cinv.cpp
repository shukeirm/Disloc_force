#include <iostream>
#include <iterator>
#include <algorithm>
#include <vector>
using namespace std;

int main()
{
  //   int i;
  //   vector<int> v(3);

  //   cout << "Enter 5 integers: \n";
  
  //   istream_iterator<int> int_itr(cin);
  //   copy(int_itr, istream_iterator<int>(), v.begin());

  //   cout << "Here are the values you entered: ";
  //   for(i = 0; i <v.size(); i++) cout << v[ i ] << " ";

  //   return 0;
  // }

  int n=3;
  int myint;
  // vector<int> v(n);

  // cout << "Please enter three integers:\n";
  // for ( int i=0; i<n; ++i )
  //   {
  //     cin >> myint;
  //     v.push_back (myint);  
  //   }

  
  //  cout << "burgers vector= " << v << " numbers.\n";

  int v[n];
  cout << "Please enter three integers:\n";
  
  for ( int i=0; i<n; ++i )
    {
      cin >> v[i];  
    }
  
  cout << "burgers vector= " << v[0] << " " << v[1] << " " << v[2] << endl;
  return 0;
}
