
#ifndef MERMAID_H
#define MERMAID_H

#include "MammalsFish.h"

class Mermaid : public MammalsFish
{
public:
	Mermaid();//set the default color to GRAY and other params to 0
	Mermaid( const char* color, int childs, float avgLifetime, float preg, float milk, int fin, int gills, const char* firstName, const char* lastName );//init the Mermaid with a given attributes
	Mermaid( ifstream& in_file );//init the Mermaid from a binary file
	virtual ~Mermaid();

public:
	const char*		GetFirstName() const;//return the first name of the mermaid
	const char*		GetLastName() const;//return the last name of the mermaid
	// /////////////MY ADDITION FUNCTION
	virtual void saveBinType(ofstream& out)const;///save the first letters.
	virtual void saveTxtType(ofstream& out)const;

//////public:
//////	void printData(ofstream& out)const;///print own data
protected:
	virtual void saveAddition(ofstream& out)const;///print base data and then own data.
	virtual void saveBinAddition(ofstream& out)const;///print data in BinFile - own data
	virtual void loadAdditon(ifstream& in);//read  mammal data and fish data and the his own data

protected:
	char* m_firstName;
	char* m_lastName;
};

#endif // ifndef