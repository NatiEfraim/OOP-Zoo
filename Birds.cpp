
#include "Birds.h"
///////////////////constrctor and destrctor
Birds::Birds():Animal(),m_incubationTime(0)
{
	//set the default color to GRAY and other params to 0
}
Birds::Birds(const char* color, int childs, float avgLifetime, float incubation)
	:Animal(color,childs,avgLifetime),m_incubationTime(incubation)
{
	//init the Birds with a given attributes
}
Birds::~Birds()
{
	////go to the Animal destrctor

	////do nothing
}
///////////Accesess function
float Birds::GetIncubationTime() const
{
	//return the incubation time of the animal
	return this->m_incubationTime;
}
///////////////MY ADDITION FUNCTION
void Birds::printData(ofstream& out)const///print own data
{
	out << this->m_incubationTime << endl;
	return;
}
void Birds::readData(ifstream& in)///read own data - TXT file
{
	in >> this->m_incubationTime;
}
Birds::Birds(ifstream& in_file):Animal(in_file),m_incubationTime(0)
{
	//init the Birds from a binary file
	in_file.read((char*)&this->m_incubationTime, sizeof(float));
}

void Birds::printBinData(ofstream& out)const///print own data - BinFile
{
	out.write((char*)&this->m_incubationTime, sizeof(float));
}
