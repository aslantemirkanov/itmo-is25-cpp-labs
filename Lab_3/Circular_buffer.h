#ifndef CIRCULAR_BUFFER_CIRCULAR_BUFFER_H
#define CIRCULAR_BUFFER_CIRCULAR_BUFFER_H

template<typename T>
class Iterator;

template<typename T>
class circular_buffer {
private:
    T* data = nullptr;
    size_t capacity = 0;
    size_t size = 0;
    size_t start = 0;
    size_t finish = 0;
public:
    //constructor
    explicit circular_buffer(size_t capacity)
            : capacity(capacity)
            , data(new T[capacity])
            , size(0)
            , start(0)
            , finish(0)
    {}

    [[nodiscard]] size_t get_size() const{
        return size;
    }

    [[nodiscard]] size_t get_capacity() const{
        return capacity;
    }

    friend Iterator<T>;

    Iterator<T> begin(){
        Iterator<T>copy(this, data + start);
        copy.is_begin = true;
        return copy;
    }

    Iterator<T> end(){
        Iterator<T>copy(this, data + start);
        copy.is_end = true;
        return copy;
    }

    //copy constructor
    circular_buffer( circular_buffer<T>& other)
        : data(new T[other.capacity])
        , capacity(other.capacity)
        , size(other.size)
        , start(other.start)
        , finish(other.finish)
    {
        for (size_t i = 0; i < capacity; ++i){
            data[i] = other.data[i];
        }
    }

    circular_buffer<T>& operator=(const circular_buffer<T>& other){
        if (&other == this){
            return *this;
        }
        size = other.size;
        start = other.start;
        finish = other.finish;
        capacity = other.capacity;
        T* new_data = new T[capacity];
        for(int i = 0; i < capacity; ++i){
            new_data[i] = other.data[i];
        }
        delete[] data;
        data = new_data;
        return *this;
    }

    T& operator[](int n){
        n %= size;
        T& current = *(data + (start + n) % capacity);
        return current;
    }

    //input in finish
    void push_back(const T& for_input){
        if (size + 1 >= capacity){
            size = capacity;
            data[finish] = for_input;
            finish = (finish + 1) % capacity;
            start = finish;
        } else{
            size++;
            data[finish] = for_input;
            finish = (finish + 1) % capacity;
        }
    }
    
    void pop_back(){
        size--;
        finish = (capacity + finish - 1) % capacity;
        data[finish] = 0;
        if (finish == start){
            start = (capacity + start - 1) % capacity;
        }
    }

    //input in start
    void push_front(const T& for_input){
        if (size + 1 > capacity){
            size = capacity;
            finish = (capacity + finish - 1) % capacity;
            start = finish;
            data[start] = for_input;
        }
        else{
            size++;
            start = (capacity + start - 1) % capacity;
            data[start] = for_input;
        }
    }

    void pop_front(){
        size--;
        data[start] = 0;
        start = (start + 1) % capacity;
        if (start == finish){
            finish = (finish + 1) % capacity;
        }
    }

    void resize(size_t new_capacity){
        size_t tmp_size = std::min(size, new_capacity);
        T* new_data = new T[new_capacity];
        size_t index = 0;
        while(index < tmp_size){
            new_data[index] = *(data + (start + index) % capacity);
            ++index;
        }
        delete[] data;
        capacity = new_capacity;
        size = tmp_size;
        start = 0;
        data = new_data;
        finish = size;
    }

    ~circular_buffer(){
        delete[] data;
    }
};

template<typename T>
class Iterator{
private:
    T *first;
    T *current;
    int start_it;
    int cur_index;
    size_t size_it;
    size_t capacity;
public:
    bool is_end = false;
    bool is_begin = false;
    using iterator_category = std::random_access_iterator_tag;
    using difference_type = std::ptrdiff_t;
    using value_type = T;
    using pointer = T*;
    using reference = T &;

    explicit Iterator(circular_buffer<T>* buffer, pointer element)
            : start_it(buffer->start)
            , first(buffer->data)
            , size_it(buffer->size)
            , capacity(buffer->capacity)
            , current(element)
    {
        if (element >= (start_it + first)){
            cur_index = element - (start_it + first);
        }
        else {
            cur_index = capacity - (start_it + first - element);
        }
    }

    Iterator() = default;

    size_t get_index() const{
        return cur_index;
    }

