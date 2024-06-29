#include<iostream>
#include<ctime>
#include<string.h>
#include<fstream>
using namespace std;
//---------------DATE------------------------//
class Date
{
private:
	int day;
	int month;
	int year;
	static Date currentdate;
public:
	Date(int d = 0, int m = 0, int y = 0)
	{
		day = d;
		month = m;
		year = y;
	}
	static void SetCurrentDate(int d, int m, int y)
	{
		Date c(d, m, y);
		currentdate = c;
	}
	void printDate()
	{
		cout << day << "/" << month << "/" << year;
	}
	static Date GetCurrentDate()
	{
		return currentdate;
	}
	static void printPresentDate()
	{
		cout << "(";
		currentdate.printDate();
		cout << ")";
	}
	int GetDay()
	{
		return day;
	}
	int GetMonth()
	{
		return month;
	}
	int GetYear()
	{
		return year;
	} 
	void ReadDateFromFile(ifstream& file)
	{
		file >> day;
		file >> month;
		file >> year;
	}
};
Date Date::currentdate;

//----------------------------------OBJECT(polymorph)---------------------//
class Object
{
private:
	char* ID;
public:
	Object()
	{
		ID = 0;
	}
	void SetId(char* str)
	{
		ID = str;
	}
	char* GetId()
	{
		return ID;
	}
	virtual void PrintName()
	{

	}
	virtual void Print()
	{

	}
	virtual ~Object()
	{
		if (ID)
		{
			delete[] ID;
		}
	}
	
};
//--------------------------COMMENTS--------------------//
class Comments
{
private:
	char* ID;
	Object* CommentedBy;
	char* content;
	//utility function
	char* GetStringFromBuffer(char* temp)
	{
		char* str = new char[strlen(temp) + 1];
		int i = 0;
		for (i = 0;temp[i] != '\0';i++)
		{
			str[i] = temp[i];
		}
		str[i] = '\0';
		return str;
	}
public:
	Comments()
	{
		ID = content = 0;
		CommentedBy = 0;
	}
	void SetID(char* ptr)
	{
		ID = ptr;
	}
	void SetContent(char* ptr)
	{
		content = ptr;
	}
	Comments& operator=(const Comments& a)
	{
		if (this != &a)
		{
			if (ID)
			{
				delete[] ID;
				delete[] content;
			}
			ID = GetStringFromBuffer(a.ID);
			content = GetStringFromBuffer(a.content);
			CommentedBy = a.CommentedBy;
		}
		return *this;
	}
	void SetCommentedBy(Object* ptr)
	{
		CommentedBy = ptr;
	}
	void Print()
	{
		CommentedBy->PrintName();
		cout << " wrote: \"" << content << "\"\n";
	}
	~Comments()
	{
		if (ID)
		{
			delete[] ID;
			delete[] content;
		}
	}
};

//----------------------ACTIVITY---------------------//
class Activity
{
private:
	int type;
	char* value;

	//utility function
	char* GetStringFromBuffer(char* temp)
	{
		char* str = new char[strlen(temp) + 1];
		int i = 0;
		for (i = 0;temp[i] != '\0';i++)
		{
			str[i] = temp[i];
		}
		str[i] = '\0';
		return str;
	}
public:
	Activity()
	{
		type = 0;
		value = 0;
	}
	void ReadActivityFromFile(ifstream& file)
	{
		char temp[30];
		file >> type;
		file.getline(temp, 30);
		value = GetStringFromBuffer(temp);
	}
	void Print()
	{
		if (type == 1)
		{
			cout << " is feeling ";
		}
		else if (type == 2)
		{
			cout << " is thinking about ";
		}
		else if (type == 3)
		{
			cout << " is making ";
		}
		else
		{
			cout << " is celebrating ";
		}
		cout << value;
	}
	~Activity()
	{
		if (value)
		{
			delete[] value;
		}
	}
};

