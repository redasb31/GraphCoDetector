#include<stdio.h>
#include<memory.h>
int M,N,D;
int P[101][4][21][21];
int S[21][21];
int C[4][21][21];
int J[4][21][21];
void set_road(int A[][21][21],char h1,int v1,char h2,int v2,int d){
	if(v1==v2){//ìkûü
		if(h1<h2){//(h1,v1)ªk¤
			A[1][v1][h1-'a'+1]=d;
			A[3][v2][h2-'a'+1]=d;
		}else{//(h1,v1)ªì¤
			A[3][v1][h1-'a'+1]=d;
			A[1][v2][h2-'a'+1]=d;
		}
	}else{//¼ûü
		if(v1<v2){//(h1,v1)ª¼¤
			A[0][v1][h1-'a'+1]=d;
			A[2][v2][h2-'a'+1]=d;
		}else{//(h1,v1)ª¤
			A[2][v1][h1-'a'+1]=d;
			A[0][v2][h2-'a'+1]=d;
		}
	}
}
int signal_to_be_blue(int T,int d,int x,int y){//TÈ~ÅdûüÌMªÂÉÈéðßé
	int t;
	if(S[x][y]){//Mª éê
		t=T/S[x][y];//»ÝÌØèÖíètF[Y
		if(t%2==d%2)//ôïª¯¶Æ«ÍÔtF[YÈÌÅAtF[YÜÅÒÂ
			t++;
		t*=S[x][y];//PÊÖ
		if(t<T)
			t=T;//ùÉÂ¾Á½Æ«Ít<TÉÈéÌÅA»ÝÉ·é
		return t;
	}else{//MªÈ¢ê
		return T;
	}
}
int is_blue(int T,int d,int x,int y){
	if(S[x][y]){
		return T/S[x][y]%2!=d%2;
	}
	return 1;
}
int main(){
	char h1,h2;
	int i,n,v1,v2,k;
	int xs,ys,xg,yg,T;
	int d,x,y;
	for(;scanf("%d%d%d%d",&M,&N,&D,&n),M;){
		memset(P,0,sizeof(P));
		memset(S,0,sizeof(S));
		memset(C,0,sizeof(C));
		memset(J,0,sizeof(J));
		//Mîñ
		for(i=0;i<n;i++){
			scanf("\n%c-%d%d",&h1,&v1,&k);
			S[v1][h1-'a'+1]=k;
		}
		//Hîñ
		scanf("%d",&n);
		for(i=0;i<n;i++){
			scanf("\n%c-%d %c-%d",&h1,&v1,&h2,&v2);
			set_road(C,h1,v1,h2,v2,1);
		}
		//aØîñ
		scanf("%d",&n);
		for(i=0;i<n;i++){
			scanf("\n%c-%d %c-%d%d",&h1,&v1,&h2,&v2,&k);
			set_road(J,h1,v1,h2,v2,k);
		}
		//n_I_
		scanf("\n%c-%d %c-%d",&h1,&v1,&h2,&v2);
		xs=v1;ys=h1-'a'+1;
		xg=v2;yg=h2-'a'+1;
#if 0
		//fobOp\¦
		{
			printf("size=(%d,%d) D=%d\n",N,M,D);
			for(y=1;y<=M;y++){//S
				for(x=1;x<=N;x++)
					printf("%3d",S[x][y]);
				puts("");
			}
			for(d=0;d<4;d++){
				printf("d=%d\n",d);
				for(y=1;y<=M;y++){
					for(x=1;x<=N;x++)//C
						printf("%3d",C[d][x][y]);
					printf("   ");
					for(x=1;x<=N;x++)//J
						printf("%3d",J[d][x][y]);
					puts("");
				}
			}
		}
#endif
		//úóÔ
#if 1
		P[0][0][xs][ys]=1;
#else
		{
			int t;
			t=D+J[0][xs][ys];
			P[t][0][xs+1][ys]=1;
		}
#endif
		//óÔJÚ
		for(T=0;;T++){
			for(d=0;d<4;d++){
				if(P[T][d][xg][yg]){
					printf("%d\n",T);
					goto done;
				}
				for(x=1;x<=N;x++){
					for(y=1;y<=M;y++){
						if(P[T][d][x][y]){
							int d1;
							for(d1=0;d1<4;d1++){
								if(d1!=(d^2)){//dÌ½ÎûüÍ­
									if(!C[d1][x][y]){
										if(is_blue(T,d,x,y)){
											int t1;
											t1=T+D+J[d1][x][y];
											if(t1<=100){
												int vx,vy;
												vx=d1==0?1:d1==2?-1:0;
												vy=d1==1?1:d1==3?-1:0;
												if(x+vx>=1&&x+vx<=N&&y+vy>=1&&y+vy<=M){
													P[t1][d1][x+vx][y+vy]=1;
													//printf("(%d,%d,%d,%d) -> (%d+%d+%d=%d,%d,%d,%d)\n",T,d,x,y,T,D,J[d1][x][y],t1,d1,x+vx,y+vy);
												}
											}
										}else{
											//printf("(%d,%d,%d,%d) -> red\n",T,d,x,y);
										}
									}
/*
									if(!C[d1][x][y]){
										int ts,t1;
										ts=signal_to_be_blue(T,d,x,y);
										t1=ts+D+J[d1][x][y];
										if(t1<=100){
											int vx,vy;
											vx=d1==0?1:d1==2?-1:0;
											vy=d1==1?1:d1==3?-1:0;
											if(x+vx>=1&&x+vx<=N&&y+vy>=1&&y+vy<=M){
												P[t1][d1][x+vx][y+vy]=1;
												printf("(%d,%d,%d,%d) -> (%d+%d+%d=%d,%d,%d,%d)\n",T,d,x,y,ts,D,J[d1][x][y],t1,d1,x+vx,y+vy);
											}
										}
									}
									*/
								}
							}
						}
					}
				}
			}
		}
done:;
	}
	return 0;
}