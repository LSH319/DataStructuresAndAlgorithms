#include <iostream>
#include <vector>
#include <random>

using namespace std;

class hash_table {
    vector<vector<pair<int, int>*>*> data_;

public:
    explicit hash_table(int HashSize)
    {
        if(HashSize == 0) HashSize=1;
        data_.resize(HashSize);
    }

    void insert_element(const int key, const int value)
    {
        const int hash = hash_function(key);

        if(data_[hash] == nullptr)
        {
            data_[hash] = new vector<pair<int, int>*>;
        }

        vector<pair<int, int>*> &hash_row = *data_[hash];
        for(pair<int, int>* &hash_element : hash_row)
        {
            if(hash_element->first == key)
            {
                hash_element->second = value;
                return;
            }
        }
        data_[hash]->push_back(new pair<int, int>(key, value));
    }

    int get_element(const int key) const
    {
        const int hash = hash_function(key);
        if(data_[hash] == nullptr) return -999;
        vector<pair<int, int>*> &hash_row = *data_[hash];
        for(pair<int, int>* &hash_element : hash_row)
        {
            if(hash_element->first == key)
            {
                return hash_element->second;
            }
        }
        return 0;
    }

    void remove_element(const int key)
    {
        const int hash = hash_function(key);
        if (data_[hash] == nullptr) return;

        vector<pair<int, int>*> &hash_row = *data_[hash];
        for (int i = 0; i < hash_row.size(); i++) {
            if (hash_row[i]->first == key)
            {
                delete hash_row[i];
                hash_row[i] = nullptr;
                hash_row.erase(hash_row.begin() + i);
                break;
            }
        }

        if (data_[hash]->empty()) {
            delete data_[hash];
            data_[hash] = nullptr;
        }
    }

    vector<int> get_keys() {
        vector<int> keys;
        for (int i = 0; i < data_.size(); i++)
        {
            if (data_[i] == nullptr)
            {
                continue;
            }
            vector<pair<int, int>*> &hash_row = *data_[i];
            for (pair<int, int>* &hash_element : hash_row)
            {
                keys.push_back(hash_element->first);
            }
        }
        return keys;
    }
    void print_table() const
    {
        for(int i = 0; i < data_.size(); i++)
        {
            if(data_[i] == nullptr)
            {
                continue;
            }
            cout << i << "\n";
            vector<pair<int, int>*> &hash_row = *data_[i];
            for(pair<int, int>* &hash_element : hash_row)
            {
                cout << "key : "<< hash_element->first << " / value : "<< hash_element->second << "\n";
            }
            cout << "----------------------------------" <<"\n";
        }
    }

private:
    int hash_function(const int key) const
    {
        return key % data_.size();
    }
};

// https://www.cs.usfca.edu/~galles/visualization/OpenHash.html Âü°í
int main(int argc, char* argv[])
{
    hash_table table(100);
    std::random_device rd;
    std::mt19937 mt(rd());
    std::uniform_int_distribution<int> dist(0, 500);
    
   while(1) {
        const int key = dist(mt);
        const int value = dist(mt);
        const int remove_key = dist(mt);
        table.insert_element(key, value);
        table.remove_element(remove_key);
        table.print_table();
    }
    
    

    return 0;
}