//------------------------------------POSTS--------------------------//
class Posts
{
private:
	int type;
	char* ID;
	char* description;
	Activity activity;
	int NumberofLikes;
	Object* SharedBy;
	Object** LikedBy;
	Date SharedDate;
	Comments** CommentList;
	//utility function
	char* GetStringFromBuffer(char* temp)
	{
		char* str = new char[strlen(temp) + 1];
		int i = 0;
		for (i = 0;temp[i] != '\0';i++)
		{
			str[i] = temp[i];
		}
		str[i] = '\0';
		return str;
	}
public:
	Posts()
	{
		ID = description = 0;
		type = NumberofLikes = 0;
		SharedBy = 0;
		LikedBy = new Object * [10];
		CommentList = new Comments * [10];
		for (int i = 0;i < 10;i++)
		{
			CommentList[i] = 0;
		}
	}
	void ReadPostFromFile(ifstream& file)
	{
		file >> type;
		char temp[100];
		file >> temp;
		ID = GetStringFromBuffer(temp);
		SharedDate.ReadDateFromFile(file);
		file.ignore();
		file.getline(temp, 100);
		description = GetStringFromBuffer(temp);
		if (type == 2)
		{
			activity.ReadActivityFromFile(file);
		}
	}
	void SetSharedBy(Object* ptr)
	{
		SharedBy = ptr;
	}
	void SetLikedBy(Object* ptr, int& i)
	{
		LikedBy[i] = ptr;
	}
	int getIndex()
	{
		int i = 0;
		while (LikedBy[i])
		{
			i++;
		}
		return i;
	}
	int isMemory()
	{
		Date temp = Date::GetCurrentDate();
		if (SharedDate.GetDay() == temp.GetDay() && SharedDate.GetMonth() == temp.GetMonth())
		{
			return (temp.GetYear() - SharedDate.GetYear());
		}
		return 0;
	}
	void UpdateCommentList(Comments* ptr)
	{
		int i = 0;
		while (CommentList[i])
		{
			i++;
		}
		CommentList[i] = ptr;
	}
	bool SouldBePrinted()
	{
		Date currentdate = Date::GetCurrentDate();
		if (SharedDate.GetDay() == currentdate.GetDay() || SharedDate.GetDay() == currentdate.GetDay() - 1)
		{
			return true;
		}
		return false;
	}
	Date GetSharedDate()
	{
		return SharedDate;
	}
	void Print()
	{
		cout << "-----";
		SharedBy->PrintName();
		if (type == 2)
		{
			activity.Print();
			cout << endl;
		}
		else
		{
			cout << " shared ";
		}
		cout << "\" " << description << " \"(";
		SharedDate.printDate();
		cout << ")\n";
		int i = 0;
		while (CommentList[i] && i < 3)
		{
			cout << "                  ";
			CommentList[i]->Print();
			i++;
		}
	}
	void PrintLikedBy()
	{
		int i = 0;
		while (LikedBy[i])
		{
			LikedBy[i]->Print();
			cout << endl;
			i++;
		}
	}
	bool CompareId(const char* str)
	{
		return(!strcmp(ID, str));
	}
	Object* GetSharedBy()
	{
		return SharedBy;
	}
	~Posts()
	{
		if (ID)
		{
			delete[] ID;
			delete[] description;
		}
		delete[] LikedBy;
		delete[] CommentList;
	}
};
class Memory
{
private:
	bool isShared;
	char* description;
	int yearsAgo;
	Date SharedDate;
	Posts* post;

