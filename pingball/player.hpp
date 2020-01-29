#ifndef PLAYER_HPP
#define PLAYER_HPP
#include <iostream>
#include <fstream>
#include <cmath>
#include <string>

class Player
{
	private:
	double aveWOBA;  //global var needed for all
	double ave, slg, obp, ops, era, k9, w9, wOBA, WAR, RC, ISO, wRAA;		//RC=Runs created
	int ab, plateA, triples, doubles, singles, SO;
	int homeruns, walks, HBP, hits, bases, sac, rbi;
	
	
	public:
	Player();
	void calcStats();
	void getAB();
	
	void printPlayerHitter();
	void addStat(char , int);
	double getWOBA();
	void setAveWOBA(double);
	void calcWRAA();
	
	
	
};


#endif
