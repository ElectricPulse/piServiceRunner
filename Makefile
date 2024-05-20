ARGS = 'make -C /home/hackerman/Desktop/piAttendance/ daemon'
FLAGS = -O0 -g
LIBS = -lbcm2835

run: main
	./main ${ARGS}

debug: main
	gdb --args ./main ${ARGS}

main: main.c
	gcc ${FLAGS} -o main main.c ${LIBS}
