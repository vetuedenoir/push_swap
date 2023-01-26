#include "push_swap.h"
#include "./libft/libft.h"

void permuter(int *a, int *b) {
    int tmp;
    tmp = *a;
    *a = *b;
    *b = tmp;
}

void triRapid(int tab[], int first, int last) {
    int pivot, i, j;
    if(first < last) {
        pivot = first;
        i = first;
        j = last;
        while (i < j) {
            while(tab[i] <= tab[pivot] && i < last)
                i++;
            while(tab[j] > tab[pivot])
                j--;
            if(i < j) {
                permuter(&tab[i], &tab[j]);
            }
        }
        permuter(&tab[pivot], &tab[j]);
        triRapid(tab, first, j - 1);
        triRapid(tab, j + 1, last);
    }
}

void	ft_sort_int_tab(int *tab, int size)
{
	int	swap;
	int	i;

	i = 0;
	while (i < size - 1)
	{	
		if (tab[i] > tab[i + 1])
		{
			swap = tab[i];
			tab[i] = tab[i + 1];
			tab[i + 1] = swap;
			i = 0 - 1;
		}			
		i++;
	}
}

static void	icopy(int *dest, const int *src, int index, int n)
{
	int	i;

	i = 0;
	while (index <= n )
	{
		dest[i] = src[index];
		index++;
		i++;
	}
}

static void	fusion(int *tab, int debut, int milieu, int fin)
{
	t_index index;
	int	*x;
	int	*v;

	index.i = 0;
	index.j = 0;
	index.k = debut;
	x = malloc(sizeof(int) * (milieu - debut + 1));
	v = malloc(sizeof(int) * (fin - milieu));
	if (!x || !v)
		exit(0);
	icopy(x, tab, debut, milieu);
	icopy(v, tab, milieu + 1, fin);
	while (index.i < (milieu - debut + 1) && index.j < (fin - milieu))
	{
		if (x[index.i] <= v[index.j])
			tab[index.k++] = x[index.i++];
		else
			tab[index.k++] = v[index.j++];
	}
	icopy(&tab[index.k], x, index.i, (milieu - debut + 1) - 1);
	icopy(&tab[index.k], v, index.j, (milieu - fin) - 1);
	free(x);
	free(v);
}

void	trifusion(int *tab, int debut, int fin)
{
	int	m;

	m = 0;
	if (debut < fin)
	{
		m = (debut + fin) / 2;
		trifusion(tab, debut, m);
		trifusion(tab, m + 1, fin);

		fusion(tab, debut, m, fin);
	}
}

void	putstab(int *tab, int t)
{
	int	i;

	i = 0;
	while (i < t)
		ft_printf("%d\n", tab[i++]);
}

int	slist(void)
{
	int	fd;
	char	*line;
	int	t;

	t = 0;
	fd = open("./test10000.txt", O_RDONLY);
	while (1)
	{
		line = get_next_line(fd);
		if (!line)
			break ;
		t++;
		free(line);
	}
	close(fd);
	return (t);
}

int	main(int argc, char *argv[])
{
	int   fd;
	int   t;
	int	i;
	int	*tab;
	char *line;

	t = slist();
	i = 0;
	if (t)
	{
		tab = malloc(sizeof(int) * t);
		fd = open("./test10000.txt", O_RDONLY);
		while (i < t)
		{
			line = get_next_line(fd);
			tab[i++] = ft_atoi(line);
			if (!line)
				break ;
			free(line);
		}
		trifusion(tab, 0, t);
		//ft_sort_int_tab(tab, t);
		//triRapid(tab, 0, t);
		putstab(tab, t);
		free(tab);
	}
	return (0);	
}
