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

    canva_size_x = 8;
    canva_size_y = 2;
    canva = canva_create(canva_size_x, canva_size_y);
    canva = canva_init(canva, canva_size_x, canva_size_y);
    context = context_init(context, canva, canva_size_x, canva_size_y);

    //circle
    float angle;
    float radius_x;
    float radius_y;
    float circle_x;
    float circle_y;
    float PI;

    angle = 0.0;
    radius_x = 3;
    radius_y = radius_x / 2;
    circle_x = -canva_size_x;
    circle_y = -canva_size_y;
    PI = 3.1215;

    while (angle <= (2 * PI))
    {
	circle_x = radius_x * cos(angle);
	circle_y = radius_y * sin(angle);
	context.fill_rect(&context, circle_x, circle_y, 0.1, 0.1);
	angle += 0.05; 
    }
    canva_print(canva);
    return (0);
}
