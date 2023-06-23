
// COS30008, Problem Set 3, 2023

#pragma once

#include "DoublyLinkedList.h"
#include "DoublyLinkedListIterator.h"

template<typename T>
class List
{
private:
    using Node = typename DoublyLinkedList<T>::Node;

    Node fHead;     // first element
    Node fTail;     // last element
    size_t fSize;   // number of elements

public:
    using Node = typename DoublyLinkedList<T>::Node;
    using Iterator = DoublyLinkedListIterator<T>;

    // Copy constructor.
    List() noexcept
        : fHead(nullptr),
        fTail(nullptr),
        fSize(0)
    {}

    // Copy constructor.
    List(const List& aOther)
        : fHead(nullptr),
        fTail(nullptr),
        fSize(0)
    {
        for (auto& element : aOther) {
            push_back(element);
        }
    }

    // Copy assignment operator.
    List& operator=(const List& aOther) {
        if (this != &aOther) {
            List tmp(aOther);
            swap(tmp);
        }
        return *this;
    }

    // Move constructor.
    List(List&& aOther) noexcept
        : fHead(std::move(aOther.fHead)),
        fTail(std::move(aOther.fTail)),
        fSize(aOther.fSize)
    {
        aOther.fSize = 0;
        aOther.fHead = nullptr;
        aOther.fTail = nullptr;
    }

    // Move assignment operator.
    List& operator=(List&& aOther) noexcept {
        if (this != &aOther) {
            List tmp(std::move(aOther));
            swap(tmp);
        }
        return *this;
    }

    void swap(List& aOther) noexcept {
        std::swap(fHead, aOther.fHead);
        std::swap(fTail, aOther.fTail);
        std::swap(fSize, aOther.fSize);
    }

    size_t size() const noexcept {
        return fSize;
    }

    void push_front(const T& data) {
        Node newNode = DoublyLinkedList<T>::makeNode(data);
        newNode->fNext = fHead;

        if (fHead) {
            fHead->fPrevious = newNode;
        }
        fHead = newNode;
        if (!fTail) {
            fTail = fHead;
        }
        fSize++;
    }

    void push_back(const T& data) {
        Node newNode = DoublyLinkedList<T>::makeNode(data);
        newNode->fPrevious = fTail;

        if (fTail) {
            fTail->fNext = newNode;
        }
        fTail = newNode;
        if (!fHead) {
            fHead = fTail;
        }
        fSize++;
    }

    void remove(const T& element) noexcept {
        Node lCurrent = fHead;
        while (lCurrent) {
            if (lCurrent->fData == element) {
                if (lCurrent->fPrevious.lock()) {
                    lCurrent->fPrevious.lock()->fNext = lCurrent->fNext;
                }
                else {
                    fHead = lCurrent->fNext;
                }

                if (lCurrent->fNext) {
                    lCurrent->fNext->fPrevious = lCurrent->fPrevious;
                }
                else {
                    fTail = lCurrent->fPrevious.lock();
                }
                lCurrent->isolate();
                fSize--;
                break;
            }
            lCurrent = lCurrent->fNext;
        }
    }

    const T& operator[](size_t index) const {
        Node lCurrent = fHead;
        while (index > 0) {
            lCurrent = lCurrent->fNext;
            index--;
        }
        return lCurrent->fData;
    }

    // iterator interface
    Iterator begin() const noexcept {
        return Iterator(fHead, fTail);
    }

    Iterator end() const noexcept {
        return Iterator(fHead, fTail).end();
    }

    Iterator rbegin() const noexcept {
        return Iterator(fTail, fHead);
    }

    Iterator rend() const noexcept {
        return Iterator(fHead, fTail).rend();
    }
};