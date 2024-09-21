#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <float.h>

struct node{
	double x;
	double y;
};

struct node a, b, c, c_in;
struct node a_mid, b_mid, c_mid;
int debug=0;

void solve(double a, double b, double c, double d, double e, double f){
	double ratio;
	double x, y;

	ratio = 1 /(a*e - b*d);
	x = ratio * (e * c + -1 * b * f);
	y = ratio * (-1 * d * c + a * f);
	if(fabs(x) < 0.001){
		x = 0;
	}
	if(fabs(y) < 0.001){
		y = 0;
	}

	printf("%.3f %.3f ", x, y);
	return ;
}

int main(void){
	int i, n;
	double a_len, b_len, c_len;
	double tmp, s;
	double sin_a, sin_b, sin_c;
	double cos_a, cos_b, cos_c;
	double sin_2a, sin_2b, sin_2c;
	double r;

	int i_tmp; //for round off

	scanf("%d", &n);

	for(i=0;i<n;i++){
		scanf("%lf %lf %lf %lf %lf %lf", 
			&(a.x), &(a.y), &(b.x), &(b.y), &(c.x), &(c.y));

		//calc a,b,c
		a_len = sqrt(pow(b.x - c.x, 2) + pow(b.y - c.y, 2));
		if(debug) printf("a:length %.3f\n", a_len);
		b_len = sqrt(pow(a.x - c.x, 2) + pow(a.y - c.y, 2));
		if(debug) printf("b:length %.3f\n", b_len);
		c_len = sqrt(pow(b.x - a.x, 2) + pow(b.y - a.y, 2));
		if(debug) printf("c:length %.3f\n", c_len);

		//heron
		tmp = 0.5 * (a_len + b_len + c_len);
		s = sqrt(tmp * (tmp - a_len) * (tmp - b_len) * (tmp - c_len));

		//calc sin A B C
		sin_a = (2 * s) / (b_len * c_len);
		sin_b = (2 * s) / (a_len * c_len);
		sin_c = (2 * s) / (a_len * b_len);

		cos_a = sqrt(1 - sin_a * sin_a);
		cos_b = sqrt(1 - sin_b * sin_b);
		cos_c = sqrt(1 - sin_c * sin_c);

		sin_2a = 2 * sin_a * cos_a;
		sin_2b = 2 * sin_b * cos_b;
		sin_2c = 2 * sin_c * cos_c;

		//ツ外ツ心ツづーツ仰づ淞づゥ
		c_in.x = (a.x * sin_2a + b.x * sin_2b + c.x * sin_2c) / (sin_2a + sin_2b + sin_2c);
		c_in.y = (a.y * sin_2a + b.y * sin_2b + c.y * sin_2c) / (sin_2a + sin_2b + sin_2c);

		//calc Radius
		r = (a_len / sin_a) * 0.5;
		if(debug) printf("radius = %.3f\n", r);

		//round off
		c_in.x = c_in.x * pow(10, 3); //2ツ個湘」ツつーツづゥ
		c_in.x = (double)(int)(c_in.x + 0.5);
		c_in.x = c_in.x * pow(10, -3);

		c_in.y = c_in.y * pow(10, 3); //2ツ個湘」ツつーツづゥ
		c_in.y = (double)(int)(c_in.y + 0.5);
		c_in.y = c_in.y * pow(10, -3);

		r = r * pow(10, 3); //2ツ個湘」ツつーツづゥ
		r = (double)(int)(r + 0.5);
		r = r * pow(10, -3);

		printf("%.3f %.3f %.3f\n", c_in.x, c_in.y, r);
		/*
		//bツづ個傾ツつォツづ陳点
		if(c.y == a.y ){	
			b_angle = HUGE_VAL;
		}else if(c.x == a.x){
			b_angle = 0;
		}else{
			b_angle = -1 / ((c.y - a.y) / (c.x - a.x));
		}
		b_mid.x = (a.x + c.x) / 2;
		b_mid.y = (a.y + c.y) / 2;
		if(debug) printf("b:angle = %.3f, x = %.3f y = %.3f\n", b_angle, b_mid.x, b_mid.y);

		//cツづ個傾ツつォツづ陳点
		if(a.y == b.y ){	
			c_angle = HUGE_VAL;
		}else if(a.x == b.x){
			c_angle = 0;
		}else{
			c_angle = -1 / ((b.y - a.y) / (b.x - a.x));
		}
		c_mid.x = (a.x + b.x) / 2;
		c_mid.y = (a.y + b.y) / 2;
		if(debug) printf("c:angle = %.3f, x = %.3f y = %.3f\n", c_angle, c_mid.x, c_mid.y);

		if(b_angle == 0){
			c_in.y = b_mid.y;
			c_in.x = ((c_in.y - c_mid.y) / c_angle) + c_mid.x;
			if(fabs(c_in.x) < 0.001){
				c_in.x = 0;
			}
			if(fabs(c_in.y) < 0.001){
				c_in.y = 0;
			}
			printf("%.3f %.3f ", c_in.x, c_in.y);
		}else if(c_angle == 0){
			c_in.y = c_mid.y;
			c_in.x = ((c_in.y - b_mid.y) / b_angle) + b_mid.y;
			if(fabs(c_in.x) < 0.001){
				c_in.x = 0;
			}
			if(fabs(c_in.y) < 0.001){
				c_in.y = 0;
			}
			printf("%.3f %.3f ", c_in.x, c_in.y);
		}else if(b_angle == HUGE_VAL){
			c_in.x = b_mid.x;
			c_in.y = c_angle * (c_in.x - c_mid.x) + c_mid.y;
			if(fabs(c_in.x) < 0.001){
				c_in.x = 0;
			}
			if(fabs(c_in.y) < 0.001){
				c_in.y = 0;
			}
			printf("%.3f %.3f ", c_in.x, c_in.y);
		}else if(c_angle == HUGE_VAL){
			c_in.x = c_mid.x;
			c_in.y = b_angle * (c_in.x - b_mid.x) + b_mid.y;
			if(fabs(c_in.x) < 0.001){
				c_in.x = 0;
			}
			if(fabs(c_in.y) < 0.001){
				c_in.y = 0;
			}
			printf("%.3f %.3f ", c_in.x, c_in.y);
		}else{
			solve(-1 * b_angle, 1, b_angle * -1 * b_mid.x + b_mid.y,
				  -1 * c_angle, 1, c_angle * -1 * c_mid.x + c_mid.y);
		}

		printf("%.3f\n", r);
		if(debug) getchar();
		*/
	}
	return 0;
}