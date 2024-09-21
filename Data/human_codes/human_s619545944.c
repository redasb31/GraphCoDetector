x;
char s[20];
d(int l,int r,int k){
    x=abs(s[l]-s[r]);
    return l<0||!s[r]?k:x&&x<3?d(l-1,r+1,k+2):fmax(d(l-1,r,k),d(l,r+1,k));
}
  
int main(){ 
    scanf("%s",s);
    x=strchr(s,'i')-s;
    printf("%d\n",d(x-1,x+3,3));
}