#include <iostream>
#include <cmath>
#include <string>
#include <fstream>
#include <ostream>
#include "player.hpp"

using namespace std;

int main(){
	Player hitter[5];
	string player[5]={"beaner.txt", "DougDimmeDome.txt", "dumbAss.txt", "elNegro.txt", "PDPaul.txt"};
	
	for(int counter=0; counter<5; counter++)
	{
		fstream fin;											//creating input object	
		fin.open(player[counter].c_str());
		
		
		string ignore;
		char play;
		int rbi;

		fin>>ignore>>ignore>>ignore;
		
		while(fin>>play>>rbi)								//reading alg
		{
			/*cout<<play<<endl;
			cout<<play<<" "<<rbi; 
			hitter.getAB();
			cout<<endl;*/
			hitter[counter].addStat(play,rbi);					
			
		}
		double aveWOBA=0;									//making the average WOBA
		for(int i=0; i<5; i++)
		{
			aveWOBA+=hitter[i].getWOBA();
		}
		aveWOBA/=5;
		
		for(int j=0; j<5;j++)
		{
			hitter[j].setAveWOBA(aveWOBA);
		}
		
		
		hitter[counter].calcStats();									//calculation of stats
		
		cout<<endl<<player[counter].substr(0, player[counter].length()-4)<<endl;
		
		hitter[counter].printPlayerHitter();							//print
		
		fin.close();
	}
	
	return 0;
}


