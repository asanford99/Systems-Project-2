#include<stdio.h>
#include<stdlib.h>
#include<string.h>

int main() {
	int tripDays = 0;
	int departTime = 0;
	int arriveTime = 0;
	float airfaireCost = 0;
	float carRentalCost = 0;
	float milesDriven = 0;
	float seminarFees = 0;
	float hotelCost = 0;

	char readDepartureTime[5];
	char readDepartureAMPM[2];
	char readArrivalTime[5];
	char readArrivalAMPM[2];

	//takes input and stores into tripDays
	printf("Total number of days spent on trip (include departure and arrival days): ");
	scanf("%d", &tripDays);

	//takes input and stores into readDepartureTime
	printf("Departure time: ");
	scanf("%s", &readDepartureTime);

	//takes input and stores into readDepartureAMPM
	printf("AM or PM?: ");
	scanf("%s", &readDepartureAMPM);

	//gives the time a number value and converts to military time
	char newReadDepartureTime[4];

	for (int i = 0; i < strlen(readDepartureTime); ++i)
	{
		if (&readDepartureTime[i] != ":") {

			strncat(newReadDepartureTime, &readDepartureTime[i], 1);

		}
	}

	departTime = atoi(newReadDepartureTime);

	if (readDepartureAMPM == "PM") {

		departTime = departTime + 1200;

	}

	//takes input and stores into readArrivalTime
	printf("Arrival time: ");
	scanf("%s", &readArrivalTime);

	//takes input and stores into readArrivalAMPM
	printf("AM or PM?: ");
	scanf("%s", &readArrivalAMPM);

	//gives the time a number value and converts to military time
	char newReadArrivalTime[4];

	for (int i = 0; i < strlen(readArrivalTime); ++i)
	{
		if (&readArrivalTime[i] != ":") {

			strncat(newReadArrivalTime, &readArrivalTime[i], 1);

		}
	}

	arriveTime = atoi(newReadArrivalTime);

	if (readArrivalAMPM == "PM") {

		arriveTime = arriveTime + 1200;

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




	return 0;
}