connectn.out: connectn.o board.o play.o endconditions.o
	gcc -g -Wall -Werror -o connectn.out connectn.o board.o play.o endconditions.o
board.o: board.c board.h
	gcc -g -Wall -Werror -c -o board.o board.c
connectn.o: connectn.c board.h
	gcc -g -Wall -Werror -c -o connectn.o connectn.c
play.o: play.c play.h endconditions.h board.h
	gcc -g -Wall -Werror -c -o play.o play.c
endconditions.o: endconditions.c endconditions.h
	gcc -g -Wall -Werror -c -o endconditions.o endconditions.c
clean:
	rm -f *.o *.out
