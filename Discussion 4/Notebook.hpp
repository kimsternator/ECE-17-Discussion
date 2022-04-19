#ifndef _NOTEBOOK
#define _NOTEBOOK

// Same things as header guards
#pragma once

#include <vector>
#include <iostream>
#include <string>

struct Page {
	std::string text;
	int pageNum;
};

// Tags (1 byte) to differentiate similar overloads
struct Index {};
struct PageNum {};

using PageList = std::vector<Page>;

class Notebook {
public:
	// Default Constructor
	Notebook();
	// Parameter Constructor
	Notebook(PageList pages);
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
	bool remove(int anIndex, Index);
	// remove index anIndex
	bool remove(int aPageNum, PageNum);

	// General Functions
	bool insert(Page aPage);
	bool contains(const Page& aPage) const;
	int find(const Page& aPage) const;
	size_t pages() const;

private:
	std::vector<Page> _pages;
};

class LabeledNotebook : public Notebook {
public:
	std::string title;
};

#endif _NOTEBOOK

/*
public
public - public
protected -protected
private - private

protected
public - protected
protected - protected
private - private

private
public - private
protected - private
private - private
*/