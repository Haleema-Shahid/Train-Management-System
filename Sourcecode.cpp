#include<iostream>
#include<fstream>
using namespace std;
class Person 
{
	char* Name;
	int Age;
	char Gender;
public:
	Person()
	{
		Name = nullptr;
		Age = 0;
		Gender = 'a';
	}
	Person(char* arr, int a, char g)
	{
		setPerson(arr, a, g);
	}
	void setPerson(char* arr, int a, char g)
	{
		int length = 0;
		for (int i = 0; arr[i] != '\0'; i++)
		{
			length++;
		}
		Name = new char[length + 1];
		int index = 0;
		for (int i = 0; arr[i] != '\0'; i++)
		{
			Name[i] = arr[i];
			index = i;
		}
		Name[index + 1] = '\0';
		Age = a;
		Gender = g;
	}
	void inputPerson(int age)
	{
		int a = age;
		cout << "ENTER NAME" << endl;
		char arr[1000];
		cin >> arr;
		cout << "ENTER GENDER" << endl << "f FOR FEMALE, m FOR MALE, t FOR TRANSGENDER" << endl;
		char g;
		cin >> g;
		setPerson(arr, a, g);
	}
	char* getName()
	{
		return Name;
	}
	int getAge()
	{
		return Age;
	}
	char getgender()
	{
		return Gender;
	}
	virtual void printperson()
	{
		cout << "Name is " << Name << endl;
		cout << "Age is " << Age << endl;
		cout << "Gender is ";
		if (Gender == 'f')
			cout << "FEMALE" << endl;
		else if (Gender == 'm')
			cout << "MALE" << endl;
		else if (Gender == 't')
			cout << "TRANSGENDER" << endl;
	}
	virtual void storeperson(ofstream&fout)
	{
		fout << "Name is " << Name << endl;
		fout << "Age is " << Age << endl;
		fout << "Gender is ";
		if (Gender == 'f')
			fout << "FEMALE" << endl;
		else if (Gender == 'm')
			fout << "MALE" << endl;
		else if (Gender == 't')
			fout << "TRANSGENDER" << endl;
	}
	~Person()
	{
		Name = nullptr;
		delete[]Name;
	}
};
void printPerson(Person* obj)
{
	obj->printperson();
}
void StorePerson(Person* obj, ofstream&fout)
{
	obj->storeperson(fout);
}
class Adult :public Person 
{
	char* Occupation;
	char* Qualification;
	char* NIC;
public:
	Adult(): Person()
	{
		Occupation = nullptr;
		Qualification = nullptr;
		NIC = nullptr;
	}
	Adult(char* nameptr, char genderchar, int ageint, char* occuptr, char* nicptr, char* quaptr): Person (nameptr,ageint,genderchar)
	{
		setNIC(nicptr);
		setOCC(occuptr);
		setQUA(quaptr);
	}
	void storeperson(ofstream&fout)
	{
		fout << "Name is " << getName() << endl;
		fout << "Age is " << getAge() << endl;
		fout << "Gender is ";
		if (getgender() == 'f')
			fout << "FEMALE" << endl;
		else if (getgender() == 'm')
			fout << "MALE" << endl;
		else if (getgender() == 't')
			fout << "TRANSGENDER" << endl;
		fout << "Occupation is " << Occupation << endl;
		fout << "Qualification is " << Qualification << endl;
		fout << "CNIC is " << NIC << endl;
	}
	void printperson()
	{
		cout << "Name is " << getName() << endl;
		cout << "Age is " << getAge() << endl;
		cout << "Gender is ";
		if (getgender() == 'f')
			cout << "FEMALE" << endl;
		else if (getgender() == 'm')
			cout << "MALE" << endl;
		else if (getgender() == 't')
			cout << "TRANSGENDER" << endl;
		cout << "Occupation is " << Occupation << endl;
		cout << "Qualification is " << Qualification << endl;
		cout << "CNIC is " << NIC << endl;
	}
	void setOCC(char* occuptr)
	{
		int length = 0;
		for (int i = 0; occuptr[i] != '\0'; i++)
		{
			length++;
		}
		Occupation = new char[length + 1];
		Occupation[length] = '\0';
		for (int i = 0; occuptr[i] != '\0'; i++)
		{
			Occupation[i] = occuptr[i];
		}
	}
	void setQUA(char* quaptr)
	{
		int length = 0;
		for (int i = 0; quaptr[i] != '\0'; i++)
		{
			length++;
		}
		Qualification = new char[length + 1];
		Qualification[length] = '\0';
		for (int i = 0; quaptr[i] != '\0'; i++)
		{
			Qualification[i] = quaptr[i];
		}
	}
	void setNIC(char* nicptr)
	{
		int length = 0;
		for (int i = 0; nicptr[i] != '\0'; i++)
		{
			length++;
		}
		NIC = new char[length + 1];
		NIC[length] = '\0';
		for (int i = 0; nicptr[i] != '\0'; i++)
		{
			NIC[i] = nicptr[i];
		}
	}
	void inputAdult(int age)
	{
		inputPerson(age);
		char arr[1000];
		cout << "ENTER QUALIFICATION" << endl;
		cin >> arr;
		setQUA(arr);
		cout << "ENTER OCCUPATION" << endl;
		cin >> arr;
		setOCC(arr);
		cout << "ENTER CNIC" << endl;
		cin >> arr;
		setNIC(arr);
	}
	void printadult()
	{
		cout << "Qualification is " << Qualification << endl;
		cout << "Occupation is " << Occupation << endl;
		cout << "CNIC is " << NIC << endl;
	}
	~Adult()
	{
		delete[]NIC;
		delete[]Qualification;
		delete[]Occupation;
	}
};
class kid :public Person 
{
	char* B_form_number;
public:
	kid(): Person()
	{
		B_form_number = nullptr;
	}
	kid(char* nameptr, char genderchar, int ageint, char * bform): Person (nameptr,ageint,genderchar)
	{
		setBFORM(bform);
	}
	void setBFORM(char* bform)
	{
		int length = 0;
		for (int i = 0; bform[i] != '\0'; i++)
		{
			length++;
		}
		B_form_number = new char[length + 1];
		B_form_number[length] = '\0';
		for (int i = 0; bform[i] != '\0'; i++)
		{
			B_form_number[i] = bform[i];
		}
	}
	void storeperson(ofstream& fout)
	{
		fout << "Name is " << getName() << endl;
		fout << "Age is " << getAge() << endl;
		fout << "Gender is ";
		if (getgender() == 'f')
			fout << "FEMALE" << endl;
		else if (getgender() == 'm')
			fout << "MALE" << endl;
		else if (getgender() == 't')
			fout << "TRANSGENDER" << endl;
		fout << "B form number is " << B_form_number << endl;
	}
	void printperson()
	{
		cout << "Name is " << getName() << endl;
		cout << "Age is " << getAge() << endl;
		cout << "Gender is ";
		if (getgender() == 'f')
			cout << "FEMALE" << endl;
		else if (getgender() == 'm')
			cout << "MALE" << endl;
		else if (getgender() == 't')
			cout << "TRANSGENDER" << endl;
		cout << "B form number is " << B_form_number << endl;
	}
	void inputkid(int age)
	{
		inputPerson(age);
		char arr[1000];
		cout << "ENTER BFORM NUMBER" << endl;
		cin >> arr;
		setBFORM(arr);
	}
	void printkid()
	{
		printperson();
		cout << "B FORM NUMBER IS " << B_form_number << endl;
	}
	~kid()
	{
		delete[]B_form_number;
	}
};
class Bogie 
{
	int Bogie_ID;
	Bogie* next;
	Person** Adults;
	Person** kids;
	int adultsindex;
	int kidsindex;
	string familyName;
public:
	Bogie(int id)
	{
		Bogie_ID = id;
		next = nullptr;
		Adults = new Person*[4];
		kids = new Person*[6];
		adultsindex = 0;
		kidsindex = 0;
	}
	Bogie* getBogie()
	{
		return next;
	}
	void setID(int ID)
	{
		Bogie_ID=ID;
	}
	void setBogie(Bogie*& obj)
	{
		next = obj;
	}
	int getID()
	{
		return Bogie_ID;
	}
	void AddPassengers()
	{
		cout << "ADD PASSENGERS" << endl;
		cout << "ENTER FAMILY NAME" << endl;
		cin >> familyName;
		cout << "ENTER THE NUMMBER OF PASSENGERS" << endl;
		int num; cin >> num;
		for (int i = 0; i < num; i++)
		{
			cout << "ENTER AGE OF PASSENGER" << endl;
			int age;
			if (adultsindex < 4 || kidsindex < 6)
			{
				cin >> age;
				if (age > 17 && adultsindex < 4)
				{
					Adult* obj=new Adult;
					obj->inputAdult(age);
					Adults[adultsindex] = obj;
					adultsindex++;
				}
				else if (age < 18 && kidsindex < 6)
				{
					kid* obj1=new kid;
					obj1->inputkid(age);
					kids[kidsindex] = obj1;
					kidsindex++;
				}
			}
		}
	}
	void Print()
	{
		int indexA = 0;
		cout << "Bogie ID is " << Bogie_ID << endl;
		cout << "FAMILY: " << familyName << endl;
		if (adultsindex != 0)
		{
			cout << "Adults: " << endl;
			for (int i = 0; i < adultsindex; i++)
			{
				Adult* obj = dynamic_cast<Adult*>(Adults[i]);
				if (obj != nullptr)
					printPerson(obj);
			}
		}
		if (kidsindex != 0)
		{
			cout << "Kids: " << endl;
			for (int i = 0; i < kidsindex; i++)
			{
				kid* obj = dynamic_cast<kid*>(kids[i]);
				if (obj != nullptr)
					printPerson(obj);
			}
		}
	}
	void store(const char file[])
	{
		ofstream fout;
		fout.open(file);
		int indexA = 0;
		fout << "Bogie ID is " << Bogie_ID << endl;
		fout << "FAMILY: " << familyName << endl;
		if (adultsindex != 0)
		{
			fout << "Adults: " << endl;
			for (int i = 0; i < adultsindex; i++)
			{
				Adult* obj = dynamic_cast<Adult*>(Adults[i]);
				if (obj != nullptr)
				{
					StorePerson(obj, fout);
				}
			}
		}
		if (kidsindex != 0)
		{
			fout << "Kids: " << endl;
			for (int i = 0; i < kidsindex; i++)
			{
				kid* obj = dynamic_cast<kid*>(kids[i]);
				if (obj != nullptr)
				{
					StorePerson(obj, fout);
				}
			}
		}
	}
	~Bogie()
	{
		delete[]Adults;
		delete[]kids;
		delete next;
	}
};
class train 
{
	Bogie* engine;	
public:
	train() 
	{
		engine = nullptr;
	}
	void addBogie(int ID) 
	{
		Bogie* temp=nullptr;
		Bogie* nextBogie=nullptr;
		nextBogie = new Bogie(ID);
		nextBogie->AddPassengers();
		if (engine == nullptr)
		{
			engine = nextBogie;
			temp = nextBogie;
		}
		else
		{
			nextBogie->setID(ID);
			temp->setBogie(nextBogie);
			temp = temp->getBogie();
		}
		
	}
	bool removeBogie(int key) 
	{
		Bogie* remove = nullptr;
		Bogie* temp = engine;
		Bogie* current = engine;
		while (current != nullptr && current->getID() != key)
		{
			temp = current;
			current = current->getBogie();
		}
		if (current == nullptr)
		{
			delete remove;
		}
		else
		{
			remove = current;
			current = current->getBogie();
			temp->setBogie(current);
			if (remove == engine)
			{
				engine = engine->getBogie();
				temp = nullptr;
			}
			delete remove;
			return true;
		}
		return false;
	}
	void printTrain() 
	{
		int i = 1;
		Bogie* current = engine;;
		while (current != nullptr)
		{
			cout << i << ". ";
			cout <<"BOGIE NUMBER "<<i<<" ID is "<< current->getID() << endl;
			current = current->getBogie();
			i++;
		}
	}
	bool SearchBogie(int key)
	{
		Bogie* search = nullptr;
		Bogie* temp = engine;
		Bogie* current = engine;
		while (current != nullptr && current->getID() != key)
		{
			temp = current;
			current = current->getBogie();
		}
		if (current != nullptr)
		{
			search = current;
			current = current->getBogie();
			return true;
		}
		return false;
	}
	Bogie* search(int id)
	{
		Bogie* search = nullptr;
		Bogie* temp = engine;
		Bogie* current = engine;
		while (current != nullptr && current->getID() != id)
		{
			temp = current;
			current = current->getBogie();
		}
		if (current != nullptr)
		{
			search = current;
			current = current->getBogie();
		}
		return search;
	}
	void printSpecificBogie(int id)
	{
		Bogie* print=search(id);
		print->Print();
	}
	
