#include <stdio.h>										//bibliot�ca padr�o
#include <math.h>										//bibliot�ca para opera��es matem�ticas

float funcProp (float x)								//Fun��o do calculo da propor��o (s� para ter, pq n�o faz nenum sentido)
{
	//VARI�VEIS
	float		y;
	//IN�CIO
	y = ((x * 2)*x)/2*2;
	return y;
}

float funcCorre (float x)								//Fun��o de corre��o de valor digitado
{
	//VARI�VEIS
	int i = 0, j;
	float y;
	float res;
	
	//IN�CIO
	y = x;
	y = y/10;
	if (y > 1 && y <= 10)							//Para n�meros dentro de 10 a 100
	{
		y = x;
		y = y/10;
		
		res = y;
	}
	else											//Para n�meros acima de 100
	{
		y = x;
		while (y > 1)								//Contando quantas casas decimais, para decobrir o n�mero
		{
			y = y/10;
			i++;
		}
		
		if (i <= 2)									//Verifica��o 1
		{
			res = x;
		}
		else if (i > 2)								//Verifica��o 2
		{
			y = x;
	
			for (j = i; j > 1; j--)
			{
				y = y/10;
			}
			
			res = y;
		}
	}

	return res;
}

float procdTri(float h)									//Procecimento do tri�ngulo
{
	//VARI�VEIS
	int i, j, k;
	int val;
	
	//IN�CIO
	for (i = 1; i <= h; i++)
	{
		for (j = h; j >= i; j--)
		{
			printf("0");
		}

		for (j = 1; j <= i; j++)
		{
			printf("|");
		}
		
		for (k = 1; k <= i; k++)
		{
			printf("i");
		}
		
		for(j = h; j >= i; j--)
		{
			printf("0");
		}
		
		printf("\n");
	}
}

float procdTitan (float h)								//Procedimento da descri��o da altura
{
	if (h >= 1.85)
	{
		printf("Tit�\n");
	}
	else if (h >= 1.76)
	{
		printf("Alto (a)\n");
	}
	else if (h >= 1.65)
	{
		printf("M�dia\n");
	}
	else
	{
		printf("Gnomo\n");
	}	
}

float procdDes (float h)								//Procedimento do desenho
{
	//VARI�VEIS
	float		x;
	float		i;									//Contadores
	
	//IN�CIO
	//procdTri (h);	
	if (h <= 0)
	{
		printf("N�o aceitamos esse tipo de valor!");
	}
	else
	{
		if (h > 1)
		{
			h = funcCorre (h);
		}
		//printf("%.2f", h);
		
		printf("______\n");
		while (h > 1.00)
		{	
			printf("%.2fm\n\n", h);
			printf("(�_�): |");
			
			x = funcProp (h);
			
			for (i = 1; i <= x; i+=0.05)
			{
				printf("_", i);
				
			}	
			printf("| %.2fm\n\n", h);
			
			procdTitan (h);
			
			printf("______\n");
			
			h = h - 0.05;
			}
	}

}

int main(void)											//Main
{
	//VARI�VEIS
	float altura;
	
	//IN�CIO
	/*
		(�_�) 
		  |
		 /|\
		/ | \
		  |
		/   \
	*/
	printf("Propor��o da altura\n\n");
	printf("Altura: ");
	scanf("%f", &altura);
	
	procdDes(altura);
	return 0;	
}
