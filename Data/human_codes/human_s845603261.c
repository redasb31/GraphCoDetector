//
//  main.c
//  You Are the Judge
//
//  Created by x15071xx on 2016/06/15.
//  Copyright ?? 2016??´ AIT. All rights reserved.
//

#include <stdio.h>
#include <string.h>

void swap (int array[50][4],int j,int soezi){
    int tmp;
    
    tmp=array[j][soezi];
    array[j][soezi] = array[j-1][soezi];
    array[j-1][soezi] = tmp;
    
}

int main(int argc, const char * argv[]) {
    
    int i,j,k,l;
    while (1) {
        int team[50][4] = {0};//0.??????????????? 1.???????????????????????£???2,??£?????° 3,??????
        int team_wrong[50][10] = {0};
        int t,p,r;
        int tid,pid,time;
        char message[8]={0};
        scanf("%d %d %d",&t,&p,&r);
        if (t==0&&p==0&&r==0) {
            break;
        }
        for (i=0; i<t; i++) {
            team[i][0] = i+1;
        }
        
        for (i=0; i<r; i++) {
            
            scanf("%d %d %d",&tid,&pid,&time);
            scanf("%s",message);
            
            if (strcmp(message, "CORRECT") == 0) {
                //o
                team[tid-1][2]++;
                
                team[tid-1][1] += (team_wrong[tid-1][pid-1] * 1200) + time;
            } else {
                //x
                team_wrong[tid-1][pid-1]++;
            }
        }
        
        //????????????
        
        //????????°?????????????????£?????°?????????
        for (i=0; i<t-1; i++) {
            for (j=t-1; j>i; j--) {
                if (team[j][2] > team[j-1][2]) {
                    swap(team,j,2);
                    swap(team,j,0);
                    swap(team,j,1);
                    swap(team,j,3);
                }
            }
        }
        
        //????????°??§???????????????
        for (i=0; i<t; i++) {
            if (team[i][2] != team[i+1][2]) {
                for (j=i+1; j<t; j++) {
                team[j][3]++;
                }
            }
        }
        
        //????????§?????????
        for (i=0; i<t-1; i++) {
            j=0;
            while (team[i+j][3] == team[i+j+1][3]) {
                j++;
            }
            
            for (k=0; k<i+j; k++) {
                for (l=i+j; l>k; l--) {
                    if ((team[l][1] < team[l-1][1]) && (team[l][3] == team[l-1][3])) {
                        swap(team,l,2);
                        swap(team,l,0);
                        swap(team,l,1);
                        swap(team,l,3);
                    }
                }
            }
        }
        
        for (i=0; i<t; i++) {
            printf("%d %d %d\n",team[i][0],team[i][2],team[i][1]);
        }
    }
    return 0;
}