
#include "Animal.h"
// ///////////////constrctor and destrctor
Animal::Animal()
	:m_color(nullptr), m_avgLifetime(0), m_childCount(0)
{
	this->m_color = _strdup("GRAY");
	//set the default color to GRAY and other params to 0
}
Animal::Animal(const char* color, int childs, float avgLifetime)
	:m_avgLifetime(avgLifetime), m_childCount(childs), m_color(nullptr)
{
	this->m_color = _strdup(color);
	//init the Animal with a given attributes
}
Animal::~Animal()
{
	if (this->m_color != nullptr)
	{
		delete[] this->m_color;
	}
	this->m_color = nullptr;
}
///////////////////////////seters and getters
///////////Accesess function

const char* Animal::GetColor() const
{
	//return the color of the animal
	return this->m_color;
}
int	Animal::GetChildCount() const
{
	//return the child count of the animal
	return this->m_childCount;
}
float Animal::GetLifetime() const
{
	//return the life time of the animal
	return this->m_avgLifetime;
}
// //////////My Addition function
void Animal::printData(ofstream& out)const///print own data - TXT file
{
	this->saveTxtType(out);///vitaul function - save Type.
	out << this->m_color << endl;
	out << this->m_childCount << endl;
	out << this->m_avgLifetime << endl;
	this->saveAddition(out);///virtual function - print the additnal dada.
}
void Animal::readData(ifstream& in)///read own data - TXT file
{
	////Nust match th Animal::print data
	int lengh = 0;
	char Buffer[256];
	////////////in >> lengh;///read the lengh
	in >> Buffer;
	this->m_color = _strdup(Buffer);//////new char[lengh + 1];///alocation
	///in >> this->m_color;
	in >> this->m_childCount;
	in >> this->m_avgLifetime;
	this->loadAdditon(in);////read the rest of data.
}
Animal::Animal(ifstream& in_file) :m_color(nullptr), m_avgLifetime(0), m_childCount(0)
{
	//init the Animal from a binary file
	size_t len = 0;
	char buffer[256];
	in_file.read((char*)&len, sizeof(size_t));//load the len
	in_file.read(buffer, len);///load the string.
	buffer[len] = '\0';
	this->m_color = _strdup(buffer);///deep copy
	in_file.read((char*)&this->m_childCount, sizeof(int));
	in_file.read((char*)&this->m_avgLifetime, sizeof(float));

	////go to the constrctor of the Mammal or Birds or Fish

}

void Animal::printBinData(ofstream& out)const///print own data - BinFile
{
	this->saveBinType(out);///virtual function - save type.
	size_t len = strlen(this->m_color);
	out.write((char*)&len, sizeof(size_t));///save the size
	out.write(this->m_color, len);///save the string
	out.write((char*)&this->m_childCount, sizeof(int));
	out.write((char*)&this->m_avgLifetime, sizeof(float));
	this->saveBinAddition(out);//virtual function - binFile - save the rest of data.
}
