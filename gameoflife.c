 #include <stdio.h>

char matris[20][20];
char matriss[20][20];

void matrisyerlestirme()
{
	for (int i = 0; i < 20; ++i)
	{
		for (int o = 0; o < 20; ++o)
		{
			matriss[i][o]= '.';
			matris[i][o]='.';
			printf("%c  ", matris[i][o]);
		}
		printf("\n");
	}
}

int matrisdoldurma()
{
	char evethayir;
	int matris1, matris2;

	while(1)
	{
		printf("Do you wanna add live cell ? (y/n)\n");
		scanf(" %c",&evethayir);
		if(evethayir == 'y')
		{
			printf("Write your matrix.(n*n)\n");
			scanf(" %d%d",&matris1,&matris2);
			matris[matris1-1][matris2-1] = '#';
			yenimatris();
		}

		else if (evethayir == 'n')
		{
			return 0;
		}
	}

}

void yenimatris()
{
	for (int i = 0; i < 20; ++i)
	{
		for (int z = 0; z < 20; ++z)
		{
			printf("%c  ",matris[i][z]);
		}
		printf("\n");
	}
}

void sonmatris()
{
	for (int i = 0; i < 20; ++i)
	{
		for (int z = 0; z < 20; ++z)
		{
			printf("%c  ",matriss[i][z]);
		}
		printf("\n");
	}
}


void tarama()
{
	int sayac = 0;
	int sayac2 =0;

	for (int x = 0; x < 20; ++x)
	{
		for (int y = 0; y < 20; ++y)
		{
			if (matris[x][y] == '.')
			{
				if(matris[x-1][y-1] == '#')
				{
					sayac++;
				}
				if(matris[x-1][y] == '#')
				{
					sayac++;
				}
				if(matris[x-1][y+1] == '#')
				{
					sayac++;
				}
				if(matris[x][y-1] == '#')
				{
					sayac++;
				}
				if(matris[x][y+1] == '#')
				{
					sayac++;
				}
				if(matris[x+1][y-1] == '#')
				{
					sayac++;
				}
				if(matris[x+1][y] == '#')
				{
					sayac++;
				}
				if(matris[x+1][y+1] == '#')
				{
					sayac++;
				}
				if(sayac==3)
				{
				matriss[x][y] = '#';
				sayac = 0;
				}
				sayac = 0;
			}

			else if(matris[x][y] == '#')
			{
				if(matris[x-1][y-1] == '#')
				{
					sayac2++;
				}
				if(matris[x-1][y] == '#')
				{
					sayac2++;
				}
				if(matris[x-1][y+1] == '#')
				{
					sayac2++;
				}
				if(matris[x][y-1] == '#')
				{
					sayac2++;
				}
				if(matris[x][y+1] == '#')
				{
					sayac2++;
				}
				if(matris[x+1][y-1] == '#')
				{
					sayac2++;
				}
				if(matris[x+1][y] == '#')
				{
					sayac2++;
				}
				if(matris[x+1][y+1] == '#')
				{
					sayac2++;
				}
				if(sayac2 < 2)
				{
					matriss[x][y] = '.';
					sayac2 = 0;
				}

				if(sayac2>3)
				{
					matriss[x][y] = '.';
					sayac2 = 0;
				}

				if(sayac2 == 2 || sayac2 == 3)
				{
					matriss[x][y] = '#';
					sayac2 = 0;
				}

			}
		}
	}
}
int main(int argc, char const *argv[])
{
	char tus;

	matrisyerlestirme();
	matrisdoldurma();
	printf("Press 'n' to see next step or press 'q' to execute this program.\n");
	do
	{
		tarama();
		scanf(" %c", &tus);
		if(tus == 'n')
		{
			sonmatris();
			printf("Press 'n' to see next step or press 'q' to execute this program.\n");
		}

		else
		{
			return 0;
		}

		for (int i = 0; i < 20; ++i)
		{
			for (int j = 0; j < 20; ++j)
			{
				matris[i][j] = matriss[i][j];
			}
		}
	}
	while(tus != 'q');
}
	