/**
 * Programmer: Muhammed Owais 
 * Desc: Q1, Book, FictionBook
 * Date: 19/03/2024
 * Roll-No: 23K-0047
 */ 
#include <iostream>

class Book
{
public:
	std::string title, author, publisher;
	Book(std::string title, std::string author, std::string publisher) : title(title), author(author), publisher(publisher) {}
	void display() {std::cout << "Title: " << title << ", Author: " << author << ", Publisher: " << publisher << std::endl;}
};

class FictionBook : public Book
{
public:
	std::string genre, protagonist;
	FictionBook(std::string genre, std::string protagonist, std::string title, std::string author, std::string publisher) 
	: genre(genre), protagonist(protagonist), Book(title, author, publisher) {}
	void display() 
	{
		std::cout << "Title: " << title << ", Author: " << author << ", Publisher: " << publisher 
		<< ", Genre: " << genre << ", Protagonist: " << protagonist << std::endl;
	}
};

int main()
{
	FictionBook book("Science Fiction", "John Smith", "The Martian", "Andy Weir", "Crown Publishers");

	book.display();
}