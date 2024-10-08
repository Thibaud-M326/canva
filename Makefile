canva: main.o canva.o context.o random.o draw.o
	cc -g -Wall -Wextra -Werror main.o canva.o context.o random.o draw.o -o canva -lm
	rm -f main.o canva.o context.o random.o draw.o
	ctags -R
	clear
	./canva

main.o: main.c canva.h context.h
	cc -g -Wall -Wextra -Werror -c main.c -o main.o

canva.o: canva.c canva.h s_canva.h
	cc -g -Wall -Wextra -Werror -c canva.c -o canva.o

context.o: context.c context.h s_context.h
	cc -g -Wall -Wextra -Werror -c context.c -o context.o

random.o: random.c random.h
	cc -g -Wall -Wextra -Werror -c random.c -o random.o

draw.o: draw.c draw.h
	cc -g -Wall -Wextra -Werror -c draw.c -o draw.o

clean:
	rm -f main.o canva.o context.o random.o canva
