#ifndef SO_LONG_H
#define SO_LONG_H
#include"mlx.h"
#include<stdio.h>
#include<fcntl.h>
#include<unistd.h>
#include<stdlib.h>
#define BUFFER_SIZE 1024
typedef struct s_var{
	void *mlx;
	void *win;
	void *img;
	char **s;
	int x;
	int y;
	int h;
	int px;
	int py;
	int w;
}	t_var;

typedef struct s_res
{
	int				x;
	int				y;
}				t_res;

char	*get_next_line(int fd);
char	*ft_change_text(char *text);
char	*ft_just_a_line(char *text);
char	*ft_read(char *text, int fd);
char **get_map(char *s);
int my_kf(int keycode, t_var *he);
char	**ft_split(char const *s, char c);
size_t	ft_strlen(char *str);
char	*ft_strchr(char *s, int c);
char	*ft_strjoin(char *s1, char *s2);
char	*ft_substr(char const	*s, unsigned int start, size_t len);
char	*ft_strjoin1(char *s1, char *s2);
void printmap(t_var *he,char **s);
#endif