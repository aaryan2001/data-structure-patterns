#pragma once
#include <memory>
#include <cassert>
#include <algorithm>

template<typename T>
class TernaryTree {
public:
    using Node = std::unique_ptr<TernaryTree>;

    TernaryTree(const T& aKey = T{}) noexcept : fKey(aKey) {}

    TernaryTree(T&& aKey) noexcept : fKey(std::move(aKey)) {}

    template<typename... Args>
    static Node makeNode(Args&&... args) {
        return std::make_unique<TernaryTree>(std::forward<Args>(args)...);
    }

    const T& operator*() const noexcept {
        return fKey;
    }

    TernaryTree& operator[](size_t aIndex) const {
        assert(aIndex < 3);
        assert(fNodes[aIndex]);
        return *fNodes[aIndex];
    }
    TernaryTree& operator[](size_t aIndex) const {
        assert(aIndex < 3);
        assert(fNodes[aIndex]);
        return *fNodes[aIndex];
    }

    void add(size_t aIndex, Node& aNode) {
        assert(aIndex < 3);
        fNodes[aIndex] = std::move(aNode);
    }

    Node remove(size_t aIndex) {
        assert(aIndex < 3);
        return std::move(fNodes[aIndex]);
    }

    bool leaf() const noexcept {
        for (const auto& node : fNodes) {
            if (node) return false;
        }
        return true;
    }

    size_t height() const noexcept {
        size_t max_height = 0;
        for (const auto& node : fNodes)
        {
            if (node != nullptr)
            {
                max_height = std::max(max_height, 1 + node->height());
            }
        }
        return max_height;
    }

private:
    T fKey;
    Node fNodes[3];
};