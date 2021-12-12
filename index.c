#include "so_long.h"

int my_kf(int keycode, t_var *he)
{
	if (keycode == 2) // x+
		right(he);
	if (keycode == 1) // y-
		down(he);
	if (keycode == 13) // y+
		up(he);
	if (keycode == 0)
		left(he);
	if (keycode == 53)
	{
		mlx_destroy_window(he->mlx,he->win);
		free(he->s);
		exit(0);
		return (0);
	}
	printcount(he);
	ft_print_m(he);
	return 0;
}
int count_w(char **s)
{
	int i;

	i = 0;
	while(s[i] != NULL)
		i++;
	return i;
}

int red(int keycode,t_var *he)
{
	mlx_destroy_window(he->mlx,he->win);
	free(he->s);
	exit(0);
	return (0);
}
int	main(int ac,char **av)
{
	void *mlx;
	void *img;
	void *jj;
	char **s;
	int i;
	int j;
	t_var he;
	t_res xe;
	s = get_map(av[1]);
	xe.x= ft_strlen(s[0]);
	xe.y= count_w(s);
	mlx = mlx_init();
	he.len = -1;
	he.win = mlx_new_window(mlx,xe.x * 40 ,xe.y * 40,"Window");
	i = 0;
	while (i <= xe.x *40)
	{
		j = 0;
		while (j <= xe.y * 40)
		{
			he.img = mlx_xpm_file_to_image(mlx,"xpm/An.xpm",&he.b, &he.d);
			mlx_put_image_to_window(mlx,he.win,he.img,i,j);
			j += 40;
		}
		i += 40;
	}
	he.s = s;

	he.mlx = mlx;
	he.h = xe.y * 40;
	he.w = xe.x * 40;
	printmap(&he,s);
	he.x = he.px;
	he.y = he.py;
	mlx_hook(he.win,17,0,red,&he);
	mlx_hook(he.win,2,0,my_kf,&he);
	mlx_loop(mlx);
}