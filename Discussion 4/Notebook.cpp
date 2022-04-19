#include "Notebook.hpp"

#include <algorithm>

Notebook::Notebook() {
	std::cout << "default" << std::endl;
}

Notebook::Notebook(PageList pages) {
	std::cout << "parameter" << std::endl;
	_pages = pages;
}

Notebook::~Notebook() {
	std::cout << "destructor" << std::endl;
}

Notebook::Notebook(const Notebook& aNotebook) {
	*this = aNotebook;
}

Notebook& Notebook::operator=(const Notebook& aNotebook) {
	this->_pages = aNotebook._pages;
	return *this;
}

Page& Notebook::operator[](size_t anIndex) {
	return _pages[anIndex];
}

// Removes Page by index
bool Notebook::remove(int anIndex, Index) {
	if (anIndex >= pages()) {
		return false;
	}
	_pages.erase(_pages.begin() + anIndex);

	return true;
}

// Removes Page by pageNum
bool Notebook::remove(int aPageNum, PageNum) {
	for (int i = (int) pages() - 1; i >= 0; i--) {
		if ((*this)[i].pageNum == aPageNum) {
			_pages.erase(_pages.begin() + i);
		}
	}

	return true;
}

// Insert a new page (at the end)
bool Notebook::insert(Page aPage) {
	_pages.push_back(aPage);
	return true;
}

// Check if notebook contains a page
bool Notebook::contains(const Page& aPage) const {
	for (auto& page : _pages) {
		if (page.pageNum == aPage.pageNum &&
			page.text == aPage.text) {
			return true;
		}
	}

	return false;
}

// Find a page in notebook, return -1 if not found
int Notebook::find(const Page& aPage) const {
	for (size_t i = 0; i < pages(); i++) {
		if (_pages[i].pageNum == aPage.pageNum &&
			_pages[i].text == aPage.text) {
			return i;
		}
	}

	return -1;
}

// Returns number of pages
size_t Notebook::pages() const {
	return _pages.size();
}
