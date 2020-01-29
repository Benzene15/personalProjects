#include <iostream>
#include <fstream>
#include <cmath>
#include <string>
#include "player.hpp"

using namespace std;

Player::Player(){
	ave=0; 
	slg=0; 
	obp=0; 
	ops=0;
	era=0; 
	k9=0; 
	w9=0; 
	wOBA=0; 
	WAR=0;
	ab=0;
	plateA=0; 
	triples=0; 
	doubles=0; 
	singles=0;
	homeruns=0; 
	walks=0; 
	HBP=0; 
	hits=0; 
	bases=0; 
	sac=0;
	rbi=0;
	SO=0;
	RC=0;
	ISO=0;
}
void Player::calcStats(){
	ave=(hits*1.0)/ab;
	slg=(bases*1.0)/ab;
	obp=((hits+walks+HBP)*1.0)/(ab+walks+HBP+sac);
	
	wOBA=((.691*walks)+(.720*HBP)+(.870*singles)+(1.218*doubles)+(1.531*triples)+(1.941*homeruns));
	wOBA/=(ab+walks+HBP+sac);
	
	ops=slg+obp;
	RC=bases*(hits+walks)/(plateA+walks);
	ISO=slg-ave;
	WAR=wRAA+((20.0/600)*plateA);
}

void Player::printPlayerHitter(){
	cout.setf(ios::fixed,ios::floatfield);
    cout.precision(3);
	cout<<"WAR: "<<WAR<<endl<<"PA: "<<plateA<<endl<<"AB: "<<ab<<endl<<"Ave: "<<ave<<endl<<"slg: "<<slg<<endl<<"obp: "<<obp<<endl;
	cout<<"ops: "<<ops<<endl<<"wOBA: "<<wOBA<<endl<< "walks: "<<walks<<endl<<"HBP: "<<HBP<<endl<<"Sac: "<<sac<<endl;
	cout<<"rbi: "<<rbi<<endl<<"2B: "<<doubles<<endl<<"3B: "<<triples<<endl<<"HR: "<<homeruns<<endl<<"Strike outs: "<<SO<<endl<<"Runs created: "<<RC<<endl<<"Isolated Power: "<<ISO<<endl;
}
void Player::addStat(char hit, int runs){
	plateA++;
	if(hit=='4'||hit=='1'||hit=='2'|| hit=='3'||hit=='F'||hit=='D'|| hit=='O'||hit=='o' ||hit=='K'||hit=='k')
	{
		ab++;											//counts as at bats
		if(hit=='4'){
			homeruns++;
			bases+=4;
			hits++;
		}
		else if(hit=='1'){
			singles++;
			bases+=1;
			hits++;
		}
		else if(hit=='2'){
			doubles++;
			bases+=2;
			hits++;
		}
		else if(hit=='3'){
			triples++;
			bases+=3;
			hits++;
		}
		else if(hit=='K' ||hit=='k'){
			SO++;
		}
		
	}
	else{
		if(hit=='S'||hit=='s'){								//this is not an at bat
			sac++;
		}
		if(hit=='H'||hit=='h'){
			HBP++;
		}
		if(hit=='B'||hit=='b'){
			walks++;
		}
	}
	rbi+=runs;										//add RBI's at the end
}

void Player::getAB(){
	cout<<" "<<ab;
}

double Player::getWOBA(){
	return wOBA;
}
void Player::setAveWOBA(double inAveWOBA){
	aveWOBA=inAveWOBA;
}
void Player::calcWRAA(){
	wRAA=((wOBA-aveWOBA)/1.25)*(ab+walks+HBP+sac);
}
