#define printOne(x) std::cout << x << std::endl

#define generateMark (rand()%100)+1

template <typename T>
void printAll(T container)
{
	for (auto element : container)
	{
		printOne(element);
	}
}
