
#include "GoldFish.h"
///////////constrctor and destrctor
GoldFish::GoldFish() :MammalsFish(),m_avgLength(0),m_avgWeight(0)
{
	//set the default color to GRAY and other params to 0
}
GoldFish::GoldFish(const char* color, int childs, float avgLifetime, float preg, float milk, int fin, int gills, float avgW, float avgL)
	:Animal(color,childs,avgLifetime), MammalsFish(color, childs, avgLifetime, preg, milk, fin, gills), m_avgLength(avgL), m_avgWeight(avgW)
{
	//init the GoldFish with a given attributes
}
GoldFish::~GoldFish()
{
	///go to the destrctor of the MammalFish
}
///////////////Accesess function
float GoldFish::GetWeight() const
{
	return this->m_avgWeight;
	//return the avg weight of the gold fish
}
float GoldFish::GetLength() const
{
	return this->m_avgLength;
	//return the avg length of the gold fish
}
// /////////////MY ADDITION FUNCTION
void GoldFish::saveAddition(ofstream& out)const///print base data and then own data.
{
	MammalsFish::printData(out);///print data of Mammal and then data of Fish
	out << this->m_avgWeight << endl;
	out << this->m_avgLength << endl;
	return;
}
GoldFish::GoldFish(ifstream& in_file):Animal(in_file),MammalsFish(in_file),m_avgLength(0),m_avgWeight(0)
{
	////read his own data.
	in_file.read((char*)&this->m_avgWeight, sizeof(float));
	in_file.read((char*)&this->m_avgLength, sizeof(float));
}

void GoldFish::saveBinAddition(ofstream& out)const///print data in BinFile - own data
{
	MammalsFish::printBinData(out);////print print Mammal and Fish data - BinFile
	out.write((char*)&this->m_avgWeight, sizeof(float));
	out.write((char*)&this->m_avgLength, sizeof(float));
}
void GoldFish::loadAdditon(ifstream& in)//read Mammal data and Fish data then his own data
{
	MammalsFish::readData(in);//read data of Mammal and Fish - and then his own data
	in >> this->m_avgWeight;
	in >> this->m_avgLength;
	return;
}
void GoldFish::saveBinType(ofstream& out)const///save the first letters.
{
	///save the Leters F
	out.write("G", 1);
}
void GoldFish::saveTxtType(ofstream& out)const
{
	out << "G" << endl;
}

