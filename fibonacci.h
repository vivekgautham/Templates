
#ifndef FIBO
#define FIBO

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







#endif
