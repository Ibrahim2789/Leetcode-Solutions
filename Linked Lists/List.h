#pragma once

template <typename T>
class List {
    public:
        const T & operator[](unsigned index);
        void insertAtFront(const T & data);

    private:
        class ListNode{
            public:
                const T & data;
                ListNode *next;
                ListNode(const T & data) : data(data), next(nullptr){}
        };

        ListNode *head_;
};