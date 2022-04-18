#ifndef _NOTEBOOK
#define _NOTEBOOK

// Same things as header guards
#pragma once

#include <vector>
#include <string>

struct Page {
	std::string text;
	int pageNum;
};

class Notebook {
public:
	// Default Constructor
	Notebook();
	// Parameter Constructor
	Notebook(std::vector<Page> pages);
	// Destructor
	~Notebook();
	// Copy Constructor
	Notebook(const Notebook& aNotebook);

	// Operator Overloading
	// Assignment Operator
	Notebook& operator=(const Notebook& aNotebook);
	// Index Operator
	Page& operator[](size_t anIndex);

	// Function Overloading
	bool remove(size_t anIndex);
	bool remove(Page aPage);

	// General Functions
	bool insert(Page aPage);
	bool contains(Page aPage);
	size_t find(Page aPage);
	size_t pages();

private:
	std::vector<Page> _pages;
};

#endif _NOTEBOOK