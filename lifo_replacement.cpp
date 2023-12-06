/**
* Assignment 5: Page replacement algorithms
 * @file lifo_replacement.cpp
 * @author ??? (TODO: your name)
 * @brief A class implementing the Last in First Out (LIFO) page replacement algorithms
 * @version 0.1
 */
//You must complete the all parts marked as "TODO". Delete "TODO" after you are done.
// Remember to add sufficient and clear comments to your code

#include "lifo_replacement.h"

// TODO: Add your implementation here
LIFOReplacement::LIFOReplacement(int num_pages, int num_frames)
: Replacement(num_pages, num_frames)
{
    // TODO: Add additional implementation code
}

// TODO: Add your implementations for desctructor, load_page, replace_page here
LIFOReplacement::~LIFOReplacement() {
    // TODO: Add necessary code here
}

// Access an invalid page, but free frames are available
void LIFOReplacement::load_page(int page_num) {
    // TODO: Add necessary code here
    s.push(page_num);
    page_table[page_num].valid = true;
    page_table[page_num].frame_num = frameCount;
    frameCount++;
    pageFaults++;
}

// Access an invalid page and no free frames are available
int LIFOReplacement::replace_page(int page_num) {
    // TODO: Add necessary code here
    int next = s.top();//to find the page that was the last one inserted
    s.pop();//pop from the stack, we dont need it anymore
    page_table[next].valid = false;//we mark it as false becuase its not in the page table anymore
    page_table[page_num].valid = true;//we mark it as true because we jsut added it to the page table
    s.push(page_num);//we add it to the stack to keep track of the last one in
    pageFaults++;//to keep track of the page faults
    pageReplacements++;

    
    return 0;
}