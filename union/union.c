/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   union.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nlutsevi <nlutsevi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/04 17:34:40 by nlutsevi          #+#    #+#             */
/*   Updated: 2020/11/12 20:38:54 by nlutsevi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

int 	main(int argc, char **argv)
{
	int i, j;
	int buff[255];

	if (argc == 3)
	{
		i = 0;
		while (i < 255)
			buff[i++] = 0;
		i = 1;
		while (i < 3)
		{
			j = 0;
			while (argv[i][j])
			{
				if (!buff[(unsigned char)argv[i][j]])
				{
					write(1, &argv[i][j], 1);
					buff[(unsigned char)argv[i][j]] = 1;
				}
				j++;
			}
			i++;
		}
	}
	write(1, "\n", 1);
	return (0);
}