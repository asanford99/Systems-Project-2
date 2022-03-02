#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<stdbool.h>


//gives the time a number value and converts to military time
int getTime(char* readTimePar, char* userAMPMPar) {
	int returnTime;
	int i;
	char newReadTime[4];

	bool hasColon = false;

	for (int i = 0; i < strlen(readTimePar); i++)
	{
		if (readTimePar[i] != ':') {

			if (hasColon == true) {

				newReadTime[i - 1] = readTimePar[i];

			}
			else {
				newReadTime[i] = readTimePar[i];
			}

		}
		else {
			hasColon = true;
		}
	}

	if (!strtod(newReadTime, NULL)) {

		return -1;

	}

	returnTime = atoi(newReadTime);

	if (returnTime < 0) {

		return -1;

	}

	if (!strcmp(userAMPMPar, "PM")) {

		returnTime = returnTime + 1200;

	}

	if (returnTime == 2400) {

		returnTime = 0;

	}

	return returnTime;

}

int main() {
	int tripDays = 0;
	int departTime = 0;
	int arriveTime = 0;
	float airfaireCost = 0;
	float carRentalCost = 0;
	float milesDriven = 0;
	float seminarFees = 0;
	float hotelCost = 0;

	char userInput[20];
	char readDepartureTime[6];
	char readDepartureAMPM[3];
	char readArrivalTime[6];
	char readArrivalAMPM[3];

	//takes input, validates it, and stores into tripDays
readTripDays:

	printf("Total number of days spent on trip (include departure and arrival days): ");
	scanf("%s", userInput);

	if (!strtod(userInput, NULL)) {

		printf("Invalid input. Please enter a valid integer.");

		goto readTripDays;

	}

	tripDays = atoi(userInput);

	//takes input and stores into readDepartureTime
readDeparture:

	printf("Departure time: ");
	scanf("%s", readDepartureTime);

	//takes input and stores into readDepartureAMPM
	printf("AM or PM?: ");
	scanf("%s", readDepartureAMPM);

	//validates input and gives the time a number value and converts to military time
	departTime = getTime(readDepartureTime, readDepartureAMPM);

	if (departTime == -1) {

		printf("Invalid input. Please put time in this format: 10:00.\n");

		goto readDeparture;

	}

	//takes input and stores into readArrivalTime
readArrival:

	printf("Arrival time: ");
	scanf("%s", readArrivalTime);

	//takes input and stores into readArrivalAMPM
	printf("AM or PM?: ");
	scanf("%s", readArrivalAMPM);

	//validates input and gives the time a number value and converts to military time
	arriveTime = getTime(readArrivalTime, readArrivalAMPM);

	if (arriveTime == -1) {

		printf("Invalid input. Please put time in this format: 10:00.\n");

		goto readDeparture;

	}

	printf("%d and %d", departTime, arriveTime);

	//takes input and stores into airfaireCost
	printf("Round-trip airfaire cost: $");
	scanf("%f", airfaireCost);

	//takes input and stores into carRentalCost
	printf("Total car rentals cost: $");
	scanf("%f", carRentalCost);

	//takes input and stores into milesDriven
	printf("Miles driven in private car (0 if not applicable): ");
	scanf("%f", milesDriven);

	//takes input and stores into seminarFees
	printf("Conference or seminar registreation fees: $");
	scanf("%f", seminarFees);

	//takes input and stores into hotelCost




	return 0;
}
