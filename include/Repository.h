#pragma once
#include <map>
#include <vector>
#include <string>

// C++ Template Requirement
template <typename T>
class Repository {
private:
    // STL Requirement: std::map
    std::map<std::string, T> database;

public:
    void save(const std::string& id, const T& item) {
        database[id] = item;
    }

    T get(const std::string& id) {
        return database[id];
    }

    bool exists(const std::string& id) const {
        return database.find(id) != database.end();
    }

    std::vector<T> getAll() const {
        std::vector<T> items;
        for (const auto& pair : database) {
            items.push_back(pair.second);
        }
        return items;
    }
    
    size_t size() const {
        return database.size();
    }
};