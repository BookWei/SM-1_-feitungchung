//Statistic Mechanics Assignment 1, Problem 0
//Fei Tung Chung, 105022469

#include <cstdio>
#include <cstdlib>
#include <ctime>
#include <iostream>

int histogram[10];

void roll(int trials, int sides)
{
    for (int i = 1; i <= sides; i++)
        histogram[i] = 0;
    int result;
    srand(time(NULL));
    for (int i = 1; i <= trials; i++)
    {
        //srand(time(NULL));
        result = rand() % sides + 1;
        histogram[result]++;
    }
    printf("sides         N_s       N_s-N/6        N_s/N    N_s/N-1/6\n");
    for (int i = 1; i <= sides; i++)
        printf("  %3d  %10d    % 10.4f   % 10.6f   % 10.6f\n", i, histogram[i],  (double)histogram[i] - (double)trials/sides, (double)histogram[i]/trials, (double)histogram[i]/trials - (double)1.0/sides);
    printf("\n");
}

int main()
{
    int sides = 6;
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
