#include "Algorithms.h"

#include <Windows.h>
//////////////////////////////////////////////////////////////////////////////////////////
// Recursive heapify 
void heapify(int* arr, int size, int node) {

	// 2 * i + 1 -> Left child
	// 2 * i + 2 -> Right child
	// i/ 2 -> Parent
	// Start node -> (array size / 2) - 1;

	int largest = node;
	int left = 2 * node + 1;
	int right = 2 * node + 2;
	// Look right child if larger than parent assing as largest
	if (right < size && arr[right] > arr[largest]) {
		largest = right;
	}
	// Look left child if larger than parent assing as largest
	if (left < size && arr[left] > arr[largest]) {
		largest = left;
	}
	// if start node is not equal largest, there is a child larger than parent so 
	// first swap parent and child than recurse the operation for lower nodes
	if (largest != node) {
		std::swap(arr[node], arr[largest]);
		heapify(arr, size, largest);
	}
}
void heapSort(int* arr, int size, sf::RenderWindow& window, const unsigned int WINDOW_WIDTH, const unsigned int WINDOW_HEIGHT) {
	// Build heap
	for (int i = size / 2 - 1; i >= 0; i--)
		heapify(arr, size, i);

	// One by one extract an element from heap
	for (int i = size - 1; i >= 0; i--) {
		// Move current root to end
		std::swap(arr[0], arr[i]);
		window.clear(sf::Color::White);
		for (int i = 0; i < size; i++) {
			int x_pos = WINDOW_WIDTH / size;
			int y_pos = arr[i];
			sf::RectangleShape rec(sf::Vector2f(x_pos, y_pos));
			rec.setPosition(i * x_pos, WINDOW_HEIGHT - arr[i]);
			rec.setFillColor(sf::Color::Black);
			rec.setOutlineThickness(2.f);
			rec.setOutlineColor(sf::Color::White);

			window.draw(rec);

			std::cout << rec.getPosition().x << " " << y_pos << std::endl;

		}
		window.display();

		// call max heapify on the reduced heap
		heapify(arr, i, 0);

	}
}
//////////////////////////////////////////////////////////////////////////////////////////

