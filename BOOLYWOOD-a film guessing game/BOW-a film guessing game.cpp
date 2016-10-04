/*!
/brief BOW-a film guessing game
This is the classic film guessing game which all you have enjoyed playing at free time. I have only ported it to computer based game.
Why have I created it?
Because I want to.
Hope you like it
*/

#include "stdafx.h"
#include "BOW-a film guessing game.h"
using namespace std;
void GameControler();

/*! \fn film_importer
This function import film names and number of films from .dat file named DATABASE.DAT
*/
void film_importer()
{
	static CHAR myArray[999999]; int  k = 0;

	ifstream file("DATA/DATABASE.dat");
	file >> noskipws;
	if (file.is_open())
	{
		for (UINT i = 0; i < 999999; i++)
		{
			file >> myArray[i];
			if ((myArray[i - 8] == '[') && (myArray[i - 7] == '/') && (myArray[i - 6] == 'F') && (myArray[i - 5] == 'I') && (myArray[i - 4] == 'L') && (myArray[i - 3] == 'M') && (myArray[i - 2] == 'S') && (myArray[i - 1] == 'I') && (myArray[i] == ']'))
			{
				myArray[i + 1] = '\0';
				break;
			}
		}
		file.close();
		for (int i = 0; i<999999; i++)
		{
			if ((myArray[i - 6] == '[') && (myArray[i - 5] == 'F') && (myArray[i - 4] == 'I') && (myArray[i - 3] == 'L') && (myArray[i - 2] == 'M') && (myArray[i - 1] == 'S') && (myArray[i] == ']'))
			{
				i++;
				for (int j = 0; j < 100; j++)
				{
					if (myArray[i] != ';')
					{
						szFilmNames[k][j] = myArray[i];
						szFilmNames[k][j+1] = '\0';
						i++;
					}
					else
					{
						k++;
						j = -1; i++;
						total_films++;
					}
					if ((myArray[i] == '[') && (myArray[i + 1] == '/') && (myArray[i + 2] == 'F') && (myArray[i + 3] == 'I') && (myArray[i + 4] == 'L') && (myArray[i + 5] == 'M') && (myArray[i + 6] == 'S') && (myArray[i + 7] == ']'))
					{
						i = i + 8;
						total_films++; k = 0; 
						break;
					}
				}
			}
			if (total_films > MAX_FILMS)
			{
				TCHAR tem[1000];
				wsprintf(tem, L"Films are more than max limit i.e. %d \nBOW will now terminate itself", MAX_FILMS);
				MessageBox(NULL, tem, L"ERROR", MB_OK | MB_ICONERROR);
				exit(0);
			}
			if ((myArray[i - 7] == '[') && (myArray[i - 6] == 'F') && (myArray[i - 5] == 'I') && (myArray[i - 4] == 'L') && (myArray[i - 3] == 'M') && (myArray[i - 2] == 'S') && (myArray[i - 1] == 'M') && (myArray[i] == ']'))
			{
				i++;
				for (int j = 0; j < 100; j++)
				{
					if (myArray[i] != ';')
					{
						szFilmMainCast[k][j] = myArray[i];
						szFilmMainCast[k][j + 1] = '\0';
						i++;
					}
					else
					{
						k++;
						j = -1; i++;
					}
					if ((myArray[i] == '[') && (myArray[i + 1] == '/') && (myArray[i + 2] == 'F') && (myArray[i + 3] == 'I') && (myArray[i + 4] == 'L') && (myArray[i + 5] == 'M') && (myArray[i + 6] == 'S') && (myArray[i + 7] == 'M') && (myArray[i + 8] == ']'))
					{
						i = i + 9; k = 0;
						break;
					}
				}
			}
			if ((myArray[i - 7] == '[') && (myArray[i - 6] == 'F') && (myArray[i - 5] == 'I') && (myArray[i - 4] == 'L') && (myArray[i - 3] == 'M') && (myArray[i - 2] == 'S') && (myArray[i-1] == 'R') && (myArray[i] == ']'))
			{
					i++;
					for (int j = 0; j < 100; j++)
					{
						if (myArray[i] != ';')
						{
							szFilmReleaseDate[k][j] = myArray[i];
							szFilmReleaseDate[k][j + 1] = '\0';
							i++;
						}
						else
						{
							k++;
							j = -1; i++;
						}
						if ((myArray[i] == '[') && (myArray[i + 1] == '/') && (myArray[i + 2] == 'F') && (myArray[i + 3] == 'I') && (myArray[i + 4] == 'L') && (myArray[i + 5] == 'M') && (myArray[i + 6] == 'S') && (myArray[i + 7] == 'R') && (myArray[i + 8] == ']'))
						{
							i = i + 9; k = 0;
							break;
						}
					}
			}
			if ((myArray[i - 7] == '[') && (myArray[i - 6] == 'F') && (myArray[i - 5] == 'I') && (myArray[i - 4] == 'L') && (myArray[i - 3] == 'M') && (myArray[i - 2] == 'S') && (myArray[i - 1] == 'D') && (myArray[i] == ']'))
			{
				i++;
				for (int j = 0; j < 100; j++)
				{
					if (myArray[i] != ';')
					{
						szFilmDirector[k][j] = myArray[i];
						szFilmDirector[k][j + 1] = '\0';
						i++;
					}
					else
					{
						k++;
						j = -1; i++;
					}
					if ((myArray[i] == '[') && (myArray[i + 1] == '/') && (myArray[i + 2] == 'F') && (myArray[i + 3] == 'I') && (myArray[i + 4] == 'L') && (myArray[i + 5] == 'M') && (myArray[i + 6] == 'S') && (myArray[i + 7] == 'D') && (myArray[i + 8] == ']'))
					{
						i = i + 9; k = 0;
						break;
					}
				}
			}
			if ((myArray[i - 7] == '[') && (myArray[i - 6] == 'F') && (myArray[i - 5] == 'I') && (myArray[i - 4] == 'L') && (myArray[i - 3] == 'M') && (myArray[i - 2] == 'S') && (myArray[i - 1] == 'G') && (myArray[i] == ']'))
			{
				i++;
				for (int j = 0; j < 100; j++)
				{
					if (myArray[i] != ';')
					{
						szFilmGenre[k][j] = myArray[i];
						szFilmGenre[k][j + 1] = '\0';
						i++;
					}
					else
					{
						k++;
						j = -1; i++;
					}
					if ((myArray[i] == '[') && (myArray[i + 1] == '/') && (myArray[i + 2] == 'F') && (myArray[i + 3] == 'I') && (myArray[i + 4] == 'L') && (myArray[i + 5] == 'M') && (myArray[i + 6] == 'S') && (myArray[i + 7] == 'G') && (myArray[i + 8] == ']'))
					{
						i = i + 9; k = 0;
						break;
					}
				}
			}
			if ((myArray[i - 7] == '[') && (myArray[i - 6] == 'F') && (myArray[i - 5] == 'I') && (myArray[i - 4] == 'L') && (myArray[i - 3] == 'M') && (myArray[i - 2] == 'S') && (myArray[i - 1] == 'W') && (myArray[i] == ']'))
			{
				i++;
				for (int j = 0; j < 100; j++)
				{
					if (myArray[i] != ';')
					{
						szFilmWikiLinks[k][j] = myArray[i];
						szFilmWikiLinks[k][j + 1] = '\0';
						i++;
					}
					else
					{
						k++;
						j = -1; i++;
					}
					if ((myArray[i] == '[') && (myArray[i + 1] == '/') && (myArray[i + 2] == 'F') && (myArray[i + 3] == 'I') && (myArray[i + 4] == 'L') && (myArray[i + 5] == 'M') && (myArray[i + 6] == 'S') && (myArray[i + 7] == 'W') && (myArray[i + 8] == ']'))
					{
						i = i + 9; k = 0;
						break;
					}
				}
			}
			if ((myArray[i - 7] == '[') && (myArray[i - 6] == 'F') && (myArray[i - 5] == 'I') && (myArray[i - 4] == 'L') && (myArray[i - 3] == 'M') && (myArray[i - 2] == 'S') && (myArray[i - 1] == 'I') && (myArray[i] == ']'))
			{
				i++;
				for (int j = 0; j < 100; j++)
				{
					if (myArray[i] != ';')
					{
						szFilmImdbLinks[k][j] = myArray[i];
						szFilmImdbLinks[k][j + 1] = '\0';
						i++;
					}
					else
					{
						k++;
						j = -1; i++;
					}
					if ((myArray[i] == '[') && (myArray[i + 1] == '/') && (myArray[i + 2] == 'F') && (myArray[i + 3] == 'I') && (myArray[i + 4] == 'L') && (myArray[i + 5] == 'M') && (myArray[i + 6] == 'S') && (myArray[i + 7] == 'I') && (myArray[i + 8] == ']'))
					{
						i = i + 9; k = 0;
						break;
					}
				}
			}
			

			if ((myArray[i - 8] == '[') && (myArray[i - 7] == '/') && (myArray[i - 6] == 'F') && (myArray[i - 5] == 'I') && (myArray[i - 4] == 'L') && (myArray[i - 3] == 'M') && (myArray[i - 2] == 'S') && (myArray[i - 1] == 'I') && (myArray[i] == ']'))
				break;
		}
	}
	else
	{
		exit(0);
	}
	return;
}
/*! \fn TotalEffectiveFilms()
This function find out the total effective films after sorting according to genre
*/
int  TotalEffectiveFilms()
{
	int temp2[MAX_FILMS];
	for (int i = 0; i < MAX_FILMS; i++)
		temp2[i] = -1;
	int kr = 0; SortedData.TotalEffectiveFilms = 0;
	for (int i = 0; i < SortedData.TotalFilmsAfterSort; i++)
	{
		for (int k = 0; k < SortedData.TotalFilmsAfterSort; k++)
		{
			if (SortedData.GenreCurrentIndex[i] == temp2[k])
				kr++;
		}
		if (kr>0)
		{
			kr = 0;
		}
		else if (kr == 0)
		{
			temp2[SortedData.TotalEffectiveFilms] = SortedData.GenreCurrentIndex[i];
			SortedData.TotalEffectiveFilms++; kr = 0;
		}
	}
	return 0;
}
/*! \fn DataSorter()
This function sort the data according to data type given to it
*/
void DataSorter(UINT DataType)
{
	if (DataType == GENRE_INDEX)
	{
		for (UINT i = 0; i < total_films; i++)
		{
			for (UINT j = 0; szFilmGenre[i][j] != 0; j++)
			{
				if (((szFilmGenre[i][j] == L'T') || (szFilmGenre[i][j] == L't')) && ((szFilmGenre[i][j + 1] == L'H') || (szFilmGenre[i][j + 1] == L'h')) && ((szFilmGenre[i][j + 2] == L'R') || (szFilmGenre[i][j + 2] == L'r')) && ((szFilmGenre[i][j + 3] == L'I') || (szFilmGenre[i][j + 3] == L'i')) && ((szFilmGenre[i][j + 4] == L'L') || (szFilmGenre[i][j + 4] == L'l')) && ((szFilmGenre[i][j + 5] == L'L') || (szFilmGenre[i][j + 5] == L'l')) && ((szFilmGenre[i][j + 6] == L'E') || (szFilmGenre[i][j + 6] == L'e')) && ((szFilmGenre[i][j + 7] == L'R') || (szFilmGenre[i][j + 7] == L'r')))
				{
					SortedData.Thriller.iGenre[SortedData.Thriller.iNdexNumber] = i;
					SortedData.Thriller.iNdexNumber++;
					j += 7;
				}
				if (((szFilmGenre[i][j] == L'R') || (szFilmGenre[i][j] == L'r')) && ((szFilmGenre[i][j + 1] == L'O') || (szFilmGenre[i][j + 1] == L'o')) && ((szFilmGenre[i][j + 2] == L'M') || (szFilmGenre[i][j + 2] == L'm')) && ((szFilmGenre[i][j + 3] == L'A') || (szFilmGenre[i][j + 3] == L'a')) && ((szFilmGenre[i][j + 4] == L'N') || (szFilmGenre[i][j + 4] == L'n')) && ((szFilmGenre[i][j + 5] == L'C') || (szFilmGenre[i][j + 5] == L'c')) && ((szFilmGenre[i][j + 6] == L'E') || (szFilmGenre[i][j + 6] == L'e')))
				{
					SortedData.Romance.iGenre[SortedData.Romance.iNdexNumber] = i;
					SortedData.Romance.iNdexNumber++;
					j += 6;
				}
				if (((szFilmGenre[i][j] == L'F') || (szFilmGenre[i][j] == L'f')) && ((szFilmGenre[i][j + 1] == L'A') || (szFilmGenre[i][j + 1] == L'a')) && ((szFilmGenre[i][j + 2] == L'N') || (szFilmGenre[i][j + 2] == L'n')) && ((szFilmGenre[i][j + 3] == L'T') || (szFilmGenre[i][j + 3] == L't')) && ((szFilmGenre[i][j + 4] == L'A') || (szFilmGenre[i][j + 4] == L'a')) && ((szFilmGenre[i][j + 5] == L'S') || (szFilmGenre[i][j + 5] == L's')) && ((szFilmGenre[i][j + 6] == L'Y') || (szFilmGenre[i][j + 6] == L'y')))
				{
					SortedData.Fantasy.iGenre[SortedData.Fantasy.iNdexNumber] = i;
					SortedData.Fantasy.iNdexNumber++;
					j += 6;
				}
				if (((szFilmGenre[i][j] == L'D') || (szFilmGenre[i][j] == L'd')) && ((szFilmGenre[i][j + 1] == L'R') || (szFilmGenre[i][j + 1] == L'r')) && ((szFilmGenre[i][j + 2] == L'A') || (szFilmGenre[i][j + 2] == L'a')) && ((szFilmGenre[i][j + 3] == L'M') || (szFilmGenre[i][j + 3] == L'm')) && ((szFilmGenre[i][j + 4] == L'A') || (szFilmGenre[i][j + 4] == L'a')))
				{
					SortedData.Drama.iGenre[SortedData.Drama.iNdexNumber] = i;
					SortedData.Drama.iNdexNumber++;
					j += 4;
				}
				if (((szFilmGenre[i][j] == L'F') || (szFilmGenre[i][j] == L'f')) && ((szFilmGenre[i][j + 1] == L'A') || (szFilmGenre[i][j + 1] == L'a')) && ((szFilmGenre[i][j + 2] == L'M') || (szFilmGenre[i][j + 2] == L'm')) && ((szFilmGenre[i][j + 3] == L'I') || (szFilmGenre[i][j + 3] == L'i')) && ((szFilmGenre[i][j + 4] == L'L') || (szFilmGenre[i][j + 4] == L'l')) && ((szFilmGenre[i][j + 5] == L'Y') || (szFilmGenre[i][j + 5] == L'y')))
				{
					SortedData.Family.iGenre[SortedData.Family.iNdexNumber] = i;
					SortedData.Family.iNdexNumber++;
					j += 5;
				}
				if (((szFilmGenre[i][j] == L'C') || (szFilmGenre[i][j] == L'c')) && ((szFilmGenre[i][j + 1] == L'O') || (szFilmGenre[i][j + 1] == L'o')) && ((szFilmGenre[i][j + 2] == L'M') || (szFilmGenre[i][j + 2] == L'm')) && ((szFilmGenre[i][j + 3] == L'E') || (szFilmGenre[i][j + 3] == L'e')) && ((szFilmGenre[i][j + 4] == L'D') || (szFilmGenre[i][j + 4] == L'd')) && ((szFilmGenre[i][j + 5] == L'Y') || (szFilmGenre[i][j + 5] == L'y')))
				{
					SortedData.Comedy.iGenre[SortedData.Comedy.iNdexNumber] = i;
					SortedData.Comedy.iNdexNumber++;
					j += 5;
				}
				if (((szFilmGenre[i][j] == L'A') || (szFilmGenre[i][j] == L'a')) && ((szFilmGenre[i][j + 1] == L'C') || (szFilmGenre[i][j + 1] == L'c')) && ((szFilmGenre[i][j + 2] == L'T') || (szFilmGenre[i][j + 2] == L't')) && ((szFilmGenre[i][j + 3] == L'I') || (szFilmGenre[i][j + 3] == L'i')) && ((szFilmGenre[i][j + 4] == L'O') || (szFilmGenre[i][j + 4] == L'o')) && ((szFilmGenre[i][j + 5] == L'N') || (szFilmGenre[i][j + 5] == L'n')))
				{
					SortedData.Action.iGenre[SortedData.Action.iNdexNumber] = i;
					SortedData.Action.iNdexNumber++;
					j += 5;
				}
				if (((szFilmGenre[i][j] == L'S') || (szFilmGenre[i][j] == L's')) && ((szFilmGenre[i][j + 1] == L'O') || (szFilmGenre[i][j + 1] == L'o')) && ((szFilmGenre[i][j + 2] == L'C') || (szFilmGenre[i][j + 2] == L'c')) && ((szFilmGenre[i][j + 3] == L'I') || (szFilmGenre[i][j + 3] == L'i')) && ((szFilmGenre[i][j + 4] == L'A') || (szFilmGenre[i][j + 4] == L'a')) && ((szFilmGenre[i][j + 5] == L'L') || (szFilmGenre[i][j + 5] == L'l')))
				{
					SortedData.Social.iGenre[SortedData.Social.iNdexNumber] = i;
					SortedData.Social.iNdexNumber++;
					j += 5;
				}
				if (((szFilmGenre[i][j] == L'S') || (szFilmGenre[i][j] == L's')) && ((szFilmGenre[i][j + 1] == L'U') || (szFilmGenre[i][j + 1] == L'u')) && ((szFilmGenre[i][j + 2] == L'S') || (szFilmGenre[i][j + 2] == L's')) && ((szFilmGenre[i][j + 3] == L'P') || (szFilmGenre[i][j + 3] == L'p')) && ((szFilmGenre[i][j + 4] == L'E') || (szFilmGenre[i][j + 4] == L'e')) && ((szFilmGenre[i][j + 5] == L'N') || (szFilmGenre[i][j + 5] == L'n')) && ((szFilmGenre[i][j + 6] == L'S') || (szFilmGenre[i][j + 6] == L's')) && ((szFilmGenre[i][j + 7] == L'E') || (szFilmGenre[i][j + 7] == L'e')))
				{
					SortedData.Suspense.iGenre[SortedData.Suspense.iNdexNumber] = i;
					SortedData.Suspense.iNdexNumber++;
					j += 7;
				}
				if (((szFilmGenre[i][j] == L'C') || (szFilmGenre[i][j] == L'c')) && ((szFilmGenre[i][j + 1] == L'H') || (szFilmGenre[i][j + 1] == L'h')) && ((szFilmGenre[i][j + 2] == L'I') || (szFilmGenre[i][j + 2] == L'i')) && ((szFilmGenre[i][j + 3] == L'L') || (szFilmGenre[i][j + 3] == L'l')) && ((szFilmGenre[i][j + 4] == L'D') || (szFilmGenre[i][j + 4] == L'd')) && ((szFilmGenre[i][j + 5] == L'R') || (szFilmGenre[i][j + 5] == L'r')) && ((szFilmGenre[i][j + 6] == L'E') || (szFilmGenre[i][j + 6] == L'e')) && ((szFilmGenre[i][j + 7] == L'N') || (szFilmGenre[i][j + 7] == L'n')))
				{
					SortedData.Children.iGenre[SortedData.Children.iNdexNumber] = i;
					SortedData.Children.iNdexNumber++;
					j += 7;
				}
				if (((szFilmGenre[i][j] == L'A') || (szFilmGenre[i][j] == L'a')) && ((szFilmGenre[i][j + 1] == L'D') || (szFilmGenre[i][j + 1] == L'd')) && ((szFilmGenre[i][j + 2] == L'V') || (szFilmGenre[i][j + 2] == L'v')) && ((szFilmGenre[i][j + 3] == L'E') || (szFilmGenre[i][j + 3] == L'e')) && ((szFilmGenre[i][j + 4] == L'N') || (szFilmGenre[i][j + 4] == L'n')) && ((szFilmGenre[i][j + 5] == L'T') || (szFilmGenre[i][j + 5] == L't')) && ((szFilmGenre[i][j + 6] == L'U') || (szFilmGenre[i][j + 6] == L'u')) && ((szFilmGenre[i][j + 7] == L'R') || (szFilmGenre[i][j + 7] == L'r')) && ((szFilmGenre[i][j + 8] == L'E') || (szFilmGenre[i][j + 8] == L'e')))
				{
					SortedData.Adventure.iGenre[SortedData.Adventure.iNdexNumber] = i;
					SortedData.Adventure.iNdexNumber++;
					j += 8;
				}
				if (((szFilmGenre[i][j] == L'C') || (szFilmGenre[i][j] == L'c')) && ((szFilmGenre[i][j + 1] == L'R') || (szFilmGenre[i][j + 1] == L'r')) && ((szFilmGenre[i][j + 2] == L'I') || (szFilmGenre[i][j + 2] == L'i')) && ((szFilmGenre[i][j + 3] == L'M') || (szFilmGenre[i][j + 3] == L'm')) && ((szFilmGenre[i][j + 4] == L'E') || (szFilmGenre[i][j + 4] == L'e')))
				{
					SortedData.Crime.iGenre[SortedData.Crime.iNdexNumber] = i;
					SortedData.Crime.iNdexNumber++;
					j += 4;
				}
				if (((szFilmGenre[i][j] == L'M') || (szFilmGenre[i][j] == L'm')) && ((szFilmGenre[i][j + 1] == L'U') || (szFilmGenre[i][j + 1] == L'u')) && ((szFilmGenre[i][j + 2] == L'S') || (szFilmGenre[i][j + 2] == L's')) && ((szFilmGenre[i][j + 3] == L'I') || (szFilmGenre[i][j + 3] == L'i')) && ((szFilmGenre[i][j + 4] == L'C') || (szFilmGenre[i][j + 4] == L'c')) && ((szFilmGenre[i][j + 5] == L'A') || (szFilmGenre[i][j + 5] == L'a')) && ((szFilmGenre[i][j + 6] == L'L') || (szFilmGenre[i][j + 6] == L'l')))
				{
					SortedData.Musical.iGenre[SortedData.Musical.iNdexNumber] = i;
					SortedData.Musical.iNdexNumber++;
					j += 6;
				}
				if (((szFilmGenre[i][j] == L'A') || (szFilmGenre[i][j] == L'a')) && ((szFilmGenre[i][j + 1] == L'N') || (szFilmGenre[i][j + 1] == L'n')) && ((szFilmGenre[i][j + 2] == L'I') || (szFilmGenre[i][j + 2] == L'i')) && ((szFilmGenre[i][j + 3] == L'M') || (szFilmGenre[i][j + 3] == L'm')) && ((szFilmGenre[i][j + 4] == L'A') || (szFilmGenre[i][j + 4] == L'a')) && ((szFilmGenre[i][j + 5] == L'T') || (szFilmGenre[i][j + 5] == L't')) && ((szFilmGenre[i][j + 6] == L'I') || (szFilmGenre[i][j + 6] == L'i')) && ((szFilmGenre[i][j + 7] == L'O') || (szFilmGenre[i][j + 7] == L'o')) && ((szFilmGenre[i][j + 8] == L'N') || (szFilmGenre[i][j + 8] == L'n')))
				{
					SortedData.Animation.iGenre[SortedData.Animation.iNdexNumber] = i;
					SortedData.Animation.iNdexNumber++;
					j += 8;
				}
				if (((szFilmGenre[i][j] == L'A') || (szFilmGenre[i][j] == L'a')) && ((szFilmGenre[i][j + 1] == L'D') || (szFilmGenre[i][j + 1] == L'd')) && ((szFilmGenre[i][j + 2] == L'U') || (szFilmGenre[i][j + 2] == L'u')) && ((szFilmGenre[i][j + 3] == L'L') || (szFilmGenre[i][j + 3] == L'l')) && ((szFilmGenre[i][j + 4] == L'T') || (szFilmGenre[i][j + 4] == L't')))
				{
					SortedData.Adult.iGenre[SortedData.Adult.iNdexNumber] = i;
					SortedData.Adult.iNdexNumber++;
					j += 4;
				}
				if (((szFilmGenre[i][j] == L'B') || (szFilmGenre[i][j] == L'b')) && ((szFilmGenre[i][j + 1] == L'I') || (szFilmGenre[i][j + 1] == L'i')) && ((szFilmGenre[i][j + 2] == L'O') || (szFilmGenre[i][j + 2] == L'o')) && ((szFilmGenre[i][j + 3] == L'G') || (szFilmGenre[i][j + 3] == L'g')) && ((szFilmGenre[i][j + 4] == L'R') || (szFilmGenre[i][j + 4] == L'r')) && ((szFilmGenre[i][j + 5] == L'A') || (szFilmGenre[i][j + 5] == L'a')) && ((szFilmGenre[i][j + 6] == L'P') || (szFilmGenre[i][j + 6] == L'p')) && ((szFilmGenre[i][j + 7] == L'H') || (szFilmGenre[i][j + 7] == L'h')) && ((szFilmGenre[i][j + 8] == L'I') || (szFilmGenre[i][j + 8] == L'i')) && ((szFilmGenre[i][j + 9] == L'C') || (szFilmGenre[i][j + 9] == L'c')) && ((szFilmGenre[i][j + 10] == L'A') || (szFilmGenre[i][j + 10] == L'a')) && ((szFilmGenre[i][j + 11] == L'L') || (szFilmGenre[i][j + 11] == L'l')))
				{
					SortedData.Biographical.iGenre[SortedData.Biographical.iNdexNumber] = i;
					SortedData.Biographical.iNdexNumber++;
					j += 11;
				}
				if (((szFilmGenre[i][j] == L'H') || (szFilmGenre[i][j] == L'h')) && ((szFilmGenre[i][j + 1] == L'I') || (szFilmGenre[i][j + 1] == L'i')) && ((szFilmGenre[i][j + 2] == L'S') || (szFilmGenre[i][j + 2] == L's')) && ((szFilmGenre[i][j + 3] == L'T') || (szFilmGenre[i][j + 3] == L't')) && ((szFilmGenre[i][j + 4] == L'O') || (szFilmGenre[i][j + 4] == L'o')) && ((szFilmGenre[i][j + 5] == L'R') || (szFilmGenre[i][j + 5] == L'r')) && ((szFilmGenre[i][j + 6] == L'I') || (szFilmGenre[i][j + 6] == L'i')) && ((szFilmGenre[i][j + 7] == L'C') || (szFilmGenre[i][j + 7] == L'c')) && ((szFilmGenre[i][j + 8] == L'A') || (szFilmGenre[i][j + 8] == L'a')) && ((szFilmGenre[i][j + 9] == L'L') || (szFilmGenre[i][j + 9] == L'l')))
				{
					SortedData.Historical.iGenre[SortedData.Historical.iNdexNumber] = i;
					SortedData.Historical.iNdexNumber++;
					j += 9;
				}
				if (((szFilmGenre[i][j] == L'M') || (szFilmGenre[i][j] == L'm')) && ((szFilmGenre[i][j + 1] == L'Y') || (szFilmGenre[i][j + 1] == L'y')) && ((szFilmGenre[i][j + 2] == L'T') || (szFilmGenre[i][j + 2] == L't')) && ((szFilmGenre[i][j + 3] == L'H') || (szFilmGenre[i][j + 3] == L'h')) && ((szFilmGenre[i][j + 4] == L'O') || (szFilmGenre[i][j + 4] == L'o')) && ((szFilmGenre[i][j + 5] == L'L') || (szFilmGenre[i][j + 5] == L'l')) && ((szFilmGenre[i][j + 6] == L'O') || (szFilmGenre[i][j + 6] == L'o')) && ((szFilmGenre[i][j + 7] == L'G') || (szFilmGenre[i][j + 7] == L'g')) && ((szFilmGenre[i][j + 8] == L'Y') || (szFilmGenre[i][j + 8] == L'y')))
				{
					SortedData.Mythology.iGenre[SortedData.Mythology.iNdexNumber] = i;
					SortedData.Mythology.iNdexNumber++;
					j += 8;
				}
				if (((szFilmGenre[i][j] == L'S') || (szFilmGenre[i][j] == L's')) && ((szFilmGenre[i][j + 1] == L'P') || (szFilmGenre[i][j + 1] == L'p')) && ((szFilmGenre[i][j + 2] == L'O') || (szFilmGenre[i][j + 2] == L'o')) && ((szFilmGenre[i][j + 3] == L'R') || (szFilmGenre[i][j + 3] == L'r')) && ((szFilmGenre[i][j + 4] == L'T') || (szFilmGenre[i][j + 4] == L't')) && ((szFilmGenre[i][j + 5] == L'S') || (szFilmGenre[i][j + 5] == L's')))
				{
					SortedData.Sports.iGenre[SortedData.Sports.iNdexNumber] = i;
					SortedData.Sports.iNdexNumber++;
					j += 5;
				}
				if (((szFilmGenre[i][j] == L'H') || (szFilmGenre[i][j] == L'h')) && ((szFilmGenre[i][j + 1] == L'O') || (szFilmGenre[i][j + 1] == L'o')) && ((szFilmGenre[i][j + 2] == L'R') || (szFilmGenre[i][j + 2] == L'r')) && ((szFilmGenre[i][j + 3] == L'R') || (szFilmGenre[i][j + 3] == L'r')) && ((szFilmGenre[i][j + 4] == L'O') || (szFilmGenre[i][j + 4] == L'o')) && ((szFilmGenre[i][j + 5] == L'R') || (szFilmGenre[i][j + 5] == L'r')))
				{
					SortedData.Horror.iGenre[SortedData.Horror.iNdexNumber] = i;
					SortedData.Horror.iNdexNumber++;
					j += 5;
				}
				if (((szFilmGenre[i][j] == L'C') || (szFilmGenre[i][j] == L'c')) && ((szFilmGenre[i][j + 1] == L'O') || (szFilmGenre[i][j + 1] == L'o')) && ((szFilmGenre[i][j + 2] == L'S') || (szFilmGenre[i][j + 2] == L's')) && ((szFilmGenre[i][j + 3] == L'T') || (szFilmGenre[i][j + 3] == L't')) && ((szFilmGenre[i][j + 4] == L'U') || (szFilmGenre[i][j + 4] == L'u')) && ((szFilmGenre[i][j + 5] == L'M') || (szFilmGenre[i][j + 5] == L'm')) && ((szFilmGenre[i][j + 6] == L'E') || (szFilmGenre[i][j + 6] == L'e')))
				{
					SortedData.Costume.iGenre[SortedData.Costume.iNdexNumber] = i;
					SortedData.Costume.iNdexNumber++;
					j += 6;
				}
				if (((szFilmGenre[i][j] == L'D') || (szFilmGenre[i][j] == L'd')) && ((szFilmGenre[i][j + 1] == L'E') || (szFilmGenre[i][j + 1] == L'e')) && ((szFilmGenre[i][j + 2] == L'V') || (szFilmGenre[i][j + 2] == L'v')) && ((szFilmGenre[i][j + 3] == L'O') || (szFilmGenre[i][j + 3] == L'o')) && ((szFilmGenre[i][j + 4] == L'T') || (szFilmGenre[i][j + 4] == L't')) && ((szFilmGenre[i][j + 5] == L'I') || (szFilmGenre[i][j + 5] == L'i')) && ((szFilmGenre[i][j + 6] == L'O') || (szFilmGenre[i][j + 6] == L'o')) && ((szFilmGenre[i][j + 7] == L'N') || (szFilmGenre[i][j + 7] == L'n')) && ((szFilmGenre[i][j + 8] == L'A') || (szFilmGenre[i][j + 8] == L'a')) && ((szFilmGenre[i][j + 9] == L'L') || (szFilmGenre[i][j + 9] == L'l')))
				{
					SortedData.Devotional.iGenre[SortedData.Devotional.iNdexNumber] = i;
					SortedData.Devotional.iNdexNumber++;
					j += 9;
				}
				if (((szFilmGenre[i][j] == L'W') || (szFilmGenre[i][j] == L'w')) && ((szFilmGenre[i][j + 1] == L'A') || (szFilmGenre[i][j + 1] == L'a')) && ((szFilmGenre[i][j + 2] == L'R') || (szFilmGenre[i][j + 2] == L'r')))
				{
					SortedData.War.iGenre[SortedData.War.iNdexNumber] = i;
					SortedData.War.iNdexNumber++;
					j += 2;
				}
				if (((szFilmGenre[i][j] == L'P') || (szFilmGenre[i][j] == L'p')) && ((szFilmGenre[i][j + 1] == L'A') || (szFilmGenre[i][j + 1] == L'a')) && ((szFilmGenre[i][j + 2] == L'T') || (szFilmGenre[i][j + 2] == L't')) && ((szFilmGenre[i][j + 3] == L'R') || (szFilmGenre[i][j + 3] == L'r')) && ((szFilmGenre[i][j + 4] == L'I') || (szFilmGenre[i][j + 4] == L'i')) && ((szFilmGenre[i][j + 5] == L'O') || (szFilmGenre[i][j + 5] == L'o')) && ((szFilmGenre[i][j + 6] == L'T') || (szFilmGenre[i][j + 6] == L't')) && ((szFilmGenre[i][j + 7] == L'I') || (szFilmGenre[i][j + 7] == L'i')) && ((szFilmGenre[i][j + 8] == L'C') || (szFilmGenre[i][j + 8] == L'c')))
				{
					SortedData.Patriotic.iGenre[SortedData.Patriotic.iNdexNumber] = i;
					SortedData.Patriotic.iNdexNumber++;
					j += 8;
				}
				if (((szFilmGenre[i][j] == L'S') || (szFilmGenre[i][j] == L's')) && ((szFilmGenre[i][j + 1] == L'C') || (szFilmGenre[i][j + 1] == L'c')) && ((szFilmGenre[i][j + 2] == L'I') || (szFilmGenre[i][j + 2] == L'i')) && ((szFilmGenre[i][j + 3] == L'E') || (szFilmGenre[i][j + 3] == L'e')) && ((szFilmGenre[i][j + 4] == L'N') || (szFilmGenre[i][j + 4] == L'n')) && ((szFilmGenre[i][j + 5] == L'C') || (szFilmGenre[i][j + 5] == L'c')) && ((szFilmGenre[i][j + 6] == L'E') || (szFilmGenre[i][j + 6] == L'e')) && ((szFilmGenre[i][j + 7] == L' ') || (szFilmGenre[i][j + 7] == L' ')) && ((szFilmGenre[i][j + 8] == L'F') || (szFilmGenre[i][j + 8] == L'f')) && ((szFilmGenre[i][j + 9] == L'I') || (szFilmGenre[i][j + 9] == L'i')) && ((szFilmGenre[i][j + 10] == L'C') || (szFilmGenre[i][j + 10] == L'c')) && ((szFilmGenre[i][j + 11] == L'T') || (szFilmGenre[i][j + 11] == L't')) && ((szFilmGenre[i][j + 12] == L'I') || (szFilmGenre[i][j + 12] == L'i')) && ((szFilmGenre[i][j + 13] == L'O') || (szFilmGenre[i][j + 13] == L'o')) && ((szFilmGenre[i][j + 14] == L'N') || (szFilmGenre[i][j + 14] == L'n')))
				{
					SortedData.Science_Fiction.iGenre[SortedData.Science_Fiction.iNdexNumber] = i;
					SortedData.Science_Fiction.iNdexNumber++;
					j += 14;
				}
				if (((szFilmGenre[i][j] == L'P') || (szFilmGenre[i][j] == L'p')) && ((szFilmGenre[i][j + 1] == L'O') || (szFilmGenre[i][j + 1] == L'o')) && ((szFilmGenre[i][j + 2] == L'L') || (szFilmGenre[i][j + 2] == L'l')) && ((szFilmGenre[i][j + 3] == L'I') || (szFilmGenre[i][j + 3] == L'i')) && ((szFilmGenre[i][j + 4] == L'T') || (szFilmGenre[i][j + 4] == L't')) && ((szFilmGenre[i][j + 5] == L'I') || (szFilmGenre[i][j + 5] == L'i')) && ((szFilmGenre[i][j + 6] == L'C') || (szFilmGenre[i][j + 6] == L'c')) && ((szFilmGenre[i][j + 7] == L'A') || (szFilmGenre[i][j + 7] == L'a')) && ((szFilmGenre[i][j + 8] == L'L') || (szFilmGenre[i][j + 8] == L'l')))
				{
					SortedData.Political.iGenre[SortedData.Political.iNdexNumber] = i;
					SortedData.Political.iNdexNumber++;
					j += 8;
				}
				if (((szFilmGenre[i][j] == L'P') || (szFilmGenre[i][j] == L'p')) && ((szFilmGenre[i][j + 1] == L'E') || (szFilmGenre[i][j + 1] == L'e')) && ((szFilmGenre[i][j + 2] == L'R') || (szFilmGenre[i][j + 2] == L'r')) && ((szFilmGenre[i][j + 3] == L'I') || (szFilmGenre[i][j + 3] == L'i')) && ((szFilmGenre[i][j + 4] == L'O') || (szFilmGenre[i][j + 4] == L'o')) && ((szFilmGenre[i][j + 5] == L'D') || (szFilmGenre[i][j + 5] == L'd')))
				{
					SortedData.Period.iGenre[SortedData.Period.iNdexNumber] = i;
					SortedData.Period.iNdexNumber++;
					j += 5;
				}
				if (((szFilmGenre[i][j] == L'B') || (szFilmGenre[i][j] == L'b')) && ((szFilmGenre[i][j + 1] == L'I') || (szFilmGenre[i][j + 1] == L'i')) && ((szFilmGenre[i][j + 2] == L'O') || (szFilmGenre[i][j + 2] == L'o')) && ((szFilmGenre[i][j + 3] == L'P') || (szFilmGenre[i][j + 3] == L'p')) && ((szFilmGenre[i][j + 4] == L'I') || (szFilmGenre[i][j + 4] == L'i')) && ((szFilmGenre[i][j + 5] == L'C') || (szFilmGenre[i][j + 5] == L'c')))
				{
					SortedData.Biopic.iGenre[SortedData.Biopic.iNdexNumber] = i;
					SortedData.Biopic.iNdexNumber++;
					j += 5;
				}
				if (((szFilmGenre[i][j] == L'F') || (szFilmGenre[i][j] == L'f')) && ((szFilmGenre[i][j + 1] == L'I') || (szFilmGenre[i][j + 1] == L'i')) && ((szFilmGenre[i][j + 2] == L'L') || (szFilmGenre[i][j + 2] == L'l')) && ((szFilmGenre[i][j + 3] == L'M') || (szFilmGenre[i][j + 3] == L'm')) && ((szFilmGenre[i][j + 4] == L' ') || (szFilmGenre[i][j + 4] == L' ')) && ((szFilmGenre[i][j + 5] == L'N') || (szFilmGenre[i][j + 5] == L'n')) && ((szFilmGenre[i][j + 6] == L'O') || (szFilmGenre[i][j + 6] == L'o')) && ((szFilmGenre[i][j + 7] == L'I') || (szFilmGenre[i][j + 7] == L'i')) && ((szFilmGenre[i][j + 8] == L'R') || (szFilmGenre[i][j + 8] == L'r')))
				{
					SortedData.Film_Noir.iGenre[SortedData.Film_Noir.iNdexNumber] = i;
					SortedData.Film_Noir.iNdexNumber++;
					j += 8;
				}
				
			}
			if (szFilmGenre[i][0] == 65440)
			{
				SortedData.Unknown.iGenre[SortedData.Unknown.iNdexNumber] = i;
				SortedData.Unknown.iNdexNumber++;
			}
		}
	}
	if (DataType == GENRE_CURRENT_INDEX)
	{
		for (int i = 0; i < MAX_FILMS;i++)
		SortedData.GenreCurrentIndex[i] = 9999;
		SortedData.TotalFilmsAfterSort = 0;
		if (SortedData.Drama.IsOsNot == TRUE)
		{
			if (SortedData.Drama.iNdexNumber != 0)
			for (UINT i = 0; i < SortedData.Drama.iNdexNumber; i++)
			{
				SortedData.GenreCurrentIndex[SortedData.TotalFilmsAfterSort] = SortedData.Drama.iGenre[i];
				SortedData.TotalFilmsAfterSort++;
			}
		}
		if (SortedData.Action.IsOsNot == TRUE)
		{
			if (SortedData.Action.iNdexNumber != 0)
			for (UINT i = 0; i < SortedData.Action.iNdexNumber; i++)
			{
				
				SortedData.GenreCurrentIndex[SortedData.TotalFilmsAfterSort] = SortedData.Action.iGenre[i];
				SortedData.TotalFilmsAfterSort++;
			}
		}
		if (SortedData.Children.IsOsNot == TRUE)
		{
			if (SortedData.Children.iNdexNumber != 0)
			for (UINT i = 0; i < SortedData.Children.iNdexNumber; i++)
			{
				
				SortedData.GenreCurrentIndex[SortedData.TotalFilmsAfterSort] = SortedData.Children.iGenre[i];
				SortedData.TotalFilmsAfterSort++;
			}
		}
		if (SortedData.Comedy.IsOsNot == TRUE)
		{
			if (SortedData.Comedy.iNdexNumber != 0)
			for (UINT i = 0; i < SortedData.Comedy.iNdexNumber; i++)
			{
				
				SortedData.GenreCurrentIndex[SortedData.TotalFilmsAfterSort] = SortedData.Comedy.iGenre[i];
				SortedData.TotalFilmsAfterSort++;
			}
		}
		if (SortedData.Family.IsOsNot == TRUE)
		{
			if (SortedData.Family.iNdexNumber != 0)
			for (UINT i = 0; i < SortedData.Family.iNdexNumber; i++)
			{
				SortedData.GenreCurrentIndex[SortedData.TotalFilmsAfterSort] = SortedData.Family.iGenre[i];
				SortedData.TotalFilmsAfterSort++;
			}
		}
		if (SortedData.Fantasy.IsOsNot == TRUE)
		{
			if (SortedData.Fantasy.iNdexNumber != 0)
			for (UINT i = 0; i < SortedData.Fantasy.iNdexNumber; i++)
			{
				SortedData.GenreCurrentIndex[SortedData.TotalFilmsAfterSort] = SortedData.Fantasy.iGenre[i];
				SortedData.TotalFilmsAfterSort++;
			}
		}
		if (SortedData.Romance.IsOsNot == TRUE)
		{
			if (SortedData.Romance.iNdexNumber != 0)
			for (UINT i = 0; i < SortedData.Romance.iNdexNumber; i++)
			{
				SortedData.GenreCurrentIndex[SortedData.TotalFilmsAfterSort] = SortedData.Romance.iGenre[i];
				SortedData.TotalFilmsAfterSort++;
			}
		}
		if (SortedData.Social.IsOsNot == TRUE)
		{
			if (SortedData.Social.iNdexNumber != 0)
			for (UINT i = 0; i < SortedData.Social.iNdexNumber; i++)
			{
				SortedData.GenreCurrentIndex[SortedData.TotalFilmsAfterSort] = SortedData.Social.iGenre[i];
				SortedData.TotalFilmsAfterSort++;
			}
		}
		if (SortedData.Suspense.IsOsNot == TRUE)
		{
			if (SortedData.Suspense.iNdexNumber != 0)
			for (UINT i = 0; i < SortedData.Suspense.iNdexNumber; i++)
			{
				SortedData.GenreCurrentIndex[SortedData.TotalFilmsAfterSort] = SortedData.Suspense.iGenre[i];
				SortedData.TotalFilmsAfterSort++;
			}
		}
		if (SortedData.Thriller.IsOsNot == TRUE)
		{
			if (SortedData.Thriller.iNdexNumber != 0)
			for (UINT i = 0; i < SortedData.Thriller.iNdexNumber; i++)
			{
				SortedData.GenreCurrentIndex[SortedData.TotalFilmsAfterSort] = SortedData.Thriller.iGenre[i];
				SortedData.TotalFilmsAfterSort++;
			}
		}
		if (SortedData.Adventure.IsOsNot == TRUE)
		{
			if (SortedData.Adventure.iNdexNumber != 0)
			for (UINT i = 0; i < SortedData.Adventure.iNdexNumber; i++)
			{
				SortedData.GenreCurrentIndex[SortedData.TotalFilmsAfterSort] = SortedData.Adventure.iGenre[i];
				SortedData.TotalFilmsAfterSort++;
			}
		}  
		if (SortedData.Crime.IsOsNot == TRUE)
		{
			if (SortedData.Crime.iNdexNumber != 0)
			for (UINT i = 0; i < SortedData.Crime.iNdexNumber; i++)
			{
				SortedData.GenreCurrentIndex[SortedData.TotalFilmsAfterSort] = SortedData.Crime.iGenre[i];
				SortedData.TotalFilmsAfterSort++;
			}
		}
		if (SortedData.Musical.IsOsNot == TRUE)
		{
			if (SortedData.Musical.iNdexNumber != 0)
			for (UINT i = 0; i < SortedData.Musical.iNdexNumber; i++)
			{
				SortedData.GenreCurrentIndex[SortedData.TotalFilmsAfterSort] = SortedData.Musical.iGenre[i];
				SortedData.TotalFilmsAfterSort++;
			}
		}
		if (SortedData.Animation.IsOsNot == TRUE)
		{
			if (SortedData.Animation.iNdexNumber != 0)
			for (UINT i = 0; i < SortedData.Animation.iNdexNumber; i++)
			{
				SortedData.GenreCurrentIndex[SortedData.TotalFilmsAfterSort] = SortedData.Animation.iGenre[i];
				SortedData.TotalFilmsAfterSort++;
			}
		}
		if (SortedData.Adult.IsOsNot == TRUE)
		{
			if (SortedData.Adult.iNdexNumber != 0)
			for (UINT i = 0; i < SortedData.Adult.iNdexNumber; i++)
			{
				SortedData.GenreCurrentIndex[SortedData.TotalFilmsAfterSort] = SortedData.Adult.iGenre[i];
				SortedData.TotalFilmsAfterSort++;
			}
		}
		if (SortedData.Biographical.IsOsNot == TRUE)
		{
			if (SortedData.Biographical.iNdexNumber != 0)
			for (UINT i = 0; i < SortedData.Biographical.iNdexNumber; i++)
			{
				SortedData.GenreCurrentIndex[SortedData.TotalFilmsAfterSort] = SortedData.Biographical.iGenre[i];
				SortedData.TotalFilmsAfterSort++;
			}
		}
		if (SortedData.Historical.IsOsNot == TRUE)
		{
			if (SortedData.Historical.iNdexNumber != 0)
			for (UINT i = 0; i < SortedData.Historical.iNdexNumber; i++)
			{
				SortedData.GenreCurrentIndex[SortedData.TotalFilmsAfterSort] = SortedData.Historical.iGenre[i];
				SortedData.TotalFilmsAfterSort++;
			}
		}
		if (SortedData.Mythology.IsOsNot == TRUE)
		{
			if (SortedData.Mythology.iNdexNumber != 0)
			for (UINT i = 0; i < SortedData.Mythology.iNdexNumber; i++)
			{
				SortedData.GenreCurrentIndex[SortedData.TotalFilmsAfterSort] = SortedData.Mythology.iGenre[i];
				SortedData.TotalFilmsAfterSort++;
			}
		}
		if (SortedData.Horror.IsOsNot == TRUE)
		{
			if (SortedData.Horror.iNdexNumber != 0)
			for (UINT i = 0; i < SortedData.Horror.iNdexNumber; i++)
			{
				SortedData.GenreCurrentIndex[SortedData.TotalFilmsAfterSort] = SortedData.Horror.iGenre[i];
				SortedData.TotalFilmsAfterSort++;
			}
		}
		if (SortedData.Sports.IsOsNot == TRUE)
		{
			if (SortedData.Sports.iNdexNumber != 0)
			for (UINT i = 0; i < SortedData.Sports.iNdexNumber; i++)
			{
				SortedData.GenreCurrentIndex[SortedData.TotalFilmsAfterSort] = SortedData.Sports.iGenre[i];
				SortedData.TotalFilmsAfterSort++;
			}
		}
		if (SortedData.Costume.IsOsNot == TRUE)
		{
			if (SortedData.Costume.iNdexNumber != 0)
			for (UINT i = 0; i < SortedData.Costume.iNdexNumber; i++)
			{
				SortedData.GenreCurrentIndex[SortedData.TotalFilmsAfterSort] = SortedData.Costume.iGenre[i];
				SortedData.TotalFilmsAfterSort++;
			}
		}
		if (SortedData.Devotional.IsOsNot == TRUE)
		{
			if (SortedData.Devotional.iNdexNumber != 0)
			for (UINT i = 0; i < SortedData.Devotional.iNdexNumber; i++)
			{
				SortedData.GenreCurrentIndex[SortedData.TotalFilmsAfterSort] = SortedData.Devotional.iGenre[i];
				SortedData.TotalFilmsAfterSort++;
			}
		}
		if (SortedData.War.IsOsNot == TRUE)
		{
			if (SortedData.War.iNdexNumber != 0)
			for (UINT i = 0; i < SortedData.War.iNdexNumber; i++)
			{
				SortedData.GenreCurrentIndex[SortedData.TotalFilmsAfterSort] = SortedData.War.iGenre[i];
				SortedData.TotalFilmsAfterSort++;
			}
		}
		if (SortedData.Patriotic.IsOsNot == TRUE)
		{
			if (SortedData.Patriotic.iNdexNumber != 0)
			for (UINT i = 0; i < SortedData.Patriotic.iNdexNumber; i++)
			{
				SortedData.GenreCurrentIndex[SortedData.TotalFilmsAfterSort] = SortedData.Patriotic.iGenre[i];
				SortedData.TotalFilmsAfterSort++;
			}
		}
		if (SortedData.Science_Fiction.IsOsNot == TRUE)
		{
			if (SortedData.Science_Fiction.iNdexNumber != 0)
			for (UINT i = 0; i < SortedData.Science_Fiction.iNdexNumber; i++)
			{
				SortedData.GenreCurrentIndex[SortedData.TotalFilmsAfterSort] = SortedData.Science_Fiction.iGenre[i];
				SortedData.TotalFilmsAfterSort++;
			}
		}
		if (SortedData.Political.IsOsNot == TRUE)
		{
			if (SortedData.Political.iNdexNumber != 0)
			for (UINT i = 0; i < SortedData.Political.iNdexNumber; i++)
			{
				SortedData.GenreCurrentIndex[SortedData.TotalFilmsAfterSort] = SortedData.Political.iGenre[i];
				SortedData.TotalFilmsAfterSort++;
			}
		}
		if (SortedData.Period.IsOsNot == TRUE)
		{
			if (SortedData.Period.iNdexNumber != 0)
			for (UINT i = 0; i < SortedData.Period.iNdexNumber; i++)
			{
				SortedData.GenreCurrentIndex[SortedData.TotalFilmsAfterSort] = SortedData.Period.iGenre[i];
				SortedData.TotalFilmsAfterSort++;
			}
		}
		if (SortedData.Biopic.IsOsNot == TRUE)
		{
			if (SortedData.Biopic.iNdexNumber != 0)
			for (UINT i = 0; i < SortedData.Biopic.iNdexNumber; i++)
			{
				SortedData.GenreCurrentIndex[SortedData.TotalFilmsAfterSort] = SortedData.Biopic.iGenre[i];
				SortedData.TotalFilmsAfterSort++;
			}
		}
		if (SortedData.Film_Noir.IsOsNot == TRUE)
		{
			if (SortedData.Film_Noir.iNdexNumber != 0)
			for (UINT i = 0; i < SortedData.Film_Noir.iNdexNumber; i++)
			{
				SortedData.GenreCurrentIndex[SortedData.TotalFilmsAfterSort] = SortedData.Film_Noir.iGenre[i];
				SortedData.TotalFilmsAfterSort++;
			}
		}
		if (SortedData.Unknown.IsOsNot == TRUE)
		{
			if (SortedData.Unknown.iNdexNumber != 0)
			for (UINT i = 0; i < SortedData.Unknown.iNdexNumber; i++)
			{
				SortedData.GenreCurrentIndex[SortedData.TotalFilmsAfterSort] = SortedData.Unknown.iGenre[i];
				SortedData.TotalFilmsAfterSort++;
			}
		}
	}
}
/* \fn FilmChooser()
	This function chooses a unique number from the total films so that by index unique film can be displayed
*/
int FilmChooser()
{
	int p, i, counti = 0; UINT dj=0;
	srand((unsigned)time(NULL));
rando:	counti = 0;
	i = rand() % total_films;
	for (p = 0; p<MAX_FILMS; p++)
	{
		if (checker[p] == i)
			counti++;

	}
	if (counti > 0)
	{
		counti = 0;
		goto rando;
	}
	else
	{
		if (SortedData.SortData == TRUE)
		{
			for (UINT j = 0; j < SortedData.TotalFilmsAfterSort; j++)
			{
				if (SortedData.GenreCurrentIndex[j] == (i))
				{
					dj++;
				}
			}
			if (dj>0)
			{
				dj = 0;
				checker[initiali] = i;
				initiali++;
				counti = 0;
				return i;
			}
			else
			{
				dj = 0;
				counti = 0;
				goto rando;
			}
		}
		else
		{
			checker[initiali] = i;
			initiali++;
			counti = 0;
			return i;
		}
	}
	return 0;
}
/*! \fn CharChecker(TCHAR film[50], TCHAR RecievedChar)
-This function checks the input of user. It checks following things
+ Checks for repeated input
+ Checks for alphabet is available or not
+ Checks if it is a vowel or a consonant
\return status of RecievedChar like char is a vowel or is it repeated, etc
*/
int CharChecker(TCHAR film[50], TCHAR RecievedChar)
{
	int flag = 0, flag1 = 0,k=0;
	if ((RecievedChar == 'A') || (RecievedChar == 'E') || (RecievedChar == 'I') || (RecievedChar == 'O') || (RecievedChar == 'U'))
			return CHAR_VOWELORSPACE;
	for (int i = 0; KeyStrokesSaver[i] != '\0'; i++)
	{
		if (KeyStrokesSaver[i] == RecievedChar)
			flag1++;
		k = i + 1;
	}
	if (flag1 > 0)
		return CHAR_REPEATED;
	else
	{
		KeyStrokesSaver[k] = RecievedChar;
		KeyStrokesSaver[k + 1] = '\0';
	}
	for (int i = 0; film[i] != '\0'; i++)
	{
		if (film[i] == RecievedChar)
			flag++;
	}
	if (flag > 0)
		return CHAR_FOUND;
	else 
		return CHAR_NOTFOUND;
}
/*! \fn FilmNameWithBlanks(TCHAR film[100])
\param film[100] contains film to be converted 
This function is used to convert a film name's consonants into blanks for the player to guess it
*/
void FilmNameWithBlanks(TCHAR film[100])
{
	int k = 0;
	for (int i = 0; film[i] != '\0'; i++)
	{
		if ((film[i] == 'A') || (film[i] == 'E') || (film[i] == 'I') || (film[i] == 'O') || (film[i] == 'U') || (film[i] == ' ') || (film[i]<'0') || ((film[i]>'9') && (film[i]<'A')) || ((film[i]>'Z') && (film[i]<'a')) || (film[i]>'z'))
		{
			szFilmWithBlanks[k] = film[i];
			k++;
			szFilmWithBlanks[k+1] = '\0';
		}
		else
		{
			szFilmWithBlanks[k] = '-';
			k++;
			szFilmWithBlanks[k+1] = '\0';
		}
	}
	return;
}
/*! \fn BanksFiller(TCHAR FilmsWithBlanks[50],TCHAR film[50],TCHAR RecievedChar)
This function fills the blank with given alphabet if it is found in film
This function do not check for repeated or vowel input
\return 1 if blank filled else 0
*/
int BlanksFiller(TCHAR FilmsWithBlanks[50],TCHAR film[50],TCHAR RecievedChar)
{
	for (int i = 0; FilmsWithBlanks[i] != '\0'; i++)
	{
		if (film[i] == RecievedChar)
			FilmsWithBlanks[i] = RecievedChar;
	}
	if (lstrcmp(FilmsWithBlanks, film) == 0)
		return 1;
	return 0;
}
/*! \fn DataResetter(BOOL GameIsOfTwoPlayers, BOOL GameIsOfOnePlayer, BOOL RessetThingsOfOneTime)
This function reset the arrays and variables to use them again
*/
void DataResetter(BOOL GameIsOfTwoPlayers, BOOL GameIsOfOnePlayer, BOOL RessetThingsOfOneTime)
{
	if ((RessetThingsOfOneTime == TRUE)&&(GameIsOfOnePlayer==TRUE))
	{
		for (int i = 49; i > -1; i--)
			KeyStrokesSaver[i] = '\0';
	}
	return;
}
/*! \fn GameControler()
It control the core of game like calling different functions to reset data or getting to result screen
*/
void GameControler()
{
		
		DataResetter(FALSE, TRUE, TRUE);
		if (GameStatus.CurrentMessage == GAME_HALTFORUSERINPUT)
		{
			szBollywood[0] = L'B'; szBollywood[1] = L'O'; szBollywood[2] = L'L'; szBollywood[3] = L'L'; szBollywood[4] = L'Y'; szBollywood[5] = L'W'; szBollywood[6] = L'O'; szBollywood[7] = L'O'; szBollywood[8] = L'D'; szBollywood[9] = L'\0';
			GameStatus.Lives = 0;
		}
		if (GameStatus.CurrentChances == MaxPlay)
		{
			GameStatus.PreviousMessage = GameStatus.CurrentMessage;
			GameStatus.CurrentMessage = GAME_PAUSE; iScreen = SCREEN_RESULTS;
			return;
		}
		iFilmNumberChoosen = FilmChooser();
		FilmNameWithBlanks(szFilmNames[iFilmNumberChoosen]);		
		GameStatus.PreviousMessage = GameStatus.CurrentMessage;
		GameStatus.CurrentMessage = GAME_PLAYING;
	
	
}
/*! \fn APIENTRY _tWinMain(_In_ HINSTANCE hInstance,_In_opt_ HINSTANCE hPrevInstance,_In_ LPTSTR    lpCmdLine, _In_ int       nCmdShow)
Its main entry point of win32 program. It initialize window title, icon and also have message loop for running the program
*/
int APIENTRY _tWinMain(_In_ HINSTANCE hInstance,
                     _In_opt_ HINSTANCE hPrevInstance,
                     _In_ LPTSTR    lpCmdLine,
                     _In_ int       nCmdShow)
{
	UNREFERENCED_PARAMETER(hPrevInstance);
	UNREFERENCED_PARAMETER(lpCmdLine);

 	// TODO: Place code here.
	MSG msg;
	HACCEL hAccelTable;

	// Initialize global strings
	LoadString(hInstance, IDS_APP_TITLE, szTitle, MAX_LOADSTRING);
	LoadString(hInstance, IDC_BOOLYWOODAFILMGUESSINGGAME, szWindowClass, MAX_LOADSTRING);
	MyRegisterClass(hInstance);

	// Perform application initialization:
	if (!InitInstance (hInstance, nCmdShow))
	{
		return FALSE;
	}

	hAccelTable = LoadAccelerators(hInstance, MAKEINTRESOURCE(IDC_BOOLYWOODAFILMGUESSINGGAME));

	// Main message loop:
	while (GetMessage(&msg, NULL, 0, 0))
	{
		if (!TranslateAccelerator(msg.hwnd, hAccelTable, &msg))
		{
			TranslateMessage(&msg);
			DispatchMessage(&msg);
		}
	}
	GdiplusShutdown(m_gdiplusToken);
	return (int) msg.wParam;
}


