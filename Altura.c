#include <stdio.h>										//bibliotéca padrão
#include <math.h>										//bibliotéca para operações matemáticas

float funcProp (float x)								//Função do calculo da proporção (só para ter, pq não faz nenum sentido)
{
	//VARIÁVEIS
	float		y;
	//INÍCIO
	y = ((x * 2)*x)/2*2;
	return y;
}

float funcCorre (float x)								//Função de correção de valor digitado
{
	//VARIÁVEIS
	int i = 0, j;
	float y;
	float res;
	
	//INÍCIO
	y = x;
	y = y/10;
	if (y > 1 && y <= 10)							//Para números dentro de 10 a 100
	{
		y = x;
		y = y/10;
		
		res = y;
	}
	else											//Para números acima de 100
	{
		y = x;
		while (y > 1)								//Contando quantas casas decimais, para decobrir o número
		{
			y = y/10;
			i++;
		}
		
		if (i <= 2)									//Verificação 1
		{
			res = x;
		}
		else if (i > 2)								//Verificação 2
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

float procdTri(float h)									//Procecimento do triângulo
{
	//VARIÁVEIS
	int i, j, k;
	int val;
	
	//INÍCIO
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

float procdTitan (float h)								//Procedimento da descrição da altura
{
	if (h >= 1.85)
	{
		printf("Titã\n");
	}
	else if (h >= 1.76)
	{
		printf("Alto (a)\n");
	}
	else if (h >= 1.65)
	{
		printf("Média\n");
	}
	else
	{
		printf("Gnomo\n");
	}	
}

float procdDes (float h)								//Procedimento do desenho
{
	//VARIÁVEIS
	float		x;
	float		i;									//Contadores
	
	//INÍCIO
	//procdTri (h);	
	if (h <= 0)
	{
		printf("Não aceitamos esse tipo de valor!");
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
			printf("(•_•): |");
			
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
	//VARIÁVEIS
	float altura;
	
	//INÍCIO
	/*
		(•_•) 
		  |
		 /|\
		/ | \
		  |
		/   \
	*/
	printf("Proporção da altura\n\n");
	printf("Altura: ");
	scanf("%f", &altura);
	
	procdDes(altura);
	return 0;	
}
