// include/Repository.h
#pragma once
#include <iostream>
#include <map>
#include <vector>
#include <string>

// This is the Template! Notice the <typename T>
template <typename T>
class Repository {
private:
    // We use std::map (STL) to store items using a string ID as the key
    std::map<std::string, T> database;

public:
    // Add or update an item
    void save(const std::string& id, const T& item) {
        database[id] = item;
    }

    // Retrieve an item by ID
    T get(const std::string& id) {
        return database[id];
    }

    // Check if an item exists
    bool exists(const std::string& id) const {
        return database.find(id) != database.end();
    }

    // Get all items (returns a vector - STL)
    std::vector<T> getAll() const {
        std::vector<T> items;
        for (const auto& pair : database) {
            items.push_back(pair.second);
        }
        return items;
    }
    
    // Get the total number of items
    size_t size() const {
        return database.size();
    }
};