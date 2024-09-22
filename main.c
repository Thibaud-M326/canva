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

    //main
    /*
    float   i;

    i = -2.0;
    while (i <= canva_size_x)
    {
	fill_rect(&context, i, 0, 0.1, 0.1);
	printf("i:%f\n", i);
	i += 0.1;
    }
    */
    fill_rect(&context, 1.9, 0, 0.1, 0.1);
    canva_print_middle(canva);
    return (0);
}
