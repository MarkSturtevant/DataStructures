#ifndef HASHTABLE_SEPARATE_CHAINING_H
#define HASHTABLE_SEPARATE_CHAINING_H

#include <functional>
#include <iostream>
#include <vector>

using std::vector;

template <class Key, class Hash=std::hash<Key>>
class HashTable {
private:
    vector<vector<Key>> list;
    size_t buckets;
    size_t numItems;
    float maxLoadFactor;

    size_t getNextPrime(size_t oldPrime);
public:
    HashTable();
    explicit HashTable(size_t length);

    bool is_empty() const;
    size_t size() const;

    void make_empty();
    bool insert(const Key& item);
    size_t remove(const Key& item);

    bool contains(const Key& item) const;

    size_t bucket_count() const;
    size_t bucket_size(size_t index) const;
    size_t bucket(const Key& item) const;
    void rehash(size_t numBuckets);

    float load_factor() const;
    float max_load_factor() const;
    void max_load_factor(float newFactor);

    void print_table(std::ostream& os = std::cout) const;
};

template <class Key, class Hash>
HashTable<Key, Hash>::HashTable() : list(11), buckets(11), numItems(0), maxLoadFactor(1) {
    for (size_t i = 0; i < buckets; ++i)
       list[i] = vector<Key>();
}

template <class Key, class Hash>
HashTable<Key, Hash>::HashTable(size_t length) : list(length), buckets(length), numItems(0), maxLoadFactor(1) {
    for (size_t i = 0; i < buckets; ++i)
        list[i] = vector<Key>();
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
        list[i].clear();
    }
    numItems = 0;
}

template <class Key, class Hash>
bool HashTable<Key, Hash>::insert(const Key &item) {
    size_t index = Hash{}(item) % buckets;

    for (size_t i = 0; i < (list[index]).size(); ++i)
        if (list[index].at(i) == item)
            return false;

    list[index].push_back(item);

    numItems++;
    if (this->load_factor() > this->maxLoadFactor)
        this->rehash(this->getNextPrime(this->buckets));

    return true;
}

template <class Key, class Hash>
size_t HashTable<Key, Hash>::remove(const Key &item) {
    size_t index = Hash{}(item) % buckets;

    size_t i = 0;
    for (; i < list[index].size(); ++i)
        if (list[index][i] == item)
            break;

    if (i == list[index].size())
        return 0;
    list[index].erase(list[index].begin() + i);
    numItems--;
    return 1;
}

template <class Key, class Hash>
bool HashTable<Key, Hash>::contains(const Key &item) const {
    size_t index = Hash{}(item) % buckets;

    size_t i = 0;
    for (; i < list[index].size(); ++i)
        if (list[index][i] == item)
            break;

    return i != list[index].size();
}

template <class Key, class Hash>
size_t HashTable<Key, Hash>::bucket_count() const {
    return this->buckets;
}

template <class Key, class Hash>
size_t HashTable<Key, Hash>::bucket_size(size_t index) const {
    if (index >= buckets)
        throw std::out_of_range("Out of range, fool!");

    return list[index].size();
}

template <class Key, class Hash>
size_t HashTable<Key, Hash>::bucket(const Key &item) const {
    return (Hash{}(item) % buckets);
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
void HashTable<Key, Hash>::max_load_factor(float newFactor) {
    if (newFactor <= 0)
        throw std::invalid_argument("newFactor must be > 0");
    maxLoadFactor = newFactor;
    if (load_factor() > newFactor)
        rehash(getNextPrime(buckets));
}

template <class Key, class Hash>
void HashTable<Key, Hash>::print_table(std::ostream &os) const {
    if (numItems == 0) {
        os << "<empty>\n";
        return;
    }

    for (size_t i = 0; i < buckets; ++i) {
        if (list[i].size() == 0)
            continue;
        os << i << ": [";

        for (size_t j = 0; j < list[i].size()-1; ++j)
            os << list[i][j] << ", ";
        os << list[i][list[i].size()-1] << "]\n";
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

    vector<vector<Key>> old = this->list;
    size_t oldLength = this->buckets;

    this->buckets = numBuckets;
    this->list = vector<vector<Key>>();

    for (size_t i = 0; i < numBuckets; ++i)
        list.push_back(vector<Key>());

    for (size_t i = 0; i < oldLength; ++i) {
        for (Key k : old[i]) {
            insert(k);
            numItems--; // insert adds to numItems, but we are MOVING, not ADDING.
        }
    }
}

#endif  // HASHTABLE_SEPARATE_CHAINING_H