#ifndef CANVA_H
#define CANVA_H

#include "s_canva.h"

int	canva_len_count(int size_x, int size_y);
t_canva *canva_create(int size_x, int size_y);
t_canva	*canva_init(t_canva *canva, int size_x, int size_y);
void	canva_print_coord(t_canva *canva);
void	canva_print_middle(t_canva *canva);
void	canva_print(t_canva *canva);

#endif
