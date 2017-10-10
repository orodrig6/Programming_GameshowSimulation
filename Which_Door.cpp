#include <iostream>
#include <string>
#include <time.h>
using namespace std;


/*
This program is designed to simulate a popular gameshow where the user is asked to pick one of 3 doors.
This program allows two users to play. The first user will constantly stick to their original choice while the second user
will switch doors
*/
int doorReveal(int arr[], int pick) {
	for (int i = 0; i < 3; i++) {
		if (pick != i && arr[i] == 0) return i; //cycles through the array, returning the index of the door with a zero that we haven't picked
	}
}

int main(int argc, char* argv[]) {
	srand(time(0)); // so we will get new random numbers during each compile
	
	int check = 1,games=0, n=0;

	int ozzy = 0, sean = 0;
	cout << "How many games we're playing?" << endl;
	cin >> n;
	//while (check) { //if we want to constantly ask the user if they want to play uncomment this and LINE X
    while (games<n) {
	//	int rand_int = 0, zero_count = 0, one_count = 0, two_count = 0; //used to keep track that the numbers were distributed evenly and randomly.
		int choice = 0, finalPick = 0, reveal = 0, rand_int = 0;
		string response, hopDoor;
		
	int	arr[3] = { 0,0,0 };

		
		rand_int = rand() % 3;
		arr[rand_int] = 1; //assigns 1 randomly to one of the doors
		cout << "\nPick a door!\n";
		cin >> choice;
		while (choice > 3 || choice < 1) {
			
			cout << "Pick a door between 1 and 3 you jerk!"<<endl;
			cin.ignore();
				cin >> choice;
		}
		choice--; //decrement it by 1 to adjust to the array index
		reveal = doorReveal(arr, choice);//gives me the index of a door to reveal. 
		cout << "Door number " << reveal + 1 << " is empty! Will you switch??(yes for ozzy, no for sean)" << endl;
		cin.ignore();
		getline(cin, hopDoor);
		if (hopDoor == "yes") { //if the user decided to switch then I know to switch from my current pick
			for (int a = 0; a < 3; a++) {
				if (a != choice && a != reveal)
					finalPick = a; //finds the index that wasn't our original pick and wasn't revealed to be 0
			}
			if (arr[finalPick] == 1) {
				ozzy++; //since we switched and I was right, I get a point
				cout << "\nCorrect ozzy!\n";
			}
		}
		else {
			finalPick = choice;
			if (arr[finalPick] == 1) {
				sean++; //since we didn't switch and it was the right door. Sean gets a point. 
				cout << "Correct sean!\n";
			}
		}
		if (arr[finalPick] == 0)
			cout << "Wrong!\n";

		//LINE X: Uncomment the section below to prompt the user after each game
	/*	cout << "Go again? type 'yes' or 'no'" << endl;
		
		getline(cin, response);
		if (response == "yes") { 
			
			check = 1; }
		else check = 0; */
		games++;
		if (games == (n / 2)) cout << "ozzy's turn!" << endl;

	}
	cout << "Total stats:\t Ozzy:" << ozzy << "\t Sean:" << sean << "\n games played:" << games << endl;

}