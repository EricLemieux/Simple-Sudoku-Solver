//Simple Sudoku Solver
//Eric Lemieux, 2014

//Basic plan:
//1) Load the puzzle from a text file
//2) Solve the puzzle 
//3) Print the results
//4) Ask the user if they want to solve another puzzle of exit.

#include <iostream>
#include <fstream>

//Predefined functions
char*	Load(char *filePath);
char*	Solve(char *puzzle);
void	Print(char *puzzle);

int main()
{
	char *arr = new char[81];
	arr = Load("puzzle.txt");

	Print(arr);

	return 0;
}

//Load the puzzle file for the program to solve.
//Inputs path to the file
//Outputs the puzzle
//Currently assumes the file is correct, may add some checking later
char* Load(char *filePath)
{
	std::ifstream file;
	file.open(filePath);

	char current;
	char *puzzle = new char[81];
	int count = 0;

	while (file.is_open())
	{
		file.get(current);

		//Check to see if the line is a comment
		if (current == '#')
		{
			//Skip this line because it is only comments for the user.
			file.ignore(256, '\n');
		}
		else
		{
			if (current != '\n')
			{
				if (count == 81)
				{
					return puzzle;
				}
				puzzle[count] = current;
				count += 1;
			}
		}
	}

	return puzzle;
}

char* Solve(char *puzzle)
{
	//TODO
	return NULL;
}

//Print the data to the console
//Inputs the puzzle
//Outputs nothing
void Print(char *puzzle)
{
	for (unsigned int rows = 0; rows < 9; rows ++)
	{
		for (unsigned int i = 0; i < 9; i++)
		{
			std::cout << puzzle[rows*9 + i];

			if (i == 2 || i == 5)
			{
				std::cout << " | ";
			}
		}

		if (rows == 2 || rows == 5)
		{
			std::cout << std::endl;
			std::cout << "----------------";
		}
		std::cout << std::endl;
	}
}