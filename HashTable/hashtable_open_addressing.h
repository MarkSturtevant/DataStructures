#ifndef HASHTABLE_OPEN_ADDRESSING_H
#define HASHTABLE_OPEN_ADDRESSING_H

#include <functional>
#include <iostream>
#include <vector>

using std::vector;

template <class Key, class Hash=std::hash<Key>>
class HashTable {
private:
    vector<Key> list;
    vector<int> states; // 0: empty, 1: used, 2: deleted
    size_t buckets;
    size_t numItems;
    float maxLoadFactor;

    size_t getNextPrime(size_t oldPrime);
public:
    HashTable();
    explicit HashTable(size_t length);

    bool is_empty() const;
    size_t size() const;
    size_t table_size() const;

    void make_empty();
    bool insert(const Key& item);
    size_t remove(const Key& item);

    bool contains(const Key& item) const;

    size_t position(const Key& item) const;

    float load_factor() const;
    float max_load_factor() const;
    void rehash(size_t numBuckets);

    void print_table(std::ostream& os = std::cout) const;
};

template <class Key, class Hash>
HashTable<Key, Hash>::HashTable() : list(), states(), buckets(11), numItems(0),
        maxLoadFactor(0.5) {
    for (size_t i = 0; i < buckets; ++i) {
        list.push_back(Key{});
        states.push_back(0);
    }

}

template <class Key, class Hash>
HashTable<Key, Hash>::HashTable(size_t length) : list(), states(), buckets(length),
        numItems(0), maxLoadFactor(0.5) {
    for (size_t i = 0; i < this->buckets; ++i) {
        list.push_back(Key{});
        states.push_back(0);
    }
}

template <class Key, class Hash>
bool HashTable<Key, Hash>::is_empty() const {
    return numItems == 0;
}

template <class Key, class Hash>
size_t HashTable<Key, Hash>::size() const {
    return numItems;
}

template <class Key, class Hash>
void HashTable<Key, Hash>::make_empty() {
    for (size_t i = 0; i < this->buckets; ++i) {
        list[i] = Key{};
        states[i] = 0;
    }
    numItems = 0;
}

template <class Key, class Hash>
bool HashTable<Key, Hash>::insert(const Key &item) {
    /*size_t index = Hash{}(item) % buckets;

    size_t indexCopy = index;

    do {
        if (states[indexCopy] == 0)
            break;
        if (states[indexCopy] == 1 && list[indexCopy] == item)
            return false;

        indexCopy = (indexCopy + 1) % buckets;
    } while (indexCopy != index);

    while (states[index] == 1)
        index = (index + 1) % buckets;

    list[index] = item;
    states[index] = 1;

    numItems++;
    if (this->load_factor() > this->maxLoadFactor)
        this->rehash(this->getNextPrime(this->buckets));*/

    size_t index = position(item);
    if (states[index] == 1 && list[index] == item)
        return false;

    states[index] = 1;
    list[index] = item;
    numItems++;

    if (this->load_factor() > this->maxLoadFactor)
        this->rehash(this->getNextPrime(this->buckets));

    return true;
}

template <class Key, class Hash>
size_t HashTable<Key, Hash>::remove(const Key &item) {
    /*size_t index = Hash{}(item) % buckets;
    size_t indexCopy = index;

    do {
        if (states[index] == 0)
            return 0;
        else if (states[index] == 1 && list[index] == item) {
            states[index] = 2;
            numItems--;
            return 1;
        }
        index = (index + 1) % buckets;
    } while (indexCopy != index);*/

    size_t index = position(item);
    if (states[index] == 1 && list[index] == item) {
        states[index] = 2;
        numItems--;
        return 1;
    }
    return 0;
}

template <class Key, class Hash>
bool HashTable<Key, Hash>::contains(const Key &item) const {
    size_t index = Hash{}(item) % buckets;
    size_t indexCopy = index;

    do {
        if (states[index] == 0)
            return false;
        else if (states[index] == 1 && list[index] == item) {
            return true;
        }
        index = (index + 1) % buckets;
    } while (indexCopy != index);
    return false;
}



template <class Key, class Hash>
float HashTable<Key, Hash>::load_factor() const {
    return static_cast<float>(numItems) / static_cast<float>(buckets);
}

template <class Key, class Hash>
float HashTable<Key, Hash>::max_load_factor() const {
    return maxLoadFactor;
}

template <class Key, class Hash>
size_t HashTable<Key, Hash>::table_size() const {
    return buckets;
}

template <class Key, class Hash>
size_t HashTable<Key, Hash>::position(const Key &item) const {
    size_t index = Hash{}(item) % buckets;
    size_t indexCopy = index;

    do {
        if (states[indexCopy] == 0)
            return indexCopy;
        if (list[indexCopy] == item)
            return indexCopy;

        indexCopy = (indexCopy + 1) % buckets;
    } while (indexCopy != index);

    while (states[index] == 1)
        index = (index + 1) % buckets;
    return index;
}

template <class Key, class Hash>
void HashTable<Key, Hash>::print_table(std::ostream &os) const {
    if (numItems == 0) {
        os << "<empty>\n";
        return;
    }

    for (size_t i = 0; i < buckets; ++i) {
        if (states[i] != 1)
            continue;
        os << i << ": [" << list[i] << "]\n";
    }
}

template <class Key, class Hash>
size_t HashTable<Key, Hash>::getNextPrime(size_t oldPrime) {
    size_t newPrime;
    if (oldPrime == 1)
        newPrime = 2;
    else {
        newPrime = oldPrime * 2 + 1;
        while (true) {
            bool good = true;
            for (size_t i = 2; i < newPrime / 2; ++i)
                if (newPrime % i == 0) {
                    good = false;
                    break;
                }

            if (good)
                break;
            else newPrime += 2;

        }
    }

    if (this->maxLoadFactor < static_cast<float>(numItems) / static_cast<float>(newPrime))
        return this->getNextPrime(newPrime);
    else return newPrime;
}

template <class Key, class Hash>
void HashTable<Key, Hash>::rehash(size_t numBuckets) {
    if (numBuckets <= 0 || maxLoadFactor < static_cast<float>(numItems) / static_cast<float>(numBuckets)) {
        numBuckets = static_cast<int>(static_cast<float>(numItems) / maxLoadFactor) + 2;
    }

    vector<Key> old = this->list;
    vector<int> oldStates = this->states;
    size_t oldLength = this->buckets;

    this->buckets = numBuckets;
    this->list = vector<Key>();
    this->states = vector<int>();

    for (size_t i = 0; i < numBuckets; ++i) {
        list.push_back(Key{});
        states.push_back(0);
    }


    for (size_t i = 0; i < oldLength; ++i) {
        if (oldStates[i] == 1) {
            insert(old[i]);
            numItems--;
        }
    }
}


#endif  // HASHTABLE_OPEN_ADDRESSING_H