	//utility function
	char* GetStringFromBuffer(const char* temp)
	{
		char* str = new char[strlen(temp) + 1];
		int i = 0;
		for (i = 0;temp[i] != '\0';i++)
		{
			str[i] = temp[i];
		}
		str[i] = '\0';
		return str;
	}
public:
	Memory()
	{
		isShared = 0;
		description = 0;
		post = 0;
		yearsAgo = 0;
	}
	void ShareMemory(const char* str)
	{
		isShared = 1;
		description = GetStringFromBuffer(str);
		SharedDate = Date::GetCurrentDate();
	}
	void SetMemory(Posts* ptr)
	{
		post = ptr;
	}
	void SetYears(int i)
	{
		yearsAgo = i;
	}
	bool GetShared()
	{
		return isShared;
	}
	Date GetSharedDate()
	{
		return SharedDate;
	}
	void PrintMemory()
	{
		if (description)
		{
			cout << "\"" << description << "\"\n";
		}
		cout << "(" << yearsAgo << " Years Ago)\n";
		post->Print();
	}
	Posts* GetMemory()
	{
		return post;
	}
	~Memory()
	{
		if (description)
		{
			delete[] description;
		}
	}
};
//-----------------------PAGES-------------------//
class Pages: public Object
{
private:
	char* title;
	int totalPosts;
	Posts** posts;
	//utility function
	char* GetStringFromBuffer(char* temp)
	{
		char* str = new char[strlen(temp) + 1];
		int i = 0;
		for (i = 0;temp[i] != '\0';i++)
		{
			str[i] = temp[i];
		}
		str[i] = '\0';
		return str;
	}
public:
	Pages()
	{
		totalPosts = 0;
		title = 0;
		posts = 0;
	}
	void ReadPageFromFile(ifstream& file)
	{
		char temp[80];
		file >> temp;
		SetId(GetStringFromBuffer(temp));
		file.getline(temp, 80);
		title = GetStringFromBuffer(temp);
	}
	bool CompareId(const char* str)
	{
		return(!strcmp(GetId(), str));
	}
	void Print()
	{
		cout << GetId() << "--" << title;
	}
	void PrintName()
	{
		cout << title;
	}
	void PrintPosts()
	{
		for (int i = 0;i < totalPosts;i++)
		{
			if (posts[i]->SouldBePrinted())
			{
				posts[i]->Print();
				cout << endl;
			}
		}
	}
	void View()
	{
		for (int i = 0;i < totalPosts;i++)
		{
			posts[i]->Print();
			cout << endl;
		}
	}
	void UpdatePostList(Posts* ptr, int& i)
	{
		posts[i] = ptr;
	}
	void SetTotalPosts(int a)
	{
		totalPosts = a;
		if (a)
		{
			posts = new Posts * [a];
		}
	}
	~Pages()
	{
		if (title)
		{
			delete[] title;
		}
		if (totalPosts)
		{
			delete[] posts;
		}
	}
};

//--------------------------USERS------------------------//
class Users:public Object
{
private:
	char* fname;
	char* lname;
	Pages** likedPages;
	Users** Friends;
	Posts** posts;
	Memory** memories;
	int totalPosts;
	int totalMemories;
	//utility function
	char* GetStringFromBuffer(char* temp)
	{
		char* str = new char[strlen(temp) + 1];
		int i = 0;
		for (i = 0;temp[i] != '\0';i++)
		{
			str[i] = temp[i];
		}
		str[i] = '\0';
		return str;
	}

