#include <iostream>
#include <cmath>
#include <ctime>
#include <cstdlib>

bool cardMatch(int gameBoard[], int &firstSpot, int &secondSpot);



using namespace std;

int main ()
{
	int NUM_TRYS;
	cout<<"How many tries would you like to do?"<<endl;
	cin>>NUM_TRYS;
	srand(time(0));
	double wins=0;
	int deck[] = {2,2,2,2,3,3,3,3,4,4,4,4,														
				  5,5,5,5,6,6,6,6,7,7,7,7,
				  8,8,8,8,9,9,9,9,10,10,10,10,
				  11,11,11,11,12,12,12,12,
				  13,13,13,13,14,14,14,14};	
	int gameBoard[]= {-1,-2,-3,-4,-5,-6,-7,-8};
	
	int firstMatch, secondMatch;
	for(int i=0; i<NUM_TRYS; i++)
	{		
		
		int playIndex=0;
		int cardPlayed=0;
		while(playIndex<9 && cardPlayed!=52)
		{
			int randCard=rand()%52;
			int randCard2=rand()%52;
		
			if(cardMatch(gameBoard, firstMatch, secondMatch))
			{
				do{
					randCard=rand()%52;
					randCard2=rand()%52;
					}while(deck[randCard]==0 || deck[randCard2]==0 || randCard==randCard2);
				gameBoard[firstMatch]=deck[randCard];
				gameBoard[secondMatch]=deck[randCard2];
				
				deck[randCard]=0;
				deck[randCard2]=0;
				cardPlayed+=2;																//make a play
			}
			else 
			{
				do{
					randCard=rand()%52;
				}while(deck[randCard]==0);
				gameBoard[playIndex]=deck[randCard];
				//cout<<"Randcard1 "<<randCard<<endl;
				deck[randCard]=0;
				playIndex++;
				cardPlayed++;
			}
			cout<<gameBoard[0]<<" "<<gameBoard[1]<<" "<<gameBoard[2]<<" "<<gameBoard[3]<<" "<<endl;
			cout<<gameBoard[4]<<" "<<gameBoard[5]<<" "<<gameBoard[6]<<" "<<gameBoard[7]<<endl<<endl;
			
			if(cardPlayed==51 && gameBoard[7]==-8)
			{
				cardPlayed++;											//This is a weird win I actually got today 6/3/19
			}
		}
		if(cardPlayed==52){
			wins+=1;
		}
	{																		//setting arrays back long and messy no one wants to see this
	deck[0]=2;									
	deck[1]=2;
	deck[2]=2;
	deck[3]=2;
	
	deck[4]=3;
	deck[5]=3;
	deck[6]=3;
	deck[7]=3;

	deck[8]=4;
	deck[9]=4;
	deck[10]=4;
	deck[11]=4;					 
	
	deck[12]=5;
	deck[13]=5;
	deck[14]=5;
	deck[15]=5;	
	
	deck[16]=6;
	deck[17]=6;
	deck[18]=6;
	deck[19]=6;
	
	deck[20]=7;
	deck[21]=7;
	deck[22]=7;
	deck[23]=7;
	
	deck[24]=8;
	deck[25]=8;
	deck[26]=8;
	deck[27]=8;
	
	deck[28]=9;
	deck[29]=9;
	deck[30]=9;
	deck[31]=9;

	deck[32]=10;
	deck[33]=10;
	deck[34]=10;
	deck[35]=10;
	
	deck[36]=11;
	deck[37]=11;
	deck[38]=11;
	deck[39]=11;
	
	deck[40]=12;
	deck[41]=12;
	deck[42]=12;
	deck[43]=12;
	
	deck[44]=13;
	deck[45]=13;
	deck[46]=13;
	deck[47]=13;
	
	deck[48]=14;
	deck[49]=14;
	deck[50]=14;
	deck[51]=14;
	
	gameBoard[0]=-1;
	gameBoard[1]=-2;
	gameBoard[2]=-3;
	gameBoard[3]=-4;
	gameBoard[4]=-5;
	gameBoard[5]=-6;
	gameBoard[6]=-7;
	gameBoard[7]=-8;
}
	
	}
	cout<<"8 cards"<<endl;
	cout<<"Sample Size: "<<NUM_TRYS<<endl;
	cout<<(wins/NUM_TRYS)*100<<" Win Percentage"<<endl;
	return 0;
}

bool cardMatch(int gameBoard[], int &firstSpot, int &secondSpot)
{
	int isTrue=0;
	for(int i=1; i<8;i++)
	{
		if(gameBoard[0]==gameBoard[i])
		{
			firstSpot=0;
			secondSpot=i;
			isTrue++;
		}	
	}
	for(int i=2;i<8;i++)
	{
		if(gameBoard[1]==gameBoard[i])
		{
			firstSpot=1;
			secondSpot=i;
			isTrue++;
		}
	}
	for(int i=3;i<8;i++)
	{
		if(gameBoard[2]==gameBoard[i])
		{
			firstSpot=2;
			secondSpot=i;
			isTrue++;
		}
	}
	for(int i=4;i<8;i++)
	{
		if(gameBoard[3]==gameBoard[i])
		{
			firstSpot=3;
			secondSpot=i;
			isTrue++;
		}
	}
	for(int i=5;i<8;i++)
	{
		if(gameBoard[4]==gameBoard[i])
		{
			firstSpot=4;
			secondSpot=i;
			isTrue++;
		}
	}
	for(int i=6;i<8;i++)
	{
		if(gameBoard[5]==gameBoard[i])
		{
			firstSpot=5;
			secondSpot=i;
			isTrue++;
		}
	}
	for(int i=7;i<8;i++)
	{
		if(gameBoard[6]==gameBoard[i])
		{
			firstSpot=6;
			secondSpot=i;
			isTrue++;
		}
	}
	
	if(isTrue!=0)
	{
		return true;
	}
	else 
	{
		return false;
	}
	

}
