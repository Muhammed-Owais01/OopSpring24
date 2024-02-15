/**
 * Programmer: Muhammed Owais 
 * Desc: Q2, Revised Book Class
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
		this->totalPageCount = 1000; 
		this->pagesRead = 0;
	}

	// Setters
	void setName(string name) {this->name = name;}
	void setAuthor(string author) {this->author = author;}
	void setISBN(int ISBN) {this->ISBN = ISBN;}
	void setTotalPageCount(int totalPageCount) {this->totalPageCount = totalPageCount;}
	void setPagesRead(int setPagesRead) {this->pagesRead = pagesRead;}

	void updatePagesRead(int n)
	{
		this->pagesRead = n;
		if (this->pagesRead = this->totalPageCount)
			cout << "You have finished the book";
	}

	void showBookInfo()
	{
		cout << "Name: "<< this->name << "\nAuthor: " << this->author << "\nISBN: " << this->ISBN 
		<< "\nTotal Page Count: " << this->totalPageCount << "\nPages Read: " << this->pagesRead;
	}
};

int main()
{
	Book book;
	book.showBookInfo();
}