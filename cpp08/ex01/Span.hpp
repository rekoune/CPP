# ifndef SPAN_HPP
# define SPAN_HPP

# include <vector>
# include <iostream>
# include <exception>

class Span {
    private:
        std::vector<int> container;
        size_t size;
        size_t spaceLeft;
        Span();
    public :
        Span(unsigned int N);
        Span(const Span& original);
        ~Span();
        Span& operator=(const Span& original);
        void addNumber(size_t N);
        size_t getSize() const;
        size_t getSpaceLeft() const;
        std::vector<int> getContainer() const;
        void    spanElements( void );
        class CapacityException;
        class NotFoundException;
        size_t shortestSpan ( void );
        size_t longestSpan ( void );

        template <typename T>
        void copyRange(T start, T end){
            size_t size = std::distance(start, end);
            if( size > spaceLeft){
                end = start;
                std::advance(end, spaceLeft);
            }
            for(; start != end; start++)
                this->container.push_back(*start);
        }
};

class Span::CapacityException : public std::exception{
    public: 
        const char* what () const throw();
};
class Span::NotFoundException : public std::exception{
    public: 
        const char* what () const throw();
};

# endif