Please make a gitignore

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
    while (i < 300)
    {
	printf("\e[1;1H\e[2J");
   	path_move_x = random_float_range(-canva_size_x, canva_size_x);
   	path_move_y = random_float_range(-canva_size_y, canva_size_y);
   	path_line_x = random_float_range(-canva_size_x, canva_size_x);
   	path_line_y = random_float_range(-canva_size_y, canva_size_y);

	begin_path(&context);
	move_to(&context, path_move_x, path_move_y);
	line_to(&context, path_line_x, path_line_y);
	stroke(&context);
	canva_print(canva);
	usleep(fps);
	i++;
    }	
    return (0);

