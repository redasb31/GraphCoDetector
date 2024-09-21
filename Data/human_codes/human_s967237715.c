#include<stdio.h>

#define MAX_CRY_NUM 1000

int main(){
    int crystal_num, crystal_num_org;
    int hero_x, hero_y;
    int mao_x, mao_y;
    int temp_x, temp_y;
    int i;
    int crystal_x[MAX_CRY_NUM];
    int crystal_y[MAX_CRY_NUM];
    char check_need_flg[MAX_CRY_NUM];
    unsigned long min, dist, total_hero_dist, mao_dist;


    while(1){
        /* initiallize */
        total_hero_dist = 0;
        for(i = 0; i < MAX_CRY_NUM; i++){
            check_need_flg[i] = 0;
        }

        /* get num of crystal */
        scanf("%d", &crystal_num);
        
        /* get addr of hero */
        scanf("%d", &hero_x);
        scanf("%d", &hero_y);
        
        /* get addr of mao */
        scanf("%d", &mao_x);
        scanf("%d", &mao_y);
        
        /* end condition */
        if((crystal_num == 0) && (hero_x == 0) && (hero_y == 0) && (mao_x == 0) && (mao_y == 0)){
            break;
        }

        /* get addr of crystal */
        for(i = 0; i < crystal_num; i++){
            scanf("%d", &crystal_x[i]);
            scanf("%d", &crystal_y[i]);
            check_need_flg[i] = 1;
        }

        crystal_num_org = crystal_num;

        /*  */
        while(1){
            min = 0xFFFFFFFF;
            for(i = 0; i < crystal_num_org; i++){
                if(check_need_flg[i] == 1){
                    dist = ((crystal_x[i] - hero_x) ^ 2) + ((crystal_y[i] - hero_y) ^ 2);
                    if(min > dist){
                        min = dist;
                        temp_x = crystal_x[i];
                        temp_y = crystal_y[i];
                    }
                }
            }
            hero_x = temp_x;
            hero_y = temp_y;
            total_hero_dist += min;

            crystal_num--;
            if(crystal_num == 0){
                break;
            }
            
        }

        /* calc mao dist to last hero point */
        mao_dist = ((mao_x - hero_x) ^ 2) + ((mao_y - hero_y) ^ 2);

        if(total_hero_dist < mao_dist){
            /* output No if hero is in mao area */
            printf("No\n");
        }
        else{
            /* output Yes if hero is out of mao area */
            printf("Yes\n");
        }
    }

    return 0;
}