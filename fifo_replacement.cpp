/**
* Assignment 5: Page replacement algorithms
 * @file fifo_replacement.cpp
 * @author ??? (TODO: your name)
 * @brief A class implementing the FIFO page replacement algorithms
 * @version 0.1
 */
//You must complete the all parts marked as "TODO". Delete "TODO" after you are done.
// Remember to add sufficient and clear comments to your code

#include "fifo_replacement.h"
//we are going to use the functions of the replacement class?
// TODO: Add your implementation here
FIFOReplacement::FIFOReplacement(int num_pages, int num_frames)
: Replacement(num_pages, num_frames)
{
    // TODO: Add additional implementation code
    //should we use the protected members of the replacement class?
    //when we create an instance of the FIFO replacement class.
    //an instance of both the FIFOReplacement class and the replacement class
    //so we can use the the protected variables of the replacement class I believe
}

// TODO: Add your implementations for desctructor, load_page, replace_page here
FIFOReplacement::~FIFOReplacement() {
    // TODO: Add necessary code here
}

// Access an invalid page, but free frames are available
void FIFOReplacement::load_page(int page_num) {
    // TODO: Update your data structure FIFO replacement and pagetable
    q.push(page_num);//we push this page into the front of the queue
    page_table[page_num].valid = true;//it is added to the page table so we mark it as true
    page_table[page_num].frame_num = frameCount;//we designate the frame num 
    frameCount++;//to keep track of the frame num
    pageFaults++;//to keep track of the pageFaults
}

// Access an invalid page and no free frames are available
int FIFOReplacement::replace_page(int page_num) {
    // TODO: Update your data structure FIFO replacement and pagetable
    //we will remove the page from the first one in
    page_table[q.front()].valid = false;//this page is no longer in the page table so we mark it as false
    q.pop();
    page_table[page_num].valid = true;//this page is added to the page table so we mark it as true
    q.push(page_num);//we push the page we just added into the front of the queue
    pageFaults++;//we increment the amount of page faults
    pageReplacements++;
    return 0;
}