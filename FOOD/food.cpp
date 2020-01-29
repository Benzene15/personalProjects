#include <iostream>
#include <string>
#include <chrono>
#include <ctime>
#include <cstdlib>
using namespace std;


int main()
{
	srand(time(0));
	char yorn;
	do{
	cout<<"Let's decide what you want to eat"<<endl;
	
	int output=rand()%27;
	string choices[]={"Culvers", "Bdubs", "Panda", "Tally's", "Noodles", "Panera", "Chili's", "Qdoba", "Jimmy Johns", "Denny's", "Daddy-oh's", "Food at Home", "Subway", "Jersey Mikes", "Fire House", "Kat's", 
		"Cafe Hollander", "Olive Garden", "Target", "Pizza hut", "Taco Bell", "La Estaction","El palmar","Dominos", "Mia's", "Papa Johns", "Rosaiti's"};
	
	cout<<"My humble suggestion is "<<choices[output]<<" I hope that you would like that!"<<endl;
	cout<<"Would you like to try again? (Y/N)"<<endl;
	
	cin>>yorn;
	}while(yorn=='Y' || yorn=='y');
	return 0;
}
