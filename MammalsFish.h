
#ifndef MAMMALSFISH_H
#define MAMMALSFISH_H

#include "Mammals.h"
#include "Fish.h"

class MammalsFish :  public Mammals, public Fish
{
public:
	MammalsFish();//set the default color to GRAY and other params to 0
	MammalsFish( const char* color, int childs, float avgLifetime, float preg, float milk, int fin, int gills );//init the MammalsFish with a given attributes
	MammalsFish( ifstream& in_file );//init the MammalsFish from a binary file
	virtual ~MammalsFish();
	// /////////////MY ADDITION FUNCTION
public:
	void printData(ofstream& out)const;///print own data - TXT file
	void readData(ifstream& in);///read own data - TXT file

	void printBinData(ofstream& out)const;///print own data - BinFile
	virtual void saveBinType(ofstream& out)const = 0;///pure virutal
	virtual void saveTxtType(ofstream& out)const = 0;
protected:
	virtual void saveAddition(ofstream& out)const=0;///pure virtual
	virtual void saveBinAddition(ofstream& out)const = 0;//pure virtual
	virtual void loadAdditon(ifstream& in) = 0;//pure virtual;


};

#endif // ifndef