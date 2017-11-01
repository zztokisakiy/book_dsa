#include <iostream>
#include <string>
using namespace std;
// 增删改查
const int hash_size = 1009;


// the size of key is 8
class Key{
public:
    Key(const std::string & str)；
    char key_letter(int position) cosnt;
    void make_bland();
private:
    std::string key;
};

Key::Key(const std::string &str){
    key = str;
}

char Key::key_letter(int position) const{
    return key[position];
}

void Key::make_bland(){

}


int hash(const Key &target){
    int value = 0;
    for (int position = 0; position < 8; position ++){
        value = 4 * value + target.key_letter(position);
    }
    return value % hash_size;
}
Key::Key(const std::string & str){
    key = str;
}


// solve collision

/* 
    1. linear probing
    2. rehashing 
    3. quadratic probing */

// quadratic probing
const inst hash_size = 997;
class Hash_table{
public:
    Hash_table();
    void clear();
    Error_code insert(const Record &new_entry);
    Error_code retrieve(const Key & target, Record &found) const;
private:
    Record table[hash_size];
};


Hash_table::Hash_table(){

}

void Hash_table::clear(){

}

Error_code Hash_table::insert(const Record &new_entry)
/* Post: 
    If the Hash_table is full, a code of overflow is returned. 
    If the table already contains an item with the key of new_entry a code of duplicate_error is returned.
    Otherwise: The Record new_entry is inserted into the Hash_table and success is returned.
    Uses: Methods for classes Key, and Record. The function hash. */
{
    Error_code result = success;
    int probe_count, // Counter to be sure that table is not full.
        increment,   // Increment used for quadratic probing.
        probe;       // Position currently probed in the hash table.
    Key null;        // Null key for comparison purposes.
    null.make_blank();
    probe = hash(new_entry);
    probe_count = 0;
    increment = 1;
    while (table[probe] != null         // Is the location empty?
           && table[probe] != new_entry // Duplicate key?
           && probe_count < (hash_size + 1) / 2)
    { // Has overflow occurred?
        probe_count++;
        probe = (probe + increment) % hash_size;
        increment += 2; // Prepare increment for next iteration.
    }
    if (table[probe] == null)
        table[probe] = new_entry; // Insert new entry.
    else if (table[probe] == new_entry)
        result = duplicate_error;
    else
        result = overflow; // The table is full.
    return result;
}