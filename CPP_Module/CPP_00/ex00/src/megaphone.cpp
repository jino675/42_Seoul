#include <iostream>

class Megaphone {
public:
	void	speak(const int ac, char **av) {
		if (ac == 1) {
			std::cout << "* LOUD AND UNBEARABLE FEEDBACK NOISE *\n";
			return ;
		}
		for (int i = 1; i < ac; ++i) {
			for (int j = 0; av[i][j] != '\0'; ++j) {
				if (av[i][j] >= 'a' && av[i][j] <= 'z')
					std::cout << (char)(av[i][j] - 'a' + 'A');
				else
					std::cout << av[i][j];
			}
		}
		std::cout << "\n";
	}
};

int	main(int ac, char **av)
{
	Megaphone	m;

	m.speak(ac, av);
	return (0);
}
