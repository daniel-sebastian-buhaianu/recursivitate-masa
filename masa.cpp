#include <fstream>
#include <cstring>
#define LGMAX 103
#define LGALFA 26
using namespace std;
// fisiere intrare/iesire
ifstream fin("masa.in");
ofstream fout("masa.out");
// variabile globale
char s[LGMAX];
int nra[LGALFA], poz;
// functii ajutatoare
void citesteDateIntrare();
int calculeazaMasa();
// functia principala
int main()
{
	citesteDateIntrare();
	fout << calculeazaMasa();
	fout.close();
	return 0;
}
int calculeazaMasa()
{
	int sum, i;
	if (s[poz] == '(')
	{
		sum = 0;
		poz++;
		while (s[poz] != ')')
		{
			sum += calculeazaMasa();
		}
		poz++;
	}
	else
	{
		sum = nra[s[poz]-'A'];
		poz++;
	}
	if (s[poz] >= '1' && s[poz] <= '9')
	{
		sum = sum * (s[poz]-'0');
		poz++;
	}
	return sum;
}
void citesteDateIntrare()
{
	char aux[LGMAX];
	fin >> aux;
	fin.close();
	// incadrez formula intre paranteze 
	strcpy(s, "(");
	strcat(s, aux);
	strcat(s, ")");
	// initializez vector caracteristic
	nra['H'-'A'] = 1;
	nra['C'-'A'] = 12;
	nra['O'-'A'] = 16;
	// initializez pozitia de inceput
	poz = 0;
}
