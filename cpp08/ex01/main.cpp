# include "Span.hpp"

int main()
{
        std::cout << "=== Basic test ===" << std::endl;
        Span sp = Span(5);
        sp.addNumber(6);
        sp.addNumber(3);
        sp.addNumber(17);
        sp.addNumber(9);
        sp.addNumber(11);

        std::cout << "Shortest span: " << sp.shortestSpan() << std::endl;
        std::cout << "Longest span: " << sp.longestSpan() << std::endl;

        std::cout << std::endl << "=== Exception test: adding beyond capacity ===" << std::endl;
        try
        {
            sp.addNumber(42);
        }
        catch (std::exception& e)
        {
            std::cerr << e.what() << std::endl;
        }

        std::cout << std::endl << "=== Range insertion test ===" << std::endl;
        Span bigSpan(10000);
        std::vector<int> v;
        for (int i = 0; i < 10000; ++i)
            v.push_back(i * 2);
        bigSpan.copyRange(v.begin(), v.end());
        std::cout << "Shortest span: " << bigSpan.shortestSpan() << std::endl;
        std::cout << "Longest span: " << bigSpan.longestSpan() << std::endl;

        std::cout << std::endl << "=== Exception test: not enough elements ===" << std::endl;
        Span smallSpan(2);
        smallSpan.addNumber(1);
        try
        {
            std::cout << smallSpan.shortestSpan() << std::endl;
        }
        catch (std::exception& e)
        {
            std::cerr << e.what() << std::endl;
        }
}
