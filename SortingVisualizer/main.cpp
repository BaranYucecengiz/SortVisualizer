#include <SFML/Graphics.hpp>
#include <iostream>
#include <iomanip>
#include "Algorithms.h"
#include "time.h"

static const unsigned int WINDOW_WIDTH = 1200;
static const unsigned int WINDOW_HEIGHT = 800;
static const int array_size = 600;
static int array[array_size];
void fill_array(int* arr, int size) {
	for (int i = 0; i < size; i++) {
		arr[i] = (rand() % WINDOW_HEIGHT);
	}
}
void printArray(int* array, int size) {	
	for (int i = 0; i < size; i++) {
		std::cout << *(array + i) << " ";
	}
	std::cout << std::endl;
}
void print_menu() {
	std::setfill(' ');
	std::cout	<< std::setw(5) << std::left << "1." << "Heap Sort\n"
				<< std::setw(5) << std::left << "1." << "Merge Sort\n"
				<< std::setw(5) << std::left << "1." << "Quick Sort\n";
				
	std::cout << "Choose sorting algorithm: ";
}
int main() {
	int choice{ 0 };
	srand(time(0));
	sf::RenderWindow window(sf::VideoMode(WINDOW_WIDTH, WINDOW_HEIGHT), "My window");
	window.setFramerateLimit(20);
	
	// Filling array with random numbers
	
	// run the program as long as the window is open
	while (window.isOpen())
	{
		print_menu();
		std::cin >> choice;
		// check all the window's events that were triggered since the last iteration of the loop
		sf::Event event;
		while (window.pollEvent(event))
		{
			if (event.type == sf::Event::Closed)
				window.close();
			// "close requested" event: we close the window
		}
		// draw
		switch (choice){
		case 1:
			fill_array(array, array_size);
			heapSort(array, array_size, window, WINDOW_WIDTH, WINDOW_HEIGHT);
			break;
		case 2:
			fill_array(array, array_size);
			mergeSort(array, 0, array_size, window, array_size, WINDOW_WIDTH, WINDOW_HEIGHT);
			break;
		case 3:
			fill_array(array, array_size);
			quickSort(array, 0, array_size, window, array_size, WINDOW_WIDTH, WINDOW_HEIGHT);
			printArray(array, array_size);
			break;
		default:
			break;
		}

		window.clear(sf::Color::White);
		
		window.display();
		// end the current frame
	}
	return 0;
}