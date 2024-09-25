#include <math.h>
#include "context.h"

int draw_circle(t_context *context, float x, float y, float radius)
{
    float angle;
    float radius_x;
    float radius_y;
    float circle_x;
    float circle_y;
    float offset_x;
    float offset_y;
    float pi;

    angle = 0.0;
    radius_x = radius;
    radius_y = radius_x / 2;
    circle_x = 0.0;
    circle_y = 0.0;
    offset_x = x;
    offset_y = y;
    pi = 3.1415;

    while (angle <= (2 * pi))
    {
	circle_x = radius_x * cos(angle) + offset_x;
	circle_y = radius_y * sin(angle) + offset_y;
	context->fill_rect(context, circle_x, circle_y, 0.1, 0.1);
	angle += 0.05; 
    }
    return (0);
}
