ARGS = 'make -C /home/hackerman/Programs/piPowerControl/ daemon'
FLAGS = -O0 -g
LIBS = -lbcm2835

run: out/main
	out/main ${ARGS}

debug: out/main
	gdb --args ./main ${ARGS}

out/main: src/main.c
	gcc ${FLAGS} -o out/main src/main.c ${LIBS}
