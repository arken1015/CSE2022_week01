#include <stdio.h> // Standard IO
#include <stdlib.h> // File stream
#include <time.h> // To get seed for rand()
#include <stdbool.h> // To use boolean
#include <direct.h> // To get current working path

#define MAX_DOT 10000

inline double getrand(const double min, const double max) // Get random generated real number
{
	double temp = (double)rand() / (double)RAND_MAX; // temp will be between 0 and 1
	temp = min + (max - min) * temp; // temp will be between min and max

	return temp; // Return generated number
}

//Sets circle's center position
double x_c = 0.5;
double y_c = 0.5;

bool incircle(const double x, const double y)
{
	const double r = 0.5;

	const double f = (x - x_c)*(x - x_c) + (y - y_c) * (y - y_c) - r * r;

	if (f > 0.0)return false;
	else return true;
}

bool inellipse(const double x, const double y)
{
	const double x_f = 16;
	const double y_f = 4;

	const double f = x_f * (x - x_c)*(x - x_c) + y_f * (y - y_c) * (y - y_c) - 1;

	if (f > 0.0)return false;
	else return true;
}

void first();
void second();
void third();

int main()
{
	int num = 0;
	char buffer[1024] = { 0, };
	char* path = NULL;
	path = getcwd(buffer, 1024);
index:
	
	printf_s("Select what you want to print\n");
	printf_s("1: Circle\n2: Dumbbell\n3: Ellipse\n");
	printf_s("0: Exit\n\n");

	scanf_s("%d", &num);
	switch (num)
	{
	case 1:
		first();
		printf_s("Saved into %s\\first.txt\n", path);
		break;
	case 2:
		second();
		printf_s("Saved into %s\\second.txt\n", path);
		break;
	case 3:
		third();
		printf_s("Saved into %s\\third.txt\n", path);
		break;
	case 0:
		printf_s("Exited with no change\n");
		return 0;
		break;
	default:
		system("cls");
		goto index;
		break;
	}
	return 0;
}

void first()
{
	FILE *of = fopen("first.txt", "w");

	srand((unsigned int)time(NULL));

	for (int i = 0; i < MAX_DOT; i++)
	{
		double x = getrand(0.0, 1.0);
		double y = getrand(0.0, 1.0);
		if (incircle(x, y))fprintf(of, "%f %f\n", x, y);
	}

	fclose(of);
}

void second()
{
	FILE *of = fopen("second.txt", "w");

	srand((unsigned int)time(NULL));

	for (int i = 0; i < MAX_DOT; i++)
	{
		double x = getrand(0.0, 1.0);
		double y = getrand(0.0, 1.0);
		if (incircle(x, y))fprintf(of, "%f %f\n", x, y);
	}

	for (int i = 0; i < MAX_DOT; i++)
	{
		double x = getrand(1.0, 2.0);
		double y = getrand(0.3, 0.7);
		fprintf(of, "%f %f\n", x, y);
	}

	x_c = 2.5;
	for (int i = 0; i < MAX_DOT; i++)
	{
		double x = getrand(2.0, 3.0);
		double y = getrand(0.0, 1.0);
		if (incircle(x, y))fprintf(of, "%f %f\n", x, y);
	}

	fclose(of);
}

void third()
{
	FILE *of = fopen("third.txt", "w");

	srand((unsigned int)time(NULL));

	for (int i = 0; i < MAX_DOT; i++)
	{
		double x = getrand(0.0, 1.0);
		double y = getrand(0.0, 1.0);
		if (inellipse(x, y))fprintf(of, "%f %f\n", x, y);
	}

	fclose(of);
}