#include<stdio.h>
#include<string.h>


#define N_MAX     200000
#define GROUP_MAX 18
#define DP_SIZE   ((N_MAX+31)/32)



typedef struct tag_group_t
{
	int l, r, is_invalid;
}group_t;


unsigned long dp[GROUP_MAX][DP_SIZE];
group_t g_group[GROUP_MAX+1][GROUP_MAX+1];
int group_num;
int n, v;
int x[N_MAX];


int group_max_calc(int v)
{
	int i;

	if(v<0) return 0;
	for(i=0;(1<<i)<=v;i++)
		;
	return i+1;
}


int group_calc(group_t d[], group_t s[], int s_num, int v)
{
	int i, j;
	int d_num=0, d_num_limit;

	d_num_limit=group_max_calc(v);
//printf("v=%d d_num_limit=%d\n", v, d_num_limit);
	for(i=0;i<s_num;i++)
	{
		if(s[i].is_invalid) continue;

		d[d_num].l=s[i].l;
		d[d_num].is_invalid=0;
		for(j=s[i].l;j<s[i].r;j++)
		{
			if(x[j+1]-x[j]>v)
			{
				d[d_num++].r=j;
				if(d_num>=d_num_limit) return -1;
				d[d_num].l=j+1;
				d[d_num].is_invalid=0;
			}
		}
		d[d_num++].r=j;
	}
	return d_num;
}


int calc(group_t group[], int group_num, int depth)
{
	group_t *group2;
	int group2_num;
	int i, v2, ret=0;

	group2=g_group[depth];
	v2=(v>>depth);
	group2_num=group_calc(group2, group, group_num, v2);
	if(group2_num<0) return 0;

	if(0)
	{
		printf("group_num=%d depth=%d v=%d", group_num, depth, v);
		for(i=0;i<group_num;i++)
		{
//			if(group[i].is_invalid) continue;
			printf(" %d-%d[%d]", group[i].l, group[i].r, group[i].is_invalid);
		}
		printf("\n");
	}

	if(0)
	{
		printf("group2_num=%d depth=%d v2=%d", group2_num, depth, v2);
		for(i=0;i<group2_num;i++)
		{
//			if(group2[i].is_invalid) continue;
			printf(" %d-%d[%d]", group2[i].l, group2[i].r, group2[i].is_invalid);
		}
		printf("\n");
	}

	if(v2<=0)
	{
		return (group2_num<=1);
	}
	if(group2_num<=1)
	{
		return 1;
	}

	for(i=0;i<group2_num;i++)
	{
		group2[i].is_invalid=1;
		if(calc(group2, group2_num, depth+1)) ret=1;
		}
		group2[i].is_invalid=0;
	}

	return 0;
}


int main(void)
{
	int i, j, group_num, result;
	group_t temp, group[GROUP_MAX];

	while(scanf("%d%d", &n, &v)==2)
	{
		memset(dp, 0, sizeof(dp));
//		printf("\nn=%d v=%d\n", n, v);
		for(i=0;i<n;i++)
		{
			scanf("%d", &x[i]);
		}
		temp.l=0;
		temp.r=n-1;
		temp.is_invalid=0;
		group_num=group_calc(group, &temp, 1, v);
		for(i=0;i<group_num;i++)
		{
			group[i].is_invalid=1;
			result=calc(group, group_num, 1);
			group[i].is_invalid=0;
			for(j=group[i].l;j<=group[i].r;j++)
			{
				printf("%s\n", result?"Possible":"Impossible");
			}
		}
	}
	return 0;
}
