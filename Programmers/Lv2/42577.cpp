#include <string>
#include <vector>
#include <unordered_set>
#include <memory>
#include <iostream>

using namespace std;

struct TrieNode
{    
private:
    unique_ptr<array<unique_ptr<TrieNode>, 10>> next = make_unique<array<unique_ptr<TrieNode>, 10>>();
    bool endNode = true;
 
public:
    TrieNode() {};
    
    void append(int n)
    {
        if (next->at(n) == nullptr)
        {
            next->at(n) = make_unique<TrieNode>();
            endNode = false;
        }
    }
    
    bool query(int n)
    {
        return !(next->at(n) == nullptr);
    }
    
    TrieNode* getNext(int n)
    {
        return next->at(n).get();
    }
    
    bool isEnd()
    {
        return endNode;
    }
};

bool solution(vector<string> phone_book)
{
    auto root = make_unique<TrieNode>();
    
    for (string phone : phone_book)
    {
        auto now = root.get();
        
        for (int i = 0; i < phone.size(); i++)
        {
            int n = phone[i] - '0';
            
            if (now->query(n))
            {
                now = now->getNext(n);
                
                if (now->isEnd() || i == phone.size() - 1)
                    return false;
            }
            else
            {
                now->append(n);
                now = now->getNext(n);
            }
        }
    }
    
    return true;
}

/*
bool solution(vector<string> phone_book)
{
    unordered_set<string> prefixes(phone_book.begin(), phone_book.end());
    
    for (string phoneNumber : phone_book)
    {
        prefixes.erase(prefixes.find(phoneNumber));
        for (int i = 1; i <= phoneNumber.size(); i++)
        {
            string nowPrefix = string(phoneNumber, 0, i);
            
            if (prefixes.find(string(phoneNumber, 0, i)) != prefixes.end())
            {
                return false;
            }
        }
        prefixes.insert(phoneNumber);
    }
    
    return true;
}
*/