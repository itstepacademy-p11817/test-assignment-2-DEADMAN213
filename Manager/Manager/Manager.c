#include <conio.h>
#include <stdio.h>

int main() {
	int basSallary = 200;
	int bonus = 200;

	double manSallary1 = basSallary;
	double manSallary2 = basSallary;
	double manSallary3 = basSallary;

	int manSale1 = -1;
	int manSale2 = -1;
	int manSale3 = -1;

//Input of sales for each manager
	while (manSale1 < 0) {
		printf("Input sales of first manager: ");
		scanf_s("%d", &manSale1);
	}
	while (manSale2 < 0) {
		printf("Input sales of second manager: ");
		scanf_s("%d", &manSale2);
	}
	while (manSale3 < 0) {
		printf("Input sales of third manager: ");
		scanf_s("%d", &manSale3);
	}

//Spoting the sallary for each manager
	if (manSale1 <= 500)
		manSallary1 += manSale1 * 3. / 100;
	else if (manSale1 > 500 && manSale1 <= 1000)
		manSallary1 += manSale1 * 5. / 100;
	else if (manSale1 > 1000)
		manSallary1 += manSale1 * 8. / 100;
	printf("Sallary of the first manager: %.2f.\n", manSallary1);

	if (manSale2 <= 500)
		manSallary2 += manSale2 * 3. / 100;
	else if (manSale2 > 500 && manSale2 <= 1000)
		manSallary2 += manSale2 * 5. / 100;
	else if (manSale2 > 1000)
		manSallary2 += manSale2 * 8. / 100;
	printf("Sallary of the second manager: %.2f.\n", manSallary2);

	if (manSale3 <= 500)
		manSallary3 += manSale3 * 3. / 100;
	else if (manSale3 > 500 && manSale3 <= 1000)
		manSallary3 += manSale3 * 5. / 100;
	else if (manSale3 > 1000)
		manSallary3 += manSale3 * 8. / 100;
	printf("Sallary of the third manager: %.2f.\n", manSallary3);

//Spoting the max sales
	int maxSal = manSale1;

	if (manSale2 > maxSal)
		maxSal = manSale2;
	if (manSale3 > maxSal)
		maxSal = manSale3;

//Spoting the best manager
	if (maxSal == manSale1) {
		manSallary1 += bonus;
		printf("The best saller is first manager and his sallary: %.2f.\n", manSallary1);
	}
	if (maxSal == manSale2) {
		manSallary2 += bonus;
		printf("The best saller is second manager and his sallary: %.2f.\n", manSallary2);
	}
	if (maxSal == manSale3) {
		manSallary3 += bonus;
		printf("The best saller is third manager and his sallary: %.2f.\n", manSallary3);
	}

	_getch();

	return 0;
}