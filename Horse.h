
#ifndef HORSE_H
#define HORSE_H

#include "Mammals.h"

class Horse : public Mammals
{
public:
	Horse();//set the default color to GRAY and other params to 0
	Horse( const char* color, int childs, float avgLifetime, float preg, float milk, const char* type );//init the Horse with a given attributes
	Horse( ifstream& in_file );//init the Horse from a binary file
	virtual ~Horse();

public:
	const char*		GetType() const;//return the type of the horse
	// /////////////MY ADDITION FUNCTION
//////public:
	virtual void saveBinType(ofstream& out)const;///save the first letters.
	virtual void saveTxtType(ofstream& out)const;///pure virutal

//////	void printData(ofstream& out)const;///print own data
protected:
	virtual void saveAddition(ofstream& out)const;
	virtual void saveBinAddition(ofstream& out)const;//print own data in BinFile - virtual function
	virtual void loadAdditon(ifstream& in);//read mammal data and then his own data

protected:
	char*	m_type;
};

#endif // ifndef