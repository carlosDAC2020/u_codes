#include <iostream>
using namespace std;
const int n=500;


int main() {
  int n,i,acum;
  n=8;
  i=1;
  acum=0;
  while(i<=n){
  	acum+=i;
  	i+=1;
  }
  cout<<acum;

  return 0;
}
