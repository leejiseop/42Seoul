#include <stdio.h>
#include <unistd.h>
#include <fcntl.h>
#include <stdlib.h>

#ifndef OPEN_MAX
# define OPEN_MAX 256
#endif

#ifndef BUFFER_SIZE
# define BUFFER_SIZE 1000
#endif

int					ft_strlen(char *s)
{
	int				i;

	i = 0;
	while (*s++)
		i++;
	return (i);
}

char				*ft_strdup(char *s)
{
	char			*new;
	int				len;
	int				i;

	i = 0;
	len = ft_strlen(s);
	if (!(new = (char *)malloc(sizeof(char) * (len + 1))))
		return (NULL);
	while (s[i])
	{
		new[i] = s[i];
		i++;
	}
	new[i] = '\0';
	return (new);
}

char				*ft_strjoin(char *s1, char *s2)
{
	char			*new;
	int				len;
	int				i;

	if (!s1 && !s2)
		return (NULL);
	if (s1 == NULL)
		return (ft_strdup(s2));
	if (s2 == NULL)
		return (NULL);
	i = 0;
	len = ft_strlen(s1) + ft_strlen(s2);
	if (!(new = (char *)malloc(sizeof(char) * (len + 1))))
		return (NULL);
	while (*s1)
		new[i++] = *s1++;
	while (*s2)
		new[i++] = *s2++;
	new[i] = '\0';
	return (new);
}

int					is_new_line(char *s)
{
	int				i;

	i = 0;
	while (s[i])
	{
		if (s[i] == '\0')
			return (i);
		i++;
	}
	return (-1);
}

int					split_line(char **backup, int split_index, char **line)
{
	char			*next_word;
	char			*temp;
// 앞에거 내보내고 뒤에거 가리킨 다음에
// 길이가 0이면(문자열 끝) 백업 널로
// 아니면 뒤에거 dup 해서 만들어놓고
// 원래거 free하고 새로 dup한거 가리키기
	(*backup)[split_index] = '\0';
	*line = ft_strdup(*backup);
	next_word = *backup + split_index + 1;
	if (ft_strlen(next_word) == 0)
	{
		free(*backup);
		*backup = NULL;
		return (1);
	}
	temp = ft_strdup(next_word);
	free(*backup);
	*backup = temp;
	return (1);
}

int					return_all(char **backup, char **line)
{
	int				split_index;
// 백업에 뭐 있으면
// 공백문자 있나없나
// 있으면 스플릿라인
// 없으면 지금 백업을 라인으로 내보내고 백업은 NULL로
// 백업이 NULL이면 "" dup해서 내보내고 끝
	if (*backup)
	{
		split_index = is_new_line(*backup);
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

int					get_next_line(int fd, char **line)
{
	static char		*backup[OPEN_MAX];
	char			buffer[BUFFER_SIZE + 1];
	char			*temp;
	int				read_size;
	int				split_index;
	
	if (fd < 0 || OPEN_MAX < fd || line == NULL || BUFFER_SIZE <= 0)
		return (-1);
	while(0 < (read_size = read(fd, buffer, BUFFER_SIZE)))
	{
		buffer[read_size] = '\0';
		temp = backup[fd];
		backup[fd] = ft_strjoin(backup[fd], buffer);
		free(temp);
		split_index = is_new_line(backup[fd]);
		if (0 <= split_index)
			return (split_line(&backup[fd], split_index, line));
	}
	if (read_size < 0)
		return (-1);
	return (return_all(&backup[fd], line));
}
