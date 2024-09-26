#ifndef CANVA_H
#define CANVA_H

#include "s_canva.h"

int	canva_len_count(int size_x, int size_y);
t_canva *canva_create(int size_x, int size_y);
t_canva	*canva_init(t_canva *canva, int size_x, int size_y);
t_canva *canva_rotate_axes(t_canva *canva, float rotation_angle);
t_canva *canva_cpy(t_canva *canva_dest,t_canva *canva_src);
void	canva_print_coord(t_canva *canva);
void	canva_print_middle(t_canva *canva);
void	canva_print(t_canva *canva);
void	canva_print_axes(t_canva *canva);

#endif
