#include <stdio.h>
#include <string.h>
#include <math.h>


#define STORY_MAX 30
#define ELEVATOR_MAX 10
#define DESTROYED 
#define INPUTLINE_MAX 120
#define TIME_ERROR 0.001



int change_target(int device[STORY_MAX], int story);


struct ELEVATOR{
	int capacity;
	int speed;
	int rest;
	/*??¨??¬???????????¶???*/
	enum STATUS{GOHOME, PICKUP, STOP} status;
	double position;
	int weight;
	double next_action;
};
struct FIRE{
	int start;
	int burnout;
	int rise;
	int fall;
};



int main(int argc, char **argv)
{
	char inputline[INPUTLINE_MAX];
	/*??????????????°N*/
	int story;
	/*?????¨???????????¢*/
	int height;
	/*???????????¨????????????????????°*/
	int device[STORY_MAX];
	/*????????????*/
	int i;
	/*??¨??¬??????????????°*/
	int elevator_num;
	/*??¨??¬???????????¶???*/
	struct ELEVATOR elevator[ELEVATOR_MAX];
	/*?????¶???*/
	struct FIRE fire;
	/*??????*/
	double time;
	/*???????????????*/
	double step;
	/*????????????*/
	int target;
	/*??\?????¨*/
	char *tokpointer;
	/*???????????????????????????*/
	int rescued_device;
	/*???????????¶*/
	int carrier;
	
	/* ***???????????¶??\???*** */
	/*story, elevator*/
	fgets( inputline, sizeof( inputline ), stdin );
	sscanf( inputline, "%d%d", &story, &elevator_num );
	/*height*/
	fgets(inputline, sizeof( inputline ), stdin );
	sscanf(inputline, "%d", &height );
	/*device*/
	fgets(inputline, sizeof( inputline ), stdin );
	tokpointer = strtok(inputline, " ");
	sscanf( tokpointer, "%d", &device[0]);
	for(i = 1; i < story; i++){
		tokpointer = strtok( NULL, " "); 
		sscanf( tokpointer, "%d", &device[i]);
	}
	/*elevator*/
	for(i = 0; i < elevator_num; i++){
		fgets(inputline, sizeof(inputline), stdin);
		sscanf( inputline, "%d%d%d%lf", &elevator[i].capacity, &elevator[i].speed, &elevator[i].rest, &elevator[i].position );
	}
	/*fire*/
	fgets(inputline, sizeof(inputline), stdin);
	sscanf( tokpointer, "%d%d%d%d", &fire.start, &fire.burnout, &fire.rise, &fire.fall);
	
	
	/* ***?????´??¨?????????*** */
	fire.start--;
	time = 0;
	step = 0;
	rescued_device = device[0];
	device[0] = 0;
	target = change_target( device, story );
	for( i = 0; i < elevator_num; i++){
		elevator[i].status = PICKUP;
		elevator[i].weight = 0;
		elevator[i].position = (elevator[i].position - 1) * height;
		elevator[i].next_action = fabs( (target * height - elevator[i].position) / elevator[i].speed );
	}
	
	
	/* ***????????\??¬????????§???????§?*** */
	while(1){
		/*???????????¶*/
		if(target == 0){
			carrier = elevator_num;
			for(i = 0; i < elevator_num; i++){
				if(elevator[i].weight == 0){
					carrier--;
				}
			}
			if(carrier == 0)
				break;
		}
		/*?????????????¶???±*/
		for(i = 0; (fire.start + i) < story ; i++){
			if(time + step >= fire.burnout + i * fire.rise){
			device[fire.start+i] = 0;
			}
		}
		for(i = 1; fire.start - i > 0 ; i++){
			if(time + step >= fire. burnout + i * fire.fall){
				device[fire.start-i] = 0;
			}
		}
		/*??????????????¨???????????????????????????*/
		for(i = 0; i < elevator_num; i++){
			if(elevator[i].next_action < TIME_ERROR){
				switch(elevator[i].status){
					case GOHOME:
						elevator[i].status = STOP;
						elevator[i].next_action = elevator[i].rest;
						rescued_device += elevator[i].weight;
						elevator[i].weight = 0;
						break;
					case STOP:
						if(target == 0 || elevator[i].weight >= elevator[i].capacity){
							elevator[i].status = GOHOME;
							elevator[i].next_action = elevator[i].position / elevator[i].speed;
						}else{
							elevator[i].status = PICKUP;
							elevator[i].next_action = fabs((target * height - elevator[i].position) / elevator[i].speed);
						}
						break;
					case PICKUP:
						/*??????????????????*/
						if( (elevator[i].weight + device[target]) <= elevator[i].capacity ){
							elevator[i].weight += device[target];
							device[target] = 0;
						}else{
							device[target] -= (elevator[i].capacity - elevator[i].weight);
							elevator[i].weight = elevator[i].capacity;
						}
						elevator[i].status = STOP;
						elevator[i].next_action = elevator[i].rest;
						target = change_target(device, story);
						break;
				}
			}
			/*??????????±????*/
			if(i == 0 || step > elevator[i].next_action){
				step = elevator[i].next_action;
			}
		}
		/*??¨??¬?????????????§????*/
		for(i =0; i < elevator_num; i++){
			elevator[i].next_action -= step;
			switch(elevator[i].status){
				case GOHOME:
					elevator[i].position -= elevator[i].speed * step;
					break;
				case STOP:
					break;
				case PICKUP:
					if(target * height > elevator[i].position){
						elevator[i].position += elevator[i].speed * step;
					}else{
						elevator[i].position -= elevator[i].speed * step;
					}
					break;
			}
		}
		/*????????????*/
		time += step;
		
	}
	
	/*????????????*/
	printf("%d %.3f\n", rescued_device, time);
	return 0;

}



int change_target(int device[], int story)
{
	int i;
	int target = 0;
	
	for(i = 0; i < story; i++){
		if(device[i] > 0){
			target = i;
		}
	}
	return target;
}