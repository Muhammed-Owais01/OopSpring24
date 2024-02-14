/**
 * Programmer: Muhammed Owais 
 * Desc: Maintaining book records
 * Date: 07/02/2024
 * Roll-No: 23K-0047
 */ 
#include <iostream>

using namespace std;
#define MAX 100

// structure bookData
struct bookData {
	string title;
	string author;
	int pubYear;
	string genre;
};

void addBook(bookData books[], int *current);
int findBook(bookData books[], int index);
void outBook(bookData books[], int index);
void updateBook(bookData books[], int index);

int main()
{
	// array book data, size max
	bookData books[MAX];
	// n is choice, current is the current index of the array which is empty
	int n = 0, current = 0;
	// loops until -1 is input
	while (n != -1)
	{
		// Choices printed
		cout << "1 - Add Books\n"
			<< "2 - Update A Book\n"
			<< "3 - Find a Book\n" 
			<< "-1 - Exit\n"
			<< "Input: ";
		cin >> n;
		// Conditions of n
		switch(n)
		{
		case 1:
			// Function adds book to array
			addBook(books, &current);
			break;
		case 2:
			// Function updates book in array
			updateBook(books, current);
			break;
		case 3:
			// outBook outputs the book being searched for, findBook finds the book and returns the index of the book
			outBook(books, findBook(books, current));
			break;
		}
	}
}

void addBook(bookData books[], int *current)
{
	// Takes input for the book
	cout << "Enter Book Title: ";
	cin.ignore(); // To empty the buffer
	getline(cin, books[*current].title);

	cout << "Enter Book Author: ";
	getline(cin, books[*current].author);

	cout << "Enter Book Genre: ";
	getline(cin, books[*current].genre);

	cout << "Enter Book Publishing Year: ";
	cin >> books[*current].pubYear;

	// Increment so that pointer now points to next empty array location
	(*current)++;
}

// Outputs the book data
void outBook(bookData books[], int index)
{
	// If -1 then outputs book not present
	if (index != -1)
	{
		cout << "Book Title: " << books[index].title
		 << "\nBook Author: " << books[index].author
		 << "\nBook Publishing Year: " << books[index].pubYear
		 << "\nBook Genre: " << books[index].genre << endl;
	}
	else
		cout << "Book Not Present\n";
}

int findBook(bookData books[], int index)
{
	// count basically keeps track of the index being searched in array
	int n, count = 0;
	// titleOrAuthor is the input of title or author by user
	string titleOrAuthor;
	cout << "1- Find Through Title\n"
		 << "2- Find Through Author\n"
		 <<"Input: ";
	cin >> n;
	(n == 1) ? cout << "Enter Book Title: " : cout << "Enter Book Author: ";
	cin.ignore();
	getline(cin, titleOrAuthor);
	// Loop through the whole array
	while (count < index)
	{
		// If book is found either by title or author depending on what user input then return that index location
		if (n == 1 && books[count].title == titleOrAuthor)
			return count;
		else if (n == 2 && books[count].author == titleOrAuthor)
			return count;
		count++;
	}
	// Return -1 if no book found
	return -1;
}

void updateBook(bookData books[], int location)
{
	// call findBook to give the location where book was found
	int index = findBook(books, location);
	// if index -1 then book wasnt there
	if (index != -1)
	{
		// call addBook to add the new details at that index location
		cout << "Enter New Details:\n"; 
		addBook(books, &index);
	}
	else
	{
		cout << "Book doesnt exist\n";
	}
}