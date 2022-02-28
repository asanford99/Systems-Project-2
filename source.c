#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<stdbool.h>

int main() {
	int tripDays = 0;
	int departTime = 0;
	int arriveTime = 0;
	int breakfastMeals = 0;
	int lunchMeals = 0;
	int dinnerMeals = 0;
	float airfaireCost = 0;
	float carRentalCost = 0;
	float milesDriven = 0;
	float seminarFees = 0;
	float hotelCost = 0;
	float* breakfastCosts;
	float* lunchCosts;
	float* dinnerCosts;

	char readDepartureTime[5];
	char readDepartureAMPM[2];
	char readArrivalTime[5];
	char readArrivalAMPM[2];

	//takes input and stores into tripDays
	printf("Total number of days spent on trip (include departure and arrival days): ");
	scanf("%d", &tripDays);

	//takes input and stores into readDepartureTime
	printf("Departure time: ");
	scanf("%s", readDepartureTime);

	//takes input and stores into readDepartureAMPM
	printf("AM or PM?: ");
	scanf("%s", readDepartureAMPM);

	//gives the time a number value and converts to military time
	char newReadDepartureTime[4];
	bool hasColon = false;

	for (int i = 0; i < strlen(readDepartureTime); i++)
	{
		if (readDepartureTime[i] != ':') {

			if (hasColon == true) {

				newReadDepartureTime[i - 1] = readDepartureTime[i];

			}
			else {
				newReadDepartureTime[i] = readDepartureTime[i];
			}

		}
		else {
			hasColon = true;
		}
	}

	hasColon = false;

	departTime = atoi(newReadDepartureTime);

	if (strcmp(readDepartureAMPM, "PM")) {

		departTime = departTime + 1200;

	}

	//takes input and stores into readArrivalTime
	printf("Arrival time: ");
	scanf("%s", readArrivalTime);

	//takes input and stores into readArrivalAMPM
	printf("AM or PM?: ");
	scanf("%s", readArrivalAMPM);

	//gives the time a number value and converts to military time, and denies invalid input times
	char newReadArrivalTime[4];

	for (int i = 0; i < strlen(readArrivalTime); i++)
	{
		if (readArrivalTime[i] != ':') {
			if (hasColon == true) {

				newReadArrivalTime[i - 1] = readArrivalTime[i];

			}
			else {
				newReadArrivalTime[i] = readArrivalTime[i];
			}

		}
		else {
			hasColon = true;
		}
	}

	arriveTime = atoi(newReadArrivalTime);

	if (strcmp(readArrivalAMPM, "PM")) {

		arriveTime = arriveTime + 1200;

	}

	//sets breakfastMeals, lunchMeals, and dinnerMeals based on arrival/departure times
	if (arriveTime < 700) {
		breakfastMeals = tripDays - 1;
		lunchMeals = tripDays - 1;
		dinnerMeals = tripDays - 1;
	}
	else {
		if (arriveTime < 1200) {
			breakfastMeals = tripDays - 2;
			lunchMeals = tripDays - 1;
			dinnerMeals = tripDays - 1;
		}
		else {
			if (arriveTime < 1800) {
				breakfastMeals = tripDays - 2;
				lunchMeals = tripDays - 2;
				dinnerMeals = tripDays - 1;
			}
			else {
				breakfastMeals = tripDays - 2;
				lunchMeals = tripDays - 2;
				dinnerMeals = tripDays - 2;
			}
		}
	}

	if (departTime > 1900) {
		breakfastMeals++;
		lunchMeals++;
		dinnerMeals++;
	}
	else {
		if (departTime > 1300) {
			lunchMeals++;
			dinnerMeals++;
		}
		else {
			if (departTime > 800) {
				dinnerMeals++;
			}
		}
	}

	//takes input and stores into breakfastCosts array
	breakfastCosts = (float*)malloc(breakfastMeals * sizeof(float));

	for (int i = 0; i < breakfastMeals; i++) {
		printf("Cost of breakfast %d: ", (i + 1));
		scanf("%f", &breakfastCosts[i]);
	}

	//takes input and stores into lunchCosts array
	lunchCosts = (float*)malloc(lunchMeals * sizeof(float));

	for (int i = 0; i < lunchMeals; i++) {
		printf("Cost of lunch %d: ", (i + 1));
		scanf("%f", &lunchCosts[i]);
	}

	//takes input and stores into dinnerCosts array
	dinnerCosts = (float*)malloc(dinnerMeals * sizeof(float));

	for (int i = 0; i < dinnerMeals; i++) {
		printf("Cost of dinner %d: ", (i + 1));
		scanf("%f", &dinnerCosts[i]);
	}


	//takes input and stores into airfaireCost
	printf("Round-trip airfaire cost: ");
	scanf("%f", &airfaireCost);

	//takes input and stores into carRentalCost
	printf("Total car rentals cost: ");
	scanf("%f", &carRentalCost);

	//takes input and stores into milesDriven
	printf("Miles driven in private car (0 if not applicable): ");
	scanf("%f", &milesDriven);

	//takes input and stores into seminarFees
	printf("Conference or seminar registreation fees: ");
	scanf("%f", &seminarFees);

	//takes input and stores into hotelCost


	//frees allocated memory
	free(breakfastCosts);

	return 0;
}