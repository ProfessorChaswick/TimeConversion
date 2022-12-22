#include <stdio.h>
#include <stdlib.h>
int *doConv(int seconds);

int main(int argc, char *argv[])
{
    int num = atoi(argv[1]);
    int *conversion = doConv(num);
    if(conversion[3] < 1)
        printf("\nconverted to %d minutes, %d seconds... \n%d seconds entered", 
        conversion[0], conversion[1], conversion[2]);
    else
        printf("\nconverted to %d hours, %d minutes, %d seconds... \n%d seconds entered", 
        conversion[3], conversion[0], conversion[1], conversion[2]);
}
int *doConv(int seconds)
{
    static int answer[4];

    div_t hours = div(seconds, 3600);
    div_t mins = div(hours.rem, 60);

    answer[0] = mins.quot; 
    answer[1] = mins.rem;
    answer[2] = seconds;
    answer[3] = hours.quot;

    return answer;
}