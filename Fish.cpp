
#include "Fish.h"
//////////////////////Constrctor and destrctor
Fish::Fish():Animal(),m_finCount(0),m_gillsCount(0)
{
	//set the default color to GRAY and other params to 0
}
Fish::Fish(const char* color, int childs, float avgLifetime, int fin, int gills)
	:Animal(color,childs,avgLifetime),m_finCount(fin),m_gillsCount(gills)
{
	//init the Fish with a given attributes
}
Fish::~Fish()
{
	////go to the Animal destrctor
}
///////////Accesess function
int	Fish::GetFinCount() const
{
	return this->m_finCount;
	//return the fin count of the animal
}
int	Fish::GetGillsCount() const
{
	return this->m_gillsCount;
	//return the gills count of the animal
}
// /////////////MY ADDITION FUNCTION
void Fish::printData(ofstream& out)const///print own data
{
	out << this->m_finCount << endl;
	out << this->m_gillsCount << endl;
}
void Fish::readData(ifstream& in)///read own data - TXT file
{
	in >> this->m_finCount;
	in >> this->m_gillsCount;
	return;
}
Fish::Fish(ifstream& in_file):Animal(in_file),m_finCount(0),m_gillsCount(0)
{
	//init the Fish from a binary file
	in_file.read((char*)&this->m_finCount, sizeof(int));
	in_file.read((char*)&this->m_gillsCount, sizeof(int));
}

void Fish::printBinData(ofstream& out)const///print own data - BinFile
{
	out.write((char*)&this->m_finCount, sizeof(int));
	out.write((char*)&this->m_gillsCount, sizeof(int));
}
