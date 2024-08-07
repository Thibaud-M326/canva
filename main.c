#include <stdio.h>
#include "canva.h"
#include "context.h"

int main(void)
{
    int	canva_size_x;
    int canva_size_y;
    t_canva *canva;
    t_context context;

    canva_size_x = 1;
    canva_size_y = 1;
    canva = canva_create(canva_size_x, canva_size_y);
    canva = canva_init(canva, canva_size_x, canva_size_y);
    context = context_init(context, canva, canva_size_x, canva_size_y);
    context.begin_path(&context);
    context.move_to(&context, -0.9, -1.0);
    context.line_to(&context, -0.9, 0.6);
    context.stroke(&context);
    canva_print_middle(canva);
    //canva_print(canva);
    return (0);
}
