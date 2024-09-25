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

    //circle
    float circle_x;
    float circle_y;
    float radius;
    float angle_x;
    float angle_y;

    circle_x = -canva_size_x + 1;
    circle_y = .0;
    radius = .5;
    angle_x = .0;
    angle_y = .0;

    while (circle_x + radius < canva_size_x)
    {
	printf("\e[1;1H\e[2J");
	draw_circle(&context, circle_x, circle_y, radius);
	circle_x = sin(angle_x) * canva_size_x * 0.5;
	circle_y = cos(angle_y) * canva_size_y * 0.5;
	angle_x += 0.13;
	angle_y += 0.09;
	canva_print(canva);
	clear_rect(&context, -canva_size_x, -canva_size_y, canva_size_x * 2, canva_size_y * 2);
	usleep(31000);
    }
    return (0);
}
