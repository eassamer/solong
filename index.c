#include "so_long.h"

int my_kf(int keycode, t_var *he)
{
	int i,j,w,h,b,d,u,o,x,f;
	void *jj;
	void *kk;
	void *ll;

	if (keycode == 2) // x+
		right(he);
	if (keycode == 1) // y-
		up(he);
	if (keycode == 13) // y+
		down(he);
	if (keycode == 0) //x-
		left(he);
	if (keycode == 53) // exit
	{
		mlx_destroy_window(he->mlx,he->win);
	}
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
int	main(void)
{
	void *mlx;
	void *win;
	void *img;
	void *jj;
	char **s;
	int i ,j,w,h,b,d;
	t_var he;
	t_res xe;
	s = get_map("maps/42.ber");
	xe.x= ft_strlen(s[0]);
	xe.y= count_w(s);
	mlx = mlx_init();
	he.len = 0;
	win = mlx_new_window(mlx,xe.x * 40 ,xe.y * 40,"Window");
	i = 0;
	while (i <= xe.x *40)
	{
		j = 0;
		while (j <= xe.y * 40)
		{
			jj = mlx_xpm_file_to_image(mlx,"xpm/An.xpm",&b, &d);
			mlx_put_image_to_window(mlx,win,jj,i,j);
			j += 40;
		}
		i += 40;
	}
	he.s = s;

	he.mlx = mlx;
	he.win = win;
	he.h = xe.y * 40;
	he.w = xe.x * 40;
	printmap(&he,s);
	he.x = he.px;
	he.y = he.py;
	mlx_hook(win,2,(1L<<0),my_kf,&he);

	mlx_loop(mlx);
}