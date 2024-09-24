#ifndef S_CONTEXT_H
#define S_CONTEXT_H

#include "s_canva.h"
#include "s_context.h"

typedef struct s_context
{
    t_canva *canva;
    float   canva_size_x;
    float   canva_size_y;
    char    canva_point;
    float   path_move_x;
    float   path_move_y;
    float   path_line_x;
    float   path_line_y;
    int	    (*fill_rect)(struct s_context *context, float x, float y, float width, float height);
    int	    (*clear_rect)(struct s_context *context, float x, float y, float width, float height);
    int	    (*begin_path)(struct s_context *context);
    int	    (*move_to)(struct s_context *context, float path_move_x, float path_move_y);
    int	    (*line_to)(struct s_context *context, float path_line_x, float path_line_y);
    int	    (*stroke)(struct s_context *context);
}   t_context;

#endif
