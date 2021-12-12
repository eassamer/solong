#include"so_long.h"

void left(t_var *he)
{
	int d;
	int b;

	if (he->s[he->y / 40][he->x / 40 - 1] != '1' && (he->s[he->y / 40][he->x / 40 - 1] != 'E' || he->len < 0))
	{
		he->img = mlx_xpm_file_to_image(he->mlx,"xpm/An.xpm",&b, &d);
		mlx_put_image_to_window(he->mlx,he->win,he->img,he->x,he->y);
		he->x = he->x - 40;
		he->img = mlx_xpm_file_to_image(he->mlx,"xpm/isr.xpm",&b, &d);
		mlx_put_image_to_window(he->mlx,he->win,he->img,he->x,he->y);
		if (he->s[he->y / 40][he->x / 40] == 'C')
			he->len--;
		else if (he->s[he->y / 40][he->x / 40] == 'E' || he->s[he->y / 40][he->x / 40] == 'N')
			exit(0);
	}
	
}

void right(t_var *he)
{
	int d;
	int b;

	
	if (he->s[he->y / 40][he->x / 40 + 1] != '1' && (he->s[he->y / 40][he->x / 40 + 1] != 'E' || he->len < 0))
	{
		he->img = mlx_xpm_file_to_image(he->mlx,"xpm/An.xpm",&b, &d);
		mlx_put_image_to_window(he->mlx,he->win,he->img,he->x,he->y);
		he->x = he->x + 40;
		he->img = mlx_xpm_file_to_image(he->mlx,"xpm/imn.xpm",&b, &d);
		mlx_put_image_to_window(he->mlx,he->win,he->img,he->x,he->y);
		if (he->s[he->y / 40][he->x / 40] == 'C')
			he->len--;
		else if (he->s[he->y / 40][he->x / 40] == 'E' || he->s[he->y / 40][he->x / 40] == 'N')
			exit(0);
	}
}

void down(t_var *he)
{
	int d;
	int b;


	if (he->s[he->y / 40 + 1][he->x / 40] != '1' && (he->s[he->y / 40 + 1][he->x / 40] != 'E' || he->len < 0))
	{
		he->img = mlx_xpm_file_to_image(he->mlx,"xpm/An.xpm",&b, &d);
		mlx_put_image_to_window(he->mlx,he->win,he->img,he->x,he->y);
		he->y = he->y + 40;
		he->img = mlx_xpm_file_to_image(he->mlx,"xpm/ltht.xpm",&b, &d);
		mlx_put_image_to_window(he->mlx,he->win,he->img,he->x,he->y);
		if (he->s[he->y / 40][he->x / 40] == 'C')
			he->len--;
		else if (he->s[he->y / 40][he->x / 40] == 'E' || he->s[he->y / 40][he->x / 40] == 'N')
			exit(0);
	}
}

void up(t_var *he)
{
	int d;
	int b;

	if (he->s[he->y / 40 - 1][he->x / 40] != '1' && (he->s[he->y / 40 - 1][he->x / 40] != 'E' || he->len < 0))
	{
		he->img = mlx_xpm_file_to_image(he->mlx,"xpm/An.xpm",&b, &d);
		mlx_put_image_to_window(he->mlx,he->win,he->img,he->x,he->y);
		he->y = he->y - 40;
		he->img = mlx_xpm_file_to_image(he->mlx,"xpm/fou9.xpm",&b, &d);
		mlx_put_image_to_window(he->mlx,he->win,he->img,he->x,he->y);
		if (he->s[he->y / 40][he->x / 40] == 'C')
			he->len--;
		else if (he->s[he->y / 40][he->x / 40] == 'E' || he->s[he->y / 40][he->x / 40] == 'N')
			exit(0);
	}
}