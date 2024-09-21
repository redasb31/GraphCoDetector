#include <iostream>
using namespace std;

int main(){
  int n, l;
  cin >> n;
  cin >> l;
  string str[n];
  string temp;
  for(int i = 0; i < n; i++) cin >> str[i];
  for(int i = 0; i < n; i++){
    for(int j = i + 1; j < n; j++){
      if(str[i].compare(str[j]) > 0){
	temp = str[i];
	str[i] = str[j];
	str[j] = temp;
      }
    }
  }
  for(int i = 0; i < n; i++) cout << str[i];
  cout << endl;
  return 0;
}