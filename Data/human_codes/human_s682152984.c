#include<iostream>
using namespace std;
int getCost(int w){
 int cost = 1150; // ?¬¬?????????
 for (int i = 11; i <= w; i++ ){
 if ( i <= 20 ) cost += 125; // ?¬¬?????????
 else if ( 30 < i ) cost += 160; // ?¬¬?????????
 else cost += 140; // ?¬¬?????????
 }
 return cost;}
int main(){
 for( int w; cin >> w && w >= 0; ) {
 cout << 4280 - getCost(w) << endl;
 }
 return 0;
}