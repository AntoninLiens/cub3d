/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   int_map.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aliens <aliens@students.s19.be>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/23 13:35:03 by aliens            #+#    #+#             */
/*   Updated: 2021/02/23 17:57:05 by aliens           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void    get_int_map(t_list *charmap, t_map *map)
{
    int i;
	int j;
	int size;

    i = ft_lstsize(charmap);
	j = -1;
	size = i;
    //printf("%d", i);
    if (!(map->map = (int **)malloc(sizeof(int *) * i)))
        return ;
    while (++j < i)
    {
        map->map[i] = int_line(charmap);
		charmap = charmap->next;
    }
    //printf("%s", charmap->content);
	//printf("%p", charmap->next);
	printf("%d\n", map->map[2][2]);
	printf("coucou\n");
	i = 0;
	while (++i < size)
	{
		j = 0;
		while (map->map[i][++j] != -48)
		{
			printf("%d", map->map[i][j]);
		}
		printf("\n");
	}
}

int     *int_line(t_list *charmap)
{
	int		i;
	char	*str;
    int		*map_line;

	i = ft_strlen(charmap->content) + 1;
	if (!(map_line = (int *)malloc(sizeof(int) * i)))
		return (0);
	str = charmap->content;
	while (--i)
		map_line[i] = (int)str[i] - '0';
	return (map_line);
}