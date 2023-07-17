// A Hashmap is another type of data structure in which the time complexity of insertion, deletion and searching is very optimal.
#include <iostream>
#include <map>
#include <unordered_map>
#include <string>
using namespace std;

int main(){
    // Creation
    unordered_map <string, int> m;

    // Insertion: 3 Ways
    // 1
    pair<string, int> p1 = make_pair("My", 1);
    m.insert(p1);
    // 2
    pair<string, int> p2("Gupta", 2);
    m.insert(p2);
    // 3
    m["name"] = 1;

    // Search
    cout<<m["My"]<<"\n";
    cout<<m.at("My")<<"\n";
    // If the key is not present in the map, then m["key"] and m.at("key") return 0. But if m.at("key") is called before m["key"], then it gives a not found error, because in m["key"], a new key is initialized.
    // cout<<m.at("key")<<"\n"; --> Gives error
    // cout<<m["key"]<<"\n";
    cout<<m["key"]<<"\n";
    cout<<m.at("key")<<"\n";

    // Size
    cout<<m.size()<<"\n";

    // To check presence of a key
    cout<<m.count("newKey")<<"\n"; // Note, if the key is present, it returns 1, i.e., the count of "key" in that map.

    // Erase
    m.erase("Gupta");
    cout<<m.size()<<"\n";

    // Ways to print the map
    // 1
    for(auto i: m) cout<<i.first<<" "<<i.second<<"\n";
    // 2: using iterator
    unordered_map<string, int> :: iterator it = m.begin();
    while(it!=m.end())
    cout<<it->first<<" "<<it->second<<"\n";
    return 0;
}
// BUCKET ARRAY: It is the array that stores our values on their respected keys in a map. The inputs are matched with the keys using hash conversions.
// HASH FUNCTIONS: Functions that perform the hash conversions, i.e., conversion of input (string, char, int, etc) to index of the bucket array (integer).
// HASH CODE: The code inside Hash Function, using which hash conversion takes place. The Hash Code returns an integer and the compression function reduces it into the range of the bucket array. It should fulfil two main responsibilities, first is conversion to int and second is uniform distribution (different inputs should have different indexes). It may be any conversion function like adding all the characters of the string, or multiplying and adding them, etc.
// COLLISION AND ITS HANDLING: When the hash code gives same output for two different inputs, it is called collision. It can be handled in two ways: 1. Open Hashing   2. Closed Addressing
// OPEN HASHING: In this method, the repeated output is stored at the same index using a LinkedList. The corresponding array index stores the head of that LinkedList. It is also called separate chaining.
// CLOSED ADDRESSING: In this method, if the key is already occupied, take the next available key, which is calculated using a function of the form  H(a)=h(a)+Fi(a). It has a few subtypes depending on how Fi works. For instance, Fi(i)=i (Linear Probing) or Fi(i)=i^2 (Quadratic Probing), and using this equation the next available key is calculated.
// TIME COMPLEXITY ANALYSIS: If the no. of inputs are n and the average size of an input is k, then the time complexity of the Hash Code should be O(k), but practically n>>k, therefore O(k) is approximated to O(1) and this way hash maps become very optimal.
// HashMaps have a load factor (n/b), where b=>bucket size, which should be kept below 0.7 for hassle free hashing. If n (no. of inputs) increases, then the size of the bucket is also increased (double usually) to adjust the load factor.