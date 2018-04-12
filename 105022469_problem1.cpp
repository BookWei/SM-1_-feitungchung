//Statistic Mechanics Assignment 1, Problem 1
//Fei Tung Chung, 105022469

#include <cstdio>
#include <cstdlib>
#include <ctime>
#include <cmath>
#include <iostream>

int histogram[20];

void roll(int trials, int sides)
{
    for (int i = 1; i <= sides; i++)
        histogram[i] = 0;
    int result;
    srand(time(NULL));
    for (int i = 1; i <= trials; i++)
    {
        result = rand() % sides + 1;
        histogram[result]++;
    }
    printf("sides         N_s       N_s-N/6        N_s/N    N_s/N-1/6\n");
    for (int i = 1; i <= sides; i++)
        printf("  %3d  %10d    % 10.4f   % 10.6f   % 10.6f\n", i, histogram[i],  (double)histogram[i] - (double)trials/sides, (double)histogram[i]/trials, (double)histogram[i]/trials - (double)1.0/sides);
    int sum1 = 0;
    for (int i = 1; i <= sides; i++)
        sum1 = sum1 + i * histogram[i];
    double mean = (double)sum1 / trials;
    printf("experimental mean = %10.6f\n", mean);
    printf("theoretical mean = %10.6f\n", ((double)(sides + 1))/2);
    int sum2 = 0;
    for (int i = 1; i <= sides; i++)
        sum2 = sum2 + i * i * histogram[i];
    double variance = (double)sum2 / trials - mean * mean;
    printf("experimental variance = %10.6f\n", variance);
    printf("theoretical variance = %10.6f\n", ((double)(sides * sides - 1))/12);
    double standard_deviation = sqrt(variance);
    printf("experimental standard deviation = %10.6f\n", standard_deviation);
    printf("theoretical standard deviation = %10.6f\n", sqrt(((double)(sides * sides - 1))/12));
    printf("\n");
}

int main()
{
    int sides = 10;
    roll(1, sides);
    roll(10, sides);
    roll(100, sides);
    roll(1000, sides);
    roll(10000, sides);
    roll(100000, sides);
    roll(1000000, sides);
    system("pause");
    return 0;
}
