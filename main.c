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

    //Rotation of axes in two dimensions

    float PI;
    float rotation_angle;

    PI = 3.1415;
    rotation_angle = 0.0;
    while (rotation_angle <= PI * 2)
    {
	printf("\e[1;1H\e[2J");

	canva_rotate_axes(canva, rotation_angle);
	canva_print_axes(canva);
	canva = canva_init(canva, canva_size_x, canva_size_y);
	rotation_angle += 0.01; 

	usleep(30000);
    }
    return (0);
}
