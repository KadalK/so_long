/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kapinarc <kapinarc@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/27 19:06:17 by kapinarc          #+#    #+#             */
/*   Updated: 2025/01/27 19:17:54 by kapinarc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

//char	*read_map(char *file)
//{
//	int 	fd;
//	char 	*line;
//	char	*join;
//	char	*tmp;
//
//	tmp = ft_strdup("");
//	fd = open(file, O_RDONLY);
//	if (fd < 0)
//		return (NULL);
//	line = get_next_line(fd);
//	if (!line)
//		return (NULL);
//	while (line)
//	{
//		join = ft_strjoin(tmp, line);
//
//		if (!join)
//			return (NULL);
//		free (tmp);
//		free (line);
//		tmp = ft_strdup(join);
//		if (!tmp)
//			return (NULL);
//		free(join);
//		line = get_next_line(fd);
//	}
//	close(fd);
//	free (line);
//	return (tmp);
//}

int	main(void)
{
	char *lel;

	lel = "putain de ta mere";
	ft_split(lel, ' ');
}