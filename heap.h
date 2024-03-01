#ifndef HEAP_H
#define HEAP_H
#include <functional>
#include <stdexcept>
#include <vector>

template <typename T, typename PComparator = std::less<T> >
class Heap : private std::vector<T>
{
public:
  /**
   * @brief Construct a new Heap object
   * 
   * @param m ary-ness of heap tree (default to 2)
   * @param c binary predicate function/functor that takes two items
   *          as an argument and returns a bool if the first argument has
   *          priority over the second.
   */
  Heap(int m=2, PComparator c = PComparator()) : comparer(c), d_ary(m) {
    T holder;
    std::vector<T>::push_back(holder);       
  }

  /**
  * @brief Destroy the Heap object
  * 
  */
  ~Heap(){}

  /**
   * @brief Push an item to the heap
   * 
   * @param item item to heap
   */
  void push(const T& item);

  /**
   * @brief Returns the top (priority) item
   * 
   * @return T const& top priority item
   * @throw std::underflow_error if the heap is empty
   */
  T const & top() const;

  /**
   * @brief Remove the top priority item
   * 
   * @throw std::underflow_error if the heap is empty
   */
  void pop();

  /// returns true if the heap is empty

  /**
   * @brief Returns true if the heap is empty
   * 
   */
  bool empty() const;

    /**
   * @brief Returns size of the heap
   * 
   */
  size_t size() const;

private:
  /// Add whatever helper functions and data members you need below 
    int d_ary;
    PComparator comparer;
    void heapify(int idx);
    void trickleUp(int loc);
    bool is_leaf(int idx)
    {

    }

};

// template <typename T, typename PComparator>
// Heap<T,PComparator>::Heap(int m=2, PComparator c = PComparator()){}

// template <typename T, typename PComparator>
// Heap<T,PComparator>::~Heap(){}

// Add implementation of member functions here
template <typename T, typename PComparator>
void Heap<T,PComparator>::trickleUp(int loc)
{
    // could be implemented recursively
    int parent = (loc - 2)/d_ary + 1;
    while(parent >= 1 && comparer(std::vector<T>::at(loc), std::vector<T>::at(parent))) { 
        T temp = std::vector<T>::at(parent);
        std::vector<T>::at(parent) = std::vector<T>::at(loc);
        std::vector<T>::at(loc) = temp;

        loc = parent;
        parent = (loc - 2)/d_ary + 1;
    }

}


template <typename T, typename PComparator>
void Heap<T,PComparator>::heapify(int idx)
{
    // for(int i = 1; i < std::vector<T>::size(); i++) {
    //     std::cout << std::vector<T>::at(i) << " ";
    // }
    // std::cout << "\n";
    
    if(d_ary * idx + 2 - d_ary > size()|| size() == 1){ return;}

    int bestChild = d_ary * idx + 2 - d_ary; // start w/ left
    int nextChild = bestChild + 1;

    // std::cout << "Best: " << bestChild << ", Next: " << nextChild << "\n";

    while((bestChild - 2)/d_ary + 1 == (nextChild - 2)/d_ary + 1 && nextChild <= std::vector<T>::size() - 1) {
        // std::cout << "Test\n";
        if(comparer(std::vector<T>::at(nextChild), std::vector<T>::at(bestChild))) {
            bestChild = nextChild;
        }
        nextChild++;
    }

    // std::cout << "Best: " << bestChild << ", Next: " << nextChild << "\n";



    if(comparer(std::vector<T>::at(bestChild), std::vector<T>::at(idx))){ // questionable
        T temp = std::vector<T>::at(idx);
        std::vector<T>::at(idx) =  std::vector<T>::at(bestChild);
        std::vector<T>::at(bestChild) = temp;
        heapify(bestChild);
    }
}

template <typename T, typename PComparator>
void Heap<T,PComparator>::push(const T& item) 
{

    std::vector<T>::push_back(item);
    trickleUp(std::vector<T>::size()-1);
    // for(int i = 1; i < std::vector<T>::size(); i++) {
    //     std::cout << std::vector<T>::at(i) << " ";
    // }
    // std::cout << "\n";
    
}

template <typename T, typename PComparator>
bool Heap<T,PComparator>::empty() const
{
    return (std::vector<T>::size() == 1);
}

template <typename T, typename PComparator>
size_t Heap<T,PComparator>::size() const
{
    return std::vector<T>::size() - 1;
}



// We will start top() for you to handle the case of 
// calling top on an empty heap
template <typename T, typename PComparator>
T const & Heap<T,PComparator>::top() const
{
  // Here we use exceptions to handle the case of trying
  // to access the top element of an empty heap
  if(empty()){
    // ================================
    // throw the appropriate exception
    // ================================
    throw std::underflow_error("Cannot get top of empty list");
  }
  // If we get here we know the heap has at least 1 item
  // Add code to return the top element
    return std::vector<T>::at(1);


}


// We will start pop() for you to handle the case of 
// calling top on an empty heap
template <typename T, typename PComparator>
void Heap<T,PComparator>::pop()
{
    if(empty()){
        // ================================
        // throw the appropriate exception
        // ================================
        throw std::underflow_error("Cannot pop empty list");
    } else {
        std::vector<T>::at(1) = std::vector<T>::back();
        std::vector<T>::pop_back();
        // std::cout << std::vector<T>::size()<< "\n";
        heapify(1);
    }

}



#endif;

