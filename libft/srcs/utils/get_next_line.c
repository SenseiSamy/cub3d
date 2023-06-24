/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: snaji <snaji@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/23 15:54:03 by snaji             #+#    #+#             */
/*   Updated: 2023/05/19 13:03:12 by snaji            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <unistd.h>

#ifndef BUFFER_SIZE
# define BUFFER_SIZE 256
#endif

typedef struct s_line
{
	char			buf[BUFFER_SIZE + 1];
	struct s_line	*next;
}					t_line;

typedef struct s_fd
{
	int			fd;
	char		buf[BUFFER_SIZE + 1];
	struct s_fd	*next;
}	t_fd;

t_fd	*get_fd(int fd, t_fd **list_fd);
void	remove_fd(int fd, t_fd **liste_fd);
void	remove_line_from_buf(t_fd *fd);
void	free_line(t_line **line);
size_t	eol_pos(char *s);
char	*get_next_line(int fd);
char	*build_line(t_line **line, int buf_count);
t_line	*get_line(t_fd *fd, int *buf_count);
t_line	*get_one(t_fd *fd, ssize_t *ret, int *buf_count);
void	remove_all_fds(t_fd **list_fd);

char	*get_next_line(int fd)
{
	static t_fd	*list_fd;
	t_line		*line;
	t_fd		*current_fd;
	int			buf_count;

	if (fd < -1 || BUFFER_SIZE < 0)
		return (NULL);
	if (fd == -1)
		return (remove_all_fds(&list_fd), NULL);
	current_fd = get_fd(fd, &list_fd);
	if (!current_fd)
		return (NULL);
	line = get_line(current_fd, &buf_count);
	if (!line)
		return (free_line(&line), remove_fd(fd, &list_fd), NULL);
	return (build_line(&line, buf_count));
}

char	*build_line(t_line **line, int buf_count)
{
	char	*result;
	t_line	*curr;
	size_t	i;
	size_t	j;

	result = malloc((buf_count * BUFFER_SIZE + 1) * sizeof (*result));
	if (!result)
		return (free_line(line), NULL);
	curr = *line;
	j = 0;
	while (curr)
	{
		i = 0;
		while (curr->buf[i] && curr->buf[i] != '\n')
			result[j++] = curr->buf[i++];
		if (curr->buf[i] == '\n')
			result[j++] = '\n';
		curr = curr->next;
	}
	result[j] = '\0';
	free_line(line);
	return (result);
}

t_line	*get_line(t_fd *fd, int *buf_count)
{
	t_line	*line;
	t_line	*curr;
	ssize_t	ret;
	size_t	i;

	*buf_count = 0;
	ret = -1;
	line = get_one(fd, &ret, buf_count);
	curr = line;
	if (!curr)
		return (NULL);
	while (ret && !eol_pos(curr->buf))
	{
		curr->next = get_one(fd, &ret, buf_count);
		if (!curr->next)
			return (free_line(&line), NULL);
		curr = curr->next;
	}
	i = 0;
	while (curr->buf[++i - 1])
		fd->buf[i - 1] = curr->buf[i - 1];
	remove_line_from_buf(fd);
	if (line->buf[0])
		return (line);
	return (free_line(&line), NULL);
}

t_line	*get_one(t_fd *fd, ssize_t *ret, int *buf_count)
{
	t_line	*line_el;

	*ret = 0;
	line_el = malloc(sizeof (*line_el));
	if (!line_el)
		return (NULL);
	line_el->next = NULL;
	if (*fd->buf)
	{
		while (fd->buf[*ret])
		{
			line_el->buf[*ret] = fd->buf[*ret];
			++*ret;
		}
		remove_line_from_buf(fd);
	}
	else
		*ret = read(fd->fd, line_el->buf, BUFFER_SIZE);
	if (*ret == -1)
		return (free(line_el), NULL);
	line_el->buf[*ret] = '\0';
	++*buf_count;
	return (line_el);
}

void	remove_all_fds(t_fd **list_fd)
{
	while (*list_fd)
		remove_fd((*list_fd)->fd, list_fd);
}
