#include <stdio.h>

typedef struct {
   int hours;
   int minutes;
   int seconds;
}time;

time *diff(time *, time *);

int main()
{
   time start_time, stop_time, *ans;
   printf("Enter the start time in hours : minutes : seconds\n");
   scanf("%d %d %d", &start_time.hours, &start_time.minutes, &start_time.seconds);
   printf("Enter the stop time in hours : minutes : seconds\n");
   scanf("%d %d %d", &stop_time.hours, &stop_time.minutes, &stop_time.seconds);
   ans = diff(&start_time, &stop_time);
   printf("The difference between start and stop time is: %d : %d : %d", ans->hours, ans->minutes, ans->seconds);
   return 0;
}

time *diff(time *start, time *stop)
{
   static time ans;
   ans.hours = ans.minutes = ans.seconds = 0;
   while(stop->seconds < start->seconds){
      --start->minutes;
      stop->seconds += 60;
   }
   ans.seconds = stop->seconds - start->seconds;

   while(stop->minutes < start->minutes){
      --start->hours;
      stop->minutes += 60;
   }

   ans.minutes = stop->minutes - start->minutes;

   ans.hours = stop->hours - start->hours;
   return &ans;
}