    reference operator*() {
        return *current;
    }

    pointer operator->() {
        return current;
    }

    Iterator& operator=(const Iterator<T>& other){
        if (&other == this){
            return *this;
        }
        is_begin = other.is_begin;
        is_end = other.is_end;
        first = other.first;
        start_it = other.start_it;
        current = other.current;
        cur_index = other.cur_index;
        size_it = other.size_it;
        capacity = other.capacity;
        return *this;
    }

    friend bool operator==(const Iterator<T>& first_it, const Iterator<T>& second_it){
        bool ans = true;
        if (first_it.cur_index != second_it.cur_index) ans = false;
        if (first_it.is_begin && second_it.is_end || first_it.is_end && second_it.is_begin) ans = false;
        return ans;
    }

    friend bool operator!=(const Iterator<T>& first_it, const Iterator<T>& second_it){
        bool ans = false;
        if (first_it.cur_index != second_it.cur_index) ans = true;
        if (first_it.is_begin && second_it.is_end || first_it.is_end && second_it.is_begin) ans = true;
        return ans;
    }

    friend bool operator>(const Iterator<T>& first_it, const Iterator<T>& second_it){
        return first_it.cur_index > second_it.cur_index;
    }

    friend bool operator>=(const Iterator<T>& first_it, const Iterator<T>& second_it){
        return first_it.cur_index > second_it.cur_index || first_it.cur_index == second_it.cur_index;
    }

    friend bool operator<(const Iterator<T>& first_it, const Iterator<T>& second_it){
        return first_it.cur_index < second_it.cur_index;
    }

    friend bool operator<=(const Iterator<T>& first_it, const Iterator<T>& second_it){
        return first_it.cur_index <= second_it.cur_index || first_it.cur_index == second_it.cur_index;

    }

    Iterator<T> operator[](size_t n){
        n %= size_it;
        current = first + (start_it + n) % capacity;
        cur_index = n;
        return *this;
    };

    Iterator<T>& operator++(){
        cur_index = (cur_index + 1) % size_it;
        current = first + (start_it + cur_index) % capacity;
        if (is_begin && cur_index != start_it) is_begin = false;
        return *this;
    };

    Iterator<T> operator++(int){
        Iterator copy = *this;
        cur_index = (cur_index + 1) % size_it;
        current = first + (start_it + cur_index) % capacity;
        if (is_begin && cur_index != start_it) is_begin = false;
        return copy;
    };

    Iterator<T>& operator--(){
        cur_index = (size_it + cur_index - 1) % size_it;
        current = first + (start_it + cur_index) % capacity;
        if (is_begin && cur_index != start_it) is_begin = false;
        return *this;
    };

    Iterator<T> operator--(int){
        Iterator copy = *this;
        cur_index = (size_it + cur_index - 1) % size_it;
        current = first + (start_it + cur_index) % capacity;
        if (is_begin && cur_index != start_it) is_begin = false;
        return copy;
    };

    Iterator<T>& operator+=(int n){
        n %= size_it;
        cur_index = (size_it + cur_index + n) % size_it;
        current = first + (start_it + cur_index ) % capacity;
        if (is_begin && cur_index != start_it) is_begin = false;
        return *this;
    }

    Iterator<T>& operator-=(int n){
        n %= size_it;
        cur_index = (size_it + cur_index - n) % size_it;
        current = first + (start_it + cur_index) % capacity;
        if (is_begin && cur_index != start_it) is_begin = false;
        return *this;
    }

    friend int operator-(const Iterator<T>& first_it, const Iterator<T>& second_it){
        if (first_it.is_begin && second_it.is_end) return first_it.size_it;
        if (second_it.is_begin && first_it.is_end) return first_it.size_it;
        return first_it.cur_index - second_it.cur_index;
    }

    friend Iterator<T> operator+(const Iterator<T>& iter, int n){
        Iterator<T> copy;
        copy = iter;
        copy += n;
        return copy;
    }

    friend Iterator<T> operator+(int n, const Iterator<T>& iter){
        Iterator<T> copy;
        copy = iter;
        copy += n;
        return copy;
    }

    friend Iterator operator-(const Iterator<T>& iter, int n){
        Iterator<T> copy;
        copy = iter;
        copy -= n;
        return copy;
    }

};

#endif //CIRCULAR_BUFFER_CIRCULAR_BUFFER_H

