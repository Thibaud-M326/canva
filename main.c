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

    canva_size_x = 22;
    canva_size_y = 7;
    canva = canva_create(canva_size_x, canva_size_y);
    canva = canva_init(canva, canva_size_x, canva_size_y);
    context = context_init(context, canva, canva_size_x, canva_size_y);

    //sin wave
    float   i;
    float   sin_value;
    float   sin_x;
    float   sin_y;

    i = 0.0;
    sin_value = 0.0;
    sin_x = canva_size_x * -1 - 0.1;
    sin_y = 0.0;
    while (i <= M_PI * 2)
    {
	sin_value = sin(i);
	sin_x += 0.1;
	sin_y = sin_value * 5;
	fill_rect(&context, sin_x, sin_y, 0.1, 0.1);
	printf("sin   :%f\n", sin_value);
	printf("sin_x :%f\n", sin_x);
	printf("sin_y :%f\n\n", sin_y);
	i += 0.1;
    }
    canva_print_middle(canva);
    return (0);
}