	~train()
	{
		delete engine;
	}
};
int main()
{

	train TRAIN;
	int choice;
	int flag=0;
	int id;
	int flag1 = 0;
	ofstream fout; 
	fout.open("data.txt");
	cout << "***WELCOME TO RAILWAY SYSTEM***" << endl;
	while (flag==0)
	{
		cout << "What would you like to do?" << endl;
		cout << "1. Add Bogie" << endl << "2. Remove Bogie" << endl << "3. Search Bogie" << "4. Print Train" << endl;
		cout << "5. Exit System" << endl;
		cin >> choice;
		if (choice < 1 || choice>5)
		{
			cout << "invalid choice" << endl;
		}
		else if (choice == 5)
		{
			flag = 1;
		}
		else if (choice == 1)
		{
			system("cls");
			cout << "***You have selected \"ADD BOGIE\" ***" << endl;
			while (flag1 == 0)
			{
				cout << "Enter bogie ID" << endl;
				cin >> id;
				if (TRAIN.SearchBogie(id) == false)
				{
					TRAIN.addBogie(id);
					Bogie*store=TRAIN.search(id);
					store->store("data.txt");
					flag1 = 1;
				}
				else
				{
					cout << "ID already exists" << endl;
					system("cls");
				}
			}
			
		}
		else if (choice == 2)
		{
			
			while (flag1 == 0)
			{
				system("cls");
				int removeBogie;
				cout << "***You have selected \"REMOVE BOGIE\" ***" << endl;
				cout << "Which Bogie do you wish to remove?" << endl;
				TRAIN.printTrain();
				cin >> removeBogie;
				bool removal = TRAIN.removeBogie(removeBogie);
				if (removal == false)
				{
					cout << "invalid entry" << endl;
				}
				else
					flag1 = 1;
			}
		}
		else if (choice == 3)
		{
			flag1 = 0;
			int search;
			system("cls");
			cout << "***You have selected \"SEARCH BOGIE\" ***" << endl;
			cout << "Enter ID of Bogie" << endl;
			cin >> search;
			if (TRAIN.SearchBogie(search) == true)
			{
				cout << "**BOGIE FOUND**" << endl;
				flag1 = 1;
				TRAIN.printSpecificBogie(search);
			}
			else
				cout << "**BOGUE NOT FOUND**" << endl;
		}
		else if (choice == 4)
		{
			TRAIN.printTrain();
		}
	}
	cout << "COMPLETED" << endl;
}