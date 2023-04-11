#include <SFML/Graphics.hpp>
#include <iostream>
#include "Algorithms.h"
#include "time.h"
void fill_array(int* arr, int size) {
	for (int i = 0; i < size; i++) {
		arr[i] = rand() % 400;
	}
}
void printArray(int* array, int size) {
	for (int i = 0; i < size; i++) {
		std::cout << *(array + i) << " ";
	}
	std::cout << std::endl;
}
static const unsigned int WINDOW_WIDTH = 800;
static const unsigned int WINDOW_HEIGHT = 500;
int main() {
	srand(time(0));


	sf::RenderWindow window(sf::VideoMode(WINDOW_WIDTH, WINDOW_HEIGHT), "My window");
	window.setFramerateLimit(20);

	// run the program as long as the window is open
	while (window.isOpen())
	{
		const int arr_size = 100;
		int array[arr_size];
		fill_array(array, arr_size);
		int array_size = sizeof(array) / sizeof(array[0]);
		// check all the window's events that were triggered since the last iteration of the loop
		sf::Event event;
		while (window.pollEvent(event))
		{
			if (event.type == sf::Event::Closed)
				window.close();
			// "close requested" event: we close the window
		}
		window.clear(sf::Color::White);
		// draw
		heapSort(array, array_size, window, WINDOW_WIDTH, WINDOW_HEIGHT);
		// end the current frame
		window.display();
	}



	return 0;
}