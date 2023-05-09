#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "appdev.h"

int main() {
	rock r;  //declare an instance of rock
	printf("Application Developers Rock\n");
	printf("Enter Rocker's name: \n");
	scanf_s("%s", r.rname, (unsigned)_countof(r.rname));
	//generate the random numbers
	r.max = rand() % 50 + 51; //max
	r.min = rand() % 50 + 1; //min
	send_data(r);
	printf("Rockn'Roll\n");
	return 0;

}