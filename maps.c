#include"so_long.h"

char **get_map(char *s)
{
	int fd = open(s,O_RDONLY);
	char *lines;
	char *line;
	int i = 0;
	line = "";
	lines = "";
	while (line)
	{
		line = get_next_line(fd);
		if (line == NULL)
			break;
		lines = ft_strjoin1(lines,line);
	}
	close(fd);
	return (ft_split(lines,'\n'));
}

void printmap(t_var *he, char **s)
{
	int i;
	int j;
	i = 0;
	
	while (s[i])
	{
		j = 0;
		he->x = 0;
		while (s[i][j])
		{
			if (s[i][j] == '1')
			{
				he->img = mlx_xpm_file_to_image(he->mlx,"xpm/wall.xpm",&he->b, &he->d);
				mlx_put_image_to_window(he->mlx,he->win,he->img,he->x,he->y);
			}
			if (s[i][j] == '0')
			{
				he->img = mlx_xpm_file_to_image(he->mlx,"xpm/An.xpm",&he->b, &he->d);
				mlx_put_image_to_window(he->mlx,he->win,he->img,he->x,he->y);
			}
			if (s[i][j] == 'P')
			{
				he->img = mlx_xpm_file_to_image(he->mlx,"xpm/isr.xpm",&he->b, &he->d);
				mlx_put_image_to_window(he->mlx,he->win,he->img,he->x,he->y);
				he->px = he->x;
				he->py = he->y;
			}
			if (s[i][j] == 'C')
			{
				he->img = mlx_xpm_file_to_image(he->mlx,"xpm/Coll.xpm",&he->b, &he->d);
				mlx_put_image_to_window(he->mlx,he->win,he->img,he->x,he->y);
				he->len++;
			}
			if (s[i][j] == 'E')
			{
				he->img = mlx_xpm_file_to_image(he->mlx,"xpm/Exit.xpm",&he->b, &he->d);
				mlx_put_image_to_window(he->mlx,he->win,he->img,he->x,he->y);
			}
			if (s[i][j] == '0')
			{
				he->img = mlx_xpm_file_to_image(he->mlx,"xpm/An.xpm",&he->b, &he->d);
				mlx_put_image_to_window(he->mlx,he->win,he->img,he->x,he->y);
				mlx_destroy_image(he->mlx,he->img);
			}
			if (s[i][j]  == 'N')
			{
				he->img = mlx_xpm_file_to_image(he->mlx,"xpm/trap.xpm",&he->b, &he->d);
				mlx_put_image_to_window(he->mlx,he->win,he->img,he->x,he->y);
				mlx_destroy_image(he->mlx,he->img);
			}
			he->x += 40;
			j++;
		}
		he->y += 40;
		i++;
	}
	he->x = 0;
	he->y = 0;
	printf("%d",he->len);
}

int check_map(char **s,t_res xe)
{
	int i;

	i = 0;
	while (s[0][i])
	{
		if (s[0][i] != '1')
			return (0);
		i++;
	}
	i = 0;
	while (s[xe.y][i])
	{
		if (s[xe.y][i] != '1')
			return (0);
		i++;
	}
	i = 0;
	while (s[i][0])
	{
		if (s[i][0] != '1')
			return (0);
		i++;
	}
	i = 0;
		while (s[i][-1])
	{
		if (s[i][-1] != '1')
			return (0);
		i++;
	}
	return (1);
}