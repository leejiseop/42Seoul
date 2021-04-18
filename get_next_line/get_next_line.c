/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ljs <marvin@42.fr>                         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/27 18:09:05 by ljs               #+#    #+#             */
/*   Updated: 2021/04/03 17:13:17 by ljs              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

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

	if (*backup) // backup이 뭘 가리키고있긴 한데 ()
	{
		split_index = is_newline(*backup); // 공백문자 있나?
		if (0 <= split_index) // fd 끝까지 다 읽었는데 한번에 \n이 여러개 들어와버린 경우
			return (split_line(backup, split_index, line));
		// \n까지 내보내고 1 리턴하고  마무리 (read = 0이면 다 내보낼 때 까지 계속 여기 반복
		else
		{ // 마지막줄 남아있긴 한데 개행문자 없음. 진짜 마지막 줄.
			*line = *backup; // 그거 내보내고
			*backup = NULL; // 정리하고
			return (0); // 끝
		}
	}
	else // backup이 아무것도 안가리키고있음. backup == NULL 예외처리
	{
		*line = ft_strdup(""); 빈문자열 만들어서 리턴
		return (0); // 끝
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
