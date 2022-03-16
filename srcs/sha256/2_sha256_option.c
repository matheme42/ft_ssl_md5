
/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   option.c                                         .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: matheme <matheme@student.le-101.fr>        +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2019/03/06 15:05:20 by matheme      #+#   ##    ##    #+#       */
/*   Updated: 2019/08/28 15:36:57 by matheme     ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "sha256.h"

/*
**  1024 512 256 128  64  32  16   8   4   2   1
**    -   -   -   -    -   -   h   s   r   q   p
**    0   0   0   0    0   0   0   0   0   0   0
**
** Lors d'ajout d'option penser a rajouter l'option dans la liste des options
*/

/*
** permet de desactivé des options par rapport à d'autre option
** pour rajouter une option il suffit de recopier le patern suivant
*/

static int	ft_plugout_option(char c, int option)
{
	(void)c;
	return (option);
}

/*
** liste des options
** pour rajouter une option il suffit de recopier le pattern suivant
*/

static int	ft_listing_option(char c, int option)
{
	c == 'p' ? option = option | 1 : 0;
	c == 'q' ? option = option | 2 : 0;
	c == 'r' ? option = option | 4 : 0;
	c == 's' ? option = option | 8 : 0;
	c == 'h' ? option = option | 16 : 0;
	option = ft_plugout_option(c, option);
	return (option);
}

/*
**
**
*/
static char **complexe_option(char c, char *d, char **av, t_option *complexe)
{
	if (c == 's') {
		complexe->s = av[1];
		if (*d != '\0' || !av[1]) {
			usage_complexe_option(c, "must be follow by a string", "./ft_ssl md5 -s \"my special string\"");
		}
		return (&av[1]);
	}
	return (NULL);
}

/*
** permet de scruter les options
** aussi bien sur le meme arg que sur plusieur arg
*/

static char	**ft_option(char **av, int *option, t_option *complexe)
{
	int		i;
	char	**rcv;

	while (*av)
	{
		i = 0;
		if ((*av)[0] != '-' || !(*av)[1])
			return (av);
		while ((*av)[++i])
		{
			if (ft_strchr(LIST_OPTION, (*av)[i]) == NULL)
				usage_option((*av)[i]);
			*option = ft_listing_option((*av)[i], *option);
			if ((rcv = complexe_option((*av)[i], &(*av)[i + 1], av, complexe)))
			{
				av = rcv;
				break ;
			}
		}
		av = &av[1];
	}
	return (av);
}

/*
** fonction visible de l'exterieur
** elle permet de recuperer les options via ...
** ...l'adresse d'un int que l'on passe en parametre
** et elle retourne l'argument qui suit les options
*/

char **sha256_get_option(char **av, int *option, t_option *complexe)
{

    *option = 0;
    ft_bzero(complexe, sizeof(complexe));
	if (!(av) || !(*av))
		return (av);
	return (ft_option(av, option, complexe));
}

/*
**  1024 512 256 128  64  32  16   8   4   2   1
**    -   -   -   -    -   -   h   s   r   q   p
**    0   0   0   0    0   0   0   0   0   0   0
**
** Lors d'ajout d'option penser a rajouter l'option dans la liste des options
*/