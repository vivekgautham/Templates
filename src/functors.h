#ifndef FUNCTORS_H
#define FUNCTORS_H

template <typename ElemType>
struct CountConsecutive
{   
    private:
        unsigned count;
    public:
        CountConsecutive(unsigned count): count(count)
        {

        }
        unsigned getCount(){
            return count;
        }

        void operator() (ElemType e1, ElemType e2)
        {
            if (e1+1 == e2) 
            {
                count++;
            }
        }
};

template <typename ElemType>
struct SumProduct
{   
    private:
        unsigned sumProd;
    public:
        SumProduct(unsigned sumProd): sumProd(sumProd)
        {

        }
        unsigned getSumProd(){
            return sumProd;
        }

        void operator() (ElemType e1, ElemType e2)
        {
            sumProd += e1*e2;
        }
};


#endif