
#include "Zoo.h"
//////////////Constrctor and destrctor
Zoo::Zoo()
	:m_address(nullptr),m_animals(nullptr),m_closeHours(nullptr),m_name(nullptr),m_numOfAnimals(0),m_openHours(nullptr),m_ticketPrice(0)
{
	//default c'tor  - all to 0 or null
}
Zoo::Zoo(const char* name, const char* address, float ticket, const char* open, const char* close)
	:m_address(nullptr),m_animals(nullptr),m_closeHours(nullptr),m_name(nullptr),m_numOfAnimals(0),m_ticketPrice(ticket),m_openHours(nullptr)
{
	this->m_name = _strdup(name);//deep copy
	this->m_address = _strdup(address);////deep copy
	this->m_closeHours = _strdup(close);///deep copy
	this->m_openHours = _strdup(open);///deep copy
	this->m_numOfAnimals = 0;
	//c'tor with data - init class
}
Zoo::~Zoo()
{
	for (int i = 0; i < this->m_numOfAnimals; i++)
	{
		if (this->m_animals[i]!=nullptr)
		{
			delete this->m_animals[i];///virtaul destrctor
			this->m_animals[i] = nullptr;
		}
	}
	delete[]this->m_animals;
	this->m_animals = nullptr;
}
///////////////Accesess function
const char* Zoo::GetName() const//return the name of the zoo
{
	return this->m_name;
}
const char* Zoo::GetAddress() const//return the address of the zoo
{
	return this->m_address;
}
float Zoo::GetTicketPrice() const//return the ticket price of the zoo
{
	return this->m_ticketPrice;
}
const char* Zoo::GetOpenHour() const//return the open hour of the zoo
{
	return this->m_openHours;
}
const char* Zoo::GetCloseHour() const//return the close hour of the zoo
{
	return this->m_closeHours;
}
int	Zoo::GetNumOfAnimals() const//return the num of animals in the zoo
{
	return this->m_numOfAnimals;
}
Animal** Zoo::GetAnimals() const//return the animals array of the zoo
{
	return this->m_animals;
}
//////////////////Other function
void Zoo::AddAnimal(Animal* an)
{
	//creates a copy of "an" (deep copy) and adds an animal to the array

	Animal** tempArr = new Animal * [this->m_numOfAnimals + 1];
	for (int i = 0; i < this->m_numOfAnimals; i++)
	{
		tempArr[i] = this->m_animals[i];//shellow copy

	}
	if (this->m_animals!=nullptr)
	{
		delete[] this->m_animals;
		this->m_animals = nullptr;
	}
	this->m_numOfAnimals += 1;///increase the size.
	/////divide for casess
	if (typeid(*an)==typeid(Horse))
	{
		///Add Horse type
		Horse* horsePtr = dynamic_cast<Horse*>(an);///converstion
		tempArr[this->m_numOfAnimals-1] = new Horse(horsePtr->GetColor(),horsePtr->GetChildCount(),horsePtr->GetLifetime(),horsePtr->GetPregnanceTime(),horsePtr->GetMilk(),horsePtr->GetType());
		
	}
	else if (typeid(*an) == typeid(Flamingo))
	{
		///Add Flamingo type
		Flamingo* flamingoPtr = dynamic_cast<Flamingo*>(an);///converstion
		tempArr[this->m_numOfAnimals - 1] = new Flamingo(flamingoPtr->GetColor(), flamingoPtr->GetChildCount(), flamingoPtr->GetLifetime(), flamingoPtr->GetIncubationTime(), flamingoPtr->GetHeight());
	}
	else if (typeid(*an) == typeid(GoldFish))
	{
		////Add GoldFish type
		GoldFish* goldFishPtr = dynamic_cast<GoldFish*>(an);///converstion
		tempArr[this->m_numOfAnimals - 1] = new GoldFish(goldFishPtr->GetColor(), goldFishPtr->GetChildCount(), goldFishPtr->GetLifetime(), goldFishPtr->GetPregnanceTime(),goldFishPtr->GetMilk(), goldFishPtr->GetFinCount(), goldFishPtr->GetGillsCount(), goldFishPtr->GetWeight(), goldFishPtr->GetLength());
	}
	else if (typeid(*an) == typeid(Mermaid))
	{
		////Add Mermaid type
		Mermaid* mermaidPtr = dynamic_cast<Mermaid*>(an);///converstion
		tempArr[this->m_numOfAnimals - 1] = new Mermaid(mermaidPtr->GetColor(), mermaidPtr->GetChildCount(), mermaidPtr->GetLifetime(), mermaidPtr->GetPregnanceTime(), mermaidPtr->GetMilk(), mermaidPtr->GetFinCount(), mermaidPtr->GetGillsCount(), mermaidPtr->GetFirstName(), mermaidPtr->GetLastName());
	}
	this->m_animals = tempArr;//reback the pointer.
	return;
}
// ////////////////////////Operatorim
Zoo& Zoo::operator+(Animal* an)
{
	this->AddAnimal(an);///deep copy.
	return *this;
	//adds an animal (only pointer, no copy needed) to the class and returns this with the change
}
Zoo Zoo::operator+(const Zoo& other) const
{
	Zoo newZoo(this->m_name,this->m_address,this->m_ticketPrice,this->m_openHours,this->m_closeHours);
	for (size_t i = 0; i < this->m_numOfAnimals; i++)
	{
		newZoo.operator+(this->m_animals[i]);///add type of Animal
	}
	for (size_t i = 0; i < other.m_numOfAnimals; i++)
	{
		newZoo.operator+(other.m_animals[i]);///add type of Animal
	}

	return newZoo;////returen by value.
	
	//returns a new Zoo with the properties of this and animals of this and other (need to deep copy the data of other)
}
////////////My addition operator +=
Zoo& Zoo::operator+=(Animal* an)
{
	this->AddAnimal(an);//deep copy
	return *this;
}
////////////////////////////Save and Load to Files - BinFile And TXT
void Zoo::Save(ofstream& ofs) const//method to save the info to a text file
{

	// ////////save to file the data of the Zoo.
	ofs << this->m_name << endl;
	ofs << this->m_address << endl;
	ofs << this->m_ticketPrice << endl;
	ofs << this->m_openHours << endl;
	ofs << this->m_closeHours << endl;
	ofs << this->m_numOfAnimals << endl;
	/////save the data memmeber of the animal
	for (int i = 0; i < this->m_numOfAnimals; i++)
	{
		/////ofs << typeid(*this->m_animals[i]).name() + 6;////print the type.
		//////if (typeid(*this->m_animals[i])==typeid(Horse))
		//////{
		//////	ofs << "H" << endl;
		//////}
		//////else if (typeid(*this->m_animals[i])==typeid(Flamingo))
		//////{
		//////	ofs << "F" << endl;
		//////}
		//////else if (typeid(*this->m_animals[i])==typeid(GoldFish))
		//////{
		//////	ofs << "G" << endl;
		//////}
		//////else if(typeid(*this->m_animals[i])==typeid(Mermaid))
		//////{
		//////	ofs << "M" << endl;
		//////}
		this->m_animals[i]->printData(ofs);///print Animal Data data - and then go virtual function
	}
	return;
}
ofstream& operator<<(ofstream& out, const Zoo& z)//operator to write the zoo to a text file
{
	 z.Save(out);///print all data mmemeber of Object.
	 return out;
}
ifstream& operator >> (ifstream& in, Zoo& z)//operator to read the zoo from a text file
{
	z.Load(in);///go and read from txt file.
	return in;
}
void Zoo::Load(ifstream& ifs)//method to load the info from a text file
{
	////The function must match to the zoo::save!!!!
	char buffer[256] ;///for help
	ifs.getline(buffer, 256);///read the name
	this->m_name = _strdup(buffer);
	ifs.getline(buffer, 256);///read the name
	this->m_address = _strdup(buffer);
	ifs >> this->m_ticketPrice;
	ifs.read(buffer, 1);//read the endl
	ifs.getline(buffer, 256);///read the openTime
	this->m_openHours = _strdup(buffer);
	ifs.getline(buffer,256);///read the close hour
	this->m_closeHours = _strdup(buffer);
	ifs >> this->m_numOfAnimals;///read the size of the arr polimorfizem
	this->m_animals = new Animal * [this->m_numOfAnimals];///alocate the arr.
	char typeOb[2];
	for (size_t i = 0; i < this->m_numOfAnimals; i++)
	{
		ifs >> typeOb;///read the type - divided for cases!!!
		typeOb[1] = '\0';
		if (typeOb[0]=='H')
		{
			///read Horse data!!
			this->m_animals[i] = new Horse();///dafult constrctor!!!
			this->m_animals[i]->readData(ifs);///read data of the Animal - and the the rest data
		}
		else if (typeOb[0]=='F')
		{
			////read flamingo type
			this->m_animals[i] = new Flamingo();///deffult constrctor
			this->m_animals[i]->readData(ifs);///read data of the Animal - and the the rest data
		}
		else if (typeOb[0] == 'G')
		{
			////read GoldFish type
			this->m_animals[i] = new GoldFish();///deffult constrctor
			this->m_animals[i]->readData(ifs);///read data of the Animal - and the the rest data

		}
		else if (typeOb[0] == 'M')
		{
			////read Mermaid type
			this->m_animals[i] = new Mermaid();///deffult constrctor
			this->m_animals[i]->readData(ifs);//////read data of the Animal - and the the rest data
		}
	}

}
Zoo::Zoo(ifstream& in_file)
	:m_address(nullptr),m_animals(nullptr),m_closeHours(nullptr),m_name(nullptr),m_openHours(nullptr),m_numOfAnimals(0),m_ticketPrice(0)
{

	///////////////////c'tor that gets a binary file and loads the data of the zoo from the file
	size_t lenName = 0;
	size_t lenAddres = 0;
	size_t lenOpen = 0;
	size_t lenClose = 0;
	char buffer[256];
	// ///read size and string from name of the zoo.
	in_file.read((char*)&lenName, sizeof(size_t));
	in_file.read(buffer,lenName);
	buffer[lenName] = '\0';
	this->m_name = _strdup(buffer);///deep copy.
	in_file.read((char*)&lenAddres, sizeof(size_t));///load the len Addres.
	in_file.read(buffer, lenAddres);///load the string addres
	buffer[lenAddres] = '\0';
	this->m_address = _strdup(buffer);/////deep copy.
	/////////buffer[0] = '\0';
	in_file.read((char*)&m_ticketPrice, sizeof(float));///load the price tikcet.
	in_file.read((char*)&lenOpen, sizeof(size_t));///load the len of openhour.
	in_file.read(buffer, lenOpen);///load the string of open hour.
	buffer[lenOpen] = '\0';
	this->m_openHours = _strdup(buffer);////deep copy.
	in_file.read((char*)&lenClose, sizeof(size_t));///load the len.
	in_file.read(buffer, lenClose);///load the string
	buffer[lenClose] = '\0';
	this->m_closeHours = _strdup(buffer);///deep copy.
	in_file.read((char*)&this->m_numOfAnimals, sizeof(int));/////load the num of arrPolimorfi.
	this->m_animals = new Animal * [this->m_numOfAnimals];
	/////need to load the rest of the data!!
	char type[2] ;
	for (size_t i = 0; i < this->m_numOfAnimals && !in_file.eof(); i++)
	{
		///read the type
		in_file.read((char*)&type, 1);///read the leeters.
		type[1] = '\0';
		//////divided for cases
		if (type[0]=='H')
		{
			////call constrctor of horse
			this->m_animals[i] = new Horse(in_file);///read the rest of the data.
		}
		else if (type[0]=='F')
		{
			////call the constrctor of the flamingo
			this->m_animals[i] = new Flamingo(in_file);////read the reast of the data
		}
		else if (type[0]=='G')
		{
			/////call the goldFish
			this->m_animals[i] = new GoldFish(in_file);////read the rest of the data
		}
		else if (type[0]=='M')
		{
			///call MerMaid constrctor
			this->m_animals[i] = new Mermaid(in_file);///read the rest of the data.
		}

	}
}

