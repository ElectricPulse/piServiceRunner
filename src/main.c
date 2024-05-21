#include <stdio.h>
#include <stdlib.h>
#include <bcm2835.h>

#define LED RPI_V2_GPIO_P1_37
#define DELAY 1000

int main(int argc, char **argv) {
	if(argc != 2) {
		fprintf(stderr, "Invalid arguments\n");
		return 1;
	}

	//configuring registers
	if(!bcm2835_init())
		return 1;

	bcm2835_gpio_fsel(LED, BCM2835_GPIO_FSEL_OUTP);
	bcm2835_gpio_clr(LED);

	int retCode = system(argv[1]);

	if(retCode == -1) {
		perror("system");
		return 1;
	}


	if(retCode == 0)
		return 0;

	bcm2835_gpio_set(LED);

	return 0;
}
