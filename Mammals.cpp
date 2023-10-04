
#include "Mammals.h"
/////////////////constrctor and destrctor
Mammals::Mammals():Animal(),m_pregnancyTime(0),m_milkLiters(0)
{
	//set the default color to GRAY and other params to 0
}
Mammals::Mammals(const char* color, int childs, float avgLifetime, float preg, float milk)
	:Animal(color,childs,avgLifetime),m_pregnancyTime(preg),m_milkLiters(milk)
{
	//init the Mammals with a given attributes
}

Mammals::~Mammals()
{
	////go to the Animal destrctor

	////do nothing
}
//////////////////seters and geeters
float Mammals::GetPregnanceTime() const
{
	return this->m_pregnancyTime;
	//return the pregnance time of the animal
}
float Mammals::GetMilk() const
{
	return this->m_milkLiters;
	//return the milk liters of the animal
}
// //////////My Addition function
void Mammals::printData(ofstream& out)const///print own data
{
	out << this->m_pregnancyTime << endl;
	out << this->m_milkLiters << endl;
	return;

}
void Mammals::readData(ifstream& in)///read own data - TXT file
{
	in >> this->m_pregnancyTime;
	in >> this->m_milkLiters;
	return;
}
Mammals::Mammals(ifstream& in_file):Animal(in_file),m_pregnancyTime(0),m_milkLiters(0)
{
	//init the Mammals from a binary file - read own data
	in_file.read((char*)&this->m_pregnancyTime, sizeof(float));
	in_file.read((char*)&this->m_milkLiters, sizeof(float));
}

void Mammals::printBinData(ofstream& out)const///print own data - BinFile
{
	out.write((char*)&this->m_pregnancyTime, sizeof(float));
	out.write((char*)&this->m_milkLiters, sizeof(float));
	return;
}
