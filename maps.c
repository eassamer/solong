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
	int d;
	int b;
	void *jj;
	i = 0;
	
	while (s[i])
	{
		j = 0;
		he->x = 0;
		while (s[i][j])
		{
			if (s[i][j] == '1')
			{
				jj = mlx_xpm_file_to_image(he->mlx,"xpm/wall.xpm",&b, &d);
				mlx_put_image_to_window(he->mlx,he->win,jj,he->x,he->y);
			}
			if (s[i][j] == '0')
			{
				jj = mlx_xpm_file_to_image(he->mlx,"xpm/An.xpm",&b, &d);
				mlx_put_image_to_window(he->mlx,he->win,jj,he->x,he->y);
			}
			if (s[i][j] == 'P')
			{
				jj = mlx_xpm_file_to_image(he->mlx,"xpm/right.xpm",&b, &d);
				mlx_put_image_to_window(he->mlx,he->win,jj,he->x,he->y);
				he->px = he->x;
				he->py = he->y;
			}
			if (s[i][j] == 'C')
			{
				jj = mlx_xpm_file_to_image(he->mlx,"xpm/Coll.xpm",&b, &d);
				mlx_put_image_to_window(he->mlx,he->win,jj,he->x,he->y);
				he->len++;
			}
			if (s[i][j] == 'E')
			{
				jj = mlx_xpm_file_to_image(he->mlx,"xpm/Exit.xpm",&b, &d);
				mlx_put_image_to_window(he->mlx,he->win,jj,he->x,he->y);
			}
			if (s[i][j] == '0')
			{
				jj = mlx_xpm_file_to_image(he->mlx,"xpm/An.xpm",&b, &d);
				mlx_put_image_to_window(he->mlx,he->win,jj,he->x,he->y);
			}
			he->x += 40;
			j++;
		}
		he->y += 40;
		i++;
	}
	printf("%d",he->len);
	he->x = 0;
	he->y = 0;
}