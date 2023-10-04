
#ifndef BIRDS_H
#define BIRDS_H

#include "Animal.h"

class Birds : public Animal
{
public:
	Birds();//set the default color to GRAY and other params to 0
	Birds( const char* color, int childs, float avgLifetime, float incubation );//init the Birds with a given attributes
	Birds( ifstream& in_file );//init the Birds from a binary file
	virtual ~Birds();

public:
	float		GetIncubationTime() const;//return the incubation time of the animal
	// /////////////MY ADDITION FUNCTION
public:
	void printData(ofstream& out)const;///print own data - txt file
	void readData(ifstream& in);///read own data - TXT file
	void printBinData(ofstream& out)const;///print own data - BinFile
	virtual void saveBinType(ofstream& out)const = 0;///pure virutal
	virtual void saveTxtType(ofstream& out)const = 0;///pure virutal

protected:
	virtual void saveAddition(ofstream& out)const = 0;//pure virtual
	virtual void saveBinAddition(ofstream& out)const = 0;//pure virtual
	virtual void loadAdditon(ifstream& in) = 0;//pure virtual;

protected:
	float m_incubationTime;
};

#endif // ifndef