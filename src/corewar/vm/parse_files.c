/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_files.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ryabicho <ryabicho@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/09/19 14:41:37 by ryabicho             #+#    #+#             */
/*   Updated: 2015/09/19 14:45:28 by ryabicho         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <unistd.h>
#include <corewar.h>
#include <libft.h>

static void	parse_header(t_champ *champion, int fd)
{
	int			ret;

	ret = read(fd, &champion->header, sizeof(champion->header));
	if (ret == -1)
		exit_error(champion->path, NULL, NULL);
	champion->header.magic = ft_revint32(champion->header.magic);
	if (champion->header.magic != COREWAR_EXEC_MAGIC)
		exit_error(champion->path, "wrong corewar magic number", NULL);
	else if (ret != sizeof(champion->header))
		exit_error(champion->path, "corrupted corewar file header", NULL);
	champion->header.prog_size = ft_revint32(champion->header.prog_size);
}

static void	parse_code(t_champ *champion, int fd)
{
	unsigned int	ret;
	off_t			current;
	off_t			end;

	champion->code = (char *)malloc(sizeof(char) * champion->header.prog_size);
	if (!champion->code)
		exit_error("malloc", NULL, NULL);
	ret = read(fd, champion->code, champion->header.prog_size);
	current = lseek(fd, 0, SEEK_CUR);
	end = lseek(fd, 0, SEEK_END);
	if (ret != champion->header.prog_size || current != end)
		exit_error(champion->path, "code size mismatch with prog_size", NULL);
	if (champion->header.prog_size > CHAMP_MAX_SIZE)
		exit_error(champion->path, "bigger size than CHAMP_MAX_SIZE", NULL);
}

void		parse_files(t_param *params)
{
	int	count;
	int	fd;

	count = 0;
	while (count < params->champs_amount)
	{
		fd = open(params->champs[count].path, O_RDONLY);
		if (fd == -1)
			exit_error(params->champs[count].path, NULL, NULL);
		parse_header(&params->champs[count], fd);
		parse_code(&params->champs[count], fd);
		if (close(fd) == -1)
			exit_error(params->champs[count].path, NULL, NULL);
		count++;
	}
}
