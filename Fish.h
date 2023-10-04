
#ifndef FISH_H
#define FISH_H

#include "Animal.h"

class Fish :virtual public Animal
{
public:
	Fish();//set the default color to GRAY and other params to 0
	Fish( const char* color, int childs, float avgLifetime, int fin, int gills );//init the Fish with a given attributes
	Fish( ifstream& in_file );//init the Fish from a binary file
	virtual ~Fish();

public:
	int		GetFinCount() const;//return the fin count of the animal
	int		GetGillsCount() const;//return the gills count of the animal
	// /////////////MY ADDITION FUNCTION - save to TXT or BinFile
public:
	void printData(ofstream& out)const;///print own data
	void readData(ifstream& in);///read own data - TXT file
	void printBinData(ofstream& out)const;///print own data - BinFile
	virtual void saveBinType(ofstream& out)const = 0;///pure virutal
	virtual void saveTxtType(ofstream& out)const = 0;///pure virutal

protected:
	virtual void saveAddition(ofstream& out)const = 0;//pure virtual
	virtual void saveBinAddition(ofstream& out)const = 0;//pure virtual
	virtual void loadAdditon(ifstream& in) = 0;//pure virtual;



protected:
	int m_finCount;
	int m_gillsCount;
};

#endif // ifndef