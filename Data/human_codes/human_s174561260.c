#inculde <stdio.h>
int main(){
  int n,t,i,ans=0,time=0;
  scanf("%d %d",&n,&t);
  int str[n];
  scanf("%d",str[0]);
  time=str[0];
  for(i=1;i<n-1;i++){
  	scanf("%d",&str[i]);
  	if(time + t >str[i] ){
    	ans=ans+(time + t - str[i]);
      	time=str[i];
    }else{
      time=str[i];
      ans+=t;
    }
    ans+=t;
    printf("%d\n",ans);
  }
return 0;
}