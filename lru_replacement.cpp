/**
* Assignment 5: Page replacement algorithms
 * @file lru_replacement.cpp
 * @author ??? (TODO: your name)
 * @brief A class implementing the LRU page replacement algorithms
 * @version 0.1
 */
//You must complete the all parts marked as "TODO". Delete "TODO" after you are done.
// Remember to add sufficient and clear comments to your code
#include <iostream>
#include "lru_replacement.h"

// TODO: Add your implementation here
LRUReplacement::LRUReplacement(int num_pages, int num_frames)
: Replacement(num_pages, num_frames)
{
    // TODO: Complete this constructor
    front = 0;
    rear = 0;
}

// TODO: Add your implementations for desctructor, touch_page, load_page, replace_page here
LRUReplacement::~LRUReplacement()
{
    // TODO: Add necessary code here
}

// Accesss a page alreay in physical memory
void LRUReplacement::touch_page(int page_num)
{ 
    unordered_map<int, list<int>::iterator>::iterator u = pageHash.find(page_num);
    
    l.erase( u->second);//remove the least recently used from our list
    l.push_back(page_num);//push the new page into our list
    
    
    pageHash[page_num] = prev(l.end()); //reupdate the position of the page num inside our map
    
    

    // if (pageHash.find(page_num) != pageHash.end())
    // {
    //     unordered_map<int, int>::iterator u = pageHash.find(page_num);
    //     v[u->second] = false;
    //     rear++;
    //     u->second = rear;
    //     l.push_back(page_num);
    //     v.push_back(true);
    //     //page_table[page_num].frame_num = page_table[u->second].frame_num;

    
    // }
}

// Access an invalid page, but free frames are available
void LRUReplacement::load_page(int page_num) {
    // TODO: Update your data structure LRU replacement and pagetable
    
    l.push_back(page_num);
    list<int>::iterator u = prev(l.end());
    pageHash.insert(make_pair(page_num, u));
    page_table[page_num].valid = true;
    page_table[page_num].frame_num = frameCount++;
    pageFaults++;
    // pageHash.insert(make_pair(page_num, rear));
    // l.push_back(page_num);
    // v.push_back(true);
    // page_table[page_num].valid = true;
    // page_table[page_num].frame_num = frameCount++;
    // pageFaults++;
    // rear++;
}

// Access an invalid page and no free frames are available
int LRUReplacement::replace_page(int page_num) {
    // TODO: Update your data structure LRU replacement and pagetable
    

    
    
    int toRemove = l.front();
    page_table[toRemove].valid = false;
    page_table[page_num].valid = true;
    pageHash.erase(pageHash.find(toRemove));
    l.push_back(page_num);
    pageHash.insert(make_pair(page_num, prev(l.end())));
    l.pop_front();
    pageFaults++;
    pageReplacements++;
    return 0;
    // if ((pageHash.find(page_num) == pageHash.end()))
    // {
    
    //     while (v[front] == false && front < rear)
    //     {
    //         front++;
    //     }

    //     v[front] = false;
    //     v.push_back(true);  

    //     unordered_map<int, int>::iterator u = pageHash.find(l[front]);
    //     if (u != pageHash.end())
    //     {
    //         pageHash.erase(u);
    //     }

    //     l.push_back(page_num);
    //     rear++;
    //     pageHash.insert(make_pair(page_num, rear));

    //     // Update page_table for the new page
    //     page_table[l[front]].valid = false;
    //     page_table[page_num].valid = true;
    //     page_table[page_num].frame_num = page_table[l[front]].frame_num;

    //     pageFaults++;
    //     pageReplacements++;

    //     // Update LRU queue after replacing a page
        
    //     front++;
    // }

    // return 0;
}

void LRUReplacement::printVectors()
{
    cout << "the size of my page num array is " << l.size() << endl;
    cout << "the size of my boolean array is " << v.size() << endl;        
    cout << "the size of my hash table is " << pageHash.size() << endl;
    cout << "my front is at index " << front << endl;
    cout << "my rear is at index " << rear << endl;
    
}