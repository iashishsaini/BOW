#include "resource.h"
#include<fstream>
#include<iostream>
#include<time.h>
#include<CommCtrl.h>
#include <windows.h>
#include <objidl.h>
#include <gdiplus.h>
#include"bass.h"
#include<Shellapi.h>
#pragma comment (lib,"Gdiplus.lib")
using namespace Gdiplus;
// pre-process directives for different in game usages 
#define MAX_LOADSTRING					100
#define CHAR_NOTFOUND					300
#define CHAR_REPEATED					1
#define CHAR_VOWELORSPACE				2
#define GAME_OUTOFLIVES					3
#define	CHAR_FOUND						4
#define ONE_PLAYER_PLAY					5
#define TWO_PLAYER_PLAY					6
#define GAME_OVERFORONEPLAYERPLAY		7
#define	GAME_OVERFORTWOPLAYERPLAY		8
#define GAME_PLAYER1ONETIMEWON			9
#define GAME_PLAYER2ONETIMEWON			10
#define	GAME_PLAYING					11
#define	GAME_PAUSE						12
#define GAME_HALTFORUSERINPUT			13
#define SCREEN_PLAY						14
#define SCREEN_RESULTS					15
#define SCREEN_INITIAL					16
#define PLAYER1							17
#define PLAYER2							18
#define GENRE							19
#define DATE							20
#define GENRE_INDEX						21
#define GENRE_CURRENT_INDEX				22
#define SCREEN_OPTIONS					23
#define OPTIONS_SOUNDS					24
#define OPTIONS_THEMES					25
#define OPTIONS_UPDATES					26
#define FOCUS_SOUNDS					27
#define FOCUS_THEMES					28
#define FOCUS_UPDATES					29
#define BGMusic1						L"DATA/Sounds/Background Music/Stealth Groover.mp3"
#define BGMusic2						L"DATA/Sounds/Background Music/Gonna Start.mp3"
#define BGMusic3						L"DATA/Sounds/Background Music/Firmament.mp3"
#define BGMusic4						L"DATA/Sounds/Background Music/Ice Flow.mp3"
#define BGMusic5						L"DATA/Sounds/Background Music/Ouroboros.mp3"
#define BGMusic6						L"DATA/Sounds/Background Music/Hustle.mp3"
#define BGMusic7						L"DATA/Sounds/Background Music/Matts Blues.mp3"
ULONG_PTR m_gdiplusToken;/**Belong to GDI+*/
HDC PerBGHdc, TempBGHdc;/**Belong to GDI+*/ HBITMAP PerBGBitmap/**Belong to GDI+*/, TempBGBitmap/**Belong to GDI+*/; BOOL one = FALSE;
// Global Variables:
HINSTANCE hInst;								// current instance
TCHAR szTitle[MAX_LOADSTRING] = L"BOW - a film guessing game";					/**Stores the title of the program*/
TCHAR szWindowClass[MAX_LOADSTRING] = L"MainWindowClass";			/**the main window class name*/
HWND StaticTextHandle;									//Handle for static text
const UINT MAX_FILMS = 2000; BOOL IsDialogOk = FALSE;
TCHAR  szBollywood[11] = { L"BOLLYWOOD" } /**Store word which should be cut during game play*/, KeyStrokesSaver[50]/**Save the keystrokes inputed by keyboard during gameplay.*/, szFilmWithBlanks[50]/**Holding for film names having blanks for filling*/, szFirstPlayerName[30]/**Stores Name of the first player.*/, szSecondPlayerName[30]/**Stores the name of second player*/, szFilmNames[MAX_FILMS][50]/**Stores all the films names available.*/, szFilmReleaseDate[MAX_FILMS][10]/**Stores realease date of all the films available.*/, szFilmMainCast[MAX_FILMS][100]/**Stores the main cast of films available.*/, szFilmWikiLinks[MAX_FILMS][100]/**Stores wikipedia links of films if available or NA if not*/, szFilmImdbLinks[MAX_FILMS][100]/**Stores imdb links of films if available or NA if not*/, szFilmGenre[MAX_FILMS][100]/**Stores genre of all available films*/, szFilmDirector[MAX_FILMS][100]/**Stores director of all available films*/;
UINT iMenuSound2 = 0, iMenuSound3 = 0, Invalidat, iDisplayCode/**Stores wheter the game is playing, pause or anything else.*/, iQuotesCode/**Stores which quote to show*/, iBowLifeCounter/**Count keeper for how many lives are over*/, total_films = 0, iFilmNumberChoosen/**Contains film choosen for current game.*/, checker[MAX_FILMS]/**Stores already taken films*/, initiali = 0/**For miscellaneous use*/, GameMode/**Stores wheter the game is Single Play or MultiPlay*/, MaxPlay/**Stores the max gameplays*/, iScreen = SCREEN_INITIAL/**Store the screen state like menu screen, playing screen*/;
GdiplusStartupInput gdiplusStartupInput;/**For GDI+*/ HSTREAM quit/**Quit sound stream*/, uhuh/**uhuh sound stream*/, yeah/**Yeah sound stream*/, hang/**Hang sound stream*/, MenuClick/**MenuClick sound stream*/, BGMusic = NULL/**Background music sound stream sound stream*/; BOOL DebugMode = FALSE/**Debug information should be shown or not.*/, ShowHint = FALSE/**Hint should be shown or not.*/;
int iFXLevel = 120, iVolumeLevel = 120;
double fVolumeLevel = 1.0/**Stores Game volume*/, fFXLevel = 1.0/**Stores Background volume*/;
TCHAR szWrongGuess[7][100] = { L"Bad Guessing",
L"Use your brain not your finger tips"
L"You are not good in guessing",
L"Good luck next time",
L"You have missed it",
L"Oh! come on",
L"Try again you ....",
}/**Contains what should be shown when user guess wrong*/, szCorrectlyGuessedMovie[6][100] = {
	L"You got that",
	L"Well nice guess",
	L"Nice guessing Huhn!",
	L"Well done!",
	L"Hurrayh!",
	L"You have made it"
}/**Contains what should be shown when user guess right*/,
szNotGuessedTheMovie[6][100] = {
	L"Shame on you... Just Kidding",
	L"You are not good in guessing",
	L"Better guess next time",
	L"Oh! you are unable to guess this movie",
	L"Nah! Na! Na! Na! Nah! Looser. Don't take it seriously",
	L"What are you doing! Concentrate"
}/**Contains what should be shown when user is unable to guess movie*/
;
/*! \struct _GameStatus
Use to store in game status;
*/
struct _GameStatus {
	UINT PreviousMessage;/**Stores previously what's the status of the game is it paused, running, completed*/
	UINT CurrentMessage = GAME_PAUSE;/**Stores currently what's the status of the game is it paused, running, completed*/
	UINT TotalChances;
	UINT Lives;/**Stores how many lives are left. For example in //////OOD three lives are left*/
	UINT CurrentChances;
	UINT CurentPlayer = PLAYER1;/**Stores who is the current player*/
}GameStatus /**Working _GameStatus structure object*/;
/*! \struct _score
Use to store score scored and hints available
*/
struct _score
{
	UINT score;
	UINT hints;
}player1/**score and hint storer for player1*/, player2/**score and hint storer for player2*/;
/*! \struct _mousepos
stores mouse position in current window used mainly for menu.
*/
struct _mousepos
{
	UINT x;
	UINT y;
	UINT PreviousX;
	UINT PreviousY;
	BOOL IsMouseDown = FALSE;
	UINT InFocus = FOCUS_SOUNDS;
}MousePosition/**working object of _mousepos*/;
struct _subsortedData
{
	BOOL IsOsNot = FALSE;
	UINT iGenre[MAX_FILMS];
	UINT iNdexNumber = 0;
};
/*! /struct _sorteddata
Stores all the sorted data which will be generated after sorting all data by genres
*/
struct _sorteddata
{
	BOOL SortData = FALSE;
	UINT TotalEffectiveFilms = 0;
	TCHAR GenresTemp[MAX_FILMS][100];
	TCHAR Genres[MAX_FILMS][100];
	TCHAR ReleaseDate[MAX_FILMS][100];
	UINT GenreCurrentIndex[MAX_FILMS];
	UINT ReleaseDateAccordingIndex[MAX_FILMS];
	UINT TotalFilmsAfterSort = 0;
	UINT TotalReleaseDates;
	_subsortedData Drama;
	_subsortedData Family;
	_subsortedData Thriller;
	_subsortedData Comedy;
	_subsortedData Action;
	_subsortedData Romance;
	_subsortedData Social;
	_subsortedData Suspense;
	_subsortedData Fantasy;
	_subsortedData Children;
	_subsortedData Adventure;
	_subsortedData Crime;
	_subsortedData Musical;
	_subsortedData Animation;
	_subsortedData Adult;
	_subsortedData Biographical;
	_subsortedData Historical;
	_subsortedData Mythology;
	_subsortedData Horror;
	_subsortedData Sports;
	_subsortedData Costume;
	_subsortedData War;
	_subsortedData Patriotic;
	_subsortedData Science_Fiction;
	_subsortedData Political;
	_subsortedData Period;
	_subsortedData Biopic;
	_subsortedData Film_Noir;
	_subsortedData Devotional;
	_subsortedData Unknown;
}SortedData/**Working object of _sorteddata*/;
// Forward declarations of functions included in this code module:
ATOM				MyRegisterClass(HINSTANCE hInstance);
BOOL				InitInstance(HINSTANCE, int);
LRESULT CALLBACK	WndProc(HWND, UINT, WPARAM, LPARAM);
INT_PTR CALLBACK	About(HWND, UINT, WPARAM, LPARAM);
INT_PTR CALLBACK	NewGame(HWND, UINT, WPARAM, LPARAM);