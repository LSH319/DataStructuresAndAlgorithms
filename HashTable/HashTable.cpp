#include <iostream>
#include <vector>

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

        auto& hash_row = *data_[hash];
        for(const auto& hash_element : hash_row)
        {
            if(hash_element->first == key)
            {
                hash_element->second = value;
                return;
            }
        }

        hash_row.push_back(new pair<int,int>(key, value));
    }

    int get_element(const int key) const
    {
        const int hash = hash_function(key);
        if(data_[hash] == nullptr) return -999;
        const auto& hash_row = *data_[hash];
        for(auto& hash_element : hash_row)
        {
            if(hash_element->first == key)
            {
                return hash_element->second;
            }
        }
        return 0;
    }

    void remove_element(const int key) const
    {
        const int hash = hash_function(key);
        
        auto& hash_row = *data_[hash];
        for(const auto& hash_element : hash_row)
        {
            int index = 0;
            if(hash_element->first == key)
            {
                delete hash_element;
                hash_row.erase(hash_row.begin() + index);
                return;
            }
            index++;
        }
    }

    void print_table() const
    {
        for(int i = 0; i < data_.size(); i++)
        {
            cout << i <<"\n";
            if(data_[i] == nullptr)
            {
                cout << "----------------------------------" <<"\n";
                continue;
            }
            const auto hash_row = *data_[i];
            for(auto& hash_element : hash_row)
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
    hash_table table(3);
 
    table.insert_element(0,0);
    table.insert_element(6,8);
    table.insert_element(6,7);
    table.insert_element(1,1);
    table.insert_element(2,2);
    table.insert_element(12,21);
    table.remove_element(0);
    
    table.print_table();

    return 0;
}