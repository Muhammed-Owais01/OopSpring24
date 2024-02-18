/**
 * Programmer: Muhammed Owais 
 * Desc: Scenario 3, Chess (Knight, Pawn)
 * Date: 18/02/2024
 * Roll-No: 23K-0047
 */ 
#include <iostream>
#include <string>
#include <cstdlib>

// Creating a chess piece
class ChessPiece
{
private:
	std::string name, color;
	char symbol;
public:
	// Default Constructor
	ChessPiece() : name("pawn"), color("white"), symbol('p') {}

	// Parameterized Constructor
	ChessPiece(std::string name, std::string color, char symbol)
	{
		this->name = name;
		this->color = color;
		this->symbol = symbol;
	}

	// Getters
	std::string getName() {return this->name;}
	std::string getColor() {return this->color;}
	char getSymbol() {return this->symbol;}

	// Setters
	void setName(std::string name) {this->name = name;}
	void setColor(std::string color) {this->color = color;}
	void setSymbol(char symbol) {this->symbol = symbol;}
};

// Creating a chess board
class ChessBoard
{
private:
	// 8x8 board of type ChessPiece 
	ChessPiece board[8][8];
	// Functions to move knight and pawn
	bool moveKnightOrPawn(std::string source, std::string destination, char symbol);
	bool movePawn(std::string source, std::string destination, char symbol);
public:
	// Initializing the board array
	ChessBoard()
	{
		// init white pieces
		board[0][0] = ChessPiece("rook", "black", 'R');
		board[0][1] = ChessPiece("knight", "black", 'N');
		board[0][2] = ChessPiece("bishop", "black", 'B');
		board[0][3] = ChessPiece("queen", "black", 'Q');
		board[0][4] = ChessPiece("king", "black", 'K');
		board[0][5] = ChessPiece("bishop", "black", 'B');
		board[0][6] = ChessPiece("knight", "black", 'N');
		board[0][7] = ChessPiece("rook", "black", 'R');

		// init white pawns
		for (int i = 0; i < 8; i++) board[1][i] = ChessPiece("pawn", "white", 'P');

		// init white spaces
		for (int i = 2; i < 6; i++)
		{
			for (int j = 0; j < 8; j++) 
			{
				board[i][j] = ChessPiece("none", "none", '.');
			}
		}

		// init black pieces
		board[7][0] = ChessPiece("rook", "white", 'r');
		board[7][1] = ChessPiece("knight", "white", 'n');
		board[7][2] = ChessPiece("bishop", "white", 'b');
		board[7][3] = ChessPiece("queen", "white", 'q');
		board[7][4] = ChessPiece("king", "white", 'k');
		board[7][5] = ChessPiece("bishop", "white", 'b');
		board[7][6] = ChessPiece("knight", "white", 'n');
		board[7][7] = ChessPiece("rook", "white", 'r');

		// init black pawns
		for (int i = 0; i < 8; i++) board[6][i] = ChessPiece("pawn", "black", 'p');
	}
	
	// Functions
	void display();
	bool movePiece(std::string source, std::string destination);
};

// To move a knight or pawn correctly
bool ChessBoard::moveKnightOrPawn(std::string source, std::string destination, char symbol)
{
	// Finding the source row col
	int sourceIndexRow = 8 - ((source[1]) - '0');
	int sourceIndexCol = source[0] - 97;

	// Finding the destination row col
	int destIndexRow = 8 - ((destination[1]) - '0');
	int destIndexCol = destination[0] - 97;

	// Finding the direction
	int dirY = destIndexRow - sourceIndexRow; 
	int dirX = destIndexCol - sourceIndexCol; 

	// If Knight
	if (symbol == 'n' || symbol == 'N')
	{
		// Knight either moves upward or downwards by two
		if (dirY == 2 || dirY == -2)
		{
			// Knight moves to the left or right by 1 and  that destination is empty 
			if ((dirX == -1 || dirX == 1) && board[destIndexRow][destIndexCol].getSymbol() == '.')
			{
				// Update the board correctly
				board[destIndexRow][destIndexCol].setSymbol(symbol);
				board[sourceIndexRow][sourceIndexCol].setSymbol('.');
				return true; 
			}
		}
	}
	// If Pawn
	else if (symbol == 'p' || symbol == 'P')
	{
		// P moves downward by postive 1 or 2, p moves upwards by negative 1 or 2
		if (((dirY == 1 || dirY == 2) && symbol == 'P') || ((dirY == -1 || dirY == -2) && symbol == 'p'))
		{
			// No change in x direction and that destination location is empty
			if (dirX == 0 && board[destIndexRow][destIndexCol].getSymbol() == '.')
			{
				// Update the board correctly
				board[destIndexRow][destIndexCol].setSymbol(symbol);
				board[sourceIndexRow][sourceIndexCol].setSymbol('.');
				return true; 
			}
		}
	}
	// False if neither work
	return false;
}

// Displaying the board
void ChessBoard::display()
{
	std::cout << "   ";
	for (int i = 97; i < 105; i++) std::cout << char(i) << "  ";
	for (int i = 0; i < 8; ++i)
	{	
		std::cout << std::endl << std::endl;
		std::cout << 8 - i << "  ";
		for (int j = 0; j < 8; ++j)
		{
			std::cout << this->board[i][j].getSymbol() << "  ";
		}
		std::cout << 8 - i << " ";
	}
	std::cout << std::endl << std::endl << "   ";
	for (int i = 97; i < 105; i++) std::cout << char(i) << "  ";
	std::cout << std::endl;
}

// Moving a piece
bool ChessBoard::movePiece(std::string source, std::string destination)
{
	int sourceIndexRow = 8 - ((source[1]) - '0');
	int sourceIndexCol = source[0] - 97;

	char symbol = board[sourceIndexRow][sourceIndexCol].getSymbol();

	return moveKnightOrPawn(source, destination, symbol);
}

int main()
{
	std::string source, destination;
	ChessBoard chessBoard;

	// Display the board initialy
	chessBoard.display();
	bool temp = false;

	// When temp is true stop user input
	while (temp == false)
	{
		// Choose a piece
		std::cout << "Choose A Piece: ";
		std::cin >> source;

		// Choose destination
		std::cout << "Choose Where You Want To Move: ";
		std::cin >> destination;

		// Move the piece and return true or false
		temp = chessBoard.movePiece(source, destination);

		// If false then user must input again
		if (temp == false)
			std::cout << "Incorrect Location Entered!!\n";
	}
	// Clear the screen
	std::system("cls");
	
	// Display the new updated board
	chessBoard.display();
}