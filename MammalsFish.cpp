
#include "MammalsFish.h"
////////////constrctor and destrctor
MammalsFish::MammalsFish():Mammals(),Fish()
{
	//set the default color to GRAY and other params to 0
}
MammalsFish::MammalsFish(const char* color, int childs, float avgLifetime, float preg, float milk, int fin, int gills)
	:Mammals(color,childs,avgLifetime,preg,milk),Fish(color,childs,avgLifetime,fin,gills)
{
	//init the MammalsFish with a given attributes
}
MammalsFish::~MammalsFish()
{
	///go to the destrctor of the Mammal and Fish
}
//////// /////////////MY ADDITION FUNCTION
void MammalsFish::printData(ofstream& out)const///print own data - txt file
{
	Mammals::printData(out);///print Mammal data
	Fish::printData(out);///print Fish data
}
void MammalsFish::readData(ifstream& in)///read own data - TXT file
{
	Mammals::readData(in);///read data of Mammal;
	Fish::readData(in);///read data of the fish 
	return;
}
MammalsFish::MammalsFish(ifstream& in_file):Mammals(in_file),Fish(in_file)
{
	//init the MammalsFish from a binary file
	//Done
}
void MammalsFish::printBinData(ofstream& out)const///print own data - BinFile
{
	Mammals::printBinData(out);//print data of Mammal - BinFile
	Fish::printBinData(out);//print data of Fish - BinFile
}
