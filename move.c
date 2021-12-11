#include"so_long.h"

void left(t_var *he)
{
	int d;
	int b;


	if (he->s[he->y / 40][he->x / 40 - 1] != '1')
	{
		he->img = mlx_xpm_file_to_image(he->mlx,"xpm/An.xpm",&b, &d);
		mlx_put_image_to_window(he->mlx,he->win,he->img,he->x,he->y);
		he->x = he->x - 40;
		he->img = mlx_xpm_file_to_image(he->mlx,"xpm/left.xpm",&b, &d);
		mlx_put_image_to_window(he->mlx,he->win,he->img,he->x,he->y);
	}
}
void right(t_var *he)
{
	int d;
	int b;


	if (he->s[he->y / 40][he->x / 40 + 1] != '1')
	{
		he->img = mlx_xpm_file_to_image(he->mlx,"xpm/An.xpm",&b, &d);
		mlx_put_image_to_window(he->mlx,he->win,he->img,he->x,he->y);
		he->x = he->x + 40;
		he->img = mlx_xpm_file_to_image(he->mlx,"xpm/right.xpm",&b, &d);
		mlx_put_image_to_window(he->mlx,he->win,he->img,he->x,he->y);
	}
}
void up(t_var *he)
{
	int d;
	int b;


	if (he->s[he->y / 40 + 1][he->x / 40] != '1')
	{
		he->img = mlx_xpm_file_to_image(he->mlx,"xpm/An.xpm",&b, &d);
		mlx_put_image_to_window(he->mlx,he->win,he->img,he->x,he->y);
		he->y = he->y + 40;
		he->img = mlx_xpm_file_to_image(he->mlx,"xpm/right.xpm",&b, &d);
		mlx_put_image_to_window(he->mlx,he->win,he->img,he->x,he->y);
	}
}
void down(t_var *he)
{
	int d;
	int b;


	if (he->s[he->y / 40 - 1][he->x / 40] != '1')
	{
		he->img = mlx_xpm_file_to_image(he->mlx,"xpm/An.xpm",&b, &d);
		mlx_put_image_to_window(he->mlx,he->win,he->img,he->x,he->y);
		he->y = he->y - 40;
		he->img = mlx_xpm_file_to_image(he->mlx,"xpm/right.xpm",&b, &d);
		mlx_put_image_to_window(he->mlx,he->win,he->img,he->x,he->y);
	}
}