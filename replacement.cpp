/**
* Assignment 5: Page replacement algorithms
 * @file replacement.cpp
 * @author ??? (TODO: your name)
 * @brief A base class for different page replacement algorithms.
 * @version 0.1
 */
//You must complete the all parts marked as "TODO". Delete "TODO" after you are done.
// Remember to add sufficient and clear comments to your code
#include <iostream>
#include "replacement.h"

// TODO: Add your implementation of the Replacement member functions here

// Constructor
Replacement::Replacement(int num_pages, int num_frames)
: page_table(num_pages)
{
	//TODO: Add your implementation here
    pages = num_pages;
    frames = num_frames;
    frameCount = 0;
    pageIndex = 0;
    pageFaults = 0;
    references = 0;
    pageReplacements = 0;
}

// Destructor
Replacement::~Replacement()
{
    // TOOD: Add your code here

}

// Simulate a single page access 
// @return true if it's a page fault
bool Replacement::access_page(int page_num, bool is_write)
{
    // TODO: Add your implementation here
    // If the page is valid, it calls the touch_page function. 
    // If the page is not valid but free frames are available, it calls the load_page function.
    // If the page is not valid and there is no free frame, it calls the replace_page function.
    references++;
    if (page_table[page_num].valid)//if page within the page is free
    {
        touch_page(page_num);
    }
    else
    {
        if (frameCount < frames)//if there is no page available but there is still a frame avalailable
        {
            load_page(page_num);
            return true;
        }
        else
        {
            replace_page(page_num);
            return true;
        }
    }
    
    return false;
}

// Print out statistics of simulation
void Replacement::print_statistics() const {
        // TODO: print out the number of references, number of page faults and number of page replacements
		std::cout << "Number of references: \t\t"  << references<< std::endl;
		std::cout << "Number of page faults: \t\t" << pageFaults<< std::endl;
		std::cout << "Number of page replacements: \t" <<pageReplacements << std::endl;
}