void Zoo::SaveBin(ofstream& ofs) const//method to save the info to a binary file
{

	size_t lenStr = strlen(m_name);
	ofs.write((char*)(&lenStr), sizeof(size_t));///save the len
	ofs.write(this->m_name, lenStr);//save the string
	size_t lenAddres = strlen(this->m_address);//save the len
	ofs.write((char*) (&lenAddres) , sizeof(size_t));///save the len
	ofs.write(this->m_address, lenAddres);///save the string
	ofs.write((char*)&this->m_ticketPrice, sizeof(float));//save the price
	size_t lenOpen = strlen(this->m_openHours);
	ofs.write((char*)(&lenOpen), sizeof(size_t));//save the len
	ofs.write(this->m_openHours, lenOpen);///save the string
	size_t  lenClose = strlen(this->m_closeHours);///save the len of close hour
	ofs.write((char*)(&lenClose), sizeof(size_t));///save the len.
	ofs.write(this->m_closeHours, lenClose);///save the string.
	ofs.write((char*)&this->m_numOfAnimals, sizeof(int));
	for (size_t i = 0; i < this->m_numOfAnimals; i++)
	{
		////save all data of the Animal in the zoo.
		///this->m_animals[i]->saveBinType(ofs);//save the first letters - virtual function
		this->m_animals[i]->printBinData(ofs);//go to the Base class of the animal - and save to BinFile.
	}
	return;
}

