#include <stdio.h>

#include <stdlib.h>

#include <time.h>

#include <limits.h>

#define vert 10

#define horiz 7



int main()



{



	int  a, cols,i, j,m,c,x,y,k;

	int **massive1 = NULL;

	int **massive2 = NULL;

	int **massive3 = NULL;

    int glass1;

    int glass2;



	massive1 = (int **)malloc(horiz * sizeof(int *));

	for (i = 0; i < horiz; i++)

	{

		massive1[i] = (int *)malloc(vert * sizeof(int));

	}



	srand(time(NULL));			/* for random */



	printf("\n Make some massives \n\n");



	for (i = 0; i < horiz; i++)

	{

        for (j = 0; j < vert; j++)

		{

			massive1[i][j] = rand() % 10000;



			printf("%d ", massive1[i][j]);

		}

        printf("\n\n");

	}

	printf("This was started Massiv");

	printf("\n\n");



	m=vert/2;



    for(j = 0;j < m;j++)                        /*overturn 1 row*/

     {

        glass1=massive1[0][j];

        massive1[0][j]=massive1[0][vert-1-j];

        massive1[0][vert-1-j]=glass1;



     }

     for(j = 0;j < m;j++)                       /*overturn 2 row*/

     {

        glass2=massive1[6][j];

        massive1[6][j]=massive1[6][vert-1-j];

        massive1[6][vert-1-j]=glass2;



     }

    for(j = 0;j < vert;j++)                        /*change 1 and 6 row*/

    {



        k= massive1[0][j];

        massive1[0][j] = massive1[6][j];

        massive1[6][j] = k;

    }

    for(i=0;i<horiz;i++)

    {

        for(j=0;j<vert;j++)

        {

        printf("%d ", massive1[i][j]);

        }

    printf("\n\n");

    }

    printf("This was changed matrix");

    printf("\n\n");

	for (i = 0; i < horiz; i++)

	{

		for (j = 0; j < vert; j++)

		{

			if (massive1[i][j] < c)

			{

				c = massive1[i][j];

				x = i;

				y = j;

			}

		}

	}



	for (i = 0; i < horiz; i++)

	{

		for (j = 0; j < vert; j++)

		{

			massive1[x][j] = -1;

			massive1[i][y] = -1;

		}

	}

	for (i = 0; i < horiz; i++)

	{

		for (j = 0; j < vert - 1; j++)

		{

			if (massive1[i][j] == -1 && massive1[i][j + 1] != -1)

			{

				a = massive1[i][j];

				massive1[i][j] = massive1[i][j + 1];

				massive1[i][j + 1] = a;

			}

		}

	}



	for (i = 0; i < horiz - 1; i++)

	{

		for (j = 0; j < vert; j++)

		{

			if (massive1[i][j] == -1 && massive1[i + 1][j] != -1)

			{

				a = massive1[i][j];

				massive1[i][j] = massive1[i + 1][j];

				massive1[i + 1][j] = a;

			}

		}

	}



	for (i = 0; i < horiz - 1; i++)

	{

		for (j = 0; j < vert - 1; j++)

		{

			printf("%d  ", massive1[i][j]);

		}

		printf("\n\n");

	}



	printf("Do you're matrix.Type in amount of columns: ");



	scanf("%d", &cols);



	printf("\n%d rows, %d columns", vert - 1, cols);



	massive2 = (int **)malloc((vert - 1) * sizeof(int *));



	for (i = 0; i < (vert - 1); i++)



	{

	massive2[i] = (int *)malloc(cols* sizeof(int));

	}

	massive3 = (int **)malloc((horiz - 1) * sizeof(int *));



  for (i = 0; i < (horiz - 1); i++)

	{

		massive3[i] = (int *)malloc(cols * sizeof(int));

	}



	printf("\n Now start typing the matrix\n");



	for (i = 0; i < vert - 1; i++)

	{

		for (j = 0; j < cols; j++)

		{

			scanf("%d", &massive2[i][j]);

		}

		scanf(",");

	}



	for (i = 0; i < vert - 1; i++)

	{

		for (j = 0; j < cols; j++)

		{

			printf("%d ", massive2[i][j]);

		}

		printf("\n\n");

	}



	printf("\n Multiply two matrixes aboce \n\n");



	for (i = 0; i < (horiz - 1); i++)

	{

		for (j = 0; j < cols; j++)

		{

			massive3[i][j] = 0;



			for (a = 0; a < vert - 1; a++)

			{

				massive3[i][j] += massive1[i][a] * massive2[a][j];

			}

		}

	}



	for (i = 0; i < horiz - 1; i++)

	{

		for (j = 0; j < cols; j++)

		{

			printf("%d ", massive3[i][j]);

		}

		printf("\n\n");

	}

}
