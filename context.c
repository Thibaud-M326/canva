#include <stdlib.h>
#include <stdio.h>
#include <math.h>
#include "context.h"
#include "s_context.h"

t_context   context_init(t_context context, t_canva *canva, int canva_size_x, int canva_size_y)
{
    context.canva = canva;
    context.canva_size_x = canva_size_x;
    context.canva_size_y = canva_size_y;
    context.path_move_x = -2147483648;
    context.path_move_y = -2147483648;
    context.path_line_x = -2147483648;
    context.path_line_y = -2147483648;
    context.fill_rect = &fill_rect;
    context.begin_path = &begin_path;
    context.move_to = &move_to;
    context.line_to = &line_to;
    context.stroke = &stroke;
    return(context);
}

//prend un pointeur vers context
//pour modifier le context original
int	fill_rect(t_context *context, float x, float y, float width, float height)
{
    float canva_max_x;
    float canva_min_x;
    float canva_max_y;
    float canva_min_y;
    float rect_width;
    float rect_height;
    int	i;

    canva_max_x = context->canva_size_x + 0.001;
    canva_min_x = context->canva_size_x * - 1;
    canva_max_y = context->canva_size_y + 0.001;
    canva_min_y = context->canva_size_y * - 1;
    rect_width = x + width + 0.001;
    rect_height = y + height + 0.001;
    i = 0;

    if (x < canva_min_x || x > canva_max_y
	    || y < canva_min_y || y > canva_max_x)
	return (0);
    if (rect_width > canva_max_x || rect_height > canva_max_y)
	return (0);
    while (context->canva[i].c)
    {
	if ((context->canva[i].x >= x && context->canva[i].x <= rect_width)
		&& (context->canva[i].y >= y && context->canva[i].y <= rect_height))
	{
	    context->canva[i].c = 's';
	}
	i++;
    }
    return(1);
}

int	begin_path(t_context *context)
{
    context->path_move_x = -2147483648.0;
    context->path_move_y = -2147483648.0;
    context->path_line_x = -2147483648.0;
    context->path_line_y = -2147483648.0;
    return (0);
}

int	move_to(t_context *context, float path_move_x, float path_move_y)
{
    context->path_move_x = path_move_x;
    context->path_move_y = path_move_y;
    return(0);
}

int	line_to(t_context *context, float path_line_x, float path_line_y)
{
    context->path_line_x = path_line_x;
    context->path_line_y = path_line_y;
    return(0);
}

int	y_min_max_define(t_context context, float *y_min, float *y_max)
{
    if (context.path_move_y <= context.path_line_y)
    {
	*y_min = context.path_move_y; 
	*y_max = context.path_line_y; 
    }
    else if (context.path_move_y > context.path_line_y)
    {
	*y_min = context.path_line_y; 
	*y_max = context.path_move_y; 
    }
    return (0);
}

int	stroke_vert(t_context *context, char c)
{
    int	i;
    float y_min; 
    float y_max; 

    i = 0;
    y_min = 0;
    y_max = 0;
    y_min_max_define(*context, &y_min, &y_max);
    while (y_min <= y_max + 0.01)
    {
	i = 0;
	while (context->canva[i].c)
	{
	    if (is_float_equal(context->canva[i].x, context->path_move_x) 
		    && is_float_equal(context->canva[i].y, y_min)
		    && context->canva[i].c != '\n')
	    {
		context->canva[i].c = c;
	    }
	    i++;	
	}
	y_min += 0.1;
    }
    return (0);
}

float	affine_find_a(t_context context, float *a)
{
    float x1;
    float y1;
    float x2;
    float y2;

    x1 = context.path_move_x;
    y1 = context.path_move_y;
    x2 = context.path_line_x;
    y2 = context.path_line_y;
    *a = (y2 - y1) / (x2 - x1);
    printf("a           : %f\n", *a); 
    return (*a);
}

float	affine_find_b(t_context context, float a, float *b)
{
    float y1;
    float x1;

    x1 = context.path_move_x;
    y1 = context.path_move_y;
    *b = y1 - a * x1;
    printf("b           : %f\n\n", *b); 
    return (*b);
}

int	is_float_equal(float a, float b)
{
    if (fabs(a - b) < 0.01)
	return (1);
    return (0);
}

int	affine_coord(float canva_x, float canva_y, float a, float b)
{
    float fx;

    fx = a * canva_x + b;

    if (is_float_equal(canva_y, fx))
    {
	return (1); 
    }	
    return (0);
}

int	stroke(t_context *context)
{
    float a;
    float b;
    int	i;
    char c;

    a = 0;
    b = 0;
    i = 0;
    c = 'o';
    if (context->path_move_x == context->path_line_x)
    {
	stroke_vert(context, c);
	return (0);
    }
    a = affine_find_a(*context, &a);
    b = affine_find_b(*context, a, &b);
    while (context->canva[i].c) 
    {
	if(affine_coord(context->canva[i].x, context->canva[i].y, a, b)
		&& context->canva[i].c != '\n')
	{
	    context->canva[i].c = c; 
	}
	i++; 
    }
    return (0);
}
