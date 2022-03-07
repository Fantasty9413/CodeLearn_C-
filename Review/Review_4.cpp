# include <iostream>

# define ToString( x ) #x

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
    output << "title:   " << book.title << '\n';
    output << "author:  " << book.author << '\n';
    output << "subject: " << book.subject << '\n';
    output << "book_id: " << book.book_id << '\n';
    output << '\n';
    return output;
}

int main()
{
    Book book;
    book.title = "Effictive C++";
    book.author = "Scott";
    book.subject = "Programme";
    book.book_id = 123456;

    std::cout << ToString(book) << book << std::endl;

    Book* book2 = new Book();
    *book2 = book;

    std::cout << "book2's author is " << book2->author << '\n' << std::endl;

    Book* book3 = new Book();
    *book3 = book;
    book3->book_id = 543210;

    std::cout << ToString(book3) << *book3 << std::endl;

    return 0;
}