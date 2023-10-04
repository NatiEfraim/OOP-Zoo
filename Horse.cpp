
#include "Horse.h"
//////////////constrctor and destrctor
Horse::Horse() :Animal(),Mammals(), m_type(nullptr)
{
	//set the default color to GRAY and other params to 0
}
Horse::Horse(const char* color, int childs, float avgLifetime, float preg, float milk, const char* type)
	:Animal(color,childs,avgLifetime), Mammals(color, childs, avgLifetime, preg, milk), m_type(nullptr)
{
	this->m_type = _strdup(type);////deep copy
	//init the Horse with a given attributes
}
Horse::~Horse()
{
	if (this->m_type != nullptr)
	{
		delete[]this->m_type;
	}
	this->m_type = nullptr;
	///go to the destrctor of Mammal
}
////////////Accesess function
const char* Horse::GetType() const
{
	return this->m_type;
	//return the type of the horse
}
///////////My addition function
void Horse::saveAddition(ofstream& out)const
{
	Mammals::printData(out);///print Mammal data - TXT file
	out << this->m_type << endl;
}
void Horse::loadAdditon(ifstream& in)//read mammal data and then his own data
{
	Mammals::readData(in);///read data of Mammal
	int lengh = 0;
	/////////in >> lengh;///read the lengh from the file
	char Buffer[256];
	in.read(Buffer, 1);//read the endl

	in.getline(Buffer, 256);
	this->m_type = _strdup(Buffer);/////new char[lengh + 1];///alocation
	/////in >> this->m_type;///read the type from the file
	return;
}
Horse::Horse(ifstream& in_file):Animal(in_file),Mammals(in_file),m_type(nullptr)
{
	size_t len = 0;
	char Buffer[256];
	in_file.read((char*)&len, sizeof(size_t));///loat the len
	in_file.read(Buffer, len);///load the string
	Buffer[len] = '\0';
	this->m_type = _strdup(Buffer);///deep copy.
	//init the Horse from a binary file
}

void Horse::saveBinAddition(ofstream& out)const//print own data in BinFile - virtual function
{
	Mammals::printBinData(out);//print data of Mammal BinFile
	size_t len = strlen(this->m_type);
	out.write((char*)&len, sizeof(size_t));///save the size
	out.write(this->m_type, len);///save the string
}
void Horse::saveBinType(ofstream& out)const///save the first letters.
{
	///save the Leters F
	out.write("H", 1);
}
void Horse::saveTxtType(ofstream& out)const
{
	out << "H" << endl;
}