	void DeAllocatePages(Pages** pg, int total)
	{
		for (int i = 0;i < total;i++)
		{
			delete[] pg[i];
		}
		delete[] pg;
	}

public:
	Users()
	{
		totalMemories=totalPosts = 0;
		fname = lname = 0;
		likedPages = new Pages* [10];
		Friends = new Users * [10];
		posts = 0;
		memories = 0;
	}
	void ReadUserFromFile(ifstream& file)
	{
		char temp[80];
		file >> temp;
		SetId(GetStringFromBuffer(temp));
		file >> temp;
		fname = GetStringFromBuffer(temp);
		file >> temp;
		lname = GetStringFromBuffer(temp);
	}
	void LikePage(Pages* ptr,int& i)
	{
		likedPages[i] = ptr;
		i++;
	}
	void MakeFriend(Users* ptr, int& i)
	{
		Friends[i] = ptr;
		i++;
	}
	void Print()
	{
		cout << GetId() << "--" << fname << " " << lname << endl;
	}
	void PrintName()
	{
		cout << fname << " " << lname;
	}
	void PrintListView()
	{
		Print();
		cout << "FriendList: \n";
		int i = 0;
		while (Friends[i])
		{
			Friends[i]->Print();
			i++;
		}
		i = 0;
		cout << "Liked pages: \n";
		while (likedPages[i])
		{
			likedPages[i]->Print();
			cout << endl;
			i++;
		}
	}
	Posts* SearchPostById(const char* str)
	{
		for (int i = 0;i < totalPosts;i++)
		{
			if (posts[i]->CompareId(str))
			{
				return posts[i];
			}
		}
		return 0;
	}
	void CreateMemories()
	{
		for (int i = 0;i < totalPosts;i++)
		{
			if (posts[i]->isMemory())
			{
				totalMemories++;
			}
		}
		if (totalMemories)
		{
			memories = new Memory * [totalMemories];
			int j = 0;
			for (int i = 0;i < totalPosts;i++)
			{
				int y = posts[i]->isMemory();
				if (y!=0)
				{
					memories[j] = new Memory[1];
					memories[j]->SetYears(y);
					memories[j]->SetMemory(posts[i]);
					j++;
				}
			}
		}

	}
	void PrintPosts()
	{
		for (int i = 0;i < totalPosts;i++)
		{
			if (posts[i]->SouldBePrinted())
			{
				posts[i]->Print();
				cout << endl;
			}
		}
	}
	void PrintPostsOfFriends()
	{
		int i = 0;
		while (Friends[i])
		{
			Friends[i]->PrintSharedMemories();
			Friends[i]->PrintPosts();
			i++;
		}
	}
	void PrintPostsOfLikedPages()
	{
		int i = 0;
		while (likedPages[i])
		{
			likedPages[i]->PrintPosts();
			i++;
		}
	}
	void ViewFriendList()
	{
		cout << "FriendList: \n";
		int i = 0;
		while (Friends[i])
		{
			Friends[i]->Print();
			i++;
		}
	}
	void ViewLikedPages()
	{
		int i = 0;
		cout << "Liked pages: \n";
		while (likedPages[i])
		{
			likedPages[i]->Print();
			cout << endl;
			i++;
		}
	}
	void UpdatePostList(Posts* ptr,int& i)
	{
		posts[i] = ptr;
	}
	void SetTotalPosts(int a)
	{
		totalPosts = a;
		if (a)
		{
			posts = new Posts* [a];
		}
	}
	bool CompareId(const char* str)
	{
		return(!strcmp(GetId(), str));
	}
	void ViewHome()
	{
		PrintName();
		cout << "-----Home Page\n\n";
		
		PrintPostsOfFriends();
		PrintPostsOfLikedPages();

	}
	void SeeMemories()
	{
		if (totalMemories)
		{
			cout << "We hope you enjoy looking back and sharing your memories on Facebook, from the most recent to those long ago.\nOn This Day\n";
			
			for (int i = 0;i < totalMemories;i++)
			{
				memories[i]->PrintMemory();
			}
		}
		else
		{
			cout << "No Memories\n";
		}
	}
	void ShareMemory(const char* str, const char* des)
	{
		Posts* ptr = SearchPostById(str);
		for (int i = 0;i < totalMemories && !memories[i]->GetShared();i++)
		{
			if (ptr == memories[i]->GetMemory())
			{
				memories[i]->ShareMemory(des);
			}
		}
	}
	void PrintSharedMemories()
	{
		if (totalMemories)
		{
			for (int i = 0;i < totalMemories;i++)
			{
				if (memories[i]->GetShared())
				{
					cout << "~~~";
					PrintName();
					cout << " shared a memory~~~~........(";
					memories[i]->GetSharedDate().printDate();
					cout << ")\n";
					memories[i]->PrintMemory();
				}
			}
		}
	}
	void ViewTimeline()
	{
		PrintName();
		cout << "-----Time Line\n\n";
		PrintSharedMemories();
		for (int i = 0;i < totalPosts;i++)
		{
			posts[i]->Print();
			cout << endl;
		}
	}
	~Users()
	{
		if (fname)
		{
			delete[] fname;
			delete[] lname;
		}
		if (posts)
		{
			delete[] posts;
		}
		if (memories)
		{
			for (int i = 0;i < totalMemories;i++)
			{
				delete[] memories[i];
			}
			delete[] memories;
		}
		delete likedPages;
		delete Friends;
	}
};


//--------------------------------FACEBOOK-----------------------------//
class MyTheFacebook
{
private:
	int totalpages;
	int totalusers;
	int totalposts;
	int totalComments;
	Pages** pg;
	Users** user;
	Posts** posts;
	Comments** comments;
	//utility function

