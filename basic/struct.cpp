# include <iostream>
# include <string>

#define Conn(x,y) x##y

// #define ToChar(x) #@x

#define ToString(x) #x

struct Book
{
    std::string title;
    std::string author;
    std::string subject;
    int book_id;
};

std::ostream &operator << (std::ostream &output, const Book book)
{
    output << '\n';
    output << "Book Information" << '\n';
    output << "Title:   " << book.title << '\n';
    output << "author:  " << book.author << '\n';
    output << "subject: " << book.subject << '\n';
    output << "book_id: " << book.book_id << '\n';
    output << '\n';
    return output;
}

int main()
{
    Book book1;
    book1.title = "Effective C++";
    book1.author = "Scott Meyers";
    book1.subject = "Programme";
    book1.book_id = 12345;

    std::cout << ToString(book1) << book1;

    Book* book2 = new Book();
    *book2 = book1;
    Book* book3 = &book1;

    std::cout << ToString(book2) << *book2;
    std::cout << ToString(book3) << *book3;

    book1.book_id = 54321;
    // book2->book_id = 11111;

    std::cout << ToString(book1) << book1;
    std::cout << ToString(book2) << *book2;
    std::cout << ToString(book3) << *book3;    

    return 0;
}
