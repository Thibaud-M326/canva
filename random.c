#include <stdio.h>
#include <time.h>
#include <stdlib.h>
#include <math.h>

float random_round_float(float range)
{
    float random;

    random = (float)rand()/(float)(RAND_MAX / range);
    random = roundf(random * 10) / 10;
    return (random);
}

float random_float(void)
{
    float random;

    random = (float)rand()/(float)(RAND_MAX);
    return (random);
}

float random_float_range(float min, float max)
{
    float random;

    random = random_float();
    random = random * (max - min) + min; 
    return (random);
}
