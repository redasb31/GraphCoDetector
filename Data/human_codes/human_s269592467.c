/* #include <iostream> */
/* using namespace std; */
#include <stdio.h>

typedef struct {
  int fst, snd;
} tuple;

int main() {
  int i,j,k,n,m,score;
  char c;
  tuple gems[20], robot, prog;
  
  while(1) {
    scanf("%d", &n); if(n==0) break;
    for(i=0;i<n;i++)
      scanf("%d %d", &gems[i].fst, &gems[i].snd);

    robot.fst = 10; robot.snd = 10; score = 0;
    
    scanf("%d", &m);
    for(i=0;i<m;i++){
      /* cin >> c >> prog.snd; */
      scanf("%*c%c %d", &c, &prog.snd);
      prog.fst = (int)(c);

      for(k=0;k<prog.snd;k++){
	switch(prog.fst) {
	case 'N': robot.snd++; break;
	case 'E': robot.fst++; break;
	case 'S': robot.snd--; break;
	case 'W': robot.fst--; break;
	default : printf("error!\n");
	}
	for(j=0;j<n;j++) if(robot.fst==gems[j].fst && robot.snd==gems[j].snd) score++;
      }
    }
    if(score==n)
      printf("Yes\n");
    else
      printf("No\n");
  }

  return 0;
}