/**
 * Programmer: Muhammed Owais 
 * Desc: Q1, Book Class
 * Date: 15/02/2024
 * Roll-No: 23K-0047
 */ 
#include <iostream>

using namespace std;

class Book
{
private:
	string name, author;
	int ISBN, totalPageCount, pagesRead;
public:
	Book()
	{
		this->name = "Harry Potter And The Chamber of Secrets"; 
		this->author = "J.K Rowling"; 
		this->ISBN = 12982;
		this->totalPageCount = 300; 
		this->pagesRead = 0;
	}
	Book(string name, string author, int ISBN, int totalPageCount, int pagesRead)
	{
		this->name = name;
		this->author = author;
		this->ISBN = ISBN;
		this->totalPageCount = totalPageCount;
		this->pagesRead = pagesRead;
	}
	void updatePagesRead(int n)
	{
		this->pagesRead = n;
		if (this->pagesRead == this->totalPageCount)
			cout << "You have finished the book\n";
		else
			cout << "You have not finished the book\n";
	}
};

int main()
{
	Book book1;
	Book book2("Mein Kampf", "Hitler", 66662, 200, 2);
	book1.updatePagesRead(2);
	book2.updatePagesRead(200);
}