/*! \fn MyRegisterClass(HINSTANCE hInstance)
Registers the window class.
*/

ATOM MyRegisterClass(HINSTANCE hInstance)
{
	WNDCLASSEX wcex;

	wcex.cbSize = sizeof(WNDCLASSEX);
	wcex.style = CS_HREDRAW | CS_VREDRAW;
	wcex.lpfnWndProc	= WndProc;
	wcex.cbClsExtra		= 0;
	wcex.cbWndExtra		= 0;
	wcex.hInstance		= hInstance;
	wcex.hIcon			= LoadIcon(hInstance, MAKEINTRESOURCE(IDI_MAINICON));
	wcex.hCursor		= LoadCursor(NULL, IDC_ARROW);
	wcex.hbrBackground = NULL;//(HBRUSH)(COLOR_WINDOW+1);
	wcex.lpszMenuName	= MAKEINTRESOURCE(IDC_BOOLYWOODAFILMGUESSINGGAME);
	wcex.lpszClassName	= szWindowClass;
	wcex.hIconSm		= LoadIcon(wcex.hInstance, MAKEINTRESOURCE(IDI_MAINICON));

	return RegisterClassEx(&wcex);
}
/*! \fn InitInstance(HINSTANCE hInstance, int nCmdShow)
Saves instance handle and creates main window. In this function, we save the instance handle in a global variable and create and display the main program window.
*/

