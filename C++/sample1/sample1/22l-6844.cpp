//#include<iostream>
//#include<conio.h>
//using namespace std;
//class Animal
//{
//private:
//	char name[30];
//public:
//	Animal(const char*);
//	virtual const char* speak()
//	{
//		return "speak() called.";
//	}
//	char* GetName();
//	virtual ~Animal() 
//	{ 
//		cout << "~Animal() called." << endl;
//	}
//};
//Animal::Animal(const char* animalName = 0)
//{
//	if (animalName == 0)
//		strcpy_s(name, "Dummy");
//	else
//	{
//		strcpy_s(name, animalName);
//	}
//}
//char* Animal::GetName()
//{
//	return name;
//}
//class Dog :public Animal
//{
//private:
//	char* type;
//public:
//	const char* speak()
//	{
//		return "woof!";
//	}
//	~Dog()
//	{
//		cout << "~Dog() called\n";
//	}
//};
//class Cat :public Animal
//{
//private:
//	char* type;
//public:
//	const char* speak()
//	{
//		return "meow!";
//	}
//	~Cat()
//	{
//		cout << "~Cat() called\n";
//	}
//};
//class Sheep :public Animal
//{
//private:
//	char* type;
//public:
//	const char* speak()
//	{
//		return "bleat!";
//	}
//	~Sheep()
//	{
//		cout << "~Sheep() called\n";
//	}
//};
//class Cow :public Animal
//{
//private:
//	char* type;
//public:
//	const char* speak()
//	{
//		return "moo!";
//	}
//	~Cow()
//	{
//		cout << "~Cow() called\n";
//	}
//};
//class Horse :public Animal
//{
//private:
//	char* type;
//public:
//	const char* speak()
//	{
//		return "neigh!";
//	}
//	~Horse()
//	{
//		cout << "~Horse() called\n";
//	}
//};
//void main()
//{
//	Animal objAnimal;
//	Dog objDog;
//	Animal* ptrAnimal = &objAnimal;
//	//----------------Exercise2-------------//
//	//ptrAnimal = &objDog;
//
//	Dog* ptrDog = &objDog;
//	//----------------Exercise2(II)-------------//
//		//ptrDog = &objAnimal;
//	cout << objAnimal.speak() << endl;
//	cout << objDog.speak() << endl;
//	cout << ptrAnimal->speak() << endl;
//	cout << ptrDog->speak() << endl;
//	
//	//part2 of exercise1
//	//cout << ptrDog->Animal::speak() << endl;
//
//	//--------------------Exercise3--------------//
//	Dog lassie;
//	Animal* myPet = &lassie;
//	cout << myPet->speak() << endl;
//	//---------------------Exercise4---------------//
//	const int size = 5;
//	Animal* myPets[size];
//	Cat whiskers;
//	Dog mutley;
//
//
//	myPets[0] = &whiskers;
//	myPets[1] = &mutley;
//
//
//	for (int i = 0; i < 2; i++)
//		cout << myPets[i]->speak() << endl;
//	//------------------------Exercise5-----------------//
//	int i = 0;
//	while (i < size)
//	{
//		cout << "Press 1 for a Dog , 2 for a Cat, 3 for Sheep, 4 for Cow and 5 for Horse" << endl;
//		switch (_getch())
//		{
//		case '1':
//			myPets[i] = new Dog;
//			cout << "Dog added at position " << i << endl << endl;
//			i++;
//			break;
//		case '2':
//			myPets[i] = new Cat;
//			cout << "Cat added at position " << i << endl << endl;
//			i++;
//			break;
//		case '3':
//			myPets[i] = new Sheep;
//			cout << "Sheep added at position " << i << endl << endl;
//			i++;
//			break;
//		case '4':
//			myPets[i] = new Cow;
//			cout << "Cow added at position " << i << endl << endl;
//			i++;
//			break;
//		case '5':
//			myPets[i] = new Horse;
//			cout << "Horse added at position " << i << endl << endl;
//			i++;
//			break;
//		default:
//			cout << "Invalid input. Enter again." << endl << endl;
//			break;
//		}
//	}
//	for (int i = 0; i < size; i++)
//		cout << myPets[i]->speak() << endl;
//	for (int i = 0;i < size;i++)
//	{
//		delete myPets[i];
//	}
//}