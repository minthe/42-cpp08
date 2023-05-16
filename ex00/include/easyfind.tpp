/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   easyfind.tpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vfuhlenb <vfuhlenb@students.42wolfsburg    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/15 20:39:24 by vfuhlenb          #+#    #+#             */
/*   Updated: 2023/05/16 17:04:45 by vfuhlenb         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

const char* ValueNotFound::what() const throw()
{
	return ("\x1b[31mValue not found!\x1b[0m");
}

template< typename T >
typename T::iterator	easyfind(T& a, const int b)
{
	typename T::iterator it = find(a.begin(), a.end(), b);
	if (it != a.end())
		return it;
	throw ValueNotFound();
}
