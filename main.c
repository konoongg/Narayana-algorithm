#include <stdlib.h>
#include <stdio.h>
int main(void) {
	int countNumbers[10] = { 0,0,0,0,0,0,0,0,0,0 };
	int numbers[10];
	char c;
	int counter = 0;
	while ((c = (char)getchar()) != '\n') {
		int intC = c - '0';
		if (countNumbers[intC] >= 1 || intC < 0 || intC > 9) {
			printf("bad input");
			return 0;
		}
		numbers[counter] = intC;
		++counter;
		++countNumbers[intC];
	}
	int times;
	if (scanf("%d", &times) == -1) {
		return 0;
	}
	for (int i = 0; i < times; ++i) {
		int nextNum = 10, nextNumIndex = 0, numIndex = 0, flag = 0;
		for (int j = counter - 2; j >= 0; --j) {
			numIndex = j;
			for (int m = j; m < counter; ++m) {
				if (numbers[m] > numbers[j] && numbers[m] < nextNum) {
					nextNum = numbers[m];
					nextNumIndex = m;
				}
			}

			if (nextNum < 10) {
				flag = 1;
				break;
			}
		}
		if (flag == 1) {
			int num = numbers[numIndex];
			numbers[numIndex] = numbers[nextNumIndex];
			numbers[nextNumIndex] = num;
			for (int j = numIndex + 1; j < counter - 1; ++j) {
				for (int m = j + 1; m < counter; ++m) {
					if (numbers[j] > numbers[m]) {
						num = numbers[m];
						numbers[m] = numbers[j];
						numbers[j] = num;
					}
				}

			}
			for (int j = 0; j < counter; ++j) {
				printf("%d", numbers[j]);
			}
			printf("\n");
		}
		else {
			break;
		}
	}
	return 0;
}


