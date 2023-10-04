
#ifndef GOLDFISH_H
#define GOLDFISH_H

#include "MammalsFish.h"

class GoldFish : public MammalsFish
{
public:
	GoldFish();//set the default color to GRAY and other params to 0
	GoldFish( const char* color, int childs, float avgLifetime, float preg, float milk, int fin, int gills, float avgW, float avgL );//init the GoldFish with a given attributes
	GoldFish( ifstream& in_file );//init the GoldFish from a binary file
	virtual ~GoldFish();

public:
	float		GetWeight() const;//return the avg weight of the gold fish
	float		GetLength() const;//return the avg length of the gold fish
	// /////////////MY ADDITION FUNCTION
	virtual void saveBinType(ofstream& out)const;///save the first letters.
	virtual void saveTxtType(ofstream& out)const;///pure virutal

//////public:
//////	void printData(ofstream& out)const;///print own data
protected:
	virtual void saveAddition(ofstream& out)const;///print base data and then own data.
	virtual void saveBinAddition(ofstream& out)const;///print data in BinFile
	virtual void loadAdditon(ifstream& in);//read Mammal data and Fish data then his own data

protected:
	float m_avgWeight;
	float m_avgLength;
};

#endif // ifndef