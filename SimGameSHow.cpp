#include <iostream>
#include <string>
#include <time.h>
using namespace std;


/*
This program is designed to simulate a popular gameshow where the user is asked to pick one of 3 doors.
After selection of a door the host reveals a door that isn't the winner and allows you to switch if you want.
A friend of mine claimed it made no difference so I created this program to demonstrate otherwise
*/
int doorReveal(int arr[], int pick) {
	for (int i = 0; i < 3; i++) {
		if (pick != i && arr[i] == 0) return i;
	}
}

int main(int argc, char* argv[]) {
	srand(time(0)); // so we will get new random numbers during each compile

	int games = 0,n=1000; //n is how many games we're running for each person. 
						  //games is a counter I use for the while loop

	int ozzy = 0, sean = 0; //keep track of how many wins each person has

		while (games < n) {

			int choice = 0, sean_choice = 0, finalPick = 0, reveal = 0, rand_int = 0;
			//choice is my pick, sean_choice is obvious. Final pick is my choice after I'm forced to switch
			// reveal is the index of the revealed door based on my choice
			//rand_int is going to be a random number between 0 and 2;

			int	arr[3] = { 0,0,0 };
			//array for the 3 doors arr[0] door 1, arr[1] door 2, arr[2] door 3

			rand_int = rand() % 3; //random number between 0 and 2 (index of array)
			arr[rand_int] = 1; //assigns 1 randomly to one of the doors to make it the winner
			choice = rand() % 3; //randomly picks a choice for me
			sean_choice = rand() % 3; //randmoly picks a choice for sean. 


			reveal = doorReveal(arr, choice);//gives me the index of a door to reveal. 


			for (int a = 0; a < 3; a++) {
				if (a != choice && a != reveal)
					finalPick = a; //finds the index of the door I have to switch to and forces me to use it. 
			}
			if (arr[finalPick] == 1) {
				ozzy++; //since we switched and I was right, I get a point
			}
			if (arr[sean_choice] == 1) {
				sean++;
				//if sean guessed right he gets a point
			}
			games++; //finished a complete game, increment games then go to top of while loop

		}
		cout << "Total stats:\t Ozzy:" << ozzy << "\t Sean:" << sean << "\n games played:" << games << endl;



}