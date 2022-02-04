#include "ft_so_long.h"

void	ft_free(char *s)
{
	if (s)
		free(s);
}

int	ft_verif_rect(t_dynarray *darr)
{
	char			**map;
	uint64_t		i;
	int				len;

	i = 1;
	map = (char **)darr->list;
	len = ft_strlen(map[0]);
	while (i < darr->nb_cells)
	{
		if (ft_strlen(map[i]) != len)
			return (printf("map not rectangular"), ft_free_all(darr), -1);
		i++;
	}
	return (0);
}

int	ft_verif_closed_rect(t_dynarray *darr)
{
	char			**map;
	int				i;
	uint64_t		j;

	i = 0;
	j = 1;
	map = (char **)darr->list;
	while (map[0][i])
	{
		if (map[0][i] != '1')
			return (printf("map not closed"), ft_free_all(darr), -1);
		i++;
	}
	i = 0;
	while (j < darr->nb_cells - 1 && map[j][i])
	{
		if (map[j][0] != '1')
			return (printf("map not closed"), ft_free_all(darr), -1);
		while (map[j][i] != '1')
			i++;
		if (map[j][i] != '1')
			return (printf("map not closed"), ft_free_all(darr), -1);
		j++;
		i = 0;
	}
	while (map[j][i])
	{
		if (map[j][i] != '1')
			return (printf("map not closed"), ft_free_all(darr), -1);
		i++;
	}
	return (ft_verif_rect(darr));
}

int	ft_count_obj(char *s, t_mlx_data *data)
{
	int	i;

	i = 0;
	while (s && s[i])
	{
		if (s[i] == 'P')
			data->nb_player++;
		if (s[i] == 'C')
			data->nb_collectibles++;
		if (s[i] == 'E')
			data->nb_exit++;
		i++;
	}
	return (0);
}
