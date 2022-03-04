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

		if(strcmp(readTimePar, "0")){

			return -1;

		}

	}

	returnTime = atoi(newReadTime);

	if (returnTime < 0) {

		return -1;

	}

	if (!strcmp(userAMPMPar, "PM")) {

		returnTime = returnTime + 1200;

	}
	else{

		if (strcmp(userAMPMPar, "AM")){

			return -1;

		}
	}

	if (returnTime == 2400) {

		returnTime = 0;

	}

	if (returnTime > 2400){

		return -1;

	}

	return returnTime;

}

int main() {
	int tripDays = 0;
	int taxiDays = 0;
	int departTime = 0;
	int arriveTime = 0;
	int i;
	float userNum;
	float airfaireCost = 0;
	float carRentalCost = 0;
	float milesDriven = 0;
	float seminarFees = 0;

	bool usedTaxi;

	char userInput[20];
	char readDepartureTime[10];
	char readDepartureAMPM[10];
	char readArrivalTime[10];
	char readArrivalAMPM[10];

	//takes input, validates it, and stores into tripDays
	readTripDays:

	printf("Total number of days spent on trip (include departure and arrival days): ");
	scanf("%s", userInput);

	if (!strtod(userInput, NULL)) {

		printf("Invalid input. Please enter a valid number of trip days.\n");

		goto readTripDays;

	}

	tripDays = atoi(userInput);

	if (tripDays < 1){

		printf("Invalid input. Please enter a number of trip days.\n");

		goto readTripDays;

	}

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

		printf("Invalid input. Please put time in this format: 10:00, and AM or PM in this format: AM.\n");

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

		printf("Invalid input. Please put time in this format: 10:00, and AM or PM in this format: AM.\n");

		goto readArrival;

	}

	//takes input, validates, and stores into airfaireCost
	readAirfaire:

	printf("Round-trip airfaire cost: $");
	scanf("%s", userInput);

	if (!strtof(userInput, NULL)){

		if(strcmp(userInput, "0")){

			printf("Invalid input. Please use a valid monetary amount.\n");

			goto readAirfaire;

		}

	}

	airfaireCost = atof(userInput);

	if (airfaireCost < 0){

		printf("Invalid input. Please use a valid monetary amount.\n");

		goto readSeminarFees;
		
	}

	//takes input, validates, and stores into carRentalCost
	readCarRental:

	printf("Total car rentals cost: $");
	scanf("%s", userInput);

	if (!strtof(userInput, NULL)){

		if(strcmp(userInput, "0")){

			printf("Invalid input. Please use a valid monetary amount.\n");

			goto readCarRental;

		}

	}

	carRentalCost = atof(userInput);

	if (carRentalCost < 0){

		printf("Invalid input. Please use a valid monetary amount.\n");

		goto readSeminarFees;
		
	}

	//takes input, validates, and stores into milesDriven
	readMilesDriven:

	printf("Miles driven in private car (0 if not applicable): ");
	scanf("%s", userInput);

	if (!strtof(userInput, NULL)){

		if(strcmp(userInput, "0")){

			printf("Invalid input. Please use a valid number.\n");

			goto readMilesDriven;

		}

	}

	milesDriven = atof(userInput);

	if (milesDriven < 0){

		printf("Invalid input. Please use a valid number.\n");

		goto readMilesDriven;
		
	}

	//takes input, validates, and stores into seminarFees
	readSeminarFees:

	printf("Conference or seminar registreation fees: $");
	scanf("%s", userInput);

	if (!strtof(userInput, NULL)){

		if(strcmp(userInput, "0")){

			printf("Invalid input. Please use a valid monetary amount.\n");

			goto readSeminarFees;

		}

	}

	seminarFees = atof(userInput);

	if (seminarFees < 0){

		printf("Invalid input. Please use a valid monetary amount.\n");

		goto readSeminarFees;

	}

	//declares dynamic array hotelCosts, takes input, validates and stores into hotelCosts
	float* hotelCosts = (float*)malloc(tripDays * sizeof(float));

	for (i = 0; i < (tripDays - 1); i++){

		readHotelCosts:

		printf("Hotel cost for night %d: $", (i + 1));
		scanf("%s", userInput);

		if (!strtof(userInput, NULL)){

			if(strcmp(userInput, "0")){

				printf("Invalid input. Please use a valid monetary amount.\n");

				goto readHotelCosts;

			}

		}

		else{

			userNum = atof(userInput);

			if (userNum < 0){

				printf("Invalid input. Please use a valid monetary amount.\n");

				goto readHotelCosts;

			}

			hotelCosts[i] = userNum;

		}

	}

	
	//declares dynamic array breakfastCosts, takes input, validates,  and stores into breakfastCosts
	int excludeDays = 0;

	if (departTime < 700){

		excludeDays += 1;

	}

	if (arriveTime > 800){

		excludeDays += 1;

	}

	float* breakfastCosts = (float*)malloc((tripDays - excludeDays) * sizeof(float));

	for (i = 0; i < (tripDays - excludeDays); i++){

		readBreakfastCosts:

		printf("Breakfast price %d: $", (i + 1));
		scanf("%s", userInput);

		if (!strtof(userInput, NULL)){

			if(strcmp(userInput, "0")){

				printf("Invalid input. Please use a valid monetary amount.\n");

				goto readBreakfastCosts;

			}

		}

		else{

			userNum = atof(userInput);

			if (userNum < 0){

				printf("Invalid input. Please use a valid monetary amount.\n");

				goto readBreakfastCosts;

			}

			breakfastCosts[i] = userNum;

		}

	}

	//declares dynamic array lunchCosts, takes input, validates,  and stores into lunchCosts
	excludeDays = 0;

	if (departTime < 1200){

		excludeDays += 1;

	}

	if (arriveTime > 1300){

		excludeDays += 1;

	}

	float* lunchCosts = (float*)malloc((tripDays - excludeDays) * sizeof(float));

	for (i = 0; i < (tripDays - excludeDays); i++){

		readLunchCosts:

		printf("Lunch price %d: $", (i + 1));
		scanf("%s", userInput);

		if (!strtof(userInput, NULL)){

			if(strcmp(userInput, "0")){

				printf("Invalid input. Please use a valid monetary amount.\n");

				goto readLunchCosts;

			}

		}

		else{

			userNum = atof(userInput);

			if (userNum < 0){

				printf("Invalid input. Please use a valid monetary amount.\n");

				goto readLunchCosts;

			}

			lunchCosts[i] = userNum;

		}

	}

	//declares dynamic array dinnerCosts, takes input, validates,  and stores into dinnerCosts
	excludeDays = 0;

	if (departTime < 1800){

		excludeDays += 1;

	}

	if (arriveTime > 1900){

		excludeDays += 1;

	}

	float* dinnerCosts = (float*)malloc((tripDays - excludeDays) * sizeof(float));

	for (i = 0; i < (tripDays - excludeDays); i++){

		readDinnerCosts:

		printf("Dinner price %d: $", (i + 1));
		scanf("%s", userInput);

		if (!strtof(userInput, NULL)){

			if(strcmp(userInput, "0")){

				printf("Invalid input. Please use a valid monetary amount.\n");

				goto readDinnerCosts;

			}

		}

		else{

			userNum = atof(userInput);

			if (userNum < 0){

				printf("Invalid input. Please use a valid monetary amount.\n");

				goto readDinnerCosts;

			}

			dinnerCosts[i] = userNum;

		}

	}

	//declares dynamic array parkingCosts, takes input, validates and stores into parkingCosts
	float* parkingCosts = (float*)malloc(tripDays * sizeof(float));

	for (i = 0; i < (tripDays); i++){

		readParkingCosts:

		printf("Parking costs for day %d: $", (i + 1));
		scanf("%s", userInput);

		if (!strtof(userInput, NULL)){

			if(strcmp(userInput, "0")){

				printf("Invalid input. Please use a valid monetary amount.\n");

				goto readParkingCosts;

			}

		}

		else{

			userNum = atof(userInput);

			if (userNum < 0){

				printf("Invalid input. Please use a valid monetary amount.\n");

				goto readParkingCosts;

			}

			parkingCosts[i] = userNum;

		}

	}

	//checks if a taxi was used during trip. if so, inputs the amount of days a taxi was used, declares dynamic array taxiCosts, takes input, validates and stores into taxiCosts
	readUsedTaxi:

	printf("Was a taxi used during this trip? (Yes or No): ");
	scanf("%s", userInput);

	if (!strcmp(userInput, "Yes")){

		usedTaxi = true;

	}
	else{

		if (strcmp(userInput, "No")){

			printf("Invalid input. Please type Yes or No.\n");

			goto readUsedTaxi;

		}

		usedTaxi = false;

	}

	if (usedTaxi == true){
		readTaxiDays:

		printf("How many days was a taxi used?: ");
		scanf("%s", userInput);

		if (!strtod(userInput, NULL)){

			if(strcmp(userInput, "0")){

				printf("Invalid input. Please enter a valid number of days.\n");

				goto readTaxiDays;

			}

		}

		taxiDays = atoi(userInput);

		if (taxiDays < 0){

			printf("Invalid input. Please enter a valid number of days.\n");

			goto readTaxiDays;

		}

		if (taxiDays > tripDays){

			printf("Invalid input. Please enter a valid number of days less than the amount of days on trip.\n");

			goto readTaxiDays;

		}

		float* taxiCosts = (float*)malloc(taxiDays * sizeof(float));

		for (i = 0; i < taxiDays; i++){

			readTaxiCosts:

			printf("Taxi costs for day %d used: $", (i + 1));
			scanf("%s", userInput);

			if (!strtof(userInput, NULL)){

				if(strcmp(userInput, "0")){

					printf("Invalid input. Please use a valid monetary amount.\n");

					goto readTaxiCosts;

				}

			}

			else{

				userNum = atof(userInput);

				if (userNum < 0){

					printf("Invalid input. Please use a valid monetary amount.\n");

					goto readTaxiCosts;

				}

				taxiCosts[i] = userNum;

			}

		}

	}


	
	free(hotelCosts);
	free(parkingCosts);
	free(breakfastCosts);
	free(lunchCosts);
	free(dinnerCosts);


	return 0;
}
