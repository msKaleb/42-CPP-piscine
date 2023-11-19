#ifndef BRAIN_HPP
# define BRAIN_HPP

# include <iostream>
# include <string>

class Brain
{
	private:
		std::string	*_ideas;

	public:

		/* Orthodox Canonical Form */
		Brain();
		Brain( Brain const &src );
		Brain	&operator=( Brain const &rhs );
		virtual ~Brain();

		std::string	*getIdeas(void) const;
};

std::ostream &			operator<<( std::ostream & o, Brain const & i );

#endif /* *********************************************************** BRAIN_H */