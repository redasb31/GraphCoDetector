#include <stdio.h>
#include <math.h>

int main() {
  // A: length of the hour hand
  // B: length of the minute hand
  // H: hours
  // M: minutes
  int A, B, H, M;
  scanf("%d %d %d %d", &A, &B, &H, &M);

  // Calculate the angle of the hour hand
  double hour_angle = (H * 60 + M) / 720.0 * 360.0; // 360 degrees / 12 hours = 30 degrees/hour

  // Calculate the angle of the minute hand
  double minute_angle = M / 60.0 * 360.0; // 360 degrees / 60 minutes = 6 degrees/minute

  // Calculate the difference in angle between the two hands
  double angle_difference = fabs(hour_angle - minute_angle);

  // Calculate the distance between the endpoints of the hands using the law of cosines
  double distance = sqrt(A * A + B * B - 2 * A * B * cos(angle_difference * M_PI / 180.0));

  // Print the answer
  printf("%.16lf\n", distance);

  return 0;
}