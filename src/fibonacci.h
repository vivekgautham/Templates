
#ifndef FIBO_H
#define FIBO_H

template <typename Int, typename Plus = std::plus<Int>, typename Minus = std::minus<Int> >

class FibonacciIterator : public std::iterator<std::bidirectional_iterator_tag, const Int>

{
public:		
	explicit FibonacciIterator(
			Int zero = Int(0),
			Int one = Int(1),
			Plus p = Plus(),
			Minus m = Minus()
		);

	const Int& operator* () const;
	const Int* operator-> () const;

	FibonacciIterator& operator++ ();
	const FibonacciIterator operator++ (int);

	FibonacciIterator& operator-- ();
	const FibonacciIterator operator-- (int);


private:
	Int curr, next;

	Plus plus;
	Minus minus;

};


template <typename Int, typename Plus, typename Minus>
bool operator== (const FibonacciIterator<Int, Plus, Minus>& lhs, 
		 const FibonacciIterator<Int, Plus, Minus>& rhs);

template <typename Int, typename Plus, typename Minus>
bool operator!= (const FibonacciIterator<Int, Plus, Minus>& lhs,
		 const FibonacciIterator<Int, Plus, Minus>& rhs);

template <typename Int, typename Plus, typename Minus>
FibonacciIterator<Int,Plus, Minus>::FibonacciIterator(Int zero,
						      Int one,
						      Plus plus,
						      Minus minus)
	: curr(zero), next(one), plus(plus), minus(minus) {

}


template <typename Int, typename Plus, typename Minus>
const Int& FibonacciIterator<Int, Plus, Minus>::operator* () const {
	return curr;
}

template <typename Int, typename Plus, typename Minus>
const Int* FibonacciIterator<Int, Plus, Minus>::operator-> () const {
	return &**this;
}

template <typename Int, typename Plus, typename Minus>
FibonacciIterator<Int, Plus, Minus>&
FibonacciIterator<Int, Plus, Minus>::operator++ () {
	Int newNext = plus(curr, next);
	curr = next;
	next = newNext;
	return *this;
}

template <typename Int, typename Plus, typename Minus>
const FibonacciIterator<Int, Plus, Minus>
FibonacciIterator<Int, Plus, Minus>::operator++ (int) {
	FibonacciIterator result = *this;
	++ *this;
	return result;
}

template <typename Int, typename Plus, typename Minus>
FibonacciIterator<Int, Plus, Minus>&
FibonacciIterator<Int, Plus, Minus>::operator-- () {
	Int prev = minus(next, curr);
	next = curr;
	curr = prev;
	return *this;
}

template <typename Int, typename Plus, typename Minus>
const FibonacciIterator<Int, Plus, Minus>
FibonacciIterator<Int, Plus, Minus>::operator-- (int) {
	FibonacciIterator result = *this;
	-- *this;
	return result;
}

template <typename Int, typename Plus, typename Minus>
bool operator== (const FibonacciIterator<Int, Plus, Minus>& lhs,
		const FibonacciIterator<Int, Plus, Minus>& rhs) {
	return lhs.curr == rhs.curr && lhs.next == rhs.next;
}

template <typename Int, typename Plus, typename Minus>
bool operator!= (const FibonacciIterator<Int, Plus, Minus>& lhs,
		const FibonacciIterator<Int, Plus, Minus>& rhs) {
	return !(lhs == rhs);
}



#endif
