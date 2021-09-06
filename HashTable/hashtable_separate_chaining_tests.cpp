#include "hashtable_separate_chaining.h"
#include <sstream>
#include <iostream>

using std::cout, std::endl;

int main() {
    // PART 1 - MY TESTS :D ------------------------------------------

    HashTable<std::string> set;

    cout << "Is Empty? " << set.is_empty() << endl;
    cout << "Size: " << set.size() << endl;
    cout << "Making the set empty." << endl;
    cout << "Is Empty? " << set.is_empty() << endl;
    cout << "Size: " << set.size() << endl;

    cout << "Contains \"hello\"? " << set.contains("hello") << endl;
    cout << "Num Buckets: " << set.bucket_count() << endl;
    cout << "Num Elements in Bucket 0: " << set.bucket_size(3) << endl;
    cout << "Bucket for \"hello\": " << set.bucket("hello") << endl;

    cout << "\nRemoving and inserting \"hello\"" << endl;

    set.remove("hello");
    set.insert("hello");

    cout << "Is Empty? " << set.is_empty() << endl;
    cout << "Size: " << set.size() << endl;
    cout << "Contains \"hello\"? " << set.contains("hello") << endl;
    cout << "Num Buckets: " << set.bucket_count() << endl;
    cout << "Num Elements in Bucket 3: " << set.bucket_size(3) << endl;
    cout << "Bucket for \"hello\": " << set.bucket("hello") << endl;
    cout << "Load Factor: " << set.load_factor() << endl;
    cout << "Max Load Factor: " << set.max_load_factor() << endl;
    set.print_table();

    cout << "\nDoing CRAZY STUFF!" << endl;

    set.max_load_factor(10);
    set.rehash(1);

    set.insert("abc"); set.insert("bdb"); set.insert("wet");
    set.insert("rtt"); set.insert("wtr"); set.insert("aaa");
    set.insert("iir"); set.insert("mjk"); set.insert("xty");

    cout << "Is Empty? " << set.is_empty() << endl;
    cout << "Size: " << set.size() << endl;
    cout << "Contains \"hello\"? " << set.contains("hello") << endl;
    cout << "Num Buckets: " << set.bucket_count() << endl;
    cout << "Num Elements in Bucket 0: " << set.bucket_size(0) << endl;
    cout << "Bucket for \"hello\": " << set.bucket("hello") << endl;
    cout << "Load Factor: " << set.load_factor() << endl;
    cout << "Max Load Factor: " << set.max_load_factor() << endl;
    set.print_table();

    try {
        set.bucket_size(1);
        cout << "WARNING: Failed to catch!" << endl;
    } catch (std::out_of_range& e) {
        cout << "Successfully caught exception." << endl;
    }

    try {
        set.max_load_factor(0.0);
        cout << "WARNING: Failed to catch!" << endl;
    } catch (std::invalid_argument& e) {
        cout << "Successfully caught exception." << endl;
    }

    cout << "\nChanging Max Load Factor to 9." << endl;
    set.max_load_factor(9);
    cout << "Is Empty? " << set.is_empty() << endl;
    cout << "Size: " << set.size() << endl;
    cout << "Contains \"hello\"? " << set.contains("hello") << endl;
    cout << "Num Buckets: " << set.bucket_count() << endl;
    cout << "Num Elements in Bucket 0: " << set.bucket_size(0) << endl;
    cout << "Bucket for \"hello\": " << set.bucket("hello") << endl;
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
    cout << "Num Buckets: " << set.bucket_count() << endl;
    cout << "Num Elements in Bucket 0: " << set.bucket_size(0) << endl;
    cout << "Bucket for \"hello\": " << set.bucket("hello") << endl;
    cout << "Load Factor: " << set.load_factor() << endl;
    cout << "Max Load Factor: " << set.max_load_factor() << endl;
    set.print_table();


    cout << "\n\n-------------------------------------------------\n" << endl;

    // PART 2 - GIVEN CODE FOR TESTING -------------------------------
    std::cout << "make an empty hash table with 11 buckets for strings" << std::endl;
    HashTable<std::string> table(11);

    std::cout << "initial size is " << table.size() << std::endl;
    std::cout << "initial bucket count is " << table.bucket_count() << std::endl;
    std::cout << "initial load factor is " << table.load_factor() << std::endl;
    std::cout << "initial max load factor is " << table.max_load_factor() << std::endl;

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
    std::cout << "bucket count is " << table.bucket_count() << std::endl;
    std::cout << "load factor is " << table.load_factor() << std::endl;
    std::cout << "max load factor is " << table.max_load_factor() << std::endl;

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
    std::cout << "bucket count is " << table.bucket_count() << std::endl;
    std::cout << "load factor is " << table.load_factor() << std::endl;
    std::cout << "max load factor is " << table.max_load_factor() << std::endl;

    {
        std::cout << "print the table" << std::endl;
        std::stringstream ss;
        table.print_table(ss);
        std::cout << ss.str() << std::endl;
    }

    std::cout << "set max load factor to 2" << std::endl;
    table.max_load_factor(2);
    std::cout << "rehash the table to size 7" << std::endl;
    table.rehash(7);

    std::cout << "size is " << table.size() << std::endl;
    std::cout << "bucket count is " << table.bucket_count() << std::endl;
    std::cout << "load factor is " << table.load_factor() << std::endl;
    std::cout << "max load factor is " << table.max_load_factor() << std::endl;

    {
        std::cout << "print the table" << std::endl;
        std::stringstream ss;
        table.print_table(ss);
        std::cout << ss.str() << std::endl;
    }

    std::cout << "find \"The Blacksmith and the Artist\"" << std::endl;
    size_t index = table.bucket("The Blacksmith and the Artist");
    std::cout << " ==> bucket " << index << std::endl;
    std::cout << "     which has " << table.bucket_size(index) << " elements" << std::endl;

    std::cout << "make the table empty" << std::endl;
    table.make_empty();

    std::cout << "size is " << table.size() << std::endl;
    std::cout << "bucket count is " << table.bucket_count() << std::endl;
    std::cout << "load factor is " << table.load_factor() << std::endl;
    std::cout << "max load factor is " << table.max_load_factor() << std::endl;

    {
        std::cout << "print the table" << std::endl;
        std::stringstream ss;
        table.print_table(ss);
        std::cout << ss.str() << std::endl;
    }


    return 0;
}
