canva: main.o canva.o context.o
	cc -g -Wall -Wextra -Werror main.o canva.o context.o -o canva -lm
	./canva

main.o: main.c canva.h context.h
	cc -g -Wall -Wextra -Werror -c main.c -o main.o

canva.o: canva.c canva.h s_canva.h
	cc -g -Wall -Wextra -Werror -c canva.c -o canva.o

context.o: context.c context.h s_context.h
	cc -g -Wall -Wextra -Werror -c context.c -o context.o

clean:
	rm -f main.o canva.o context.o canva
