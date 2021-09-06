#include "hashtable_open_addressing.h"
#include <iostream>
#include <sstream>

using std::cout, std::endl;

int main() {
    // PART 0 - CLASS TESTS ------------------------------------------

    HashTable<int> table5(10);
    table5.insert(3);
    table5.insert(4);
    size_t index13b = table5.position(13);
    table5.insert(13);
    size_t index14 = table5.position(14);

    table5.print_table();

    table5.remove(4);

    table5.print_table();

    cout << "Should be equal: " << index13b << " | " << table5.position(13) << endl;
    cout << "Should be equal: " << index14 << " | " << table5.position(14) << endl;

    cout << "-------------------------------------------------" << endl;

    HashTable<int> table3(10);
    size_t index3 = table3.position(3);
    table3.insert(3);
    std::cout << "Should be equal: " << table3.position(3) << " | " << index3 << endl;
    size_t index13 = table3.position(13);
    table3.insert(13);
    std::cout << "Should be equal: " << table3.position(3) << " | " << index3 << endl;
    std::cout << "Should be equal: " << table3.position(13) << " | " << index13 << endl;
    table3.remove(3);
    std::cout << "Should be equal: " << table3.position(3) << " | " << index3 << endl;
    std::cout << "Should be equal: " << table3.position(13) << " | " << index13 << endl;
    table3.insert(3);
    std::cout << "Should be equal: " << table3.position(3) << " | " << index3 << endl;
    std::cout << "Should be equal: " << table3.position(13) << " | " << index13 << endl;
    table3.remove(13);
    std::cout << "Should be equal: " << table3.position(3) << " | " << index3 << endl;
    std::cout << "Should be equal: " << table3.position(13) << " | " << index13 << endl;
    table3.insert(13);
    std::cout << "Should be equal: " << table3.position(3) << " | " << index3 << endl;
    std::cout << "Should be equal: " << table3.position(13) << " | " << index13 << endl;

    // PART 1 - MY TESTS :D ------------------------------------------

    HashTable<std::string> set;

    cout << "Is Empty? " << set.is_empty() << endl;
    cout << "Size: " << set.size() << endl;
    cout << "Making the set empty." << endl;
    cout << "Is Empty? " << set.is_empty() << endl;
    cout << "Size: " << set.size() << endl;

    cout << "Contains \"hello\"? " << set.contains("hello") << endl;

    cout << "\nRemoving and inserting \"hello\"" << endl;

    set.remove("hello");
    set.insert("hello");

    cout << "Is Empty? " << set.is_empty() << endl;
    cout << "Size: " << set.size() << endl;
    cout << "Contains \"hello\"? " << set.contains("hello") << endl;
    cout << "Load Factor: " << set.load_factor() << endl;
    cout << "Max Load Factor: " << set.max_load_factor() << endl;
    set.print_table();

    cout << "\nDoing CRAZY STUFF!" << endl;

    set.insert("abc"); set.insert("bdb"); set.insert("wet");
    set.insert("rtt"); set.insert("wtr"); set.insert("aaa");
    set.insert("iir"); set.insert("mjk"); set.insert("xty");

    cout << "Is Empty? " << set.is_empty() << endl;
    cout << "Size: " << set.size() << endl;
    cout << "Contains \"hello\"? " << set.contains("hello") << endl;
    cout << "Load Factor: " << set.load_factor() << endl;
    cout << "Max Load Factor: " << set.max_load_factor() << endl;
    set.print_table();

    cout << "Is Empty? " << set.is_empty() << endl;
    cout << "Size: " << set.size() << endl;
    cout << "Contains \"hello\"? " << set.contains("hello") << endl;
    cout << "Load Factor: " << set.load_factor() << endl;
    cout << "Max Load Factor: " << set.max_load_factor() << endl;
    set.print_table();

    cout << "\nFinal Tests" << endl;
    set.insert("hello");
    set.insert("hello");
    set.remove("hello");
    set.remove("hello");

    cout << "Is Empty? " << set.is_empty() << endl;
    cout << "Size: " << set.size() << endl;
    cout << "Contains \"hello\"? " << set.contains("hello") << endl;
    cout << "Load Factor: " << set.load_factor() << endl;
    cout << "Max Load Factor: " << set.max_load_factor() << endl;
    set.print_table();


    cout << "\n\n-------------------------------------------------\n" << endl;


    // PART 2 -- TEACHER GIVEN TESTS

    std::cout << "make an empty hash table with 11 buckets for strings" << std::endl;
    HashTable<std::string> table(11);

    std::cout << "initial size is " << table.size() << std::endl;
    std::cout << "initial table size is " << table.table_size() << std::endl;

    std::cout << "insert several strings" << std::endl;
    table.insert("And them who hold High Places");

    table.insert("Must be the ones to start");
    table.insert("To mold a new Reality");
    table.insert("Closer to the Heart");
    table.insert("The Blacksmith and the Artist");
    table.insert("Reflect it in their Art");
    table.insert("Forge their Creativity");
    table.insert("Closer to the Heart");
    table.insert("Philosophers and Plowmen");
    table.insert("Each must know their Part");
    table.insert("To sow a new Mentality");
    table.insert("Closer to the Heart");
    table.insert("You can be the Captain");
    table.insert("I will draw the Chart");
    table.insert("Sailing into Destiny");
    table.insert("Closer to the Heart");

    std::cout << "size is " << table.size() << std::endl;

    std::cout << "table size is " << table.table_size() << std::endl;

    {
        std::cout << "print the table" << std::endl;
        std::stringstream ss;
        table.print_table(ss);
        std::cout << ss.str() << std::endl;
    }
    std::cout << "remove \"Philosophers and Plowmen\"" << std::endl;
    table.remove("Philosophers and Plowmen");
    std::cout << "remove \"Each must know their Part\"" << std::endl;
    table.remove("Each must know their Part");

    std::cout << "size is " << table.size() << std::endl;
    std::cout << "table size is " << table.table_size() << std::endl;

    {
        std::cout << "print the table" << std::endl;
        std::stringstream ss;
        table.print_table(ss);
        std::cout << ss.str() << std::endl;
    }

    std::cout << "find \"The Blacksmith and the Artist\"" << std::endl;
    size_t index = table.position("The Blacksmith and the Artist");
    std::cout << " ==> cell " << index << std::endl;

    std::cout << "make the table empty" << std::endl;
    table.make_empty();

    std::cout << "size is " << table.size() << std::endl;
    std::cout << "table size is " << table.table_size() << std::endl;

    {
        std::cout << "print the table" << std::endl;
        std::stringstream ss;
        table.print_table(ss);
        std::cout << ss.str() << std::endl;
    }


    return 0;
}