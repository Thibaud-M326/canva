#include <stdio.h>
#include <math.h>
#include "canva.h"
#include "context.h"
#include "random.h"

int main(void)
{
    //canva & context : initialisation
    int	canva_size_x;
    int canva_size_y;
    t_canva *canva;
    t_context context;

    canva_size_x = 2;
    canva_size_y = 1;
    canva = canva_create(canva_size_x, canva_size_y);
    canva = canva_init(canva, canva_size_x, canva_size_y);
    context = context_init(context, canva, canva_size_x, canva_size_y);

    //sin_wave
    float   i;
    float   sin_x;
    float   sin_y;

    i = 0.0;
    sin_x = canva_size_x * -1;
    sin_y = 0.0;
    while (i <= M_PI * 2)
    {
	sin_x += 0.05;
	sin_y = sin(i) * 0.5;
	context.fill_rect(&context, sin_x, sin_y, 0.1, 0.1);
	i += 0.1;
    }
    canva_print_middle(canva);
    return (0);
}
