/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   inter.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nlutsevi <nlutsevi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/04 17:22:52 by nlutsevi          #+#    #+#             */
/*   Updated: 2020/11/12 20:36:02 by nlutsevi         ###   ########.fr       */
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
		i = 2;
		while (i > 0)
		{
			j = 0;
			while (argv[i][j])
			{
				if (i == 2 && !buff[(unsigned char)argv[i][j]])
					buff[(unsigned char)argv[i][j]] = 1;
				else if (i == 1 && buff[(unsigned char)argv[i][j]] == 1)
				{
					write(1, &argv[i][j], 1);
					buff[(unsigned char)argv[i][j]] = 0;
				} 
				j++;
			}
			i--;
		}
	}
	write(1, "\n", 1);
	return (0);
}