BOOL InitInstance(HINSTANCE hInstance, int nCmdShow)
{
   HWND hWnd;
   hInst = hInstance; // Store instance handle in our global variable
   hWnd = CreateWindow(szWindowClass, szTitle, WS_OVERLAPPEDWINDOW,
	   40, 2, 1016, 687, NULL, NULL, hInstance, NULL);

   if (!hWnd)
   {
      return FALSE;
   }

   ShowWindow(hWnd, nCmdShow);
   UpdateWindow(hWnd);

   return TRUE;
}
/*! \fn WndProc(HWND hWnd, UINT message, WPARAM wParam, LPARAM lParam)
Processes messages for the main window. It is the heart of the program, process all the inputs from user as well as internal inputs
WM_COMMAND	- process the application menu
WM_PAINT	- Paint the main window
WM_DESTROY	- post a quit message and return
*/
LRESULT CALLBACK WndProc(HWND hWnd, UINT message, WPARAM wParam, LPARAM lParam)
{
	int wmId, wmEvent;
	PAINTSTRUCT ps;
	HDC hdc; static HFONT hFont,hFonts,hFontt,hFontu;
	static TCHAR szBuffer[100],k;
	static int cxChar, cxChars, cyChar, cyChars, cxChart, cyChart, iWidth, iHeight, iCenter; 
	TEXTMETRIC  tm; RECT rect;
	switch (message)
	{
	case WM_CREATE:
	{
					  film_importer();
					  DataSorter(GENRE_INDEX);
					  //Initialize Gdi+ to use graphic objects
					  GdiplusStartup(&m_gdiplusToken, &gdiplusStartupInput, NULL);
					  //Initialize bass to use sounds
					  BASS_Init(-1, 44100, 0, hWnd, NULL);
					  quit = BASS_StreamCreateFile(FALSE, L"DATA/Sounds/quit.wav", 0, 0, BASS_ASYNCFILE);
					  uhuh = BASS_StreamCreateFile(FALSE, L"DATA/Sounds/uhuh.wav", 0, 0, BASS_ASYNCFILE );
					  yeah = BASS_StreamCreateFile(FALSE, L"DATA/Sounds/yeah.wav", 0, 0, BASS_ASYNCFILE );
					  hang = BASS_StreamCreateFile(FALSE, L"DATA/Sounds/hang.wav", 0, 0, BASS_ASYNCFILE );
					  MenuClick = BASS_StreamCreateFile(FALSE, L"DATA/Sounds/Menu_click.wav", 0, 0, BASS_ASYNCFILE );
					  //Fonts to use in different parts of program
					  hdc = GetDC(hWnd);
					  hFont = CreateFont(40, 11, 0, 0, FW_DONTCARE, FALSE, FALSE, FALSE, DEFAULT_CHARSET, OUT_OUTLINE_PRECIS,
						  CLIP_DEFAULT_PRECIS, CLEARTYPE_QUALITY, VARIABLE_PITCH, TEXT("Mistral"));
					  hFonts = CreateFont(25, 8, 0, 0, FW_DONTCARE, FALSE, FALSE, FALSE, DEFAULT_CHARSET, OUT_OUTLINE_PRECIS,
						  CLIP_DEFAULT_PRECIS, CLEARTYPE_QUALITY, VARIABLE_PITCH, TEXT("Mistral"));
					  hFontt = CreateFont(30, 8.5, 0, 0, FW_DONTCARE, FALSE, FALSE, FALSE, DEFAULT_CHARSET, OUT_OUTLINE_PRECIS,
						  CLIP_DEFAULT_PRECIS, CLEARTYPE_QUALITY, VARIABLE_PITCH, TEXT("Mistral"));
					  hFontu = CreateFont(40, 11, 0, 0, FW_DONTCARE, FALSE, TRUE, FALSE, DEFAULT_CHARSET, OUT_OUTLINE_PRECIS, CLIP_DEFAULT_PRECIS, CLEARTYPE_QUALITY, VARIABLE_PITCH, TEXT("Mistral"));
					  //Following code get the width and height of different fonts used in program
					  SelectObject(hdc, hFont);
					  GetTextMetrics(hdc, &tm);
					  cxChar = tm.tmAveCharWidth;
					  cyChar = tm.tmHeight + tm.tmExternalLeading;
					  SelectObject(hdc, hFonts);
					  GetTextMetrics(hdc, &tm);
					  cxChars = tm.tmAveCharWidth;
					  cyChars = tm.tmHeight + tm.tmExternalLeading;
					  SelectObject(hdc, hFontt);
					  GetTextMetrics(hdc, &tm);
					  cxChart = tm.tmAveCharWidth;
					  cyChart = tm.tmHeight + tm.tmExternalLeading;
					  GetClientRect(hWnd, &rect);
					  TempBGHdc = CreateCompatibleDC(hdc);
					  TempBGBitmap = CreateCompatibleBitmap(hdc, rect.right - rect.left, rect.bottom - rect.top);
					  SelectObject(TempBGHdc, TempBGBitmap);
					  ReleaseDC(hWnd, hdc);
					  KeyStrokesSaver[0] = '\0';
					  for (int m = 0; m<MAX_FILMS; m++)
						  checker[m] = -1;
					  SetTimer(hWnd, 1, 1000, NULL);
	}break;

	case WM_COMMAND:

	{
					   wmId = LOWORD(wParam);
					   wmEvent = HIWORD(wParam);
					   // Parse the menu selections:
					   switch (wmId)
					   {
					   case IDM_ABOUT:
						   DialogBox(hInst, MAKEINTRESOURCE(IDD_ABOUTBOX), hWnd, About);
						   break;
					   case IDC_DEBUG:
						   if (DebugMode == FALSE)
						   {
							   DebugMode = TRUE;

						   }
						   else if (DebugMode == TRUE)
							   DebugMode = FALSE;
						   GetClientRect(hWnd, &rect);
						   InvalidateRect(hWnd, &rect, FALSE);
						   break;
					   case IDC_HINT:
						   if ((player1.hints > 0) && (GameStatus.CurentPlayer == PLAYER1))
						   {
							   player1.hints--;
							   ShowHint = TRUE;
							   GetClientRect(hWnd, &rect);
							   InvalidateRect(hWnd, &rect, FALSE);
						   }
						   if ((player2.hints > 0) && (GameStatus.CurentPlayer == PLAYER2))
						   {
							   player2.hints--;
							   ShowHint = TRUE;
							   GetClientRect(hWnd, &rect);
							   InvalidateRect(hWnd, &rect, FALSE);
						   }
						   break;
					   case ID_VISITWIKLINK:
						   if (GameStatus.CurrentMessage == GAME_HALTFORUSERINPUT)
						   {
							   if (lstrcmpi(L"NA", szFilmWikiLinks[iFilmNumberChoosen])== 0)
								   MessageBox(hWnd, L"Sorry no wikipedia link available for this film", L"Sorry!", MB_OK | MB_ICONEXCLAMATION);
							   else
							   {
								   TCHAR temp[100];
								   if ((szFilmWikiLinks[iFilmNumberChoosen][0] != L'w') && (szFilmWikiLinks[iFilmNumberChoosen][1] != L'w') && (szFilmWikiLinks[iFilmNumberChoosen][2] != L'w'))
								   {
									   temp[0] = L'w'; temp[1] = L'w'; temp[2] = L'w'; temp[3] = L'.';
									   for (int i = 0; szFilmWikiLinks[iFilmNumberChoosen][i] != '\0'; i++)
									   {
										   temp[i + 4] = szFilmWikiLinks[iFilmNumberChoosen][i];
										   temp[i + 5] = '\0';
									   }
								   }
								   else
									   lstrcpy(temp, szFilmWikiLinks[iFilmNumberChoosen]);
								   ShellExecute(hWnd, L"open", temp, NULL, NULL, SW_SHOWNORMAL);
							   }
						   }
						   break;
					   case ID_VISITIMDBLINK:
						   if (GameStatus.CurrentMessage == GAME_HALTFORUSERINPUT)
						   {
							   if (lstrcmpi(L"NA", szFilmImdbLinks[iFilmNumberChoosen]) == 0)
								   MessageBox(hWnd, L"Sorry no IMDB link available for this film", L"Sorry!", MB_OK | MB_ICONEXCLAMATION);
							   else
							   {
								   TCHAR temp[100];
								   if ((szFilmImdbLinks[iFilmNumberChoosen][0] != L'w') && (szFilmImdbLinks[iFilmNumberChoosen][1] != L'w') && (szFilmImdbLinks[iFilmNumberChoosen][2] != L'w'))
								   {
									   temp[0] = L'w'; temp[1] = L'w'; temp[2] = L'w'; temp[3] = L'.';
									   for (int i = 0; szFilmImdbLinks[iFilmNumberChoosen][i] != '\0'; i++)
									   {
										   temp[i + 4] = szFilmImdbLinks[iFilmNumberChoosen][i];
										   temp[i + 5] = '\0';
									   }
								   }
								   else
									   lstrcpy(temp, szFilmImdbLinks[iFilmNumberChoosen]);
								   ShellExecute(hWnd, L"open", temp, NULL, NULL, SW_SHOWNORMAL);
							   }
						   }
						   break;
					   case ID_HELP_README:
						   ShellExecute(hWnd, L"open", L"Do not readme.txt", NULL, NULL, SW_SHOWNORMAL);
						   break;
					   case IDM_EXIT:
						   BASS_ChannelPlay(
							   quit,
							   TRUE
							   );
						   if (MessageBox(hWnd, L"Are you sure you want to quit", L"Confirmation!", MB_OKCANCEL | MB_ICONEXCLAMATION) == IDOK)
							   DestroyWindow(hWnd);
						   break;
					   case ID_FILE_OPTIONS:
						   iScreen = SCREEN_OPTIONS;
						   GetClientRect(hWnd, &rect);
						   InvalidateRect(hWnd, &rect, FALSE);
						   break;
					   case ID_FILE_NEWGAME:
						   if (GameStatus.CurrentMessage==GAME_PAUSE)
							   DialogBox(hInst, MAKEINTRESOURCE(IDD_DIALOG1), hWnd, NewGame);
						   else
						   {
							   if (MessageBox(hWnd, L"Are you sure you want to leave your current game", L"Confirmation!", MB_OKCANCEL | MB_ICONWARNING) == IDOK)
							   {
								   
								   DialogBox(hInst, MAKEINTRESOURCE(IDD_DIALOG1), hWnd, NewGame);
							   }
							 
						   }
						   if (IsDialogOk==TRUE)
						   {
							  
							   for (int i = MAX_FILMS-1; i >= 0; i--)
								   checker[i] = -1; iScreen = SCREEN_PLAY;
							   initiali = 0; DataResetter(FALSE, TRUE, TRUE);
							   player1.score = 0; player2.score = 0; player1.hints = 0; player2.hints = 0; GameStatus.Lives = 0;
							   GameStatus.CurrentChances = 0;
							   GameStatus.CurrentMessage = GAME_PLAYING;
							   szBollywood[0] = L'B'; szBollywood[1] = L'O'; szBollywood[2] = L'L'; szBollywood[3] = L'L'; szBollywood[4] = L'Y'; szBollywood[5] = L'W'; szBollywood[6] = L'O'; szBollywood[7] = L'O'; szBollywood[8] = L'D'; szBollywood[9] = L'\0';
							   iFilmNumberChoosen = FilmChooser();
							   FilmNameWithBlanks(szFilmNames[iFilmNumberChoosen]);
							   GetClientRect(hWnd, &rect);
							   InvalidateRect(hWnd, &rect, TRUE); IsDialogOk = FALSE;

						   }
						   
						   break;
					   default:
						   return DefWindowProc(hWnd, message, wParam, lParam);
					   }
	}	break;
	case WM_CHAR:
	{
					ShowHint = FALSE;
					if ((GameStatus.CurrentMessage == GAME_HALTFORUSERINPUT) && (LOWORD(wParam) == VK_RETURN))
					{
						if (GameMode == TWO_PLAYER_PLAY)
						{
							if (GameStatus.CurentPlayer == PLAYER1)
							{
								GameStatus.CurentPlayer = PLAYER2;
							}
							else if (GameStatus.CurentPlayer == PLAYER2)
							{
								GameStatus.CurentPlayer = PLAYER1;
							}
						}

						GameControler(); iDisplayCode = GAME_PLAYING;
					}
					else if ((GameStatus.CurrentMessage == GAME_PAUSE) && (LOWORD(wParam) == VK_RETURN) && (GameStatus.PreviousMessage == GAME_HALTFORUSERINPUT))
					{

						iScreen = SCREEN_INITIAL;
					}
					TCHAR characterinputed[2];
					characterinputed[0] = (TCHAR)LOWORD(wParam); characterinputed[1] = '\0';
					if (GameStatus.CurrentMessage == GAME_PLAYING)
					{
						characterinputed[0] = toupper(characterinputed[0]);
						k = toupper(characterinputed[0]);
						if (((k >= L'A') && (k <= 'Z')) || ((k >= '0') && (k <= '9')))
						{
							srand((unsigned)time(NULL));
							iQuotesCode = rand() % 6;
							int iZ;
							iZ = CharChecker(szFilmNames[iFilmNumberChoosen], k);
							iDisplayCode = iZ;
							if (iZ == CHAR_NOTFOUND)
							{
								szBollywood[GameStatus.Lives] = '/';
								GameStatus.Lives++; BASS_ChannelPlay(uhuh, TRUE);
								if (GameStatus.Lives == 9)
								{
									GameStatus.PreviousMessage = GameStatus.CurrentMessage;
									GameStatus.CurrentMessage = GAME_OUTOFLIVES;
									BASS_ChannelPlay(hang, TRUE);
								}
							}
							else if (iZ == CHAR_FOUND)
							{
								BASS_ChannelPlay(yeah, TRUE);
								if (BlanksFiller(szFilmWithBlanks, szFilmNames[iFilmNumberChoosen], k) == 1)
								{
									GameStatus.PreviousMessage = GameStatus.CurrentMessage;
									GameStatus.CurrentMessage = GAME_PLAYER1ONETIMEWON;
									if (GameStatus.CurentPlayer == PLAYER1)
									{
										player1.score++;
										if (GameStatus.Lives == 0)
											player1.hints++;
									}
									if (GameStatus.CurentPlayer == PLAYER2)
									{
										player2.score++;
										if (GameStatus.Lives == 0)
											player2.hints++;
									}
								}

							}

						}
					}
					GetClientRect(hWnd, &rect);
					InvalidateRect(hWnd, &rect, FALSE);

	}break;
	case WM_MOUSEMOVE:
		MousePosition.x = LOWORD(lParam);
		MousePosition.y = HIWORD(lParam);
		GetClientRect(hWnd, &rect);
		if (iScreen == SCREEN_INITIAL)
		{

			if (((MousePosition.x <= (450 + ((0.5*rect.right) - 275))) && (MousePosition.x >= ((0.5*rect.right) - 275)) && (MousePosition.y <= (60 + ((0.5*rect.bottom) - (30 + 110/*Change this value to go up and down*/)))) && (MousePosition.y >= ((0.5*rect.bottom) - (30 + 110/*Change this value to go up and down*/)))) || ((MousePosition.x <= (450 + ((0.5*rect.right) - 275))) && (MousePosition.x >= ((0.5*rect.right) - 275)) && (MousePosition.y <= (60 + ((0.5*rect.bottom) - (30 + 40/*Change this value to go up and down*/)))) && (MousePosition.y >= ((0.5*rect.bottom) - (30 + 40/*Change this value to go up and down*/)))) || ((MousePosition.x <= (450 + ((0.5*rect.right) - 275))) && (MousePosition.x >= ((0.5*rect.right) - 275)) && (MousePosition.y <= (60 + ((0.5*rect.bottom) - (30 - 30/*Change this value to go up and down*/)))) && (MousePosition.y >= ((0.5*rect.bottom) - (30 - 30/*Change this value to go up and down*/)))) || ((MousePosition.x <= (450 + ((0.5*rect.right) - 275))) && (MousePosition.x >= ((0.5*rect.right) - 275)) && (MousePosition.y <= (60 + ((0.5*rect.bottom) - (30 - 100/*Change this value to go up and down*/)))) && (MousePosition.y >= ((0.5*rect.bottom) - (30 - 100/*Change this value to go up and down*/)))))
			{
				InvalidateRect(hWnd, &rect, FALSE); Invalidat = 0;
			}
			else
			{
				iMenuSound2 = 0;
				Invalidat++;
			}
			if (Invalidat == 1)
				InvalidateRect(hWnd, &rect, FALSE);
			if (iMenuSound3 != iMenuSound2)
			{
				if ((iMenuSound2 >= 1) && (iMenuSound2 <= 4))
					BASS_ChannelPlay(MenuClick, FALSE);
				iMenuSound3 = iMenuSound2;
			}
		}
		if ((iScreen == SCREEN_OPTIONS) && (MousePosition.IsMouseDown == TRUE))
		{
			if ((MousePosition.x <= ((0.5*rect.right) + iVolumeLevel + 22)) && (MousePosition.x >= ((0.5*rect.right) + iVolumeLevel)) && (MousePosition.y >= (0.5*rect.bottom + (cyChar * 0.7))) && (MousePosition.y <= (0.5*rect.bottom + (cyChar * 0.7) + 22)))
			{
				if ((MousePosition.x - MousePosition.PreviousX >= 300) && (iVolumeLevel >= -78))
				{
					InvalidateRect(hWnd, &rect, FALSE);
					iVolumeLevel -= 22;
					if (fVolumeLevel > 0.0)
					fVolumeLevel -= 0.1;
					BASS_ChannelSetAttribute(
						BGMusic,
						BASS_ATTRIB_VOL,
						fVolumeLevel
						);
					MousePosition.PreviousX = MousePosition.x;
					MousePosition.PreviousY = MousePosition.y;
				}
				if ((MousePosition.PreviousX - MousePosition.x >= 300) && (iVolumeLevel <= 98))
				{
					InvalidateRect(hWnd, &rect, FALSE);
					iVolumeLevel += 22;
					if (fVolumeLevel < 1.0)
						fVolumeLevel += 0.1;
					BASS_ChannelSetAttribute(
						BGMusic,
						BASS_ATTRIB_VOL,
						fVolumeLevel
						);
					MousePosition.PreviousX = MousePosition.x;
					MousePosition.PreviousY = MousePosition.y;
				}
			}
			if ((MousePosition.x <= ((0.5*rect.right) + iFXLevel + 22)) && (MousePosition.x >= ((0.5*rect.right) + iFXLevel)) && (MousePosition.y >= (0.5*rect.bottom + (cyChar * 4.7))) && (MousePosition.y <= (0.5*rect.bottom + (cyChar * 4.7) + 22)))
			{
				if ((MousePosition.x - MousePosition.PreviousX >= 300) && (iFXLevel >= -78))
				{
					InvalidateRect(hWnd, &rect, FALSE);
					iFXLevel -= 22;
					if (fFXLevel > 0.0)
						fFXLevel -= 0.1;
					BASS_ChannelSetAttribute(quit, BASS_ATTRIB_VOL, fFXLevel);
					BASS_ChannelSetAttribute(uhuh, BASS_ATTRIB_VOL, fFXLevel);
					BASS_ChannelSetAttribute(yeah, BASS_ATTRIB_VOL, fFXLevel);
					BASS_ChannelSetAttribute(hang, BASS_ATTRIB_VOL, fFXLevel);
					BASS_ChannelSetAttribute(MenuClick, BASS_ATTRIB_VOL, fFXLevel);
					MousePosition.PreviousX = MousePosition.x;
					MousePosition.PreviousY = MousePosition.y;
				}
				if ((MousePosition.PreviousX - MousePosition.x >= 300) && (iFXLevel <= 98))
				{
					InvalidateRect(hWnd, &rect, FALSE);
					iFXLevel += 22;
					if (fFXLevel < 1.0)
						fFXLevel += 0.1;
					BASS_ChannelSetAttribute(quit, BASS_ATTRIB_VOL, fFXLevel);
					BASS_ChannelSetAttribute(uhuh, BASS_ATTRIB_VOL, fFXLevel);
					BASS_ChannelSetAttribute(yeah, BASS_ATTRIB_VOL, fFXLevel);
					BASS_ChannelSetAttribute(hang, BASS_ATTRIB_VOL, fFXLevel);
					BASS_ChannelSetAttribute(MenuClick, BASS_ATTRIB_VOL, fFXLevel);
					MousePosition.PreviousX = MousePosition.x;
					MousePosition.PreviousY = MousePosition.y;
				}
			}
		}
				
		break;
	case WM_LBUTTONDOWN:
		GetClientRect(hWnd, &rect);
		if (iScreen == SCREEN_OPTIONS)
		{
			if ((MousePosition.x <= ((0.5*rect.right) + iVolumeLevel + 22)) && (MousePosition.x >= ((0.5*rect.right) + iVolumeLevel)) && (MousePosition.y >= (0.5*rect.bottom + (cyChar * 0.7))) && (MousePosition.y <= (0.5*rect.bottom + (cyChar * 0.7) + 22)))
			{
				MousePosition.IsMouseDown = TRUE;
				MousePosition.PreviousX = MousePosition.x;
				MousePosition.PreviousY = MousePosition.y;
			}
			if ((MousePosition.x <= ((0.5*rect.right) + iFXLevel + 22)) && (MousePosition.x >= ((0.5*rect.right) + iFXLevel)) && (MousePosition.y >= (0.5*rect.bottom + (cyChar * 4.7))) && (MousePosition.y <= (0.5*rect.bottom + (cyChar * 4.7) + 22)))
			{
				MousePosition.IsMouseDown = TRUE;
				MousePosition.PreviousX = MousePosition.x;
				MousePosition.PreviousY = MousePosition.y;
			}
			if ((MousePosition.x > 0.7*rect.right - ((lstrlen(L"Go Back")*cxChar) / 2)) && (MousePosition.x < 0.7*rect.right + (lstrlen(L"Go Back")*cxChar)) && (MousePosition.y>0.5*rect.bottom + (cyChar * 6)) && (MousePosition.y<0.5*rect.bottom + (cyChar * 6)+33))
			{
				if (GameStatus.CurrentMessage == GAME_PAUSE)
					iScreen = SCREEN_INITIAL;
				else
					iScreen = SCREEN_PLAY;
				InvalidateRect(hWnd, &rect,FALSE);
			}
		}
		MousePosition.x = LOWORD(lParam);
		MousePosition.y = HIWORD(lParam);
		if (iScreen == SCREEN_INITIAL)
		{
			GetClientRect(hWnd, &rect);
			if ((MousePosition.x <= (450 + ((0.5*rect.right) - 275))) && (MousePosition.x >= ((0.5*rect.right) - 275)) && (MousePosition.y <= (60 + ((0.5*rect.bottom) - (30 + 110/*Change this value to go up and down*/)))) && (MousePosition.y >= ((0.5*rect.bottom) - (30 + 110/*Change this value to go up and down*/))))
				SendMessage(hWnd, WM_COMMAND, ID_FILE_NEWGAME, NULL);
			if ((MousePosition.x <= (450 + ((0.5*rect.right) - 275))) && (MousePosition.x >= ((0.5*rect.right) - 275)) && (MousePosition.y <= (60 + ((0.5*rect.bottom) - (30 - 100/*Change this value to go up and down*/)))) && (MousePosition.y >= ((0.5*rect.bottom) - (30 - 100/*Change this value to go up and down*/))))
				SendMessage(hWnd, WM_COMMAND, IDM_EXIT, NULL);
			if ((MousePosition.x <= (450 + ((0.5*rect.right) - 275))) && (MousePosition.x >= ((0.5*rect.right) - 275)) && (MousePosition.y <= (60 + ((0.5*rect.bottom) - (30 + 40/*Change this value to go up and down*/)))) && (MousePosition.y >= ((0.5*rect.bottom) - (30 + 40/*Change this value to go up and down*/))))
			{
					iScreen = SCREEN_OPTIONS;
				InvalidateRect(hWnd, &rect, FALSE);
			}
			if ((MousePosition.x <= (450 + ((0.5*rect.right) - 275))) && (MousePosition.x >= ((0.5*rect.right) - 275)) && (MousePosition.y <= (60 + ((0.5*rect.bottom) - (30 - 30/*Change this value to go up and down*/)))) && (MousePosition.y >= ((0.5*rect.bottom) - (30 - 30/*Change this value to go up and down*/))))
				SendMessage(hWnd, WM_COMMAND, ID_HELP_README, NULL);
		}
			break;
	case WM_LBUTTONUP:
		MousePosition.IsMouseDown = FALSE;
		break;
	case WM_TIMER:
		
		
			if (BASS_ChannelIsActive(BGMusic) != BASS_ACTIVE_PLAYING)
			{
				srand((unsigned)time(NULL));
				int k = rand() % 8;
				if (k==1)
					BGMusic = BASS_StreamCreateFile(FALSE, BGMusic1, 0, 0, BASS_ASYNCFILE | BASS_STREAM_AUTOFREE);
				else if (k == 2)
					BGMusic = BASS_StreamCreateFile(FALSE, BGMusic2, 0, 0, BASS_ASYNCFILE | BASS_STREAM_AUTOFREE);
				else if (k == 3)
					BGMusic = BASS_StreamCreateFile(FALSE, BGMusic3, 0, 0, BASS_ASYNCFILE | BASS_STREAM_AUTOFREE);
				else if (k == 4)
					BGMusic = BASS_StreamCreateFile(FALSE, BGMusic4, 0, 0, BASS_ASYNCFILE | BASS_STREAM_AUTOFREE);
				else if (k == 5)
					BGMusic = BASS_StreamCreateFile(FALSE, BGMusic5, 0, 0, BASS_ASYNCFILE | BASS_STREAM_AUTOFREE);
				else if (k == 6)
					BGMusic = BASS_StreamCreateFile(FALSE, BGMusic6, 0, 0, BASS_ASYNCFILE | BASS_STREAM_AUTOFREE);
				else if (k == 7)
					BGMusic = BASS_StreamCreateFile(FALSE, BGMusic7, 0, 0, BASS_ASYNCFILE | BASS_STREAM_AUTOFREE);
				BASS_ChannelPlay(BGMusic, TRUE);
				BASS_ChannelSetAttribute(BGMusic,BASS_ATTRIB_VOL,fVolumeLevel);
			}
		
		break;
	case WM_PAINT:
	{
					 hdc = BeginPaint(hWnd, &ps);
					 GetClientRect(hWnd, &rect);
					 Graphics graphics(TempBGHdc);
					 SetBkMode(TempBGHdc, TRANSPARENT);
					 SelectObject(TempBGHdc, hFont);
					 // Initialize the color matrix.
					 // Change the value in row 4, column 4 to change the transparency.
					 ColorMatrix colorMatrix = {
						 1.0f, 0.0f, 0.0f, 0.0f, 0.0f,
						 0.0f, 1.0f, 0.0f, 0.0f, 0.0f,
						 0.0f, 0.0f, 1.0f, 0.0f, 0.0f,
						 0.0f, 0.0f, 0.0f, 0.5f, 0.0f,
						 0.0f, 0.0f, 0.0f, 0.0f, 1.0f };
					 // Create an ImageAttributes object and set its color matrix.
					 ImageAttributes imageAtt;
					 imageAtt.SetColorMatrix(&colorMatrix, ColorMatrixFlagsDefault, ColorAdjustTypeBitmap);
					 if (iScreen == SCREEN_PLAY)
					 {
						 if (GameStatus.CurrentMessage == GAME_OUTOFLIVES)
						 {
							 srand((unsigned)time(NULL));
							 int ch = rand() % 5;
							 TextOut(TempBGHdc, iCenter - ((lstrlen(szNotGuessedTheMovie[ch])*cxChar) / 2), rect.bottom - ((cyChar * -2) + (0.8*rect.bottom)), szNotGuessedTheMovie[ch], lstrlen(szNotGuessedTheMovie[ch]));
						 }
						 
						 Bitmap image(L"DATA/Images/design-background-patterns.png");
						 Bitmap but(L"DATA/Images/Panel_square.png");
						 graphics.DrawImage(&image, 0, 0, rect.right, rect.bottom);
						 graphics.DrawImage(
							 &but,
							 Rect(rect.right - 0.23*rect.right, 0, 0.23*rect.right, rect.bottom),  // Destination rectangle
							 0,                             // Source rectangle X 
							 0,                             // Source rectangle Y
							 but.GetWidth(),                        // Source rectangle width
							 but.GetHeight(),                       // Source rectangle height
							 UnitPixel,
							 &imageAtt);
						 Pen greenpen(Color(255, 91, 115, 15), 5);
						 graphics.DrawLine(&greenpen, rect.right - 0.23*rect.right, rect.top + 0.35*rect.bottom, rect.right, rect.top + 0.35*rect.bottom);

						 if (GameStatus.Lives == 1)
						 {
							 int x = (rect.right + 0.02*rect.right) - 0.25*rect.right;//x-coordinate of hangman
							 Bitmap Hangman(L"DATA/Images/Hangman/hangman8.png"); graphics.DrawImage(&Hangman, x, rect.top + 0.15*rect.bottom + (rect.bottom - 0.8*rect.bottom), 0.25*(INT)rect.right, 0.8*(INT)rect.bottom);
						 }
						 else if (GameStatus.Lives == 2)
						 {
							 int x = (rect.right + 0.02*rect.right) - 0.25*rect.right;//x-coordinate of hangman
							 Bitmap Hangman(L"DATA/Images/Hangman/hangman7.png"); graphics.DrawImage(&Hangman, x, rect.top + 0.15*rect.bottom + (rect.bottom - 0.8*rect.bottom), 0.25*(INT)rect.right, 0.8*(INT)rect.bottom);
						 }
						 else if (GameStatus.Lives == 3)
						 {
							 int x = (rect.right + 0.02*rect.right) - 0.25*rect.right;//x-coordinate of hangman
							 Bitmap Hangman(L"DATA/Images/Hangman/hangman6.png"); graphics.DrawImage(&Hangman, x, rect.top + 0.15*rect.bottom + (rect.bottom - 0.8*rect.bottom), 0.25*(INT)rect.right, 0.8*(INT)rect.bottom);
						 }
						 else if (GameStatus.Lives == 4)
						 {
							 int x = (rect.right + 0.02*rect.right) - 0.25*rect.right;//x-coordinate of hangman
							 Bitmap Hangman(L"DATA/Images/Hangman/hangman5.png"); graphics.DrawImage(&Hangman, x, rect.top + 0.15*rect.bottom + (rect.bottom - 0.8*rect.bottom), 0.25*(INT)rect.right, 0.8*(INT)rect.bottom);
						 }
						 else if (GameStatus.Lives == 5)
						 {
							 int x = (rect.right + 0.02*rect.right) - 0.25*rect.right;//x-coordinate of hangman
							 Bitmap Hangman(L"DATA/Images/Hangman/hangman4.png"); graphics.DrawImage(&Hangman, x, rect.top + 0.15*rect.bottom + (rect.bottom - 0.8*rect.bottom), 0.25*(INT)rect.right, 0.8*(INT)rect.bottom);
						 }
						 else if (GameStatus.Lives == 6)
						 {
							 int x = (rect.right + 0.02*rect.right) - 0.25*rect.right;//x-coordinate of hangman
							 Bitmap Hangman(L"DATA/Images/Hangman/hangman3.png"); graphics.DrawImage(&Hangman, x, rect.top + 0.15*rect.bottom + (rect.bottom - 0.8*rect.bottom), 0.25*(INT)rect.right, 0.8*(INT)rect.bottom);
						 }
						 else if (GameStatus.Lives == 7)
						 {
							 int x = (rect.right + 0.02*rect.right) - 0.25*rect.right;//x-coordinate of hangman
							 Bitmap Hangman(L"DATA/Images/Hangman/hangman2.png"); graphics.DrawImage(&Hangman, x, rect.top + 0.15*rect.bottom + (rect.bottom - 0.8*rect.bottom), 0.25*(INT)rect.right, 0.8*(INT)rect.bottom);
						 }
						 else if (GameStatus.Lives == 8)
						 {
							 int x = (rect.right + 0.02*rect.right) - 0.25*rect.right;//x-coordinate of hangman
							 Bitmap Hangman(L"DATA/Images/Hangman/hangman1.png"); graphics.DrawImage(&Hangman, x, rect.top + 0.15*rect.bottom + (rect.bottom - 0.8*rect.bottom), 0.25*(INT)rect.right, 0.8*(INT)rect.bottom);
						 }
						 else if (GameStatus.Lives == 9)
						 {
							 int x = (rect.right + 0.02*rect.right) - 0.25*rect.right;//x-coordinate of hangman
							 Bitmap Hangman(L"DATA/Images/Hangman/hangman_full.png"); graphics.DrawImage(&Hangman, x, rect.top + 0.15*rect.bottom + (rect.bottom - 0.8*rect.bottom), 0.25*(INT)rect.right, 0.8*(INT)rect.bottom);
						 }
						 SelectObject(TempBGHdc, hFont);//Change font
						 SetTextColor(TempBGHdc, RGB(91, 115, 15));//Change color to green
						 iCenter = (0.77*rect.right) / 2;
						 if ((GameStatus.CurrentMessage == GAME_OUTOFLIVES) || ((GameStatus.CurrentMessage == GAME_HALTFORUSERINPUT&&GameStatus.PreviousMessage == GAME_OUTOFLIVES)))
						 {
							 TextOut(TempBGHdc, iCenter - (((lstrlen(L"The film was: ") + lstrlen(szFilmNames[iFilmNumberChoosen]))*cxChar) / 2), rect.bottom - ((cyChar * 2) + (0.8*rect.bottom)), L"The film was: ", lstrlen(L"The film was: "));
							 TextOut(TempBGHdc, iCenter - (((lstrlen(szFilmNames[iFilmNumberChoosen]) - lstrlen(L"The film was: "))*cxChar) / 2), rect.bottom - ((cyChar * 2) + (0.8*rect.bottom)), szFilmNames[iFilmNumberChoosen], lstrlen(szFilmNames[iFilmNumberChoosen]));
						 }
						 else
						 {
							 TextOut(TempBGHdc, iCenter - (((lstrlen(L"You have to guess in: ") + lstrlen(szFilmWithBlanks))*cxChar) / 2), rect.bottom - ((cyChar * 2) + (0.8*rect.bottom)), L"You have to guess in: ", lstrlen(L"You have to guess in: "));
							 TextOut(TempBGHdc, iCenter - (((lstrlen(szFilmWithBlanks) - lstrlen(L"You have to guess in: "))*cxChar) / 2), rect.bottom - ((cyChar * 2) + (0.8*rect.bottom)), szFilmWithBlanks, lstrlen(szFilmWithBlanks));
						 }
						 if (DebugMode==TRUE)
						 TextOut(TempBGHdc, 2, cyChar * 4, szFilmNames[iFilmNumberChoosen], lstrlen(szFilmNames[iFilmNumberChoosen]));
						 TextOut(TempBGHdc, iCenter - (((lstrlen(L"This film was released in year:") + lstrlen(szFilmReleaseDate[iFilmNumberChoosen]))*cxChar) / 2), rect.bottom - ((cyChar * 1) + (0.8*rect.bottom)), L"This film was released in year:", lstrlen(L"This film was released in year:"));
						 TextOut(TempBGHdc, iCenter - (((lstrlen(szFilmReleaseDate[iFilmNumberChoosen]) - lstrlen(L"This film was released in year:"))*cxChar) / 2), rect.bottom - ((cyChar * 1) + (0.8*rect.bottom)), szFilmReleaseDate[iFilmNumberChoosen], lstrlen(szFilmReleaseDate[iFilmNumberChoosen]));
						 TextOut(TempBGHdc, (rect.right - ((0.23*rect.right) / 2) - (((lstrlen(szBollywood) + 6) *cxChars) / 2)), (0.2*rect.bottom) + cyChar, szBollywood, lstrlen(szBollywood));
						 SelectObject(TempBGHdc, hFonts);
						 if (GameStatus.CurentPlayer==PLAYER1)
							 SetTextColor(TempBGHdc, RGB(91, 40, 15));
						 else
							 SetTextColor(TempBGHdc, RGB(91, 115, 15));
						 TextOut(TempBGHdc, (rect.right - ((0.23*rect.right) / 2) - (((lstrlen(L"Player 1: ") + lstrlen(szFirstPlayerName)) *cxChars) / 2)), cyChars * 0, L"Player 1: ", lstrlen(L"Player 1: "));
						 TextOut(TempBGHdc, (rect.right - ((0.23*rect.right) / 2) - ((lstrlen(szFirstPlayerName) - lstrlen(L"Player 1: ")) *cxChars) / 2), cyChars * 0, szFirstPlayerName, lstrlen(szFirstPlayerName));
						 static int iT; iT = wsprintf(szBuffer, L"Score: %d Hints: %d", player1.score, player1.hints);
						 TextOut(TempBGHdc, (rect.right - ((0.23*rect.right) / 2) - (iT *cxChars) / 2), cyChars * 1, szBuffer, iT);
						 if (GameMode == TWO_PLAYER_PLAY)
						 {
							 if (GameStatus.CurentPlayer == PLAYER2)
								 SetTextColor(TempBGHdc, RGB(91, 40, 15));
							 else
								 SetTextColor(TempBGHdc, RGB(91, 115, 15));
							 TextOut(TempBGHdc, (rect.right - ((0.23*rect.right) / 2) - (((lstrlen(L"Player 2: ") + lstrlen(szSecondPlayerName)) *cxChars) / 2)), (cyChars * 2) + 20, L"Player 2: ", lstrlen(L"Player 2: "));
							 TextOut(TempBGHdc, (rect.right - ((0.23*rect.right) / 2) - ((lstrlen(szSecondPlayerName) - lstrlen(L"Player 2: ")) *cxChars) / 2), (cyChars * 2) + 20, szSecondPlayerName, lstrlen(szSecondPlayerName));
							 iT = wsprintf(szBuffer, L"Score: %d Hints: %d", player2.score, player2.hints);
							 TextOut(TempBGHdc, (rect.right - ((0.23*rect.right) / 2) - (iT *cxChars) / 2), (cyChars * 3) + 20, szBuffer, iT);
						 }
						 SelectObject(TempBGHdc, hFont);
						 TCHAR Alphabets[2]; int x = 10, y = 4, z = 0;
						 if ((GameStatus.CurrentMessage != GAME_HALTFORUSERINPUT) && (GameStatus.CurrentMessage != GAME_PLAYER1ONETIMEWON) && (GameStatus.CurrentMessage != GAME_OUTOFLIVES))
						 {
							 for (int i = 0; i < 26; i++)
							 {
								 for (int j = 0; KeyStrokesSaver[j] != '\0'; j++)
								 {
									 if (KeyStrokesSaver[j] == 'A' + i)
										 SetTextColor(TempBGHdc, RGB(91, 40, 15));
								 }
								 if (('A' + i == 'A') || ('A' + i == 'E') || ('A' + i == 'I') || ('A' + i == 'O') || ('A' + i == 'U'))
									 SetTextColor(TempBGHdc, RGB(91, 40, 15));
								 TextOut(TempBGHdc, iCenter - (2 * x*(cxChar / 2)) + (z*cxChar * 2), rect.bottom - ((cyChar * y) + (0.2*rect.bottom)), Alphabets, wsprintf(Alphabets, L"%c", 'A' + i));
								 z++;
								 if (i == 9)
								 {
									 x = 8;; z = 0;
									 y--;
								 }
								 if (i == 17)
								 {
									 x = 5; y--; z = 0;
								 }
								 if (i == 22)
								 {
									 x = 3; y--; z = 0;
								 }
								 SetTextColor(TempBGHdc, RGB(91, 115, 15));
							 }
							 y++;
							 for (int i = 0; i < 10; i++)
							 {
								 for (int j = 0; KeyStrokesSaver[j] != '\0'; j++)
								 {
									 if (KeyStrokesSaver[j] == '0' + i)
										 SetTextColor(TempBGHdc, RGB(91, 40, 15));
								 }
								 TextOut(TempBGHdc, iCenter - (20 * (cxChar / 2)) + (i*cxChar * 2), rect.bottom - (0.2*rect.bottom), Alphabets, wsprintf(Alphabets, L"%c", '0' + i));
								 SetTextColor(TempBGHdc, RGB(91, 115, 15));
							 }
						 }
						 SetTextColor(TempBGHdc, RGB(91, 40, 15));
						 if (iDisplayCode==CHAR_REPEATED)
							 TextOut(TempBGHdc, iCenter - ((lstrlen(L"You have already inputed this alphabet")*cxChar) / 2), rect.bottom - ((cyChar * 0) + (0.8*rect.bottom)), L"You have already inputed this alphabet", lstrlen(L"You have already inputed this alphabet"));
						 else if (iDisplayCode==CHAR_VOWELORSPACE)
							 TextOut(TempBGHdc, iCenter - ((lstrlen(L"Please do not enter vowel")*cxChar) / 2), rect.bottom - ((cyChar * 0) + (0.8*rect.bottom)), L"Please do not enter vowel", lstrlen(L"Please do not enter vowel"));
						 if ((iDisplayCode == CHAR_NOTFOUND)&&(GameStatus.CurrentMessage != GAME_OUTOFLIVES))
						 {
							 
							 TextOut(TempBGHdc, iCenter - ((lstrlen(szWrongGuess[iQuotesCode])*cxChar) / 2), rect.bottom - ((cyChar * 0) + (0.8*rect.bottom)), szWrongGuess[iQuotesCode], lstrlen(szWrongGuess[iQuotesCode]));
						 }

						 if ((GameStatus.CurrentMessage == GAME_PLAYER1ONETIMEWON) || ((GameStatus.PreviousMessage == GAME_PLAYER1ONETIMEWON) && (GameStatus.CurrentMessage == GAME_HALTFORUSERINPUT)))

						 {
							 TextOut(TempBGHdc, iCenter - ((lstrlen(szCorrectlyGuessedMovie[iQuotesCode])*cxChart) / 2), rect.bottom - ((cyChart * 0) + (0.8*rect.bottom)), szCorrectlyGuessedMovie[iQuotesCode], lstrlen(szCorrectlyGuessedMovie[iQuotesCode]));
						 }
						 if ((GameStatus.CurrentMessage == GAME_OUTOFLIVES) || ((GameStatus.PreviousMessage == GAME_OUTOFLIVES) && (GameStatus.CurrentMessage == GAME_HALTFORUSERINPUT)))

						 {
							 TextOut(TempBGHdc, iCenter - ((lstrlen(szNotGuessedTheMovie[iQuotesCode])*cxChart) / 2), rect.bottom - ((cyChart * 0) + (0.8*rect.bottom)), szNotGuessedTheMovie[iQuotesCode], lstrlen(szNotGuessedTheMovie[iQuotesCode]));
						 }
						 if ((GameStatus.CurrentMessage == GAME_OUTOFLIVES) || (GameStatus.CurrentMessage == GAME_OVERFORONEPLAYERPLAY) || (GameStatus.CurrentMessage == GAME_PLAYER1ONETIMEWON))
						 {
							 GameStatus.PreviousMessage = GameStatus.CurrentMessage; GameStatus.CurrentMessage = GAME_HALTFORUSERINPUT;
							 iDisplayCode = 0;
							 GameStatus.CurrentChances++;
						 }
						 if ((GameStatus.CurrentMessage == GAME_HALTFORUSERINPUT) || (ShowHint == TRUE))
						 {
							 SelectObject(TempBGHdc, hFontt);
							 TextOut(TempBGHdc, iCenter - (((lstrlen(L"Director of this film: ") + lstrlen(szFilmDirector[iFilmNumberChoosen]))*cxChart) / 2), rect.bottom - ((cyChart * -2) + (0.8*rect.bottom)), L"Director of this film: ", lstrlen(L"Director of this film: "));
							 TextOut(TempBGHdc, iCenter - (((lstrlen(szFilmDirector[iFilmNumberChoosen]) - lstrlen(L"Director of this film: "))*cxChart) / 2), rect.bottom - ((cyChart * -2) + (0.8*rect.bottom)), szFilmDirector[iFilmNumberChoosen], lstrlen(szFilmDirector[iFilmNumberChoosen]));
							 TextOut(TempBGHdc, iCenter - (((lstrlen(L"Genre: ") + lstrlen(szFilmGenre[iFilmNumberChoosen]))*cxChart) / 2), rect.bottom - ((cyChart * -3) + (0.8*rect.bottom)), L"Genre: ", lstrlen(L"Genre: "));
							 TextOut(TempBGHdc, iCenter - (((lstrlen(szFilmGenre[iFilmNumberChoosen]) - lstrlen(L"Genre: "))*cxChart) / 2), rect.bottom - ((cyChart * -3) + (0.8*rect.bottom)), szFilmGenre[iFilmNumberChoosen], lstrlen(szFilmGenre[iFilmNumberChoosen]));
							 TextOut(TempBGHdc, iCenter - (((lstrlen(L"Main Cast:  ") + lstrlen(szFilmMainCast[iFilmNumberChoosen]))*cxChart) / 2), rect.bottom - ((cyChart * -4) + (0.8*rect.bottom)), L"Main Cast: ", lstrlen(L"Main Cast:  "));
							 TextOut(TempBGHdc, iCenter - (((lstrlen(szFilmMainCast[iFilmNumberChoosen]) - lstrlen(L"Main Cast:  "))*cxChart) / 2), rect.bottom - ((cyChart * -4) + (0.8*rect.bottom)), szFilmMainCast[iFilmNumberChoosen], lstrlen(szFilmMainCast[iFilmNumberChoosen]));
							 TextOut(TempBGHdc, iCenter - (((lstrlen(L"Wiki Link: ") + lstrlen(szFilmWikiLinks[iFilmNumberChoosen]))*cxChart) / 2), rect.bottom - ((cyChart * -5) + (0.8*rect.bottom)), L"Wiki Link: ", lstrlen(L"Wiki Link: "));
							 TextOut(TempBGHdc, iCenter - (((lstrlen(szFilmWikiLinks[iFilmNumberChoosen]) - lstrlen(L"Wiki Link: "))*cxChart) / 2), rect.bottom - ((cyChart * -5) + (0.8*rect.bottom)), szFilmWikiLinks[iFilmNumberChoosen], lstrlen(szFilmWikiLinks[iFilmNumberChoosen]));
							 TextOut(TempBGHdc, iCenter - (((lstrlen(L"IMDb Link: ") + lstrlen(szFilmImdbLinks[iFilmNumberChoosen]))*cxChart) / 2), rect.bottom - ((cyChart * -6) + (0.8*rect.bottom)), L"IMDb Link: ", lstrlen(L"IMDb Link: "));
							 TextOut(TempBGHdc, iCenter - (((lstrlen(szFilmImdbLinks[iFilmNumberChoosen]) - lstrlen(L"Wiki Link: "))*cxChart) / 2), rect.bottom - ((cyChart * -6) + (0.8*rect.bottom)), szFilmImdbLinks[iFilmNumberChoosen], lstrlen(szFilmImdbLinks[iFilmNumberChoosen]));
							 SetTextColor(TempBGHdc, RGB(91, 115, 15));
							 if (ShowHint == FALSE)
								 TextOut(TempBGHdc, iCenter - ((lstrlen(L"Press Enter to continue...")*cxChart) / 2), rect.bottom - ((cyChar * -8) + (0.8*rect.bottom)), L"Press Enter to continue...", lstrlen(L"Press Enter to continue..."));
							 
						 }
						 SelectObject(TempBGHdc, hFonts);
						 SetTextColor(TempBGHdc, RGB(91, 115, 15));
						 if (DebugMode == TRUE)
						 {
							 int k = wsprintf(szBuffer, L"Chances Left: %d Debug %d Right %d Bottom %d Top %d Left %d, Unique %d", MaxPlay - GameStatus.CurrentChances, GameStatus.CurrentMessage, rect.right, rect.bottom, rect.top, rect.left, iFilmNumberChoosen);
							 TextOut(TempBGHdc, 0, 0, szBuffer, k);
						 }
						 else
						 {
							 int k = wsprintf(szBuffer, L"Chances Left: %d", MaxPlay - GameStatus.CurrentChances);
							 TextOut(TempBGHdc, 0, 0, szBuffer, k);
						 }
					 }
					 if (iScreen == SCREEN_RESULTS)
					 {
						 SetTextColor(TempBGHdc, RGB(1, 58, 69));
						 Bitmap BackScr(L"DATA/Images/green-background-vector-designs.jpg");
						 graphics.DrawImage(&BackScr, 0, 0, rect.right, rect.bottom);
						 TextOut(TempBGHdc, 0.34*rect.right - ((lstrlen(L"Here are the scores")*cxChar) / 2), 0.5*rect.bottom + (cyChar*-7), L"Here are the scores", lstrlen(L"Here are scores     "));
						 if (GameMode == ONE_PLAYER_PLAY)
						 {
							 TextOut(TempBGHdc, 0.34*rect.right - ((lstrlen(L"The Game was of one player")*cxChar) / 2), 0.5*rect.bottom + (cyChar*-6), L"The Game was of one player", lstrlen(L"The Game was of one player"));
							 int l = wsprintf(szBuffer, L"  you have scored %d points", player1.score);
							 SelectObject(TempBGHdc, hFontt);
							 TextOut(TempBGHdc, 0.34*rect.right - (((lstrlen(szFirstPlayerName) + l)*cxChart) / 2), 0.5*rect.bottom + (cyChar*-4), szFirstPlayerName, lstrlen(szFirstPlayerName));
							 TextOut(TempBGHdc, 0.34*rect.right - (((l - lstrlen(szFirstPlayerName))*cxChart) / 2), 0.5*rect.bottom + (cyChar*-4), szBuffer, l);
							 l = wsprintf(szBuffer, L"By taking %d chances", MaxPlay);
							 TextOut(TempBGHdc, 0.34*rect.right - ((l*cxChart) / 2), 0.5*rect.bottom + (cyChar*-3), szBuffer, l);
							 int percentage = (((float)player1.score) / ((float)MaxPlay)) * 100;
							 l = wsprintf(szBuffer, L"Your scuccess percentage is %d %%", percentage);
							 TextOut(TempBGHdc, 0.34*rect.right - ((l*cxChart) / 2), 0.5*rect.bottom + (cyChar*-2), szBuffer, l);
							 TextOut(TempBGHdc, 0.34*rect.right - ((lstrlen(L"Press Enter to continue...") *cxChart) / 2), 0.5*rect.bottom + (cyChar * 0), L"Press Enter to continue...", lstrlen(L"Press Enter to continue..."));
						 }
						 if (GameMode == TWO_PLAYER_PLAY)
						 {
							 TextOut(TempBGHdc, 0.34*rect.right - ((lstrlen(L"The Game was of Two players")*cxChar) / 2), 0.5*rect.bottom + (cyChar*-6), L"The Game was of Two players", lstrlen(L"The Game was of Two players"));
							 int l = wsprintf(szBuffer, L"  you have scored %d points", player1.score);
							 SelectObject(TempBGHdc, hFontt);
							 TextOut(TempBGHdc, 0.34*rect.right - (((lstrlen(szFirstPlayerName) + l)*cxChart) / 2), 0.5*rect.bottom + (cyChar*-4), szFirstPlayerName, lstrlen(szFirstPlayerName));
							 TextOut(TempBGHdc, 0.34*rect.right - (((l - lstrlen(szFirstPlayerName))*cxChart) / 2), 0.5*rect.bottom + (cyChar*-4), szBuffer, l);
							 l = wsprintf(szBuffer, L"By taking %d chances", MaxPlay/2);
							 TextOut(TempBGHdc, 0.34*rect.right - ((l*cxChart) / 2), 0.5*rect.bottom + (cyChar*-3), szBuffer, l);
							 int percentage = (((float)player1.score) / ((float)MaxPlay/2)) * 100;
							 l = wsprintf(szBuffer, L"Your scuccess percentage is %d %%", percentage);
							 TextOut(TempBGHdc, 0.34*rect.right - ((l*cxChart) / 2), 0.5*rect.bottom + (cyChar*-2), szBuffer, l);
							 l = wsprintf(szBuffer, L"   you have scored %d points", player2.score);
							 TextOut(TempBGHdc, 0.34*rect.right - (((lstrlen(szSecondPlayerName) + l)*cxChart) / 2), 0.5*rect.bottom + (cyChar * 0), szSecondPlayerName, lstrlen(szSecondPlayerName));
							 TextOut(TempBGHdc, 0.34*rect.right - (((l - lstrlen(szSecondPlayerName))*cxChart) / 2), 0.5*rect.bottom + (cyChar * 0), szBuffer, l);
							 l = wsprintf(szBuffer, L"By taking %d chances", MaxPlay / 2);
							 TextOut(TempBGHdc, 0.34*rect.right - ((l*cxChart) / 2), 0.5*rect.bottom + (cyChar * 1), szBuffer, l);
							 percentage = (((float)player2.score) / ((float)MaxPlay / 2)) * 100;
							 l = wsprintf(szBuffer, L"Your scuccess percentage is %d %%", percentage);
							 TextOut(TempBGHdc, 0.34*rect.right - ((l*cxChart) / 2), 0.5*rect.bottom + (cyChar * 2), szBuffer, l);
							 TextOut(TempBGHdc, 0.34*rect.right - ((lstrlen(L"By seeing the scores of course")*cxChart) / 2), 0.5*rect.bottom + (cyChar * 4), L"By seeing the scores ofcourse", lstrlen(L"By seeing the scores ofcourse"));
							 if (player1.score > player2.score)
							 {
								 TextOut(TempBGHdc, 0.34*rect.right - (((lstrlen(szFirstPlayerName) + lstrlen(L"   you have won"))*cxChart) / 2), 0.5*rect.bottom + (cyChar * 5), szFirstPlayerName, lstrlen(szFirstPlayerName));
								 TextOut(TempBGHdc, 0.34*rect.right - (((lstrlen(L"   you have won") - lstrlen(szFirstPlayerName))*cxChart) / 2), 0.5*rect.bottom + (cyChar * 5), L"   you have won", lstrlen(L"   you have won"));
							 }
							 else  if (player1.score < player2.score)
							 {
								 TextOut(TempBGHdc, 0.34*rect.right - (((lstrlen(szSecondPlayerName) + lstrlen(L"   you have won"))*cxChart) / 2), 0.5*rect.bottom + (cyChar * 5), szSecondPlayerName, lstrlen(szSecondPlayerName));
								 TextOut(TempBGHdc, 0.34*rect.right - (((lstrlen(L"   you have won") - lstrlen(szSecondPlayerName))*cxChart) / 2), 0.5*rect.bottom + (cyChar * 5), L"   you have won", lstrlen(L"   you have won"));
							 }
							 else
								 TextOut(TempBGHdc, 0.34*rect.right - ((lstrlen(L"The game is drawn") *cxChart) / 2), 0.5*rect.bottom + (cyChar * 5), L"The game is drawn", lstrlen(L"The game is drawn"));
							 TextOut(TempBGHdc, 0.34*rect.right - ((lstrlen(L"Press Enter to continue...") *cxChart) / 2), 0.5*rect.bottom + (cyChar * 7), L"Press Enter to continue...", lstrlen(L"Press Enter to continue..."));
						 }
					 }
					 if (iScreen == SCREEN_INITIAL)
					 {	 
							 Bitmap BgImg(L"DATA/Images/pattern-orange-blue-sky-background-patterns-pattern-wallpapers.jpg");
							 graphics.DrawImage(&BgImg, 0, 0, rect.right, rect.bottom);
							 Bitmap Logo(L"DATA/Images/Ash.png");
							 graphics.DrawImage(&Logo, 0, 0, rect.right, 150);
							 //For Bar
							 Bitmap Bar(L"DATA/Images/Bar.png");
							 graphics.DrawImage(
								 &Bar,
								 Rect(0.5*rect.right - 220, 0.5*rect.bottom - 200, 40, 400),  // Destination rectangle
								 0,                             // Source rectangle X 
								 0,                             // Source rectangle Y
								 40,                        // Source rectangle width
								 400,                       // Source rectangle height
								 UnitPixel,
								 &imageAtt);
						 //For New game
						 if ((MousePosition.x <= (450 + ((0.5*rect.right) - 275))) && (MousePosition.x >= ((0.5*rect.right) - 275)) && (MousePosition.y <= (60 + ((0.5*rect.bottom) - (30 + 110/*Change this value to go up and down*/)))) && (MousePosition.y >= ((0.5*rect.bottom) - (30 + 110/*Change this value to go up and down*/))))
						 {
							
								 
							 iMenuSound2 = 1;
							 Bitmap Button1(L"DATA/Images/Button1.png");
							 graphics.DrawImage(&Button1, 0.5*rect.right - 275, 0.5*rect.bottom - (30 + 110/*Change this value to go up and down*/), 450, 60);
						 }
						 else
						 {
							 
							 Bitmap Button1(L"DATA/Images/Button2.png");
							 graphics.DrawImage(
								 &Button1,
								 Rect(0.5*rect.right - 275, 0.5*rect.bottom - (30+110/*Change this value to go up and down*/), 450, 60),  // Destination rectangle
								 0,                             // Source rectangle X 
								 0,                             // Source rectangle Y
								 450,                        // Source rectangle width
								 60,                       // Source rectangle height
								 UnitPixel,
								 &imageAtt);
						 }
						 //For Options
						 if ((MousePosition.x <= (450 + ((0.5*rect.right) - 275))) && (MousePosition.x >= ((0.5*rect.right) - 275)) && (MousePosition.y <= (60 + ((0.5*rect.bottom) - (30+40/*Change this value to go up and down*/)))) && (MousePosition.y >= ((0.5*rect.bottom) - (30 + 40/*Change this value to go up and down*/))))
						 {
							 iMenuSound2 = 2;
							 Bitmap Button1(L"DATA/Images/Button_Options1.png");
							 graphics.DrawImage(&Button1, 0.5*rect.right - 275, 0.5*rect.bottom - (30 + 40/*Change this value to go up and down*/), 450, 60);
						 }
						 else
						 {
							 
							 Bitmap Button1(L"DATA/Images/Button_Options2.png");
							 graphics.DrawImage(
								 &Button1,
								 Rect(0.5*rect.right - 275, 0.5*rect.bottom - (30 + 40/*Change this value to go up and down*/), 450, 60),  // Destination rectangle
								 0,                             // Source rectangle X 
								 0,                             // Source rectangle Y
								 450,                        // Source rectangle width
								 60,                       // Source rectangle height
								 UnitPixel,
								 &imageAtt);
						 }
						 //For Help
						 if ((MousePosition.x <= (450 + ((0.5*rect.right) - 275))) && (MousePosition.x >= ((0.5*rect.right) - 275)) && (MousePosition.y <= (60 + ((0.5*rect.bottom) - (30 - 30/*Change this value to go up and down*/)))) && (MousePosition.y >= ((0.5*rect.bottom) - (30 - 30/*Change this value to go up and down*/))))
						 {
							 iMenuSound2 = 3;
							 Bitmap Button1(L"DATA/Images/Button_Help1.png");
							 graphics.DrawImage(&Button1, 0.5*rect.right - 275, 0.5*rect.bottom - (30 - 30/*Change this value to go up and down*/), 450, 60);
						 }
						 else
						 {
							
							 Bitmap Button1(L"DATA/Images/Button_Help2.png");
							 graphics.DrawImage(
								 &Button1,
								 Rect(0.5*rect.right - 275, 0.5*rect.bottom - (30 -30/*Change this value to go up and down*/), 450, 60),  // Destination rectangle
								 0,                             // Source rectangle X 
								 0,                             // Source rectangle Y
								 450,                        // Source rectangle width
								 60,                       // Source rectangle height
								 UnitPixel,
								 &imageAtt);
						 }
						 //For Exit
						 if ((MousePosition.x <= (450 + ((0.5*rect.right) - 275))) && (MousePosition.x >= ((0.5*rect.right) - 275)) && (MousePosition.y <= (60 + ((0.5*rect.bottom) - (30 - 100/*Change this value to go up and down*/)))) && (MousePosition.y >= ((0.5*rect.bottom) - (30 - 100/*Change this value to go up and down*/))))
						 {
							 iMenuSound2 = 4;
							 Bitmap Button1(L"DATA/Images/Button_Exit1.png");
							 graphics.DrawImage(&Button1, 0.5*rect.right - 275, 0.5*rect.bottom - (30 - 100/*Change this value to go up and down*/), 450, 60);
						 }
						 else
						 {

						
							 Bitmap Button1(L"DATA/Images/Button_Exit2.png");
							 graphics.DrawImage(
								 &Button1,
								 Rect(0.5*rect.right - 275, 0.5*rect.bottom - (30 - 100/*Change this value to go up and down*/), 450, 60),  // Destination rectangle
								 0,                             // Source rectangle X 
								 0,                             // Source rectangle Y
								 450,                        // Source rectangle width
								 60,                       // Source rectangle height
								 UnitPixel,
								 &imageAtt);
						 }
						 
						 if (DebugMode == TRUE)
						 {
							 int mp = wsprintf(szBuffer, L"Mouse X %d Mouse Y %d Menu %d", MousePosition.x, MousePosition.y, iMenuSound2);
							 TextOut(TempBGHdc, 0, 0, szBuffer, mp);
						 }
					 }
					 if (iScreen == SCREEN_OPTIONS)
					 {
						 SelectObject(TempBGHdc, hFont);
						 SetTextColor(TempBGHdc, RGB(40, 157, 218));
						 Bitmap BgImg(L"DATA/Images/wallpaper_abstract_pattern_widescreen_hd_wallpaper.jpg");
						 graphics.DrawImage(&BgImg, 0, 0, rect.right, rect.bottom);
						 TextOut(TempBGHdc, 0.5*rect.right - ((lstrlen(L"Options")*cxChart) / 2), 0.5*rect.bottom + (cyChar * -8), L"Options", lstrlen(L"Options"));
						 if (MousePosition.InFocus == FOCUS_SOUNDS)
						 {
							 SelectObject(TempBGHdc, hFontu);
							 SetTextColor(TempBGHdc, RGB(130, 97, 142));
						 }
						 else
						 {
							 SelectObject(TempBGHdc, hFont);
							 SetTextColor(TempBGHdc, RGB(40, 157, 218));
						 }
						 TextOut(TempBGHdc, 0.2*rect.right - ( (lstrlen(L"Sounds")*cxChart) / 2), 0.5*rect.bottom + (cyChar * -5), L"Sounds", lstrlen(L"Sounds"));
						 if (MousePosition.InFocus == FOCUS_THEMES)
						 {
							 SelectObject(TempBGHdc, hFontu);
							 SetTextColor(TempBGHdc, RGB(130, 97, 142));
						 }
						 else
						 {
							 SelectObject(TempBGHdc, hFont);
							 SetTextColor(TempBGHdc, RGB(40, 157, 218));
						 }
						 TextOut(TempBGHdc, 0.5*rect.right - ((lstrlen(L"Themes")*cxChart) / 2), 0.5*rect.bottom + (cyChar * -5), L"Themes", lstrlen(L"Themes"));
						 if (MousePosition.InFocus == FOCUS_UPDATES)
						 {
							 SelectObject(TempBGHdc, hFontu);
							 SetTextColor(TempBGHdc, RGB(130, 97, 142));
						 }
						 else
						 {
							 SelectObject(TempBGHdc, hFont);
							 SetTextColor(TempBGHdc, RGB(40, 157, 218));
						 }
						 TextOut(TempBGHdc, 0.8*rect.right - ((lstrlen(L"Updates")*cxChart) / 2), 0.5*rect.bottom + (cyChar * -5), L"Updates", lstrlen(L"Updates"));
						 iDisplayCode = OPTIONS_SOUNDS;
						 if (iDisplayCode == OPTIONS_SOUNDS)
						 {
							 TextOut(TempBGHdc, 0.5*rect.right - ((lstrlen(L"Background Music")*cxChart) / 2), 0.5*rect.bottom + (cyChar * -1), L"Background Music", lstrlen(L"Background Music"));
							 Pen blackpen(Color(255, 38, 115, 197), 3);
							 graphics.DrawLine(&blackpen, (int)(0.5*rect.right) - 100, 0.5*rect.bottom + (cyChar * 1), (int)(0.5*rect.right) + 142, 0.5*rect.bottom + (cyChar * 1));
							 TextOut(TempBGHdc, 0.5*rect.right - ((lstrlen(L"FX Music")*cxChart) / 2), 0.5*rect.bottom + (cyChar * 3), L"FX Music", lstrlen(L"FX Music"));
							 Bitmap Volume_Bar(L"DATA/Images/Bar_Volume.png" );
							 graphics.DrawImage(&Volume_Bar, (0.5*(double)rect.right) + iVolumeLevel, 0.5*rect.bottom + (cyChar * 0.7), 22, 22);
							 graphics.DrawLine(&blackpen, (int)(0.5*(double)rect.right) - 100, 0.5*rect.bottom + (cyChar * 5), (int)(0.5*rect.right) + 142, 0.5*rect.bottom + (cyChar * 5));
							 graphics.DrawImage(&Volume_Bar, (0.5*(double)rect.right) + iFXLevel, 0.5*rect.bottom + (cyChar * 4.7), 22, 22);
							 TextOut(TempBGHdc, 0.7*rect.right - ((lstrlen(L"Go Back")*cxChar )/ 2), 0.5*rect.bottom + (cyChar * 6), L"Go Back", lstrlen(L"Go Back"));
							 TCHAR kl[100];
							 TextOut(TempBGHdc, 0, 0, kl, wsprintf(kl, L"FXLevel %d Volume %d", iVolumeLevel, fVolumeLevel));

						 }	
					 }
					 BitBlt(hdc, 0, 0, rect.right - rect.left, rect.bottom - rect.top, TempBGHdc, 0, 0, SRCCOPY);
					 ReleaseDC(hWnd, TempBGHdc); DeleteObject(TempBGBitmap);
					 EndPaint(hWnd, &ps);
	}break;
	case WM_SIZE:
		GetWindowRect(hWnd, &rect);
		if (rect.bottom-rect.top < 687)
			MoveWindow(hWnd, rect.left, rect.top, rect.right-rect.left, 687, TRUE);
		if (rect.right-rect.left<1016)
			MoveWindow(hWnd, rect.left, rect.top, 1016, rect.bottom-rect.top, TRUE);
		GetClientRect(hWnd, &rect);
		InvalidateRect(hWnd, &rect, TRUE);
		hdc = GetDC(hWnd);
		TempBGHdc = CreateCompatibleDC(hdc);
		TempBGBitmap = CreateCompatibleBitmap(hdc, rect.right - rect.left, rect.bottom - rect.top);
		SelectObject(TempBGHdc, TempBGBitmap);
		break;
	case WM_CLOSE:
	BASS_ChannelPlay(
			quit,
			TRUE
			);
		if (MessageBox(hWnd, L"Are you sure you want to quit", L"Confirmation!", MB_OKCANCEL | MB_ICONEXCLAMATION) == IDOK)
			DestroyWindow(hWnd); break;
	case WM_DESTROY:
		PostQuitMessage(0);
		break;
	default:
		return DefWindowProc(hWnd, message, wParam, lParam);
	}
	return 0;
}
/* \fn About(HWND hDlg, UINT message, WPARAM wParam, LPARAM lParam)
Message handler for about box.
*/
INT_PTR CALLBACK About(HWND hDlg, UINT message, WPARAM wParam, LPARAM lParam)
{
	UNREFERENCED_PARAMETER(lParam);
	switch (message)
	{
	case WM_INITDIALOG:
		return (INT_PTR)TRUE;

	case WM_COMMAND:
		if (LOWORD(wParam) == IDOK || LOWORD(wParam) == IDCANCEL)
		{
			EndDialog(hDlg, LOWORD(wParam));
			return (INT_PTR)TRUE;
		}
		break;
	}
	return (INT_PTR)FALSE;
}
/* \fn NewGame(HWND hNwGm, UINT message, WPARAM wParam, LPARAM lParam)
Message handler for new game dialog box.
*/
INT_PTR CALLBACK NewGame(HWND hNwGm, UINT message, WPARAM wParam, LPARAM lParam)
{
	int wmId, wmEvent;
	switch (message)
	{
		SortedData.TotalEffectiveFilms = 0;
	case WM_INITDIALOG:
		
		/*szFirstPlayerName[0] = '\0'; szSecondPlayerName[0] = '\0';*/
		SendDlgItemMessage(hNwGm, IDC_SPIN1, UDM_SETBUDDY, IDC_MAXFILMS, 0);
		SendDlgItemMessage(hNwGm, IDC_SPIN1, UDM_SETRANGE, 0, MAKELPARAM(total_films/2, 1));
		SetDlgItemInt(hNwGm, IDC_MAXFILMS, 2,TRUE);
		SetDlgItemInt(hNwGm, IDC_STATIC5, total_films, TRUE);
		return (INT_PTR)TRUE;
	case WM_COMMAND:
	{
					   
		 wmId = LOWORD(wParam);
		 wmEvent = HIWORD(wParam);
		 switch (wmId)
		 {
		 case IDCANCEL:
			 IsDialogOk = FALSE;
			 EndDialog(hNwGm, wmId);
			 return (INT_PTR)TRUE;
			 break;
		 case IDC_ONEPLAYER:
			 EnableWindow(GetDlgItem(hNwGm, IDC_STATIC1), TRUE);
			 EnableWindow(GetDlgItem(hNwGm, IDC_FIRSTPLAYERNAME),TRUE);
			 EnableWindow(GetDlgItem(hNwGm, IDC_STATIC2), FALSE);
			 EnableWindow(GetDlgItem(hNwGm, IDC_SECONDPLAYERNAME), FALSE);
			 if (!IsWindowEnabled(GetDlgItem(hNwGm, IDC_SECONDPLAYERNAME)))
			 {
				 if (GetWindowTextLength(GetDlgItem(hNwGm, IDC_FIRSTPLAYERNAME)) > 0)
				 {
					 EnableWindow(GetDlgItem(hNwGm, IDC_STATIC3), TRUE);
					 EnableWindow(GetDlgItem(hNwGm, IDC_MAXFILMS), TRUE);
					 EnableWindow(GetDlgItem(hNwGm, IDC_SPIN1), TRUE);
					 EnableWindow(GetDlgItem(hNwGm, IDC_STATIC5), TRUE);
					 EnableWindow(GetDlgItem(hNwGm, IDC_STATIC4), TRUE);
				 }
				 else
				 {
					 EnableWindow(GetDlgItem(hNwGm, IDC_STATIC3), FALSE);
					 EnableWindow(GetDlgItem(hNwGm, IDC_MAXFILMS), FALSE);
					 EnableWindow(GetDlgItem(hNwGm, IDC_SPIN1), FALSE);
					 EnableWindow(GetDlgItem(hNwGm, IDC_STATIC5), FALSE);
					 EnableWindow(GetDlgItem(hNwGm, IDC_STATIC4), FALSE);
				 }
			 }
				 if (IsWindowEnabled(GetDlgItem(hNwGm, IDC_MAXFILMS)))
					 EnableWindow(GetDlgItem(hNwGm, IDOK), TRUE);
				 else
					 EnableWindow(GetDlgItem(hNwGm, IDOK), FALSE);
				 return (INT_PTR)TRUE;
			 break;
		 case IDC_TWOPLAYER:
			 EnableWindow(GetDlgItem(hNwGm, IDC_STATIC1), TRUE);
			 EnableWindow(GetDlgItem(hNwGm, IDC_FIRSTPLAYERNAME), TRUE);
			 EnableWindow(GetDlgItem(hNwGm, IDC_STATIC2), TRUE);
			 EnableWindow(GetDlgItem(hNwGm, IDC_SECONDPLAYERNAME), TRUE);
			 if (GetWindowTextLength(GetDlgItem(hNwGm, IDC_SECONDPLAYERNAME)) == 0)
			 {
				 EnableWindow(GetDlgItem(hNwGm, IDC_STATIC3), FALSE);
				 EnableWindow(GetDlgItem(hNwGm, IDC_MAXFILMS), FALSE);
				 EnableWindow(GetDlgItem(hNwGm, IDC_SPIN1), FALSE);
				 EnableWindow(GetDlgItem(hNwGm, IDC_STATIC5), FALSE);
				 EnableWindow(GetDlgItem(hNwGm, IDC_STATIC4), FALSE);
			 }
			 if (IsWindowEnabled(GetDlgItem(hNwGm, IDC_MAXFILMS)))
				 EnableWindow(GetDlgItem(hNwGm, IDOK), TRUE);
			 else
				 EnableWindow(GetDlgItem(hNwGm, IDOK), FALSE);
			 return (INT_PTR)TRUE;
			 break;
		 case IDOK:
			 if ((GetDlgItemInt(hNwGm, IDC_MAXFILMS, FALSE, TRUE) % 2 == 0) && (GetDlgItemInt(hNwGm, IDC_MAXFILMS, FALSE, TRUE) <= (SortedData.SortData == FALSE ? total_films : SortedData.TotalEffectiveFilms)))
			 {
				 GetWindowText(GetDlgItem(hNwGm, IDC_FIRSTPLAYERNAME), szFirstPlayerName, GetWindowTextLength(GetDlgItem(hNwGm, IDC_FIRSTPLAYERNAME)) + 1);
				 GameMode = ONE_PLAYER_PLAY;
				 MaxPlay=GetDlgItemInt(hNwGm, IDC_MAXFILMS, FALSE, TRUE);
				 if (IsWindowEnabled(GetDlgItem(hNwGm, IDC_SECONDPLAYERNAME)))
				 {
					 GetWindowText(GetDlgItem(hNwGm, IDC_SECONDPLAYERNAME), szSecondPlayerName, GetWindowTextLength(GetDlgItem(hNwGm, IDC_SECONDPLAYERNAME)) + 1);
					 GameMode = TWO_PLAYER_PLAY;
				 }
				 IsDialogOk = TRUE;
				 EndDialog(hNwGm, wmId);
			 }
			 else if (GetDlgItemInt(hNwGm, IDC_MAXFILMS, FALSE, TRUE) > (SortedData.SortData==FALSE?total_films:SortedData.TotalEffectiveFilms))
			 {
				 TCHAR szBuffer[40];
				 wsprintf(szBuffer, L"Please Enter Max Films less than %d", SortedData.SortData==FALSE?total_films:SortedData.TotalEffectiveFilms);
				 MessageBox(hNwGm, szBuffer, L"It's necessary", MB_OK | MB_ICONINFORMATION);
			 }
			 else
				 MessageBox(hNwGm, L"Please enter an even number!", L"It's necessary", MB_OK | MB_ICONINFORMATION);
			 return (INT_PTR)TRUE;
			 break;
		 }
		 if ((IsWindowEnabled(GetDlgItem(hNwGm, IDC_GENRESORT))) && (int)SendMessage(GetDlgItem(hNwGm, IDC_GENRESORT), BM_GETCHECK, 0, 0) != 0)
		 {
			 SortedData.SortData = TRUE;
			 EnableWindow(GetDlgItem(hNwGm, IDC_DRAMA), TRUE);
			 EnableWindow(GetDlgItem(hNwGm, IDC_FAMILY), TRUE);
			 EnableWindow(GetDlgItem(hNwGm, IDC_THRILLER), TRUE);
			 EnableWindow(GetDlgItem(hNwGm, IDC_COMEDY), TRUE);
			 EnableWindow(GetDlgItem(hNwGm, IDC_ACTION), TRUE);
			 EnableWindow(GetDlgItem(hNwGm, IDC_ROMANCE), TRUE);
			 EnableWindow(GetDlgItem(hNwGm, IDC_SOCIAL), TRUE);
			 EnableWindow(GetDlgItem(hNwGm, IDC_SUSPENSE), TRUE);
			 EnableWindow(GetDlgItem(hNwGm, IDC_FANTASY), TRUE);
			 EnableWindow(GetDlgItem(hNwGm, IDC_CHILDREN), TRUE);
			 EnableWindow(GetDlgItem(hNwGm, IDC_ADVENTURE), TRUE);
			 EnableWindow(GetDlgItem(hNwGm, IDC_CRIME), TRUE);
			 EnableWindow(GetDlgItem(hNwGm, IDC_MUSICAL), TRUE);
			 EnableWindow(GetDlgItem(hNwGm, IDC_ANIMATION), TRUE);
			 EnableWindow(GetDlgItem(hNwGm, IDC_ADULT), TRUE);
			 EnableWindow(GetDlgItem(hNwGm, IDC_BIOGRAPHICAL), TRUE);
			 EnableWindow(GetDlgItem(hNwGm, IDC_HISTORICAL), TRUE);
			 EnableWindow(GetDlgItem(hNwGm, IDC_MYTHOLOGY), TRUE);
			 EnableWindow(GetDlgItem(hNwGm, IDC_HORROR), TRUE);
			 EnableWindow(GetDlgItem(hNwGm, IDC_SPORTS), TRUE);
			 EnableWindow(GetDlgItem(hNwGm, IDC_COSTUME), TRUE);
			 EnableWindow(GetDlgItem(hNwGm, IDC_DEVOTIONAL), TRUE);
			 EnableWindow(GetDlgItem(hNwGm, IDC_WAR), TRUE);
			 EnableWindow(GetDlgItem(hNwGm, IDC_PATRIOTIC), TRUE);
			 EnableWindow(GetDlgItem(hNwGm, IDC_SCIENCEFICTION), TRUE);
			 EnableWindow(GetDlgItem(hNwGm, IDC_POLITICAL), TRUE);
			 EnableWindow(GetDlgItem(hNwGm, IDC_PERIOD), TRUE);
			 EnableWindow(GetDlgItem(hNwGm, IDC_BIOPIC), TRUE);
			 EnableWindow(GetDlgItem(hNwGm, IDC_FILMNOIR), TRUE);
			 EnableWindow(GetDlgItem(hNwGm, IDC_UNKNOWN), TRUE);
			 if ((int)SendMessage(GetDlgItem(hNwGm, IDC_ACTION), BM_GETCHECK, 0, 0) != 0)
				 SortedData.Action.IsOsNot = TRUE;
			 else
				 SortedData.Action.IsOsNot = FALSE;

			 if ((int)SendMessage(GetDlgItem(hNwGm, IDC_CHILDREN), BM_GETCHECK, 0, 0) != 0)
				 SortedData.Children.IsOsNot = TRUE;
			 else
				 SortedData.Children.IsOsNot = FALSE;
			 if ((int)SendMessage(GetDlgItem(hNwGm, IDC_COMEDY), BM_GETCHECK, 0, 0) != 0)
				 SortedData.Comedy.IsOsNot = TRUE;
			 else
				 SortedData.Comedy.IsOsNot = FALSE;
			 if ((int)SendMessage(GetDlgItem(hNwGm, IDC_DRAMA), BM_GETCHECK, 0, 0) != 0)
				 SortedData.Drama.IsOsNot = TRUE;
			 else
				 SortedData.Drama.IsOsNot = FALSE;
			 if ((int)SendMessage(GetDlgItem(hNwGm, IDC_FAMILY), BM_GETCHECK, 0, 0) != 0)
				 SortedData.Family.IsOsNot = TRUE;
			 else
				 SortedData.Family.IsOsNot = FALSE;
			 if ((int)SendMessage(GetDlgItem(hNwGm, IDC_FANTASY), BM_GETCHECK, 0, 0) != 0)
				 SortedData.Fantasy.IsOsNot = TRUE;
			 else
				 SortedData.Fantasy.IsOsNot = FALSE;
			 if ((int)SendMessage(GetDlgItem(hNwGm, IDC_ROMANCE), BM_GETCHECK, 0, 0) != 0)
				 SortedData.Romance.IsOsNot = TRUE;
			 else
				 SortedData.Romance.IsOsNot = FALSE;
			 if ((int)SendMessage(GetDlgItem(hNwGm, IDC_SOCIAL), BM_GETCHECK, 0, 0) != 0)
				 SortedData.Social.IsOsNot = TRUE;
			 else
				 SortedData.Social.IsOsNot = FALSE;
			 if ((int)SendMessage(GetDlgItem(hNwGm, IDC_SUSPENSE), BM_GETCHECK, 0, 0) != 0)
				 SortedData.Suspense.IsOsNot = TRUE;
			 else
				 SortedData.Suspense.IsOsNot = FALSE;
			 if ((int)SendMessage(GetDlgItem(hNwGm, IDC_THRILLER), BM_GETCHECK, 0, 0) != 0)
				 SortedData.Thriller.IsOsNot = TRUE;
			 else
				 SortedData.Thriller.IsOsNot = FALSE;
			 if ((int)SendMessage(GetDlgItem(hNwGm, IDC_ADVENTURE), BM_GETCHECK, 0, 0) != 0)
				 SortedData.Adventure.IsOsNot = TRUE;
			 else
				 SortedData.Adventure.IsOsNot = FALSE;
			 if ((int)SendMessage(GetDlgItem(hNwGm, IDC_CRIME), BM_GETCHECK, 0, 0) != 0)
				 SortedData.Crime.IsOsNot = TRUE;
			 else
				 SortedData.Crime.IsOsNot = FALSE;
			 if ((int)SendMessage(GetDlgItem(hNwGm, IDC_MUSICAL), BM_GETCHECK, 0, 0) != 0)
				 SortedData.Musical.IsOsNot = TRUE;
			 else
				 SortedData.Musical.IsOsNot = FALSE;
			 if ((int)SendMessage(GetDlgItem(hNwGm, IDC_ANIMATION), BM_GETCHECK, 0, 0) != 0)
				 SortedData.Animation.IsOsNot = TRUE;
			 else
				 SortedData.Animation.IsOsNot = FALSE;
			 if ((int)SendMessage(GetDlgItem(hNwGm, IDC_ADULT), BM_GETCHECK, 0, 0) != 0)
				 SortedData.Adult.IsOsNot = TRUE;
			 else
				 SortedData.Adult.IsOsNot = FALSE;
			 if ((int)SendMessage(GetDlgItem(hNwGm, IDC_BIOGRAPHICAL), BM_GETCHECK, 0, 0) != 0)
				 SortedData.Biographical.IsOsNot = TRUE;
			 else
				 SortedData.Biographical.IsOsNot = FALSE;
			 if ((int)SendMessage(GetDlgItem(hNwGm, IDC_HISTORICAL), BM_GETCHECK, 0, 0) != 0)
				 SortedData.Historical.IsOsNot = TRUE;
			 else
				 SortedData.Historical.IsOsNot = FALSE;
			 if ((int)SendMessage(GetDlgItem(hNwGm, IDC_MYTHOLOGY), BM_GETCHECK, 0, 0) != 0)
				 SortedData.Mythology.IsOsNot = TRUE;
			 else
				 SortedData.Mythology.IsOsNot = FALSE;
			 if ((int)SendMessage(GetDlgItem(hNwGm, IDC_HORROR), BM_GETCHECK, 0, 0) != 0)
				 SortedData.Horror.IsOsNot = TRUE;
			 else
				 SortedData.Horror.IsOsNot = FALSE;
			 if ((int)SendMessage(GetDlgItem(hNwGm, IDC_SPORTS), BM_GETCHECK, 0, 0) != 0)
				 SortedData.Sports.IsOsNot = TRUE;
			 else
				 SortedData.Sports.IsOsNot = FALSE;
			 if ((int)SendMessage(GetDlgItem(hNwGm, IDC_COSTUME), BM_GETCHECK, 0, 0) != 0)
				 SortedData.Costume.IsOsNot = TRUE;
			 else
				 SortedData.Costume.IsOsNot = FALSE;
			 if ((int)SendMessage(GetDlgItem(hNwGm, IDC_DEVOTIONAL), BM_GETCHECK, 0, 0) != 0)
				 SortedData.Devotional.IsOsNot = TRUE;
			 else
				 SortedData.Devotional.IsOsNot = FALSE;
			 if ((int)SendMessage(GetDlgItem(hNwGm, IDC_WAR), BM_GETCHECK, 0, 0) != 0)
				 SortedData.War.IsOsNot = TRUE;
			 else
				 SortedData.War.IsOsNot = FALSE;
			 if ((int)SendMessage(GetDlgItem(hNwGm, IDC_PATRIOTIC), BM_GETCHECK, 0, 0) != 0)
				 SortedData.Patriotic.IsOsNot = TRUE;
			 else
				 SortedData.Patriotic.IsOsNot = FALSE;
			 if ((int)SendMessage(GetDlgItem(hNwGm, IDC_SCIENCEFICTION), BM_GETCHECK, 0, 0) != 0)
				 SortedData.Science_Fiction.IsOsNot = TRUE;
			 else
				 SortedData.Science_Fiction.IsOsNot = FALSE;
			 if ((int)SendMessage(GetDlgItem(hNwGm, IDC_POLITICAL), BM_GETCHECK, 0, 0) != 0)
				 SortedData.Political.IsOsNot = TRUE;
			 else
				 SortedData.Political.IsOsNot = FALSE;
			 if ((int)SendMessage(GetDlgItem(hNwGm, IDC_PERIOD), BM_GETCHECK, 0, 0) != 0)
				 SortedData.Period.IsOsNot = TRUE;
			 else
				 SortedData.Period.IsOsNot = FALSE;
			 if ((int)SendMessage(GetDlgItem(hNwGm, IDC_BIOPIC), BM_GETCHECK, 0, 0) != 0)
				 SortedData.Biopic.IsOsNot = TRUE;
			 else
				 SortedData.Biopic.IsOsNot = FALSE;
			 if ((int)SendMessage(GetDlgItem(hNwGm, IDC_FILMNOIR), BM_GETCHECK, 0, 0) != 0)
				 SortedData.Film_Noir.IsOsNot = TRUE;
			 else
				 SortedData.Film_Noir.IsOsNot = FALSE;
			 if ((int)SendMessage(GetDlgItem(hNwGm, IDC_UNKNOWN), BM_GETCHECK, 0, 0) != 0)
				 SortedData.Unknown.IsOsNot = TRUE;
			 else
				 SortedData.Unknown.IsOsNot = FALSE;
			 DataSorter(GENRE_CURRENT_INDEX); 
			 TotalEffectiveFilms();
			 SendDlgItemMessage(hNwGm, IDC_SPIN1, UDM_SETRANGE, 0, MAKELPARAM(SortedData.TotalEffectiveFilms / 2, 1));
			 SetDlgItemInt(hNwGm, IDC_STATIC5, SortedData.TotalEffectiveFilms, TRUE);
			 if (SortedData.TotalEffectiveFilms < 2)
			 {
				 EnableWindow(GetDlgItem(hNwGm, IDC_MAXFILMS), FALSE);
				 EnableWindow(GetDlgItem(hNwGm, IDC_SPIN1), FALSE);
				 EnableWindow(GetDlgItem(hNwGm, IDOK), FALSE);
			 }
			 else
			 {
				 EnableWindow(GetDlgItem(hNwGm, IDC_MAXFILMS), TRUE);
				 EnableWindow(GetDlgItem(hNwGm, IDC_SPIN1), TRUE);
				 EnableWindow(GetDlgItem(hNwGm, IDOK), TRUE);
			 }

		 }
		 else
		 {
			 SortedData.SortData = FALSE;
			 EnableWindow(GetDlgItem(hNwGm, IDC_MAXFILMS), TRUE);
			 EnableWindow(GetDlgItem(hNwGm, IDC_SPIN1), TRUE);
			 EnableWindow(GetDlgItem(hNwGm, IDC_DRAMA), FALSE);
			 EnableWindow(GetDlgItem(hNwGm, IDC_FAMILY), FALSE);
			 EnableWindow(GetDlgItem(hNwGm, IDC_THRILLER), FALSE);
			 EnableWindow(GetDlgItem(hNwGm, IDC_COMEDY), FALSE);
			 EnableWindow(GetDlgItem(hNwGm, IDC_ACTION), FALSE);
			 EnableWindow(GetDlgItem(hNwGm, IDC_ROMANCE), FALSE);
			 EnableWindow(GetDlgItem(hNwGm, IDC_SOCIAL), FALSE);
			 EnableWindow(GetDlgItem(hNwGm, IDC_SUSPENSE), FALSE);
			 EnableWindow(GetDlgItem(hNwGm, IDC_FANTASY), FALSE);
			 EnableWindow(GetDlgItem(hNwGm, IDC_CHILDREN), FALSE);
			 EnableWindow(GetDlgItem(hNwGm, IDC_ADVENTURE), FALSE);
			 EnableWindow(GetDlgItem(hNwGm, IDC_CRIME), FALSE);
			 EnableWindow(GetDlgItem(hNwGm, IDC_MUSICAL), FALSE);
			 EnableWindow(GetDlgItem(hNwGm, IDC_ANIMATION), FALSE);
			 EnableWindow(GetDlgItem(hNwGm, IDC_ADULT), FALSE);
			 EnableWindow(GetDlgItem(hNwGm, IDC_BIOGRAPHICAL), FALSE);
			 EnableWindow(GetDlgItem(hNwGm, IDC_HISTORICAL), FALSE);
			 EnableWindow(GetDlgItem(hNwGm, IDC_MYTHOLOGY), FALSE);
			 EnableWindow(GetDlgItem(hNwGm, IDC_HORROR), FALSE);
			 EnableWindow(GetDlgItem(hNwGm, IDC_SPORTS), FALSE);
			 EnableWindow(GetDlgItem(hNwGm, IDC_COSTUME), FALSE);
			 EnableWindow(GetDlgItem(hNwGm, IDC_DEVOTIONAL), FALSE);
			 EnableWindow(GetDlgItem(hNwGm, IDC_WAR), FALSE);
			 EnableWindow(GetDlgItem(hNwGm, IDC_PATRIOTIC), FALSE);
			 EnableWindow(GetDlgItem(hNwGm, IDC_SCIENCEFICTION), FALSE);
			 EnableWindow(GetDlgItem(hNwGm, IDC_POLITICAL), FALSE);
			 EnableWindow(GetDlgItem(hNwGm, IDC_PERIOD), FALSE);
			 EnableWindow(GetDlgItem(hNwGm, IDC_BIOPIC), FALSE);
			 EnableWindow(GetDlgItem(hNwGm, IDC_FILMNOIR), FALSE);
			 EnableWindow(GetDlgItem(hNwGm, IDC_UNKNOWN), FALSE);
			 SendDlgItemMessage(hNwGm, IDC_SPIN1, UDM_SETRANGE, 0, MAKELPARAM(total_films / 2, 1));
			 SetDlgItemInt(hNwGm, IDC_STATIC5, total_films, TRUE);
			 
		 }
		 
		 switch (wmEvent)
		 {
		 case EN_UPDATE:
			 if (!IsWindowEnabled(GetDlgItem(hNwGm, IDC_SECONDPLAYERNAME)))
			 {
				 int x = GetWindowTextLength(GetDlgItem(hNwGm, IDC_FIRSTPLAYERNAME));
				 if (x > 0)
				 {
					 EnableWindow(GetDlgItem(hNwGm, IDC_STATIC3), TRUE);
					 if (SortedData.SortData == FALSE)
					 {
						 EnableWindow(GetDlgItem(hNwGm, IDC_MAXFILMS), TRUE);
						 EnableWindow(GetDlgItem(hNwGm, IDC_SPIN1), TRUE);
					 }
					 EnableWindow(GetDlgItem(hNwGm, IDC_STATIC5), TRUE);
					 EnableWindow(GetDlgItem(hNwGm, IDC_STATIC4), TRUE);
					 EnableWindow(GetDlgItem(hNwGm, IDC_GENRESORT), TRUE);
				 }
				 else
				 {
					 EnableWindow(GetDlgItem(hNwGm, IDC_STATIC3), FALSE);
					 if (SortedData.SortData == FALSE)
					 {
						 EnableWindow(GetDlgItem(hNwGm, IDC_MAXFILMS), FALSE);
						 EnableWindow(GetDlgItem(hNwGm, IDC_SPIN1), FALSE);
					 }
					 EnableWindow(GetDlgItem(hNwGm, IDC_STATIC5), FALSE);
					 EnableWindow(GetDlgItem(hNwGm, IDC_STATIC4), FALSE);
					 EnableWindow(GetDlgItem(hNwGm, IDC_GENRESORT), FALSE);
				 }
			 }
			 if (IsWindowEnabled(GetDlgItem(hNwGm, IDC_SECONDPLAYERNAME)))
			 {
				 
				 int x = GetWindowTextLength(GetDlgItem(hNwGm, IDC_FIRSTPLAYERNAME));
				 int y = GetWindowTextLength(GetDlgItem(hNwGm, IDC_SECONDPLAYERNAME));
				 if ((x > 0) && (y>0))
				 {
					 EnableWindow(GetDlgItem(hNwGm, IDC_STATIC3), TRUE);
					 if (SortedData.SortData == FALSE)
					 {
						 EnableWindow(GetDlgItem(hNwGm, IDC_MAXFILMS), TRUE);
						 EnableWindow(GetDlgItem(hNwGm, IDC_SPIN1), TRUE);
					 }
					 EnableWindow(GetDlgItem(hNwGm, IDC_STATIC5), TRUE);
					 EnableWindow(GetDlgItem(hNwGm, IDC_STATIC4), TRUE);
					 EnableWindow(GetDlgItem(hNwGm, IDC_GENRESORT), TRUE);
				 }
				 else
				 {
					 EnableWindow(GetDlgItem(hNwGm, IDC_STATIC3), FALSE);
					 if (SortedData.SortData == FALSE)
					 {
						 EnableWindow(GetDlgItem(hNwGm, IDC_MAXFILMS), FALSE);
						 EnableWindow(GetDlgItem(hNwGm, IDC_SPIN1), FALSE);
					 }
					 EnableWindow(GetDlgItem(hNwGm, IDC_STATIC5), FALSE);
					 EnableWindow(GetDlgItem(hNwGm, IDC_STATIC4), FALSE);
					 EnableWindow(GetDlgItem(hNwGm, IDC_GENRESORT), FALSE);
				 }
			 }
			
			 if (IsWindowEnabled(GetDlgItem(hNwGm, IDC_MAXFILMS)))
				 EnableWindow(GetDlgItem(hNwGm, IDOK), TRUE);
			 else
				 EnableWindow(GetDlgItem(hNwGm, IDOK), FALSE);
		 } return (INT_PTR)TRUE; break;

	}
	return (INT_PTR)TRUE; break;
		
		case WM_VSCROLL:
			wmId = LOWORD(wParam);
			wmEvent = HIWORD(wParam);
			switch (wmId)
			{
			case SB_THUMBPOSITION:
				SetDlgItemInt(hNwGm, IDC_MAXFILMS, wmEvent*2, TRUE);
			}
			return (INT_PTR)TRUE;
			break;

	}
	return(INT_PTR)FALSE;
}