	template<class type>
	void DeAllocate(type** ptr, int total)
	{
		for (int i = 0;i < total;i++)
		{
			delete[] ptr[i];
		}
		delete[] ptr;
	}
	char* GetStringFromBuffer(const char* temp)
	{
		char* str = new char[strlen(temp) + 1];
		int i = 0;
		for (i = 0;temp[i] != '\0';i++)
		{
			str[i] = temp[i];
		}
		str[i] = '\0';
		return str;
	}
public:
	MyTheFacebook()
	{
		totalpages = totalusers = totalposts = totalComments = 0;
		pg = 0;
		user = 0;
		posts = 0;
		comments = 0;
	}
	void Load()
	{
		LoadPagesFromFile();
		LoadUsersFromFile();
		LoadPostsFromFile();
		LoadCommentsFromFile();
	}
	void LoadPagesFromFile()
	{
		ifstream pfile;
		pfile.open("Pages.txt");
		if (pfile.is_open())
		{
			pfile >> totalpages;
			pg = new Pages * [totalpages];
			for (int i = 0;i < totalpages;i++)
			{
				pg[i] = new Pages[1];
				pg[i]->ReadPageFromFile(pfile);
			}
		}
		pfile.close();
	}
	Pages* SearchPageById(const char* Id)
	{
		for (int i = 0;i < totalpages;i++)
		{
			if (pg[i]->CompareId(Id))
			{
				return pg[i];
			}
		}
		return 0;
	}
	Users* SearchUserbyId(const char* str)
	{
		for (int i = 0;i < totalusers;i++)
		{
			if (user[i]->CompareId(str))
			{
				return user[i];
			}
		}
		return 0;
	}
	void LoadUsersFromFile()
	{
		ifstream ufile;
		ufile.open("Users.txt");
		if (ufile.is_open())
		{
			ufile >> totalusers;
			user = new Users * [totalusers];
			char*** FriendList = new char** [totalusers];
			for (int i = 0;i < totalusers;i++)
			{
				user[i] = new Users[1];
				user[i]->ReadUserFromFile(ufile);
				FriendList[i] = new char* [totalusers];
				char temp1[5];
				int j = 0;
				ufile >> temp1;
				while (temp1[0] != '-' )
				{
					FriendList[i][j] = GetStringFromBuffer(temp1);
					j++;
					ufile >> temp1;
				}
				FriendList[i][j] = 0;
				j = 0;
				char tem[5];
				ufile >> tem;
				while (tem[0] != '-'  )
				{
					user[i]->LikePage(SearchPageById(tem),j);
					ufile >> tem;
				}
				user[i]->LikePage(0, j);
			}
			
			for (int i = 0;i < totalusers;i++)
			{
				int k = 0;
				for (int j = 0;FriendList[i][j] != 0;j++)
				{
					user[i]->MakeFriend(SearchUserbyId(FriendList[i][j]), k);
				}
				user[i]->MakeFriend(0, k);
			}
			for (int i = 0;i < totalusers;i++)
			{
				for (int j = 0;FriendList[i][j] != 0;j++)
				{
					delete[] FriendList[i][j];
				}
				delete[] FriendList[i];
			}
			delete[] FriendList;
		}
		ufile.close();
	}
	void LoadPostsFromFile()
	{
		ifstream p_file;
		char temp[20];
		Object* ptr = 0;
		p_file.open("Posts.txt");
		if (p_file.is_open())
		{
			p_file >> totalposts;
			posts = new Posts * [totalposts];
			for (int i = 0;i < totalposts;i++)
			{
				posts[i] = new Posts[1];
				posts[i]->ReadPostFromFile(p_file);
				p_file >> temp;
				if (temp[0] == 'u')
				{
					ptr = SearchUserbyId(temp);

				}
				else
				{
					ptr = SearchPageById(temp);
				}
				posts[i]->SetSharedBy(ptr);
				p_file >> temp;
				int j = 0;
				while (temp[0] != '-')
				{
					if (temp[0] == 'u')
					{
						posts[i]->SetLikedBy(SearchUserbyId(temp),j);
					}
					else
					{
						posts[i]->SetLikedBy(SearchPageById(temp),j);
					}
					p_file >> temp;
					j++;
				}
				posts[i]->SetLikedBy(0, j);
			}
		}
		AssociatePostsWithUsers();
		AssociatePostsWithPages();
		p_file.close();
	}
	Posts* SearchPostByID(const char* str)
	{
		for (int i = 0;i < totalposts;i++)
		{
			if (posts[i]->CompareId(str))
			{
				return posts[i];
			}
		}
		return 0;
	}
	void LoadCommentsFromFile()
	{
		ifstream cfile;
		char temp[100];
		cfile.open("Comments.txt");
		if (cfile.is_open())
		{
			cfile >> totalComments;
			comments = new Comments * [totalComments];
			for (int i = 0;i < totalComments;i++)
			{
				comments[i] = new Comments[1];
				cfile >> temp;
				comments[i]->SetID(GetStringFromBuffer(temp));
				cfile >> temp;
				Posts* ptr = SearchPostByID(temp);
				ptr->UpdateCommentList(comments[i]);
				cfile >> temp;
				if (temp[0] == 'u')
				{
					comments[i]->SetCommentedBy(SearchUserbyId(temp));
				}
				else
				{
					comments[i]->SetCommentedBy(SearchPageById(temp));
				}
				cfile.getline(temp, 100);
				comments[i]->SetContent(GetStringFromBuffer(temp));
			}
		}
	}
	void AssociatePostsWithUsers()
	{
		int c = 0;
		for (int i = 0;i < totalusers;i++)
		{
			c = 0;
			for (int j = 0;j < totalposts;j++)
			{
				if (user[i] == posts[j]->GetSharedBy())
				{
					c++;
				}
			}
			user[i]->SetTotalPosts(c);
		}
		c = 0;
		for (int i = 0;i < totalusers;i++)
		{
			c = 0;
			for (int j = 0;j < totalposts;j++)
			{
				if (user[i] == posts[j]->GetSharedBy())
				{
					user[i]->UpdatePostList(posts[j], c);
					c++;
				}
			}
			user[i]->CreateMemories();
		}
	}
	void AssociatePostsWithPages()
	{
		int c = 0;
		for (int i = 0;i < totalpages;i++)
		{
			c = 0;
			for (int j = 0;j < totalposts;j++)
			{
				if (pg[i] == posts[j]->GetSharedBy())
				{   
					c++;
				}
			}
			pg[i]->SetTotalPosts(c);
		}
		c = 0;
		for (int i = 0;i < totalusers;i++)
		{
			c = 0;
			for (int j = 0;j < totalposts;j++)
			{
				if (pg[i] == posts[j]->GetSharedBy())
				{
					pg[i]->UpdatePostList(posts[j], c);
					c++;
				}
			}
		}
	}
	Comments* PostComment(const char* str, const char* content,Object* commentedBy)
	{
		Comments* newComment=new Comments [1];
		newComment->SetID(GetStringFromBuffer("c14"));
		newComment->SetContent(GetStringFromBuffer(content));
		newComment->SetCommentedBy(commentedBy);
		Posts* ptr = SearchPostByID(str);
		if (ptr)
		{
			ptr->UpdateCommentList(newComment);
		}
		return newComment;
	}
	void ViewPost(const char* str)
	{
		Posts* ptr = SearchPostByID(str);
		if (ptr)
		{
			ptr->Print();
		}
		else
		{
			cout << "No results Found\n";
		}
	}
	void ViewLikedList(const char* str)
	{
		Posts* ptr = SearchPostByID(str);
		if (ptr)
		{
			ptr->PrintLikedBy();
		}
		else
		{
			cout << "No Result Found\n";
		}
	}
	void LikePost(const char* str,Object* like)
	{
		Posts* ptr = SearchPostByID(str);
		if (ptr)
		{
			int i = ptr->getIndex();
			ptr->SetLikedBy(like, i);
			i++;
			ptr->SetLikedBy(0, i);
		}
		else
		{
			cout << "No Result Found\n";
		}
	}
	void ViewPage(const char* str)
	{
		Pages* ptr = SearchPageById(str);
		if (ptr)
		{
			ptr->View();
		}
		else
		{
			cout << "No Result Found\n";
		}
	}
	static void Run()
	{
		MyTheFacebook fb;
		Date::SetCurrentDate(15, 11, 2017);
		Date::printPresentDate();
		cout << endl;
		fb.Load();
		Users* CurrentUser = fb.SearchUserbyId("u7");
		CurrentUser->PrintName();
		cout << " successfully set as current user\n";
		cout << "-------------------------------------------------------------------\n";
		cout << "Command: ViewFriendList\n";
		cout << "-------------------------------------------------------------------\n";
		CurrentUser->ViewFriendList();
		cout << "-------------------------------------------------------------------\n";
		cout << "Command: ViewPagesList\n";
		cout << "-------------------------------------------------------------------\n";
		CurrentUser->ViewLikedPages();
		cout << "-------------------------------------------------------------------\n";
		cout << "Command: ViewHome\n";
		cout << "-------------------------------------------------------------------\n";
		CurrentUser->ViewHome();
		cout << "-------------------------------------------------------------------\n";
		cout << "Command: ViewTimeLine\n";
		cout << "-------------------------------------------------------------------\n";
		CurrentUser->ViewTimeline();
		cout << "Command: ViewLikedList\n";
		cout << "-------------------------------------------------------------------\n";
		cout << "Post Liked By:\n";
		fb.ViewLikedList("post5");
		cout << "Command: LikePost\n";
		fb.LikePost("post5", CurrentUser);
		cout << "Command: ViewLikedList\n";
		cout << "-------------------------------------------------------------------\n";
		cout << "Post Liked By:\n";
		fb.ViewLikedList("post5");
		cout << "-------------------------------------------------------------------\n";
		cout << "Command: PostComment\n";
		Comments* comment = fb.PostComment("post4", "Good Luck For Your Result", CurrentUser);
		cout << "Command: ViewPost\n";
		cout << "-------------------------------------------------------------------\n";
		fb.ViewPost("post4");
		cout << "-------------------------------------------------------------------\n";
		cout << "Command: PostComment\n";
		Comments* comment1 = fb.PostComment("post8", "Thanks for the wishes", CurrentUser);
		cout << "Command: ViewPost\n";
		cout << "-------------------------------------------------------------------\n";
		fb.ViewPost("post8");
		cout << "Command: SeeMemories\n";
		cout << "-------------------------------------------------------------------\n";
		CurrentUser->SeeMemories();
		cout << "Command: ShareMemory\n";
		cout << "-------------------------------------------------------------------\n";
		CurrentUser->ShareMemory("post10", "Never thought I will be specialist in this field...");
		cout << "-------------------------------------------------------------------\n";
		cout << "Command: ViewTimeLine\n";
		cout << "-------------------------------------------------------------------\n";
		CurrentUser->ViewTimeline();
		cout << "Command: ViewPage\n";
		cout << "-------------------------------------------------------------------\n";
		fb.ViewPage("p1");
		CurrentUser = fb.SearchUserbyId("u11");
		CurrentUser->PrintName();
		cout << " successfully set as current user\n";
		cout << "-------------------------------------------------------------------\n";
		cout << "Command: ViewHome\n";
		cout << "-------------------------------------------------------------------\n";
		CurrentUser->ViewHome();
		cout << "-------------------------------------------------------------------\n";
		cout << "Command: ViewTimeLine\n";
		cout << "-------------------------------------------------------------------\n";
		CurrentUser->ViewTimeline();
		delete[] comment1;
		delete[] comment;
	}
	~MyTheFacebook()
	{
		if (pg)
		{
			DeAllocate(pg, totalpages);
		}
		if (user)
		{
			DeAllocate(user, totalusers);
		}
		if (posts)
		{
			DeAllocate(posts, totalposts);
		}
		if (comments)
		{
			DeAllocate(comments, totalComments);
		}
	}
};

void main()
{
	MyTheFacebook::Run();
}
