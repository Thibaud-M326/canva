#include <stdio.h>
#include <math.h>
#include "canva.h"
#include "context.h"
#include "random.h"

int main(void)
{
    //canva & context : initialisation
    float   canva_size_x;
    float   canva_size_y;
    t_canva *canva;
    t_context context;

    canva_size_x = 2;
    canva_size_y = 1;
    canva = canva_create(canva_size_x, canva_size_y);
    canva = canva_init(canva, canva_size_x, canva_size_y);
    context = context_init(context, canva, canva_size_x, canva_size_y);

    //clear_rect
    context.fill_rect(&context, -canva_size_x, -canva_size_y, canva_size_x * 2, canva_size_y * 2);
    context.clear_rect(&context, -canva_size_x / 2, -canva_size_y / 2, canva_size_x, canva_size_y);
    canva_print(canva);
    return (0);
}
