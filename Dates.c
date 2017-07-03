#include <conio.h>
#include <stdio.h>
#include <stdbool.h>

int main() {
	int startYear;
	int startMonth;
	int startDay;

	int endYear;
	int endMonth;
	int endDay;

	int days = 0;

	printf("Input first date.\n");
	printf("Input first year: ");
	scanf_s("%d", &startYear);

	printf("Input first month: ");
	scanf_s("%d", &startMonth);

	printf("Input first day: ");
	scanf_s("%d", &startDay);

	printf("\nInput second date.\n");
	printf("Input second year: ");
	scanf_s("%d", &endYear);

	printf("Input second month: ");
	scanf_s("%d", &endMonth);

	printf("Input second day: ");
	scanf_s("%d", &endDay);

	if (startYear == endYear && startMonth == endMonth)
		days = endDay - startDay == 0 ? 0 : endDay - startDay - 1;
	else {
		//Counting days from the start day to the end of the start month
		if (startMonth == 1 || startMonth == 3 || startMonth == 5 || startMonth == 7 || startMonth == 8 || startMonth == 10 || startMonth == 12)
			days += 31 - startDay;
		else if (startMonth == 4 || startMonth == 6 || startMonth == 9 || startMonth == 11)
			days += 30 - startDay;
		else
			days = startYear % 4 == 0 && (startYear % 100 != 0 || startYear % 400 == 0) ? 29 - startDay : 28 - startDay;//If february and (not) leap year

		//Counting days from the next from the start month to the end of the start year
		int end = 12;
		int start = 1;
		if (startYear == endYear && startMonth != endMonth) {
			end = endMonth - 1;
			start = endMonth;
		}
		for (int i = startMonth + 1; i <= end; i++) {
			if (i == 1 || i == 3 || i == 5 || i == 7 || i == 8 || i == 10 || i == 12)
				days += 31;
			else if (i == 4 || i == 6 || i == 9 || i == 11)
				days += 30;
			else days += startYear % 4 == 0 && (startYear % 100 != 0 || startYear % 400 == 0) ? 29 : 28;
		}

		//Counting days from the start of the end year to the end month - 1
		for (int i = start; i < endMonth; i++) {
			if (i == 1 || i == 3 || i == 5 || i == 7 || i == 8 || i == 10 || i == 12)
				days += 31;
			else if (i == 4 || i == 6 || i == 9 || i == 11)
				days += 30;
			else days += endYear % 4 == 0 && (endYear % 100 != 0 || endYear % 400 == 0) ? 29 : 28;
		}

		//Counting days of the end month
		days += endDay - 1;
	}

	//Counting days between start and end year
	for (int i = startYear + 1; i < endYear; i++) {
		days += i % 4 == 0 && (i % 100 != 0 || i % 400 == 0) ? 366 : 365;
	}

	printf("Days: %d.", days);

	_getch();
	return 0;
}