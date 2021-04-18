/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ljs <marvin@42.fr>                         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/27 21:15:04 by ljs               #+#    #+#             */
/*   Updated: 2021/02/27 21:15:12 by ljs              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line_bonus.h"

int				is_newline(char *str)
{
	int			i;

	i = 0;
	while (str[i])
	{
		if (str[i] == '\n')
			return (i);
		i++;
	}
	return (-1);
}

int				split_line(char **backup, int split_index, char **line)
{
	int			remain_len;
	char		*second_str;
	char		*temp_backup;

	(*backup)[split_index] = '\0';
	*line = ft_strdup(*backup);
	second_str = *backup + split_index + 1;
	remain_len = ft_strlen(second_str);
	if (remain_len == 0)
	{
		free(*backup);
		*backup = NULL;
		return (1);
	}
	temp_backup = ft_strdup(second_str);
	free(*backup);
	*backup = temp_backup;
	return (1);
}

int				return_backup(char **backup, char **line)
{
	int			split_index;

	if (*backup)
	{
		split_index = is_newline(*backup);
		if (0 <= split_index)
			return (split_line(backup, split_index, line));
		else
		{
			*line = *backup;
			*backup = NULL;
			return (0);
		}
	}
	else
	{
		*line = ft_strdup("");
		return (0);
	}
}

int				get_next_line(int fd, char **line)
{
	static char *backup[OPEN_MAX];
	char		buffer[BUFFER_SIZE + 1];
	char		*temp;
	int			read_size;
	int			split_index;

	if (fd < 0 || OPEN_MAX < fd || line == NULL || BUFFER_SIZE <= 0)
		return (-1);
	while (0 < (read_size = read(fd, buffer, BUFFER_SIZE)))
	{
		buffer[read_size] = '\0';
		temp = backup[fd];
		backup[fd] = ft_strjoin(backup[fd], buffer);
		free(temp);
		split_index = is_newline(backup[fd]);
		if (0 <= split_index)
			return (split_line(&backup[fd], split_index, line));
	}
	if (read_size < 0)
		return (-1);
	return (return_backup(&backup[fd], line));
}
