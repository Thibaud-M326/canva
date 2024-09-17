#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <math.h>
#include "canva.h"
#include "context.h"

float random_round_float(float range)
{
    int timestamp;
    float random;

    timestamp = time(NULL);
    srand(timestamp);
    random = (float)rand()/(float)(RAND_MAX / range);
    random = roundf(random * 10) / 10;
    return (random);
}

int main(void)
{
    //canva & context initialisation

    int	canva_size_x;
    int canva_size_y;
    t_canva *canva;
    t_context context;

    canva_size_x = 2;
    canva_size_y = 1;
    canva = canva_create(canva_size_x, canva_size_y);
    canva = canva_init(canva, canva_size_x, canva_size_y);
    context = context_init(context, canva, canva_size_x, canva_size_y);


    //code
    float random;

    random = random_round_float(2.0);
    printf("random: %f", random);
    /*
    int i;
    float x1;
    float y1;
    float x2;
    float y2;


    i = 0;
    while (i < 10)
    {
    
    }
    context.begin_path(&context);
    context.move_to(&context, -1.8, -0.4);
    context.line_to(&context, 1, 1);
    context.stroke(&context);

    canva_print_middle(canva);
    */
    return (0);
}
