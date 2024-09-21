#include<bits/stdc++.h>
using namespace std;

long long oddsum,evensum,bil,oddmin,evenmin,arr[200001];
int n;

int main(){
	cin>>n;
	oddmin = 99999999999;
	evenmin = 99999999999;
	for(int i = 1;i <= n;i ++){
		cin>>bil;
		arr[i] = bil;
		if(i % 2 == 1){
			oddsum = oddsum + bil;
			if(oddmin > bil){
				oddmin = bil;
			}
		}else{
			evensum = evensum + bil;
			if(evenmin > bil){
				evenmin = bil;
			}
		}
	}
	if(n % 2 == 0){
		cout<<max(oddsum,evensum)<<endl;
	}else{
		cout<<max((oddsum,evensum),(oddsum - oddmin,evensum - evenmin))<<endl;
	}
}
