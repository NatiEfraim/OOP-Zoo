
#include "Mermaid.h"
//////////////constrctor and destrctor
Mermaid::Mermaid():MammalsFish(),m_firstName(nullptr),m_lastName(nullptr)
{
	//set the default color to GRAY and other params to 0
}
Mermaid::Mermaid(const char* color, int childs, float avgLifetime, float preg, float milk, int fin, int gills, const char* firstName, const char* lastName)
	:Animal(color,childs,avgLifetime), MammalsFish(color, childs, avgLifetime, preg, milk, fin, gills), m_firstName(nullptr), m_lastName(nullptr)
{
	this->m_firstName = _strdup(firstName);///deep copy
	this->m_lastName = _strdup(lastName);///deep copy.
	//init the Mermaid with a given attributes
}
Mermaid::~Mermaid()
{
	if (this->m_firstName!=nullptr)
	{
		delete[] this->m_firstName;
	}
	if (this->m_lastName!=nullptr)
	{
		delete[] this->m_lastName;
	}
	this->m_firstName = nullptr;
	this->m_lastName = nullptr;
	/////go to the destrctor of the MammalFish
}
const char* Mermaid::GetFirstName() const//return the first name of the mermaid
{
	return this->m_firstName;
}
const char* Mermaid::GetLastName() const//return the last name of the mermaid
{
	return this->m_lastName;
}
///////////My addition function
void Mermaid::saveAddition(ofstream& out)const///print base data and then own data.
{
	MammalsFish::printData(out);///print data of Mammal and then the data of Fish
	out << this->m_firstName << endl;
	out   << this->m_lastName << endl;
	return;
}
void Mermaid::loadAdditon(ifstream& in)//read  mammal data and fish data and the his own data
{
	MammalsFish::readData(in);//read data of Mammal and Fish - and then his own data
	int lengh = 0;
	/////////in >> lengh;//read the lengh from the file
	char buffer[256];
	///////////this->m_firstName = new char[lengh + 1];///alocte
	in.read(buffer, 1);//read endl;
	in.getline(buffer, 256);
	this->m_firstName = _strdup(buffer);
	in.getline(buffer, 256);
	this->m_lastName = _strdup(buffer);
	////////in >> lengh;//read the lengh og the last name 
	//////////this->m_lastName = new char[lengh + 1];
	//////////////////////in >> this->m_lastName;///read the last name from the file

}
Mermaid::Mermaid(ifstream& in_file):Animal(in_file),MammalsFish(in_file),m_firstName(nullptr),m_lastName(nullptr)
{
	size_t lenFirstName = 0;
	size_t lenLastName = 0;
	char buffer[256];
	in_file.read((char*)&lenFirstName, sizeof(size_t));///load the len.
	in_file.read(buffer, lenFirstName);///load the first name.
	buffer[lenFirstName] = '\0';
	this->m_firstName = _strdup(buffer);///deep copy.
	in_file.read((char*)&lenLastName, sizeof(size_t));///load the lan
	in_file.read(buffer, lenLastName);///load the string
	buffer[lenLastName] = '\0';
	this->m_lastName = _strdup(buffer);//deep copy.
	//init the Mermaid from a binary file
}

 void Mermaid::saveBinAddition(ofstream& out)const///print data in BinFile - own data
{
	 MammalsFish::printBinData(out);////print print Mammal and Fish data - BinFile
	 size_t lenFirstName = strlen(this->m_firstName);
	 out.write((char*)&lenFirstName, sizeof(size_t));///save the len
	 out.write(this->m_firstName, lenFirstName);//save the string
	 size_t lenLastName = strlen(this->m_lastName);
	 out.write((char*)&lenLastName, sizeof(size_t));///save the len.
	 out.write(this->m_lastName, lenLastName);///save the string.
}
 void Mermaid::saveBinType(ofstream& out)const///save the first letters.
 {
	 ///save the Leters F
	 out.write("M", 1);
 }
 void  Mermaid::saveTxtType(ofstream& out)const
 {
	 out << "M" << endl;
 }
