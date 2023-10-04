
#include "Flamingo.h"
////////////constrctor and destrctor
Flamingo::Flamingo():Birds(),m_avgHeight(0)
{
	//set the default color to GRAY and other params to 0
}
Flamingo::Flamingo(const char* color, int childs, float avgLifetime, float incubation, float avgHeight)
	:Birds(color, childs, avgLifetime, incubation), m_avgHeight(avgHeight)
{
	//init the Flamingo with a given attributes
}
Flamingo::~Flamingo()
{
	///go to the destrctor of the Birds
	///do nothing
}
////////////Accesess function
float Flamingo::GetHeight() const
{
	return this->m_avgHeight;
	//return the avg height of the flamingo
}
///////////My addition function

void Flamingo::saveAddition(ofstream& out)const
{
	Birds::printData(out);//print data of Birds at first - TXT file
	out << this->m_avgHeight << endl;
}
void Flamingo::loadAdditon(ifstream& in)//read Birds data and then his own data
{
	Birds::readData(in);//read data from Birds
	in >> this->m_avgHeight;
	return;
}
Flamingo::Flamingo(ifstream& in_file):Birds(in_file),m_avgHeight(0)
{
	//init the Flamingo from a binary file
	in_file.read((char*)&this->m_avgHeight, sizeof(int));
}

void  Flamingo::saveBinAddition(ofstream& out)const//print own data in BinFile - virtual function
{
	Birds::printBinData(out);//print data of Birds in binFile
	out.write((char*)&this->m_avgHeight, sizeof(float));//save is own data
}
void Flamingo::saveBinType(ofstream& out)const///save the first letters.
{
	///save the Leters F
	out.write("F", 1);
}
void Flamingo::saveTxtType(ofstream& out)const
{
	out << "F" << endl;
}