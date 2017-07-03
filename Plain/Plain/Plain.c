#include <conio.h>
#include <stdio.h>

int main() {
	int distAB = 0;
	int distBC = 0;
	int cargoW = 0;
	int tankVol = 300;
	
	int k;
	int ch = 0;

	do {
//Input and verification of source data
		while (distAB <= 0) {
			printf("Input A to B distance: ");
			scanf_s("%d", &distAB);

			if (distAB <= 0)
				printf("Wrong input! Please repeat!\n");
		}	

		while (distBC <= 0) {
			printf("Input B to C distance: ");
			scanf_s("%d", &distBC);

			if (distBC <= 0)
				printf("Wrong input! Please repeat!\n");
		}

		while (cargoW <=0 || cargoW > 2000) {
			printf("Input cargo weight: ");
			scanf_s("%d", &cargoW);

			if (cargoW <= 0 || cargoW > 2000)
				printf("Wrong input! Please repeat!\n");
		}

//Determination of the coefficient for the formula V = k*S
		if (cargoW <= 500)
			k = 1;
		if (cargoW > 500 && cargoW <= 1000)
			k = 4;
		if (cargoW > 1000 && cargoW <= 1500)
			k = 7;
		if (cargoW > 1500 && cargoW <= 2000)
			k = 9;

//Calculation of the fuel volume for refueling
		if (k*distAB > tankVol)
			printf("Flight impossible! Too long distance between A and B!\n\n");
		else if (k*distBC > tankVol)
			printf("Flight impossible! Too long distance between B and C!\n\n");
		else
			printf("Refueling requires %d littres.\n\n", tankVol - k*distAB - k*distBC >= 0 ? 0 : -(tankVol - k*distAB - k*distBC));

		printf("1 - repeat calculation.\n");
		printf("0 - exit the program.\n");
		printf("Choice: ");
		scanf_s("%d", &ch);
	} while (ch == 1);

	printf("End!");
	_getch();

	return 0;
}