//============================================================================
// Name        : Mars Rover Interview Question
// Author      : James Villamayor
// Version     :
// Copyright   : Your copyright notice
// Description :
//============================================================================

#include <iostream>
#include <cstring>
using namespace std;

int findPlacement(int size, int place, int direction);
string getDirection();
int convertDirection(string direction);

int main() {

	int size = 8; //designate size of board
	int place = 0;
	string direction;

	while(true){
		string direction;
		int numberedDirection;
		direction = getDirection();
		numberedDirection = convertDirection(direction); //convert string to int value for switch statement
		place = findPlacement(size, place, numberedDirection);
		cout << "The rover is now on space: " << place << endl << endl;

	}

	return 0;
}

int convertDirection(string direction){

	int numberedDirection;

	if(direction == "UP" || direction == "Up" || direction == "up")
		numberedDirection = 1;
	if(direction == "DOWN" || direction == "Down" || direction == "down")
		numberedDirection = 2;
	if(direction == "LEFT" || direction == "Left" || direction == "left")
		numberedDirection = 3;
	if(direction == "RIGHT" || direction == "Right" || direction == "right")
		numberedDirection = 4;

	return numberedDirection;

}

int findPlacement(int size, int currentPlacement, int direction){

	switch(direction){
	case 1:
		if(currentPlacement >= size)
			return currentPlacement - size;
		else
			return currentPlacement;
	case 2:
		if(currentPlacement >= size * size - size)
			return currentPlacement;
		else
			return currentPlacement + size;
	case 3:
		if(currentPlacement % size == 0)
			return currentPlacement;
		else
			return currentPlacement - 1;
	case 4:
		if (currentPlacement % size == size - 1)
			return currentPlacement;
		else
			return currentPlacement + 1;
	}

}

string getDirection(){

	string direction;
	cout << "Move which direction? ";
	cin  >> direction;
	return direction;

}
