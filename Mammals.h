
#ifndef MAMMALS_H
#define MAMMALS_H

#include "Animal.h"

class Mammals :virtual public Animal
{
public:
	Mammals();//set the default color to GRAY and other params to 0
	Mammals( const char* color, int childs, float avgLifetime, float preg, float milk );//init the Mammals with a given attributes
	Mammals( ifstream& in_file );//init the Mammals from a binary file
	virtual ~Mammals();

public:
	float		GetPregnanceTime() const;//return the pregnance time of the animal
	float		GetMilk() const;//return the milk liters of the animal
	// /////////////MY ADDITION FUNCTION
public:
	void printData(ofstream& out)const;///print own data - TXT file
	void readData(ifstream& in);///read own data - TXT file

	void printBinData(ofstream& out)const;///print own data - BinFile
	virtual void saveBinType(ofstream& out)const = 0;///pure virutal
	virtual void saveTxtType(ofstream& out)const=0;///pure virutal

protected:
	virtual void saveAddition(ofstream& out)const = 0;//pure virtual
	virtual void saveBinAddition(ofstream& out)const = 0;//pure virtual
	virtual void loadAdditon(ifstream& in) = 0;//pure virtual;


protected:
	float m_pregnancyTime;
	float m_milkLiters;
};

#endif // ifndef