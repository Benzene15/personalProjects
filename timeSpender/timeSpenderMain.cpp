#include <iostream>
#include <cmath>
#include <chrono>
#include <fstream>
using namespace std;

void spendingTime(int &timeSpend);
void manualTimeAdd(int &lookingAtDog, int &switchTime, int &engineeringTime, int &phoneTime, int &hangingTime, int &eatTime, int &bikeTime);
void activityOutput(int myTime, ostream &out);
void timeOutput(int lookingAtDog, int switchTime, int engineeringTime, int phoneTime, int hangingTime, int eatTime, int bikeTime, ostream &out);
void minSecAdd(int &activity, int min, int sec);

int main()
{
	int lookingAtDog=0, switchTime=0, engineeringTime=0, phoneTime=0, hangingTime=0, eatTime=0, bikeTime=0;
	char whatDo;
	while(1==1)
	{
		cout<<endl;
		timeOutput(lookingAtDog, switchTime, engineeringTime, phoneTime, hangingTime, eatTime, bikeTime, cout);
		cout<<"A= Add time manually"<<endl;
		cout<<"Anything else Day is done"<<endl;
		cin>>whatDo;
		if(whatDo=='D' || whatDo=='d'){												//recording live time actions with spendingTime func
			spendingTime(lookingAtDog);
		}else if(whatDo=='S'|| whatDo=='s'){
			spendingTime(switchTime);		
		}else if(whatDo=='E'||whatDo=='e'){
			spendingTime(engineeringTime);
		}else if(whatDo=='P'||whatDo=='p'){
			spendingTime(phoneTime);
		}else if(whatDo=='H'|| whatDo=='h'){
			spendingTime(hangingTime);
		}else if(whatDo=='F'||whatDo=='f'){
			spendingTime(eatTime);
		}else if(whatDo=='B' || whatDo=='b'){
			spendingTime(bikeTime);
			
		}else if(whatDo=='A' || whatDo=='a'){
			manualTimeAdd(lookingAtDog, switchTime, engineeringTime, phoneTime, hangingTime, eatTime, bikeTime);    //add time on your own
		}
		else{
			int day, month, year;
			cout<<"Insert the date DD MM YYYY: ";
			cin>>day>>month>>year;																							//output to the file the day and how the day went
			ofstream fout;
			fout.open("myLifeInAFile.dat", ios::app);
			fout<<day<<"/"<<month<<"/"<<year<<endl;
			timeOutput(lookingAtDog, switchTime, engineeringTime, phoneTime, hangingTime, eatTime, bikeTime, fout);
			fout<<"-----------------------------------------------";
			cout<<endl;
			
			return 0;
		}
		
	}
	return 0;

}

void spendingTime(int &timeSpend)
{
	int thisAct=0;
	cout<<"Hit any key to say that your are done	"<<endl;
	auto start=chrono::steady_clock::now();								//This is where we wnat to count how long I have been doing somehting
	string input="heck";
	while(input=="heck")
	{
		cin>>input;
	}
	auto end=chrono::steady_clock::now();
	
	thisAct=chrono::duration_cast<chrono::seconds>(end - start).count();
	timeSpend+=thisAct;
	cout<<"You did this activity for "; activityOutput(thisAct, cout);
	cout<<endl;
}


void activityOutput(int myTime, ostream &out)
{
	int mins, seconds;
	mins=myTime/60;
	seconds=myTime-(mins*60);
	out<<mins<<" Minutes "<<seconds<<" Seconds"<<endl;
}

void manualTimeAdd(int &lookingAtDog, int &switchTime, int &engineeringTime, int &phoneTime, int &hangingTime, int &eatTime, int &bikeTime)
{
	char whatDo;
	cout<<endl<<"What activity did you just do?"<<endl;
	timeOutput(lookingAtDog, switchTime, engineeringTime, phoneTime, hangingTime, eatTime, bikeTime, cout);
	cin>>whatDo;
	int timeAddedMin=0, timeAddedSec=0;
	cout<<"How long did you do it for? (Mins Seconds) ";	
	cin>>timeAddedMin>>timeAddedSec;
	if(timeAddedMin<0 || timeAddedSec<0){
		cout<<"NAY TO NEGATIVE"<<endl;				
	}																//make each activity have an adding fuction that adds the input.
	else if(whatDo=='D' || whatDo=='d'){
		minSecAdd(lookingAtDog, timeAddedMin, timeAddedSec);
	}else if(whatDo=='S' || whatDo=='s'){
		minSecAdd(switchTime, timeAddedMin, timeAddedSec);	
	}else if(whatDo=='E' ||whatDo=='e'){
		minSecAdd(engineeringTime, timeAddedMin, timeAddedSec);
	}else if(whatDo=='P' || whatDo=='p'){
		minSecAdd(phoneTime, timeAddedMin, timeAddedSec);
	}else if(whatDo=='H' || whatDo=='h'){
		minSecAdd(hangingTime, timeAddedMin, timeAddedSec);
	}else if(whatDo=='F' || whatDo=='f'){
		minSecAdd(eatTime, timeAddedMin, timeAddedSec);
	}else if(whatDo=='B' || whatDo=='b'){
		minSecAdd(bikeTime, timeAddedMin, timeAddedSec);		
	}
	else{
		cout<<"INVALID!!"<<endl;
	}
}

void timeOutput(int lookingAtDog, int switchTime, int engineeringTime, int phoneTime, int hangingTime, int eatTime, int bikeTime, ostream &out)
{
	out<<"D= Dog: "; activityOutput(lookingAtDog, out);
	out<<"S= Switch: ";activityOutput(switchTime, out);
	out<<"E= Engineering: ";activityOutput(engineeringTime, out);
	out<<"P= Phone: ";activityOutput(phoneTime, out);
	out<<"H= Hanging: ";activityOutput(hangingTime, out);
	out<<"F= Eating food: ";activityOutput(eatTime, out);
	out<<"B= Biking around: ";activityOutput(bikeTime, out);
	
}

void minSecAdd(int &activity, int min, int sec)
{
	activity+=((60*min)+sec);
}

