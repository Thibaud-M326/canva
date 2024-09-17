#include <stdlib.h>
#include <stdio.h>
#include "canva.h"
#include "s_canva.h"

int	canva_len_count(int size_x, int size_y)
{
    int size_line_feed;
    int size_row;
    int size_col;
    int canva_end;
    int canva_len;

    size_row = ((size_x * 10) * 2) + 1;
    size_col = ((size_y * 10) * 2) + 1;
    size_line_feed = size_col;
    canva_end = 1;
    canva_len = size_row * size_col + size_line_feed + canva_end;
    return (canva_len);
}

t_canva *canva_create(int size_x, int size_y)
{
    t_canva *canva;
    int	canva_len;

    canva_len = canva_len_count(size_x, size_y);
    canva = malloc(sizeof(t_canva) * canva_len);
    return (canva);
}

void	canva_init_line_feed(t_canva *canva_point)
{
    canva_point->x = -2147483648;
    canva_point->y = -2147483648;
    canva_point->c = '\n';
}

void	canva_init_point(float x, float y, t_canva *canva_point)
{
    char c;

    c = '.';
    canva_point->x = x;
    canva_point->y = y;
    canva_point->c = c;
}

t_canva	*canva_init(t_canva *canva, int size_x, int size_y)
{
    int i;
    int j;
    float x;
    float y;
    int size_row;
    int canva_len;

    i = 0;
    j = 0;
    x = size_x * -1;
    y = size_y * -1;
    size_row = size_x * 10 * 2 + 1;
    canva_len = canva_len_count(size_x, size_y);
    printf("\ncanva_len:%d\n\n", canva_len);
    while (i < canva_len - 1)
    {
	j = 0;
	while ((j < size_row + 1) && (i < canva_len - 1))
	{
	    if(j == size_row)
		canva_init_line_feed(&(canva[i]));
	    else
		canva_init_point(x, y, &(canva[i]));
	    x = x + 0.1;
	    i++;
	    j++;
	}
	x = size_x * -1;
	y = y + 0.1;
    }
    canva[i].c = '\0';
    return (canva);
}

void	canva_print_coord(t_canva *canva)
{
    int	i;

    i = 0; 
    while (canva[i].c != '\0')
    {
	if (canva[i].c == '\n')
	    printf("%c", canva[i].c);
	else
	    printf("(%0.1f, %0.1f) ", canva[i].x, canva[i].y);
	i++;
    }
}

void	canva_print_middle(t_canva *canva)
{
    int	i;

    i = 0;
    while (canva[i].c != '\0')
    {
	if (canva[i].x >= 0.0 && canva[i].x <= 0.01
		&& canva[i].y >= 0.0 && canva[i].y <= 0.01)
	    canva[i].c = 'x';
	printf("%c", canva[i].c); 
	i++;
    }
}

void	canva_print(t_canva *canva)
{
    int	i;

    i = 0;
    while (canva[i].c != '\0')
    {
	printf("%c", canva[i].c); 
	i++;
    }
}
