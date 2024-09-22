#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <unistd.h>
#include "canva.h"
#include "context.h"
#include "random.h"

int main(void)
{
    //canva & context initialisation
    int	canva_size_x;
    int canva_size_y;
    t_canva *canva;
    t_context context;

    //x = 22 //y = 7 //make a big square
    canva_size_x = 22;
    canva_size_y = 7;
    canva = canva_create(canva_size_x, canva_size_y);
    canva = canva_init(canva, canva_size_x, canva_size_y);
    context = context_init(context, canva, canva_size_x, canva_size_y);

    //random lines
    int timestamp;
    int i;
    float path_move_x;
    float path_move_y;
    float path_line_x;
    float path_line_y;
    int fps = 30000;

    timestamp = time(NULL);
    srand(timestamp);

    i = 0;
    while (i < 30)
    {
	printf("\e[1;1H\e[2J");
   	path_move_x = random_float_range(-canva_size_x, canva_size_x);
   	path_move_y = random_float_range(-canva_size_y, canva_size_y);
   	path_line_x = random_float_range(-canva_size_x, canva_size_x);
   	path_line_y = random_float_range(-canva_size_y, canva_size_y);

	context.begin_path(&context);
	context.move_to(&context, path_move_x, path_move_y);
	context.line_to(&context, path_line_x, path_line_y);
	context.stroke(&context);
	canva_print(canva);
	usleep(fps);
	i++;
    }	
    return (0);
}
