/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   MutantStack.class.tpp                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vfuhlenb <vfuhlenb@students.42wolfsburg    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/17 18:53:26 by vfuhlenb          #+#    #+#             */
/*   Updated: 2023/05/17 23:05:05 by vfuhlenb         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

template< typename T >
MutantStack<T>::MutantStack() {}

template< typename T >
MutantStack<T>::~MutantStack() {}

template< typename T >
MutantStack<T>::MutantStack(const MutantStack<T>& src) {
	*this = src;
}

template< typename T >
MutantStack<T>&	MutantStack<T>::operator=(const MutantStack<T>& rhs)
{
	(void)rhs;
	return *this;
}

template <typename T>
typename MutantStack<T>::iterator MutantStack<T>::begin()
{
	return std::stack<T>::c.begin(); // c refers to the type of the stack container -> underlaying
}

template <typename T>
typename MutantStack<T>::iterator MutantStack<T>::end()
{
	return std::stack<T>::c.end();
}
