template <typename T>
LinkedQueue<T>::LinkedQueue() {
    // TODO

}

template <typename T>
LinkedQueue<T>::LinkedQueue(const LinkedQueue<T>& copyObj) {
    copy(copyObj);
}

template <typename T>
LinkedQueue<T>& LinkedQueue<T>::operator=(const LinkedQueue<T>& rightObj) {
    if (this != &rightObj) {
        clear();
        copy(rightObj);
    }
    return *this;
}

template <typename T>
LinkedQueue<T>::~LinkedQueue() {
    clear();
}

template <typename T>
T LinkedQueue<T>::back() const {
    // TODO
    if (head == nullptr) throw string ("error: Queue is empty. Nothing to return.");

    return tail->value;
}

template <typename T>
void LinkedQueue<T>::clear() {
    // TODO
    Node* cur = head;
    Node* temp = cur;

    while (cur != nullptr){
        cur = cur -> next;
        delete temp;
        temp = cur;
    }

    head = nullptr;
    tail = nullptr;
    this->length = 0;
}

template <typename T>
void LinkedQueue<T>::copy(const LinkedQueue<T>& copyObj) {
    // TODO
}

template <typename T>
void LinkedQueue<T>::dequeue() {
    // TODO
}

template <typename T>
void LinkedQueue<T>::enqueue(const T& elem) {
    // TODO
}

template <typename T>
T LinkedQueue<T>::front() const {
    // TODO
    if (head == nullptr) throw string ("error: Queue is empty. Nothing to return.");

    return head->value;
}

template <typename T>
int LinkedQueue<T>::getLength() const {
    return this->length;
}

template <typename T>
bool LinkedQueue<T>::isEmpty() const {
    return this->length == 0;
}
