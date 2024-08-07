#ifndef CONTEXT_H
#define CONTEXT_H

#include "s_context.h"

t_context   context_init(t_context context, t_canva *canva, int canva_size_x, int canva_size_y);
int	fill_rect(t_context *context, float x, float y, float width, float height);
int	begin_path(t_context *context);
int	move_to(t_context *context, float path_move_x, float path_move_y);
int	line_to(t_context *context, float path_line_x, float path_line_y);
int	stroke(t_context *context);

#endif
