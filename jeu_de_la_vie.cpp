#include <iostream>
#include <array>
#include <cstdlib>
#include <ctime>

#define WIDTH 20 //largeur du monde
#define HEIGHT 20 //longueur du monde
#define NBgene 150 //nombre de génération



void annulation_bordures(int M[WIDTH+2][HEIGHT+2])
{for (int j=0; j<WIDTH+2; j++)
	{M[0][j]=0;
	M[j][0]=0;
	M[j][WIDTH+1]=0;
	M[HEIGHT+1][j]=0;
}}

 
void MAJ(int MA[WIDTH+2][HEIGHT+2], int MB[WIDTH+2][HEIGHT+2]) 
{

    for (int i=1; i<WIDTH+1; i++)
		{for (int j=1; j<HEIGHT+1; j++)
			{


				if (MA[i][j]==0 && (MA[i-1][j-1]+MA[i][j-1]+MA[i+1][j-1]+MA[i-1][j]+MA[i+1][j]+MA[i-1][j+1]+MA[i][j+1]+MA[i+1][j+1])==3)
					MB[i][j]=1;

				else if (MA[i][j]==1 && 2<=(MA[i-1][j-1]+MA[i][j-1]+MA[i+1][j-1]+MA[i-1][j]+MA[i+1][j]+MA[i-1][j+1]+MA[i][j+1]+MA[i+1][j+1])&&(MA[i-1][j-1]+MA[i][j-1]+MA[i+1][j-1]+MA[i-1][j]+MA[i+1][j]+MA[i-1][j+1]+MA[i][j+1]+MA[i+1][j+1])<=3 ) 
					MB[i][j]=1;

				else
					MB[i][j]=0;

				}
		
		}
		annulation_bordures(MB);
}

	
void swap(int MA[WIDTH+2][HEIGHT+2], int MB[WIDTH+2][HEIGHT+2])
{
	int res;
	for (int i=1; i<WIDTH+1; i++)
		{for (int j=1; j<HEIGHT+1; j++)
			{
			res=MB[i][j];
			MB[i][j]=MA[i][j];
			MA[i][j]=res;
			}
		}

}


void affiche(int M[WIDTH+2][HEIGHT+2])
{
	for (int i=1; i<WIDTH+1; i++)
		{for (int j=1; j<HEIGHT+1; j++)
			{
			 std::cout << M[i][j] << " ";
			}
		std::cout << "\n";
		}

}


int main()
{std::system("clear");

srand(time(NULL));


//initialisation des matrices
int T1[WIDTH+2][HEIGHT+2];
int T2[WIDTH+2][HEIGHT+2];


//remplissage de T1 en random et T2 en 0 et affichage de T1
for (int i=0; i<WIDTH+2; i++)
	{for (int j=0; j<HEIGHT+2; j++)
		{int rand = std::rand();
		T1[i][j]=rand%2;
		T2[i][j]=0;
		

		std::cout << T1[i][j] << " ";}
	std::cout <<"\n";
	}
std::cout <<"\n "<< "\n";

//annulaion des bordures de T1 
annulation_bordures(T1);

//affichage de T1 après l'annulation des bords
for (int i=0; i<WIDTH+2; i++)
	{for (int j=0; j<HEIGHT+2; j++)
		{

		std::cout << T1[i][j] << " ";}
	std::cout <<"\n";
	}
std::cout <<"\n "<< "\n";


//boucle principale avec NBgene le nombre de génération d'évolution
for (int n = 0; n<NBgene; n++)
{
	std::cout <<"génération " << n << "\n";

	MAJ(T1, T2);
	affiche(T2); 
	swap(T1,T2);
	std::cout << "\n";
}


return 0;

}
