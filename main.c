#include <stdio.h>
#include <math.h>
#include <unistd.h>
#include "canva.h"
#include "context.h"
#include "random.h"
#include "draw.h"

int main(void)
{
    //canva & context : initialisation
    float   canva_size_x;
    float   canva_size_y;
    t_canva *canva;
    t_context context;

    canva_size_x = 8;
    canva_size_y = 2;
    canva = canva_create(canva_size_x, canva_size_y);
    canva = canva_init(canva, canva_size_x, canva_size_y);
    context = context_init(context, canva, canva_size_x, canva_size_y);

    //lissajous curve

    float radius;

    radius = 1.0;
    lissajous_curve(&context, radius);
    return (0);
}
