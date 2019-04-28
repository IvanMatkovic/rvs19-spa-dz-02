#include "game_of_life.h"
#include <ctime>

bool game_of_life::slucajna_vrijednost()
{
	
	int i =  rand() % (4 - 1 + 1) + 1;
	if (i == 4) {
		return true;
	}
	else {
		return false;
	}
	
}

bool game_of_life::celija_zauzeta(int i, int j)
{
	if (polje[i][j] == '*')
	{
		return true;
	}
	else return false;
}

int game_of_life::how_much_neighbours_alive(int n, int m)
{
	int br = 0;
	if (n == 0 && m == 0) {
		if (polje[n][m + 1] == '*')
		{
			br++;
		}
		if (polje[n + 1][m + 1] == '*')
		{
			br++;
		}
		if (polje[n + 1][m] == '*')
		{
			br++;
		}

	}else if (n == 0 && m == 39)
	{
		if (polje[n][m - 1] == '*')
		{
			br++;
		}
		if (polje[n + 1][m - 1] == '*')
		{
			br++;
		}
		if (polje[n + 1][m] == '*')
		{
			br++;
		}

	}else if (n == 19 && m == 0)
	{
		if (polje[n][m + 1] == '*')
		{
			br++;
		}
		if (polje[n - 1][m + 1] == '*')
		{
			br++;
		}
		if (polje[n - 1][m] == '*')
		{
			br++;
		}

	}else if (n == 19 && m == 39)
	{
		if (polje[n][m - 1] == '*')
		{
			br++;
		}
		if (polje[n - 1][m - 1] == '*')
		{
			br++;
		}
		if (polje[n - 1][m] == '*')
		{
			br++;
		}
	}else if (n == 0 && m > 0 && m < 39) // //
		{
			if (polje[n][m + 1] == '*')
			{
				br++;
			}
			if (polje[n][m - 1] == '*')
			{
				br++;
			}
			if (polje[n + 1][m] == '*')
			{
				br++;
			}
			if (polje[n + 1][m + 1] == '*')
			{
				br++;
			}
			if (polje[n + 1][m - 1] == '*')
			{
				br++;
			}
			

		}else if (n == 19 && m > 0 && m < 39) // //
		{
			if (polje[n][m - 1] == '*')
			{
				br++;
			}
			if (polje[n][m + 1] == '*')
			{
				br++;
			}
			if (polje[n - 1][m] == '*')
			{
				br++;
			}
			if (polje[n - 1][m + 1] == '*')
			{
				br++;
			}
			if (polje[n - 1][m - 1] == '*')
			{
				br++;
			}


		}else if (m == 0 && n > 0 && n < 19) // //
		{
			if (polje[n][m + 1] == '*')
			{
				br++;
			}
			if (polje[n - 1][m] == '*')
			{
				br++;
			}
			if (polje[n + 1][m] == '*')
			{
				br++;
			}
			if (polje[n - 1][m + 1] == '*')
			{
				br++;
			}
			if (polje[n + 1][m + 1] == '*')
			{
				br++;
			}


		}else if (m == 39 && n > 0 && n < 19) // //
		{
			if (polje[n][m - 1] == '*')
			{
				br++;
			}
			if (polje[n + 1][m] == '*')
			{
				br++;
			}
			if (polje[n - 1][m] == '*')
			{
				br++;
			}
			if (polje[n + 1][m - 1] == '*')
			{
				br++;
			}
			if (polje[n - 1][m - 1] == '*')
			{
				br++;
			}


		}else {

		    if (polje[n + 1][m] == '*')
		    {
			br++;
		    }
		    if (polje[n - 1][m] == '*')
		    {
			br++;
		    }
		    if (polje[n][m - 1] == '*')
		    {
			br++;
		    }
		    if (polje[n][m + 1] == '*')
		    {
			br++;
		    }
		    if (polje[n + 1][m + 1] == '*')
		    {
			br++;
		    }
		    if (polje[n + 1][m - 1] == '*')
		    {
			br++;
		    }
		    if (polje[n - 1][m + 1] == '*')
		    {
			br++;
		    }
		    if (polje[n - 1][m - 1] == '*')
		    {
			br++;
		    }

        }

	return br;
}


game_of_life::game_of_life()
{
}

void game_of_life::sljedeca_generacija()
{
	int br = 0;
	for (int n = 0; n < 20; n++) {
		for (int m = 0; m < 40; m++)
		{

			int alive = how_much_neighbours_alive(n, m);
			


			/*br++;
			cout << alive;
			if (br == 40) {
				cout << endl;
				br = 0;
			}*/


			if (polje[n][m] == '*')
			{
				if (alive < 2 || alive > 3)
				{
					polje[n][m] = '-';
				}
			}

			if (polje[n][m] == '-')
			{
				if (alive == 3)
				{
					polje[n][m] = '*';
				}
			}


		}
	}
}

void game_of_life::iscrtaj()
{
	
	if (gamestart)
	{
		game_start();
	}
	gamestart = false;

	for (int n = 0; n < 20; n++){
		for (int m = 0; m < 40; m++)
		{
			cout << polje[n][m];
			
			}
	      cout << endl;
		}
/*	for (int n = 0; n < 20; n++) {
		for (int m = 0; m < 40; m++)
		{
			cout << how_much_neighbours_alive(n,m);

		}
		cout << endl;
	}*/
}

void game_of_life::game_start()
{
	
		for (int n = 0; n < 20; n++)
			for (int m = 0; m < 40; m++)
			{
				if (slucajna_vrijednost())
				{
					polje[n][m] = '*';
				}
				else {
					polje[n][m] = '-';
				}
			}

}

	

