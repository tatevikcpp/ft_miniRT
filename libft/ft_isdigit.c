/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isdigit.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tkhechoy <tkhechoy@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/05 11:05:35 by tkhechoy          #+#    #+#             */
/*   Updated: 2023/08/05 11:05:36 by tkhechoy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_isdigit(int x)
{
	if (x >= '0' && x <= '9')
		return (1);
	return (0);
}
