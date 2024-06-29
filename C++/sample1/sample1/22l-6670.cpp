//#include<iostream>
//#include<conio.h>
//using namespace std;
//class Animal
//{
//public:
//	virtual const char* speak()
//	{
//		return "speak() called.\n";
//	}
//	virtual ~Animal()
//	{
//		cout << "~Animal() called." << endl;
//	}
//};
//class Dog :public Animal
//{
//public:
//	const char* speak()
//	{
//		return "woof!\n";
//	}
//	~Dog()
//	{
//		cout << "~Dog() called\n";
//	}
//};
//class Cat :public Animal
//{
//public:
//	const char* speak()
//	{
//		return "meow!\n";
//	}
//	~Cat()
//	{
//		cout << "~Cat() called\n";
//	}
//};
//class Sheep :public Animal
//{
//public:
//	const char* speak()
//	{
//		return "bleat!\n";
//	}
//	~Sheep()
//	{
//		cout << "~Sheep() called\n";
//	}
//};
//class Cow :public Animal
//{
//public:
//	const char* speak()
//	{
//		return "moo!\n";
//	}
//	~Cow()
//	{
//		cout << "~Cow() called\n";
//	}
//};
//class Horse :public Animal
//{
//public:
//	const char* speak()
//	{
//		return "neigh!\n";
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
//	cout<<"-------------------------------------answer#2-----------------------\n";
//	ptrAnimal = &objDog;
//
//	Dog* ptrDog = &objDog;
//	cout<<"Answer2(II)\n";
//		//ptrDog = &objAnimal;
//	cout << objAnimal.speak() << endl;
//	cout << objDog.speak() << endl;
//	cout << ptrAnimal->speak() << endl;
//	cout << ptrDog->speak() << endl;
//
//	cout<<"----------------------Answer1(II)----------------------------\n";
//	cout << ptrDog->Animal::speak() << endl;
//
//	cout<<"---------------------------answer#3----------------------------------\n";
//	Dog lassie;
//	Animal* myPet = &lassie;
//	cout << myPet->speak() << endl;
//	cout<<"-------------------------------answer#4--------------------------------\n";
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
//	for (int i = 0; i < 2; i++)//size=2 in answer#4//
//		cout << myPets[i]->speak() << endl;
//	cout<<"-----------------answer#5,6,7--------------------\n";
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