/*
 * AOJ #2400 You Are the Judge
 */
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct team_t {
  int tid, nsolved, penalty;
  int *nwrong;
} team_t;

int compareTeams(const void *a, const void *b)
{
  const team_t *x = a, *y = b;
  return y->nsolved != x->nsolved ? y->nsolved - x->nsolved :
         x->penalty != y->penalty ? x->penalty - y->penalty : x->tid - y->tid;
}

int main()
{
  int t, p, r, i;
  int tid, pid, tm;
  static char msg[] = "CORRECT";
  team_t *team;
  while (1) {
    scanf("%d%d%d", &t, &p, &r);
    if (t == 0) { break; }

    team = malloc(sizeof(team_t) * (t + 1));
    for (tid = 1; tid <= t; tid++) {
      team[tid].tid = tid;
      team[tid].nsolved = 0;
      team[tid].penalty = 0;
      team[tid].nwrong = malloc(sizeof(team[tid].nwrong[0]) * (p + 1));
      for (pid = 1; pid <= p; pid++) {
        team[tid].nwrong[pid] = 0;
      }
    }

    for (i = 0; i < r; i++) {
      scanf("%d%d%d%s", &tid, &pid, &tm, msg);
      if (team[tid].nwrong[pid] < 0) { continue; }
      if (strcmp(msg, "CORRECT") == 0) {
        team[tid].nsolved++;
        team[tid].penalty += team[tid].nwrong[pid] * 1200 + tm;
        team[tid].nwrong[pid] = -1;
      } else {
        team[tid].nwrong[pid]++;
      }
    }
    qsort(team + 1, t, sizeof(team[0]), compareTeams);

    for (i = 1; i <= t; i++) {
      printf("%d %d %d\n", team[i].tid, team[i].nsolved, team[i].penalty);
    }

    for (tid = 1; tid <= t; tid++) { free(team[tid].nwrong); }
    free(team);
  }
  return 0;
}