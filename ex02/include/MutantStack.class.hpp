/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   MutantStack.class.hpp                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vfuhlenb <vfuhlenb@students.42wolfsburg    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/17 18:42:40 by vfuhlenb          #+#    #+#             */
/*   Updated: 2023/05/17 19:56:35 by vfuhlenb         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MUTANTSTACK_CLASS_HPP
#define MUTANTSTACK_CLASS_HPP

#include <stack>
#include <string>

template< typename T >
class MutantStack : public std::stack<T>
{
	public:
		MutantStack();
		virtual ~MutantStack();
		MutantStack(const MutantStack<T>& src);
		MutantStack& operator=(const MutantStack<T>& rhs);

		typedef typename std::stack<T>::container_type::iterator		iterator;
		typedef typename std::stack<T>::container_type::const_iterator	const_iterator;

		iterator begin();
		iterator end();
		const_iterator begin() const;
		const_iterator end() const;
	
	private:

};

#include "MutantStack.class.tpp"

#endif
