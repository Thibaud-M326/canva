#include <math.h>
#include <stdio.h>
#include <unistd.h>
#include "context.h"
#include "canva.h"

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

int lissajous_curve(t_context *context, float radius)
{
    float circle_x;
    float circle_y;
    float angle_x;
    float angle_y;
    float canva_size_x;
    float canva_size_y;

    circle_x = .0;
    circle_y = .0;
    angle_x = .0;
    angle_y = .0;
    canva_size_x = context->canva_size_x;
    canva_size_y = context->canva_size_y;

    while (1)
    {
	printf("\e[1;1H\e[2J");
	draw_circle(context, circle_x, circle_y, radius);
	circle_x = sin(angle_x) * canva_size_x * 0.5;
	circle_y = cos(angle_y) * canva_size_y * 0.5;
	angle_x += 0.13;
	angle_y += 0.09;
	canva_print(context->canva);
	clear_rect(context, -canva_size_x, -canva_size_y, canva_size_x * 2, canva_size_y * 2);
	usleep(31000);
    }
    return (0);
}
