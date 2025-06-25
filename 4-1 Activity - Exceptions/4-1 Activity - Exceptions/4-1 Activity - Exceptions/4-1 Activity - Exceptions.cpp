// 4-1 Activity - Exceptions.cpp : This file contains the 'main' function. Program execution begins and ends there.
// 
// Molly Vaughns
// SNHU - CS-405 Secure Coding - Joseph Kovacic
//

#include <iostream>

// Create custom exception
class CustomException : public std::exception {
public:
    const char* what() const noexcept override {
        return "Custom exception derived from std:: exception has been thrown.";
    }
};

bool do_even_more_custom_application_logic()
{
    // TODO: Throw any standard exception
    // Throw out of range C++ exception
    throw std::out_of_range("Out of range, throwing any standard C++ exception");

    std::cout << "Running Even More Custom Application Logic." << std::endl;

    return true;
}
void do_custom_application_logic()
{
    // TODO: Wrap the call to do_even_more_custom_application_logic()
    //  with an exception handler that catches std::exception, displays
    //  a message and the exception.what(), then continues processing
    
    // Create exception try-block to wrap code that can potentially throw exceptional errors
    try {
        std::cout << "Running Custom Application Logic." << std::endl;

        if (do_even_more_custom_application_logic())
        {
            std::cout << "Even More Custom Application Logic Succeeded." << std::endl;
        }
    }
    catch (const std::exception& ex) {
        std::cout << "Standard exception caught" << std::endl;
        std::cout << ex.what() << std::endl;
    }


    // TODO: Throw a custom exception derived from std::exception
    //  and catch it explictly in main
    throw CustomException();

    std::cout << "Leaving Custom Application Logic." << std::endl;

}

float divide(float num, float den)
{
    // TODO: Throw an exception to deal with divide by zero errors using
    //  a standard C++ defined exception
    if (den == 0)
    {
        throw std::invalid_argument("Invalid argument, unable to divide by zero");
    }
    
    return (num / den);
}

void do_division() noexcept
{
    //  TODO: create an exception handler to capture ONLY the exception thrown
    //  by divide.
    try {
        float numerator = 10.0f;
        float denominator = 0;

        auto result = divide(numerator, denominator);
        std::cout << "divide(" << numerator << ", " << denominator << ") = " << result << std::endl;
    }
    catch (const std::invalid_argument& ex) {
        std::cout << ex.what() << std::endl;
    }
}

int main()
{
    std::cout << "Exceptions Tests!" << std::endl;

    // TODO: Create exception handlers that catch (in this order):
    //  your custom exception
    //  std::exception
    //  uncaught exception 
    //  that wraps the whole main function, and displays a message to the console.
    try {
        do_division();
        do_custom_application_logic();
    }
    // Catch custom exception derived from standard exception
    catch (const CustomException& ex) {
        std::cout << ex.what() << std::endl;
    }
    // Catch any standard exception
    catch (const std::exception& ex) {
        std::cout << ex.what() << std::endl;
    }
    // Catch any uncaught exceptions
    catch (...) {
        std::cout << "An exception has been caught" << std::endl;
    }
    
}

// Run program: Ctrl + F5 or Debug > Start Without Debugging menu
// Debug program: F5 or Debug > Start Debugging menu