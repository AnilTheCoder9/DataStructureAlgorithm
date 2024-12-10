#pragma once
#include <iostream>

class SinglyLinkedList
{
private:
    class Node
    {
    public:
        int m_value;
        Node* next;

        // Parameterized constructor
        Node(int value) : m_value(value), next(nullptr) {}
    };

    Node* m_head;

public:
    // Default constructor
    SinglyLinkedList() : m_head(nullptr) {}

    // Parameterized constructor
    SinglyLinkedList(int value) : m_head(new Node(value)) {}

    // Insert element at the start of linked list
    void InsertElementAtStart(int value);

    // Insert element at the end of linked list
    void InsertElementAtEnd(int value);

    // Delete element from linked list
    void DeleteElement(int value);

    // Traverse the linked list
    void Traverse() const;

    // Delete first node
    void DeleteFirstNode();

    // Delete last node
    void DeleteEndNode();

    // Delete node after given node
    void DeleteNodeAfterGivenNode(int key);

    // Destructor
    ~SinglyLinkedList();
};

//-----------------------------------------------------------------------------
// Insert at the start
void SinglyLinkedList::InsertElementAtStart(int value)
{
    Node* node = new Node(value);
    node->next = m_head;
    m_head = node;
}

//-----------------------------------------------------------------------------
// Insert at the end
void SinglyLinkedList::InsertElementAtEnd(int value)
{
    Node* node = new Node(value);
    if (!m_head)
    {
        m_head = node;
        return;
    }
    Node* current = m_head;
    while (current->next)
    {
        current = current->next;
    }
    current->next = node;
}

//-----------------------------------------------------------------------------
// Delete element by value
void SinglyLinkedList::DeleteElement(int value)
{
    if (!m_head) return;

    if (m_head->m_value == value)
    {
        Node* temp = m_head;
        m_head = m_head->next;
        delete temp;
        return;
    }

    Node* current = m_head;
    while (current->next && current->next->m_value != value)
    {
        current = current->next;
    }

    if (current->next)
    {
        Node* temp = current->next;
        current->next = current->next->next;
        delete temp;
    }
}

//-----------------------------------------------------------------------------
// Traverse
void SinglyLinkedList::Traverse() const
{
    Node* current = m_head;
    while (current)
    {
        std::cout << current->m_value << " ";
        current = current->next;
    }
    std::cout << std::endl;
}

//-----------------------------------------------------------------------------
// Delete first node
void SinglyLinkedList::DeleteFirstNode()
{
    if (!m_head) return;

    Node* temp = m_head;
    m_head = m_head->next;
    delete temp;
}

//-----------------------------------------------------------------------------
// Delete last node
void SinglyLinkedList::DeleteEndNode()
{
    if (!m_head) return;

    if (!m_head->next)
    {
        delete m_head;
        m_head = nullptr;
        return;
    }

    Node* current = m_head;
    while (current->next && current->next->next)
    {
        current = current->next;
    }

    delete current->next;
    current->next = nullptr;
}

//-----------------------------------------------------------------------------
// Delete node after a given node
void SinglyLinkedList::DeleteNodeAfterGivenNode(int key)
{
    Node* current = m_head;

    while (current && current->m_value != key)
    {
        current = current->next;
    }

    if (current && current->next)
    {
        Node* temp = current->next;
        current->next = current->next->next;
        delete temp;
    }
}

//-----------------------------------------------------------------------------
// Destructor
SinglyLinkedList::~SinglyLinkedList()
{
    while (m_head)
    {
        Node* temp = m_head;
        m_head = m_head->next;
        delete temp;
    }
}
