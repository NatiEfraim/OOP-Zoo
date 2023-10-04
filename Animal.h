
#ifndef ANIMAL_H
#define ANIMAL_H

#define _CRT_SECURE_NO_WARNINGS

#include <iostream>
#include <cstring>
#include <typeinfo>
#include <fstream>

using namespace std;

class Animal
{
protected:
	Animal();//set the default color to GRAY and other params to 0
	Animal( const char* color, int childs, float avgLifetime );//init the Animal with a given attributes
	Animal( ifstream& in_file );//init the Animal from a binary file

public:
	virtual ~Animal();

public:
	const char* GetColor() const;//return the color of the animal
	int			GetChildCount() const;//return the child count of the animal
	float		GetLifetime() const;//return the life time of the animal
	// /////////////MY ADDITION FUNCTION
	// //////////////////////Function of Save to TXT file or BinFile
public:
	void printData(ofstream& out)const;///print own data - TXT file
	void readData(ifstream& in);///read own data - TXT file
	void printBinData(ofstream& out)const;///print own data - BinFile
	virtual void saveBinType(ofstream& out)const = 0;///pure virutal
	virtual void saveTxtType(ofstream& out)const = 0;///pure virutal
protected:
	virtual void saveAddition(ofstream& out)const = 0;//pure virtual
	virtual void saveBinAddition(ofstream& out)const =0;//pure virtual
	virtual void loadAdditon(ifstream& in) = 0;//pure virtual;
	// //////////////////////Function of Save to BinFile



protected:
	char*	m_color;
	int		m_childCount;
	float	m_avgLifetime;
};

#endif // ifndef