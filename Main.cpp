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

	return 0;
}

//Load the puzzle file for the program to solve.
//Takes in the path to the file
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

void Print(char *puzzle)
{
	//TODO
}